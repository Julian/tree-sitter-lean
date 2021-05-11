const attr = require('./grammar/attr.js')
const command = require('./grammar/command.js')
const do_ = require('./grammar/do.js')
const syntax = require('./grammar/syntax.js')
const tactic = require('./grammar/tactic.js')
const term = require('./grammar/term.js')
const {sep0, sep1} = require('./grammar/util.js')

module.exports = grammar({
  name: 'lean',

  extras: $ => [
    $.comment,
    /\s/,
  ],

  externals: $ => [
    $._newline,
    $._indent,
    $._dedent,
  ],

  conflicts: $ => [
    [$._argument, $.binary_expression],
    [$._basic_fun, $.binary_expression],
    [$._binder_ident, $._decl_id],
    [$._binder_ident, $._struct_explicit_binder],
    [$._binder_ident],
    [$._decl_sig, $.implicit_binder],
    [$._decl_sig],
    [$._dollar, $._argument],
    [$._dollar, $._basic_fun],
    [$._dollar, $.binary_expression],
    [$._dollar, $.exists],
    [$._dollar, $.explicit],
    [$._dollar, $.if_then_else],
    [$._dollar, $.match_alt],
    [$._dollar, $.projection],
    [$._dollar, $.subarray],
    [$._dollar, $.unary_expression],
    [$._dollar],
    [$._fun_simple_binder],
    [$._let_equations_decl],
    [$._let_id_decl, $._dollar],
    [$._let_id_decl, $.projection],
    [$._let_id_decl, $.subarray],
    [$._let_id_lhs],
    [$._let_id_lhs, $._applyable_term],
    [$._match_discr, $._applyable_term],
    [$._binder_ident, $._applyable_term],
    [$._struct_instance_binder, $._applyable_term],
    [$.instance_binder, $._applyable_term],
    [$._let_pattern_decl, $._dollar],
    [$._let_pattern_decl, $.projection],
    [$._let_pattern_decl, $.subarray],
    [$._opt_decl_sig],
    [$._simple_binder],
    [$._struct_simple_binder],
    [$._where_decls],
    [$.do_try],
    [$._match_alts],
    [$.apply, $.binary_expression],
    [$.apply, $.forall, $.binary_expression],
    [$.apply, $.forall],
    [$.apply, $.unary_expression],
    [$.binary_expression],
    [$.explicit, $.binary_expression],
    [$.fun],
    [$.identifier],
    [$.if_then_else, $.binary_expression],
    [$.instance_binder, $._struct_instance_binder],
    [$.instance_binder, $.list],
    [$.match_alt, $.binary_expression],
    [$.pipe_projection],
    [$.projection, $._argument],
    [$.projection, $._basic_fun],
    [$.projection, $.exists],
    [$.projection, $.explicit],
    [$.projection, $.if_then_else],
    [$.projection, $.match_alt],
    [$.projection, $.unary_expression],
    [$.projection, $.user_tactic],
    [$._tactic_seq],
    [$.quoted_tactic, $.user_tactic],
    [$._dollar, $.user_tactic],
    [$.apply_tactic, $.projection],
    [$.apply_tactic, $._dollar],
    [$.apply_tactic, $.subarray],
    [$.subarray, $._argument],
    [$.term, $.projection],
    [$.term, $._dollar],
    [$.term, $.subarray],
    [$.rewrite, $.projection],
    [$.rewrite, $._dollar],
    [$.rewrite, $.subarray],
    [$.subarray, $._basic_fun],
    [$.subarray, $.exists],
    [$.subarray, $.explicit],
    [$.subarray, $.if_then_else],
    [$.subarray, $.match_alt],
    [$.subarray, $.unary_expression],
    [$.subarray, $.user_tactic],
  ],

  word: $ => $._identifier,

  rules: {
    // src/Lean/Parser/Module.lean
    module: $ => seq(
      optional($.prelude),
      repeat($.import),
      repeat($._command),
    ),
    prelude: $ => 'prelude',
    import: $ => seq('import', field('module', $.identifier)),

    conditional_when: $ => prec.right(seq(
      'if',
      $._term,
      'then',
      $._do_seq,
    )),

    assign: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._term),
    ),

    let_mut: $ => seq(
      'let', 'mut',
      // $.binders,
      choice($._left_arrow, ':='),
      field('value', $._term),
    ),

    let_bind: $ => seq(
      'let',
      field('name', $.identifier),
      $._left_arrow,
      field('value', $._term),
    ),

    _left_arrow: $ => choice('<-', '←'),

    escape_sequence: $ => token(
      seq(
        '\\', choice(
          /u[a-fA-F\d]{4}/,
          /x[a-fA-F\d]{2}/,
          /['"rnt\\]/,
        ),
      ),
    ),

    comment: $ => token(choice(
      seq('--', /.*/),
      seq(
        '/-',
        repeat(choice(
          /[^-]/,
          /-[^/]/
        )),
        '-/',
      ),
    )),

    _identifier: $ => /[_a-zA-ZͰ-ϿĀ-ſ\U0001D400-\U0001D7FF][_`'`a-zA-Z0-9Ͱ-ϿĀ-ſ∇!?\u2070-\u209F\U0001D400-\U0001D7FF]*/,
    _escaped_identifier: $ =>  /«[^»]*»/,

    ...attr,
    ...command,
    ...do_,
    ...syntax,
    ...tactic,
    ...term,
  }
});
