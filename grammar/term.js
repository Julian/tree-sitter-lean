// src/Lean/Parser/Command.lean
module.exports = {
  sorry: $ => 'sorry',

  true: $ => 'true',
  false: $ => 'false',

  _term: $ => choice(
    $.sorry,
    $.true,
    $.false,
  ),
}
