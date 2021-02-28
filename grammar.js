const PREC = {
  dollar: -2,
  apply: -1,
  parenthesized_expression: 1,
  compare: -1,
  element_of: 1,

  equal: -1,
  negation: 1,
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
      'where',
      field('constructors', repeat1($.constructor)),
    ),

    instance: $ => seq(
      'instance',
      optional(field('name', $.identifier)),
      ':',
      field('class', $._expression),
      'where',
      field('fields', repeat1($.instance_field)),
    ),

    instance_field: $ => seq(
      field('name', $.identifier),
      field('parameters', $.parameter_list),
      ':',
      field('return_type', $._expression),
      ':=',
      field('implementation', $._expression),
    ),

    constructor: $ => seq(
      '|', $.identifier, ':', $.identifier,
    ),

    namespace: $ => seq(
      'namespace',
      field('name', $.identifier),
      repeat($._command),
      'end',
      $.identifier,
    ),

    section: $ => seq(
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
      repeat1($.identifier),
      ':',
      $._type_annotation,
      ')',
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
      field('parameters', optional($.parameter_list)),
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
      field('parameters', optional($.parameter_list)),
      'where',
      field('fields', repeat1($.structure_field)),
    ),

    theorem: $ => seq(
      'theorem',
      field('name', $.identifier),
      field('parameters', optional($.parameter_list)),
      ':',
      $._expression,
      ':=',
      $.identifier,
    ),

    example: $ => seq(
      'example',
      ':',
      $._expression,
      ':=',
      $._expression,
    ),

    _expression: $ => choice(
      $.identifier,
      $._parenthesized_expression,
      $.product,
      $.comparison,
      $.conditional,
      $.element_of,
      $.match,
      $.apply,
      $.lambda,
      $.do,
      $.unary_expression,
      $.binary_expression,
      $.number,
      $.string,
      $.inductive_constructor,
      $.list,
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
        $.let,
        $.try,
        $.throw,
        $.return,
      ),
      $._newline,
    ),

    do: $ => prec.right(seq('do', repeat($._do_expression))),

    let: $ => seq(
      'let', $.identifier, choice('<-', '←', ':='), $._expression,
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
      $.identifier,
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

    lambda: $ => seq(
      'fun', $.parameter_list, '=>', $._expression,
    ),

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

    element_of: $ => prec(PREC.element_of, seq(
      field('type', $._expression),
      '.',
      field('field', $.identifier),
    )),

    unary_expression: $ => choice(
      prec.left(PREC.negation, seq('!', $._expression)),
    ),

    binary_expression: $ => choice(
      prec.left(2, seq($._expression, '*', $._expression)),
      prec.left(1, seq($._expression, '+', $._expression)),
      prec.left(1, seq($._expression, '-', $._expression)),

      prec.left(1, seq($._expression, '++', $._expression)),
      prec.left(1, seq($._expression, '::', $._expression)),

      prec.left(1, seq($._expression, '<|>', $._expression)),

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

    string: $ => seq(
      '"',
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

    true: $ => 'true',
    false: $ => 'false',
  }
});

function sep1 (rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}
