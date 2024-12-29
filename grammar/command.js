export default {
  _command: $ => choice(
    $.scoped_in,

    $.def,

    $.interactive,

    $.open,
    $.export,
    $.section,
    $.namespace,
    $.variable,
  ),

  // src/Lean/Parser/Command.lean
  scoped_in: $ => prec.right(seq($._command, 'in', $._command)),

  _decl_id: $ => field('name', $.identifier),
  _decl_val_simple: $ => seq(':=', $._term),
  _decl_val: $ => field('body', choice(
    $._decl_val_simple,
  )),
  def: $ => seq(
    'def',
    $._decl_id,
    $._decl_val,
  ),

  interactive: $ => seq(
    choice(
      '#check',
      '#check_failure',
      '#eval',
      '#print',
      '#reduce',
    ),
    $._term,
  ),

  open: $ => seq(
    'open',
    repeat1(field('namespace', $.identifier)),
  ),
  export: $ => seq(
    'export',
    field('class', $.identifier),
    '(',
    repeat1($.identifier),
    ')',
  ),

  section: $ => seq(
    'section',
    optional(field('name', $.identifier)),
    field('body', repeat($._command)),
    'end',
    optional($.identifier),
  ),
  namespace: $ => seq(
    'namespace',
    field('name', $.identifier),
    field('body', repeat($._command)),
    'end',
    $.identifier,
  ),

  variable: $ => seq('variable', repeat1($._bracketed_binder)),
};
