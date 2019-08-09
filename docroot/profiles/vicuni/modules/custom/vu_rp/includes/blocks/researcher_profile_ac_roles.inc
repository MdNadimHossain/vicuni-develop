<?php

/**
 * @file
 * Researcher key details.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_ac_roles_info() {
  return [
    'info' => t('Researcher academic roles'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_ac_roles_view() {
  $render = [];
  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  // Check if this researcher has any academic roles.
  $field_rp_any_academic = vu_rp_extract_single_field_value('node', $node, 'field_rp_has_academic_roles', 'value');
  if (!$field_rp_any_academic) {
    return $render;
  }

  $pids = $node->field_rp_academic_roles[LANGUAGE_NONE];
  if (!empty($pids)) {
    foreach ($pids as $pid) {
      $paragraphs_item = entity_load('paragraphs_item', [$pid['value']]);
      $paragraph = reset($paragraphs_item);
      $record = [
        'field_rp_ar_role' => $paragraph->field_rp_ar_role[LANGUAGE_NONE][0]['value'],
        'field_rp_ar_organisation' => $paragraph->field_rp_ar_organisation[LANGUAGE_NONE][0]['value'],
        'field_start' => $paragraph->field_rp_ar_period[LANGUAGE_NONE][0]['value'],
        'field_end' => $paragraph->field_rp_ar_period[LANGUAGE_NONE][0]['value2'],
      ];

      $data[] = $record;
    }
  }

  if ($data) {
    vu_rp_block_researcher_profile_ac_roles_format_items($data);
  }

  $output = theme('vu_rp_block_rp_academic_roles', ['content' => $data]);

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
function vu_rp_block_researcher_profile_ac_roles_format_items(&$data) {
  foreach ($data as &$item) {
    foreach ($item as $field => $value) {
      switch ($field) {
        case 'field_start':
          $value = date('M Y', strtotime($value));
          break;

        case 'field_end':
          $value = date('M Y', strtotime($value));
          $value = $value == date('M Y') ? t('present') : $value;
          break;
      }

      $item[$field] = $value;
    }
  }
}
