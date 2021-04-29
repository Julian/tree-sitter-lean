const

min1 = (one, two) => choice(seq(one, optional(two)), seq(optional(one), two))
sep0 = (rule, separator) => optional(sep1(rule, separator))
sep1 = (rule, separator) => seq(rule, repeat(seq(separator, rule)))
sep2 = (rule, separator) => seq(rule, repeat1(seq(separator, rule)))
sep1_ = (rule, separator) => seq(sep1(rule, separator), optional(separator))

module.exports = {
  min1,
  sep0,
  sep1,
  sep2,
  sep1_,
}
