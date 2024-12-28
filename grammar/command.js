export default {
  _command: $ => choice(
    $.interactive,
    $.open,
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
};
