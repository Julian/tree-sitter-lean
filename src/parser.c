#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 36
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 8

enum ts_symbol_identifiers {
  sym__identifier_component = 1,
  sym_prelude = 2,
  anon_sym_import = 3,
  anon_sym_POUNDcheck = 4,
  anon_sym_POUNDcheck_failure = 5,
  anon_sym_POUNDeval = 6,
  anon_sym_POUNDprint = 7,
  anon_sym_POUNDreduce = 8,
  anon_sym_open = 9,
  anon_sym_in = 10,
  anon_sym_export = 11,
  anon_sym_LPAREN = 12,
  anon_sym_RPAREN = 13,
  anon_sym_DOT = 14,
  sym_number = 15,
  anon_sym_DQUOTE = 16,
  aux_sym_string_token1 = 17,
  sym_quoted_char = 18,
  sym_comment = 19,
  sym_module = 20,
  sym_import = 21,
  sym__command = 22,
  sym_interactive = 23,
  sym_open = 24,
  sym_export = 25,
  sym__term = 26,
  sym_identifier = 27,
  sym_string = 28,
  sym__apply = 29,
  aux_sym_module_repeat1 = 30,
  aux_sym_module_repeat2 = 31,
  aux_sym_open_repeat1 = 32,
  aux_sym_export_repeat1 = 33,
  aux_sym_identifier_repeat1 = 34,
  aux_sym_string_repeat1 = 35,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__identifier_component] = "_identifier_component",
  [sym_prelude] = "prelude",
  [anon_sym_import] = "import",
  [anon_sym_POUNDcheck] = "#check",
  [anon_sym_POUNDcheck_failure] = "#check_failure",
  [anon_sym_POUNDeval] = "#eval",
  [anon_sym_POUNDprint] = "#print",
  [anon_sym_POUNDreduce] = "#reduce",
  [anon_sym_open] = "open",
  [anon_sym_in] = "in",
  [anon_sym_export] = "export",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DOT] = ".",
  [sym_number] = "number",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [sym_quoted_char] = "quoted_char",
  [sym_comment] = "comment",
  [sym_module] = "module",
  [sym_import] = "import",
  [sym__command] = "_command",
  [sym_interactive] = "interactive",
  [sym_open] = "open",
  [sym_export] = "export",
  [sym__term] = "_term",
  [sym_identifier] = "identifier",
  [sym_string] = "string",
  [sym__apply] = "apply",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_module_repeat2] = "module_repeat2",
  [aux_sym_open_repeat1] = "open_repeat1",
  [aux_sym_export_repeat1] = "export_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__identifier_component] = sym__identifier_component,
  [sym_prelude] = sym_prelude,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_POUNDcheck] = anon_sym_POUNDcheck,
  [anon_sym_POUNDcheck_failure] = anon_sym_POUNDcheck_failure,
  [anon_sym_POUNDeval] = anon_sym_POUNDeval,
  [anon_sym_POUNDprint] = anon_sym_POUNDprint,
  [anon_sym_POUNDreduce] = anon_sym_POUNDreduce,
  [anon_sym_open] = anon_sym_open,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_export] = anon_sym_export,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_number] = sym_number,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [sym_quoted_char] = sym_quoted_char,
  [sym_comment] = sym_comment,
  [sym_module] = sym_module,
  [sym_import] = sym_import,
  [sym__command] = sym__command,
  [sym_interactive] = sym_interactive,
  [sym_open] = sym_open,
  [sym_export] = sym_export,
  [sym__term] = sym__term,
  [sym_identifier] = sym_identifier,
  [sym_string] = sym_string,
  [sym__apply] = sym__apply,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym_module_repeat2] = aux_sym_module_repeat2,
  [aux_sym_open_repeat1] = aux_sym_open_repeat1,
  [aux_sym_export_repeat1] = aux_sym_export_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__identifier_component] = {
    .visible = false,
    .named = true,
  },
  [sym_prelude] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDcheck] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDcheck_failure] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDeval] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDprint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDreduce] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_open] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_export] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_quoted_char] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_import] = {
    .visible = true,
    .named = true,
  },
  [sym__command] = {
    .visible = false,
    .named = true,
  },
  [sym_interactive] = {
    .visible = true,
    .named = true,
  },
  [sym_open] = {
    .visible = true,
    .named = true,
  },
  [sym_export] = {
    .visible = true,
    .named = true,
  },
  [sym__term] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym__apply] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_module_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_module_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_open_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_export_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_argument = 1,
  field_class = 2,
  field_function = 3,
  field_module = 4,
  field_namespace = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
  [field_class] = "class",
  [field_function] = "function",
  [field_module] = "module",
  [field_namespace] = "namespace",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_module, 1},
  [1] =
    {field_argument, 0, .inherited = true},
    {field_function, 0, .inherited = true},
  [3] =
    {field_namespace, 0},
  [4] =
    {field_namespace, 1, .inherited = true},
  [5] =
    {field_argument, 1},
    {field_function, 0},
  [7] =
    {field_namespace, 0, .inherited = true},
    {field_namespace, 1, .inherited = true},
  [9] =
    {field_class, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 3,
  [33] = 6,
  [34] = 7,
  [35] = 35,
  [36] = 36,
  [37] = 10,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 42,
};

