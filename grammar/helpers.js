/* One or more `rule`s, separated via the separator. */
export function sep1(
  /** @type {RuleOrLiteral} */ rule,
  /** @type {RuleOrLiteral} */ separator) {
  return seq(rule, repeat(seq(separator, rule)))
}

export function sepBy1Indent(
  $,
  /** @type {RuleOrLiteral} */ parser,
  /** @type {RuleOrLiteral} */ separator,
  /** @type {boolean} */ allowTrailingSep = false,
) {
  // FIXME: allowTrailingSep
  return seq(
    $._indent,
    sep1(parser, choice($._newline, separator)),
    $._dedent,
  );
}

/* Zero or more `rule`s, separated via the separator. */
export const sep0  = (
  /** @type {RuleOrLiteral} */ rule,
  /** @type {RuleOrLiteral} */ separator
) => optional(sep1(rule, separator));

/* At least one of the given choices in sequence.

   Used to work around possible empty rules by wrapping this rule in `optional`
   afterwards */
export function min1(
  /** @type {RuleOrLiteral} */ one,
  /** @type {RuleOrLiteral} */ two) {
  return choice(seq(one, optional(two)), seq(optional(one), two))
}
