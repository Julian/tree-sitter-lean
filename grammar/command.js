export default {
  _command: $ => choice(
    $.interactive,
    $.open,
    $.export,
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
    optional(seq('in', $._command)),
  ),
  export: $ => seq(
    'export',
    field('class', $.identifier),
    '(',
    repeat1($.identifier),
    ')',
  ),
};
