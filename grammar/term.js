// src/Lean/Parser/Command.lean
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
  _type_spec: $ => field('type', seq(':', $._term)),
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

  true: $ => 'true',
  false: $ => 'false',

  attributes: $ => seq('@[', sep1($._attribute, ','), ']'),

  _term: $ => choice(
    $.identifier,
    $.number,
    $.float,
    $.string,
    $.char,
    $.sorry,
    $.cdot,
    $.forall,
    $.true,
    $.false,
    $._notation_extra_term,
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
}
