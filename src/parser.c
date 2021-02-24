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
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 32},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 32},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 32},
  [9] = {.lex_state = 32},
  [10] = {.lex_state = 33},
  [11] = {.lex_state = 33},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 33},
  [14] = {.lex_state = 33},
  [15] = {.lex_state = 33},
  [16] = {.lex_state = 33},
  [17] = {.lex_state = 33},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 33},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 32},
  [26] = {.lex_state = 33},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 32},
  [30] = {.lex_state = 32},
  [31] = {.lex_state = 32},
  [32] = {.lex_state = 32},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 32},
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
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 33},
  [54] = {.lex_state = 33},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 33},
  [58] = {.lex_state = 33},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 33},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 1},
  [76] = {.lex_state = 1},
  [77] = {.lex_state = 1},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 33},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 33},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 32},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 33},
  [101] = {.lex_state = 1},
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
    [sym__command] = STATE(11),
    [sym__hash_command] = STATE(11),
    [sym_eval_command] = STATE(11),
    [sym_namespace_definition] = STATE(11),
    [sym_section_definition] = STATE(11),
    [sym_function_definition] = STATE(11),
    [sym_theorem_definition] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(11),
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
    STATE(4), 1,
      aux_sym_argument_list_repeat1,
    STATE(26), 1,
      sym_argument_list,
    ACTIONS(15), 4,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(33), 4,
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
  [35] = 8,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym_number,
    STATE(8), 1,
      aux_sym_argument_list_repeat1,
    STATE(26), 1,
      sym_argument_list,
    ACTIONS(17), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(25), 4,
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
  [70] = 7,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      sym_number,
    STATE(5), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(31), 4,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(33), 4,
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
    STATE(33), 4,
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
  [134] = 4,
    STATE(9), 1,
      aux_sym_argument_list_repeat1,
    STATE(25), 4,
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
  [160] = 4,
    STATE(5), 1,
      aux_sym_argument_list_repeat1,
    STATE(33), 4,
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
  [186] = 7,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym_number,
    STATE(9), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(33), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(25), 4,
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
  [218] = 7,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(54), 1,
      sym_number,
    STATE(9), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(37), 4,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
    STATE(25), 4,
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
  [250] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(57), 1,
      anon_sym_POUNDeval,
    ACTIONS(59), 1,
      anon_sym_end,
    ACTIONS(61), 1,
      anon_sym_def,
    STATE(15), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [279] = 7,
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
    ACTIONS(63), 1,
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
  [308] = 6,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    STATE(19), 1,
      aux_sym_argument_list_repeat1,
    STATE(26), 1,
      sym_argument_list,
    ACTIONS(67), 2,
      sym_identifier,
      sym_number,
    STATE(49), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(15), 5,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [335] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(57), 1,
      anon_sym_POUNDeval,
    ACTIONS(61), 1,
      anon_sym_def,
    ACTIONS(69), 1,
      anon_sym_end,
    STATE(10), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [364] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(57), 1,
      anon_sym_POUNDeval,
    ACTIONS(61), 1,
      anon_sym_def,
    ACTIONS(71), 1,
      anon_sym_end,
    STATE(17), 8,
      sym__command,
      sym__hash_command,
      sym_eval_command,
      sym_namespace_definition,
      sym_section_definition,
      sym_function_definition,
      sym_theorem_definition,
      aux_sym_source_file_repeat1,
  [393] = 7,
    ACTIONS(73), 1,
      anon_sym_POUNDeval,
    ACTIONS(76), 1,
      anon_sym_namespace,
    ACTIONS(79), 1,
      anon_sym_end,
    ACTIONS(81), 1,
      anon_sym_section,
    ACTIONS(84), 1,
      anon_sym_def,
    ACTIONS(87), 1,
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
  [422] = 7,
    ACTIONS(76), 1,
      anon_sym_namespace,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    ACTIONS(81), 1,
      anon_sym_section,
    ACTIONS(87), 1,
      anon_sym_theorem,
    ACTIONS(90), 1,
      anon_sym_POUNDeval,
    ACTIONS(93), 1,
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
  [451] = 7,
    ACTIONS(7), 1,
      anon_sym_namespace,
    ACTIONS(9), 1,
      anon_sym_section,
    ACTIONS(13), 1,
      anon_sym_theorem,
    ACTIONS(57), 1,
      anon_sym_POUNDeval,
    ACTIONS(61), 1,
      anon_sym_def,
    ACTIONS(96), 1,
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
  [480] = 5,
    ACTIONS(98), 1,
      anon_sym_DQUOTE,
    STATE(18), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(101), 2,
      sym_identifier,
      sym_number,
    STATE(49), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(35), 5,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [504] = 5,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    STATE(18), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(67), 2,
      sym_identifier,
      sym_number,
    STATE(49), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(31), 5,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [528] = 3,
    STATE(18), 1,
      aux_sym_argument_list_repeat1,
    STATE(49), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
    ACTIONS(31), 8,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [548] = 3,
    ACTIONS(108), 1,
      anon_sym_STAR,
    ACTIONS(104), 5,
      anon_sym_POUNDeval,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(106), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [567] = 1,
    ACTIONS(110), 12,
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
  [582] = 2,
    ACTIONS(104), 6,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(106), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [599] = 2,
    ACTIONS(110), 6,
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
  [616] = 4,
    ACTIONS(118), 1,
      anon_sym_STAR,
    ACTIONS(120), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(114), 4,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(116), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [637] = 1,
    ACTIONS(122), 12,
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
  [652] = 2,
    ACTIONS(122), 6,
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
  [669] = 2,
    ACTIONS(126), 6,
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
  [686] = 3,
    ACTIONS(118), 1,
      anon_sym_STAR,
    ACTIONS(106), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(104), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [705] = 2,
    ACTIONS(106), 5,
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
  [722] = 2,
    ACTIONS(112), 5,
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
  [739] = 2,
    ACTIONS(124), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(122), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [756] = 4,
    ACTIONS(108), 1,
      anon_sym_STAR,
    ACTIONS(130), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(114), 3,
      anon_sym_POUNDeval,
      anon_sym_DQUOTE,
      sym_number,
    ACTIONS(116), 6,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
  [777] = 2,
    ACTIONS(128), 5,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      sym_identifier,
    ACTIONS(126), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
  [794] = 1,
    ACTIONS(126), 12,
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
  [809] = 1,
    ACTIONS(104), 12,
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
  [824] = 2,
    ACTIONS(132), 1,
      anon_sym_STAR,
    ACTIONS(104), 8,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      anon_sym_PLUS,
      anon_sym_DASH,
  [838] = 3,
    ACTIONS(132), 1,
      anon_sym_STAR,
    ACTIONS(136), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(134), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [854] = 2,
    ACTIONS(138), 1,
      anon_sym_STAR,
    ACTIONS(104), 8,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
      anon_sym_PLUS,
      anon_sym_DASH,
  [868] = 3,
    ACTIONS(132), 1,
      anon_sym_STAR,
    ACTIONS(136), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(140), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [884] = 3,
    ACTIONS(138), 1,
      anon_sym_STAR,
    ACTIONS(142), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(134), 6,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [900] = 3,
    ACTIONS(138), 1,
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
  [916] = 3,
    ACTIONS(138), 1,
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
  [932] = 3,
    ACTIONS(132), 1,
      anon_sym_STAR,
    ACTIONS(136), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(144), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [948] = 1,
    ACTIONS(104), 8,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [959] = 1,
    ACTIONS(110), 8,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [970] = 1,
    ACTIONS(122), 8,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [981] = 1,
    ACTIONS(126), 8,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [992] = 3,
    ACTIONS(146), 1,
      anon_sym_STAR,
    ACTIONS(148), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(114), 5,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1007] = 2,
    ACTIONS(146), 1,
      anon_sym_STAR,
    ACTIONS(104), 7,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_identifier,
      sym_number,
  [1020] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(154), 1,
      sym_number,
    STATE(40), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1036] = 3,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(156), 2,
      sym_identifier,
      sym_number,
    STATE(21), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1050] = 1,
    ACTIONS(158), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1060] = 1,
    ACTIONS(160), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1070] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(162), 1,
      sym_identifier,
    ACTIONS(164), 1,
      sym_number,
    STATE(90), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1086] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(166), 1,
      sym_number,
    STATE(38), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1102] = 1,
    ACTIONS(168), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1112] = 1,
    ACTIONS(170), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1122] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(162), 1,
      sym_identifier,
    ACTIONS(172), 1,
      sym_number,
    STATE(83), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1138] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(162), 1,
      sym_identifier,
    ACTIONS(174), 1,
      sym_number,
    STATE(36), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1154] = 3,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(176), 2,
      sym_identifier,
      sym_number,
    STATE(30), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1168] = 3,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(178), 2,
      sym_identifier,
      sym_number,
    STATE(29), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1182] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_number,
    STATE(43), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1198] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(162), 1,
      sym_identifier,
    ACTIONS(184), 1,
      sym_number,
    STATE(91), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1214] = 3,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    ACTIONS(186), 2,
      sym_identifier,
      sym_number,
    STATE(45), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1228] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(188), 1,
      sym_number,
    STATE(41), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1244] = 1,
    ACTIONS(190), 7,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_def,
      anon_sym_theorem,
  [1254] = 3,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    ACTIONS(192), 2,
      sym_identifier,
      sym_number,
    STATE(50), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1268] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(194), 1,
      sym_number,
    STATE(42), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1284] = 3,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 2,
      sym_identifier,
      sym_number,
    STATE(23), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1298] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(174), 1,
      sym_number,
    STATE(36), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1314] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(180), 1,
      sym_identifier,
    ACTIONS(198), 1,
      sym_number,
    STATE(39), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1330] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(200), 1,
      sym_number,
    STATE(44), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1346] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(152), 1,
      sym_identifier,
    ACTIONS(202), 1,
      sym_number,
    STATE(37), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1362] = 4,
    ACTIONS(150), 1,
      anon_sym_DQUOTE,
    ACTIONS(174), 1,
      sym_number,
    ACTIONS(180), 1,
      sym_identifier,
    STATE(36), 4,
      sym__expression,
      sym_function_application,
      sym_binary_expression,
      sym_string,
  [1378] = 5,
    ACTIONS(204), 1,
      anon_sym_LPAREN,
    ACTIONS(206), 1,
      anon_sym_COLON_EQ,
    ACTIONS(208), 1,
      sym_identifier,
    STATE(106), 1,
      sym_parameter_list,
    STATE(88), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1395] = 5,
    ACTIONS(204), 1,
      anon_sym_LPAREN,
    ACTIONS(208), 1,
      sym_identifier,
    ACTIONS(210), 1,
      anon_sym_COLON_EQ,
    STATE(100), 1,
      sym_parameter_list,
    STATE(88), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1412] = 4,
    ACTIONS(212), 1,
      anon_sym_DQUOTE,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(216), 1,
      sym__string_content,
    STATE(81), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1426] = 4,
    ACTIONS(218), 1,
      anon_sym_LPAREN,
    ACTIONS(221), 1,
      anon_sym_COLON_EQ,
    ACTIONS(223), 1,
      sym_identifier,
    STATE(79), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1440] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(226), 1,
      anon_sym_DQUOTE,
    ACTIONS(228), 1,
      sym__string_content,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1454] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(228), 1,
      sym__string_content,
    ACTIONS(230), 1,
      anon_sym_DQUOTE,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1468] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(228), 1,
      sym__string_content,
    ACTIONS(232), 1,
      anon_sym_DQUOTE,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1482] = 2,
    ACTIONS(234), 1,
      anon_sym_STAR,
    ACTIONS(104), 4,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1492] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(236), 1,
      anon_sym_DQUOTE,
    ACTIONS(238), 1,
      sym__string_content,
    STATE(87), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1506] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(240), 1,
      anon_sym_DQUOTE,
    ACTIONS(242), 1,
      sym__string_content,
    STATE(80), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1520] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(244), 1,
      anon_sym_DQUOTE,
    ACTIONS(246), 1,
      sym__string_content,
    STATE(82), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1534] = 4,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
    ACTIONS(228), 1,
      sym__string_content,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1548] = 4,
    ACTIONS(204), 1,
      anon_sym_LPAREN,
    ACTIONS(250), 1,
      anon_sym_COLON_EQ,
    ACTIONS(252), 1,
      sym_identifier,
    STATE(79), 2,
      sym_annotated,
      aux_sym_parameter_list_repeat1,
  [1562] = 4,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LBRACE,
    ACTIONS(259), 1,
      sym__string_content,
    STATE(89), 2,
      sym_interpolation,
      aux_sym_string_repeat1,
  [1576] = 3,
    ACTIONS(234), 1,
      anon_sym_STAR,
    ACTIONS(262), 1,
      anon_sym_RPAREN,
    ACTIONS(264), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1587] = 3,
    ACTIONS(234), 1,
      anon_sym_STAR,
    ACTIONS(266), 1,
      anon_sym_COLON_EQ,
    ACTIONS(264), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1598] = 1,
    ACTIONS(268), 3,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      sym__string_content,
  [1604] = 1,
    ACTIONS(270), 3,
      anon_sym_LPAREN,
      anon_sym_COLON_EQ,
      sym_identifier,
  [1610] = 1,
    ACTIONS(272), 1,
      sym_identifier,
  [1614] = 1,
    ACTIONS(274), 1,
      sym_identifier,
  [1618] = 1,
    ACTIONS(276), 1,
      anon_sym_COLON,
  [1622] = 1,
    ACTIONS(278), 1,
      sym_identifier,
  [1626] = 1,
    ACTIONS(280), 1,
      sym_identifier,
  [1630] = 1,
    ACTIONS(282), 1,
      anon_sym_RBRACE,
  [1634] = 1,
    ACTIONS(284), 1,
      anon_sym_COLON_EQ,
  [1638] = 1,
    ACTIONS(286), 1,
      sym_identifier,
  [1642] = 1,
    ACTIONS(288), 1,
      sym_identifier,
  [1646] = 1,
    ACTIONS(290), 1,
      sym_identifier,
  [1650] = 1,
    ACTIONS(292), 1,
      sym_identifier,
  [1654] = 1,
    ACTIONS(294), 1,
      anon_sym_COLON,
  [1658] = 1,
    ACTIONS(296), 1,
      anon_sym_COLON_EQ,
  [1662] = 1,
    ACTIONS(298), 1,
      ts_builtin_sym_end,
  [1666] = 1,
    ACTIONS(300), 1,
      sym_identifier,
  [1670] = 1,
    ACTIONS(302), 1,
      sym_identifier,
  [1674] = 1,
    ACTIONS(304), 1,
      sym_identifier,
  [1678] = 1,
    ACTIONS(306), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 35,
  [SMALL_STATE(4)] = 70,
  [SMALL_STATE(5)] = 102,
  [SMALL_STATE(6)] = 134,
  [SMALL_STATE(7)] = 160,
  [SMALL_STATE(8)] = 186,
  [SMALL_STATE(9)] = 218,
  [SMALL_STATE(10)] = 250,
  [SMALL_STATE(11)] = 279,
  [SMALL_STATE(12)] = 308,
  [SMALL_STATE(13)] = 335,
  [SMALL_STATE(14)] = 364,
  [SMALL_STATE(15)] = 393,
  [SMALL_STATE(16)] = 422,
  [SMALL_STATE(17)] = 451,
  [SMALL_STATE(18)] = 480,
  [SMALL_STATE(19)] = 504,
  [SMALL_STATE(20)] = 528,
  [SMALL_STATE(21)] = 548,
  [SMALL_STATE(22)] = 567,
  [SMALL_STATE(23)] = 582,
  [SMALL_STATE(24)] = 599,
  [SMALL_STATE(25)] = 616,
  [SMALL_STATE(26)] = 637,
  [SMALL_STATE(27)] = 652,
  [SMALL_STATE(28)] = 669,
  [SMALL_STATE(29)] = 686,
  [SMALL_STATE(30)] = 705,
  [SMALL_STATE(31)] = 722,
  [SMALL_STATE(32)] = 739,
  [SMALL_STATE(33)] = 756,
  [SMALL_STATE(34)] = 777,
  [SMALL_STATE(35)] = 794,
  [SMALL_STATE(36)] = 809,
  [SMALL_STATE(37)] = 824,
  [SMALL_STATE(38)] = 838,
  [SMALL_STATE(39)] = 854,
  [SMALL_STATE(40)] = 868,
  [SMALL_STATE(41)] = 884,
  [SMALL_STATE(42)] = 900,
  [SMALL_STATE(43)] = 916,
  [SMALL_STATE(44)] = 932,
  [SMALL_STATE(45)] = 948,
  [SMALL_STATE(46)] = 959,
  [SMALL_STATE(47)] = 970,
  [SMALL_STATE(48)] = 981,
  [SMALL_STATE(49)] = 992,
  [SMALL_STATE(50)] = 1007,
  [SMALL_STATE(51)] = 1020,
  [SMALL_STATE(52)] = 1036,
  [SMALL_STATE(53)] = 1050,
  [SMALL_STATE(54)] = 1060,
  [SMALL_STATE(55)] = 1070,
  [SMALL_STATE(56)] = 1086,
  [SMALL_STATE(57)] = 1102,
  [SMALL_STATE(58)] = 1112,
  [SMALL_STATE(59)] = 1122,
  [SMALL_STATE(60)] = 1138,
  [SMALL_STATE(61)] = 1154,
  [SMALL_STATE(62)] = 1168,
  [SMALL_STATE(63)] = 1182,
  [SMALL_STATE(64)] = 1198,
  [SMALL_STATE(65)] = 1214,
  [SMALL_STATE(66)] = 1228,
  [SMALL_STATE(67)] = 1244,
  [SMALL_STATE(68)] = 1254,
  [SMALL_STATE(69)] = 1268,
  [SMALL_STATE(70)] = 1284,
  [SMALL_STATE(71)] = 1298,
  [SMALL_STATE(72)] = 1314,
  [SMALL_STATE(73)] = 1330,
  [SMALL_STATE(74)] = 1346,
  [SMALL_STATE(75)] = 1362,
  [SMALL_STATE(76)] = 1378,
  [SMALL_STATE(77)] = 1395,
  [SMALL_STATE(78)] = 1412,
  [SMALL_STATE(79)] = 1426,
  [SMALL_STATE(80)] = 1440,
  [SMALL_STATE(81)] = 1454,
  [SMALL_STATE(82)] = 1468,
  [SMALL_STATE(83)] = 1482,
  [SMALL_STATE(84)] = 1492,
  [SMALL_STATE(85)] = 1506,
  [SMALL_STATE(86)] = 1520,
  [SMALL_STATE(87)] = 1534,
  [SMALL_STATE(88)] = 1548,
  [SMALL_STATE(89)] = 1562,
  [SMALL_STATE(90)] = 1576,
  [SMALL_STATE(91)] = 1587,
  [SMALL_STATE(92)] = 1598,
  [SMALL_STATE(93)] = 1604,
  [SMALL_STATE(94)] = 1610,
  [SMALL_STATE(95)] = 1614,
  [SMALL_STATE(96)] = 1618,
  [SMALL_STATE(97)] = 1622,
  [SMALL_STATE(98)] = 1626,
  [SMALL_STATE(99)] = 1630,
  [SMALL_STATE(100)] = 1634,
  [SMALL_STATE(101)] = 1638,
  [SMALL_STATE(102)] = 1642,
  [SMALL_STATE(103)] = 1646,
  [SMALL_STATE(104)] = 1650,
  [SMALL_STATE(105)] = 1654,
  [SMALL_STATE(106)] = 1658,
  [SMALL_STATE(107)] = 1662,
  [SMALL_STATE(108)] = 1666,
  [SMALL_STATE(109)] = 1670,
  [SMALL_STATE(110)] = 1674,
  [SMALL_STATE(111)] = 1678,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(78),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(33),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(33),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(85),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(25),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(25),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(66),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(101),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(110),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(111),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(108),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(56),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(109),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(84),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(49),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 1),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_argument_list_repeat1, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_application, 2, .production_id = 1),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_application, 2, .production_id = 1),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_eval_command, 2),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 3),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 5),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 5),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 4),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_theorem_definition, 6),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 4),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [216] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [218] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(94),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(79),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [232] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [244] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 1),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [256] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(104),
  [259] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(89),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpolation, 3),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotated, 5),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [298] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
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
