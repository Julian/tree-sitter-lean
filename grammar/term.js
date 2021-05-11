const {PREC} = require('./basic.js')

// src/Lean/Parser/Term.lean
module.exports = {
  _tactic_seq1_indented: $ => repeat1(seq($._tactic, optional(';'))),
  _tactic_seq: $ => choice($._tactic_seq1_indented),
  tactics: $ => prec(PREC.lead, seq('by', $._tactic_seq)),

  // FIXME: see name.cpp for the real definition...
  identifier: $ => choice(
    sep1($._identifier, token.immediate('.')),
    $._identifier,
    $._escaped_identifier,
  ),
  number: $ => /\d+/,
  float: $ => /\d+\.\d*/,
  string: $ => seq(
    '"',
    repeat(choice($.escape_sequence, /[^"]/)),
    '"',
  ),
  char: $ => seq("'", choice($.escape_sequence, /[^']/), "'"),
  hole: $ => "_",
  sorry: $ => 'sorry',
  cdot: $ => choice('.', '·'),
  _parenthesized_expression: $ => seq('(', optional($._term), ')'),
  anonymous_constructor: $ => seq('⟨', sep0($._term, ','), '⟩'),
  _structure_instance_field: $ => seq(
    field('name', $.identifier),
    ':=',
    field('value', $._term),
  ),
  structure_instance: $ => seq(
    '{',
    optional(field('extends', seq($._term, 'with'))),
    // Unlike everywhere else, records seem OK with trailing commas.
    optional(sep1_($._structure_instance_field, ',')),
    field('type', optional($._type_spec)),
    '}',
  ),
  _type_spec: $ => field('type', seq(':', $._term)),

  explicit: $ => seq('@', $._term),
  _binder_ident: $ => choice($.identifier, $.hole),
  _binder_default: $ => field('default', seq(':=', $._term)),
  explicit_binder: $ => seq(
    '(',
    field('name', repeat1($._binder_ident)),
    field('type', optional($._type_spec)),
    optional(choice($._binder_default)),
    ')',
  ),
  implicit_binder: $ => seq(
    '{',
    field('name', repeat1($.identifier)),
    field('type', optional($._type_spec)),
    '}',
  ),
  instance_binder: $ => seq(
    '[',
    optional(seq(field('name', $.identifier), ':')),
    field('type', $._term),
    ']',
  ),
  _bracketed_binder: $ => choice(
    $.explicit_binder,
    $.implicit_binder,
    $.instance_binder,
  ),
  arrow: $ => prec.right(25, seq($._term, choice('->', '→'), $._term)),

  forall: $ => prec(PREC.lead, seq(
    '∀',
    field(
      'binders',
      alias(repeat1(choice($._simple_binder, $._bracketed_binder)), $.binders),
    ),
    ',',
    field('body', $._term),
  )),

  _simple_binder: $ => seq(
    field('name', repeat1($._binder_ident)),
    optional($._type_spec),
  ),

  match_alt: $ => seq(
    '|',
    field('lhs', sep1($._term, ',')),
    '=>',
    $._term,
  ),

  _match_alts: $ => repeat1($.match_alt),
  _match_discr: $ => seq(optional(seq($.identifier, ':')), $._term),

  true: $ => 'true',
  false: $ => 'false',

  match: $ => prec(PREC.lead, seq(
    'match',
    field('value', sep1($._match_discr, ',')),
    optional($._type_spec),
    'with',
    field('patterns', $._match_alts),
  )),

  _fun_implicit_binder: $ => seq(
    '{',
    field('name', repeat1($._binder_ident)),
    choice(":",  "}"),
    $.implicit_binder,
  ),
  _fun_simple_binder: $ => seq(
    field('name', repeat1($._binder_ident)),
    ":",
    $._simple_binder,
  ),
  _fun_binder: $ => choice(
    alias($._fun_implicit_binder, $.implicit_binder),
    $.instance_binder,
    $._fun_simple_binder,
    prec(PREC.max, $._term),
  ),
  _basic_fun: $ => seq(
    alias(repeat1($._fun_binder), $.binders), '=>', $._term,
  ),
  fun: $ => prec(PREC.max, seq(
    choice('fun', 'λ'),
    choice($._basic_fun, $._match_alts),
  )),

  _simple_binder_without_type: $ => repeat1($._binder_ident),
  _let_id_lhs: $ => seq(
    field('name', $.identifier),
    field('binders', repeat(
      choice($._simple_binder_without_type, $._bracketed_binder)),
    ),
    field('type', optional($._type_spec)),
  ),
  _let_id_decl: $ => seq($._let_id_lhs, ":=", field('body', $._term)),
  _let_pattern_decl: $ => seq($._term, optional($._type_spec), ":=", $._term),
  _let_equations_decl: $ => seq($._let_id_lhs, field('body', $._match_alts)),
  _let_decl: $ => choice(
    $._let_id_decl, $._let_pattern_decl, $._let_equations_decl,
  ),
  let: $ => prec(PREC.lead, seq('let', $._let_decl, optional(';'), $._term)),

  attributes: $ => seq('@[', sep1($._attribute, ','), ']'),
  _let_rec_decl: $ => seq($._let_decl),

  _where_decls: $ => seq(
    'where', repeat1(seq(alias($._let_rec_decl, $.where_decl))),
  ),
  _match_alts_where_decls: $ => seq($._match_alts, optional($._where_decls)),

  named_argument: $ => seq('(', $.identifier, ':=', $._term, ')'),
  _argument: $ => choice($.named_argument, $._term),
  apply: $ => prec(PREC.lead,
    seq(
      field('name', prec(PREC.max, $._applyable_term)),
      field('arguments', prec(PREC.arg, repeat1($._argument))),
  )),
  projection: $ => seq(
    field('term', $._term),
    token.immediate('.'),
    field('field', choice($.identifier, $.number)),
  ),
  pipe_projection: $ => prec(PREC.min, seq(
    "|>.",
    field('field', choice($.identifier, $.number)),
    field('arguments', repeat($._argument)),
  )),

  quoted_tactic: $ => seq('`(tactic|', $._tactic, ')'),

  _applyable_term: $ => choice(
    $.identifier,
    $._parenthesized_expression,
  ),
  _term: $ => choice(
    // $.tactics,
    $.number,
    $.float,
    $.string,
    $.char,
    $.sorry,
    $.cdot,
    $.anonymous_constructor,
    $.structure_instance,
    $.explicit,
    $.forall,
    $.true,
    $.false,
    $.match,
    $.fun,
    $.let,
    $.apply,
    $.projection,
    $.arrow,
    $.pipe_projection,
    $.quoted_tactic,

    $.do,
    alias($.do_unless, $.unless),

    $._applyable_term,
    $._notation_term,
    $._notation_extra_term,
    $.array,
    $.subarray,
    $.range,
    $.interpolated_string,
    $._cant_find_term,
  ),

  // src/Init/Notation.lean
  product_type: $ => prec.right(35, seq($._term, '×', $._term)),
  binary_expression: $ => choice(
    infixr($, 90, "∘"),

    infixl($, 55, "|||"),
    infixl($, 58, "^^^"),
    infixl($, 60, "&&&"),
    infixl($, 65, "+"),
    infixl($, 65, "-"),
    infixl($, 70, "*"),
    infixl($, 70, "/"),
    infixl($, 70, "%"),
    infixl($, 75, "<<<"),
    infixl($, 75, ">>>"),
    infixr($, 80, "^"),

    infix($, 50, "<="),
    infix($, 50, "≤"),
    infix($, 50, "<"),
    infix($, 50, ">="),
    infix($, 50, "≥"),
    infix($, 50, ">"),
    infix($, 50, "="),
    infix($, 50, "=="),
    infix($, 50, "~="),
    infix($, 50, "≅"),

    infixr($, 35, "/\\"),
    infixr($, 35, "∧"),
    infixr($, 30, "\\/"),
    infixr($, 30, "∨"),

    infixl($, 35, "&&"),
    infixl($, 30, "||"),

    infixl($, 65, "++"),
    infixr($, 67, "::"),

    infixr($, PREC.min, "<|"),
    infixr($, PREC.min, "|>"),

    infixr($, 20, "<|>"),
    infixr($, 60, ">>"),
    infixl($, 55, ">>="),
    infixl($, 60, "<*>"),
    infixl($, 60, "<*"),
    infixr($, 60, "*>"),
    infixr($, 100, "<$>"),

    // src/Init/Core.lean
    infix($, 20, "<->"),
    infix($, 20, "↔"),
    infix($, 50, "≈"),
    infix($, 50, "!="),
    infix($, 50, "≠"),
  ),
  unary_expression: $ => seq(
    choice(
      prec(100, '-'),
      prec(40, '¬'),
      prec(40, '!'),
    ),
    $._term,
  ),
  if_then_else: $ => seq(
    'if',
    $._term,
    'then',
    $._term,
    'else',
    $._term,
  ),

  _dollar: $ => seq(
    field('name', $._term),
    '$',
    field('argument', $._term),
  ),

  list: $ => seq('[', sep0($._term, ','), ']'),

  _notation_term: $ => choice(
    $.product_type,
    $.binary_expression,
    $.unary_expression,
    $.if_then_else,
    alias($._dollar, $.apply),
    $.list,
  ),

  // src/Init/NotationExtra.lean
  exists: $ => seq(
    '∃',
    field(
      'binders',
      alias(repeat1(choice($._simple_binder, $._bracketed_binder)), $.binders),
    ),
    ',',
    field('body', $._term),
  ),

  _notation_extra_term: $ => choice(
    $.exists,
  ),

  // src/Init/Data/Array/Basic.lean
  array: $ => seq('#[', sep0($._term, ','), ']'),

  // src/Init/Data/Array/Subarray.lean
  subarray: $ => seq(
    field('term', $._term),
    token.immediate('['),
    choice(
      field('value', $._term),
      seq(
        optional(field('start', $._term)),
        ':',
        field('stop', $._term),
      ),
      seq(
        field('start', $._term),
        ':',
        optional(field('stop', $._term)),
      ),
    ),
    ']',
  ),

  // src/Init/Data/Range.lean
  range: $ => seq(
    '[',
    optional(field('start', $._term)),
    ':',
    field('stop', $._term),
    optional(seq(
      ':',
      field('step', $._term),
    )),
    ']',
  ),

  // src/Init/Data/ToString/Macro.lean
  interpolated_string: $ => seq(
    's!"',
    repeat(choice(/[^"]/, $.escape_sequence, $.interpolation)),
    '"',
  ),
  interpolation: $ => seq(
    '{', $._term, '}'
  ),

  // FINDME: I can't find where these are defined...
  coe: $ => seq('(', field('term', $._term), ':', field('type', $._term), ')'),
  product: $ => seq('(', sep2($._term, ','), ')'),
  _cant_find_term: $ => choice(
    $.coe,
    $.product,
  ),
}

function infix($, precedence, operator) {
  return prec(precedence, seq($._term, operator, $._term))
}

function infixl($, precedence, operator) {
  return prec.left(precedence, seq($._term, operator, $._term))
}

function infixr($, precedence, operator) {
  return prec.right(precedence, seq($._term, operator, $._term))
}
