<?php

/**
 * @file
 * Campus Maps.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_campus_maps_info() {
  return [
    'info' => t('Campus Maps'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_campus_maps_view() {

  $campuses = vu_core_get_campuses();
  $titles = $variables = $d_campuses = [];
  foreach ($campuses as $campus) {
    $class = '';
    $campus_alias = drupal_get_path_alias('node/' . $campus->nid);
    $campus_id = vumain_googlemaps_get_campus_id($campus_alias);
    $d_campuses[$campus_id] = $campus_alias;
    // Set Default campus.
    if ($campus->title == "Footscray Park") {
      $variables['default'] = $campus;
      $variables['campus_name'] = $campus_alias;
      // Add active class for default location.
      $class = 'active';
    }

    $titles[] = l($campus->title, '', ['attributes' => ['data-nid' => $campus->nid, 'class' => [$class]]]);
  }

  $titles_list = theme('item_list', ['items' => $titles]);

  $variables['locations'] = $titles_list;
  $variables['campuses'] = $d_campuses;
  $campus_maps = theme('vu_core_block_campus_maps', $variables);

  return [
    'subject' => t('Campus Maps'),
    'content' => $campus_maps,
  ];
}
