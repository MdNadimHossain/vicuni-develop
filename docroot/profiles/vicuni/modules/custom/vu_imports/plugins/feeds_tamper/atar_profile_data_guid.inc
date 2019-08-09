<?php

/**
 * @file
 * Feeds Tamper process definitions.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_atar_profile_data_form',
  'callback' => 'vu_imports_atar_profile_data_callback',
  'name'     => 'Resolve a course code to guid',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_atar_profile_data_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_atar_profile_data_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Create a prefixed GUID.
 *
 * @param string $field
 *   The string value to search for.
 *          array modified by reference into an array of feed GUIDs.
 */
function vu_imports_atar_profile_data_callback($source, $item_key, $element_key, &$field, $settings) {

  if (substr('course-', 0, strlen($field)) !== $field) {
    // Modify $field import by reference.
    $field = 'course-' . $field;
  }

}
