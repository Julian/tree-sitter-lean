/*
 * External scanner for tree-sitter-lean.
 *
 * Externalized tokens:
 *   1. `_scanned_ident` — dotted, `«quoted»`, or Unicode identifiers.
 *      Plain ASCII single-component idents go through tree-sitter's
 *      internal lexer so word/keyword extraction works.
 *   2. Nested block/doc/module-doc comments.
 *   3. Raw string literals with matched `#`-delimiter counts.
 *   4. Layout-sensitive tokens `_indent`, `_dedent`, `_newline` that
 *      delimit tactic and do-block bodies.
 *
 * Lean's character classifications mirror `src/Init/Meta/Defs.lean`
 * upstream.
 */

#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

enum TokenType {
  SCANNED_IDENT,
  BLOCK_COMMENT,
  DOC_COMMENT,
  MODULE_DOC_COMMENT,
  RAW_STRING_LITERAL,
  INDENT,
  DEDENT,
  NEWLINE,
  ERROR_SENTINEL,
};

#define ID_BEGIN_ESCAPE 0x00ab // «
#define ID_END_ESCAPE   0x00bb // »

static inline bool is_alpha_ascii(int32_t c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

static inline bool is_digit_ascii(int32_t c) {
  return c >= '0' && c <= '9';
}

static bool is_letter_like(int32_t c) {
  return (0x3b1   <= c && c <= 0x3c9   && c != 0x3bb)
      || (0x391   <= c && c <= 0x3a9   && c != 0x3a0 && c != 0x3a3)
      || (0x3ca   <= c && c <= 0x3fb)
      || (0x1f00  <= c && c <= 0x1ffe)
      || (0x2100  <= c && c <= 0x214f)
      || (0x1d400 <= c && c <= 0x1d7ff)  /* Math alphanumeric symbols (𝟙, 𝒜, 𝔽, …) */
      || (0x00c0  <= c && c <= 0x00ff && c != 0x00d7 && c != 0x00f7)
      || (0x0100  <= c && c <= 0x017f);
}

static bool is_subscript_alnum(int32_t c) {
  return (0x2080 <= c && c <= 0x2089)
      || (0x2090 <= c && c <= 0x209c)
      || (0x1d62 <= c && c <= 0x1d6a)
      || c == 0x2c7c;
}

static bool is_id_first(int32_t c) {
  return is_alpha_ascii(c) || c == '_' || is_letter_like(c);
}

static bool is_id_rest(int32_t c) {
  return is_alpha_ascii(c)
      || is_digit_ascii(c)
      || c == '_' || c == '\'' || c == '!' || c == '?'
      || is_letter_like(c) || is_subscript_alnum(c);
}

/*
 * Indent stack: each entry is the column (in columns, not bytes) of an
 * open tactic/do block. Always contains at least one entry — the base
 * (0). Tokens push and pop based on observed line indentation.
 */
struct Scanner {
  Array(uint16_t) indents;
};

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer)    { lexer->advance(lexer, true); }

/* ---------- identifier --------------------------------------------------- */

/*
 * Consume a single identifier part: `«…»` or `isIdFirst isIdRest*`.
 * Three out-params are vestigial from an earlier keyword-deferral
 * approach; kept so callers don't need to change shape.
 */
static bool scan_ident_part(TSLexer *lexer,
                            char *buf, size_t buf_size,
                            size_t *out_len, bool *out_is_ascii) {
  (void)buf; (void)buf_size;
  *out_len = 0;
  *out_is_ascii = true;

  int32_t c = lexer->lookahead;
  if (c == ID_BEGIN_ESCAPE) {
    *out_is_ascii = false;
    advance(lexer);
    while (lexer->lookahead != 0
        && lexer->lookahead != ID_END_ESCAPE
        && lexer->lookahead != '\n') {
      advance(lexer);
    }
    if (lexer->lookahead != ID_END_ESCAPE) return false;
    advance(lexer);
    return true;
  }
  if (!is_id_first(c)) return false;

  do {
    if (lexer->lookahead >= 0x80) *out_is_ascii = false;
    advance(lexer);
  } while (is_id_rest(lexer->lookahead));

  return true;
}

