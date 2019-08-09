<?php

/**
 * @file
 * ATAR Student Profile.
 */

define('ATAR_HAS_VALUE_TEXT', 'Lowest selection rank*:');
define('ATAR_NO_VALUE_TEXT', 'Not required*');
define('ATAR_EDUCATION_ONLY_TEXT', 'Minimum ATAR*:');
define('ATAR_MORE_LINK_TEXT', '*Offers made in 2019.');
define('ATAR_MORE_DUCATION_ONLY_LINK_TEXT', '*Entry in 2019.');
define('EDUCATION_COURSE_CODE', 'EBED');
/**
 * Class VuCoreStudentProfileCourseBlock.
 */
class VuCoreAtarMinEntryCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'ATAR Minimum Entry';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_atar_min_entry';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    if (vu_feature_switches_switch_state('courses-admission-transparency')) {
      // Ensure that this works for only HE diploma courses.
      if ($this->getCourseAqf() == VU_CBS_AQF_DIPLOMA) {
        if ($this->getCourseType() != VU_CBS_TYPE_HE) {
          return FALSE;
        }
      }

      return TRUE;
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {

    // Add the JS.
    drupal_add_js(drupal_get_path('module', 'vu_core') . '/js/vu_core.admission_atar.js');

    // Get Atar Minimum data & text.
    $variables = vu_core_get_atar_minimum_entry_data($this->course);
    return $variables;
  }

}

/**
 * Get/Customise the Atar Minimum Data.
 */
function vu_core_get_atar_minimum_entry_data($course) {

  $atar_min_entry_data = vu_core_extract_single_field_value($course, 'node', 'field_atar_minimum_entry');
  $course_code = vu_core_extract_single_field_value($course, 'node', 'field_unit_code');

  $atar_more_link_text = ATAR_MORE_LINK_TEXT;

  if ((strtoupper($course_code) == EDUCATION_COURSE_CODE) && $atar_min_entry_data) {
    $atar_heading = ATAR_EDUCATION_ONLY_TEXT;
    $atar_more_link_text = ATAR_MORE_DUCATION_ONLY_LINK_TEXT;
  }
  elseif ($atar_min_entry_data) {
    $atar_heading = ATAR_HAS_VALUE_TEXT;
  }
  else {
    $atar_heading = ATAR_NO_VALUE_TEXT;
  }

  if ($atar_min_entry_data) {
    // Maximum only two lines.
    $atar_min_entry_data = ($atar_min_entry_data) ? str_replace(PHP_EOL, '<br>', $atar_min_entry_data) : FALSE;
  }

  return [
    'atar_value' => $atar_min_entry_data,
    'atar_heading' => $atar_heading,
    'atar_more_link_text' => $atar_more_link_text,
  ];

}
