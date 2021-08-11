const {PREC} = require('./basic.js')
const {Parser} = require('./util.js')

const term = new Parser($ => [
  $.identifier,
  $.number,
  $.float,
  $.string,
  $.char,
  $.hole,
  $.sorry,
  $.cdot,
  $.parenthesized,
  $.anonymous_constructor,
  $.structure_instance,
  $.explicit,
  $.forall,
  $.true,
  $.false,
  $.match,
  $.proj,
  $.arrow,
  $._notation_term,
  $._notation_extra_term,
  $.array,
  $.subarray,
  $.range,
  $.interpolated_string,
])

// src/Lean/Parser/Term.lean
module.exports = {
  term,
  rules: {
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
      repeat(choice($.escape_sequence, token.immediate(prec(1, /[^"\n\\]+/)),)),
      '"',
    ),
    char: $ => seq("'", choice($.escape_sequence, /[^']/), "'"),
    hole: $ => "_",
    sorry: $ => 'sorry',
    cdot: $ => choice('.', '·'),
    type_ascription: $ => seq(':', field('type', $._expression)),
    tuple_tail: $ => seq(',', sep1($._expression, ',')),
    parenthesized: $ => seq(
      '(',
      optional(
        seq($._expression, optional(choice($.tuple_tail, $.type_ascription)))
      ),
      ')',
    ),
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
    proj: $ => seq(
      field('term', prec(PREC.lead, $._term)),
      token.immediate('.'),
      field('name', choice($.identifier, $.number)),
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
    _match_discr: $ => seq(
      optional(seq($.identifier, token.immediate(':'))),
      $._expression,
    ),

    true: $ => 'true',
    false: $ => 'false',

    match: $ => prec.left(seq(
      'match',
      field('value', sep1($._match_discr, ', ')),
      field('type', optional($._type_spec)),
      'with',
      field('patterns', $._match_alts),
    )),

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
    _attr_kind: $ => choice('scoped', 'local'),
    attributes: $ => seq('@[', sep1($._attribute, ','), ']'),
    _let_rec_decl: $ => seq($._let_decl),

    _where_decls: $ => seq(
      'where', repeat1(seq(alias($._let_rec_decl, $.where_decl))),
    ),

    quoted_tactic: $ => seq('`(tactic|', $._tactic, ')'),

    _term: $ => term.all($),

    // src/Init/Notation.lean
    // FIXME: precedence is wrong, it should be 35, but apply needs fixing
    product: $ => prec.right(35, seq($._term, '×', $._term)),

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
      $.product,
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
  },
}
