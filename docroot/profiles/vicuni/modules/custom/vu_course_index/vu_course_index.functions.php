<?php

/**
 * @file
 * Non-framework functions for course index functionality.
 */

require_once 'CourseIntakeList.class.php';
require_once 'CourseEssentialsPresenter.class.php';

define('VU_COURSE_INDEX_MODULE_PATH', drupal_get_path('module', 'vu_course_index'));

define('VU_COURSE_INDEX_MOBILE_APPLY_ONLINE_URL', 'mobile/apply-online');

/**
 * Check if a course node is Postgrad Research.
 *
 * @param object $course_node
 *        Drupal node.
 *
 * @return bool
 *         Is the cours postgrad research?
 */
function vu_course_index_is_pgr($course_node) {
  if ($course_node->field_unit_lev[$course_node->language][0]['value'] == 'postgrad') {
    $code = $course_node->field_unit_code[$course_node->language][0]['safe_value'];
    $in_index = count(vu_course_index_load_rows($code)) > 0 ? TRUE : FALSE;
    $is_diploma = stripos($course_node->title, 'diploma') !== FALSE ? TRUE : FALSE;
    return !($in_index || $is_diploma);
  }
  return FALSE;
}

/**
 * Map supplementary form codes to form names and URLs.
 *
 * @param string $code
 *        Supplementary form code.
 *
 * @return string|null
 *         Returns a link to the form if it exists.
 */
function vu_course_index_supplementary_form_link($code) {
  $forms = array(
    "A130" => array(
      "name" => "A130 - Community Services reference form",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A130-Community-reference-form.pdf",
    ),

    "A310" => array(
      "name" => "A310 - Additional Information for Honours Courses",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A310-additional-information-for-honours-courses.pdf",
    ),

    "A305" => array(
      "name" => "A305 - Additional Information for Bachelor of Social Work",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A305-additional-information-for-bachelor-of-social-work.pdf",
    ),

    "A315" => array(
      "name" => "A315 - Additional Information for Youth Work Certificate IV and Diploma",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A315-additional-information-youth-work-certificate-4-and-diploma.pdf",
    ),

    "A141" => array(
      "name" => "A141 - Master of Teaching supplementary form",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A141-Master-of-Teaching-Supplementary-Form.pdf",
    ),

    "A313" => array(
      "name" => "A313 - Additional Information for Paramedic Postgraduate and Degree Conversion Programs",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A313-additional-information-for-paramedic-postgraduate-and-degree-conversion-programs.pdf",
    ),

    "A134" => array(
      "name" => "A134 - Referee report for Graduate programs in Psychology or Counselling",
      "url" => "http://www.vu.edu.au/sites/default/files/student-connections/pdfs/A134-referee-report-counselling-psychology.pdf",
    ),

  );

  if (isset($forms[$code])) {
    $form = $forms[$code];
    return l($form['name'], $form['url']);
  }
  return NULL;
}

/**
 * Return CourseIndexList for a VU course code.
 *
 * @param string $vu_course_code
 *        VU course code.
 *
 * @return CourseIntakeList
 *         Course index rows in an object that can answer questions.
 */
function vu_course_index_get_course_intake_list($vu_course_code) {
  return new CourseIntakeList(vu_course_index_load_rows($vu_course_code));
}

/**
 * Get CourseEssentialsPresenter for a set of course essentials information.
 *
 * @param array $info
 *        From `CourseIntakeList::courseEssentialsInfo()`.
 *
 * @return CourseEssentialsPresenter
 *         Presenter based on the information provided.
 */
function vu_course_index_get_course_essentials_presenter($info) {
  $info['value_map'] = [
    'place_type' => [
      'GOVTFUND' => theme('fee-csp'),
      'HEFULLFEE' => theme('fee-full'),
    ],
  ];
  return new CourseEssentialsPresenter($info);
}

/**
 * Test if a course is open for mid-year intake.
 *
 * @param object $node
 *        The course node.
 *
 * @return bool
 *         Whether the course is open for mid-year.
 */
function vu_course_index_is_midyear($node) {
  $delivery = vu_course_index_get_course_intake_list($node->field_unit_code[$node->language][0]['safe_value']);
  return vu_feature_switches_switch_state('courses-midyear-info') && $delivery->isOpen() ? 1 : 0;
}

/**
 * Return a function that encloses course to enable simpler field access.
 *
 * @param object $course
 *   Drupal node.
 *
 * @return callable
 *   Function that cloases over course and returns field values for use in
 *   preprocess functions or templates.
 */
