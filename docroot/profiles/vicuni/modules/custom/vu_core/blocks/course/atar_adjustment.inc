<?php

/**
 * @file
 * Courses - Atar Adjustment.
 */

/**
 * Class VuCoreAtarAdjustmentCourseBlock.
 */
class VuCoreAtarAdjustmentCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'ATAR Adjustment';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_atar_adjustment';

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
      // Ensure atar is enabled.
      $atar_indicator = vu_core_extract_single_field_value($this->course, 'node', 'field_atar_indicator');
      if ($atar_indicator != "Y") {
        return FALSE;
      }

      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $atar_adjustment = vu_core_extract_single_field_value($this->course, 'node', 'field_atar_adjustment');

    return [
      'atar_adjustment' => $atar_adjustment,
    ];
  }

}
