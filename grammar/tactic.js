module.exports = {
  // src/Init/Notation.lean
  intro: $ => seq('intro', $.identifier),
  apply_tactic: $ => seq('apply', $._term),
  term: $ => seq('exact', $._term),
  rewrite: $ => seq(choice('rewrite', 'rw'), $._term),
  simp: $ => prec.left(seq(
    'simp',
    optional(field('extra', $.list)),
  )),
  trivial: $ => 'trivial',

  user_tactic: $ => $._term,

  _tactic: $ => choice(
    alias($.apply_tactic, $.apply),
    $.intro,
    $.rewrite,
    $.simp,
    $.term,
    $.trivial,
    $.user_tactic,
  ),
}
