<?php
/**
 * @file
 * vpoly_core.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function vpoly_core_eck_bundle_info() {
  $items = array(
    'course_information_session_links_tafe_info_session_link' => array(
      'machine_name' => 'course_information_session_links_tafe_info_session_link',
      'entity_type' => 'course_information_session_links',
      'name' => 'tafe_info_session_link',
      'label' => 'TAFE information session link',
      'config' => array(
        'managed_properties' => array(
          'title' => 0,
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function vpoly_core_eck_entity_type_info() {
  $items = array(
    'course_information_session_links' => array(
      'name' => 'course_information_session_links',
      'label' => 'Course information session links ',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}
