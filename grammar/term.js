// src/Lean/Parser/Command.lean
module.exports = {
  number: $ => /\d+/,
  float: $ => /\d+\.\d*/,
  string: $ => seq(
    '"',
    repeat(choice($.escape_sequence, /[^"]/)),
    '"',
  ),
  char: $ => seq("'", choice($.escape_sequence, /[^']/), "'"),
  sorry: $ => 'sorry',

  true: $ => 'true',
  false: $ => 'false',

  attributes: $ => seq('@[', sep1($._attribute, ','), ']'),

  _term: $ => choice(
    $.number,
    $.float,
    $.string,
    $.char,
    $.sorry,
    $.true,
    $.false,
  ),
}
