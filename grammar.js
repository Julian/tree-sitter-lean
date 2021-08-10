const attr = require('./grammar/attr.js')
const command = require('./grammar/command.js')
const do_ = require('./grammar/do.js')
const syntax = require('./grammar/syntax.js')
const tactic = require('./grammar/tactic.js')
const term = require('./grammar/term.js')
const {sep1} = require('./grammar/util.js')

const PREC = {
  dollar: -5,
  equal: -3,
  compare: -2,
  apply: -1,
  multitype: -1,

  opop: 13,
  or: 14,
  and: 15,
  eqeq: 16,
  plus: 17,
  times: 18,
  unary: 19,
  power: 20,

  name: 30,
}

module.exports = grammar({
  name: 'lean',

  extras: $ => [
    $.comment,
    /\s/,
  ],

  externals: $ => [
    $._newline,
  ],

  conflicts: $ => [
    [$.instance_binder, $.list],

    [$._binder_ident],
    [$.instance_binder, $._term],
    [$._binder_ident, $.named_argument],
    [$._let_id_lhs],
    [$._binder_ident, $._term],
    [$.assign, $._term],
    [$._let_id_lhs, $._term],
    [$.identifier],
    [$._simple_binder],
    [$._user_tactic, $.quoted_tactic],
  ],

  word: $ => $._identifier,

  rules: {
    // src/Lean/Parser/Module.lean
    module: $ => seq(
      optional($.prelude),
      repeat($.import),
      repeat($._command),
    ),
    prelude: $ => 'prelude',
    import: $ => seq('import', field('module', $.identifier)),

    product_type: $ => prec.right(PREC.multitype, sep2($._expression, '×')),

    parameters: $ => seq(
      repeat1(
        choice(
          field('name', $.identifier),
          $.hole,
          $._bracketed_binder,
          $.anonymous_constructor,
        )
      ),
    ),

    _expression: $ => choice(
      $._primary_expression,
    ),

    _primary_expression: $ => choice(
      $.apply,
      $.comparison,
      $.let,
      $.tactics,
      $.binary_expression,
      $.unary_expression,
      $.quoted_tactic,
      $.product_type,
      $.field_of,
      $.fun,
      $._term,

      // FIXME: These two rules make grammar generation absurdly slow, by 20x.
      //        Really `do` is the relevant one, `unless` uses it.
      //        Possibly https://github.com/tree-sitter/tree-sitter/issues/693
      //        is a relevant ticket.
      $.do,
      $.unless,
    ),

    let: $ => prec.left(seq(
      'let',
      field('name', $.identifier),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('type', $._expression))),
      ':=',
      field('value', $._expression),
      choice($._newline, ';'),
      optional(field('body', $._expression)),
    )),

    _do_command: $ => seq(
      choice(
        $._expression,
        $.assign,
        $.for_in,
        $.let_bind,
        $.let_mut,
        $.return,
        $.throw,

        // FIXME: These rules are what make the above really slow it'd
        //        appear, each seem to make things ~4x slower
        // $.conditional_when,
        // $.try,
        // $.finally,
      ),
    ),

    do: $ => prec.right(seq('do', sep1_($._do_command, $._newline))),

    conditional_when: $ => prec.right(seq(
      'if',
      $._expression,
      'then',
      $._do_command,
    )),

    for_in: $ => seq(
      'for',
      choice($.identifier, $.anonymous_constructor),
      'in',
      field('iterable', $._expression),
      field('body', $.do),
    ),

    assign: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._expression),
    ),

    let_mut: $ => seq(
      'let', 'mut',
      $.parameters,
      choice(do_._left_arrow($), ':='),
      field('value', $._expression),
    ),

    let_bind: $ => seq(
      'let',
      field('name', $.identifier),
      do_._left_arrow($),
      field('value', $._expression),
    ),

    throw: $ => seq('throw', $._expression),

    unless: $ => seq('unless', $._expression, $.do),

    // FIXME: nesting (which depends on the indent processing)
    try: $ => prec.left(1, seq(
      'try',
      sep1_($._do_command, $._newline),
      choice(
        seq($.catch, optional($.finally)),
        $.finally,
    ))),

    catch: $ => prec.left(seq(
      'catch',
      $._expression,
      '=>',
      sep1_($._do_command, $._newline),
    )),

    finally: $ => prec.left(seq(
      'finally',
      sep1_($._do_command, $._newline),
    )),

    return: $ => prec.right(
      seq('return', field('value', optional($._expression))),
    ),

    pattern: $ => seq(
      '|',
      field('lhs', sep1($._expression, ',')),
      '=>',
      $._expression,
    ),

    fun: $ => prec.right(seq(
      choice('fun', 'λ'),
      choice(
        seq(
          $.parameters,
          '=>',
          $._expression,
        ),
        repeat($.pattern),
      ),
    )),

    _argument: $ => choice($._expression, $.named_argument),
    named_argument: $ => seq(
      '(', $.identifier, ':=', $._expression, ')',
    ),

    apply: $ => choice($._apply, $._dollar),

    _apply: $ => prec(PREC.apply, seq(
      field('name', term.term.all($)),
      field('arguments', repeat1($._argument)),
    )),

    // FIXME: This is almost certainly wrong
    _dollar: $ => prec.right(PREC.dollar, seq(
      field('name', $._expression),
      '$',
      field('argument', $._expression),
    )),

    field_of: $ => prec(1, seq(
      field('term', $._expression),
      token.immediate('.'),
      field('name', choice($.identifier, $.number)),
    )),

    unary_expression: $ => prec(PREC.unary, choice(
      seq('←', $._expression),
      seq('¬', $._expression),
      seq('-', $._primary_expression),
      seq('!', $._expression),
    )),

    binary_expression: $ => choice(
      prec.right(PREC.power, seq($._expression, '^', $._expression)),
      prec.left(PREC.times, seq($._expression, '*', $._expression)),
      prec.left(PREC.times, seq($._expression, '/', $._expression)),
      prec.left(PREC.times, seq($._expression, '%', $._expression)),
      prec.left(PREC.plus, seq($._expression, '+', $._expression)),
      prec.left(PREC.plus, seq($._expression, '-', $._expression)),

      prec.right(PREC.plus, seq($._expression, '∘', $._expression)),

      prec.left(PREC.opop, seq($._expression, '∧', $._expression)),
      prec.left(PREC.opop, seq($._expression, '∨', $._expression)),
      prec.left(PREC.opop, seq($._expression, '/\\', $._expression)),
      prec.left(PREC.opop, seq($._expression, '\\/', $._expression)),
      prec.left(PREC.opop, seq($._expression, '↔', $._expression)),

      prec.left(PREC.or, seq($._expression, '||', $._expression)),
      prec.left(PREC.and, seq($._expression, '&&', $._expression)),
      prec.left(PREC.eqeq, seq($._expression, '==', $._expression)),

      prec.left(PREC.opop, seq($._expression, '++', $._expression)),
      prec.left(PREC.opop, seq($._expression, '::', $._expression)),

      prec.left(PREC.opop, seq($._expression, '|>', $._expression)),
      prec.left(PREC.opop, seq($._expression, '|>.', $._expression)),
      prec.right(PREC.dollar, seq($._expression, '<|', $._expression)),

      prec.left(PREC.opop, seq($._expression, '<|>', $._expression)),
      prec.left(PREC.opop, seq($._expression, '>>', $._expression)),
      prec.left(PREC.opop, seq($._expression, '>>=', $._expression)),
      prec.left(PREC.opop, seq($._expression, '<*>', $._expression)),
      prec.left(PREC.opop, seq($._expression, '<*', $._expression)),
      prec.left(PREC.opop, seq($._expression, '*>', $._expression)),
      prec.left(PREC.opop, seq($._expression, '<$>', $._expression)),

      prec.left(PREC.equal, seq($._expression, '=', $._expression)),
      prec.left(PREC.equal, seq($._expression, '≠', $._expression)),
    ),

    comparison: $ => prec.left(PREC.compare, seq(
      $._expression,
      choice(
        '<',
        '>',
        '≤',
        '≥',
        '<=',
        '>=',
      ),
      $._expression,
    )),

    escape_sequence: $ => token(
      seq(
        '\\', choice(
          /u[a-fA-F\d]{4}/,
          /x[a-fA-F\d]{2}/,
          /['"rnt\\]/,
        ),
      ),
    ),

    comment: $ => token(choice(
      seq('--', /.*/),
      seq(
        '/-',
        repeat(choice(
          /[^-]/,
          /-[^/]/
        )),
        '-/',
      ),
    )),

    _identifier: $ => /[_a-zA-ZͰ-ϿĀ-ſ\U0001D400-\U0001D7FF][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F\U0001D400-\U0001D7FF]*/,
    _escaped_identifier: $ =>  /«[^»]*»/,

    ...attr,
    ...command,
    ...syntax,
    ...tactic,
    ...term.rules,
  }
});
