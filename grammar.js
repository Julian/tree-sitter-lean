const PREC = {
  function_application: -1,
  parenthesized_expression: 1,
  compare: -1,

  equal: -1,
}

module.exports = grammar({
  name: 'lean',

  extras: $ => [
    $.comment,
    /\s/,
  ],

  word: $ => $.identifier,

  rules: {
    source_file: $ => repeat($._command),

    _command: $ => choice(
      $.hash_command,
      $.namespace_definition,
      $.section_definition,
      $.example_definition,
      $.function_definition,
      $.inductive_type,
      $.theorem_definition,
    ),

    hash_command: $ => seq(
      choice('#check', '#eval', '#reduce'),
      $._expression,
    ),

    inductive_type: $ => seq(
      'inductive',
      field('name', $.identifier),
      'where',
      field('constructors', repeat1($.constructor)),
    ),

    constructor: $ => seq(
      '|', $.identifier, ':', $.identifier,
    ),

    namespace_definition: $ => seq(
      'namespace',
      field('name', $.identifier),
      repeat($._command),
      'end',
      $.identifier,
    ),

    section_definition: $ => seq(
      'section',
      field('name', $.identifier),
      repeat($._command),
      'end',
      $.identifier,
    ),

    parameter_list: $ => seq(
      repeat1(
        choice($.identifier, $.annotated)
      ),
    ),

    annotated: $ => seq(
      '(',
      $.identifier,
      ':',
      $._type_annotation,
      ')',
    ),

    _type_annotation: $ => choice(
      $._expression,
      $.function_annotation,
    ),

    function_annotation: $ => seq(
      $._expression, '→', $._expression,
    ),

    function_definition: $ => seq(
      'def',
      field('name', $.identifier),
      field('parameters', optional($.parameter_list)),
      ':=',
      $._expression,
    ),

    theorem_definition: $ => seq(
      'theorem',
      field('name', $.identifier),
      field('parameters', optional($.parameter_list)),
      ':',
      $._expression,
      ':=',
      $.identifier,
    ),

    example_definition: $ => seq(
      'example',
      ':',
      $._expression,
      ':=',
      $._expression,
    ),

    _expression: $ => choice(
      $.identifier,
      $._parenthesized_expression,
      $.comparison,
      $.conditional,
      $.element_of,
      $.function_application,
      $.lambda,
      $.binary_expression,
      $.number,
      $.string,
    ),

    _parenthesized_expression: $ => prec(PREC.parenthesized_expression, seq(
      '(',
      $._expression,
      ')'
    )),

    conditional: $ => seq(
      'if',
      $._expression,
      'then',
      $._expression,
      'else',
      $._expression,
    ),

    lambda: $ => seq(
      'fun', $.parameter_list, '=>', $._expression,
    ),

    function_application: $ => prec(PREC.function_application, seq(
      field('name', $._expression),
      field('arguments', repeat1($._expression)),
    )),

    element_of: $ => seq(
      field('type', $.identifier),
      '.',
      field('field', $.identifier),
    ),

    binary_expression: $ => choice(
      prec.left(2, seq($._expression, '*', $._expression)),
      prec.left(1, seq($._expression, '+', $._expression)),
      prec.left(1, seq($._expression, '-', $._expression)),
      prec.left(PREC.equal, seq($._expression, '=', $._expression)),
    ),

    comparison: $ => prec.left(PREC.compare, seq(
      $._expression,
      choice(
        '<',
        '>',
      ),
      $._expression,
    )),

    string: $ => seq(
      '"',
      repeat(choice($._string_content, $.interpolation)),
      '"',
    ),

    interpolation: $ => seq(
      '{', $._expression, '}'
    ),

    // TODO: actual right string content, escape sequences, etc.
    _string_content: $ => /[^"]/,

    comment: $ => token(seq('--', /.*/)),

    identifier: $ => /[A-za-z][A-za-z0-9!]*/,

    number: $ => /\d+/
  }
});
