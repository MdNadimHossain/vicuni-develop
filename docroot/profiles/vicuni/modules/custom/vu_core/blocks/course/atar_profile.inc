<?php

/**
 * @file
 * ATAR Student Profile.
 */

/**
 * Class VuCoreStudentProfileCourseBlock.
 */
class VuCoreAtarProfileCourseBlock extends VuCoreCourseBlockBase {

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
  public static $info = 'ATAR profile ranking data';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_atar_profile_block';

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

    // Get Atar Table data.
    $atar_profile_data = vu_core_extract_single_field_value($this->course, 'node', 'field_atar_profile_data');
    $variables = [
      'data' => $atar_profile_data,
    ];

    return $variables;
  }

}
