const

min1 = (one, two) => choice(
  seq(one, optional(two)), seq(optional(one), two)
)

module.exports = {
  min1,
}
