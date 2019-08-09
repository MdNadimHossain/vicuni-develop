<?php

/**
 * @file
 * Feeds Tamper process definitions.
 *
 * This tamper process will take a courselevel value and combined with aqf
 * value will set the course level.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_unit_level_form',
  'callback' => 'vu_imports_unit_level_callback',
  'name'     => 'Maps unit level based on course level and aqf fields.',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * Form to show in tamper page.
 */
function vu_imports_unit_level_form($importer, $element_key, $settings) {
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
 * Identifies course level for field_unit_lev.
 */
function vu_imports_unit_level_callback($source, $item_key, $element_key, &$field, $settings) {
  if (!empty($source->current_item['courselevel'])) {
    $course_level_raw = $source->current_item['courselevel'];
  }
  elseif (!empty($source->current_item['sector'])) {
    $course_level_raw = strtolower($source->current_item['sector']);
  }
  else {
    $field = '';
    return;
  }

  $course_level_raw = vumain_courses_normalise_course_level($course_level_raw);
  $aqf = !empty($source->current_item['aqftype']) ? $source->current_item['aqftype'] : '';

  // The course level is determined using the value from the XML AND the
  // Australian Qualification Type (AQF) value (e.g. bachelor, diploma...etc).
  // if AQF is not set then the course is a short course.
  $course_level = vumain_courses_get_unit_levels($course_level_raw, $aqf);
  $field = $course_level;
}
