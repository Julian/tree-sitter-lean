// src/Lean/Parser/Syntax.lean
module.exports = {
  _precedence: $ => seq(
    token.immediate(':'),
    choice($.number, 'max', 'arg', 'lead', 'min', 'min1'),
  ),
  _syntax_cat: $ => $.identifier,
  _syntax_atom: $ => $.string,
  _syntax: $ => choice(
    $._syntax_cat,
    $._syntax_atom,
  ),

  mixfix: $ => seq(
    optional($._attr_kind),
    choice('prefix', 'infix', 'infixl', 'infixr', 'postfix'),
    $._precedence,
    $.string,
    '=>',
    $._term,
  ),
  notation: $ => seq(
    optional($._attr_kind),
    'notation',
    $._expression,
    '=>',
    $._expression,
  ),
  macro_rules: $ => seq(
    optional($._attr_kind),
    'macro_rules',
    $._match_alts,
  ),
  syntax: $ => seq(
    optional($._attr_kind),
    'syntax',
    repeat1($._syntax),
    ':',
    $.identifier,
  ),
  _macro_arg_simple: $ => seq(
    $.identifier,
    token.immediate(':'),
    $._syntax,
  ),
  _macro_arg_symbol: $ => seq($.string),
  _macro_arg: $ => choice($._macro_arg_symbol, $._macro_arg_simple),
  _macro_head: $ => $._macro_arg,
  _elab_head: $ => $._macro_head,
  _elab_arg: $ => $._macro_arg,
  _elab_tail: $ => seq(
    ':',
    $.identifier,
    optional(seq('<=', $.identifier)),
    '=>',
    $._expression,
  ),
  elab: $ => seq(
    optional($._attr_kind),
    'elab',
    $._elab_head,
    repeat($._elab_arg),
    $._elab_tail,
  ),
}
