<?php

/**
 * @file
 * Courses - Pathways and Credits Intro.
 */

/**
 * Class VuCorePAthwaysCreditsIntroCourseBlock.
 */
class VuCorePAthwaysCreditsIntroCourseBlock extends vuCoreCourseBlockBase {
  /**
   * {@inheritdoc}
   */
  public static $info = 'Pathways and Credits Intro';
  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_pathways_credits_intro';
  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

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

}
