import { sepBy1Indent } from './helpers.js';

const tactic = ($, rule, name) => alias(rule, $[`tactic.${name}`])

/* `sepBy1IndentSemicolon(p)` parses a (nonempty) sequence of `p` optionally followed by `;`,
similar to `many1Indent(p ";"?)`, except that if two occurrences of `p` occur on the same line,
the `;` is mandatory. This is used by tactic parsing, so that
```
example := by
  skip
  skip
```
is legal, but `by skip skip` is not - it must be written as `by skip; skip`. */
const sepBy1IndentSemicolon = ($, /** @type {RuleOrLiteral} */ rule) =>
  sepBy1Indent($, rule, ';', true);

export default {
  by: $ => seq('by', $._tacticSeqIndentGt),

  _tacticSeqIndentGt: $ => seq($._newline, $._tacticSeq1Indented),
  _tacticSeq1Indented: $ => sepBy1IndentSemicolon($, $._tactic),

  _tactic: $ => prec('tactic', choice(
    tactic($, seq('exact', field('term', $._term)), 'exact'),
    tactic($, 'rfl', 'rfl'),
    tactic($, seq('have', $._optDeclSig, field('term', $._declValSimple)), 'have'),
  )),
}
