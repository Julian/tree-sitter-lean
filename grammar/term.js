import { sep1 } from './helpers.js';

export default {
  _term: $ => choice(
    $.number,
    $.string,
    $.identifier,
    alias($._apply, $.apply),
  ),

  identifier: $ => choice(
    sep1($._identifier_component, token.immediate('.')),
  ),
  _identifier_component: $ =>
    /[_a-zA-ZͰ-ϿĀ-ſ\U0001D400-\U0001D7FF][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F\U0001D400-\U0001D7FF]*/,

  number: $ => /\d+/,
  string: $ => seq(
    '"',
    repeat(choice($.quoted_char, token.immediate(prec(1, /[^"\n\\]+/)),)),
    '"',
  ),
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
};
