import { sep1 } from './helpers.js';

export default {
  _term: $ => choice(
    $.identifier,
    $.sorry,
    $.number,
    $.string,
    $.char,
    $.hole,
    alias($._apply, $.apply),
    $.arrow,
    $.true,
    $.false,
    $.ite,
    $.interpolated_string,
  ),

  // src/Lean/Parser/Term.lean
  identifier: $ => choice(
    sep1($._identifier_component, token.immediate('.')),
  ),
  _identifier_component: $ =>
    /[_a-zA-ZͰ-ϿĀ-ſ\U0001D400-\U0001D7FF][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F\U0001D400-\U0001D7FF]*/,

  sorry: $ => 'sorry',

  number: $ => /\d+/,
  string: $ => seq(
    '"',
    repeat(choice($.quoted_char, token.immediate(prec(1, /[^"\n\\]+/)),)),
    '"',
  ),
  char: $ => seq("'", choice($.quoted_char, /[^']/), "'"),
  hole: $ => "_",
  quoted_char: $ => token(
    seq(
      '\\', choice(
        /u[a-fA-F\d]{4}/,
        /x[a-fA-F\d]{2}/,
        /[\\"'rnt]/,
      ),
    ),
  ),

  _apply: $ => prec.left('apply', seq(
    field('function', $._term),
    field('argument', $._term),
  )),

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
    field('name', repeat1($._binder_ident)),
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
  arrow: $ => prec.right('arrow', seq($._term, '→', $._term)),

  true: $ => 'true',
  false: $ => 'false',

  // src/Init/Notation.lean
  ite: $ => prec('ite', seq(
    'if',
    $._term,
    'then',
    $._term,
    'else',
    $._term,
  )),

  // src/Init/Data/ToString/Macro.lean
  interpolated_string: $ => seq(
    's!"',
    repeat(choice(/[^"]/, $.quoted_char, $.interpolation)),
    '"',
  ),
  interpolation: $ => seq(
    '{', $._term, '}'
  ),
};
