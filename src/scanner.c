#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

enum TokenType {
  INDENT,
  DEDENT,
  NEWLINE,
  ERROR_SENTINEL,
};

struct Scanner {
  Array(uint16_t) indents;
};

  static bool scan(
    struct Scanner* const this,
    TSLexer* const lexer,
    const bool* const valid_symbols
  ) {
    lexer->mark_end(lexer);

    bool found_end_of_line = false;
    uint16_t indent = 0;

    for (;;) {
      if (lexer->lookahead == '\n') {
        found_end_of_line = true;
        indent = 0;
        lexer->advance(lexer, true);
      } else if (lexer->lookahead == ' ' && valid_symbols[INDENT]) {
        indent++;
        lexer->advance(lexer, true);
      } else if (lexer->eof(lexer)) {
        found_end_of_line = true;
        indent = 0;
        break;
      } else {
        break;
      }
    }

    if (found_end_of_line) {
      if (this->indents.size > 0) {
        uint16_t last_indent = *array_back(&this->indents);

        if (valid_symbols[INDENT] && indent > last_indent) {
          array_push(&this->indents, indent);
          lexer->result_symbol = INDENT;
          return true;
        }

        if (valid_symbols[DEDENT] && indent < last_indent) {
          array_pop(&this->indents);
          lexer->result_symbol = DEDENT;
          return true;
        }
      }

      if (valid_symbols[NEWLINE]) {
        lexer->result_symbol = NEWLINE;
        return true;
      }
    }

    return false;
  }

  static void scanner_init(struct Scanner* const this) {
    Array(uint16_t) *indents = ts_malloc(sizeof(Array(uint16_t)));
    array_init(&this->indents);
  }

  static void scanner_free(struct Scanner* const this) {
    array_delete(&this->indents);
  }

  static unsigned scanner_serialize(
    const struct Scanner* const this,
    char* const buffer
  ) {
    unsigned offset = 0;

    uint32_t iter = 1;
    for (; iter < this->indents.size && offset < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; ++iter) {
      buffer[offset++] = (char)*array_get(&this->indents, iter);
    }

    return offset;
  }

  static void scanner_deserialize(
    struct Scanner* const this,
    const char* const buffer,
    unsigned const length
  ) {
    array_delete(&this->indents);
    array_push(&this->indents, 0);

    if (length > 0) {
      size_t size = 0;
      for (; size < length; size++) {
        array_push(&this->indents, (unsigned char)buffer[size]);
      }
    }
  }

void *tree_sitter_lean_external_scanner_create() {
  struct Scanner* scanner = ts_malloc(sizeof(struct Scanner));
  scanner_init(scanner);
  return scanner;
}

void tree_sitter_lean_external_scanner_destroy(void *payload) {
  struct Scanner* const scanner = (struct Scanner*)(payload);
  scanner_free(scanner);
  ts_free(scanner);
}

unsigned tree_sitter_lean_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  const struct Scanner* const scanner = (struct Scanner*)(payload);
  return scanner_serialize(scanner, buffer);
}

void tree_sitter_lean_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  struct Scanner* const scanner = (struct Scanner*)(payload);
  scanner_deserialize(scanner, buffer, length);
}

bool tree_sitter_lean_external_scanner_scan(
  void* const payload,
  TSLexer* const lexer,
  const bool* const valid_symbols
) {
  if (valid_symbols[ERROR_SENTINEL]) {
    return false;
  }
  struct Scanner* const scanner = (struct Scanner*)(payload);
  return scan(scanner, lexer, valid_symbols);
}
