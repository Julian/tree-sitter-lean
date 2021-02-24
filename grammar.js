const PREC = {
  parenthesized_expression: 1,
}

module.exports = grammar({
  name: 'lean',

  rules: {
    source_file: $ => repeat($._command),

    _command: $ => choice(
      $._hash_command,
      $.namespace_definition,
      $.section_definition,
      $.function_definition,
      $.theorem_definition,
      // TODO: other kinds of definitions
    ),

    _hash_command: $ => choice(
      $.eval_command,
    ),

    eval_command: $ => seq(
      '#eval', $._expression,
    ),

    namespace_definition: $ => seq(
      'namespace',
      $.identifier,
      repeat($._command),
      'end',
      $.identifier,
    ),

    section_definition: $ => seq(
      'section',
      $.identifier,
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
      $.identifier,
      ':',
      $._expression,
      ':=',
      $.identifier,
    ),

    _expression: $ => choice(
      prec(1, $.identifier),
      $._parenthesized_expression,
      $.function_application,
      $.binary_expression,
      $.number,
      $.string,
      // TODO: other kinds of expressions
    ),

    _parenthesized_expression: $ => prec(PREC.parenthesized_expression, seq(
      '(',
      $._expression,
      ')'
    )),

    argument_list: $ => seq(
      prec.left(repeat1($._expression)),
    ),

    function_application: $ => seq(
      field('name', $.identifier),
      prec.left(1, field('arguments', $.argument_list)),
    ),

    binary_expression: $ => choice(
      prec.left(2, seq($._expression, '*', $._expression)),
      prec.left(1, seq($._expression, '+', $._expression)),
      prec.left(1, seq($._expression, '-', $._expression)),
    ),

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

    identifier: $ => /[A-za-z][A-za-z0-9!]*/,

    number: $ => /\d+/
  }
});
