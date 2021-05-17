const attr = require('./grammar/attr.js')
const command = require('./grammar/command.js')
const syntax = require('./grammar/syntax.js')
const tactic = require('./grammar/tactic.js')
const term = require('./grammar/term.js')
const {sep0, sep1} = require('./grammar/util.js')

const PREC = {
  dollar: -5,
  equal: -3,
  compare: -2,
  apply: -1,
  multitype: -1,

  index: 10,
  parenthesized_expression: 12,
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
    [$.typeclass_resolved_parameter, $._term],
    [$.assign, $._term],
    [$.user_tactic, $._expression],
    [$.user_tactic, $.quoted_tactic],
    [$.identifier],
    [$._simple_binder],
  ],

  word: $ => $._identifier,

  rules: {
    module: $ => repeat($._command),

    _command: $ => choice(
      $.declaration,
      $.section,
      $.namespace,
      $.variable,
      $.universe,
      $.universes,
      $.hash_command,
      $.attribute,
      $.export,
      $.open,
      $.prelude,
      $.import,

      // src/Lean/Parser/Syntax.lean
      $.notation,
      $.macro_rules,
      $.syntax,
    ),

    prelude: $ => 'prelude',

    import: $ => seq('import', field('module', $.identifier)),

    _where: $ => seq('where', repeat1($.where_decl)),
    where_decl: $ => seq(
      $._decl_id,
      optional($._opt_decl_sig),
      field('body', choice($._decl_val_simple, $._decl_val_equations)),
    ),

    export: $ => seq(
      'export',
      field('class', $.identifier),
      '(',
      repeat1($.identifier),
      ')',
    ),

    variable_declaration: $ => seq('variable', repeat1($._parameter)),

    function_type: $ => prec(PREC.multitype,
      sep2($._expression, $._right_arrow),
    ),

    product_type: $ => prec.right(PREC.multitype, sep2($._expression, '×')),

    parameters: $ => seq(
      repeat1(
        choice(
          field('name', $.identifier),
          $._parameter,
          $.anonymous_constructor,
        )
      ),
    ),

    _parameter: $ => choice(
      $._explicit_parameter,
      $.implicit_parameter,
      $.typeclass_resolved_parameter,
    ),

    _explicit_parameter: $ => seq(
      '(',
      field('name', repeat1($.identifier)),
      field('type', optional(seq(':', $._expression))),
      ')',
    ),

    implicit_parameter: $ => seq(
      '{',
      field('name', repeat1($.identifier)),
      field('type', optional(seq(':', $._expression))),
      '}',
    ),

    typeclass_resolved_parameter: $ => seq(
      '[',
      field('name', optional(seq(repeat1($.identifier), ':'))),
      field('type', $._expression),
      ']',
    ),

    field: $ => seq(
      field('name', $.identifier),
      optional(field('parameters', $.parameters)),
      optional(field('type', seq(':', $._expression))),
      optional(
        seq(
          ':=',
          field('default', $._expression),
        ),
      ),
      $._newline,
    ),

    _expression: $ => choice(
      $._primary_expression,
      $.apply,
      $.comparison,
      $.do,
      $.let,
      $.unless,
      $.tactics,
    ),

    _primary_expression: $ => choice(
      $.coe,
      $._parenthesized_expression,
      $.unary_expression,
      $.quoted_tactic,
      $.explicit,
      $.function_type,
      $.product_type,
      $.product,
      $.index,
      $.conditional,
      $.field_of,
      $.match,
      $.lambda,
      $.binary_expression,
      $.interpolated_string,
      $.anonymous_constructor,
      $.structure_instance,
      $.list,
      $.range,
      $.array,
      $._term,
    ),

    _parenthesized_expression: $ => prec(PREC.parenthesized_expression, seq(
      '(',
      $._expression,
      ')'
    )),

    product: $ => seq('(', sep2($._expression, ','), ')'),

    conditional: $ => prec.right(1, seq(
      'if',
      $._expression,
      'then',
      $._expression,
      'else',
      $._expression,
    )),

    index: $ => prec(PREC.index, seq(
      field('container', $._expression),
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
        $.for_in,
        $.assign,
        $.let_bind,
        $.let_mut,
        $.try,
        $.finally,
        $.throw,
        $.conditional_when,
        $.return,
      ),
    ),

    do: $ => prec.right(seq('do', sep1_($._do_command, $._newline))),

    mutable_specifier: $ => 'mut',

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
      choice($._left_arrow, ':='),
      field('value', $._expression),
    ),

    let_bind: $ => seq(
      'let',
      field('name', $.identifier),
      $._left_arrow,
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

    match: $ => prec.left(seq(
      'match',
      field('value', sep1($._expression, ',')),
      'with',
      field('patterns', repeat1($.pattern)),
    )),

    pattern: $ => seq(
      '|',
      field('lhs', sep1($._expression, ',')),
      '=>',
      $._expression,
    ),

    lambda: $ => prec.right(seq(
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
      field('name', $._primary_expression),
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

    // src/Lean/Parser/Syntax.lean
    quoted_tactic: $ => seq(
      '`(tactic|', choice($._tactic, $._expression), ')',
    ),

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

    structure_instance: $ => seq(
      '{',
      optional(field('extends', seq($._expression, 'with'))),
      // Unlike everywhere else, records seem OK with trailing commas.
      optional(sep1_($._structure_instance_field, ',')),
      field('type', optional(seq(':', $._expression))),
      '}',
    ),

    _structure_instance_field: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._expression),
    ),

    anonymous_constructor: $ => seq('⟨', sep0($._expression, ','), '⟩'),

    list: $ => seq('[', sep0($._expression, ','), ']'),

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

    array: $ => seq('#[', sep0($._expression, ','), ']'),

    interpolated_string: $ => seq(
      's!"',
      repeat(choice(/[^"]/, $.escape_sequence, $.interpolation)),
      '"',
    ),

    interpolation: $ => seq(
      '{', $._expression, '}'
    ),

    coe: $ => seq(
      '(',
      field('term', $._expression),
      ':',
      field('type', $._expression),
      ')',
    ),

    _left_arrow: $ => choice('<-', '←'),
    _right_arrow: $ => choice('->', '→'),

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

    explicit: $ => seq('@', $.identifier),

    // FIXME: see name.cpp for the real definition...
    identifier: $ => choice(
      sep1($._identifier, token.immediate('.')),
      $._lambda_magic_identifier,
      $._escaped_identifier,
    ),
    _identifier: $ => /[_a-zA-ZͰ-ϿĀ-ſ\U0001D400-\U0001D7FF][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F\U0001D400-\U0001D7FF]*/,
    _escaped_identifier: $ =>  /«[^»]*»/,
    _lambda_magic_identifier: $ => choice('.', '·'),

    ...attr,
    ...command,
    ...syntax,
    ...tactic,
    ...term,
  }
});
