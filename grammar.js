/**
 * @file Tree-sitter grammar for the Lean 4 theorem prover.
 *
 * Node names mirror Lean's own `SyntaxNodeKind`s where doing so costs
 * nothing — e.g. `Lean.Parser.Command.import` becomes `import`,
 * `Lean.Parser.Term.app` becomes `app`. Highlight queries should target
 * the same vocabulary the Lean LSP uses for semantic tokens.
 *
 * Stage 1: full lexical layer plus a placeholder `_term` exposed via
 * `#check` so the literals can be exercised. Syntactic layers arrive in
 * Stage 2.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

export default grammar({
  name: 'lean',

  externals: $ => [
    $.identifier,
    $.block_comment,
    $.doc_comment,
    $.module_doc_comment,
    $.raw_string,
    $.error_sentinel,
  ],

  extras: $ => [
    /\s/,
    $.line_comment,
    $.block_comment,
    $.doc_comment,
  ],

  word: $ => $._wordToken,

  conflicts: _ => [],

  rules: {
    module: $ => seq(
      optional($.module_doc_comment),
      optional($.moduleTk),
      optional($.prelude),
      repeat($.import),
      repeat($._command),
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

    /* Stage 1 places a single `#check` command so every literal form
       has a syntactic home to be parsed in. Real command grammar
       arrives in Stage 2. */
    _command: $ => $.check,
    check: $ => seq('#check', field('term', $._term)),

    _term: $ => choice(
      $.identifier,
      $.num_lit,
      $.scientific_lit,
      $.char_lit,
      $.str_lit,
      $.raw_string,
      $.interpolated_str,
      $.name_lit,
    ),

    /* ----- numerics ---------------------------------------------------- */

    num_lit: _ => token(choice(
      /0[xX][0-9a-fA-F](_?[0-9a-fA-F])*/,
      /0[oO][0-7](_?[0-7])*/,
      /0[bB][01](_?[01])*/,
      /[0-9](_?[0-9])*/,
    )),

    scientific_lit: _ => token(choice(
      // 1.0, 1.0e10, 1e10, .5 (Lean accepts trailing dot too)
      /[0-9](_?[0-9])*\.[0-9]?(_?[0-9])*([eE][+-]?[0-9](_?[0-9])*)?/,
      /[0-9](_?[0-9])*[eE][+-]?[0-9](_?[0-9])*/,
    )),

    /* ----- characters & strings --------------------------------------- */

    char_lit: $ => seq(
      '\'',
      choice($.escape_sequence, /[^'\\\n]/),
      '\'',
    ),

    str_lit: $ => seq(
      '"',
      repeat(choice(
        $.escape_sequence,
        token.immediate(prec(1, /[^"\\\n]+/)),
      )),
      '"',
    ),

    escape_sequence: _ => token.immediate(seq('\\', choice(
      /[\\"'rnt0]/,
      /x[0-9a-fA-F]{2}/,
      /u[0-9a-fA-F]{4}/,
      /u\{[0-9a-fA-F]+\}/,
    ))),

    /* s!"… {expr} …", m!"… {expr} …" — only one level of `{ … }` nesting
       beyond the string body is permitted by the lexer. */
    interpolated_str: $ => seq(
      $._interp_open,
      repeat(choice(
        $.escape_sequence,
        $.interpolation,
        token.immediate(prec(1, /[^"\\\{\n]+/)),
      )),
      '"',
    ),
    _interp_open: _ => choice('s!"', 'm!"'),
    interpolation: $ => seq(
      token.immediate('{'),
      $._term,
      '}',
    ),

    /* `name literal — a backtick followed by an identifier. */
    name_lit: $ => seq(
      '`',
      field('name', $.identifier),
    ),

    /* ----- comments --------------------------------------------------- */

    line_comment: _ => token(seq('--', /[^\n]*/)),

    /* `block_comment`, `doc_comment`, `module_doc_comment` come from the
       external scanner; declared in externals above. */

    /* ----- internal word token for keyword recognition ---------------- */

    /* Tree-sitter uses `word` to disambiguate keywords vs. identifiers
       when an external identifier rule is in play. This must be a regex
       (not external) and only needs to match the ASCII portion of a
       keyword's spelling. */
    _wordToken: _ => /[a-zA-Z_][a-zA-Z_0-9]*/,
  },
});