static TSCharacterRange sym__identifier_component_character_set_1[] = {
  {'!', '!'}, {'\'', '\''}, {'0', '9'}, {'?', '?'}, {'A', 'Z'}, {'_', 'z'}, {0x100, 0x17f}, {0x370, 0x3ff},
  {0x2070, 0x209f}, {0x2207, 0x2207}, {0x1d400, 0x1d7ff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(37);
      ADVANCE_MAP(
        '"', 48,
        '#', 9,
        '(', 43,
        ')', 44,
        '-', 3,
        '.', 45,
        '/', 4,
        '\\', 28,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x100 <= lookahead && lookahead <= 0x17f) ||
          (0x370 <= lookahead && lookahead <= 0x3ff) ||
          (0x1d400 <= lookahead && lookahead <= 0x1d7ff)) ADVANCE(46);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '"') ADVANCE(48);
      if (lookahead == '-') ADVANCE(50);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0) ADVANCE(54);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(48);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(57);
      END_STATE();
    case 4:
      if (lookahead == '-') ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(56);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 9:
      if (lookahead == 'c') ADVANCE(18);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead == 'p') ADVANCE(25);
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 10:
      if (lookahead == 'c') ADVANCE(21);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(15);
      END_STATE();
    case 12:
      if (lookahead == 'd') ADVANCE(30);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 17:
      if (lookahead == 'f') ADVANCE(8);
      END_STATE();
    case 18:
      if (lookahead == 'h') ADVANCE(14);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == 'k') ADVANCE(38);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(29);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 26:
      if (lookahead == 'r') ADVANCE(16);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 28:
      ADVANCE_MAP(
        'u', 35,
        'x', 33,
        '"', 55,
        '\'', 55,
        '\\', 55,
        'n', 55,
        'r', 55,
        't', 55,
      );
      END_STATE();
    case 29:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 30:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 31:
      if (lookahead == 'v') ADVANCE(7);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (eof) ADVANCE(37);
      if (lookahead == '"') ADVANCE(48);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x100 <= lookahead && lookahead <= 0x17f) ||
          (0x370 <= lookahead && lookahead <= 0x3ff) ||
          (0x1d400 <= lookahead && lookahead <= 0x1d7ff)) ADVANCE(46);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_POUNDcheck);
      if (lookahead == '_') ADVANCE(17);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_POUNDcheck_failure);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_POUNDeval);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_POUNDprint);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_POUNDreduce);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym__identifier_component);
      if (set_contains(sym__identifier_component_character_set_1, 11, lookahead)) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(50);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(54);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(54);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(54);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '/') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(51);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_quoted_char);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(57);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'e') ADVANCE(1);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'o') ADVANCE(3);
      if (lookahead == 'p') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'x') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == 'm') ADVANCE(6);
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 3:
      if (lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 'p') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 'p') ADVANCE(11);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 12:
      if (lookahead == 'n') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 14:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_open);
      END_STATE();
    case 17:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(21);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(23);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_prelude);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__identifier_component] = ACTIONS(1),
    [sym_prelude] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_POUNDcheck] = ACTIONS(1),
    [anon_sym_POUNDcheck_failure] = ACTIONS(1),
    [anon_sym_POUNDeval] = ACTIONS(1),
    [anon_sym_POUNDprint] = ACTIONS(1),
    [anon_sym_POUNDreduce] = ACTIONS(1),
    [anon_sym_open] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_export] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_quoted_char] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_module] = STATE(41),
    [sym_import] = STATE(5),
    [sym__command] = STATE(12),
    [sym_interactive] = STATE(12),
    [sym_open] = STATE(12),
    [sym_export] = STATE(12),
    [aux_sym_module_repeat1] = STATE(5),
    [aux_sym_module_repeat2] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_prelude] = ACTIONS(7),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_POUNDcheck] = ACTIONS(11),
    [anon_sym_POUNDcheck_failure] = ACTIONS(13),
    [anon_sym_POUNDeval] = ACTIONS(13),
    [anon_sym_POUNDprint] = ACTIONS(13),
    [anon_sym_POUNDreduce] = ACTIONS(13),
    [anon_sym_open] = ACTIONS(15),
    [anon_sym_export] = ACTIONS(17),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(4), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [36] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOT,
    STATE(6), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(23), 6,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(21), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      sym_number,
      anon_sym_DQUOTE,
  [64] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(17), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(13), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [100] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(17), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [136] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOT,
    STATE(7), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(31), 6,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(29), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      sym_number,
      anon_sym_DQUOTE,
  [164] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(37), 1,
      anon_sym_DOT,
    STATE(7), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(35), 6,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(33), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      sym_number,
      anon_sym_DQUOTE,
  [192] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 1,
      sym__identifier_component,
    ACTIONS(46), 1,
      sym_number,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    STATE(20), 1,
      sym__apply,
    ACTIONS(44), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
    STATE(9), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(40), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [225] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(20), 1,
      sym__apply,
    STATE(9), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(52), 4,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(50), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [252] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 6,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(33), 9,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      anon_sym_DOT,
      sym_number,
      anon_sym_DQUOTE,
  [275] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(14), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [304] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(14), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [333] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(54), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(14), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [362] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    ACTIONS(58), 1,
      anon_sym_POUNDcheck,
    ACTIONS(64), 1,
      anon_sym_open,
    ACTIONS(67), 1,
      anon_sym_export,
    ACTIONS(61), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(14), 5,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      aux_sym_module_repeat2,
  [391] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 1,
      sym__identifier_component,
    ACTIONS(74), 1,
      anon_sym_in,
    STATE(16), 1,
      aux_sym_open_repeat1,
    STATE(22), 1,
      sym_identifier,
    ACTIONS(72), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
    ACTIONS(70), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [419] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(78), 1,
      sym__identifier_component,
    STATE(16), 1,
      aux_sym_open_repeat1,
    STATE(22), 1,
      sym_identifier,
    ACTIONS(81), 4,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      anon_sym_export,
    ACTIONS(76), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [445] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(85), 1,
      anon_sym_import,
    ACTIONS(88), 1,
      anon_sym_POUNDcheck,
    STATE(17), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(83), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
  [468] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(25), 4,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
  [493] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(92), 4,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(90), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [512] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(96), 4,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(94), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [531] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(100), 4,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      sym__identifier_component,
    ACTIONS(98), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [550] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(102), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(104), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      anon_sym_export,
      sym__identifier_component,
  [568] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(108), 1,
      anon_sym_POUNDcheck,
    ACTIONS(106), 8,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
  [585] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(112), 1,
      anon_sym_POUNDcheck,
    ACTIONS(110), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
  [601] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(116), 1,
      anon_sym_POUNDcheck,
    ACTIONS(114), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
  [617] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(118), 1,
      sym__identifier_component,
    ACTIONS(120), 1,
      sym_number,
    STATE(20), 1,
      sym__apply,
    STATE(8), 3,
      sym__term,
      sym_identifier,
      sym_string,
  [638] = 5,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      aux_sym_string_token1,
    ACTIONS(126), 1,
      sym_quoted_char,
    ACTIONS(128), 1,
      sym_comment,
    STATE(28), 1,
      aux_sym_string_repeat1,
  [654] = 5,
    ACTIONS(128), 1,
      sym_comment,
    ACTIONS(130), 1,
      anon_sym_DQUOTE,
    ACTIONS(132), 1,
      aux_sym_string_token1,
    ACTIONS(134), 1,
      sym_quoted_char,
    STATE(30), 1,
      aux_sym_string_repeat1,
  [670] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym__identifier_component,
    ACTIONS(138), 1,
      anon_sym_RPAREN,
    STATE(31), 2,
      sym_identifier,
      aux_sym_export_repeat1,
  [684] = 5,
    ACTIONS(128), 1,
      sym_comment,
    ACTIONS(140), 1,
      anon_sym_DQUOTE,
    ACTIONS(142), 1,
      aux_sym_string_token1,
    ACTIONS(145), 1,
      sym_quoted_char,
    STATE(30), 1,
      aux_sym_string_repeat1,
  [700] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(148), 1,
      sym__identifier_component,
    ACTIONS(151), 1,
      anon_sym_RPAREN,
    STATE(31), 2,
      sym_identifier,
      aux_sym_export_repeat1,
  [714] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_DOT,
    STATE(33), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(21), 2,
      anon_sym_RPAREN,
      sym__identifier_component,
  [728] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_DOT,
    STATE(34), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(29), 2,
      anon_sym_RPAREN,
      sym__identifier_component,
  [742] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      anon_sym_DOT,
    STATE(34), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(33), 2,
      anon_sym_RPAREN,
      sym__identifier_component,
  [756] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 1,
      sym__identifier_component,
    STATE(15), 1,
      aux_sym_open_repeat1,
    STATE(22), 1,
      sym_identifier,
  [769] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym__identifier_component,
    STATE(29), 2,
      sym_identifier,
      aux_sym_export_repeat1,
  [780] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      sym__identifier_component,
  [789] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 1,
      sym__identifier_component,
    STATE(23), 1,
      sym_identifier,
  [799] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 1,
      sym__identifier_component,
    STATE(40), 1,
      sym_identifier,
  [809] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 1,
      anon_sym_LPAREN,
  [816] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(160), 1,
      ts_builtin_sym_end,
  [823] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(162), 1,
      sym__identifier_component,
  [830] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(164), 1,
      sym__identifier_component,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 36,
  [SMALL_STATE(4)] = 64,
  [SMALL_STATE(5)] = 100,
  [SMALL_STATE(6)] = 136,
  [SMALL_STATE(7)] = 164,
  [SMALL_STATE(8)] = 192,
  [SMALL_STATE(9)] = 225,
  [SMALL_STATE(10)] = 252,
  [SMALL_STATE(11)] = 275,
  [SMALL_STATE(12)] = 304,
  [SMALL_STATE(13)] = 333,
  [SMALL_STATE(14)] = 362,
  [SMALL_STATE(15)] = 391,
  [SMALL_STATE(16)] = 419,
  [SMALL_STATE(17)] = 445,
  [SMALL_STATE(18)] = 468,
  [SMALL_STATE(19)] = 493,
  [SMALL_STATE(20)] = 512,
  [SMALL_STATE(21)] = 531,
  [SMALL_STATE(22)] = 550,
  [SMALL_STATE(23)] = 568,
  [SMALL_STATE(24)] = 585,
  [SMALL_STATE(25)] = 601,
  [SMALL_STATE(26)] = 617,
  [SMALL_STATE(27)] = 638,
  [SMALL_STATE(28)] = 654,
  [SMALL_STATE(29)] = 670,
  [SMALL_STATE(30)] = 684,
  [SMALL_STATE(31)] = 700,
  [SMALL_STATE(32)] = 714,
  [SMALL_STATE(33)] = 728,
  [SMALL_STATE(34)] = 742,
  [SMALL_STATE(35)] = 756,
  [SMALL_STATE(36)] = 769,
  [SMALL_STATE(37)] = 780,
  [SMALL_STATE(38)] = 789,
  [SMALL_STATE(39)] = 799,
  [SMALL_STATE(40)] = 809,
  [SMALL_STATE(41)] = 816,
  [SMALL_STATE(42)] = 823,
  [SMALL_STATE(43)] = 830,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 1, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 2, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 2, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interactive, 2, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interactive, 2, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__apply, 2, 0, 5),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__apply, 2, 0, 5),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 3, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(26),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(26),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(35),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(39),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open, 2, 0, 4),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open, 2, 0, 4),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6), SHIFT_REPEAT(3),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term, 1, 0, 2),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__term, 1, 0, 2),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_repeat1, 1, 0, 3),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 1, 0, 3),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 2, 0, 1),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 2, 0, 1),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_export, 5, 0, 7),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_export, 5, 0, 7),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open, 4, 0, 4),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open, 4, 0, 4),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_export_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_export_repeat1, 2, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [160] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_lean(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym__identifier_component,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
