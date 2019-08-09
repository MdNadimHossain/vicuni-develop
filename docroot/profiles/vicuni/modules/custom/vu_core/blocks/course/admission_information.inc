<?php

/**
 * @file
 * Courses - Admission Information.
 */

/**
 * Class VuCoreAdmissionReqSummaryCourseBlock.
 */
class VuCoreAdmissionInformationCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Admission Information';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_admission_info';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Do not display for undergrad courses if switch is on
    // and for tafe courses.
    $course_type = $this->getCourseType();
    if (vu_feature_switches_switch_state('courses-admission-transparency') &&
      $this->isUndergrad() ||
      $course_type == VU_CBS_TYPE_VE ||
      ($course_type == VU_CBS_TYPE_HE && $this->getCourseAqf() == VU_CBS_AQF_DIPLOMA)) {
      return FALSE;
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $isInternational = vu_courses_is_international_course_url();

    $admission_information = vu_core_extract_single_field_value($this->course, 'node', 'field_imp_admission_requirements', 'safe_value');

    // Format admission information for domestion courses.
    if (!$isInternational) {
      // Remove International and PG course info.
      $patterns = [
        '|<li>International: .*</li>|uiUs',
        '|<li>Bachelor/Honours degree: .*</li>|uiUs',
        '|<li>Mature: .*</li>|uiUs',
      ];
      $admission_info = preg_replace($patterns, '', $admission_information);
      $raw_admission_info = trim(strip_tags($admission_info));
      $is_admission_info = strlen($raw_admission_info) > 3;
      $admission_information = $is_admission_info ? $admission_info : '';
    }
    else {
      // Unset admission information for international courses.
      $admission_information = '';
    }

    if (!empty($admission_information)) {
      $admission_information = filter_xss_admin($admission_information);
    }

    return [
      'is_international' => $isInternational,
      'admission_information' => $admission_information,
    ];
  }

}
