/*
 * External scanner for tree-sitter-lean.
 *
 * Externalized tokens fall into three groups:
 *   1. Identifiers — dotted, `«quoted»`, and Unicode-aware. Doing this in
 *      the LR lexer would bloat the DFA badly; the scanner approximates
 *      Lean's `isIdFirst`/`isIdRest` directly.
 *   2. Nested block/doc/module-doc comments. Tree-sitter regex cannot do
 *      balanced nesting.
 *   3. Raw string literals with a custom `#`-delimiter count (r"..."#).
 *
 * Layout-sensitive tokens (indent/dedent/newline) arrive in a later stage
 * along with tactic blocks. The scanner state struct is intentionally
 * empty for now but kept so the serialization/deserialization plumbing
 * can grow without an ABI break.
 *
 * Lean's character classifications are mirrored from
 *   src/Init/Meta/Defs.lean
 * in upstream lean4. Full Unicode `Char.isAlpha` is approximated with the
 * common letter blocks Lean code actually uses; expand the table below
 * as needed.
 */

#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

#include <stdbool.h>
#include <stdint.h>

enum TokenType {
  SCANNED_IDENT,
  BLOCK_COMMENT,
  DOC_COMMENT,
  MODULE_DOC_COMMENT,
  RAW_STRING_LITERAL,
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
      || (0x1d49c <= c && c <= 0x1d59f)
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

struct Scanner {
  // Reserved for layout state in a later stage.
  int _unused;
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

/* ---------- dispatch ----------------------------------------------------- */

static bool scan(struct Scanner *scanner, TSLexer *lexer,
                 const bool *valid_symbols) {
  (void)scanner;

  if (valid_symbols[ERROR_SENTINEL]) return false;

  /* Skip whitespace so the scanner's view matches the lexer's. */
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
  return ts_calloc(1, sizeof(struct Scanner));
}

void tree_sitter_lean_external_scanner_destroy(void *payload) {
  ts_free(payload);
}

unsigned tree_sitter_lean_external_scanner_serialize(void *payload, char *buffer) {
  (void)payload; (void)buffer;
  return 0;
}

void tree_sitter_lean_external_scanner_deserialize(void *payload,
                                                   const char *buffer,
                                                   unsigned length) {
  (void)payload; (void)buffer; (void)length;
}

bool tree_sitter_lean_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  return scan((struct Scanner *)payload, lexer, valid_symbols);
}
