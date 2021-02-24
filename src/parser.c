#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 107
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 36
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 6

enum {
  anon_sym_POUNDeval = 1,
  anon_sym_namespace = 2,
  anon_sym_end = 3,
  anon_sym_section = 4,
  anon_sym_def = 5,
  anon_sym_COLON_EQ = 6,
  anon_sym_theorem = 7,
  anon_sym_COLON = 8,
  anon_sym_STAR = 9,
  anon_sym_PLUS = 10,
  anon_sym_DQUOTE = 11,
  anon_sym_LBRACE = 12,
  anon_sym_RBRACE = 13,
  sym__string_content = 14,
  sym_identifier = 15,
  sym_number = 16,
  sym_source_file = 17,
  sym__command = 18,
  sym__hash_command = 19,
  sym_eval_command = 20,
  sym_namespace_definition = 21,
  sym_section_definition = 22,
  sym_parameter_list = 23,
  sym_function_definition = 24,
  sym_theorem_definition = 25,
  sym__expression = 26,
  sym_argument_list = 27,
  sym_function_application = 28,
  sym_binary_expression = 29,
  sym_string = 30,
  sym_interpolation = 31,
  aux_sym_source_file_repeat1 = 32,
  aux_sym_parameter_list_repeat1 = 33,
  aux_sym_argument_list_repeat1 = 34,
  aux_sym_string_repeat1 = 35,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_POUNDeval] = "#eval",
  [anon_sym_namespace] = "namespace",
  [anon_sym_end] = "end",
  [anon_sym_section] = "section",
  [anon_sym_def] = "def",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_theorem] = "theorem",
  [anon_sym_COLON] = ":",
  [anon_sym_STAR] = "*",
  [anon_sym_PLUS] = "+",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym__string_content] = "_string_content",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym_source_file] = "source_file",
  [sym__command] = "_command",
  [sym__hash_command] = "_hash_command",
  [sym_eval_command] = "eval_command",
  [sym_namespace_definition] = "namespace_definition",
  [sym_section_definition] = "section_definition",
  [sym_parameter_list] = "parameter_list",
  [sym_function_definition] = "function_definition",
  [sym_theorem_definition] = "theorem_definition",
  [sym__expression] = "_expression",
  [sym_argument_list] = "argument_list",
  [sym_function_application] = "function_application",
  [sym_binary_expression] = "binary_expression",
  [sym_string] = "string",
  [sym_interpolation] = "interpolation",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_POUNDeval] = anon_sym_POUNDeval,
  [anon_sym_namespace] = anon_sym_namespace,
  [anon_sym_end] = anon_sym_end,
  [anon_sym_section] = anon_sym_section,
  [anon_sym_def] = anon_sym_def,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_theorem] = anon_sym_theorem,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym__string_content] = sym__string_content,
  [sym_identifier] = sym_identifier,
  [sym_number] = sym_number,
  [sym_source_file] = sym_source_file,
  [sym__command] = sym__command,
  [sym__hash_command] = sym__hash_command,
  [sym_eval_command] = sym_eval_command,
  [sym_namespace_definition] = sym_namespace_definition,
  [sym_section_definition] = sym_section_definition,
  [sym_parameter_list] = sym_parameter_list,
  [sym_function_definition] = sym_function_definition,
  [sym_theorem_definition] = sym_theorem_definition,
  [sym__expression] = sym__expression,
  [sym_argument_list] = sym_argument_list,
  [sym_function_application] = sym_function_application,
  [sym_binary_expression] = sym_binary_expression,
  [sym_string] = sym_string,
  [sym_interpolation] = sym_interpolation,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_POUNDeval] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_namespace] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_section] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_theorem] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym__string_content] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__command] = {
    .visible = false,
    .named = true,
  },
  [sym__hash_command] = {
    .visible = false,
    .named = true,
  },
  [sym_eval_command] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_section_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_theorem_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_function_application] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_interpolation] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_arguments = 1,
  field_name = 2,
  field_parameters = 3,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_arguments] = "arguments",
  [field_name] = "name",
  [field_parameters] = "parameters",
};

