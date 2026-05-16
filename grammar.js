/**
 * @file Tree-sitter grammar for the Lean 4 theorem prover.
 *
 * Node names mirror Lean's own `SyntaxNodeKind`s where doing so costs
 * nothing — e.g. `Lean.Parser.Command.import` becomes `import`,
 * `Lean.Parser.Term.app` becomes `app`. Highlight queries should
 * target the same vocabulary the Lean LSP uses for semantic tokens.
 *
 * Stage 0: only enough grammar to verify the toolchain produces a
 * working parser. The lexical layer arrives in Stage 1.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

export default grammar({
  name: 'lean',

  extras: $ => [/\s/],

  word: $ => $._identComponent,

  rules: {
    module: $ => seq(
      optional($.moduleTk),
      optional($.prelude),
      repeat($.import),
    ),

    moduleTk: _ => 'module',
    prelude:  _ => 'prelude',

    import: $ => seq(
      optional($.public),
      optional($.meta),
      'import',
      optional($.all),
      field('name', $.identifier),
    ),

    public: _ => 'public',
    meta:   _ => 'meta',
    all:    _ => 'all',

    identifier: $ => seq(
      $._identComponent,
      repeat(seq(
        token.immediate('.'),
        token.immediate(/[A-Za-z_][A-Za-z_0-9'!?]*/),
      )),
    ),

    _identComponent: _ => /[A-Za-z_][A-Za-z_0-9'!?]*/,
  },
});
