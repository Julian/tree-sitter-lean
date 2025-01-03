import { sep0, sep1 } from './helpers.js';
import { terms as mathlibTerms } from './mathlib.js';

export default {
  _term: $ => choice(
    $.by,
    $.identifier,
    $.number,
    $.string,
    $.char,
    $.hole,
    $.sorry,
    $.anonymousConstructor,
    $.apply,
    $.arrow,
    $.true,
    $.false,
    $.ite,
    $.interpolatedString,

    ...(mathlibTerms($)),
  ),

  // src/Lean/Parser/Term.lean
  identifier: $ => choice(
    sep1($._identifierComponent, token.immediate('.')),
  ),
  _identifierComponent: $ =>
    /[_a-zA-ZͰ-ϿĀ-ſ\U0001D400-\U0001D7FF][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F\U0001D400-\U0001D7FF]*/,

  sorry: $ => 'sorry',

  number: $ => /\d+/,
  string: $ => seq(
    '"',
    repeat(choice($.quotedChar, token.immediate(prec(1, /[^"\n\\]+/)),)),
    '"',
  ),
  char: $ => seq("'", choice($.quotedChar, /[^']/), "'"),
  hole: $ => "_",
  quotedChar: $ => token(
    seq(
      '\\', choice(
        /u[a-fA-F\d]{4}/,
        /x[a-fA-F\d]{2}/,
        /[\\"'rnt]/,
      ),
    ),
  ),
  anonymousConstructor: $ => seq('⟨', sep0($._term, ','), '⟩'),

  _typeSpec: $ => field('type', seq(':', $._term)),

  _binderIdent: $ => prec('binderIdent', choice($.identifier, $.hole)),
  _binderDefault: $ => field('default', seq(':=', $._term)),
  explicitBinder: $ => seq(
    '(',
    field('name', repeat1($._binderIdent)),
    field('type', optional($._typeSpec)),
    optional(choice($._binderDefault)),
    ')',
  ),
  implicitBinder: $ => seq(
    '{',
    field('name', repeat1($._binderIdent)),
    field('type', optional($._typeSpec)),
    '}',
  ),
  instanceBinder: $ => seq(
    '[',
    optional(seq(field('name', $.identifier), ':')),
    field('type', $._term),
    ']',
  ),
  _bracketedBinder: $ => choice(
    $.explicitBinder,
    $.implicitBinder,
    $.instanceBinder,
  ),

  _arguments: $ => repeat1(prec('arg', field('argument', $._term))),
  apply: $ => prec.right('lead', seq(
    prec('max', field('lhs', $._term)),
    field('argument', $._arguments),
  )),

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

  _attrKind: $ => choice('scoped', 'local'),
  _attrInstance: $ => seq(optional($._attrKind), $._attribute),
  attributes: $ => seq('@[', sep1($._attrInstance, ','), ']'),

  // src/Init/Data/ToString/Macro.lean
  interpolatedString: $ => seq(
    's!"',
    repeat(choice(/[^"]/, $.quotedChar, $.interpolation)),
    '"',
  ),
  interpolation: $ => seq(
    '{', $._term, '}'
  ),
};
