const {min1, sep1} = require('./util.js')

// src/Lean/Parser/Command.lean
module.exports = {
  _decl_modifiers: $ => seq(
    min1(
      field('attributes', $._attributes),
      repeat1(
        choice('noncomputable', 'partial', 'private', 'protected', 'unsafe'),
      ),
    ),
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
  _decl_val_simple: $ => seq(':=', $._expression),
  _decl_val_equations: $ => repeat1($.pattern),
  _decl_val: $ => field('body', choice(
    $._decl_val_simple,
    $._decl_val_equations,
    $._where,
  )),
  abbrev: $ => seq(
    'abbrev',
    $._decl_id,
    optional($._opt_decl_sig),
    $._decl_val,
  ),
  def: $ => seq(
    'def',
    $._decl_id,
    optional($._opt_decl_sig),
    $._decl_val,
  ),
  theorem: $ => seq(
    'theorem',
    $._decl_id,
    $._decl_sig,
    $._decl_val,
  ),
  constant: $ => seq(
    'constant',
    $._decl_id,
    $._decl_sig,
    optional($._decl_val_simple),
  ),
  instance: $ => seq(
    'instance',
    optional($._decl_id),
    $._decl_sig,
    $._decl_val,
  ),
  axiom: $ => seq('axiom', $._decl_id, $._decl_sig),
  example: $ => seq(
    'example',
    $._decl_sig,
    $._decl_val,
  ),
  constructor: $ => seq(
    '|',
    field('name', $._dotted_name),
    optional($._opt_decl_sig),
  ),
  _deriving: $ => field('deriving', seq('deriving', sep1($.identifier, ','))),
  inductive: $ => seq(
    'inductive',
    $._decl_id,
    optional($._opt_decl_sig),
    optional(choice(':=', 'where')),
    optional(field('constructors', repeat1($.constructor))),
    optional($._deriving),
  ),
  class_inductive: $ => seq(
    'class', 'inductive',
    $._decl_id,
    optional($._opt_decl_sig),
    optional(choice(':=', 'where')),
    optional(field('constructors', repeat1($.constructor))),
    optional($._deriving),
  ),
  structure: $ => seq(
    choice('structure', 'class'),
    $._decl_id,
    optional($._opt_decl_sig),
    optional(field('extends', seq('extends', sep1($._expression, ',')))),
    'where',
    optional(field('fields', repeat1($.field))),
    optional($._deriving),
  ),
  declaration: $ => seq(
    optional($._decl_modifiers),
    choice(
      $.abbrev,
      $.def,
      $.theorem,
      $.constant,
      $.instance,
      $.axiom,
      $.example,
      $.inductive,
      $.class_inductive,
      $.structure,
    ),
  ),
  section: $ => seq(
    'section',
    optional(field('name', $._dotted_name)),
    field('body', repeat($._command)),
    'end',
    optional($._dotted_name),
  ),
  namespace: $ => seq(
    'namespace',
    field('name', $._dotted_name),
    field('body', repeat($._command)),
    'end',
    $._dotted_name,
  ),
}
