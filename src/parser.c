#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 112
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 6

enum {
  anon_sym_POUNDeval = 1,
  anon_sym_namespace = 2,
  anon_sym_end = 3,
  anon_sym_section = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COLON = 6,
  anon_sym_RPAREN = 7,
  anon_sym_def = 8,
  anon_sym_COLON_EQ = 9,
  anon_sym_theorem = 10,
  anon_sym_STAR = 11,
  anon_sym_PLUS = 12,
  anon_sym_DASH = 13,
  anon_sym_DQUOTE = 14,
  anon_sym_LBRACE = 15,
  anon_sym_RBRACE = 16,
  sym__string_content = 17,
  sym_identifier = 18,
  sym_number = 19,
  sym_source_file = 20,
  sym__command = 21,
  sym__hash_command = 22,
  sym_eval_command = 23,
  sym_namespace_definition = 24,
  sym_section_definition = 25,
  sym_parameter_list = 26,
  sym_annotated = 27,
  sym_function_definition = 28,
  sym_theorem_definition = 29,
  sym__expression = 30,
  sym_argument_list = 31,
  sym_function_application = 32,
  sym_binary_expression = 33,
  sym_string = 34,
  sym_interpolation = 35,
  aux_sym_source_file_repeat1 = 36,
  aux_sym_parameter_list_repeat1 = 37,
  aux_sym_argument_list_repeat1 = 38,
  aux_sym_string_repeat1 = 39,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_POUNDeval] = "#eval",
  [anon_sym_namespace] = "namespace",
  [anon_sym_end] = "end",
  [anon_sym_section] = "section",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COLON] = ":",
  [anon_sym_RPAREN] = ")",
  [anon_sym_def] = "def",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_theorem] = "theorem",
  [anon_sym_STAR] = "*",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
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
  [sym_annotated] = "annotated",
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
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_def] = anon_sym_def,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_theorem] = anon_sym_theorem,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
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
  [sym_annotated] = sym_annotated,
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
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
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
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
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
  [sym_annotated] = {
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
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == ')') ADVANCE(45);
      if (lookahead == '*') ADVANCE(51);
      if (lookahead == '+') ADVANCE(52);
      if (lookahead == '-') ADVANCE(53);
      if (lookahead == ':') ADVANCE(44);
      if (lookahead == 'd') ADVANCE(64);
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == 'n') ADVANCE(59);
      if (lookahead == 's') ADVANCE(65);
      if (lookahead == 't') ADVANCE(71);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == ')') ADVANCE(45);
      if (lookahead == '*') ADVANCE(51);
      if (lookahead == '+') ADVANCE(52);
      if (lookahead == '-') ADVANCE(53);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(58);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(48);
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
      if (lookahead == 'f') ADVANCE(46);
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
      if (lookahead == 'm') ADVANCE(49);
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
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '*') ADVANCE(51);
      if (lookahead == '+') ADVANCE(52);
      if (lookahead == '-') ADVANCE(53);
      if (lookahead == ':') ADVANCE(43);
      if (lookahead == 'd') ADVANCE(64);
      if (lookahead == 'n') ADVANCE(59);
      if (lookahead == 's') ADVANCE(65);
      if (lookahead == 't') ADVANCE(71);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 33:
      if (eof) ADVANCE(34);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == ')') ADVANCE(45);
      if (lookahead == '*') ADVANCE(51);
      if (lookahead == '+') ADVANCE(52);
      if (lookahead == '-') ADVANCE(53);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == 'd') ADVANCE(11);
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead == 'n') ADVANCE(5);
      if (lookahead == 's') ADVANCE(12);
      if (lookahead == 't') ADVANCE(18);
      if (lookahead == '}') ADVANCE(56);
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
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_end);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_section);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_section);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(48);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_theorem);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_theorem);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__string_content);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(57);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(74);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(62);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(82);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(68);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(70);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(61);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(81);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(37);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(73);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(47);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(66);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(78);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(50);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(67);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(63);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(41);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(80);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(76);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(60);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(69);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(79);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(72);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '!' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
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
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 32},
  [7] = {.lex_state = 32},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 32},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 33},
  [13] = {.lex_state = 33},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 33},
  [16] = {.lex_state = 33},
  [17] = {.lex_state = 33},
  [18] = {.lex_state = 33},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 33},
  [21] = {.lex_state = 33},
  [22] = {.lex_state = 33},
  [23] = {.lex_state = 33},
  [24] = {.lex_state = 33},
  [25] = {.lex_state = 32},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 32},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 32},
  [34] = {.lex_state = 32},
  [35] = {.lex_state = 32},
  [36] = {.lex_state = 32},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 33},
  [40] = {.lex_state = 33},
  [41] = {.lex_state = 33},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 33},
  [46] = {.lex_state = 33},
  [47] = {.lex_state = 33},
  [48] = {.lex_state = 33},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 33},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 33},
  [54] = {.lex_state = 33},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 33},
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
  [71] = {.lex_state = 33},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 1},
  [76] = {.lex_state = 1},
  [77] = {.lex_state = 33},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 33},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 32},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 33},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 32},
  [106] = {.lex_state = 33},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 1},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_POUNDeval] = ACTIONS(1),
    [anon_sym_namespace] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [anon_sym_section] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_theorem] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(107),
    [sym__command] = STATE(17),
    [sym__hash_command] = STATE(17),
    [sym_eval_command] = STATE(17),
    [sym_namespace_definition] = STATE(17),
    [sym_section_definition] = STATE(17),
    [sym_function_definition] = STATE(17),
    [sym_theorem_definition] = STATE(17),
    [aux_sym_source_file_repeat1] = STATE(17),
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
    STATE(6), 1,
      aux_sym_argument_list_repeat1,
    STATE(22), 1,
      sym_argument_list,
    ACTIONS(17), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(27), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(15), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [35] = 8,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym_number,
    STATE(4), 1,
      aux_sym_argument_list_repeat1,
    STATE(22), 1,
      sym_argument_list,
    ACTIONS(15), 4,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(32), 4,
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
  [70] = 7,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym_number,
    STATE(5), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(31), 4,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(32), 4,
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
  [102] = 7,
    ACTIONS(39), 1,
      anon_sym_DQUOTE,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(45), 1,
      sym_number,
    STATE(5), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(35), 4,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(32), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(37), 5,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [134] = 7,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      sym_number,
    STATE(7), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(33), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(27), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(31), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [166] = 7,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(54), 1,
      sym_number,
    STATE(7), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(37), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(27), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(35), 5,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [198] = 4,
    STATE(5), 1,
      aux_sym_argument_list_repeat1,
    STATE(32), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(31), 6,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(33), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [224] = 4,
    STATE(7), 1,
      aux_sym_argument_list_repeat1,
    STATE(27), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(33), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(31), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [250] = 6,
    ACTIONS(57), 1,
      anon_sym_DQUOTE,
    STATE(14), 1,
      aux_sym_argument_list_repeat1,
    STATE(22), 1,
      sym_argument_list,
    ACTIONS(59), 2,
      sym_identifier,
      sym_number,
    STATE(38), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(15), 6,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [278] = 5,
    ACTIONS(61), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(64), 2,
      sym_identifier,
      sym_number,
    STATE(38), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(35), 6,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [303] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(67), 1,
      anon_sym_POUNDeval,
    ACTIONS(69), 1,
      anon_sym_end,
    ACTIONS(71), 1,
      anon_sym_def,
    STATE(18), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [332] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(67), 1,
      anon_sym_POUNDeval,
    ACTIONS(71), 1,
      anon_sym_def,
    ACTIONS(73), 1,
      anon_sym_end,
    STATE(20), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [361] = 5,
    ACTIONS(57), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(59), 2,
      sym_identifier,
      sym_number,
    STATE(38), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(31), 6,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [386] = 7,
    ACTIONS(75), 1,
      anon_sym_POUNDeval,
    ACTIONS(78), 1,
      anon_sym_namespace,
    ACTIONS(81), 1,
      anon_sym_end,
    ACTIONS(83), 1,
      anon_sym_section,
    ACTIONS(86), 1,
      anon_sym_def,
    ACTIONS(89), 1,
      anon_sym_theorem,
    STATE(15), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [415] = 7,
    ACTIONS(78), 1,
      anon_sym_namespace,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      anon_sym_section,
    ACTIONS(89), 1,
      anon_sym_theorem,
    ACTIONS(92), 1,
      anon_sym_POUNDeval,
    ACTIONS(95), 1,
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
  [444] = 7,
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
    ACTIONS(98), 1,
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
  [473] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(67), 1,
      anon_sym_POUNDeval,
    ACTIONS(71), 1,
      anon_sym_def,
    ACTIONS(100), 1,
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
  [502] = 3,
    STATE(11), 1,
      aux_sym_argument_list_repeat1,
    STATE(38), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(31), 9,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [523] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(67), 1,
      anon_sym_POUNDeval,
    ACTIONS(71), 1,
      anon_sym_def,
    ACTIONS(102), 1,
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
  [552] = 1,
    ACTIONS(104), 13,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_RPAREN,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [568] = 1,
    ACTIONS(106), 13,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_RPAREN,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [584] = 1,
    ACTIONS(108), 13,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_RPAREN,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [600] = 1,
    ACTIONS(110), 13,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_RPAREN,
      anon_sym_def,
      anon_sym_COLON_EQ,
      anon_sym_theorem,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [616] = 2,
    ACTIONS(112), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(108), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [633] = 3,
    ACTIONS(114), 1,
      anon_sym_STAR,
    ACTIONS(108), 5,
      anon_sym_POUNDeval,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(112), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [652] = 4,
    ACTIONS(120), 1,
      anon_sym_STAR,
    ACTIONS(122), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(116), 4,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(118), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [673] = 2,
    ACTIONS(108), 6,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(112), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [690] = 2,
    ACTIONS(110), 6,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(124), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [707] = 2,
    ACTIONS(106), 6,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(126), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [724] = 2,
    ACTIONS(104), 6,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(128), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [741] = 4,
    ACTIONS(114), 1,
      anon_sym_STAR,
    ACTIONS(130), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(116), 3,
      anon_sym_POUNDeval,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(118), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [762] = 3,
    ACTIONS(120), 1,
      anon_sym_STAR,
    ACTIONS(112), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(108), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [781] = 2,
    ACTIONS(124), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(110), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [798] = 2,
    ACTIONS(126), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(106), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [815] = 2,
    ACTIONS(128), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(104), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [832] = 1,
    ACTIONS(106), 9,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [844] = 3,
    ACTIONS(132), 1,
      anon_sym_STAR,
    ACTIONS(134), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(116), 6,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [860] = 2,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(108), 8,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      anon_sym_PLUS,
      anon_sym_DASH,
  [874] = 2,
    ACTIONS(138), 1,
      anon_sym_STAR,
    ACTIONS(108), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      anon_sym_PLUS,
      anon_sym_DASH,
  [888] = 3,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(142), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(140), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [904] = 1,
    ACTIONS(108), 9,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [916] = 1,
    ACTIONS(110), 9,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [928] = 1,
    ACTIONS(104), 9,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [940] = 3,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(142), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(144), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [956] = 3,
    ACTIONS(138), 1,
      anon_sym_STAR,
    ACTIONS(148), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(146), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [972] = 3,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(142), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(146), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [988] = 3,
    ACTIONS(138), 1,
      anon_sym_STAR,
    ACTIONS(148), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(140), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1004] = 2,
    ACTIONS(132), 1,
      anon_sym_STAR,
    ACTIONS(108), 8,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
  [1018] = 3,
    ACTIONS(138), 1,
      anon_sym_STAR,
    ACTIONS(148), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(144), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1034] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(154), 1,
      sym_number,
    STATE(47), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1050] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 1,
      sym_identifier,
    ACTIONS(158), 1,
      sym_number,
    STATE(50), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1066] = 1,
    ACTIONS(160), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1076] = 1,
    ACTIONS(162), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1086] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(166), 1,
      sym_number,
    STATE(91), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1102] = 3,
    ACTIONS(57), 1,
      anon_sym_DQUOTE,
    ACTIONS(168), 2,
      sym_identifier,
      sym_number,
    STATE(42), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1116] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(170), 1,
      sym_number,
    STATE(93), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1132] = 1,
    ACTIONS(172), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1142] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 1,
      sym_identifier,
    ACTIONS(174), 1,
      sym_number,
    STATE(23), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1158] = 1,
    ACTIONS(176), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1168] = 3,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(178), 2,
      sym_identifier,
      sym_number,
    STATE(25), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1182] = 3,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 2,
      sym_identifier,
      sym_number,
    STATE(33), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1196] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_number,
    STATE(92), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1212] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 1,
      sym_identifier,
    ACTIONS(184), 1,
      sym_number,
    STATE(40), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1228] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_number,
    STATE(39), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1244] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(174), 1,
      sym_number,
    STATE(23), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1260] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(188), 1,
      sym_number,
    STATE(41), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1276] = 3,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(190), 2,
      sym_identifier,
      sym_number,
    STATE(26), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1290] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(192), 1,
      sym_number,
    STATE(45), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1306] = 3,
    ACTIONS(57), 1,
      anon_sym_DQUOTE,
    ACTIONS(194), 2,
      sym_identifier,
      sym_number,
    STATE(49), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1320] = 1,
    ACTIONS(196), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1330] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 1,
      sym_identifier,
    ACTIONS(198), 1,
      sym_number,
    STATE(48), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1346] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 1,
      sym_identifier,
    ACTIONS(200), 1,
      sym_number,
    STATE(46), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1362] = 3,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(202), 2,
      sym_identifier,
      sym_number,
    STATE(28), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1376] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(204), 1,
      sym_number,
    STATE(77), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1392] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(174), 1,
      sym_number,
    STATE(23), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1408] = 2,
    ACTIONS(206), 1,
      anon_sym_STAR,
    ACTIONS(108), 5,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RBRACE,
  [1419] = 5,
    ACTIONS(208), 1,
      anon_sym_LPAREN,
    ACTIONS(210), 1,
      anon_sym_COLON_EQ,
    ACTIONS(212), 1,
      sym_identifier,
    STATE(106), 1,
      sym_parameter_list,
    STATE(90), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1436] = 5,
    ACTIONS(208), 1,
      anon_sym_LPAREN,
    ACTIONS(212), 1,
      sym_identifier,
    ACTIONS(214), 1,
      anon_sym_COLON_EQ,
    STATE(101), 1,
      sym_parameter_list,
    STATE(90), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1453] = 4,
    ACTIONS(216), 1,
      anon_sym_DQUOTE,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(220), 1,
      sym__string_content,
    STATE(82), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1467] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(222), 1,
      anon_sym_DQUOTE,
    ACTIONS(224), 1,
      sym__string_content,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1481] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(224), 1,
      sym__string_content,
    ACTIONS(226), 1,
      anon_sym_DQUOTE,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1495] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(224), 1,
      sym__string_content,
    ACTIONS(228), 1,
      anon_sym_DQUOTE,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1509] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(230), 1,
      anon_sym_DQUOTE,
    ACTIONS(232), 1,
      sym__string_content,
    STATE(87), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1523] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(234), 1,
      anon_sym_DQUOTE,
    ACTIONS(236), 1,
      sym__string_content,
    STATE(83), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1537] = 4,
    ACTIONS(238), 1,
      anon_sym_LPAREN,
    ACTIONS(241), 1,
      anon_sym_COLON_EQ,
    ACTIONS(243), 1,
      sym_identifier,
    STATE(86), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1551] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(224), 1,
      sym__string_content,
    ACTIONS(246), 1,
      anon_sym_DQUOTE,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1565] = 4,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    ACTIONS(250), 1,
      sym__string_content,
    STATE(81), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1579] = 4,
    ACTIONS(252), 1,
      anon_sym_DQUOTE,
    ACTIONS(254), 1,
      anon_sym_LBRACE,
    ACTIONS(257), 1,
      sym__string_content,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1593] = 4,
    ACTIONS(208), 1,
      anon_sym_LPAREN,
    ACTIONS(260), 1,
      anon_sym_COLON_EQ,
    ACTIONS(262), 1,
      sym_identifier,
    STATE(86), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1607] = 3,
    ACTIONS(206), 1,
      anon_sym_STAR,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    ACTIONS(266), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1618] = 3,
    ACTIONS(206), 1,
      anon_sym_STAR,
    ACTIONS(268), 1,
      anon_sym_COLON_EQ,
    ACTIONS(266), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1629] = 3,
    ACTIONS(206), 1,
      anon_sym_STAR,
    ACTIONS(270), 1,
      anon_sym_RBRACE,
    ACTIONS(266), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1640] = 1,
    ACTIONS(272), 3,
      anon_sym_LPAREN,
      anon_sym_COLON_EQ,
      sym_identifier,
  [1646] = 1,
    ACTIONS(274), 3,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      sym__string_content,
  [1652] = 1,
    ACTIONS(276), 1,
      sym_identifier,
  [1656] = 1,
    ACTIONS(278), 1,
      sym_identifier,
  [1660] = 1,
    ACTIONS(280), 1,
      anon_sym_COLON,
  [1664] = 1,
    ACTIONS(282), 1,
      sym_identifier,
  [1668] = 1,
    ACTIONS(284), 1,
      sym_identifier,
  [1672] = 1,
    ACTIONS(286), 1,
      anon_sym_COLON_EQ,
  [1676] = 1,
    ACTIONS(288), 1,
      sym_identifier,
  [1680] = 1,
    ACTIONS(290), 1,
      sym_identifier,
  [1684] = 1,
    ACTIONS(292), 1,
      sym_identifier,
  [1688] = 1,
    ACTIONS(294), 1,
      anon_sym_COLON,
  [1692] = 1,
    ACTIONS(296), 1,
      anon_sym_COLON_EQ,
  [1696] = 1,
    ACTIONS(298), 1,
      ts_builtin_sym_end,
  [1700] = 1,
    ACTIONS(300), 1,
      sym_identifier,
  [1704] = 1,
    ACTIONS(302), 1,
      sym_identifier,
  [1708] = 1,
    ACTIONS(304), 1,
      sym_identifier,
  [1712] = 1,
    ACTIONS(306), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 35,
  [SMALL_STATE(4)] = 70,
  [SMALL_STATE(5)] = 102,
  [SMALL_STATE(6)] = 134,
  [SMALL_STATE(7)] = 166,
  [SMALL_STATE(8)] = 198,
  [SMALL_STATE(9)] = 224,
  [SMALL_STATE(10)] = 250,
  [SMALL_STATE(11)] = 278,
  [SMALL_STATE(12)] = 303,
  [SMALL_STATE(13)] = 332,
  [SMALL_STATE(14)] = 361,
  [SMALL_STATE(15)] = 386,
  [SMALL_STATE(16)] = 415,
  [SMALL_STATE(17)] = 444,
  [SMALL_STATE(18)] = 473,
  [SMALL_STATE(19)] = 502,
  [SMALL_STATE(20)] = 523,
  [SMALL_STATE(21)] = 552,
  [SMALL_STATE(22)] = 568,
  [SMALL_STATE(23)] = 584,
  [SMALL_STATE(24)] = 600,
  [SMALL_STATE(25)] = 616,
  [SMALL_STATE(26)] = 633,
  [SMALL_STATE(27)] = 652,
  [SMALL_STATE(28)] = 673,
  [SMALL_STATE(29)] = 690,
  [SMALL_STATE(30)] = 707,
  [SMALL_STATE(31)] = 724,
  [SMALL_STATE(32)] = 741,
  [SMALL_STATE(33)] = 762,
  [SMALL_STATE(34)] = 781,
  [SMALL_STATE(35)] = 798,
  [SMALL_STATE(36)] = 815,
  [SMALL_STATE(37)] = 832,
  [SMALL_STATE(38)] = 844,
  [SMALL_STATE(39)] = 860,
  [SMALL_STATE(40)] = 874,
  [SMALL_STATE(41)] = 888,
  [SMALL_STATE(42)] = 904,
  [SMALL_STATE(43)] = 916,
  [SMALL_STATE(44)] = 928,
  [SMALL_STATE(45)] = 940,
  [SMALL_STATE(46)] = 956,
  [SMALL_STATE(47)] = 972,
  [SMALL_STATE(48)] = 988,
  [SMALL_STATE(49)] = 1004,
  [SMALL_STATE(50)] = 1018,
  [SMALL_STATE(51)] = 1034,
  [SMALL_STATE(52)] = 1050,
  [SMALL_STATE(53)] = 1066,
  [SMALL_STATE(54)] = 1076,
  [SMALL_STATE(55)] = 1086,
  [SMALL_STATE(56)] = 1102,
  [SMALL_STATE(57)] = 1116,
  [SMALL_STATE(58)] = 1132,
  [SMALL_STATE(59)] = 1142,
  [SMALL_STATE(60)] = 1158,
  [SMALL_STATE(61)] = 1168,
  [SMALL_STATE(62)] = 1182,
  [SMALL_STATE(63)] = 1196,
  [SMALL_STATE(64)] = 1212,
  [SMALL_STATE(65)] = 1228,
  [SMALL_STATE(66)] = 1244,
  [SMALL_STATE(67)] = 1260,
  [SMALL_STATE(68)] = 1276,
  [SMALL_STATE(69)] = 1290,
  [SMALL_STATE(70)] = 1306,
  [SMALL_STATE(71)] = 1320,
  [SMALL_STATE(72)] = 1330,
  [SMALL_STATE(73)] = 1346,
  [SMALL_STATE(74)] = 1362,
  [SMALL_STATE(75)] = 1376,
  [SMALL_STATE(76)] = 1392,
  [SMALL_STATE(77)] = 1408,
  [SMALL_STATE(78)] = 1419,
  [SMALL_STATE(79)] = 1436,
  [SMALL_STATE(80)] = 1453,
  [SMALL_STATE(81)] = 1467,
  [SMALL_STATE(82)] = 1481,
  [SMALL_STATE(83)] = 1495,
  [SMALL_STATE(84)] = 1509,
  [SMALL_STATE(85)] = 1523,
  [SMALL_STATE(86)] = 1537,
  [SMALL_STATE(87)] = 1551,
  [SMALL_STATE(88)] = 1565,
  [SMALL_STATE(89)] = 1579,
  [SMALL_STATE(90)] = 1593,
  [SMALL_STATE(91)] = 1607,
  [SMALL_STATE(92)] = 1618,
  [SMALL_STATE(93)] = 1629,
  [SMALL_STATE(94)] = 1640,
  [SMALL_STATE(95)] = 1646,
  [SMALL_STATE(96)] = 1652,
  [SMALL_STATE(97)] = 1656,
  [SMALL_STATE(98)] = 1660,
  [SMALL_STATE(99)] = 1664,
  [SMALL_STATE(100)] = 1668,
  [SMALL_STATE(101)] = 1672,
  [SMALL_STATE(102)] = 1676,
  [SMALL_STATE(103)] = 1680,
  [SMALL_STATE(104)] = 1684,
  [SMALL_STATE(105)] = 1688,
  [SMALL_STATE(106)] = 1692,
  [SMALL_STATE(107)] = 1696,
  [SMALL_STATE(108)] = 1700,
  [SMALL_STATE(109)] = 1704,
  [SMALL_STATE(110)] = 1708,
  [SMALL_STATE(111)] = 1712,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(84),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(32),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(32),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(85),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(27),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(27),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(80),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(38),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(67),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(96),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(110),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(111),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(108),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(72),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(109),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_application, 2, .production_id = 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 1),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 1),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_application, 2, .production_id = 1),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_eval_command, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 3),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 2),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 5),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 5),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_theorem_definition, 6),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 4),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 4),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [216] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [218] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [220] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [222] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [232] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [234] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [238] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(102),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [243] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(86),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [250] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [254] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(57),
  [257] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(89),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 1),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotated, 5),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpolation, 3),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [298] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
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
