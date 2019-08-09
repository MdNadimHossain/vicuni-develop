<?php

/**
 * @file
 * An additional tamper process for processing units and unit sets.
 *
 * This tamper process will take a unit or unit set ID and add the
 * appropriate prefix to match against the feed item GUID for the corresponding
 * imported unit or unit set in the feed_items table.
 *
 * This allows mapping the units or unit sets listed in a course in the course
 *   xml to entityreference fields, pointing at the previously imported unit or
 *   unit set entities.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_unitset_publish_test_form',
  'callback' => '_vu_imports_unitset_publish_test_callback',
  'name'     => 'Set published status of imported unitset',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_unitset_publish_test_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See _vu_imports_unitset_publish_test_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Transform the GUID from the units / unitset xml.
 *
 * Process the unit / unit set ID transformation into a type prefixed GUID for
 * use in entity reference by GUID string look up feed tamper.
 *
 * @param string &$field
 *   The string value to search for. Could also be an array.
 *   Modified by reference into an array of feed GUIDs.
 */
function _vu_imports_unitset_publish_test_callback($source, $item_key, $element_key, &$field, $settings) {
  $field = FALSE;
  if ($source->current_item['handbookinclude'] === 'Y' && $source->current_item['continuingstudent'] === 'N') {
    $field = TRUE;
  }
}
