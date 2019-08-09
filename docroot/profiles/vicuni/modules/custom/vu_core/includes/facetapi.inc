<?php

/**
 * @file
 * VU Specific facetapi related functions.
 */

/**
 * Implements hook_block_view_alter().
 */
function facetapi_vu_core_block_view_alter(&$data, $block) {
  if ($block->module == 'facetapi') {
    $block_title = $data['content']['#title'];
    $url_query = drupal_get_query_parameters();

    $query_type = !empty($url_query['type']) ? drupal_strtolower($url_query['type']) : '';
    $courses_query_types = ['course', 'midyear'];

    if (empty($query_type) || in_array($query_type, $courses_query_types)) {
      // Hide the location facet that isn't needed for each search type.
      if (isset($url_query['iam']) && $url_query['iam'] === VU_COURSE_SEARCH_NON_RESIDENT && $block_title == 'Locations') {
        unset($data['content']);
      }
      elseif (isset($url_query['iam']) && $url_query['iam'] === VU_COURSE_SEARCH_RESIDENT && $block_title == 'Cricos code') {
        unset($data['content']);
      }
      elseif (!isset($url_query['iam']) && $block_title == 'Cricos code') {
        // Hide the CRICOS field if ?iam isn't set. Default to domestic search.
        unset($data['content']);
      }
    }
    if (isset($query_type) && $query_type === 'unit' && $block_title == 'Cricos code') {
      // Unit search doesn't have non-resident option so hide CRICOS code block.
      unset($data['content']);
    }
  }
}
