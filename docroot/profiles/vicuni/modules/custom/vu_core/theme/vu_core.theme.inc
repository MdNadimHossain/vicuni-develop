<?php

/**
 * @file
 * Theme functions.
 */

/**
 * Template preprocess: vu_core_search_tabs.
 */
function vu_core_preprocess_vu_course_search_tabs(&$variables) {
  $params = drupal_get_query_parameters();
  $path = current_path();

  // Remove page for tab switching.
  if (isset($params['page'])) {
    unset($params['page']);
  }

  // Set the default values for (non) resident queries and URLs.
  $non_resident_query = $resident_query = $params;

  // Update the non-resident query.
  $non_resident_query['iam'] = 'non-resident';
  // Update the resident query.
  $resident_query['iam'] = 'resident';

  // Build up the URL options.
  $url_options = [
    'attributes' => [
      'class' => [
        'search-navigation',
      ],
    ],
    'html' => TRUE,
  ];

  // Build up the non-resident URL.
  $url_options['query'] = $non_resident_query;
  // Determine which search page is being viewed.
  $search_type = isset($url_options['query']['type']) ? $url_options['query']['type'] : '';

  // Non-resident search shouldn't have Mid-year filter.
  if (drupal_strtolower($search_type) == drupal_strtolower(VU_MIDYEAR_INTAKE_SEARCH_TYPE)) {
    unset($url_options['query']['type']);
  }

  // Remove location facet if it is set for Course Search.
  if (empty($search_type) || drupal_strtolower($search_type) != "unit") {
    $facet_query = !empty($url_options['query']['f']) ? $url_options['query']['f'] : [];
    foreach ($facet_query as $key => $facet) {
      if (strpos($facet, "field_locations") !== FALSE) {
        $retained_facet = str_replace("field_locations", "field_cricos_code", $facet);
        $url_options['query']['f'][$key] = $retained_facet;
      }
    }
  }
  $non_resident_url = l(t('Results for <strong>non-residents</strong>'), $path, $url_options);

  // Build up the resident URL.
  $url_options['query'] = $resident_query;
  // Determine which search page is being viewed.
  $search_type = $url_options['query']['type'];
  // Remove CRICOS facet if it is set for Course Search.
  if (!isset($search_type) || drupal_strtolower($search_type) != "unit") {
    $facet_query = !empty($url_options['query']['f']) ? $url_options['query']['f'] : [];
    foreach ($facet_query as $key => $facet) {
      if (strpos($facet, "field_cricos_code") !== FALSE) {
        $retained_facet = str_replace("field_cricos_code", "field_locations", $facet);
        $url_options['query']['f'][$key] = $retained_facet;
      }
    }
  }
  $resident_url = l(t('Results for <strong>residents</strong>'), $path, $url_options);

  // Add the variables to the template.
  $variables['non_resident_url'] = $non_resident_url;
  $variables['resident_url'] = $resident_url;
  $variables['active_tab'] = isset($params['iam']) && $params['iam'] == 'non-resident' ? 'non_resident_url' : 'resident_url';
}

/**
 * Get pathways for course.
 *
 * @param object $node
 *   Course Node.
 *
 * @return array
 *   array of pathways
 */
function vu_core_course_pathways($node) {
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['pathways'] = &drupal_static(__FUNCTION__, []);
  }
  $pathways = &$drupal_static_fast['pathways'];
  $nid = $node->nid;
  $vid = $node->vid;

  if (isset($pathways[$nid])) {
    return $pathways[$nid];
  }

  $query = db_select('field_data_field_pathways_cams', 'p');
  $query->leftJoin('field_data_field_unit_code', 'c', 'p.field_pathways_cams_type = :type AND p.field_pathways_cams_code = c.field_unit_code_value', [':type' => 'Internal to VU']);
  $query->leftJoin('node', 'n', 'c.entity_id = n.nid');
  $query->leftJoin('field_data_field_course_aqf', 'a', 'a.revision_id = n.vid');
  $query->leftJoin('field_data_field_unit_lev', 'l', 'l.revision_id = n.vid');
  $or = db_or();
  $or->condition('n.status', NODE_PUBLISHED);
  $or->condition('n.status', NULL);

  $query->fields('p', [
    'field_pathways_cams_code',
    'field_pathways_cams_credit_points',
    'field_pathways_cams_type',
    'field_pathways_cams_title',
    'field_pathways_cams_institution',
    'field_pathways_cams_country',
    'field_pathways_cams_guaranteed_entry',
  ])->fields('n', ['nid', 'title'])
    ->fields('c', ['field_unit_code_value'])
    ->fields('a', ['field_course_aqf_value'])
    ->fields('l', ['field_unit_lev_value'])
    ->condition('p.entity_id', $nid)
    ->condition('p.revision_id', $vid)
    ->condition($or);

  $results = $query->execute();

  if (!isset($pathways[$nid])) {
    $pathways[$nid] = [];
  }

  foreach ($results as $result) {
    $pathways[$nid][] = [
      'code' => !empty($result->field_unit_code_value) ? $result->field_unit_code_value : $result->field_pathways_cams_code,
      'name' => !empty($result->title) ? $result->title : $result->field_pathways_cams_title,
      'credit_units' => $result->field_pathways_cams_credit_points,
      'type' => $result->field_pathways_cams_type,
      'institution' => $result->field_pathways_cams_institution,
      'country' => $result->field_pathways_cams_country,
      'guaranteed_entry' => $result->field_pathways_cams_guaranteed_entry,
      'aqf' => $result->field_course_aqf_value,
      'level' => $result->field_unit_lev_value,
      'nid' => $result->nid,
    ];
  }
  usort($pathways[$nid], function ($a, $b) {
    return $a['name'] <=> $b['name'];
  });
  return $pathways[$nid];
}

