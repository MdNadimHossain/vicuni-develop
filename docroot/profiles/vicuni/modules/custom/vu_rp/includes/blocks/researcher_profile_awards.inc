<?php

/**
 * @file
 * Researcher awards.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_awards_info() {
  return [
    'info' => t('Researcher awards'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_awards_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  // Check if this researcher has any awards.
  $field_rp_any_awards = vu_rp_extract_single_field_value('node', $node, 'field_rp_has_awards', 'value');
  if (!$field_rp_any_awards) {
    return $render;
  }

  $fields = [
    'field_rp_a_year' => [],
    'field_rp_a_award_name' => [],
    'field_rp_a_organisation' => [],
    'field_rp_a_organisation_link' => [],
  ];

  $data = vu_rp_get_paragraph_item_values($node, 'field_rp_awards', 'rp_award', $fields);
  if ($data) {
    vu_rp_block_researcher_profile_awards_format_items($data);
  }

  $output = theme('vu_rp_block_rp_awards', ['content' => $data]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}

/**
 * Formats paragraph data.
 */
function vu_rp_block_researcher_profile_awards_format_items(&$data) {
  foreach ($data as &$item) {
    foreach ($item as $field => $value) {
      switch ($field) {
        case 'field_rp_a_year':
          $value = date('Y', strtotime($value));
          break;
      }

      $item[$field] = $value;
    }
  }
}
