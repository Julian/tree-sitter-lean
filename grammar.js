/**
 * @file A tree sitter grammar for the Lean theorem prover.
 * @author Julian Berman <Julian+tree-sitter-lean@GrayVines.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

import attr from './grammar/attr.js';
import command from './grammar/command.js';
import term from './grammar/term.js';
import tactic from './grammar/tactic.js';
import mathlib from './grammar/mathlib.js';

export default grammar({
  name: 'lean',

  externals: $ => [
    $._indent,
    $._dedent,
    $._newline,
    $.error_sentinel,
  ],

  extras: $ => [
    $.comment,
    /\s/,
  ],

  word: $ => $._identifierComponent,

  precedences: $ => [
    [
      'min',
      'arrow',
      'ite',
      'lead',
      'arg',
      'max',
    ],
    [
      'tactic',
    ],
    [
      'declId',
      'binderIdent',
    ],
  ],

  rules: {
    module: $ => seq(
      // header
      optional($.prelude),
      repeat($.import),

      repeat($._command),
    ),

    prelude: $ => 'prelude',
    import: $ => seq('import', field('module', $.identifier)),

    ...attr,
    ...command,
    ...term,
    ...tactic,

    ...mathlib,

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
  }
});
