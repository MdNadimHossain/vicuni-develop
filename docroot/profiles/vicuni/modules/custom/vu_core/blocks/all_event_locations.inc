<?php

/**
 * @file
 * All event locations.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_all_event_locations_info() {
  return [
    'info' => t('All event locations'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_all_event_locations_view() {
  $node = menu_get_object();
  if ($node->type !== 'events') {
    return FALSE;
  }
  $rhs_component_id = vu_core_extract_single_field_value($node, 'node', 'field_rhs_components', 'value');
  if (!empty($rhs_component_id)) {
    $rhs_component = paragraphs_item_load($rhs_component_id);
    $map_component_row = $rhs_component->field_map_component_row[LANGUAGE_NONE];
    foreach ($map_component_row as $location) {
      $location_arr = paragraphs_item_load($location['value']);
      // Load campus names.
      $campus_nid = vu_core_extract_single_field_value($location_arr, 'paragraphs_item', 'field_campus', 'target_id');
      if (!empty($campus_nid)) {
        $campus = node_load($campus_nid);
        $custom_location[] = $campus->title;
      }
      // Load custom locations.
      $custom_loc = vu_core_extract_single_field_value($location_arr, 'paragraphs_item', 'field_place_name', 'value');
      if (!empty($custom_loc)) {
        $custom_location[] = $custom_loc;
      }
    }
  }
  if (count($custom_location) > 5) {
    $custom_location = '';
  }
  else {
    $custom_location = implode(', ', $custom_location);
  }
  $variables = [
    'multiple_locations' => $custom_location,
  ];

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => theme('vu_all_event_locations', $variables),
    ],
  ];

}
