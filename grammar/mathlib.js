export const terms = $ => [
  $.typeStar,
  $['[X]'],
]

export default {
  typeStar: $ => 'Type*',
  "[X]": $ => seq(field('R', $.identifier), token.immediate('[X]')),
}
