<?php

/**
 * @file
 * Courses - Undergrad Special Admission Programs for ATAR SE.
 */

/**
 * Class VuCoreSpecialAdProSeCourseBlock.
 */
class VuCoreSpecialAdProSeCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Undergrad Special Admission Programs ATAR SE';
  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_special_admission_pro';
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
    // Display for undergrad courses if switch is on.
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

}
