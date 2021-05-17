// src/Lean/Parser/Attr.lean

module.exports = {
  _attribute: $ => choice($._simple_attribute),

  _simple_attribute: $ => field(
    'name', seq($.identifier, optional($.identifier)),
  ),
}