/*
 * Continue scanning an identifier after `len` chars have already been
 * consumed and buffered in `buf`. Used by the dispatch when a leading
 * character (e.g. `r`, `s`, `m`) was eaten to peek for a non-identifier
 * token but turned out to belong to an identifier after all.
 */
/*
 * Continue scanning an identifier after the first character has been
 * consumed. `seen_unusual` tracks whether anything beyond a plain ASCII
 * single-component identifier has been seen — non-ASCII, an escape, or
 * a dot-continuation. If nothing unusual appears, the scanner returns
 * false so tree-sitter's internal lexer (with its keyword-extraction)
 * handles the token instead.
 */
static bool scan_identifier_continue(TSLexer *lexer, bool seen_unusual) {
  while (is_id_rest(lexer->lookahead)) {
    if (lexer->lookahead >= 0x80) seen_unusual = true;
    advance(lexer);
  }
  lexer->mark_end(lexer);

  while (lexer->lookahead == '.') {
    advance(lexer);
    int32_t next = lexer->lookahead;
    if (next != ID_BEGIN_ESCAPE && !is_id_first(next)) break;
    seen_unusual = true;
    char dummy_buf[2];
    size_t dummy_len;
    bool dummy_ascii;
    if (!scan_ident_part(lexer, dummy_buf, sizeof(dummy_buf),
                         &dummy_len, &dummy_ascii)) break;
    lexer->mark_end(lexer);
  }

  if (!seen_unusual) return false;
  lexer->result_symbol = SCANNED_IDENT;
  return true;
}

static bool scan_identifier(TSLexer *lexer) {
  int32_t c = lexer->lookahead;
  if (c == ID_BEGIN_ESCAPE) {
    char dummy_buf[2];
    size_t dummy_len;
    bool dummy_ascii;
    if (!scan_ident_part(lexer, dummy_buf, sizeof(dummy_buf),
                         &dummy_len, &dummy_ascii)) return false;
    lexer->mark_end(lexer);
    while (lexer->lookahead == '.') {
      advance(lexer);
      int32_t next = lexer->lookahead;
      if (next != ID_BEGIN_ESCAPE && !is_id_first(next)) break;
      if (!scan_ident_part(lexer, dummy_buf, sizeof(dummy_buf),
                           &dummy_len, &dummy_ascii)) break;
      lexer->mark_end(lexer);
    }
    lexer->result_symbol = SCANNED_IDENT;
    return true;
  }
  if (!is_id_first(c)) return false;
  bool seen_unusual = (c >= 0x80);
  advance(lexer);
  return scan_identifier_continue(lexer, seen_unusual);
}

/* ---------- comments ----------------------------------------------------- */

/*
 * Consume the body of a `/- … -/` style comment, honoring nesting.
 * The opening `/-` (or `/--`, `/-!`) must already have been consumed.
 */
static bool scan_block_comment_body(TSLexer *lexer) {
  unsigned depth = 1;
  while (depth > 0) {
    if (lexer->eof(lexer)) return false;
    if (lexer->lookahead == '/') {
      advance(lexer);
      if (lexer->lookahead == '-') {
        advance(lexer);
        depth++;
      }
    } else if (lexer->lookahead == '-') {
      advance(lexer);
      if (lexer->lookahead == '/') {
        advance(lexer);
        depth--;
      }
    } else {
      advance(lexer);
    }
  }
  return true;
}

/*
 * Dispatch among `/- … -/`, `/-- … -/`, `/-! … -/` based on the third
 * character after the opening `/-`. The caller has consumed nothing yet.
 */
static bool scan_block_or_doc_comment(TSLexer *lexer,
                                      const bool *valid_symbols) {
  if (lexer->lookahead != '/') return false;
  advance(lexer);
  if (lexer->lookahead != '-') return false;
  advance(lexer);

  int kind;
  if (lexer->lookahead == '-' && valid_symbols[DOC_COMMENT]) {
    advance(lexer);
    /* Avoid eating `/---` style ASCII rulers as doc comments? Lean does
       treat them as doc comments, so accept. */
    kind = DOC_COMMENT;
  } else if (lexer->lookahead == '!' && valid_symbols[MODULE_DOC_COMMENT]) {
    advance(lexer);
    kind = MODULE_DOC_COMMENT;
  } else if (valid_symbols[BLOCK_COMMENT]) {
    kind = BLOCK_COMMENT;
  } else {
    return false;
  }

  if (!scan_block_comment_body(lexer)) return false;
  lexer->result_symbol = kind;
  return true;
}

