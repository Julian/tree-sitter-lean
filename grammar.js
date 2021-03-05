const PREC = {
  dollar: -2,
  apply: -1,
  index: -1,
  parenthesized_expression: 1,
  compare: -1,
  field_of: 1,

  equal: -1,
  opop: 1,
  or: 1,
  and: 2,
  eqeq: 2,
  plus: 3,
  times: 4,
  unary: 5,
  power: 6,
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
    [$.typeclass_resolved_parameter, $._expression],
    [$._apply, $.let],
  ],

  word: $ => $.identifier,

  rules: {
    module: $ => repeat($._command),

    _command: $ => choice(
      $.prelude,
      $.hash_command,
      $.import,
      $.open,
      $.namespace,
      $.section,
      $.example,
      $.def,
      $.structure_definition,
      $.class,
      $.inductive_type,
      $.instance,
      $.export,
      $.theorem,
      $.variable_declaration,
      $.constant,
      $.universe,
    ),

    prelude: $ => 'prelude',

    import: $ => seq('import', field('module', $._dotted_name)),

    open: $ => seq('open', field('namespace', $.identifier)),

    hash_command: $ => seq(
      choice('#check', '#check_failure', '#eval', '#print', '#reduce'),
      $._expression,
    ),

    inductive_type: $ => seq(
      'inductive',
      field('name', $._dotted_name),
      optional('where'),
      field('constructors', repeat1($.constructor)),
    ),

    constructor: $ => seq('|', $._maybe_annotated),

    instance: $ => seq(
      'instance',
      optional(field('name', $._dotted_name)),
      optional(field('parameters', seq(
        repeat1(
          choice(
            $._explicit_parameter,
            $.implicit_parameter,
            $.typeclass_resolved_parameter,
          ),
        ),
      ))),
      ':',
      field('class', $._expression),
      field('body', choice(
        seq('where', field('fields', repeat1($.instance_field))),
        seq(':=', $.inductive_constructor),
      )),
    ),

    instance_field: $ => seq(
      field('name', $.identifier),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('return_type', $._expression))),
      ':=',
      field('body', $._expression),
    ),

    export: $ => seq(
      'export',
      field('class', $.identifier),
      '(',
      repeat1($.identifier),
      ')',
    ),

    namespace: $ => seq(
      'namespace',
      field('name', $.identifier),
      field('body', repeat($._command)),
      'end',
      $.identifier,
    ),

    section: $ => seq(
      'section',
      optional(field('name', $.identifier)),
      field('body', repeat($._command)),
      'end',
      optional($.identifier), // FIXME: needs to match start
    ),

    variable_declaration: $ => seq(
      'variable',
      repeat1(
        choice(
          $._explicit_parameter,
          $.implicit_parameter,
          $.typeclass_resolved_parameter,
        ),
      ),
    ),

    constant: $ => seq(
      'constant',
      field('name', $.identifier),
      ':',
      field('type', $._expression),
    ),

    universe: $ => seq(
      'universe',
      repeat1($.identifier),
    ),

    parameters: $ => seq(
      repeat1(
        choice(
          field('name', $.identifier),
          $._explicit_parameter,
          $.implicit_parameter,
          $.typeclass_resolved_parameter,
        )
      ),
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

    function_type: $ => prec(-1, seq(
      $._expression, repeat1(seq($._right_arrow, $._expression)),
    )),

    product_type: $ => prec(-1, seq(
      $._expression, repeat1(seq('×', $._expression)),
    )),

    def: $ => seq(
      field('attributes', optional(seq(
        '@[', $.identifier, optional(repeat(seq(',', $.identifier))), ']',
      ))),
      field('partial', optional('partial')),
      'def',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('return_type', $._expression))),
      field('body', choice(
        seq(':=', $._expression),
        repeat($.pattern),
      )),
    ),

    field: $ => seq(
      $._maybe_annotated,
      optional(
        seq(
          ':=',
          field('default', $._expression),
        ),
      ),
    ),

    structure_definition: $ => seq(
      'structure',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      'where',
      field('fields', repeat1($.field)),
    ),

    class: $ => seq(
      'class',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      'where',
      field('fields', repeat1($.field)),
    ),

    theorem: $ => seq(
      'theorem',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      ':',
      field('type', $._expression),
      ':=',
      field('body', $.identifier),  // FIXME
    ),

    example: $ => seq(
      'example',
      ':',
      $._expression,
      ':=',
      field('body', $._expression),
    ),

    _expression: $ => choice(
      $.identifier,
      $.coe,
      $._parenthesized_expression,
      $.explicit,
      $.function_type,
      $.product_type,
      $.product,
      $.index,
      $.comparison,
      $.conditional,
      $.field_of,
      $.match,
      $.apply,
      $.lambda,
      $.let,
      $.do,
      $.unary_expression,
      $.binary_expression,
      $.number,
      $.float,
      $.char,
      $.string,
      $.interpolated_string,
      $.inductive_constructor,
      $.list,
      $.range,
      $.array,
      $.true,
      $.false,
    ),

    _parenthesized_expression: $ => prec(PREC.parenthesized_expression, seq(
      '(',
      $._expression,
      ')'
    )),

    product: $ => seq(
      '(',
        $._expression,
        repeat1(seq(',', $._expression)),
      ')'
    ),

    conditional: $ => prec.right(seq(
      'if',
      $._expression,
      'then',
      $._expression,
      optional(
        seq(
          'else',
          $._expression,
        ),
      ),
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

    let: $ => seq(
      'let',
      field('name', $._maybe_annotated),
      ':=',
      field('body', $._expression),
      $._newline,
    ),

    _do_expression: $ => seq(
      choice(
        $._expression,
        $.for_in,
        $.assign,
        $.let_bind,
        $.let_mut,
        $.try,
        $.throw,
        $.return,
      ),
      $._newline,
    ),

    do: $ => prec.right(seq('do', repeat($._do_expression))),

    mutable_specifier: $ => 'mut',

    for_in: $ => seq(
      'for',
      field('name', $.identifier),
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
      'let mut',
      field('name', $._maybe_annotated),
      choice($._left_arrow, ':='),
      field('body', $._expression),
    ),


    let_bind: $ => seq(
      'let',
      field('name', $._maybe_annotated),
      $._left_arrow,
      field('body', $._expression),
    ),

    // FIXME: nesting (which depends on the indent processing)
    try: $ => prec.left(seq(
      'try',
      repeat1($._do_expression),
      choice(
        seq($.catch, optional($.finally)),
        $.finally,
    ))),

    throw: $ => seq('throw', $._expression),

    catch: $ => prec.left(seq(
      'catch',
      $._expression,
      '=>',
      repeat1($._do_expression),
    )),

    finally: $ => seq(
      'finally',
      repeat1($._do_expression),
    ),

    return: $ => seq('return', field('value', optional($._expression))),

    match: $ => prec.left(seq(
      'match',
      field('value', $._expression),
      'with',
      field('patterns', repeat1($.pattern)),
    )),

    pattern: $ => seq(
      '|',
      choice($._expression, $.lhs),
      '=>',
      $._expression,
    ),

    lhs: $ => seq($._expression, repeat1(seq(',', $._expression))),

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
      field('name', $._expression),
      field('arguments', repeat1($._argument)),
    )),

    // FIXME: This is almost certainly wrong
    _dollar: $ => prec.right(PREC.dollar, seq(
      field('name', $._expression),
      '$',
      field('argument', $._expression),
    )),

    field_of: $ => prec(PREC.field_of, seq(
      field('term', $._expression),
      '.',
      field('name', $.identifier),
    )),

    unary_expression: $ => prec(PREC.unary, choice(
      seq('!', $._expression),
    )),

    binary_expression: $ => choice(
      prec.right(PREC.power, seq($._expression, '^', $._expression)),
      prec.left(PREC.times, seq($._expression, '*', $._expression)),
      prec.left(PREC.times, seq($._expression, '/', $._expression)),
      prec.left(PREC.times, seq($._expression, '%', $._expression)),
      prec.left(PREC.plus, seq($._expression, '+', $._expression)),
      prec.left(PREC.plus, seq($._expression, '-', $._expression)),

      prec.left(PREC.opop, seq($._expression, '∧', $._expression)),
      prec.left(PREC.opop, seq($._expression, '∨', $._expression)),
      prec.left(PREC.opop, seq($._expression, '↔', $._expression)),

      prec.left(PREC.opop, seq($._expression, '++', $._expression)),
      prec.left(PREC.opop, seq($._expression, '::', $._expression)),

      prec.left(PREC.or, seq($._expression, '||', $._expression)),
      prec.left(PREC.and, seq($._expression, '&&', $._expression)),
      prec.left(PREC.eqeq, seq($._expression, '==', $._expression)),

      prec.left(PREC.opop, seq($._expression, '<|>', $._expression)),

      prec.left(PREC.equal, seq($._expression, '=', $._expression)),
      prec.left(PREC.equal, seq($._expression, '≠', $._expression)),
    ),

    comparison: $ => prec.left(PREC.compare, seq(
      $._expression,
      choice(
        '<',
        '>',
      ),
      $._expression,
    )),

    inductive_constructor: $ => seq(
      '⟨',
      optional($._expression),
      repeat(seq(',', $._expression)),
      '⟩',
    ),

    list: $ => seq(
      '[',
      optional($._expression),
      repeat(seq(',', $._expression)),
      ']',
    ),

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

    array: $ => seq(
      '#[',
      optional($._expression),
      repeat(seq(',', $._expression)),
      ']',
    ),

    char: $ => seq("'", $._string_content, "'"),

    string: $ => seq('"', repeat($._string_content), '"'),

    interpolated_string: $ => seq(
      's!"',
      repeat(choice($._string_content, $.interpolation)),
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

    _dotted_name: $ => prec.right(choice(
      $.identifier,
      sep1($.identifier, '.'),
    )),

    _left_arrow: $ => choice('<-', '←'),
    _right_arrow: $ => choice('->', '→'),


    // TODO: actual right string content, escape sequences, etc.
    _string_content: $ => /[^"]/,

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

    explicit: $ => seq('@', $._dotted_name),

    // FIXME: see name.cpp for the real definition...
    identifier: $ => /[_a-zA-ZͰ-ϿĀ-ſ∇][_a-zA-Z0-9Ͱ-ϿĀ-ſ∇!\u2070-\u209F]*/,

    _maybe_annotated: $ => seq(
      field('name', $.identifier),
      field('type', optional(seq(':', $._expression))),
    ),

    number: $ => /\d+/,
    float: $ => /\d+\.\d*/,

    true: $ => 'true',
    false: $ => 'false',
  }
});

function sep1 (rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}
