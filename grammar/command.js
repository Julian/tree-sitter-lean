const {min1} = require('./util.js')

// src/Lean/Parser/Command.lean
module.exports = {
  abbrev: $ => seq(
    optional($._decl_mods),
    'abbrev',
    $._decl_id,
    optional($._opt_decl_sig),
    $._decl_val,
  ),
  def: $ => seq(
    optional($._decl_mods),
    'def',
    $._decl_id,
    optional($._opt_decl_sig),
    $._decl_val,
  ),
  theorem: $ => seq(
    optional($._decl_mods),
    'theorem',
    $._decl_id,
    $._decl_sig,
    $._decl_val,
  ),
  constant: $ => seq(
    optional($._decl_mods),
    'constant',
    $._decl_id,
    $._decl_sig,
    optional($._decl_val_simple),
  ),
  instance: $ => seq(
    optional($._decl_mods),
    'instance',
    optional($._decl_id),
    $._decl_sig,
    $._decl_val,
  ),
  axiom: $ => seq('axiom', $._decl_id, $._decl_sig),
  example: $ => seq(
    optional($._decl_mods),
    'example',
    $._decl_sig,
    $._decl_val,
  ),

  _decl_id: $ => field('name', $._dotted_name),
  _decl_sig: $ => seq(
    optional(field('parameters', $.parameters)),
    ':', field('type', $._expression),
  ),
  _opt_decl_sig: $ => min1(
    field('parameters', $.parameters),
    seq(':', field('type', $._expression)),
  ),
  _decl_val: $ => field('body', choice(
    $._decl_val_simple,
    $._decl_val_equations,
    $._where,
  )),
  _decl_mods: $ => min1(
    field('attributes', $._attributes),
    repeat1(
      choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
    ),
  ),

  _decl_val_simple: $ => seq(':=', $._expression),
  _decl_val_equations: $ => repeat1($.pattern),
}
