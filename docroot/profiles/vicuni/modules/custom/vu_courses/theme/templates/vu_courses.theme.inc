<?php

/**
 * @file
 * Prepare data for course pages.
 */

/**
 * Preprocess vars for the description section of a course page.
 */
function vu_courses_description_preprocess(&$variables) {
  if (isset($variables['node']->field_imp_desc[LANGUAGE_NONE][0]['safe_value'])) {
    $variables['description'] = $variables['node']->field_imp_desc[LANGUAGE_NONE][0]['safe_value'];
  }
  if (isset($variables['node']->field_unit_lev[LANGUAGE_NONE][0]['value'])) {
    $variables['postgraduate'] = $variables['node']->field_unit_lev[LANGUAGE_NONE][0]['value'] == 'postgrad';
  }
}

/**
 * Preprocess vars for the structure section of a course page.
 *
 * NOTE: structure field machine name is field_structure on
 * units/unitsets and field_imp_structure on courses.
 */
function vu_courses_units_and_electives_preprocess(&$variables) {
  $node = $variables['node'];

  // Handle BBUS-$specialisation structure which is a combination of the
  // BBUS structure and the specialisation unitset structure.
  $code = $node->field_unit_code[$node->language][0]['safe_value'];
  if (preg_match('/^BBUS-(.*)$/i', $code, $matches)) {
    $unitset_code = $matches[1];
    $unitset_structure = '';

    // Load relevant specialisation unitset node.
    $spec_query = new EntityFieldQuery();
    $spec_query->entityCondition('entity_type', 'node')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_unit_code', 'value', $unitset_code);
    $spec_result = $spec_query->execute();

    if (isset($spec_result['node'])) {
      $spec_nids = array_keys($spec_result['node']);
      $spec_nodes = entity_load('node', $spec_nids);
      $spec_unitset = reset($spec_nodes);

      // Unit/unitset structure is styled via xlst in
      // vumain_unit_format_xml_field().
      $unitset_structure = vumain_unit_format_xml_field($spec_unitset->field_structure[$spec_unitset->language][0]['value']);
    }

    // Load parent BBUS node.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_unit_code', 'value', 'BBUS');
    $result = $query->execute();

    $bbus = FALSE;
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $nodes = entity_load('node', $nids);
      $bbus = reset($nodes);
    }

    if ($bbus) {
      // Course structure is parsed via simpleXML in
      // vu_courses_transform_structure().
      $bbus_structure = vu_courses_transform_structure($bbus->field_imp_structure[$node->language][0]['value']);
      $structure = substr($bbus_structure, 0, strrpos($bbus_structure, '<ul>'));
      $structure .= $unitset_structure;
      $structure = str_replace('Students will be required to choose a specialisation to study from the list of specialisations below', '', $structure);
      $node->field_imp_structure[$node->language][0]['safe_value'] = $structure;
    }
  }

  if (!empty($node->field_imp_structure[$node->language][0]['safe_value'])) {
    $structure = $node->field_imp_structure[$node->language][0]['safe_value'];
    $raw_structure = trim(strip_tags($structure));
    $is_structure = strlen($raw_structure) > 3;
    $variables['structure'] = $is_structure ? $structure : '';
  }

  // If it has the "not applicable" text just remove it.
  $field_imp_prereq_units = !empty($node->field_imp_prereq_units[$node->language][0]['value']) ? $node->field_imp_prereq_units[$node->language][0]['value'] : '';
  $check_val = strtolower(trim(strip_tags($field_imp_prereq_units)));
  $variables['prerequisite_units'] = strpos($check_val, 'not applicable') === FALSE && strpos($check_val, 'n/a') === FALSE ? $field_imp_prereq_units : '';
}

/**
 * Preprocess vars for the objectives section of a course page.
 */
function vu_courses_course_objectives_preprocess(&$variables) {
  $variables['course_objectives'] = isset($variables['node']->field_imp_object[$variables['node']->language][0]['safe_value']) ? $variables['node']->field_imp_object[$variables['node']->language][0]['safe_value'] : NULL;
}

