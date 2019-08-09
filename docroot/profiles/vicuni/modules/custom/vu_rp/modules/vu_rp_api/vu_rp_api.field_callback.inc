<?php

/**
 * @file
 * Code for the VU Researcher Profile API field callbacks.
 */

/**
 * Field callback to create first name.
 */
function vu_rp_api_field_callback_first_name($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
  $node->{$dst_field}[LANGUAGE_NONE] = [[$dst_value_key => vu_rp_api_convert_first_name($source_value)]];
}

/**
 * Field callback to create last name.
 */
function vu_rp_api_field_callback_last_name($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
  $node->{$dst_field}[LANGUAGE_NONE] = [[$dst_value_key => vu_rp_api_convert_last_name($source_value)]];
}

/**
 * Field callback to create email.
 */
function vu_rp_api_field_callback_email($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
  $node->{$dst_field}[LANGUAGE_NONE] = [[$dst_value_key => vu_rp_api_convert_email($source_value)]];
}

/**
 * Field callback to create publication paragraph.
 */
function vu_rp_api_field_callback_publications($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
  $data = (array) $source_value;

  if (empty($data)) {
    return;
  }

  $groups = vu_rp_api_convert_publications($data);
  if (empty($groups)) {
    return;
  }

  // Only store total count if there is data.
  vu_rp_api_set_field_value(count($data), $node, 'field_rpc_publication_count', 'value', 0);

  // Reset current publication values on the node.
  $node->field_rpa_publications = [];
  // Create new values per group.
  foreach ($groups as $type => $pubs_per_group) {
    foreach ($pubs_per_group['items'] as $pub_per_group) {
      _vu_rp_api_publications_paragraph_create($pub_per_group, $node);
    }
    $count_per_type_value[] = $type . ': ' . $pubs_per_group['total'];
  }

  $count_per_type_value_lines = implode(PHP_EOL, $count_per_type_value);

  // Special place to store count per type on the node. This will later be used
  // to display total numbers on the front-end.
  vu_rp_api_set_field_value($count_per_type_value_lines, $node, 'field_rpc_publication_type_count', 'value', 0);
  vu_rp_api_set_field_value($count_per_type_value_lines, $node, 'field_rpc_publication_type_count', 'safe_value', 0);
}

/**
 * Field callback to create funding paragraph.
 */