/* ---------- raw strings -------------------------------------------------- */

/*
 * Recognize r"…", r#"…"#, r##"…"##, … with matching `#` counts. The
 * leading `r` is assumed already consumed by the dispatcher.
 */
static bool scan_raw_string_after_r(TSLexer *lexer) {
  unsigned hashes = 0;
  while (lexer->lookahead == '#') {
    advance(lexer);
    hashes++;
  }
  if (lexer->lookahead != '"') return false;
  advance(lexer);

  for (;;) {
    if (lexer->eof(lexer)) return false;
    if (lexer->lookahead == '"') {
      advance(lexer);
      unsigned seen = 0;
      while (seen < hashes && lexer->lookahead == '#') {
        advance(lexer);
        seen++;
      }
      if (seen == hashes) {
        lexer->result_symbol = RAW_STRING_LITERAL;
        return true;
      }
    } else {
      advance(lexer);
    }
  }
}

/* ---------- layout (indent / dedent / newline) -------------------------- */

/*
 * If we're sitting on a newline AND any layout token is valid, walk
 * forward to the next non-blank, non-comment line and report what
 * happened to the indent level.
 *
 *   indent > top  → push, emit INDENT
 *   indent < top  → pop one, emit DEDENT (caller will re-invoke us if
 *                   more pops are needed)
 *   indent == top → emit NEWLINE
 *
 * Lines that are entirely blank or contain only a comment don't
 * participate — they're skipped, and we use the indent of the next
 * real content line.
 */
static bool scan_layout(struct Scanner *scanner, TSLexer *lexer,
                        const bool *valid_symbols) {
  if (!(valid_symbols[INDENT]
     || valid_symbols[DEDENT]
     || valid_symbols[NEWLINE])) {
    return false;
  }

  /* Skip trailing spaces/tabs on the current line; we only care about
     layout once we reach a newline. */
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t'
      || lexer->lookahead == '\r') {
    skip(lexer);
  }

  /* If we're not at a newline (or EOF), no layout token applies. */
  if (lexer->lookahead != '\n' && !lexer->eof(lexer)) return false;

  uint32_t indent = 0;
  bool saw_newline = false;
  for (;;) {
    if (lexer->lookahead == '\n') {
      indent = 0;
      saw_newline = true;
      skip(lexer);
    } else if (lexer->lookahead == ' ') {
      indent++;
      skip(lexer);
    } else if (lexer->lookahead == '\t') {
      indent += 8;
      skip(lexer);
    } else if (lexer->lookahead == '\r') {
      skip(lexer);
    } else if (lexer->eof(lexer)) {
      /* EOF closes every open block. */
      if (valid_symbols[DEDENT] && scanner->indents.size > 1) {
        array_pop(&scanner->indents);
        lexer->result_symbol = DEDENT;
        return true;
      }
      return false;
    } else {
      break;
    }
  }
  if (!saw_newline) return false;

  uint16_t top = scanner->indents.size > 0
    ? *array_back(&scanner->indents)
    : 0;

  /* `|` always continues the surrounding rule (match alt, ctor alt,
     pipe-operator) — never terminates a layout block. Suppress
     NEWLINE/DEDENT at the start of a `|`-line so the parser stays
     inside the match/inductive/etc. */
  if (lexer->lookahead == '|') return false;

  if (indent > top && valid_symbols[INDENT]) {
    array_push(&scanner->indents, (uint16_t)indent);
    lexer->result_symbol = INDENT;
    return true;
  }
  if (indent < top && valid_symbols[DEDENT]) {
    array_pop(&scanner->indents);
    lexer->result_symbol = DEDENT;
    return true;
  }
  if (valid_symbols[NEWLINE]) {
    lexer->result_symbol = NEWLINE;
    return true;
  }
  return false;
}

