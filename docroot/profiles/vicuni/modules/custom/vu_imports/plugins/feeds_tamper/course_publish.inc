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
  'form'     => 'vu_imports_course_publish_form',
  'callback' => 'vu_imports_course_publish_callback',
  'name'     => 'Set published status of imported course',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_course_publish_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_course_publish_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Feeds tamper plugin callback.
 */
function vu_imports_course_publish_callback($source, $item_key, $element_key, &$field, $settings) {
  // Unpublished by default.
  $field = NODE_NOT_PUBLISHED;

  // Check if there's an existing course that is published.
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'courses')
    ->fieldCondition('field_unit_code', 'value', $source->current_item['coursecode'])
    ->propertyCondition('status', 1)
    ->execute();
  if (isset($result['node']) && !empty($result['node'])) {
    // Compensate for missing <continuingstudent> element for Non Award courses.
    if (!isset($source->current_item['continuingstudent'])) {
      $source->current_item['continuingstudent'] = 'N';
    }
    // Check if published criteria is still valid.
    if ((is_null($source->current_item['continuingstudent']) && is_null($source->current_item['courseoffered']) && is_null($source->current_item['handbookinclude'])) || ($source->current_item['continuingstudent'] == 'N' && $source->current_item['courseoffered'] == 'Y' && $source->current_item['handbookinclude'] == 'Y')) {
      $field = NODE_PUBLISHED;
    }
    // If this is the international feed, return the existing node status.
    if (vu_imports_is_international_feed_import($source)) {
      $field = $result['node']->status;
    }
  }
}
