module.exports = {
  tactics: $ => prec.left(
    seq('by', sep1_($._tactic, seq(optional(';'), $._newline))),
  ),

  apply_tactic: $ => seq('apply', $._expression),
  intro: $ => seq('intro', $.identifier),
  rewrite: $ => seq(choice('rewrite', 'rw'), $._expression),
  term: $ => seq('exact', $._expression),
  simp: $ => prec.right(seq(
    'simp',
    optional(field('extra', $.list)),
  )),
  trivial: $ => 'trivial',

  _user_tactic: $ => $._expression,

  _tactic: $ => choice(
    $.apply_tactic,
    $.intro,
    $.rewrite,
    $.simp,
    $.term,
    $.trivial,
    $._user_tactic,
  ),
}
