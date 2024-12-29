import { min1 } from './helpers.js';

export default {
  _command: $ => choice(
    $.scopedIn,

    $.interactive,

    $.declaration,
    $.section,
    $.namespace,
    $.variable,
    $.export,
    $.open,
  ),

  scopedIn: $ => prec.right(seq($._command, 'in', $._command)),

  // src/Lean/Parser/Command.lean
  _visibility: $ => choice('private', 'protected'),
  _declModifiers: $ => seq(
    min1(
      $.attributes,
      repeat1(
        choice('noncomputable', 'partial', $._visibility, 'unsafe'),
      ),
    ),
  ),
  _declId: $ => prec('declId', field('name', $.identifier)),
  _declSig: $ => seq(
    alias(
      repeat(choice($._binderIdent, $._bracketedBinder)),
      $.binders,
    ),
    $._typeSpec,
  ),
  _optDeclSig: $ => min1(
    alias(
      repeat1(choice($._binderIdent, $._bracketedBinder)),
      $.binders,
    ),
    $._typeSpec,
  ),
  _declValSimple: $ => seq(':=', $._term),
  _declVal: $ => field('body', choice(
    $._declValSimple,
  )),
  abbrev: $ => seq(
    'abbrev',
    $._declId,
    optional($._optDeclSig),
    $._declVal,
  ),
  def: $ => seq(
    'def',
    $._declId,
    optional($._optDeclSig),
    $._declVal,
  ),
  theorem: $ => seq(
    'theorem',
    $._declId,
    $._declSig,
    $._declVal,
  ),
  constant: $ => seq(
    'constant',
    $._declId,
    $._declSig,
    optional($._declValSimple),
  ),
  instance: $ => seq(
    'instance',
    optional($._declId),
    $._declSig,
    $._declVal,
  ),
  axiom: $ => seq('axiom', $._declId, $._declSig),
  example: $ => seq(
    'example',
    $._declSig,
    $._declVal,
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
    optional($._declModifiers),
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

  variable: $ => seq('variable', repeat1($._bracketedBinder)),

  _openOnly: $ => seq(
    field('namespace', $.identifier),
    '(',
    repeat1(field('only', $.identifier)),
    ')',
  ),
  _openSimple: $ => repeat1(field('namespace', $.identifier)),
  _openScoped: $ => seq(
    'scoped',
    repeat1(field('scoped', $.identifier)),
  ),
  _openDecl: $ => choice(
    $._openOnly,
    $._openSimple,
    $._openScoped,
  ),
  open: $ => seq(
    'open',
    $._openDecl,
  ),
  export: $ => seq(
    'export',
    field('class', $.identifier),
    '(',
    repeat1($.identifier),
    ')',
  ),
};