function _course_field_lookup_func($course) {
  return function ($field_name, $type = 'safe_value') use ($course) {
    $full_field_name = "field_${field_name}";
    $field = $course->$full_field_name;
    $field_value = !empty($field[$course->language]) && !empty($field[$course->language][0][$type]) ? $field[$course->language][0][$type] : NULL;
    // Fallback for when safe_value isn't populated.
    if ($field_value === NULL && $type === 'safe_value') {
      $type = 'value';
      $field_value = !empty($field[$course->language]) && !empty($field[$course->language][0][$type]) ? $field[$course->language][0][$type] : NULL;
    }
    return $field_value;
  };
}

/**
 * Checks if an international course has July intake for a given year.
 *
 * @param array $field_int_sem_int_value
 *    Field value xml string.
 * @param string $year
 *    String representing a year eg. 2016.
 *
 * @return bool
 *    TRUE if course has July intake.
 */
function vu_courses_has_july_intake_from_xml($field_int_sem_int_value, $year = '') {
  if (empty($field_int_sem_int)) {
    return FALSE;
  }

  if (!$year) {
    $year = date('Y');
  }

  $intake_xml = simplexml_load_string($field_int_sem_int_value);
  if ($intake_xml) {
    // $intake_out = array();
    foreach ($intake_xml->semesterintake as $intake) {
      $attributes = $intake->attributes();
      if (!empty($attributes) && isset($attributes['year']) && $attributes['year']) {
        $semesters = vu_courses_get_inter_semester($intake);
        $intake_year = $attributes['year'];
        if ($intake_year == $year && stripos($semesters, 'July') !== FALSE) {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

/**
 * Check if given course (node/stdclass object) is above bachelors level.
 */
function vu_courses_above_bachelors($course) {
  $levels = array(
    'Graduate Certificate',
    'Graduate Diploma',
    'Bachelor Honours Degree (stand alone)',
    'Masters (Coursework) Degree',
    'Doctoral Degree',
    'Masters (Research) Degree',
    'Associate Degree',
  );
  $exceptional_courses = array(
    '22248VIC',
    'BLGE',
    'EMTC',
    'EMTP',
    'EMTS',
    'HBTD',
    'ICA50411',
    'ICA50611',
    'ICA60211',
  );

  $aqf = isset($course->field_course_aqf[$course->language][0]['safe_value']) ? $course->field_course_aqf[$course->language][0]['safe_value'] : '';
  $unit_code = isset($course->field_unit_code[$course->language][0]['safe_value']) ? $course->field_unit_code[$course->language][0]['safe_value'] : '';

  return in_array(strtolower($aqf), array_map('strtolower', $levels)) ||
    in_array(strtolower($unit_code), array_map('strtolower', $exceptional_courses));
}

// TEMP\.
/**
 * A list of VU campuses: URL and title, keyed by title.
 */

function vu_campuses_list() {
  $results = db_query(
    "SELECT `nid`, `title` FROM {node} WHERE `type`='campus' AND `status` = 1 ORDER BY `title`");

  $campuses = array();
  $result = $results->fetchAllKeyed();

  foreach ($result as $nid => $title) {
    $campuses[$title] = array(
      'title' => $title,
      'url' => url('node/' . $nid),
    );
  }

  // Handle the specia case where VU Sydney doesn't have
  // a real campus node.
  $campuses['VU Sydney'] = array(
    'title' => 'VU Sydney',
    'url' => vu_unit_special_location_link('VU Sydney', TRUE),
  );
  ksort($campuses);

  return $campuses;
}

/**
 * Test if a course is open for b3 intake.
 *
 * @param object $node
 *        The course node.
 *
 * @return bool
 *         Whether the course is open for b3.
 */
function vu_course_index_is_b3intake($node) {
  $course_code = field_get_items('node', $node, 'field_unit_code', $node->language);
  if (!empty($course_code[0]['value'])) {
    $delivery = vu_course_index_get_course_intake_list($course_code[0]['value']);
    return $delivery->commencementDateNext() ? 1 : 0;
  }

  return false;
}

/**
 * Test if a course is open for b3 intake.
 *
 * @param object $node
 *        The course node.
 *
 * @return bool
 *         Whether the course is open for b3.
 */
function vu_course_index_is_b3intake_closed($node) {
  $course_code = field_get_items('node', $node, 'field_unit_code', $node->language);
  if (!empty($course_code[0]['value'])) {
    $delivery = vu_course_index_get_course_intake_list($course_code[0]['value']);
    return $delivery->isClosed('direct') ? 1 : 0;
  }

  return false;
}