static const TSFieldMapSlice ts_field_map_slices[4] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 3, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_arguments, 1},
    {field_name, 0},
  [2] =
    {field_name, 1},
  [3] =
    {field_name, 1},
    {field_parameters, 2},
};

static TSSymbol ts_alias_sequences[4][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(34);
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '*') ADVANCE(49);
      if (lookahead == '+') ADVANCE(50);
      if (lookahead == ':') ADVANCE(48);
      if (lookahead == 'd') ADVANCE(61);
      if (lookahead == 'e') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(56);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 't') ADVANCE(68);
      if (lookahead == '{') ADVANCE(52);
      if (lookahead == '}') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(81);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '*') ADVANCE(49);
      if (lookahead == '+') ADVANCE(50);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(81);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '{') ADVANCE(52);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0) ADVANCE(54);
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(44);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 'c') ADVANCE(30);
      END_STATE();
    case 8:
      if (lookahead == 'c') ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == 'd') ADVANCE(38);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'f') ADVANCE(42);
      END_STATE();
    case 18:
      if (lookahead == 'h') ADVANCE(13);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'm') ADVANCE(45);
      END_STATE();
    case 22:
      if (lookahead == 'm') ADVANCE(14);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(9);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 27:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 28:
      if (lookahead == 'r') ADVANCE(16);
      END_STATE();
    case 29:
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 30:
      if (lookahead == 't') ADVANCE(19);
      END_STATE();
    case 31:
      if (lookahead == 'v') ADVANCE(4);
      END_STATE();
    case 32:
      if (eof) ADVANCE(34);
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '*') ADVANCE(49);
      if (lookahead == '+') ADVANCE(50);
      if (lookahead == ':') ADVANCE(47);
      if (lookahead == 'd') ADVANCE(61);
      if (lookahead == 'n') ADVANCE(56);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 't') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(81);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 33:
      if (eof) ADVANCE(34);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '*') ADVANCE(49);
      if (lookahead == '+') ADVANCE(50);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == 'd') ADVANCE(11);
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead == 'n') ADVANCE(5);
      if (lookahead == 's') ADVANCE(12);
      if (lookahead == 't') ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(33)
      END_STATE();
    case 34:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_POUNDeval);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_namespace);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_namespace);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_end);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_section);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_section);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_theorem);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_theorem);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(44);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__string_content);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '{') ADVANCE(52);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(54);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(71);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(59);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(79);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(65);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(67);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(58);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(74);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(78);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(37);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(70);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(43);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(63);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(75);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(46);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(64);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(60);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(41);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(77);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(73);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(57);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(66);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(76);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(69);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(81);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 33},
  [2] = {.lex_state = 32},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 32},
  [6] = {.lex_state = 32},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 32},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 33},
  [11] = {.lex_state = 33},
  [12] = {.lex_state = 33},
  [13] = {.lex_state = 33},
  [14] = {.lex_state = 33},
  [15] = {.lex_state = 33},
  [16] = {.lex_state = 33},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 32},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 32},
  [22] = {.lex_state = 32},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 32},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 32},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 32},
  [33] = {.lex_state = 33},
  [34] = {.lex_state = 33},
  [35] = {.lex_state = 33},
  [36] = {.lex_state = 33},
  [37] = {.lex_state = 33},
  [38] = {.lex_state = 33},
  [39] = {.lex_state = 33},
  [40] = {.lex_state = 33},
  [41] = {.lex_state = 33},
  [42] = {.lex_state = 33},
  [43] = {.lex_state = 33},
  [44] = {.lex_state = 33},
  [45] = {.lex_state = 33},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 33},
  [50] = {.lex_state = 33},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 33},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 33},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 33},
  [89] = {.lex_state = 33},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 32},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 33},
  [102] = {.lex_state = 33},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 1},
  [106] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_POUNDeval] = ACTIONS(1),
    [anon_sym_namespace] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [anon_sym_section] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_theorem] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(92),
    [sym__command] = STATE(10),
    [sym__hash_command] = STATE(10),
    [sym_eval_command] = STATE(10),
    [sym_namespace_definition] = STATE(10),
    [sym_section_definition] = STATE(10),
    [sym_function_definition] = STATE(10),
    [sym_theorem_definition] = STATE(10),
    [aux_sym_source_file_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_def] = ACTIONS(11),
    [anon_sym_theorem] = ACTIONS(13),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      sym_number,
    STATE(5), 1,
      aux_sym_argument_list_repeat1,
    STATE(36), 1,
      sym_argument_list,
    ACTIONS(15), 4,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(17), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(21), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [34] = 8,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym_number,
    STATE(9), 1,
      aux_sym_argument_list_repeat1,
    STATE(36), 1,
      sym_argument_list,
    ACTIONS(15), 3,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
    STATE(24), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(17), 5,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [68] = 7,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(38), 1,
      sym_identifier,
    ACTIONS(41), 1,
      sym_number,
    STATE(4), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(31), 3,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
    STATE(24), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(33), 5,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [99] = 7,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      sym_number,
    STATE(8), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(44), 4,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(46), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(21), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [130] = 4,
    STATE(8), 1,
      aux_sym_argument_list_repeat1,
    STATE(21), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(46), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(44), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
  [155] = 4,
    STATE(4), 1,
      aux_sym_argument_list_repeat1,
    STATE(24), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(44), 5,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(46), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [180] = 7,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(54), 1,
      sym_number,
    STATE(8), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(31), 4,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(33), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(21), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [211] = 7,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym_number,
    STATE(4), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(44), 3,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
    STATE(24), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(46), 5,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [242] = 7,
    ACTIONS(5), 1,
      anon_sym_POUNDeval,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(11), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(57), 1,
      ts_builtin_sym_end,
    STATE(16), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [271] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(59), 1,
      anon_sym_POUNDeval,
    ACTIONS(61), 1,
      anon_sym_end,
    ACTIONS(63), 1,
      anon_sym_def,
    STATE(14), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [300] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(59), 1,
      anon_sym_POUNDeval,
    ACTIONS(63), 1,
      anon_sym_def,
    ACTIONS(65), 1,
      anon_sym_end,
    STATE(15), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [329] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(59), 1,
      anon_sym_POUNDeval,
    ACTIONS(63), 1,
      anon_sym_def,
    ACTIONS(67), 1,
      anon_sym_end,
    STATE(11), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [358] = 7,
    ACTIONS(69), 1,
      anon_sym_POUNDeval,
    ACTIONS(72), 1,
      anon_sym_namespace,
    ACTIONS(75), 1,
      anon_sym_end,
    ACTIONS(77), 1,
      anon_sym_section,
    ACTIONS(80), 1,
      anon_sym_def,
    ACTIONS(83), 1,
      anon_sym_theorem,
    STATE(14), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [387] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(59), 1,
      anon_sym_POUNDeval,
    ACTIONS(63), 1,
      anon_sym_def,
    ACTIONS(86), 1,
      anon_sym_end,
    STATE(14), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [416] = 7,
    ACTIONS(72), 1,
      anon_sym_namespace,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    ACTIONS(77), 1,
      anon_sym_section,
    ACTIONS(83), 1,
      anon_sym_theorem,
    ACTIONS(88), 1,
      anon_sym_POUNDeval,
    ACTIONS(91), 1,
      anon_sym_def,
    STATE(16), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [445] = 6,
    ACTIONS(94), 1,
      anon_sym_DQUOTE,
    STATE(28), 1,
      aux_sym_argument_list_repeat1,
    STATE(36), 1,
      sym_argument_list,
    ACTIONS(96), 2,
      sym_identifier,
      sym_number,
    ACTIONS(15), 3,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
    STATE(71), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [470] = 2,
    ACTIONS(98), 5,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(100), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [486] = 3,
    ACTIONS(106), 1,
      anon_sym_STAR,
    ACTIONS(102), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(104), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [504] = 2,
    ACTIONS(108), 5,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(110), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [520] = 4,
    ACTIONS(106), 1,
      anon_sym_STAR,
    ACTIONS(116), 1,
      anon_sym_PLUS,
    ACTIONS(112), 4,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(114), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [540] = 2,
    ACTIONS(120), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(118), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
  [556] = 3,
    ACTIONS(122), 1,
      anon_sym_STAR,
    ACTIONS(102), 4,
      anon_sym_POUNDeval,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(104), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [574] = 4,
    ACTIONS(122), 1,
      anon_sym_STAR,
    ACTIONS(124), 1,
      anon_sym_PLUS,
    ACTIONS(112), 3,
      anon_sym_POUNDeval,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(114), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [594] = 3,
    STATE(31), 1,
      aux_sym_argument_list_repeat1,
    STATE(71), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(44), 6,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [612] = 2,
    ACTIONS(100), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(98), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
  [628] = 2,
    ACTIONS(102), 5,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(104), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [644] = 5,
    ACTIONS(94), 1,
      anon_sym_DQUOTE,
    STATE(31), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(96), 2,
      sym_identifier,
      sym_number,
    ACTIONS(44), 3,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
    STATE(71), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [666] = 2,
    ACTIONS(118), 5,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(120), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [682] = 2,
    ACTIONS(110), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(108), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
  [698] = 5,
    ACTIONS(126), 1,
      anon_sym_DQUOTE,
    STATE(31), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(129), 2,
      sym_identifier,
      sym_number,
    ACTIONS(31), 3,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
    STATE(71), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [720] = 2,
    ACTIONS(104), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(102), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_number,
  [736] = 1,
    ACTIONS(108), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
  [749] = 1,
    ACTIONS(102), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
  [762] = 1,
    ACTIONS(118), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
  [775] = 1,
    ACTIONS(98), 10,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
  [788] = 3,
    ACTIONS(134), 1,
      anon_sym_STAR,
    ACTIONS(136), 1,
      anon_sym_PLUS,
    ACTIONS(132), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [803] = 3,
    ACTIONS(140), 1,
      anon_sym_STAR,
    ACTIONS(142), 1,
      anon_sym_PLUS,
    ACTIONS(138), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [818] = 3,
    ACTIONS(140), 1,
      anon_sym_STAR,
    ACTIONS(142), 1,
      anon_sym_PLUS,
    ACTIONS(132), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [833] = 2,
    ACTIONS(134), 1,
      anon_sym_STAR,
    ACTIONS(102), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      anon_sym_PLUS,
  [846] = 2,
    ACTIONS(140), 1,
      anon_sym_STAR,
    ACTIONS(102), 7,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      anon_sym_PLUS,
  [859] = 3,
    ACTIONS(134), 1,
      anon_sym_STAR,
    ACTIONS(136), 1,
      anon_sym_PLUS,
    ACTIONS(144), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [874] = 3,
    ACTIONS(134), 1,
      anon_sym_STAR,
    ACTIONS(136), 1,
      anon_sym_PLUS,
    ACTIONS(138), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [889] = 3,
    ACTIONS(140), 1,
      anon_sym_STAR,
    ACTIONS(142), 1,
      anon_sym_PLUS,
    ACTIONS(144), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [904] = 1,
    ACTIONS(146), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [914] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(150), 1,
      sym_identifier,
    ACTIONS(152), 1,
      sym_number,
    STATE(89), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [930] = 3,
    ACTIONS(94), 1,
      anon_sym_DQUOTE,
    ACTIONS(154), 2,
      sym_identifier,
      sym_number,
    STATE(74), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [944] = 3,
    ACTIONS(94), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 2,
      sym_identifier,
      sym_number,
    STATE(70), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [958] = 1,
    ACTIONS(158), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [968] = 1,
    ACTIONS(160), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [978] = 3,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(162), 2,
      sym_identifier,
      sym_number,
    STATE(23), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [992] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(166), 1,
      sym_number,
    STATE(42), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1008] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(168), 1,
      sym_number,
    STATE(37), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1024] = 3,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(170), 2,
      sym_identifier,
      sym_number,
    STATE(27), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1038] = 1,
    ACTIONS(172), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1048] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(174), 1,
      sym_number,
    STATE(40), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1064] = 3,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(176), 2,
      sym_identifier,
      sym_number,
    STATE(32), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1078] = 3,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(178), 2,
      sym_identifier,
      sym_number,
    STATE(19), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1092] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_number,
    STATE(38), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1108] = 1,
    ACTIONS(184), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1118] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(150), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_number,
    STATE(34), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1134] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(188), 1,
      sym_number,
    STATE(44), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1150] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(150), 1,
      sym_identifier,
    ACTIONS(190), 1,
      sym_number,
    STATE(88), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1166] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_number,
    STATE(34), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1182] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(192), 1,
      sym_number,
    STATE(39), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1198] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(194), 1,
      sym_number,
    STATE(41), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1214] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(196), 1,
      sym_number,
    STATE(43), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1230] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_number,
    STATE(34), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1246] = 1,
    ACTIONS(118), 6,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1255] = 1,
    ACTIONS(102), 6,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1264] = 3,
    ACTIONS(198), 1,
      anon_sym_STAR,
    ACTIONS(200), 1,
      anon_sym_PLUS,
    ACTIONS(112), 4,
      anon_sym_COLON_EQ,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1277] = 1,
    ACTIONS(108), 6,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1286] = 1,
    ACTIONS(98), 6,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1295] = 2,
    ACTIONS(198), 1,
      anon_sym_STAR,
    ACTIONS(102), 5,
      anon_sym_COLON_EQ,
      anon_sym_PLUS,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1306] = 4,
    ACTIONS(202), 1,
      anon_sym_DQUOTE,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(206), 1,
      sym__string_content,
    STATE(79), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1320] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(206), 1,
      sym__string_content,
    ACTIONS(208), 1,
      anon_sym_DQUOTE,
    STATE(79), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1334] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(210), 1,
      anon_sym_DQUOTE,
    ACTIONS(212), 1,
      sym__string_content,
    STATE(75), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1348] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(214), 1,
      anon_sym_DQUOTE,
    ACTIONS(216), 1,
      sym__string_content,
    STATE(81), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1362] = 4,
    ACTIONS(218), 1,
      anon_sym_DQUOTE,
    ACTIONS(220), 1,
      anon_sym_LBRACE,
    ACTIONS(223), 1,
      sym__string_content,
    STATE(79), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1376] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(226), 1,
      anon_sym_DQUOTE,
    ACTIONS(228), 1,
      sym__string_content,
    STATE(76), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1390] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(206), 1,
      sym__string_content,
    ACTIONS(230), 1,
      anon_sym_DQUOTE,
    STATE(79), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1404] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(232), 1,
      anon_sym_DQUOTE,
    ACTIONS(234), 1,
      sym__string_content,
    STATE(83), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1418] = 4,
    ACTIONS(204), 1,
      anon_sym_LBRACE,
    ACTIONS(206), 1,
      sym__string_content,
    ACTIONS(236), 1,
      anon_sym_DQUOTE,
    STATE(79), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1432] = 4,
    ACTIONS(238), 1,
      anon_sym_COLON_EQ,
    ACTIONS(240), 1,
      sym_identifier,
    STATE(87), 1,
      aux_sym_parameter_list_repeat1,
    STATE(102), 1,
      sym_parameter_list,
  [1445] = 4,
    ACTIONS(240), 1,
      sym_identifier,
    ACTIONS(242), 1,
      anon_sym_COLON_EQ,
    STATE(87), 1,
      aux_sym_parameter_list_repeat1,
    STATE(101), 1,
      sym_parameter_list,
  [1458] = 3,
    ACTIONS(244), 1,
      anon_sym_COLON_EQ,
    ACTIONS(246), 1,
      sym_identifier,
    STATE(86), 1,
      aux_sym_parameter_list_repeat1,
  [1468] = 3,
    ACTIONS(249), 1,
      anon_sym_COLON_EQ,
    ACTIONS(251), 1,
      sym_identifier,
    STATE(86), 1,
      aux_sym_parameter_list_repeat1,
  [1478] = 3,
    ACTIONS(253), 1,
      anon_sym_COLON_EQ,
    ACTIONS(255), 1,
      anon_sym_STAR,
    ACTIONS(257), 1,
      anon_sym_PLUS,
  [1488] = 2,
    ACTIONS(255), 1,
      anon_sym_STAR,
    ACTIONS(102), 2,
      anon_sym_COLON_EQ,
      anon_sym_PLUS,
  [1496] = 1,
    ACTIONS(259), 3,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      sym__string_content,
  [1502] = 1,
    ACTIONS(261), 1,
      sym_identifier,
  [1506] = 1,
    ACTIONS(263), 1,
      ts_builtin_sym_end,
  [1510] = 1,
    ACTIONS(265), 1,
      sym_identifier,
  [1514] = 1,
    ACTIONS(267), 1,
      sym_identifier,
  [1518] = 1,
    ACTIONS(269), 1,
      sym_identifier,
  [1522] = 1,
    ACTIONS(271), 1,
      anon_sym_COLON,
  [1526] = 1,
    ACTIONS(273), 1,
      sym_identifier,
  [1530] = 1,
    ACTIONS(275), 1,
      sym_identifier,
  [1534] = 1,
    ACTIONS(277), 1,
      sym_identifier,
  [1538] = 1,
    ACTIONS(279), 1,
      sym_identifier,
  [1542] = 1,
    ACTIONS(281), 1,
      anon_sym_COLON_EQ,
  [1546] = 1,
    ACTIONS(283), 1,
      anon_sym_COLON_EQ,
  [1550] = 1,
    ACTIONS(285), 1,
      anon_sym_RBRACE,
  [1554] = 1,
    ACTIONS(287), 1,
      sym_identifier,
  [1558] = 1,
    ACTIONS(289), 1,
      sym_identifier,
  [1562] = 1,
    ACTIONS(291), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 34,
  [SMALL_STATE(4)] = 68,
  [SMALL_STATE(5)] = 99,
  [SMALL_STATE(6)] = 130,
  [SMALL_STATE(7)] = 155,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 211,
  [SMALL_STATE(10)] = 242,
  [SMALL_STATE(11)] = 271,
  [SMALL_STATE(12)] = 300,
  [SMALL_STATE(13)] = 329,
  [SMALL_STATE(14)] = 358,
  [SMALL_STATE(15)] = 387,
  [SMALL_STATE(16)] = 416,
  [SMALL_STATE(17)] = 445,
  [SMALL_STATE(18)] = 470,
  [SMALL_STATE(19)] = 486,
  [SMALL_STATE(20)] = 504,
  [SMALL_STATE(21)] = 520,
  [SMALL_STATE(22)] = 540,
  [SMALL_STATE(23)] = 556,
  [SMALL_STATE(24)] = 574,
  [SMALL_STATE(25)] = 594,
  [SMALL_STATE(26)] = 612,
  [SMALL_STATE(27)] = 628,
  [SMALL_STATE(28)] = 644,
  [SMALL_STATE(29)] = 666,
  [SMALL_STATE(30)] = 682,
  [SMALL_STATE(31)] = 698,
  [SMALL_STATE(32)] = 720,
  [SMALL_STATE(33)] = 736,
  [SMALL_STATE(34)] = 749,
  [SMALL_STATE(35)] = 762,
  [SMALL_STATE(36)] = 775,
  [SMALL_STATE(37)] = 788,
  [SMALL_STATE(38)] = 803,
  [SMALL_STATE(39)] = 818,
  [SMALL_STATE(40)] = 833,
  [SMALL_STATE(41)] = 846,
  [SMALL_STATE(42)] = 859,
  [SMALL_STATE(43)] = 874,
  [SMALL_STATE(44)] = 889,
  [SMALL_STATE(45)] = 904,
  [SMALL_STATE(46)] = 914,
  [SMALL_STATE(47)] = 930,
  [SMALL_STATE(48)] = 944,
  [SMALL_STATE(49)] = 958,
  [SMALL_STATE(50)] = 968,
  [SMALL_STATE(51)] = 978,
  [SMALL_STATE(52)] = 992,
  [SMALL_STATE(53)] = 1008,
  [SMALL_STATE(54)] = 1024,
  [SMALL_STATE(55)] = 1038,
  [SMALL_STATE(56)] = 1048,
  [SMALL_STATE(57)] = 1064,
  [SMALL_STATE(58)] = 1078,
  [SMALL_STATE(59)] = 1092,
  [SMALL_STATE(60)] = 1108,
  [SMALL_STATE(61)] = 1118,
  [SMALL_STATE(62)] = 1134,
  [SMALL_STATE(63)] = 1150,
  [SMALL_STATE(64)] = 1166,
  [SMALL_STATE(65)] = 1182,
  [SMALL_STATE(66)] = 1198,
  [SMALL_STATE(67)] = 1214,
  [SMALL_STATE(68)] = 1230,
  [SMALL_STATE(69)] = 1246,
  [SMALL_STATE(70)] = 1255,
  [SMALL_STATE(71)] = 1264,
  [SMALL_STATE(72)] = 1277,
  [SMALL_STATE(73)] = 1286,
  [SMALL_STATE(74)] = 1295,
  [SMALL_STATE(75)] = 1306,
  [SMALL_STATE(76)] = 1320,
  [SMALL_STATE(77)] = 1334,
  [SMALL_STATE(78)] = 1348,
  [SMALL_STATE(79)] = 1362,
  [SMALL_STATE(80)] = 1376,
  [SMALL_STATE(81)] = 1390,
  [SMALL_STATE(82)] = 1404,
  [SMALL_STATE(83)] = 1418,
  [SMALL_STATE(84)] = 1432,
  [SMALL_STATE(85)] = 1445,
  [SMALL_STATE(86)] = 1458,
  [SMALL_STATE(87)] = 1468,
  [SMALL_STATE(88)] = 1478,
  [SMALL_STATE(89)] = 1488,
  [SMALL_STATE(90)] = 1496,
  [SMALL_STATE(91)] = 1502,
  [SMALL_STATE(92)] = 1506,
  [SMALL_STATE(93)] = 1510,
  [SMALL_STATE(94)] = 1514,
  [SMALL_STATE(95)] = 1518,
  [SMALL_STATE(96)] = 1522,
  [SMALL_STATE(97)] = 1526,
  [SMALL_STATE(98)] = 1530,
  [SMALL_STATE(99)] = 1534,
  [SMALL_STATE(100)] = 1538,
  [SMALL_STATE(101)] = 1542,
  [SMALL_STATE(102)] = 1546,
  [SMALL_STATE(103)] = 1550,
  [SMALL_STATE(104)] = 1554,
  [SMALL_STATE(105)] = 1558,
  [SMALL_STATE(106)] = 1562,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(78),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(24),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(24),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 1),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 1),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(80),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(21),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(21),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(62),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(99),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(97),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(106),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(93),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(52),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(94),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_application, 2, .production_id = 1),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_application, 2, .production_id = 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 1),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 1),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(82),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(71),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 3),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_eval_command, 2),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_theorem_definition, 6),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 5),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 5),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 4),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 4),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [208] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [216] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [220] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(91),
  [223] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(79),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [232] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [234] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [246] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(86),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 1),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpolation, 3),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [263] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_lean(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const uint16_t *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .field_count = FIELD_COUNT,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .field_names = ts_field_names,
    .large_state_count = LARGE_STATE_COUNT,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .state_count = STATE_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
