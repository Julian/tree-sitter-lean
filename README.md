# tree-sitter-lean

A [tree-sitter](https://tree-sitter.github.io/) grammar for the
[Lean 4](https://lean-lang.org/) theorem prover.

The parser is designed to be a drop-in for Neovim's `nvim-treesitter`
and any other editor that consumes tree-sitter grammars. Highlight,
fold, indent, locals, and injection queries live under `queries/`.

## What this is

A **static concrete-syntax** parser that covers enough of Lean 4 for
editor tooling: highlighting, folding, indentation, scope-aware
features. Node names mirror Lean's own `SyntaxNodeKind`s where doing
so costs nothing — `Lean.Parser.Command.import` becomes `import`,
`Lean.Parser.Term.app` becomes `app`. Highlight captures use the
nvim-treesitter naming that maps back to Lean's
[`SemanticTokenType`][stt] vocabulary, so cold-start coloring lines up
with what the LSP server emits at runtime.

[stt]: https://github.com/leanprover/lean4/blob/master/src/Lean/Data/Lsp/LanguageFeatures.lean

## What this is *not*

A faithful reproduction of Lean's parser. Lean's parser is dynamic and
extensible: users register new tokens, notation, and categories at
runtime, and macros expand inside a `Syntax` tree the parser
materializes. Tree-sitter is LR(1) + GLR over a static grammar — it
*cannot* model any of that.

Concretely, this grammar does **not** support:

- User-defined `notation` / `syntax` / `macro` extensions. The
  `notation`, `prefix`, `infix`, `infixl`, `infixr`, `postfix`,
  `syntax`, `macro`, and `macro_rules` commands themselves parse, but
  uses of the operators they introduce inside other code are only
  recognized when they're already in the static operator table.
- Custom precedence numbers via `:N` suffixes (e.g. `leading_parser:max`).
- The full set of Mathlib tactics. Tactics are uniformly parsed as
  generic term-shaped invocations; tooling can dispatch on the head
  identifier of an `app` node for highlighting.
- Multi-name structure fields (`x y : T`) and inline doc-comments /
  attributes on individual fields. One name per field, one line per
  field; this matches the dominant style in practice.

`end` is treated as a top-level command rather than a nested closer.
Files in lean4 and Mathlib routinely leave namespaces unclosed
relative to a strict scope discipline, and a flat `end` recovers
better.

## Layout

Tactic and do blocks use the external scanner's indent stack. A
newline-introduced indented region opens a block; subsequent same-
indent lines are separators; a dedent closes the block. EOF closes
every open block. This matches Lean's behavior closely enough for
all real source we've tested.

## State-count budget

The generated `parser.c` is currently under 5 MB. An earlier draft
with one rule per built-in tactic produced a 10 MB file; the grammar
intentionally keeps tactic, do-element, and Mathlib operator
vocabularies generic to avoid LR state explosion. Adding rules that
recurse into `_term` is the most expensive thing you can do here —
double-check the budget after every such change.

## Layout

```
grammar.js               — grammar definition
src/scanner.c            — external scanner (identifiers, comments,
                           raw strings, indent tracking)
queries/
  highlights.scm         — syntax highlighting
  injections.scm         — markdown injection in doc-comments
  locals.scm             — scope-aware definition/reference tracking
  folds.scm              — block-level folds
  indents.scm            — auto-indent hints
test/corpus/             — tree-sitter test corpus
```

## Development

```sh
tree-sitter generate
tree-sitter test
```

`prek` (drop-in for pre-commit) is configured via
`.pre-commit-config.yaml`.

## License

MIT — see [LICENSE](LICENSE).
