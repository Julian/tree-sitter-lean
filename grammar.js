const PREC = {
  dollar: -5,
  quantified: -4,
  equal: -3,
  compare: -2,
  apply: -1,
  multitype: -1,

  index: 10,
  field_of: 11,
  parenthesized_expression: 12,
  opop: 13,
  or: 14,
  and: 15,
  eqeq: 16,
  plus: 17,
  times: 18,
  unary: 19,
  power: 20,
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
    [$.typeclass_resolved_parameter, $._atom],
    [$.assign, $._atom],
    [$.inductive_type, $.def, $.structure_definition,
     $.class, $.instance, $.theorem, $.example, $.constant],
  ],

  word: $ => $._identifier,

  rules: {
    module: $ => repeat($._command),

    _command: $ => choice(
      $.prelude,
      $.hash_command,
      $.import,
      $.open,
      $.namespace,
      $.notation,
      $.section,
      $.example,
      $.def,
      $.attribute,
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

    open: $ => seq(
      'open',
      repeat1(field('namespace', $._dotted_name)),
      optional(seq('in', $._command)),
    ),

    hash_command: $ => seq(
      choice('#check', '#check_failure', '#eval', '#print', '#reduce'),
      $._expression,
    ),

    notation: $ => seq(
      'notation', $._expression, '=>', $._expression,
    ),

    constructor: $ => seq(
      '|',
      optional(field('name', $._dotted_name)),
      optional(field('parameters', seq(repeat1($._parameter)))),
      optional(seq(':', field('type', $._expression))),
    ),

    instance_field: $ => seq(
      field('name', $.identifier),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('return_type', $._expression))),
      field('body', choice(
        seq(':=', $._expression),
        repeat1($.pattern),
      )),
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
      optional($.identifier),
    ),

    variable_declaration: $ => seq('variable', repeat1($._parameter)),

    universe: $ => seq(
      choice('universe', 'universes'),
      repeat1($.identifier),
    ),

    function_type: $ => prec(PREC.multitype,
      sep2($._expression, $._right_arrow),
    ),

    product_type: $ => prec.right(PREC.multitype, sep2($._expression, '×')),

    inductive_type: $ => seq(
      repeat(choice('private', 'protected', 'unsafe')),
      'inductive',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('type', $._atom))),
      optional('where'),
      optional(field('constructors', repeat1($.constructor))),
    ),

    def: $ => seq(
      optional(field('attributes', $._attributes)),
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'def',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('return_type', $._expression))),
      field('body', choice(
        seq(':=', $._expression),
        repeat($.pattern),
      )),
    ),

    structure_definition: $ => seq(
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'structure',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      optional(field('extends', seq('extends', sep1($._expression, ',')))),
      'where',
      field('fields', repeat1($.field)),
    ),

    class: $ => seq(
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'class',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      optional(field('extends', seq('extends', sep1($._expression, ',')))),
      'where',
      field('fields', repeat1($.field)),
    ),

    instance: $ => seq(
      optional(field('attributes', $._attributes)),
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'instance',
      optional(field('name', $._dotted_name)),
      optional(field('parameters', seq(repeat1($._parameter)))),
      ':',
      field('class', $._expression),
      field('body', choice(
        seq('where', field('fields', repeat1($.instance_field))),
        seq(':=', $._expression),
      )),
    ),

    theorem: $ => seq(
      optional(field('attributes', $._attributes)),
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'theorem',
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      ':',
      field('type', $._expression),
      ':=',
      field('body', $._expression),
    ),

    example: $ => seq(
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'example',
      optional(field('parameters', $.parameters)),
      ':',
      field('type', $._expression),
      ':=',
      field('body', $._expression),
    ),

    constant: $ => seq(
      optional(field('attributes', $._attributes)),
      repeat(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
      'constant',
      field('name', $.identifier),
      ':',
      field('type', $._expression),
    ),

    _attributes: $ => seq('@[', sep1($.identifier, ','), ']'),

    parameters: $ => seq(
      repeat1(
        choice(
          field('name', $.identifier),
          $._parameter,
          $.inductive_constructor,
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
      $._maybe_annotated,
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
    ),

    _atom: $ => choice(
      $._parenthesized_expression,
      $.identifier,
      $.float,
      $.number,
      $.unary_expression,
    ),

    _primary_expression: $ => choice(
      $.sorry,
      $.coe,
      $._atom,
      $.explicit,
      $.function_type,
      $.product_type,
      $.product,
      $.index,
      $.conditional,
      $.field_of,
      $.match,
      $.quantified,
      $.lambda,
      $.tactics,
      $.binary_expression,
      $.char,
      $.string,
      $.interpolated_string,
      $.inductive_constructor,
      $.structure_literal,
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
      field('name', $._dotted_name),
      optional(field('parameters', $.parameters)),
      optional(seq(':', field('type', $._expression))),
      ':=',
      field('value', $._expression),
      choice($._newline, ';'),
      optional(field('body', $._expression)),
    )),

    sorry: $ => 'sorry',

    tactics: $ => prec.left(seq('by', sep1_($._tactics_command, $._newline))),

    rewrite: $ => seq('rewrite', $._expression),
    term: $ => seq('exact', $._expression),
    simp: $ => prec.right(seq(
      'simp',
      optional(field('extra', $.list)),
    )),

    _tactics_command: $ => choice(
      $.rewrite,
      $.simp,
      $.term,
    ),

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
      choice($.identifier, $.inductive_constructor),
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
      field('name', $._maybe_annotated),
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

    attribute: $ => seq(
      'attribute',
      '[',
      sep1(field('name', $._atom), ','),
      ']',
      field('term', $._expression),
    ),

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

    field_of: $ => prec(PREC.field_of, seq(
      field('term', $._expression),
      '.',
      field('name', choice($.identifier, $.number)),
    )),

    unary_expression: $ => prec(PREC.unary, choice(
      seq('¬', $._expression),
      seq('-', $._atom),
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

    structure_literal: $ => seq(
      '{',
      optional(field('extends', seq($._expression, 'with'))),
      // Unlike everywhere else, records seem OK with trailing commas.
      optional(sep1_($._structure_literal_field, ',')),
      field('type', optional(seq(':', $._expression))),
      '}',
    ),

    _structure_literal_field: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._expression),
    ),

    inductive_constructor: $ => seq('⟨', sep0($._expression, ','), '⟩'),

    quantified: $ => prec(PREC.quantified, seq(
      choice('∀', '∃'),
      field('binders', $.parameters),
      ',',
      field('body', $._expression),
    )),

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

    char: $ => seq("'", choice($.escape_sequence, /[^']/), "'"),
    string: $ => seq(
      '"',
      repeat(choice($.escape_sequence, /[^"]/)),
      '"',
    ),

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

    _dotted_name: $ => prec.right(sep1($.identifier, '.')),

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

    explicit: $ => seq('@', $._dotted_name),

    // FIXME: see name.cpp for the real definition...
    identifier: $ => choice(
      $._lambda_magic_identifier,
      $._identifier,
      $._escaped_identifier,
    ),
    _identifier: $ => /[_a-zA-ZͰ-ϿĀ-ſ∇][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F]*/,
    _escaped_identifier: $ =>  /«[^»]*»/,
    _lambda_magic_identifier: $ => choice('.', '·'),

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

function sep0 (rule, separator) {
  return optional(sep1(rule, separator))
}

function sep1 (rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}

function sep2 (rule, separator) {
  return seq(rule, repeat1(seq(separator, rule)))
}

function sep1_ (rule, separator) {
  return seq(sep1(rule, separator), optional(separator))
}