/**
 * Preprocess vars for the how to apply section of a domestic course page.
 */
function vu_courses_domestic_how_to_apply_preprocess(&$variables) {
  $node = $variables['node'];
  $code = $node->field_unit_code[$node->language][0]['safe_value'];
  $variables['course_code'] = $code;
  $level = $node->field_unit_lev[$node->language][0]['value'];
  $variables['is_short_course'] = $level == 'short';
  $variables['is_international'] = FALSE;
  $variables['how_to_apply'] = !empty($node->field_how_to_apply[$node->language]) ? $node->field_how_to_apply[$node->language][0]['safe_value'] : '';
  $variables['college'] = !empty($node->field_college[$node->language]) ? $node->field_college[$node->language][0]['title'] : '';
  $variables['has_admission_requirements'] = !empty($node->field_imp_admission_requirements[$node->language][0]['safe_value']);
}

/**
 * Preprocess vars for the how to apply section of an international course page.
 */
function vu_courses_international_how_to_apply_preprocess(&$variables) {
  vu_courses_domestic_how_to_apply_preprocess($variables);
  $variables['is_international'] = TRUE;
  // There is no separate imported version of this field anymore.
  $variables['how_to_apply'] = '';
  if (!empty($variables['node']->field_how_to_apply[$variables['node']->language][0]['safe_value'])) {
    $variables['how_to_apply'] = $variables['node']->field_how_to_apply[$variables['node']->language][0]['safe_value'];
  }
}

/**
 * Preprocess vars for the admission info section of a domestic course page.
 */
function vu_courses_domestic_admission_information_preprocess(&$variables) {
  $node = $variables['node'];

  if (!empty($node->field_imp_admission_requirements[$node->language][0]['safe_value'])) {
    $admission_info = preg_replace('|<li>International: .*</li>|uiUs', '', $node->field_imp_admission_requirements[$node->language][0]['safe_value']);
    $raw_admission_info = trim(strip_tags($admission_info));
    $is_admission_info = strlen($raw_admission_info) > 3;
    $variables['admission_information'] = $is_admission_info ? $admission_info : '';
  }
}

/**
 * Preprocess vars for admission info section of an international course page.
 */
function vu_courses_international_admission_information_preprocess(&$variables) {
  $node = $variables['node'];
  $variables['admission_information'] = !empty($node->field_imp_admission_requirements[$node->language][0]['safe_value']) ? $node->field_imp_admission_requirements[$node->language][0]['safe_value'] : NULL;
  $variables['international_lang_requirements'] = !empty($node->field_inter_lang_requirements[$node->language][0]['safe_value']) ? $node->field_inter_lang_requirements[$node->language][0]['safe_value'] : '<p>Find out if you meet the <a href="/courses/how-to-apply/international-applications/entry-requirements">entry requirements</a>, including English language and academic requirements.</p>';
}

/**
 * Populate some template vars if the user came to a course page from a search.
 */
function vu_courses_search_result_preprocess(&$variables) {
  parse_str(parse_url($_SERVER['HTTP_REFERER'], PHP_URL_QUERY), $referer_qstring);
  if (isset($referer_qstring['query'])) {
    $variables['referer'] = $_SERVER['HTTP_REFERER'];
    $variables['is_search_result'] = TRUE;
    $variables['search_query'] = $referer_qstring['query'];
  }
}

/**
 * Callback for `preg_replace`.
 *
 * Used to remove units which aren't published from
 * the 'Course structure' section of course pages.
 */
function vu_courses_unit_exists_callback($matches) {
  list($unit_markup, $unit_code) = $matches;

  if (is_callable('vu_units_exists')) {
    return vu_units_exists($unit_code) ? $unit_markup : '';
  }
  else {
    return $unit_markup;
  }
}

/**
 * Preprocess vars for a coursebrowser list.
 */
