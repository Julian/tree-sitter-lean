/**
 * @file A tree sitter grammar for the Lean theorem prover
 * @author Julian Berman <Julian+tree-sitter-lean@GrayVines.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

export default grammar({
  name: 'lean',

  rules: {
    source_file: $ => "hello"
  }
});
