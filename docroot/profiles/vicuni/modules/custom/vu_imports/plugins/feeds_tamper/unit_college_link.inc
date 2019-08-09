<?php

/**
 * @file
 * Feeds Tamper process definitions.
 *
 * This tamper process will take a course name and return the relevant course
 * URL.
 *
 * This allows mapping the college listed in the course xml so that the course
 * has the relevant link.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_unit_college_link_form',
  'callback' => 'vu_imports_unit_college_link_callback',
  'name'     => 'Return the link for a given college name',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_unit_college_link_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_unit_college_link_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Return the link for a given college name.
 *
 * @param string $field
 *   The string value to search for.
 */
function vu_imports_unit_college_link_callback($source, $item_key, $element_key, &$field, $settings) {
  // Get the college name.
  $college_name = $source->current_item['college'];
  // Get a list of college links.
  $college_links = _vumain_get_college_links();

  // If the college name is in the link array.
  if (array_key_exists($college_name, $college_links)) {
    // Update the field value to the relevant link.
    $field = $college_links[$college_name];
  }
  else {
    $field = '';
  }
}
