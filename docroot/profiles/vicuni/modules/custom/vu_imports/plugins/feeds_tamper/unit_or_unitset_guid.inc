<?php

/**
 * @file
 * Feeds Tamper process definitions.
 *
 * This tamper process will take a unit or unit set ID and add the
 * appropriate prefix to match against the feed item GUID for the corresponding
 * imported unit or unit set in the feed_items table.
 *
 * This allows mapping the units or unit sets listed in a course in the course
 * xml to entityreference fields, pointing at the previously imported unit or
 * unit set entities.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_unit_or_unitset_guid_form',
  'callback' => 'vu_imports_unit_or_unitset_guid_callback',
  'name'     => 'Resolve a unit or unit set ID to GUID for entityreference',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_unit_or_unitset_guid_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_unit_or_unitset_guid_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Create a prefixed GUID to differentiate Units and Unit sets.
 *
 * Process the unit / unit set ID transformation into a type prefixed GUID
 * for use in entity reference by GUID string look up feed tamper.
 *
 * @param string $field
 *   The string value to search for. Could also be an
 *          array modified by reference into an array of feed GUIDs.
 */
function vu_imports_unit_or_unitset_guid_callback($source, $item_key, $element_key, &$field, $settings) {
  $guids = [];

  foreach ($source->current_item['isunitset'] as $key => $value) {
    $prefix = ($value === 'Y' ? 'unitset-' : 'unit-');
    $guids[$key] = $prefix . $source->current_item['unitid'][$key];
  }

  // Modify $field import by reference.
  $field = $guids;
}
