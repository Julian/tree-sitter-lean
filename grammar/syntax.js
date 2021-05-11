// src/Lean/Parser/Syntax.lean
module.exports = {
  notation: $ => seq('notation', $._term, '=>', $._term),
  macro_rules: $ => seq('macro_rules', $._match_alts),
  syntax: $ => seq('syntax', $._term, ':', $.identifier),
}
