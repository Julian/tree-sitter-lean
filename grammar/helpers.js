/* One or more `rule`s, separated via the separator. */
export function sep1(
  /** @type {RuleOrLiteral} */ rule,
  /** @type {RuleOrLiteral} */ separator) {
    return seq(rule, repeat(seq(separator, rule)));
}
