<?php

/**
 * @file
 * Feeds Tamper process definitions.
 *
 * Some <location> xml nodes have special values that cannot be mapped
 * to the entity reference field. This tamper looks for those values
 * and stores them in a new field for later use in a theme function.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_unit_locations_special_form',
  'callback' => 'vu_imports_unit_locations_special_callback',
  'name'     => 'Handle special location xml node values',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_unit_locations_special_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_unit_locations_special_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Handle special location xml node values.
 *
 * @param string $field
 *   The string value to search for.
 */
function vu_imports_unit_locations_special_callback($source, $item_key, $element_key, &$field, $settings) {
  $values = $source->current_item['locations'];
  $haystack = array_flip($values);

  // Build a new array of field values.
  $found = [];
  if (isset($haystack['VU Sydney'])) {
    $found[] = 'VU Sydney';
  }
  if (isset($haystack['Industry'])) {
    $found[] = 'Industry';
  }
  if (isset($haystack['Other'])) {
    $found[] = 'Other';
  }

  // Return the subset of special locations found in the array.
  $field = $found;
}