function vu_courses_coursebrowser_list_preprocess(&$variables) {
  // Get study topics and populate $variables['topics'].
  $topics = vu_course_study_areas_get_topics();

  if (!empty($variables['topics'])) {
    $topics = array_merge($topics, $variables['topics']);
  }
  $variables['topics'] = [];
  foreach ($topics as $topic) {
    if (strtolower($topic['title']) == "trades") {
      continue;
    }
    $variables['topics']['/' . $topic['dst']] = $topic['title'];
  }
  $variables['features'] = variable_get('features', []);
}

/**
 * Prepare variables for info session templates.
 */
function vu_courses_info_sessions_preprocess(&$variables) {
  $nid = $variables['nid'];
  $audience = $variables['audience'];
  $info_sessions = [];
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'events')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_date', 'value', time(), '>');
  if ($audience == 'international') {
    $query->fieldCondition('field_cours_feat_int', 'target_id', $nid);
  }
  else {
    $query->fieldCondition('field_cours_feat_dom', 'target_id', $nid);
  }

  $query->addTag('nicedpq');

  $result = $query->execute();

  // If no events reference this node stop here.
  if (!isset($result['node'])) {
    return;
  }

  $events = [];
  if (isset($result['node'])) {
    $events_nids = array_keys($result['node']);
    $events = entity_load('node', $events_nids);
  }

  $info_sessions = [];

  if (!empty($events)) {
    // Loop over event nodes with dates in the future.
    foreach ($events as $nid => $node) {
      $url = '/' . drupal_get_path_alias('node/' . $node->nid);
      $title = $node->title;

      // Format where the event be at, yo.
      $location = NULL;
      $campus = field_get_items('node', $node, 'field_event_campus');
      // If we have a valid campus selection use that.
      if (!empty($campus) && $campus[0]['value'] != 'off-campus') {
        $campus = field_view_value('node', $node, 'field_event_campus', $campus[0], $node->language);
        $campus = drupal_render($campus);
        // Handle edge case pseudo campus.
        $location = $campus . (vu_campuses_is_full_campus($campus) ? ' Campus' : '');
      }
      // Next try the location entity reference.
      elseif (!empty($node->field_location)) {
        $location = field_get_items('node', $node, 'field_location');
        // This gives us the title of the referenced entity.
        // Albeit wrapped in markup that we don't want.
        $location = field_view_field('node', $node, 'field_location', ['label' => 'hidden'], $node->language);
        // Strip field markup.
        $location = strip_tags(drupal_render($location));
      }
      // Next try the location text field.
      elseif (!empty($node->field_location_desc)) {
        // Grab the field content without field template markup.
        $location = field_get_items('node', $node, 'field_location_desc');
        $location = field_view_value('node', $node, 'field_location_desc', $location[0], $node->language);
        $location = drupal_render($location);
      }

      $when = [];
      $date_field = field_get_items('node', $node, 'field_date');
      // Loop over date field items.
      foreach ($date_field as $field_item) {
        // If field delta event start date is in the future.
        if (strtotime($field_item['value']) > REQUEST_TIME) {
          // Add just this field delta value to the event dates.
          $when[] = drupal_render(field_view_value('node', $node, 'field_date', $field_item, $node->language));
        }
      }

      // Add a new info session to the array.
      $info_sessions[] = [
        'location' => $location,
        'url' => $url,
        'title' => $title,
        'when' => [
          '#theme' => 'item_list',
          '#items' => $when,
          '#type' => 'ul',
          '#attributes' => [
            'class' => [
              'event-dates',
              'unstyled',
            ],
          ],
        ],
      ];
    }
  }
  $variables['info_sessions'] = $info_sessions;
}

/**
 * Preprocess variables for course tile template.
 */
function vu_courses_course_tile_preprocess(&$variables) {
  $course_tiles = variable_get('course_tiles');
  $feature = $variables['feature'];
  if (empty($feature) || !isset($course_tiles[$feature])) {
    return FALSE;
  }
  $variables['url'] = $course_tiles[$feature];
}

