// src/Lean/Parser/Syntax.lean
module.exports = {
  notation: $ => seq('notation', $._expression, '=>', $._expression),
  macro_rules: $ => seq('macro_rules', repeat($.pattern)),
  syntax: $ => seq('syntax', $._expression, ':', $.identifier),
}
