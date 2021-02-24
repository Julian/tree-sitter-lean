#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 27
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 20
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6

enum {
  anon_sym_POUNDeval = 1,
  anon_sym_namespace = 2,
  anon_sym_end = 3,
  anon_sym_section = 4,
  anon_sym_theorem = 5,
  anon_sym_COLON = 6,
  anon_sym_COLON_EQ = 7,
  sym_identifier = 8,
  sym_number = 9,
  sym_source_file = 10,
  sym__command = 11,
  sym__hash_command = 12,
  sym_eval_command = 13,
  sym_namespace_definition = 14,
  sym_section_definition = 15,
  sym_function_definition = 16,
  sym_theorem_definition = 17,
  sym__expression = 18,
  aux_sym_source_file_repeat1 = 19,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_POUNDeval] = "#eval",
  [anon_sym_namespace] = "namespace",
  [anon_sym_end] = "end",
  [anon_sym_section] = "section",
  [anon_sym_theorem] = "theorem",
  [anon_sym_COLON] = ":",
  [anon_sym_COLON_EQ] = ":=",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym_source_file] = "source_file",
  [sym__command] = "_command",
  [sym__hash_command] = "_hash_command",
  [sym_eval_command] = "eval_command",
  [sym_namespace_definition] = "namespace_definition",
  [sym_section_definition] = "section_definition",
  [sym_function_definition] = "function_definition",
  [sym_theorem_definition] = "theorem_definition",
  [sym__expression] = "_expression",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_POUNDeval] = anon_sym_POUNDeval,
  [anon_sym_namespace] = anon_sym_namespace,
  [anon_sym_end] = anon_sym_end,
  [anon_sym_section] = anon_sym_section,
  [anon_sym_theorem] = anon_sym_theorem,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [sym_identifier] = sym_identifier,
  [sym_number] = sym_number,
  [sym_source_file] = sym_source_file,
  [sym__command] = sym__command,
  [sym__hash_command] = sym__hash_command,
  [sym_eval_command] = sym_eval_command,
  [sym_namespace_definition] = sym_namespace_definition,
  [sym_section_definition] = sym_section_definition,
  [sym_function_definition] = sym_function_definition,
  [sym_theorem_definition] = sym_theorem_definition,
  [sym__expression] = sym__expression,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [anon_sym_theorem] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
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
      if (eof) ADVANCE(30);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == ':') ADVANCE(37);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'n') ADVANCE(4);
      if (lookahead == 's') ADVANCE(11);
      if (lookahead == 't') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 1:
      if (lookahead == ':') ADVANCE(36);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 2:
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(38);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(18);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 'c') ADVANCE(28);
      END_STATE();
    case 8:
      if (lookahead == 'c') ADVANCE(14);
      END_STATE();
    case 9:
      if (lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(32);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 16:
      if (lookahead == 'h') ADVANCE(12);
      END_STATE();
    case 17:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 18:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 19:
      if (lookahead == 'm') ADVANCE(35);
      END_STATE();
    case 20:
      if (lookahead == 'm') ADVANCE(13);
      END_STATE();
    case 21:
      if (lookahead == 'n') ADVANCE(9);
      END_STATE();
    case 22:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 23:
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 24:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 25:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 26:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 27:
      if (lookahead == 's') ADVANCE(25);
      END_STATE();
    case 28:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 29:
      if (lookahead == 'v') ADVANCE(5);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_POUNDeval);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_namespace);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_section);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_theorem);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(38);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
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
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_POUNDeval] = ACTIONS(1),
    [anon_sym_namespace] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [anon_sym_section] = ACTIONS(1),
    [anon_sym_theorem] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(17),
    [sym__command] = STATE(7),
    [sym__hash_command] = STATE(7),
    [sym_eval_command] = STATE(7),
    [sym_namespace_definition] = STATE(7),
    [sym_section_definition] = STATE(7),
    [sym_function_definition] = STATE(7),
    [sym_theorem_definition] = STATE(7),
    [aux_sym_source_file_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_theorem] = ACTIONS(11),
  },
  [2] = {
    [sym__command] = STATE(2),
    [sym__hash_command] = STATE(2),
    [sym_eval_command] = STATE(2),
    [sym_namespace_definition] = STATE(2),
    [sym_section_definition] = STATE(2),
    [sym_function_definition] = STATE(2),
    [sym_theorem_definition] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(13),
    [anon_sym_POUNDeval] = ACTIONS(15),
    [anon_sym_namespace] = ACTIONS(18),
    [anon_sym_end] = ACTIONS(13),
    [anon_sym_section] = ACTIONS(21),
    [anon_sym_theorem] = ACTIONS(24),
  },
  [3] = {
    [sym__command] = STATE(5),
    [sym__hash_command] = STATE(5),
    [sym_eval_command] = STATE(5),
    [sym_namespace_definition] = STATE(5),
    [sym_section_definition] = STATE(5),
    [sym_function_definition] = STATE(5),
    [sym_theorem_definition] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(5),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_end] = ACTIONS(27),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_theorem] = ACTIONS(11),
  },
  [4] = {
    [sym__command] = STATE(2),
    [sym__hash_command] = STATE(2),
    [sym_eval_command] = STATE(2),
    [sym_namespace_definition] = STATE(2),
    [sym_section_definition] = STATE(2),
    [sym_function_definition] = STATE(2),
    [sym_theorem_definition] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_end] = ACTIONS(29),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_theorem] = ACTIONS(11),
  },
  [5] = {
    [sym__command] = STATE(2),
    [sym__hash_command] = STATE(2),
    [sym_eval_command] = STATE(2),
    [sym_namespace_definition] = STATE(2),
    [sym_section_definition] = STATE(2),
    [sym_function_definition] = STATE(2),
    [sym_theorem_definition] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_end] = ACTIONS(31),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_theorem] = ACTIONS(11),
  },
  [6] = {
    [sym__command] = STATE(4),
    [sym__hash_command] = STATE(4),
    [sym_eval_command] = STATE(4),
    [sym_namespace_definition] = STATE(4),
    [sym_section_definition] = STATE(4),
    [sym_function_definition] = STATE(4),
    [sym_theorem_definition] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_end] = ACTIONS(33),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_theorem] = ACTIONS(11),
  },
  [7] = {
    [sym__command] = STATE(2),
    [sym__hash_command] = STATE(2),
    [sym_eval_command] = STATE(2),
    [sym_namespace_definition] = STATE(2),
    [sym_section_definition] = STATE(2),
    [sym_function_definition] = STATE(2),
    [sym_theorem_definition] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(35),
    [anon_sym_POUNDeval] = ACTIONS(5),
    [anon_sym_namespace] = ACTIONS(7),
    [anon_sym_section] = ACTIONS(9),
    [anon_sym_theorem] = ACTIONS(11),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(37), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_theorem,
  [9] = 1,
    ACTIONS(39), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_theorem,
  [18] = 1,
    ACTIONS(41), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_theorem,
  [27] = 1,
    ACTIONS(43), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_theorem,
  [36] = 1,
    ACTIONS(45), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_theorem,
  [45] = 1,
    ACTIONS(47), 6,
      ts_builtin_sym_end,
      anon_sym_POUNDeval,
      anon_sym_namespace,
      anon_sym_end,
      anon_sym_section,
      anon_sym_theorem,
  [54] = 2,
    STATE(9), 1,
      sym__expression,
    ACTIONS(49), 2,
      sym_identifier,
      sym_number,
  [62] = 2,
    STATE(25), 1,
      sym__expression,
    ACTIONS(51), 2,
      sym_identifier,
      sym_number,
  [70] = 1,
    ACTIONS(53), 1,
      anon_sym_COLON,
  [74] = 1,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
  [78] = 1,
    ACTIONS(57), 1,
      sym_identifier,
  [82] = 1,
    ACTIONS(59), 1,
      sym_identifier,
  [86] = 1,
    ACTIONS(61), 1,
      sym_identifier,
  [90] = 1,
    ACTIONS(63), 1,
      sym_identifier,
  [94] = 1,
    ACTIONS(65), 1,
      sym_identifier,
  [98] = 1,
    ACTIONS(67), 1,
      sym_identifier,
  [102] = 1,
    ACTIONS(69), 1,
      sym_identifier,
  [106] = 1,
    ACTIONS(71), 1,
      anon_sym_COLON_EQ,
  [110] = 1,
    ACTIONS(73), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 9,
  [SMALL_STATE(10)] = 18,
  [SMALL_STATE(11)] = 27,
  [SMALL_STATE(12)] = 36,
  [SMALL_STATE(13)] = 45,
  [SMALL_STATE(14)] = 54,
  [SMALL_STATE(15)] = 62,
  [SMALL_STATE(16)] = 70,
  [SMALL_STATE(17)] = 74,
  [SMALL_STATE(18)] = 78,
  [SMALL_STATE(19)] = 82,
  [SMALL_STATE(20)] = 86,
  [SMALL_STATE(21)] = 90,
  [SMALL_STATE(22)] = 94,
  [SMALL_STATE(23)] = 98,
  [SMALL_STATE(24)] = 102,
  [SMALL_STATE(25)] = 106,
  [SMALL_STATE(26)] = 110,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(22),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(21),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(19),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 4),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_eval_command, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 4),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_definition, 5),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_definition, 5),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_theorem_definition, 6),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [55] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
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
