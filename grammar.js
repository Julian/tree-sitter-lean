/**
 * @file Tree-sitter grammar for the Lean 4 theorem prover.
 *
 * Node names mirror Lean's own `SyntaxNodeKind`s where doing so costs
 * nothing — e.g. `Lean.Parser.Command.import` becomes `import`,
 * `Lean.Parser.Term.app` becomes `app`. Highlight queries should target
 * the same vocabulary the Lean LSP uses for semantic tokens.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

/* Operator precedence — higher binds tighter. Numbers loosely follow
   Lean's notation precedences in `Init/Notation.lean`. Each level here
   becomes one prec annotation on a single `binary_op` choice variant. */
const PREC = {
  arrow:  10,
  iff:    20,
  or:     30,
  and:    35,
  cmp:    50,
  append: 60,
  add:    70,
  mul:    80,
  pow:    85,
  comp:   90,
  pipe:   95,
  prefix: 100,
  app:    110,
  proj:   120,
};

const sep1 = (rule, sep) => seq(rule, repeat(seq(sep, rule)));
const sep0 = (rule, sep) => optional(sep1(rule, sep));

export default grammar({
  name: 'lean',

  externals: $ => [
    $._scanned_ident,
    $.block_comment,
    $.doc_comment,
    $.module_doc_comment,
    $.raw_string,
    $._indent,
    $._dedent,
    $._newline,
    $.error_sentinel,
  ],

  extras: $ => [
    /[ \t\r\n]/,
    $.line_comment,
    $.block_comment,
    $.doc_comment,
  ],

  word: $ => $._plain_ident,

  conflicts: $ => [
    /* `public`/`meta` can start either an `import` or a Lean 4
       module-system-visibility-prefixed declaration. */
    [$.import, $.declaration],
  ],

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

    /* ===== commands ====================================================== */

    _command: $ => choice(
      $.check,
      $.eval,
      $.print,
      $.reduce,
      $.namespace,
      $.section,
      $.public_section,
      $.end,
      $.variable,
      $.universe,
      $.open,
      $.export,
      $.attribute_cmd,
      $.initialize,
      $.set_option,
      $.deriving_cmd,
      $.assert_cmd,
      $.declaration,
    ),

    /* `assert_not_exists Name`, `assert_not_imported Name`, etc. —
       Lean's lightweight assertion commands taking a single ident. */
    assert_cmd: $ => seq(
      choice(
        'assert_not_exists', 'assert_not_imported',
        'assert_exists', 'check_assertions',
        '#exit', '#synth', '#version',
      ),
      optional(field('target', $._term_atom)),
    ),

    /* `deriving instance Foo, Bar for Baz` — standalone deriving. */
    deriving_cmd: $ => seq(
      'deriving', 'instance',
      sep1(field('class', $.identifier), ','),
      'for',
      sep1(field('target', $.identifier), ','),
    ),

    /* `set_option pp.all true` — value is intentionally restricted to
       an atom (literal/identifier) so it can't consume the rest of
       the file as part of an over-eager `_term` parse. */
    set_option: $ => seq(
      'set_option',
      field('name', $.identifier),
      field('value', $._term_atom),
    ),

    /* `attribute [foo] bar baz` — bracketed attr list followed by
       targets. Different syntax from declaration-leading `@[…]`. */
    attribute_cmd: $ => prec.right(seq(
      'attribute',
      '[', sep1($._attr_instance, ','), ']',
      repeat1(field('target', $.identifier)),
    )),

    /* `initialize` and `builtin_initialize` introduce a side-effectful
       module-level binding evaluated at module-load time. */
    initialize: $ => prec.right(seq(
      choice('initialize', 'builtin_initialize'),
      optional(seq(
        field('name', $._binder_ident),
        optional($._type_spec),
        choice(':=', '←', '<-'),
      )),
      choice(
        $._term,
        seq(
          $._indent,
          sep1($._term, choice(';', $._newline)),
          $._dedent,
        ),
      ),
    )),

    /* `public section` is a Lean 4 module-system marker — everything
       below is exported. It has no body and no matching `end`.
       Optionally preceded by attributes (e.g. `@[expose] public section`). */
    public_section: $ => seq(
      optional($.attributes),
      'public', 'section',
    ),

    check:  $ => seq(choice('#check', '#check_failure'),  field('term', $._term)),
    eval:   $ => seq('#eval',   field('term', $._term)),
    print:  $ => seq(choice('#print', '#print_axioms'),   field('term', $._term)),
    reduce: $ => seq('#reduce', field('term', $._term)),

    /* `namespace`, `section`, and `end` are top-level commands rather
       than nested rules. Files in lean4 + Mathlib routinely leave
       namespaces unclosed (relying on EOF as `end`), which a nested
       grammar can't accept. Editor tooling can reconstruct scope by
       pairing namespace/end siblings via queries. */
    namespace: $ => seq(
      optional($.decl_modifiers),
      'namespace', field('name', $.identifier),
    ),
    section: $ => seq(
      optional($.decl_modifiers),
      'section', optional(field('name', $.identifier)),
    ),
    end: $ => seq('end', optional(field('name', $.identifier))),

    variable: $ => seq('variable', repeat1($._bracketed_binder)),

    universe: $ => seq(
      choice('universe', 'universes'),
      repeat1(field('name', $.identifier)),
    ),

    open: $ => seq('open', $._open_decl),
    _open_decl: $ => choice(
      seq(
        field('namespace', $.identifier),
        '(',
        repeat1(field('only', $.identifier)),
        ')',
      ),
      seq('scoped', repeat1(field('scoped', $.identifier))),
      repeat1(field('namespace', $.identifier)),
    ),

    export: $ => seq(
      'export',
      field('namespace', $.identifier),
      '(',
      repeat1(field('only', $.identifier)),
      ')',
    ),

    /* ----- declarations ------------------------------------------------- */

    declaration: $ => seq(
      optional($.attributes),
      optional($._visibility_mods),
      optional($.decl_modifiers),
      choice(
        $.def,
        $.theorem,
        $.example,
        $.abbrev,
        $.instance,
        $.axiom,
        $.opaque,
        $.constant,
        $.structure,
        $.inductive,
      ),
    ),

    /* Lean 4 module system visibility markers `public`/`meta` —
       structured separately from decl_modifiers to avoid conflict
       with the `import` prefix forms. May appear before or after
       decl_modifiers (`protected meta def …`). */
    _visibility_mods: $ => repeat1(choice($.public, $.meta)),

    decl_modifiers: $ => repeat1(choice(
      'noncomputable',
      'partial',
      'nonrec',
      'private',
      'protected',
      'unsafe',
    )),

    attributes: $ => seq('@[', sep1($._attr_instance, ','), ']'),
    _attr_instance: $ => seq(
      optional(choice('scoped', 'local')),
      $._attribute,
    ),
    /* Attributes can carry arguments (`@[simp 1000]`,
       `@[combinator_parenthesizer foo, expose]`, `@[simps -isSimp]`).
       Args restricted to atoms or unary-prefixed atoms (`-isSimp`,
       `←foo`) to keep state count bounded. */
    _attribute: $ => seq(
      field('name', $.identifier),
      repeat(field('arg', choice($._term_atom, $.unary_op))),
    ),


    def: $ => seq(
      'def',
      field('name', $.identifier),
      optional($._binders),
      optional($._type_spec),
      $._decl_val,
    ),

    theorem: $ => seq(
      choice('theorem', 'lemma'),
      field('name', $.identifier),
      optional($._binders),
      $._type_spec,
      $._decl_val,
    ),

    example: $ => seq(
      'example',
      optional($._binders),
      optional($._type_spec),
      $._decl_val,
    ),

    abbrev: $ => seq(
      'abbrev',
      field('name', $.identifier),
      optional($._binders),
      optional($._type_spec),
      $._decl_val,
    ),

    /* Two distinct shapes so tree-sitter doesn't have to disambiguate
       `instance ident (` against `instance (binder)`. With a name, the
       binder list can be `_binders` (bare-ident or bracketed). Without a
       name, only bracketed binders are accepted — the name slot doesn't
       compete with bare-ident binders. */
    instance: $ => choice(
      seq(
        'instance',
        field('name', $.identifier),
        optional($._binders),
        $._type_spec,
        $._decl_val,
      ),
      seq(
        'instance',
        repeat($._bracketed_binder),
        $._type_spec,
        $._decl_val,
      ),
    ),

    axiom: $ => seq(
      'axiom',
      field('name', $.identifier),
      optional($._binders),
      $._type_spec,
    ),

    opaque: $ => seq(
      'opaque',
      field('name', $.identifier),
      optional($._binders),
      $._type_spec,
      optional($._decl_val),
    ),

    constant: $ => seq(
      'constant',
      field('name', $.identifier),
      optional($._binders),
      $._type_spec,
      optional($._decl_val),
    ),

    structure: $ => prec.right(seq(
      choice('structure', 'class'),
      field('name', $.identifier),
      optional($._binders),
      optional($._type_spec),
      optional($._extends_clause),
      optional(seq(
        'where',
        optional($.ctor),
        repeat($.field),
      )),
      optional($._deriving_clause),
    )),

    inductive: $ => prec.right(seq(
      choice('inductive', seq('class', 'inductive')),
      field('name', $.identifier),
      optional($._binders),
      optional($._type_spec),
      optional($._extends_clause),
      optional(seq('where',
        repeat($.ctor_alt))),
      optional($._deriving_clause),
    )),

    _extends_clause: $ => seq('extends', sep1($._term, ',')),

    /* `MkStruct ::` declares a named constructor (followed by fields).
       Optionally preceded by decl modifiers (e.g. `private mk ::`). */
    ctor: $ => seq(
      optional($.decl_modifiers),
      field('name', $.identifier),
      '::',
    ),

    /* Fields do not allow inline attributes/doc-comments or multi-name
       grouping: both create unresolvable ambiguities with the
       surrounding declaration. Real Lean code overwhelmingly uses one
       name per line in structure fields. doc_comment is in `extras`
       so it still attaches to the field as trivia. Also accepts
       `[name : T]` instance-implicit field form. */
    field: $ => choice(
      seq(
        field('name', $._binder_ident),
        $._type_spec,
        optional(field('default', seq(':=', $._term))),
      ),
      seq(
        '[',
        field('name', $._binder_ident),
        $._type_spec,
        ']',
      ),
    ),

    ctor_alt: $ => seq(
      '|',
      field('name', $.identifier),
      optional($._binders),
      optional($._type_spec),
    ),

    _deriving_clause: $ => seq('deriving', sep1($.identifier, ',')),

    /* A declaration body is either `:= term`, a sequence of match-
       style equations `| pat => body | …`, or a `where`-style struct
       body of `field := value` lines (instance/anonymous-structure
       def form). */
    _decl_val: $ => choice(
      field('body', seq(':=', $._term)),
      repeat1($.match_alt),
      $.where_struct,
    ),
    _type_spec: $ => field('type', seq(':', $._term)),

    /* `where f := v g := w …` body of a `def name : T where …` —
       declares a value of a structure/instance type by field. */
    where_struct: $ => prec.right(seq(
      'where',
      repeat1($.struct_field),
    )),

    /* ===== binders ======================================================= */

    _binders: $ => alias(repeat1($._binder), $.binders),
    _binder: $ => choice($._binder_ident, $._bracketed_binder, $.tuple_binder),

    /* `fun (x, y) => …` — destructured tuple as a single binder.
       Distinct from `explicit_binder` (which has `:`). */
    tuple_binder: $ => seq('(',
      $._binder_ident, ',', sep1($._binder_ident, ','),
      ')'),

    _binder_ident: $ => choice($.identifier, $.hole),

    _bracketed_binder: $ => choice(
      $.explicit_binder,
      $.implicit_binder,
      $.strict_implicit_binder,
      $.instance_binder,
    ),

    explicit_binder: $ => seq(
      '(',
      repeat1(field('name', $._binder_ident)),
      optional($._type_spec),
      optional(field('default', seq(':=', $._term))),
      ')',
    ),

    implicit_binder: $ => seq(
      '{',
      repeat1(field('name', $._binder_ident)),
      optional($._type_spec),
      '}',
    ),

    strict_implicit_binder: $ => seq(
      choice('⦃', '{{'),
      repeat1(field('name', $._binder_ident)),
      optional($._type_spec),
      choice('⦄', '}}'),
    ),

    instance_binder: $ => seq(
      '[',
      optional(seq(field('name', $.identifier), ':')),
      field('type', $._term),
      ']',
    ),

    /* ===== terms =========================================================
     *
     * Split into three tiers to keep LR state count under control:
     *
     *   `_term`         — any term; the entry point for declarations,
     *                     fun bodies, paren contents, etc.
     *   `_lead_term`    — terms that begin with a keyword and consume
     *                     everything to their right at low precedence
     *                     (fun/let/have/show/if/match/forall/exists/
     *                     by/do). Not allowed as binary-op operands.
     *   `_op_term`      — terms that participate in operator chains:
     *                     atoms, application, projection, binary ops,
     *                     unary ops.
     *
     * Restricting binary-op operands to `_op_term` rather than `_term`
     * stops every operator state from forking through every lead-term
     * alternative. Lead terms can still wrap an op-term (`fun x => x + 1`)
     * because the `_term` rule under fun's body covers both.
     */

    _term: $ => choice($._lead_term, $._op_term),

    _lead_term: $ => choice(
      $.fun,
      $.let,
      $.have,
      $.show,
      $.if_then_else,
      $.forall,
      $.exists,
      $.by,
      $.do_block,
      $.match,
    ),

    _op_term: $ => choice(
      $._term_atom,
      $.app,
      $.proj,
      $.subscript,
      $.postfix_op,
      $.binary_op,
      $.unary_op,
    ),

    _term_atom: $ => choice(
      $.identifier,
      $.num_lit,
      $.scientific_lit,
      $.char_lit,
      $.str_lit,
      $.raw_string,
      $.interpolated_str,
      $.name_lit,
      $.hole,
      $.synth_hole,
      $.named_hole,
      $.cdot,
      $.dot_ident,
      $.type_const,
      $.sort_const,
      $.prop_const,
      $.true_const,
      $.false_const,
      $.sorry,
      $.paren,
      $.anon_ctor,
      $.list_lit,
      $.range_lit,
      $.array_lit,
      $.struct_lit,
      $.set_builder,
      $.subtype_lit,
      $.rest_pat,
      $.prec_annotated,
      $.pct_macro,
      $.explicit_mode,
      $.quotation,
    ),

    /* `.foo` is Lean's anonymous-namespace projection (used for
       constructors and methods). Distinct from `e.foo` projection. */
    dot_ident: $ => seq('.', field('name', $.identifier)),

    /* `..` rest-pattern, used inside match arms. */
    rest_pat: _ => '..',

    /* `name:precNum` — precedence annotation on a parser combinator
       like `leading_parser:leadPrec`. The `:` is immediate (no space
       allowed). */
    prec_annotated: $ => seq(
      field('name', $.identifier),
      token.immediate(':'),
      field('prec', choice($.identifier, $.num_lit)),
    ),

    /* `ident%` — Lean built-in macro postfix (e.g. `decl_name%`). */
    pct_macro: $ => seq(
      field('name', $.identifier),
      token.immediate('%'),
    ),

    /* `@foo` — disables implicit insertion (explicit args mode).
       Distinct from `@[…]` attributes via immediate-next-char check. */
    explicit_mode: $ => seq('@', $.identifier),


    hole:        _ => '_',
    synth_hole:  _ => '?_',
    named_hole:  $ => seq('?', $.identifier),
    /* `·` (cdot) — placeholder for the next argument of an anonymous
       function. `(·.foo bar)` reads as `(fun x => x.foo bar)`. */
    cdot:        _ => '·',

    type_const: $ => prec.right(1, seq('Type', optional(choice(
      $.identifier,
      '*',
      seq('.{', sep1($.identifier, ','), '}'),
    )))),
    sort_const: $ => prec.right(1, seq('Sort', optional(choice(
      $.identifier,
      '*',
    )))),
    prop_const: _ => 'Prop',
    /* Capital `True`/`False` are Prop; lowercase `true`/`false` are
       the boolean inductive's constructors. */
    true_const:  _ => choice('True', 'true'),
    false_const: _ => choice('False', 'false'),
    sorry:       _ => choice('sorry', 'admit'),

    paren: $ => seq(
      '(',
      optional(choice(
        /* Named-argument form: `(name := value)`. */
        seq(
          field('arg_name', $.identifier),
          ':=',
          field('arg_value', $._term),
        ),
        /* Regular parenthesized term, optionally type-ascribed, with
           an optional tuple tail. */
        seq(
          $._term,
          optional($._type_spec),
          repeat(seq(',', $._term)),
        ),
      )),
      ')',
    ),

    anon_ctor: $ => seq('⟨', sep0($._term, ','), '⟩'),

    list_lit: $ => seq('[', sep0($._term, ','), ']'),

    /* `[a : b]` or `[a : b : step]` — range/subarray slice. */
    range_lit: $ => seq(
      '[',
      optional(field('start', $._term)),
      ':',
      optional(field('stop', $._term)),
      optional(seq(':', field('step', $._term))),
      ']',
    ),

    /* `#[a, b, c]` — array literal. */
    array_lit: $ => seq('#[', sep0($._term, ','), ']'),

    /* `{ field := value, ... }` (anonymous structure) and the
       `{ src with field := value, ... }` update form. `{}` is empty.
       `{e}` matches the Mathlib singleton-set notation. */
    struct_lit: $ => seq(
      '{',
      optional(choice(
        seq(
          optional(seq(field('source', $._term), 'with')),
          sep1($.struct_field, optional(',')),
        ),
        field('singleton', $._term),
      )),
      '}',
    ),

    /* `{ x : T | predicate }` — set-builder notation. */
    set_builder: $ => seq(
      '{',
      field('binder', $._binder_ident),
      $._type_spec,
      '|',
      field('pred', $._term),
      '}',
    ),

    /* `{ x : T // predicate }` — subtype notation. */
    subtype_lit: $ => seq(
      '{',
      field('binder', $._binder_ident),
      $._type_spec,
      '//',
      field('pred', $._term),
      '}',
    ),
    struct_field: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._term),
    ),

    /* `f x` — left-associative application. The argument can be an
       atom or a lead term (`f fun x => x`, `g do return 1`), which is
       common in monadic code. The fn must stay in `_op_term` to keep
       binary-op states from forking through every lead alternative. */
    app: $ => prec.left(PREC.app, seq(
      field('fn', $._op_term),
      field('arg', choice($._term_atom, $._lead_term)),
    )),

    proj: $ => prec.left(PREC.proj, seq(
      field('term', $._op_term),
      token.immediate('.'),
      field('field', choice($.identifier, $.num_lit)),
    )),

    /* Mathlib-style postfix operators: `Aᵒᵖ` (opposite), `Aᵐᵒᵖ` (mul
       opposite), `x⁻¹` (inverse), `Aᵀ` (transpose). Tree-sitter sees
       these as separate tokens after the term, not as part of the
       identifier (the modifier-letter unicode chars aren't in
       `isIdRest`). */
    postfix_op: $ => prec.left(PREC.proj, seq(
      field('term', $._op_term),
      field('op', choice(
        'ᵒᵖ', 'ᵐᵒᵖ', '⁻¹', 'ᵀ', '⊥', '†',
        'ᶜ', 'ˣ', '✝',
      )),
    )),

    /* `arr[idx]` — array/dict indexing. Distinguished from `f [list]`
       by the immediate `[` (no whitespace between fn and bracket).
       `arr[idx]?` and `arr[idx]!` are option-returning and panicking
       variants. */
    subscript: $ => prec.left(PREC.proj, seq(
      field('term', $._op_term),
      token.immediate('['),
      field('index', $._term),
      ']',
      optional(choice(token.immediate('?'), token.immediate('!'))),
    )),

    /* ----- operators ---------------------------------------------------- */

    unary_op: $ => prec(PREC.prefix, seq(
      field('op', choice('-', '¬', '!', '←', '<-', '#',
        /* Coercion prefixes. */
        '↥', '↑', '↓')),
      field('rhs', $._op_term),
    )),

    binary_op: $ => choice(
      prec.right(PREC.arrow, seq(
        field('lhs', $._op_term),
        field('op', choice(
          '→', '->',
          /* Mathlib homomorphism arrows (without bracket param —
             `→ₗ[R]` parses as `→ₗ` + `[R]` applied to rhs).
             `≃` itself is in the cmp set; only the variants here. */
          '→+', '→*', '→+*', '→ₗ', '→ₐ', '→ₒ',
          '→ₙ+', '→ₙ*', '→ₙ+*', '→ₑ', '→ₑ+', '→ₑ*',
          '≃+', '≃*', '≃+*', '≃ₗ', '≃ₐ', '≃ₒ',
          '→ᵃ', '≃ᵃ',
          '↪', '↠',  /* embedding, surjection */
        )),
        field('rhs', $._term),
      )),
      prec.right(PREC.iff, seq(
        field('lhs', $._op_term),
        field('op', choice('↔', '<->')),
        field('rhs', $._op_term),
      )),
      prec.left(PREC.or, seq(
        field('lhs', $._op_term),
        field('op', choice('∨', '||', '⊔')),
        field('rhs', $._op_term),
      )),
      prec.left(PREC.and, seq(
        field('lhs', $._op_term),
        field('op', choice('∧', '&&', '⊓')),
        field('rhs', $._op_term),
      )),
      prec.left(PREC.cmp, seq(
        field('lhs', $._op_term),
        field('op', choice(
          '=', '==', '≠', '!=',
          '<', '≤', '<=',
          '>', '≥', '>=',
          '∈', '∉', '⊆', '⊂', '⊇', '⊃',
          '≡', '≢', '~', '≃', '≅',
          '∣', '∤',  /* divides, not-divides */
        )),
        field('rhs', $._op_term),
      )),
      prec.right(PREC.append, seq(
        field('lhs', $._op_term),
        field('op', '::'),
        field('rhs', $._op_term),
      )),
      prec.right(PREC.append, seq(
        field('lhs', $._op_term),
        field('op', '++'),
        field('rhs', $._op_term),
      )),
      prec.left(PREC.add, seq(
        field('lhs', $._op_term),
        field('op', choice(
          '+', '-', '∪', '\\',
          /* Mathlib torsor & substitution operators. */
          '-ᵥ', '+ᵥ', '▸',
        )),
        field('rhs', $._op_term),
      )),
      prec.left(PREC.mul, seq(
        field('lhs', $._op_term),
        field('op', choice(
          '*', '/', '%', '∩', '×', '•', '∙',
          /* Tensor and related Mathlib operators (without bracket
             param — `⊗ₜ[R]` parses as `⊗ₜ` + `[R]` consumed by app). */
          '⊗', '⊗ₜ', '⊗ₛ',
        )),
        field('rhs', $._op_term),
      )),
      prec.right(PREC.pow, seq(
        field('lhs', $._op_term),
        field('op', '^'),
        field('rhs', $._op_term),
      )),
      prec.right(PREC.comp, seq(
        field('lhs', $._op_term),
        field('op', '∘'),
        field('rhs', $._op_term),
      )),
      prec.left(PREC.pipe, seq(
        field('lhs', $._op_term),
        field('op', choice('|>', '<|')),
        field('rhs', $._op_term),
      )),
      /* `$` is right-associative function application without parens
         (`f $ g x = f (g x)`). Low precedence. */
      prec.right(PREC.arrow, seq(
        field('lhs', $._op_term),
        field('op', '$'),
        field('rhs', $._op_term),
      )),
      /* Monad/applicative and parser-combinator operators. Grouped
         together at "append" precedence since their actual notation
         precedences vary per definition. */
      prec.left(PREC.append, seq(
        field('lhs', $._op_term),
        field('op', choice(
          '>>', '<<', '>>>', '<<<',
          '>>=', '=<<',
          '<$>', '<*>', '<|>', '<&>', '<&&>', '<||>',
          '&&&', '|||', '^^^',
        )),
        field('rhs', $._op_term),
      )),
    ),

    /* ----- binder-using terms ------------------------------------------- */

    /* `fun arg1 arg2 => body`  or  `fun | pat => body | …` (match
       style). The latter is sugar for `fun x => match x with | … | …`. */
    fun: $ => prec.right(seq(
      choice('fun', 'λ'),
      choice(
        seq(
          $._binders,
          optional($._type_spec),
          choice('=>', '↦'),
          field('body', $._term),
        ),
        repeat1($.match_alt),
      ),
    )),

    forall: $ => prec.right(seq(
      /* `Π` is a deprecated Mathlib synonym for `∀` for product types. */
      choice('∀', 'forall', 'Π'),
      $._binders,
      optional($._type_spec),
      ',',
      field('body', $._term),
    )),

    exists: $ => prec.right(seq(
      choice('∃', 'exists'),
      $._binders,
      optional($._type_spec),
      ',',
      field('body', $._term),
    )),

    /* `let` and `have` accept either the term form `let x := v; body`
       (or `let x := v body` via the block's NEWLINE separator) or the
       do-block statement form `let x := v` with the surrounding block
       supplying the body implicitly. Use `_` for the anonymous name.
       Inline binders are not modeled — write `let f := fun x => …`
       instead. The `←`/`<-` form is monadic bind for do-blocks. */
    let: $ => prec.right(seq(
      'let',
      optional(choice('mut', 'rec')),
      field('name', choice($._binder_ident, $.tuple_binder)),
      optional($._type_spec),
      choice(':=', '←', '<-'),
      field('value', $._term),
      optional(seq(';', field('body', $._term))),
    )),

    have: $ => prec.right(seq(
      'have',
      field('name', $._binder_ident),
      optional($._type_spec),
      ':=',
      field('value', $._term),
      optional(seq(';', field('body', $._term))),
    )),

    show: $ => prec.right(seq(
      'show',
      field('type', $._term),
      choice(
        seq('from', field('value', $._term)),
        $.by,
      ),
    )),

    /* `if h : cond then a else b` — named hypothesis form. */
    if_then_else: $ => prec.right(seq(
      'if',
      optional(seq(field('hyp', $._binder_ident), ':')),
      field('cond', $._term),
      'then',
      field('then', $._term),
      'else',
      field('else', $._term),
    )),

    /*
     * `by` and `do` accept either a single inline term or an
     * indent-delimited block of `;`/newline-separated terms.
     *
     * Tactics and do-elements are deliberately *not* given dedicated
     * rules. Every extra rule pulling on `_term` multiplied the LR
     * state count; an earlier draft with named tactic forms grew
     * parser.c to 10MB. Tooling can still recognize specific tactic
     * vocabulary by inspecting the head identifier of an `app` node.
     *
     * The grammar accepts `let mut`, `←`/`<-` (bind), and `for`/`while`
     * /`return` etc. by virtue of those being valid Lean syntax that
     * the term-tier rules already cover (via `let`, the `for` keyword
     * inside ranges, etc.). Coverage is approximate but far cheaper.
     */
    by: $ => seq('by', $._block_body),
    do_block: $ => seq('do', $._block_body),

    _block_body: $ => choice(
      /* Inline `by tac; tac` and `do x; y` — multiple tactics
         separated by semicolons, all on one line. */
      prec.right(sep1(field('inline', $._term), ';')),
      seq(
        $._indent,
        sep1(field('stmt', choice($.block_assign, $._term)),
             choice(';', $._newline)),
        $._dedent,
      ),
    ),

    /* `x := v` mutation, valid only inside a do-block. */
    block_assign: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._term),
    ),

    match: $ => prec.right(seq(
      'match',
      sep1(field('scrutinee', $._term), ','),
      'with',
      repeat1($.match_alt),
    )),
    match_alt: $ => seq(
      '|',
      sep1(field('pattern', $._term), ','),
      '=>',
      field('body', $._term),
    ),

    /* ===== lexicals (carried from stage 1) =============================== */

    num_lit: _ => token(choice(
      /0[xX][0-9a-fA-F](_?[0-9a-fA-F])*/,
      /0[oO][0-7](_?[0-7])*/,
      /0[bB][01](_?[01])*/,
      /[0-9](_?[0-9])*/,
    )),

    scientific_lit: _ => token(choice(
      /[0-9](_?[0-9])*\.[0-9]?(_?[0-9])*([eE][+-]?[0-9](_?[0-9])*)?/,
      /[0-9](_?[0-9])*[eE][+-]?[0-9](_?[0-9])*/,
    )),

    char_lit: $ => seq(
      '\'',
      choice($.escape_sequence, /[^'\\\n]/),
      '\'',
    ),

    str_lit: $ => seq(
      '"',
      repeat(choice(
        $.escape_sequence,
        token.immediate(prec(1, /[^"\\]+/)),
      )),
      '"',
    ),

    escape_sequence: _ => token.immediate(seq('\\', choice(
      /[\\"'rnt0]/,
      /x[0-9a-fA-F]{2}/,
      /u[0-9a-fA-F]{4}/,
      /u\{[0-9a-fA-F]+\}/,
    ))),

    interpolated_str: $ => seq(
      $._interp_open,
      repeat(choice(
        $.escape_sequence,
        $.interpolation,
        token.immediate(prec(1, /[^"\\\{]+/)),
      )),
      '"',
    ),
    _interp_open: _ => choice('s!"', 'm!"'),
    interpolation: $ => seq(
      token.immediate('{'),
      $._term,
      '}',
    ),

    /* `Foo  — quote a name. ``Foo  — quote and resolve against the
       current scope (`SyntaxNodeKind.full`). Both forms are common
       in Lean source. */
    name_lit: $ => seq(choice('`', '``'), field('name', $.identifier)),

    /* `(term)  or  `(category| term)  — syntax quotation. The
       category-bar is `prec.dynamic(1, ...)` so tree-sitter prefers
       it over treating `name |` as a stray pipe. */
    quotation: $ => seq(
      '`',
      token.immediate('('),
      optional(prec.dynamic(1, seq(field('category', $.identifier), '|'))),
      $._term,
      ')',
    ),

    line_comment: _ => token(seq('--', /[^\n]*/)),

    /* Identifier is split into two paths:
     *   `_plain_ident` — internal regex for the ASCII single-component
     *     case. This is the `word` token, so tree-sitter performs
     *     keyword extraction against grammar literals automatically.
     *   `_scanned_ident` — external token emitted by the scanner only
     *     when the identifier needs richer handling: dotted parts,
     *     `«quoted»` escapes, or non-ASCII characters.
     * The scanner returns false (rewind to start) for the plain case,
     * letting internal lexing handle word/keyword arbitration. */
    identifier: $ => choice($._plain_ident, $._scanned_ident),
    _plain_ident: _ => /[a-zA-Z_][a-zA-Z_0-9'!?]*/,
  },
});
