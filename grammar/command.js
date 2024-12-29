import { min1 } from './helpers.js';

export default {
  _command: $ => choice(
    $.scoped_in,

    $.interactive,

    $.declaration,
    $.section,
    $.namespace,
    $.variable,
    $.export,
    $.open,
  ),

  scoped_in: $ => prec.right(seq($._command, 'in', $._command)),

  // src/Lean/Parser/Command.lean
  _visibility: $ => choice('private', 'protected'),
  _decl_modifiers: $ => seq(
    min1(
      $.attributes,
      repeat1(
        choice('noncomputable', 'partial', $._visibility, 'unsafe'),
      ),
    ),
  ),
  _decl_id: $ => prec('declId', field('name', $.identifier)),
  _decl_sig: $ => seq(
    alias(
      repeat(choice($._binder_ident, $._bracketed_binder)),
      $.binders,
    ),
    $._type_spec,
  ),
  _opt_decl_sig: $ => min1(
    alias(
      repeat1(choice($._binder_ident, $._bracketed_binder)),
      $.binders,
    ),
    $._type_spec,
  ),
  _decl_val_simple: $ => seq(':=', $._term),
  _decl_val: $ => field('body', choice(
    $._decl_val_simple,
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

  interactive: $ => seq(
    choice(
      '#check',
      '#check_failure',
      '#eval',
      '#print',
      '#reduce',
    ),
    $._term,
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
    ),
  ),
  section: $ => seq(
    'section',
    optional(field('name', $.identifier)),
    field('body', repeat($._command)),
    'end',
    optional($.identifier),
  ),
  namespace: $ => seq(
    'namespace',
    field('name', $.identifier),
    field('body', repeat($._command)),
    'end',
    $.identifier,
  ),

  variable: $ => seq('variable', repeat1($._bracketed_binder)),

  _open_only: $ => seq(
    field('namespace', $.identifier),
    '(',
    repeat1(field('only', $.identifier)),
    ')',
  ),
  _open_simple: $ => repeat1(field('namespace', $.identifier)),
  _open_scoped: $ => seq(
    'scoped',
    repeat1(field('scoped', $.identifier)),
  ),
  _open_decl: $ => choice(
    $._open_only,
    $._open_simple,
    $._open_scoped,
  ),
  open: $ => seq(
    'open',
    $._open_decl,
  ),
  export: $ => seq(
    'export',
    field('class', $.identifier),
    '(',
    repeat1($.identifier),
    ')',
  ),
};
