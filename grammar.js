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

    function_definition: $ => choice(
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
      $.identifier,
      $.number
      // TODO: other kinds of expressions
    ),

    identifier: $ => /[A-za-z]+/,

    number: $ => /\d+/
  }
});