function vu_rp_api_field_callback_funding($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
  $data = (array) $source_value;

  if (empty($data)) {
    return 0;
  }

  $groups = vu_rp_api_convert_fundings($data);
  if (empty($groups)) {
    return 0;
  }

  // Reset current funding details.
  $node->field_rpa_funding = [];

  foreach ($groups as $records) {
    foreach ($records as $record) {
      $investigators = !empty($record['otherInvestigators']) ? _vu_rp_api_process_funding_investigators($record['otherInvestigators']) : '';
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rpa_funding', 'bundle' => 'rp_funding']);

      vu_rp_api_set_field_value($record['projectTitle'], $paragraph, 'field_rp_project_title');
      vu_rp_api_set_field_value($record['grantFundSource'], $paragraph, 'field_rp_fund_sources');
      vu_rp_api_set_field_value($investigators, $paragraph, 'field_rp_fund_investigators');
      vu_rp_api_set_field_value($record['grantAmount'], $paragraph, 'field_rp_fund_amount');

      $duration = [
        'timezone' => 'Australia/Melbourne',
        'timezone_db' => 'Australia/Melbourne',
        'date_type' => 'datetime',
      ];
      $duration['value'] = date('Y-m-d H:i:s', strtotime($record['startDate']));
      if (!empty($record['endDate'])) {
        $duration['value2'] = date('Y-m-d H:i:s', strtotime($record['endDate']));
      }
      $paragraph->field_rp_fund_period_duration[LANGUAGE_NONE][] = $duration;

      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return count($source_value);
}

/**
 * Helper to process investigators values before saving.
 */
function _vu_rp_api_process_funding_investigators($records) {
  $output = [];
  foreach ($records as $value) {
    $value = (array) $value;
    $parts = [];
    if (!empty($value['honorific'])) {
      $parts[] = ucfirst(strtolower($value['honorific']));
    }

    if (!empty($value['firstName'])) {
      $parts[] = $value['firstName'];
    }

    if (!empty($value['lastName'])) {
      $parts[] = $value['lastName'];
    }

    $output[] = implode(' ', $parts);
  }

  $output = array_filter($output);

  return implode(', ', $output);
}

/**
 * Field callback to create supervision paragraphs.
 */
function vu_rp_api_field_callback_supervision($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
  _vu_rp_api_supervision_paragraph_create($node, $source_value, TRUE);
  _vu_rp_api_supervision_paragraph_create($node, $source_value, FALSE);
}

/**
 * Helper to set value in field_rpa_publications.
 */
function _vu_rp_api_publications_paragraph_create($publication, $node) {
  if (empty($node) || empty($publication)) {
    return;
  }

  $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rpa_publications', 'bundle' => 'rp_publication']);
  vu_rp_api_set_field_value($publication['type'], $paragraph, 'field_rpa_p_type');
  $paragraph->field_rpa_p_year[LANGUAGE_NONE][] = [
    'value' => $publication['publicationDate'],
    'timezone' => 'Australia/Melbourne',
    'timezone_db' => 'Australia/Melbourne',
    'date_type' => 'datetime',
  ];

  // @todo: Move this to converter.
  $citation = _vu_rp_api_render_publication_citation($publication);
  $citation = vu_rp_api_convert_strings($citation);

  vu_rp_api_set_field_value($citation, $paragraph, 'field_rpc_p_citation');

  if (!empty($publication['DOI'])) {
    vu_rp_api_set_field_value($publication['DOI'], $paragraph, 'field_rpa_p_doi');
  }
  $paragraph->setHostEntity('node', $node);
  $paragraph->save(TRUE);
}

/**
 * Helper to set supervision data values.
 *
 * @todo: Refactor this to extract converter.
 */
function _vu_rp_api_supervision_paragraph_create($node, $data, $is_current) {
  $data = (array) $data;

  if (empty($node) || empty($data)) {
    return count($data);
  }

  $field_name = $is_current ? 'field_rpa_sup_current' : 'field_rpa_sup_completed';

  $groups = [];
  foreach ($data as $record) {
    $record = (array) $record;
    if (is_null($record['yearOfCompletion']) != $is_current) {
      continue;
    }

    // Increment total value.
    $groups[$record['HDRType']][$record['supervisionRole']] =
      isset($groups[$record['HDRType']][$record['supervisionRole']]) ?
        $groups[$record['HDRType']][$record['supervisionRole']] + 1 : 1;
  }

  // Remove all paragraphs before creating the new ones. This is faster and
  // easier then resolve between existing and non-existing paragraphs by group
  // and level.
  // We're specifically not removing paragraphs_item entities here (they will
  // be automatically archived on node save) - doing so would break node
  // revisioning. We actually do not need to store the revisions of these
  // calculated fields, but we do want to maintain data integrity for each
  // revision and deleting paragraphs_item entities will break it.
  $node->{$field_name} = [];

  $count = 0;
  foreach ($groups as $level => $roles) {
    foreach ($roles as $role => $group_count) {
      $current_role = $role . ' supervisor';
      $current_level = $level == 'Masters' ? $level . ' by Research' : $level;

      $paragraph = new ParagraphsItemEntity(['field_name' => $field_name, 'bundle' => 'rp_supervision']);
      vu_rp_api_set_field_value($current_level, $paragraph, 'field_rp_sup_study_level');
      vu_rp_api_set_field_value($current_role, $paragraph, 'field_rp_sup_role');
      vu_rp_api_set_field_value($group_count, $paragraph, 'field_rp_sup_students');
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
      $count += $group_count;
    }
  }

  return $count;
}