/* ---------- dispatch ----------------------------------------------------- */

static bool scan(struct Scanner *scanner, TSLexer *lexer,
                 const bool *valid_symbols) {
  if (valid_symbols[ERROR_SENTINEL]) return false;

  /* Layout tokens have to be considered before the whitespace skip —
     they're triggered by newlines and leading-line indentation. */
  if (valid_symbols[INDENT] || valid_symbols[DEDENT] || valid_symbols[NEWLINE]) {
    if (scan_layout(scanner, lexer, valid_symbols)) return true;
  }

  /* Skip plain whitespace so the rest of the scanner's view matches
     the lexer's. */
  while (lexer->lookahead == ' '
      || lexer->lookahead == '\t'
      || lexer->lookahead == '\r'
      || lexer->lookahead == '\n') {
    skip(lexer);
  }

  if ((valid_symbols[BLOCK_COMMENT]
    || valid_symbols[DOC_COMMENT]
    || valid_symbols[MODULE_DOC_COMMENT])
      && lexer->lookahead == '/') {
    if (scan_block_or_doc_comment(lexer, valid_symbols)) return true;
    return false;
  }

  /* `r` may start either a raw string or an identifier. Both can be
     valid at the same parser position, so we peek past the `r` and
     dispatch based on what follows. If neither path matches, we still
     have to consume the `r` we just ate — fall through as a 1-char
     identifier. */
  if (lexer->lookahead == 'r'
      && (valid_symbols[RAW_STRING_LITERAL] || valid_symbols[SCANNED_IDENT])) {
    advance(lexer);
    int32_t next = lexer->lookahead;
    if (valid_symbols[RAW_STRING_LITERAL]
        && (next == '"' || next == '#')) {
      return scan_raw_string_after_r(lexer);
    }
    if (valid_symbols[SCANNED_IDENT]) {
      /* Continue an identifier that already has one ASCII char. Plain
         single-component idents are handled by tree-sitter's internal
         lexer, so this path only succeeds if a dot continuation or a
         non-ASCII char shows up. */
      return scan_identifier_continue(lexer, false);
    }
    return false;
  }

  if (valid_symbols[SCANNED_IDENT]
      && (lexer->lookahead == ID_BEGIN_ESCAPE
       || is_id_first(lexer->lookahead))) {
    if (scan_identifier(lexer)) return true;
  }

  return false;
}

/* ---------- tree-sitter ABI --------------------------------------------- */

void *tree_sitter_lean_external_scanner_create(void) {
  struct Scanner *s = ts_calloc(1, sizeof(struct Scanner));
  array_init(&s->indents);
  array_push(&s->indents, 0);
  return s;
}

void tree_sitter_lean_external_scanner_destroy(void *payload) {
  struct Scanner *s = payload;
  array_delete(&s->indents);
  ts_free(s);
}

unsigned tree_sitter_lean_external_scanner_serialize(void *payload, char *buffer) {
  struct Scanner *s = payload;
  unsigned offset = 0;
  for (uint32_t i = 0;
       i < s->indents.size && offset + sizeof(uint16_t) <= TREE_SITTER_SERIALIZATION_BUFFER_SIZE;
       i++) {
    uint16_t v = *array_get(&s->indents, i);
    memcpy(buffer + offset, &v, sizeof v);
    offset += sizeof v;
  }
  return offset;
}

void tree_sitter_lean_external_scanner_deserialize(void *payload,
                                                   const char *buffer,
                                                   unsigned length) {
  struct Scanner *s = payload;
  array_clear(&s->indents);
  unsigned offset = 0;
  while (offset + sizeof(uint16_t) <= length) {
    uint16_t v;
    memcpy(&v, buffer + offset, sizeof v);
    array_push(&s->indents, v);
    offset += sizeof v;
  }
  if (s->indents.size == 0) array_push(&s->indents, 0);
}

bool tree_sitter_lean_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  return scan((struct Scanner *)payload, lexer, valid_symbols);
}
