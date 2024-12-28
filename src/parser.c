#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 33
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 7

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
  anon_sym_DOT = 11,
  sym_number = 12,
  anon_sym_DQUOTE = 13,
  aux_sym_string_token1 = 14,
  sym_quoted_char = 15,
  sym_comment = 16,
  sym_module = 17,
  sym_import = 18,
  sym__command = 19,
  sym_interactive = 20,
  sym_open = 21,
  sym__term = 22,
  sym_identifier = 23,
  sym_string = 24,
  sym__apply = 25,
  aux_sym_module_repeat1 = 26,
  aux_sym_module_repeat2 = 27,
  aux_sym_open_repeat1 = 28,
  aux_sym_identifier_repeat1 = 29,
  aux_sym_string_repeat1 = 30,
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
  [sym__term] = "_term",
  [sym_identifier] = "identifier",
  [sym_string] = "string",
  [sym__apply] = "apply",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_module_repeat2] = "module_repeat2",
  [aux_sym_open_repeat1] = "open_repeat1",
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
  [sym__term] = sym__term,
  [sym_identifier] = sym_identifier,
  [sym_string] = sym_string,
  [sym__apply] = sym__apply,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym_module_repeat2] = aux_sym_module_repeat2,
  [aux_sym_open_repeat1] = aux_sym_open_repeat1,
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
  field_function = 2,
  field_module = 3,
  field_namespace = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
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
  [32] = 32,
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
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '.') ADVANCE(43);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x100 <= lookahead && lookahead <= 0x17f) ||
          (0x370 <= lookahead && lookahead <= 0x3ff) ||
          (0x1d400 <= lookahead && lookahead <= 0x1d7ff)) ADVANCE(44);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '-') ADVANCE(48);
      if (lookahead == '/') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(47);
      if (lookahead != 0) ADVANCE(52);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(55);
      END_STATE();
    case 4:
      if (lookahead == '-') ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(54);
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
        '"', 53,
        '\'', 53,
        '\\', 53,
        'n', 53,
        'r', 53,
        't', 53,
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
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
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
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x100 <= lookahead && lookahead <= 0x17f) ||
          (0x370 <= lookahead && lookahead <= 0x3ff) ||
          (0x1d400 <= lookahead && lookahead <= 0x1d7ff)) ADVANCE(44);
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
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__identifier_component);
      if (set_contains(sym__identifier_component_character_set_1, 11, lookahead)) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(48);
      if (lookahead == '/') ADVANCE(50);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(47);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(52);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(52);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(52);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(49);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_quoted_char);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(55);
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
      if (lookahead == 'i') ADVANCE(1);
      if (lookahead == 'o') ADVANCE(2);
      if (lookahead == 'p') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'm') ADVANCE(4);
      if (lookahead == 'n') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(12);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 11:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_open);
      END_STATE();
    case 13:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(16);
      END_STATE();
    case 15:
      if (lookahead == 'd') ADVANCE(17);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 18:
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
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
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
    [anon_sym_DOT] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_quoted_char] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_module] = STATE(31),
    [sym_import] = STATE(4),
    [sym__command] = STATE(14),
    [sym_interactive] = STATE(14),
    [sym_open] = STATE(14),
    [aux_sym_module_repeat1] = STATE(4),
    [aux_sym_module_repeat2] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_prelude] = ACTIONS(7),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_POUNDcheck] = ACTIONS(11),
    [anon_sym_POUNDcheck_failure] = ACTIONS(13),
    [anon_sym_POUNDeval] = ACTIONS(13),
    [anon_sym_POUNDprint] = ACTIONS(13),
    [anon_sym_POUNDreduce] = ACTIONS(13),
    [anon_sym_open] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    STATE(3), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(15), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [32] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
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
    STATE(13), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [64] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    STATE(17), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(15), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [96] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym__identifier_component,
    ACTIONS(27), 1,
      sym_number,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    STATE(18), 1,
      sym__apply,
    ACTIONS(25), 2,
      anon_sym_POUNDcheck,
      anon_sym_open,
    STATE(7), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(21), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [128] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_DOT,
    STATE(9), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(33), 5,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      sym__identifier_component,
    ACTIONS(31), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [154] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(18), 1,
      sym__apply,
    ACTIONS(39), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      sym__identifier_component,
    STATE(7), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(37), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [180] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_DOT,
    STATE(6), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(43), 5,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      sym__identifier_component,
    ACTIONS(41), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [206] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(49), 1,
      anon_sym_DOT,
    STATE(9), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(47), 5,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      sym__identifier_component,
    ACTIONS(45), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [232] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(47), 5,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      sym__identifier_component,
    ACTIONS(45), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_DOT,
      sym_number,
      anon_sym_DQUOTE,
  [253] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(52), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 1,
      anon_sym_POUNDcheck,
    ACTIONS(60), 1,
      anon_sym_open,
    ACTIONS(57), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [278] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym__identifier_component,
    ACTIONS(67), 1,
      anon_sym_in,
    STATE(16), 1,
      aux_sym_open_repeat1,
    STATE(21), 1,
      sym_identifier,
    ACTIONS(65), 2,
      anon_sym_POUNDcheck,
      anon_sym_open,
    ACTIONS(63), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [305] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [330] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [355] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 4,
      sym__command,
      sym_interactive,
      sym_open,
      aux_sym_module_repeat2,
  [380] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(73), 1,
      sym__identifier_component,
    STATE(16), 1,
      aux_sym_open_repeat1,
    STATE(21), 1,
      sym_identifier,
    ACTIONS(76), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
    ACTIONS(71), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [405] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_import,
    ACTIONS(83), 1,
      anon_sym_POUNDcheck,
    STATE(17), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(78), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
  [427] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      sym__identifier_component,
    ACTIONS(85), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [445] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      sym__identifier_component,
    ACTIONS(89), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [463] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 3,
      anon_sym_POUNDcheck,
      anon_sym_open,
      sym__identifier_component,
    ACTIONS(93), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [481] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 4,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_in,
      sym__identifier_component,
    ACTIONS(97), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [498] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    STATE(25), 3,
      sym__command,
      sym_interactive,
      sym_open,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [519] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      anon_sym_POUNDcheck,
    ACTIONS(101), 7,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
  [535] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(105), 1,
      sym__identifier_component,
    ACTIONS(107), 1,
      sym_number,
    STATE(18), 1,
      sym__apply,
    STATE(5), 3,
      sym__term,
      sym_identifier,
      sym_string,
  [556] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 1,
      anon_sym_POUNDcheck,
    ACTIONS(109), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
  [571] = 5,
    ACTIONS(113), 1,
      anon_sym_DQUOTE,
    ACTIONS(115), 1,
      aux_sym_string_token1,
    ACTIONS(117), 1,
      sym_quoted_char,
    ACTIONS(119), 1,
      sym_comment,
    STATE(27), 1,
      aux_sym_string_repeat1,
  [587] = 5,
    ACTIONS(119), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_DQUOTE,
    ACTIONS(123), 1,
      aux_sym_string_token1,
    ACTIONS(125), 1,
      sym_quoted_char,
    STATE(28), 1,
      aux_sym_string_repeat1,
  [603] = 5,
    ACTIONS(119), 1,
      sym_comment,
    ACTIONS(127), 1,
      anon_sym_DQUOTE,
    ACTIONS(129), 1,
      aux_sym_string_token1,
    ACTIONS(132), 1,
      sym_quoted_char,
    STATE(28), 1,
      aux_sym_string_repeat1,
  [619] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(105), 1,
      sym__identifier_component,
    STATE(12), 1,
      aux_sym_open_repeat1,
    STATE(21), 1,
      sym_identifier,
  [632] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(105), 1,
      sym__identifier_component,
    STATE(23), 1,
      sym_identifier,
  [642] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 1,
      ts_builtin_sym_end,
  [649] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(137), 1,
      sym__identifier_component,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 32,
  [SMALL_STATE(4)] = 64,
  [SMALL_STATE(5)] = 96,
  [SMALL_STATE(6)] = 128,
  [SMALL_STATE(7)] = 154,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 206,
  [SMALL_STATE(10)] = 232,
  [SMALL_STATE(11)] = 253,
  [SMALL_STATE(12)] = 278,
  [SMALL_STATE(13)] = 305,
  [SMALL_STATE(14)] = 330,
  [SMALL_STATE(15)] = 355,
  [SMALL_STATE(16)] = 380,
  [SMALL_STATE(17)] = 405,
  [SMALL_STATE(18)] = 427,
  [SMALL_STATE(19)] = 445,
  [SMALL_STATE(20)] = 463,
  [SMALL_STATE(21)] = 481,
  [SMALL_STATE(22)] = 498,
  [SMALL_STATE(23)] = 519,
  [SMALL_STATE(24)] = 535,
  [SMALL_STATE(25)] = 556,
  [SMALL_STATE(26)] = 571,
  [SMALL_STATE(27)] = 587,
  [SMALL_STATE(28)] = 603,
  [SMALL_STATE(29)] = 619,
  [SMALL_STATE(30)] = 632,
  [SMALL_STATE(31)] = 642,
  [SMALL_STATE(32)] = 649,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 1, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 2, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interactive, 2, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interactive, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 2, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__apply, 2, 0, 5),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__apply, 2, 0, 5),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(24),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(24),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(29),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open, 2, 0, 4),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open, 2, 0, 4),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 3, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6), SHIFT_REPEAT(8),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term, 1, 0, 2),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__term, 1, 0, 2),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_repeat1, 1, 0, 3),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 1, 0, 3),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 2, 0, 1),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 2, 0, 1),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open, 4, 0, 4),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open, 4, 0, 4),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [132] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [135] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
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
