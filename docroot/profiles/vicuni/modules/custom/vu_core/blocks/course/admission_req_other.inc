<?php

/**
 * @file
 * Courses - Admission Requirement - Additional Information.
 */

/**
 * Class VuCoreAdmissionReqOtherCourseBlock.
 */
class VuCoreAdmissionReqOtherCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Additional Admission Requirement Other';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_admission_req_other';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Display for undergrad courses if switch is on.
    if (vu_feature_switches_switch_state('courses-admission-transparency')) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {

    // Getting information from the XML.
    $additional_information = vu_core_extract_single_field_value($this->course, 'node', 'field_additional_information', 'safe_value');

    // Checking if there is any information.
    if (!empty($additional_information)) {
      $additional_information = filter_xss_admin($additional_information);
    }

    return [
      'additional_information' => $additional_information,
    ];

  }

}
