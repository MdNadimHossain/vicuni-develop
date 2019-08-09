<?php

/**
 * @file
 * Feeds Tamper process definitions.
 *
 * This tamper process will clean the course title.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_clean_course_title',
  'callback' => 'vu_imports_clean_course_title_callback',
  'name'     => 'Clean course title',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_clean_course_title($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_clean_course_title_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Clean the course title.
 */
function vu_imports_clean_course_title_callback($source, $item_key, $element_key, &$field, $settings) {
  $field = _vumain_courses_title_order($source->current_item['course_title']);
}