/**
 * Process xml stored in field_international_fees into suitable markup.
 *
 * @param StdClass $node
 *   A node-like object with field_international_fees.
 *
 * @return string
 *   Markup string.
 */
function vu_courses_international_fees_from_node($node) {
  $processed_fees = FALSE;
  $fees_field = $node->field_international_fees[$node->language][0]['value'];
  $fee_out = vu_courses_international_fees_formatter($fees_field);

  if (empty($fee_out)) {
    return "";
  }

  $processed_fees = array_map(function ($string) {
    return "${string}<sup>*</sup>";
  }, array_column($fee_out, 'formatted'));
  $processed_fees[] = '<em><small>* fee per semester</small></em>';
  return implode('<br/>', $processed_fees);
}

/**
 * Produce formatted output to render international fees information.
 *
 * @param string $xml
 *   Fees XML.
 *
 * @return array
 *   Array of [formatted:string, year:string, fees:string].
 */
function vu_courses_international_fees_formatter($xml) {
  $fee_out = [];
  $fee_xml = simplexml_load_string($xml);
  if ($fee_xml) {
    $delta = 0;
    foreach ($fee_xml->fee as $fee) {
      $attributes = $fee->attributes();
      if (!empty($attributes) && isset($attributes['year'])) {
        // When fees are arranged by year.
        $year = $attributes['year'];
        $fee = trim((string) $fee);
        // Occasionally we see things that aren't numbers, like "NA".
        $formatted_fee = is_numeric($fee) ? 'A$' . number_format($fee) : $fee;
        $fee_out[$delta]['formatted'] = $year . ': ' . $formatted_fee;
        $fee_out[$delta]['year'] = trim((string) $year);
        $fee_out[$delta]['fee'] = $fee;
      }
      else {
        // Fee text without year attribute.
        $fee_out[$delta]['formatted'] = $fee;
      }
      $delta++;
    }
  }
  return $fee_out;
}

/**
 * Process xml stored in field_int_sem_int into suitable markup.
 *
 * @param array $variables
 *   Theme function variables array.
 * @param bool $return_array
 *   If true, return the result as an array.
 *
 * @return string
 *   Markup string.
 */
function vu_courses_international_intake_from_xml(array $variables, $return_array = FALSE) {
  $processed_intake = FALSE;
  if (!empty($variables['node']) && is_object($variables['node'])) {
    $node = $variables['node'];
    $intake_field = $node->field_int_sem_int[$node->language][0]['value'];
  }
  elseif (!empty($variables['value'])) {
    $intake_field = $variables['value'];
  }

  $intake_xml = simplexml_load_string($intake_field);
  if ($intake_xml) {
    $intake_out = [];
    $delta = 0;
    foreach ($intake_xml->semesterintake as $intake) {
      $attributes = $intake->attributes();
      if (!empty($attributes) && isset($attributes['year'])) {
        // When intakes are arranged by year.
        $year = trim((string) $attributes['year']);
        $semester = vu_courses_get_inter_semester($intake);
        $intake_out[$delta]['year'] = $year;
        $intake_out[$delta]['semester'] = $semester;
        $intake_out[$delta]['formatted'] = $year . ': ' . $semester;
      }
      else {
        // Intake without year attribute.
        $intake_out[$delta]['formatted'] = $intake;
      }
      $delta++;
    }

    // Return array.
    if ($return_array) {
      return $intake_out;
    }
    // Return a formatted string.
    $processed_intake = implode('<br />', array_column($intake_out, 'formatted'));
  }
  return $processed_intake;
}

/**
 * Expands semester from international XML.
 *
 * String $input example "1, 2"
 * returns string semester months.
 */
function vu_courses_get_inter_semester($input) {
  $sem = [];
  foreach (explode(',', $input) as $semester) {
    $sem[] = DateTime::createFromFormat('!m', trim($semester))->format('F');
  }
  $last = array_pop($sem);
  return empty($sem) ? $last : implode(', ', $sem) . " and {$last}";
}
