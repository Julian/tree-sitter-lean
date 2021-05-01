// src/Lean/Parser/Attr.lean

module.exports = {
  _attribute: $ => choice($._simple_attribute),

  _simple_attribute: $ => seq($._dotted_name, optional($._dotted_name)),
}
