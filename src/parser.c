#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 82
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 0
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 11

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
  anon_sym_export = 10,
  anon_sym_LPAREN = 11,
  anon_sym_RPAREN = 12,
  anon_sym_section = 13,
  anon_sym_end = 14,
  anon_sym_namespace = 15,
  anon_sym_DOT = 16,
  sym_number = 17,
  anon_sym_DQUOTE = 18,
  aux_sym_string_token1 = 19,
  sym_quoted_char = 20,
  sym_comment = 21,
  sym_module = 22,
  sym_import = 23,
  sym__command = 24,
  sym_interactive = 25,
  sym_open = 26,
  sym_export = 27,
  sym_section = 28,
  sym_namespace = 29,
  sym__term = 30,
  sym_identifier = 31,
  sym_string = 32,
  sym__apply = 33,
  aux_sym_module_repeat1 = 34,
  aux_sym_module_repeat2 = 35,
  aux_sym_open_repeat1 = 36,
  aux_sym_export_repeat1 = 37,
  aux_sym_identifier_repeat1 = 38,
  aux_sym_string_repeat1 = 39,
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
  [anon_sym_export] = "export",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_section] = "section",
  [anon_sym_end] = "end",
  [anon_sym_namespace] = "namespace",
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
  [sym_section] = "section",
  [sym_namespace] = "namespace",
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
  [anon_sym_export] = anon_sym_export,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_section] = anon_sym_section,
  [anon_sym_end] = anon_sym_end,
  [anon_sym_namespace] = anon_sym_namespace,
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
  [sym_section] = sym_section,
  [sym_namespace] = sym_namespace,
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
  [anon_sym_section] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_namespace] = {
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
  [sym_section] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace] = {
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
  field_body = 2,
  field_class = 3,
  field_function = 4,
  field_module = 5,
  field_name = 6,
  field_namespace = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
  [field_body] = "body",
  [field_class] = "class",
  [field_function] = "function",
  [field_module] = "module",
  [field_name] = "name",
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
  [8] = {.index = 10, .length = 1},
  [9] = {.index = 11, .length = 2},
  [10] = {.index = 13, .length = 1},
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
    {field_name, 1},
  [10] =
    {field_body, 1},
  [11] =
    {field_body, 2},
    {field_name, 1},
  [13] =
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
  [6] = 5,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 10,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 11,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 13,
  [25] = 17,
  [26] = 16,
  [27] = 18,
  [28] = 8,
  [29] = 7,
  [30] = 9,
  [31] = 22,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 32,
  [38] = 36,
  [39] = 39,
  [40] = 35,
  [41] = 34,
  [42] = 39,
  [43] = 43,
  [44] = 44,
  [45] = 44,
  [46] = 46,
  [47] = 47,
  [48] = 47,
  [49] = 43,
  [50] = 46,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 56,
  [60] = 60,
  [61] = 61,
  [62] = 61,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 64,
  [69] = 65,
  [70] = 70,
  [71] = 71,
  [72] = 71,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 80,
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
      if (lookahead == 'n') ADVANCE(3);
      if (lookahead == 'o') ADVANCE(4);
      if (lookahead == 'p') ADVANCE(5);
      if (lookahead == 's') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'n') ADVANCE(7);
      if (lookahead == 'x') ADVANCE(8);
      END_STATE();
    case 2:
      if (lookahead == 'm') ADVANCE(9);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == 'p') ADVANCE(11);
      END_STATE();
    case 5:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 7:
      if (lookahead == 'd') ADVANCE(14);
      END_STATE();
    case 8:
      if (lookahead == 'p') ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 10:
      if (lookahead == 'm') ADVANCE(17);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(20);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(21);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 18:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 21:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 22:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 23:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_open);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 26:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 29:
      if (lookahead == 'p') ADVANCE(34);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(35);
      END_STATE();
    case 31:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 37:
      if (lookahead == 'c') ADVANCE(40);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_prelude);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_section);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_namespace);
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
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
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
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
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
    [anon_sym_export] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_section] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [anon_sym_namespace] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_quoted_char] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_module] = STATE(79),
    [sym_import] = STATE(4),
    [sym__command] = STATE(23),
    [sym_interactive] = STATE(23),
    [sym_open] = STATE(23),
    [sym_export] = STATE(23),
    [sym_section] = STATE(23),
    [sym_namespace] = STATE(23),
    [aux_sym_module_repeat1] = STATE(4),
    [aux_sym_module_repeat2] = STATE(23),
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
    [anon_sym_section] = ACTIONS(19),
    [anon_sym_namespace] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym_import] = STATE(3),
    [sym__command] = STATE(12),
    [sym_interactive] = STATE(12),
    [sym_open] = STATE(12),
    [sym_export] = STATE(12),
    [sym_section] = STATE(12),
    [sym_namespace] = STATE(12),
    [aux_sym_module_repeat1] = STATE(3),
    [aux_sym_module_repeat2] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_POUNDcheck] = ACTIONS(11),
    [anon_sym_POUNDcheck_failure] = ACTIONS(13),
    [anon_sym_POUNDeval] = ACTIONS(13),
    [anon_sym_POUNDprint] = ACTIONS(13),
    [anon_sym_POUNDreduce] = ACTIONS(13),
    [anon_sym_open] = ACTIONS(15),
    [anon_sym_export] = ACTIONS(17),
    [anon_sym_section] = ACTIONS(19),
    [anon_sym_namespace] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
  [3] = {
    [sym_import] = STATE(33),
    [sym__command] = STATE(19),
    [sym_interactive] = STATE(19),
    [sym_open] = STATE(19),
    [sym_export] = STATE(19),
    [sym_section] = STATE(19),
    [sym_namespace] = STATE(19),
    [aux_sym_module_repeat1] = STATE(33),
    [aux_sym_module_repeat2] = STATE(19),
    [ts_builtin_sym_end] = ACTIONS(25),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_POUNDcheck] = ACTIONS(11),
    [anon_sym_POUNDcheck_failure] = ACTIONS(13),
    [anon_sym_POUNDeval] = ACTIONS(13),
    [anon_sym_POUNDprint] = ACTIONS(13),
    [anon_sym_POUNDreduce] = ACTIONS(13),
    [anon_sym_open] = ACTIONS(15),
    [anon_sym_export] = ACTIONS(17),
    [anon_sym_section] = ACTIONS(19),
    [anon_sym_namespace] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
  [4] = {
    [sym_import] = STATE(33),
    [sym__command] = STATE(12),
    [sym_interactive] = STATE(12),
    [sym_open] = STATE(12),
    [sym_export] = STATE(12),
    [sym_section] = STATE(12),
    [sym_namespace] = STATE(12),
    [aux_sym_module_repeat1] = STATE(33),
    [aux_sym_module_repeat2] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_POUNDcheck] = ACTIONS(11),
    [anon_sym_POUNDcheck_failure] = ACTIONS(13),
    [anon_sym_POUNDeval] = ACTIONS(13),
    [anon_sym_POUNDprint] = ACTIONS(13),
    [anon_sym_POUNDreduce] = ACTIONS(13),
    [anon_sym_open] = ACTIONS(15),
    [anon_sym_export] = ACTIONS(17),
    [anon_sym_section] = ACTIONS(19),
    [anon_sym_namespace] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(33), 1,
      anon_sym_open,
    ACTIONS(35), 1,
      anon_sym_export,
    ACTIONS(37), 1,
      anon_sym_section,
    ACTIONS(39), 1,
      anon_sym_end,
    ACTIONS(41), 1,
      anon_sym_namespace,
    STATE(16), 1,
      sym_identifier,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(15), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [43] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(33), 1,
      anon_sym_open,
    ACTIONS(35), 1,
      anon_sym_export,
    ACTIONS(37), 1,
      anon_sym_section,
    ACTIONS(41), 1,
      anon_sym_namespace,
    ACTIONS(43), 1,
      anon_sym_end,
    STATE(26), 1,
      sym_identifier,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(10), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [86] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(49), 1,
      anon_sym_DOT,
    STATE(9), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(45), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(47), 8,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [116] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(49), 1,
      anon_sym_DOT,
    STATE(7), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(51), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(53), 8,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [146] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_DOT,
    STATE(9), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(55), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(57), 8,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [176] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(66), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(27), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [213] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(68), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(27), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [250] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(19), 1,
      anon_sym_section,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(18), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [287] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    ACTIONS(74), 1,
      sym_number,
    ACTIONS(76), 1,
      anon_sym_DQUOTE,
    STATE(32), 1,
      sym__apply,
    STATE(17), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(70), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(72), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [322] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(78), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(21), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [359] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(80), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(27), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [396] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(82), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(20), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [433] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(32), 1,
      sym__apply,
    STATE(17), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(86), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
      sym__identifier_component,
    ACTIONS(84), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [462] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(88), 1,
      ts_builtin_sym_end,
    ACTIONS(90), 1,
      anon_sym_POUNDcheck,
    ACTIONS(96), 1,
      anon_sym_open,
    ACTIONS(99), 1,
      anon_sym_export,
    ACTIONS(102), 1,
      anon_sym_section,
    ACTIONS(105), 1,
      anon_sym_namespace,
    ACTIONS(93), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(18), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [499] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(19), 1,
      anon_sym_section,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(108), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(18), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [536] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(110), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(27), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [573] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(112), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(27), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [610] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(57), 8,
      anon_sym_import,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
    ACTIONS(55), 9,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_LPAREN,
      anon_sym_DOT,
      sym_number,
      anon_sym_DQUOTE,
  [635] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_POUNDcheck,
    ACTIONS(15), 1,
      anon_sym_open,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(19), 1,
      anon_sym_section,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(18), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [672] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(114), 1,
      sym__identifier_component,
    ACTIONS(116), 1,
      sym_number,
    ACTIONS(118), 1,
      anon_sym_DQUOTE,
    STATE(37), 1,
      sym__apply,
    STATE(25), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(70), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(72), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [707] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(37), 1,
      sym__apply,
    STATE(25), 3,
      sym__term,
      sym_identifier,
      sym_string,
    ACTIONS(84), 6,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(86), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [736] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_export,
    ACTIONS(21), 1,
      anon_sym_namespace,
    ACTIONS(29), 1,
      anon_sym_POUNDcheck,
    ACTIONS(62), 1,
      anon_sym_open,
    ACTIONS(64), 1,
      anon_sym_section,
    ACTIONS(120), 1,
      anon_sym_end,
    ACTIONS(31), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(11), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [773] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(88), 1,
      anon_sym_end,
    ACTIONS(99), 1,
      anon_sym_export,
    ACTIONS(105), 1,
      anon_sym_namespace,
    ACTIONS(122), 1,
      anon_sym_POUNDcheck,
    ACTIONS(128), 1,
      anon_sym_open,
    ACTIONS(131), 1,
      anon_sym_section,
    ACTIONS(125), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    STATE(27), 7,
      sym__command,
      sym_interactive,
      sym_open,
      sym_export,
      sym_section,
      sym_namespace,
      aux_sym_module_repeat2,
  [810] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_DOT,
    STATE(29), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(51), 7,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_RPAREN,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(53), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [838] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_DOT,
    STATE(30), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(45), 7,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_RPAREN,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(47), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [866] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_DOT,
    STATE(30), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(55), 7,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_RPAREN,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(57), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [894] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(57), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
    ACTIONS(55), 8,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_RPAREN,
      anon_sym_DOT,
      sym_number,
      anon_sym_DQUOTE,
  [917] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(141), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
      sym__identifier_component,
    ACTIONS(139), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [938] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 1,
      anon_sym_import,
    ACTIONS(148), 1,
      anon_sym_POUNDcheck,
    STATE(33), 2,
      sym_import,
      aux_sym_module_repeat1,
    ACTIONS(143), 9,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [963] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(36), 1,
      aux_sym_open_repeat1,
    STATE(59), 1,
      sym_identifier,
    ACTIONS(150), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(152), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [990] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(156), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
      sym__identifier_component,
    ACTIONS(154), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [1011] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(160), 1,
      sym__identifier_component,
    STATE(36), 1,
      aux_sym_open_repeat1,
    STATE(59), 1,
      sym_identifier,
    ACTIONS(158), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(163), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [1038] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 6,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(141), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [1059] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(165), 1,
      sym__identifier_component,
    STATE(38), 1,
      aux_sym_open_repeat1,
    STATE(56), 1,
      sym_identifier,
    ACTIONS(158), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(163), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1086] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
      sym__identifier_component,
    ACTIONS(168), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
  [1107] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(154), 6,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(156), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [1128] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(114), 1,
      sym__identifier_component,
    STATE(38), 1,
      aux_sym_open_repeat1,
    STATE(56), 1,
      sym_identifier,
    ACTIONS(150), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(152), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1155] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(168), 6,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      sym_number,
      anon_sym_DQUOTE,
    ACTIONS(170), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [1176] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(51), 1,
      sym_identifier,
    ACTIONS(174), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(172), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1200] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(60), 1,
      sym_identifier,
    ACTIONS(176), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(178), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [1224] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(60), 1,
      sym_identifier,
    ACTIONS(176), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(178), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1248] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(54), 1,
      sym_identifier,
    ACTIONS(180), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(182), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [1272] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(58), 1,
      sym_identifier,
    ACTIONS(184), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(186), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [1296] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(58), 1,
      sym_identifier,
    ACTIONS(184), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(186), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1320] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(51), 1,
      sym_identifier,
    ACTIONS(172), 5,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
    ACTIONS(174), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
  [1344] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      sym__identifier_component,
    STATE(54), 1,
      sym_identifier,
    ACTIONS(180), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(182), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1368] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(190), 1,
      anon_sym_POUNDcheck,
    ACTIONS(188), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1387] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 1,
      anon_sym_POUNDcheck,
    ACTIONS(192), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1406] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(198), 1,
      anon_sym_POUNDcheck,
    ACTIONS(196), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1425] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(202), 1,
      anon_sym_POUNDcheck,
    ACTIONS(200), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1444] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(206), 1,
      anon_sym_POUNDcheck,
    ACTIONS(204), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1463] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(210), 4,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(208), 7,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
      sym__identifier_component,
  [1482] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 1,
      anon_sym_POUNDcheck,
    ACTIONS(212), 10,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
  [1501] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 1,
      anon_sym_POUNDcheck,
    ACTIONS(216), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1520] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(210), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
    ACTIONS(208), 6,
      anon_sym_POUNDcheck,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_namespace,
      sym__identifier_component,
  [1539] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 1,
      anon_sym_POUNDcheck,
    ACTIONS(220), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDcheck_failure,
      anon_sym_POUNDeval,
      anon_sym_POUNDprint,
      anon_sym_POUNDreduce,
      anon_sym_open,
      anon_sym_export,
      anon_sym_section,
      anon_sym_end,
      anon_sym_namespace,
  [1558] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 1,
      anon_sym_DQUOTE,
    ACTIONS(224), 1,
      sym__identifier_component,
    ACTIONS(226), 1,
      sym_number,
    STATE(37), 1,
      sym__apply,
    STATE(24), 3,
      sym__term,
      sym_identifier,
      sym_string,
  [1579] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_DQUOTE,
    ACTIONS(228), 1,
      sym__identifier_component,
    ACTIONS(230), 1,
      sym_number,
    STATE(32), 1,
      sym__apply,
    STATE(13), 3,
      sym__term,
      sym_identifier,
      sym_string,
  [1600] = 5,
    ACTIONS(232), 1,
      anon_sym_DQUOTE,
    ACTIONS(234), 1,
      aux_sym_string_token1,
    ACTIONS(237), 1,
      sym_quoted_char,
    ACTIONS(240), 1,
      sym_comment,
    STATE(63), 1,
      aux_sym_string_repeat1,
  [1616] = 5,
    ACTIONS(240), 1,
      sym_comment,
    ACTIONS(242), 1,
      anon_sym_DQUOTE,
    ACTIONS(244), 1,
      aux_sym_string_token1,
    ACTIONS(246), 1,
      sym_quoted_char,
    STATE(63), 1,
      aux_sym_string_repeat1,
  [1632] = 5,
    ACTIONS(240), 1,
      sym_comment,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    ACTIONS(250), 1,
      aux_sym_string_token1,
    ACTIONS(252), 1,
      sym_quoted_char,
    STATE(64), 1,
      aux_sym_string_repeat1,
  [1648] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(254), 1,
      sym__identifier_component,
    ACTIONS(257), 1,
      anon_sym_RPAREN,
    STATE(66), 2,
      sym_identifier,
      aux_sym_export_repeat1,
  [1662] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 1,
      sym__identifier_component,
    ACTIONS(259), 1,
      anon_sym_RPAREN,
    STATE(66), 2,
      sym_identifier,
      aux_sym_export_repeat1,
  [1676] = 5,
    ACTIONS(240), 1,
      sym_comment,
    ACTIONS(244), 1,
      aux_sym_string_token1,
    ACTIONS(246), 1,
      sym_quoted_char,
    ACTIONS(261), 1,
      anon_sym_DQUOTE,
    STATE(63), 1,
      aux_sym_string_repeat1,
  [1692] = 5,
    ACTIONS(240), 1,
      sym_comment,
    ACTIONS(263), 1,
      anon_sym_DQUOTE,
    ACTIONS(265), 1,
      aux_sym_string_token1,
    ACTIONS(267), 1,
      sym_quoted_char,
    STATE(68), 1,
      aux_sym_string_repeat1,
  [1708] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 1,
      sym__identifier_component,
    STATE(67), 2,
      sym_identifier,
      aux_sym_export_repeat1,
  [1719] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym__identifier_component,
    STATE(34), 1,
      aux_sym_open_repeat1,
    STATE(59), 1,
      sym_identifier,
  [1732] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 1,
      sym__identifier_component,
    STATE(41), 1,
      aux_sym_open_repeat1,
    STATE(56), 1,
      sym_identifier,
  [1745] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym__identifier_component,
    STATE(78), 1,
      sym_identifier,
  [1755] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym__identifier_component,
    STATE(55), 1,
      sym_identifier,
  [1765] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym__identifier_component,
    STATE(52), 1,
      sym_identifier,
  [1775] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym__identifier_component,
    STATE(14), 1,
      sym_identifier,
  [1785] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym__identifier_component,
    STATE(57), 1,
      sym_identifier,
  [1795] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(269), 1,
      anon_sym_LPAREN,
  [1802] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(271), 1,
      ts_builtin_sym_end,
  [1809] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      sym__identifier_component,
  [1816] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(275), 1,
      sym__identifier_component,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 43,
  [SMALL_STATE(7)] = 86,
  [SMALL_STATE(8)] = 116,
  [SMALL_STATE(9)] = 146,
  [SMALL_STATE(10)] = 176,
  [SMALL_STATE(11)] = 213,
  [SMALL_STATE(12)] = 250,
  [SMALL_STATE(13)] = 287,
  [SMALL_STATE(14)] = 322,
  [SMALL_STATE(15)] = 359,
  [SMALL_STATE(16)] = 396,
  [SMALL_STATE(17)] = 433,
  [SMALL_STATE(18)] = 462,
  [SMALL_STATE(19)] = 499,
  [SMALL_STATE(20)] = 536,
  [SMALL_STATE(21)] = 573,
  [SMALL_STATE(22)] = 610,
  [SMALL_STATE(23)] = 635,
  [SMALL_STATE(24)] = 672,
  [SMALL_STATE(25)] = 707,
  [SMALL_STATE(26)] = 736,
  [SMALL_STATE(27)] = 773,
  [SMALL_STATE(28)] = 810,
  [SMALL_STATE(29)] = 838,
  [SMALL_STATE(30)] = 866,
  [SMALL_STATE(31)] = 894,
  [SMALL_STATE(32)] = 917,
  [SMALL_STATE(33)] = 938,
  [SMALL_STATE(34)] = 963,
  [SMALL_STATE(35)] = 990,
  [SMALL_STATE(36)] = 1011,
  [SMALL_STATE(37)] = 1038,
  [SMALL_STATE(38)] = 1059,
  [SMALL_STATE(39)] = 1086,
  [SMALL_STATE(40)] = 1107,
  [SMALL_STATE(41)] = 1128,
  [SMALL_STATE(42)] = 1155,
  [SMALL_STATE(43)] = 1176,
  [SMALL_STATE(44)] = 1200,
  [SMALL_STATE(45)] = 1224,
  [SMALL_STATE(46)] = 1248,
  [SMALL_STATE(47)] = 1272,
  [SMALL_STATE(48)] = 1296,
  [SMALL_STATE(49)] = 1320,
  [SMALL_STATE(50)] = 1344,
  [SMALL_STATE(51)] = 1368,
  [SMALL_STATE(52)] = 1387,
  [SMALL_STATE(53)] = 1406,
  [SMALL_STATE(54)] = 1425,
  [SMALL_STATE(55)] = 1444,
  [SMALL_STATE(56)] = 1463,
  [SMALL_STATE(57)] = 1482,
  [SMALL_STATE(58)] = 1501,
  [SMALL_STATE(59)] = 1520,
  [SMALL_STATE(60)] = 1539,
  [SMALL_STATE(61)] = 1558,
  [SMALL_STATE(62)] = 1579,
  [SMALL_STATE(63)] = 1600,
  [SMALL_STATE(64)] = 1616,
  [SMALL_STATE(65)] = 1632,
  [SMALL_STATE(66)] = 1648,
  [SMALL_STATE(67)] = 1662,
  [SMALL_STATE(68)] = 1676,
  [SMALL_STATE(69)] = 1692,
  [SMALL_STATE(70)] = 1708,
  [SMALL_STATE(71)] = 1719,
  [SMALL_STATE(72)] = 1732,
  [SMALL_STATE(73)] = 1745,
  [SMALL_STATE(74)] = 1755,
  [SMALL_STATE(75)] = 1765,
  [SMALL_STATE(76)] = 1775,
  [SMALL_STATE(77)] = 1785,
  [SMALL_STATE(78)] = 1795,
  [SMALL_STATE(79)] = 1802,
  [SMALL_STATE(80)] = 1809,
  [SMALL_STATE(81)] = 1816,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 2, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interactive, 2, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interactive, 2, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__apply, 2, 0, 5),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__apply, 2, 0, 5),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(62),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(62),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(71),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(73),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(5),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(76),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 3, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [122] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(61),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(61),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(72),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat2, 2, 0, 0), SHIFT_REPEAT(6),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term, 1, 0, 2),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__term, 1, 0, 2),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open, 2, 0, 4),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open, 2, 0, 4),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6), SHIFT_REPEAT(8),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 2, 0, 6), SHIFT_REPEAT(28),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 3, 0, 8),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 3, 0, 8),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 4, 0, 9),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 4, 0, 9),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 3, 0, 7),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 3, 0, 7),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 4, 0, 8),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 4, 0, 8),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace, 4, 0, 7),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace, 4, 0, 7),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_export, 5, 0, 10),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_export, 5, 0, 10),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 5, 0, 9),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 5, 0, 9),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace, 5, 0, 9),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace, 5, 0, 9),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_open_repeat1, 1, 0, 3),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_repeat1, 1, 0, 3),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 2, 0, 1),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 2, 0, 1),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 4, 0, 7),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 4, 0, 7),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 3, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 3, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [234] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [237] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [252] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [254] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_export_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_export_repeat1, 2, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [263] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [267] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [271] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
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
