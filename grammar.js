const PREC = {
  dollar: -2,
  apply: -1,
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

  word: $ => $.identifier,

  rules: {
    source_file: $ => repeat($._command),

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
      $.inductive_type,
      $.instance,
      $.theorem,
    ),

    prelude: $ => 'prelude',

    import: $ => seq('import', field('name', $.dotted_name)),

    open: $ => seq('open', $.identifier),

    hash_command: $ => seq(
      choice('#check', '#eval', '#reduce'),
      $._expression,
    ),

    inductive_type: $ => seq(
      'inductive',
      field('name', $.identifier),
      optional('where'),
      field('constructors', repeat1($.constructor)),
    ),

    constructor: $ => seq(
      '|',
      field('name', $.identifier),
      optional(seq(':', field('type', $.identifier))),
    ),

    instance: $ => seq(
      'instance',
      optional(field('name', $.identifier)),
      ':',
      field('class', $._expression),
      field('body', choice(
        seq('where', field('fields', repeat1($.instance_field))),
        seq(':=', $.inductive_constructor),
      )),
    ),

    instance_field: $ => seq(
      field('name', $.identifier),
      field('parameters', $.parameters),
      ':',
      field('return_type', $._expression),
      ':=',
      field('body', $._expression),
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
      field('name', $.identifier),
      field('body', repeat($._command)),
      'end',
      $.identifier,
    ),

    parameters: $ => seq(
      repeat1(
        choice(
          field('name', $.identifier),
          $._explicit_parameter,
          $.implicit_parameter,
        )
      ),
    ),

    _explicit_parameter: $ => seq(
      '(',
      field('name', repeat1($.identifier)),
      field('type', optional(seq(':', $._type_annotation))),
      ')',
    ),

    implicit_parameter: $ => seq(
      '{',
      field('name', repeat1($.identifier)),
      field('type', optional(seq(':', $._type_annotation))),
      '}',
    ),

    _type_annotation: $ => choice(
      $._expression,
      $.function_annotation,
    ),

    function_annotation: $ => seq(
      $._expression, repeat1(seq($._arrow, $._expression)),
    ),

    def: $ => seq(
      field('partial', optional('partial')),
      'def',
      field('name', $.identifier),
      field('parameters', optional($.parameters)),
      optional(seq(':', field('return_type', $._type_annotation))),
      field('body', choice(
        seq(':=', $._expression),
        repeat($.pattern),
      )),
    ),

    structure_field: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $._expression),
    ),

    structure_definition: $ => seq(
      'structure',
      field('name', $.identifier),
      field('parameters', optional($.parameters)),
      'where',
      field('fields', repeat1($.structure_field)),
    ),

    theorem: $ => seq(
      'theorem',
      field('name', $.identifier),
      field('parameters', optional($.parameters)),
      ':',
      $._expression,
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
      $._parenthesized_expression,
      $.product,
      $.comparison,
      $.conditional,
      $.field_of,
      $.match,
      $.apply,
      $.lambda,
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

    _do_expression: $ => seq(
      choice(
        $._expression,
        $.for_in,
        $.assign,
        $.let,
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

    let: $ => seq(
      'let',
      optional($.mutable_specifier),
      field('name', $.identifier),
      choice('<-', '←', ':='),
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
      prec.left(PREC.times, seq($._expression, '*', $._expression)),
      prec.left(PREC.times, seq($._expression, '/', $._expression)),
      prec.left(PREC.times, seq($._expression, '%', $._expression)),
      prec.left(PREC.plus, seq($._expression, '+', $._expression)),
      prec.left(PREC.plus, seq($._expression, '-', $._expression)),

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

    dotted_name: $ => sep1($.identifier, '.'),

    _arrow: $ => choice('->', '→'),


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

    // FIXME: see name.cpp for the real definition...
    identifier: $ => /[_a-zA-ZͰ-ϿĀ-ſ∇][_a-zA-Z0-9Ͱ-ϿĀ-ſ∇!\u2070-\u209F]*/,

    number: $ => /\d+/,
    float: $ => /\d+\.\d*/,

    true: $ => 'true',
    false: $ => 'false',
  }
});

function sep1 (rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}
