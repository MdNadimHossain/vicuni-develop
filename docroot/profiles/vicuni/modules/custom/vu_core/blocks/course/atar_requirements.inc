<?php

/**
 * @file
 * Courses - Atar Requirements.
 */

/**
 * Class VuCoreAtarRequirementsCourseBlock.
 */
class VuCoreAtarRequirementsCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Atar Requirements';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_atar_requirements';

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Do not display for undergrad courses if switch is on.
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
    $is_international = vu_courses_is_international_course_url();
    $enquiry_link = $is_international ? '/international-students/make-an-enquiry' : '#goto-enquire-now';

    return [
      'enquiry_link' => $enquiry_link,
      'additional_requirements' => vu_core_extract_single_field_value($this->course, 'node', 'field_additional_requirements', 'safe_value'),
    ];
  }

}