/**
 * Get a comparable value for a course AQF.
 */
function vu_core_course_aqf_value_to_level($aqf) {
  switch ($aqf) {
    // Null is short course.
    case NULL:
    case '':
    case 'Statement of Attainment':
      return 0;

    case 'Certificate I':
      return 1;

    case 'Certificate II':
      return 2;

    case 'Certificate III':
      return 3;

    case 'Certificate IV':
      return 4;

    case 'Diploma':
      return 5;

    case 'Advanced Diploma':
    case 'Associate Degree':
      return 6;

    case 'Bachelor Degree':
      return 7;

    case 'Bachelor Honours Degree (embedded)':
    case 'Bachelor Honours Degree (stand alone)':
    case 'Graduate Certificate':
    case 'Graduate Diploma':
      return 8;

    case 'Bachelor Degree/Masters (Coursework) Degree':
    case 'Masters (Coursework) Degree':
    case 'Masters (Research) Degree':
      return 9;

    case 'Doctoral Degree':
      return 10;
  }
}

/**
 * Compare 2 AQF levels.
 */
function vu_core_course_aqf_compare($aqf1, $aqf2) {
  return vu_core_course_aqf_value_to_level($aqf1) <=> vu_core_course_aqf_value_to_level($aqf2);
}

/**
 * Get pathways into the course.
 */
function vu_core_pathways_in($node, $international = FALSE) {
  $pathways = vu_core_course_pathways($node);
  $aqf = vu_core_extract_single_field_value($node, 'node', 'field_course_aqf');
  $pathways_in = [
    'Internal to VU' => [],
    'External to VU' => [],
    'Offshore' => [],
  ];
  foreach ($pathways as $pathway) {
    if ($pathway['type'] !== 'Internal to VU') {
      if ($pathway['type'] === 'Offshore' && !$international) {
        continue;
      }
      // We know it's a pathway in.
      $pathways_in[$pathway['type']][] = $pathway;
      continue;
    }
    // Remove pathways to higher level courses (out).
    if (vu_core_course_aqf_compare($aqf, $pathway['aqf']) < 0) {
      continue;
    }
    $pathways_in[$pathway['type']][] = $pathway;
  }
  return $pathways_in;
}

/**
 * Get pathways out of the course.
 */
function vu_core_pathways_out($node) {
  $pathways = vu_core_course_pathways($node);
  $aqf = vu_core_extract_single_field_value($node, 'node', 'field_course_aqf');
  foreach ($pathways as $index => $pathway) {
    // Out pathways must be internal.
    if ($pathway['type'] !== 'Internal to VU') {
      unset($pathways[$index]);
      continue;
    }
    // Remove pathways to lower level courses (in).
    if (vu_core_course_aqf_compare($aqf, $pathway['aqf']) > 0) {
      unset($pathways[$index]);
      continue;
    }
  }
  return $pathways;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function theme_vu_core_study_level_info_box(&$variables) {
  $labels = vumain_courses_return_unit_level_labels();
  $level = $variables['level'];
  $output = '';
  switch ($level) {
    case $labels[VUMAIN_COURSELEVEL_HE_DIPLOMAS]:
      $output = theme('vu_core_he_diploma_info_box');
      break;

    case $labels[VUMAIN_COURSELEVEL_POSTGRADUATE_RESEARCH]:
      $output = theme('vu_core_postgrad_research_info_box');
      break;
  }
  return $output;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vu_core_preprocess_vu_core_postgrad_research_info_box(&$variables) {
  $image_attributes = [
    'path' => drupal_get_path('theme', 'vu') . '/images/browse/postgraduate.jpg',
    'alt' => 'Postgraduate Research',
  ];
  $variables['image'] = theme('image', $image_attributes);
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vu_core_preprocess_vu_core_he_diploma_info_box(&$variables) {
  $image_attributes = [
    'path' => drupal_get_path('theme', 'vu') . '/images/browse/he-diplomas.jpg',
    'alt' => 'Higher education diplomas',
  ];
  $variables['image'] = theme('image', $image_attributes);
}
