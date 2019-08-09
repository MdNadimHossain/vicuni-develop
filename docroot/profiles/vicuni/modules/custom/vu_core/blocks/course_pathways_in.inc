<?php

/**
 * @file
 * Course pathways in block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_pathways_in_info() {
  return [
    'info' => t('Course pathways in'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_pathways_in_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }

  $level = vu_core_extract_single_field_value($node, 'node', 'field_unit_lev');
  $non_award = $level == 'short' ? TRUE : FALSE;
  $undergrad = $level == 'undergrad' ? TRUE : FALSE;

  // Condition for diplomas.
  $aqf = vu_core_extract_single_field_value($node, 'node', 'field_course_aqf');
  $diploma = ($level == 'he_diplomas' && $aqf == 'Diploma') ? TRUE : FALSE;

  // Don't Display block for non award courses.
  if ($non_award || (($undergrad || $diploma) && vu_feature_switches_switch_state('courses-admission-transparency'))) {
    return;
  }

  // Prepare array of arguments for theme function.
  $course_code = vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
  $international = vu_core_extract_single_field_value($node, 'node', 'field_international');
  $international = ($international && vu_courses_is_international_course_url());
  $variables = [];
  module_load_include('inc', 'vu_core', 'theme/vu_core.theme');
  $pathways = vu_core_pathways_in($node, $international);

  $variables['course_code'] = $course_code;
  $variables['course_name'] = $node->title;
  $variables['college'] = vu_core_extract_single_field_value($node, 'node', 'field_college', 'title');
  $variables['is_ve'] = $level == 'tafe' ? TRUE : FALSE;
  $variables['international'] = $international;

  // Allows for optionally excluding accordion items.
  $content = [];

  $variables['type'] = 'Internal to VU';
  $variables['introText'] = ($variables['type'] === 'Internal to VU') ? TRUE : FALSE;
  $variables['pathways'] = $pathways['Internal to VU'];
  $content[] = [
    '#theme' => 'vu_accordion',
    '#name' => 'accordion-pathways-from-vu',
    '#title' => t('Pathways from VU courses'),
    '#content' => theme('pathways_to_this_course', $variables),
  ];

  // Unsetting the variable so that introtext only
  // shows for Internal to VU when the switch off.
  $variables['introText'] = FALSE;

  if (count($pathways['External to VU'])) {
    $variables['type'] = 'External to VU';
    $variables['pathways'] = $pathways['External to VU'];
    $content[] = [
      '#theme' => 'vu_accordion',
      '#name' => 'accordion-pathways-from-external',
      '#title' => t('Pathways from other institutions'),
      '#content' => theme('pathways_to_this_course', $variables),
    ];
  }

  if (count($pathways['Offshore'])) {
    $variables['type'] = 'Offshore';
    $variables['pathways'] = $pathways['Offshore'];
    $content[] = [
      '#theme' => 'vu_accordion',
      '#name' => 'accordion-pathways-from-international',
      '#title' => t('Pathways from overseas institutions'),
      '#content' => theme('pathways_to_this_course', $variables),
    ];
  }

  $content[] = [
    '#theme' => 'vu_accordion',
    '#name' => 'accordion-pathways-credit',
    '#title' => $variables['is_ve'] ? t('Recognition of Prior Learning (RPL)') : t('Credit for skills and past study'),
    '#content' => theme('pathways_credit', $variables),
  ];

  return [
    'subject' => NULL,
    'content' => $content,
  ];
}
