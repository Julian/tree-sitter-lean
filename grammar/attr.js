export default {
  _attribute: $ => choice(
    $._simpleAttribute,
    $._externAttribute,
  ),

  _simpleAttribute: $ => field(
    'name', seq($.identifier, optional($.identifier)),
  ),

  _externEntry: $ => seq(
    optional($.identifier),
    optional('inline'),
    field('extern', $.string),
  ),
  _externAttribute: $ => seq(
    'extern',
    optional($.number),
    repeat($._externEntry),
  )
}
