const {PREC} = require('./basic.js')

// src/Lean/Parser/Do.lean
module.exports = {
  _do_seq_indent: $ => seq($._indent, $._do_element),
  _do_seq: $ => choice($._do_seq_indent),

  do_let: $ => seq('let ', optional('mut'), $._let_decl),
  do_catch: $ => seq(
    'catch',
    $._binder_ident,
    optional(seq(':', $._term)),
    '=>',
    $._do_seq,
  ),
  do_finally: $ => seq('finally', $._do_seq),
  _do_for_decl: $ => seq($._term, 'in', $._term),
  do_for: $ => seq(
    'for',
    sep1($._do_for_decl, ','),
    'do',
    $._do_seq,
  ),
  do_try: $ => seq(
    'try',
    $._do_seq,
    repeat(choice($.do_catch)),
    optional($.do_finally),
  ),
  do_return: $ => prec.left(PREC.lead,
    seq('return', optional(field('value', $._term))),
  ),
  do_unless: $ => seq('unless', $._term, $._do_seq),

  do: $ => prec(PREC.lead, seq('do', $._do_seq)),

  _do_element: $ => choice(
    $.do_try,
  ),
}
