const {PREC} = require('./basic.js')

// src/Lean/Parser/Term.lean
module.exports = {
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
  _parenthesized_expression: $ => seq('(', optional($._expression), ')'),
  anonymous_constructor: $ => seq('⟨', sep0($._expression, ','), '⟩'),
  _structure_instance_field: $ => seq(
    field('name', $.identifier),
    ':=',
    field('value', $._expression),
  ),
  structure_instance: $ => seq(
    '{',
    optional(field('extends', seq($._expression, 'with'))),
    // Unlike everywhere else, records seem OK with trailing commas.
    optional(sep1_($._structure_instance_field, ',')),
    field('type', optional($._type_spec)),
    '}',
  ),
  _type_spec: $ => field('type', seq(':', $._expression)),

  explicit: $ => seq('@', $._expression),
  _binder_ident: $ => choice($.identifier, $.hole),
  _binder_default: $ => field('default', seq(':=', $._expression)),
  explicit_binder: $ => seq(
    '(',
    field('name', repeat1($._binder_ident)),
    field('type', optional($._type_spec)),
    optional(choice($._binder_default)),
    ')',
  ),
  implicit_binder: $ => seq(
    '{',
    field('name', repeat1($._binder_ident)),
    field('type', optional($._type_spec)),
    '}',
  ),
  instance_binder: $ => seq(
    '[',
    optional(seq(field('name', $.identifier), ':')),
    field('type', $._expression),
    ']',
  ),
  _bracketed_binder: $ => choice(
    $.explicit_binder,
    $.implicit_binder,
    $.instance_binder,
  ),
  arrow: $ => prec.right(25, seq($._term, choice('->', '→'), $._expression)),

  forall: $ => prec(-4, seq(
    '∀',
    field(
      'binders',
      alias(repeat1(choice($._simple_binder, $._bracketed_binder)), $.binders),
    ),
    ',',
    field('body', $._expression),
  )),

  _simple_binder: $ => seq(
    field('name', repeat1($._binder_ident)),
    optional($._type_spec),
  ),

  match_alt: $ => seq(
    '|',
    field('lhs', sep1($._expression, ',')),
    '=>',
    $._expression,
  ),

  _match_alts: $ => repeat1($.match_alt),
  true: $ => 'true',
  false: $ => 'false',

  _simple_binder_without_type: $ => repeat1($._binder_ident),
  _let_id_lhs: $ => seq(
    field('name', $.identifier),
    field('binders', repeat(
      choice($._simple_binder_without_type, $._bracketed_binder)),
    ),
    field('type', optional($._type_spec)),
  ),
  _let_id_decl: $ => seq($._let_id_lhs, ":=", field('body', $._expression)),
  _let_pattern_decl: $ => seq($._expression, optional($._type_spec), ":=", $._expression),
  _let_equations_decl: $ => seq($._let_id_lhs, field('body', $._match_alts)),
  _let_decl: $ => choice(
    $._let_id_decl, $._let_pattern_decl, $._let_equations_decl,
  ),
  attributes: $ => seq('@[', sep1($._attribute, ','), ']'),
  _let_rec_decl: $ => seq($._let_decl),

  _where_decls: $ => seq(
    'where', repeat1(seq(alias($._let_rec_decl, $.where_decl))),
  ),

  _term: $ => choice(
    $._parenthesized_expression,
    $.identifier,
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
    $.arrow,
    $._notation_term,
    $._notation_extra_term,
    $.array,
    $.subarray,
    $.range,
    $.interpolated_string,
    $._cant_find_term,
  ),

  // src/Init/Notation.lean
  list: $ => seq('[', sep0($._expression, ','), ']'),

  assumption_literal: $ => seq('‹', $._term, '›'),
  if_then_else: $ => seq(
    'if',
    $._expression,
    'then',
    $._expression,
    'else',
    $._expression,
  ),

  _notation_term: $ => choice(
    $.if_then_else,
    $.list,
    $.assumption_literal,
  ),

  // src/Init/NotationExtra.lean
  exists: $ => prec(-4, seq(
    '∃',
    field(
      'binders',
      alias(repeat1(choice($._simple_binder, $._bracketed_binder)), $.binders),
    ),
    ',',
    field('body', $._expression),
  )),

  _notation_extra_term: $ => choice(
    $.exists,
  ),

  // src/Init/Data/Array/Basic.lean
  array: $ => seq('#[', sep0($._expression, ','), ']'),

  // src/Init/Data/Array/Subarray.lean
  subarray: $ => prec(PREC.max, seq(
    field('term', $._expression),
    token.immediate('['),
    choice(
      field('value', $._expression),
      seq(
        optional(field('start', $._expression)),
        ':',
        field('stop', $._expression),
      ),
      seq(
        field('start', $._expression),
        ':',
        optional(field('stop', $._expression)),
      ),
    ),
    ']',
  )),

  // src/Init/Data/Range.lean
  range: $ => seq(
    '[',
    optional(field('start', $._expression)),
    ':',
    field('stop', $._expression),
    optional(seq(
      ':',
      field('step', $._expression),
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
    '{', $._expression, '}'
  ),

  // FINDME: I can't find where these are defined...
  coe: $ => seq('(', field('term', $._expression), ':', field('type', $._expression), ')'),
  product: $ => seq('(', sep2($._expression, ','), ')'),
  _cant_find_term: $ => choice(
    $.coe,
    $.product,
  ),
}
