// src/Lean/Parser/Command.lean
module.exports = {
  sorry: $ => 'sorry',

  true: $ => 'true',
  false: $ => 'false',

  _attributes: $ => seq('@[', sep1($._attribute, ','), ']'),

  _term: $ => choice(
    $.sorry,
    $.true,
    $.false,
  ),
}
