<?php

/**
 * @file
 * Unit assessment.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_unit_assessment_info() {
  return [
    'info' => t('Unit assessment'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_unit_assessment_view() {
  $node = menu_get_object();
  $assessment = $assessment_offshore = '';

  $assessment_details = vu_core_extract_single_field_value($node, 'node', 'field_assesment', 'value');
  if (!empty($assessment_details)) {
    $assessment = vumain_unit_format_xml_field($assessment_details);
  }

  $assessment_offshore_details = vu_core_extract_single_field_value($node, 'node', 'field_assessment_offshore', 'value');
  if (!empty($assessment_offshore_details)) {
    $assessment_offshore = vumain_unit_format_xml_field($assessment_offshore_details);
  }

  $show_titles = empty($assessment) || empty($assessment_offshore) ? FALSE : TRUE;

  $variables = [
    'show_titles' => $show_titles,
    'assessment' => $assessment,
    'assessment_offshore' => $assessment_offshore,
  ];

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => theme('vu_unit_assessment', $variables),
    ],
  ];

}
