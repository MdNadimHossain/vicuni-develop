<?php

/**
 * @file
 * Researchers Profile node data retrieval.
 */

/**
 * Get variation first name.
 */
function vu_rp_node_get_variation_first_name($node) {
  $api_name = vu_rp_get_variation_value($node, 'field_rpa_first_name', NULL, FALSE);
  $api_preferred_name = vu_rp_get_variation_value($node, 'field_rpa_first_name', 'field_rpa_preferred_name');
  $name_variation = vu_rp_get_variation_value($node, 'field_rpa_first_name', 'field_rp_first_name', 'field_rp_name_variation');
  $preferred_name_variation = vu_rp_get_variation_value($node, 'field_rpa_preferred_name', 'field_rp_first_name', 'field_rp_name_variation');

  $resolved = $preferred_name_variation ?: ($name_variation ?: ($api_preferred_name ?: $api_name));

  return $resolved;
}

/**
 * Get variation last name.
 */
function vu_rp_node_get_variation_last_name($node) {
  return vu_rp_get_variation_value($node, 'field_rpa_last_name', 'field_rp_last_name', 'field_rp_name_variation');
}

/**
 * Get correct research institute.
 */
function vu_rp_node_get_institute($node) {
  $institute_id = vu_core_extract_single_field_value($node, 'node', 'field_rp_institute_primary', 'target_id');

  if ($institute_id === FALSE) {
    return FALSE;
  }
  elseif ($institute_id === '0') {
    $institute_id = vu_core_extract_single_field_value($node, 'node', 'field_rp_institute_best_align', 'target_id');
  }

  if (empty($institute_id)) {
    return FALSE;
  }

  return taxonomy_term_load($institute_id);
}

/**
 * Get all publications from a node.
 */
function vu_rp_node_get_publications($node) {
  $types = [];

  $wrapper = entity_metadata_wrapper('node', $node);
  if (!isset($wrapper->field_rpa_publications)) {
    return $types;
  }

  $count_per_type = _vu_rp_node_get_publications_count_per_type($node);
  foreach ($wrapper->field_rpa_publications as $paragraph) {
    $publication = [];
    $doi = NULL;
    $type = $paragraph->field_rpa_p_type->value();

    $year = $paragraph->field_rpa_p_year->value();
    if ($year) {
      $publication['year'] = date('Y', $year);
    }

    $citation = $paragraph->field_rpc_p_citation->value();
    if ($citation) {
      $publication['citation'] = $citation;
    }

    $doi = $paragraph->field_rpa_p_doi->value();
    if ($doi) {
      $publication['doi'] = $doi;
      $publication['link'] = vu_rp_render_doi_link($doi);
    }

    $types[$type]['items'][] = $publication;
    if (isset($count_per_type[$type])) {
      $types[$type]['total'] = $count_per_type[$type];
    }
  }

  // Sort groups by name.
  ksort($types);

  // Sort reverse chronologically within types.
  foreach (array_keys($types) as $group) {
    uasort($types[$group]['items'], function ($a, $b) {
      return $a['year'] == $b['year'] ? 0 : ($a['year'] > $b['year'] ? -1 : 1);
    });
    $types[$group]['items'] = array_values($types[$group]['items']);
  }

  return $types;
}

/**
 * Get count of publications per type.
 */
function _vu_rp_node_get_publications_count_per_type($node) {
  $types = [];

  $value = vu_rp_extract_single_field_value('node', $node, 'field_rpc_publication_type_count');
  if (empty($value)) {
    return $types;
  }

  $value = trim($value);
  $lines = preg_split('/\r\n|[\r\n]/', $value);
  foreach ($lines as $line) {
    list($type, $count) = explode(':', $line);
    $type = trim($type);
    $count = trim($count);
    $types[$type] = $count;
  }

  return $types;
}

/**
 * Get all fundings for a node.
 */
function vu_rp_node_get_fundings($node) {
  $groups = [];

  $wrapper = entity_metadata_wrapper('node', $node);
  if (!isset($wrapper->field_rpa_funding)) {
    return $groups;
  }

  foreach ($wrapper->field_rpa_funding as $paragraph) {
    $funding['title'] = $paragraph->field_rp_project_title->value();
    $funding['source'] = $paragraph->field_rp_fund_sources->value();
    $funding['investigators'] = $paragraph->field_rp_fund_investigators->value();
    $funding['amount'] = $paragraph->field_rp_fund_amount->value();
    if (is_numeric($funding['amount'])) {
      $funding['amount'] = intval($funding['amount']);
      $funding['amount'] = '$' . vu_core_format_currency($funding['amount']);
    }

    $start = $paragraph->field_rp_fund_period_duration->value->value();
    $end = $paragraph->field_rp_fund_period_duration->value2->value();
    $funding['year'] = date('Y', $start);
    $funding['start'] = date('Y', $start);
    $funding['period'] = $funding['start'];
    $funding['end'] = NULL;
    if ($end) {
      $funding['end'] = date('Y', $end);
      $funding['period'] .= '-' . $funding['end'];
    }
    $groups[$funding['year']][] = $funding;
  }

  krsort($groups);

  // Sort reverse chronologically within groups.
  foreach (array_keys($groups) as $group) {
    uasort($groups[$group], function ($a, $b) {
      return $a['year'] == $b['year'] ? 0 : ($a['year'] > $b['year'] ? -1 : 1);
    });
    $groups[$group] = array_values($groups[$group]);
  }

  return $groups;
}

/**
 * Get all supervisions.
 */
function vu_rp_get_node_supervisions($node, $is_current, $groupby = FALSE) {
  $groups = [];

  $field_name = $is_current ? 'field_rpa_sup_current' : 'field_rpa_sup_completed';

  $wrapper = entity_metadata_wrapper('node', $node);
  if (!isset($wrapper->{$field_name})) {
    return $groups;
  }

  $supervisions = [];
  foreach ($wrapper->{$field_name} as $paragraph) {
    $supervision['level'] = $paragraph->field_rp_sup_study_level->value();
    $supervision['role'] = $paragraph->field_rp_sup_role->value();
    $supervision['student_count'] = $paragraph->field_rp_sup_students->value();
    $supervisions[] = $supervision;
    $groups[$supervision['level']][$supervision['role']] = $supervision;
  }

  ksort($groups);

  // Sort reverse chronologically within groups.
  foreach (array_keys($groups) as $group) {
    ksort($groups[$group]);
  }

  return $groupby ? $groups : $supervisions;
}

/**
 * Check if can submit a profile for review.
 */
function vu_rp_node_can_submit_for_review($node, $account) {
  $publications = vu_rp_node_get_publications($node);

  return count($publications) > 0;
}
