<?php

/**
 * @file
 * Courses - ATAR Information.
 */

/**
 * Class VuCoreAtarInformationCourseBlock.
 */
class VuCoreAtarInformationCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'ATAR Information';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_atar_info';

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

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $admin_req_link = url('https://policy.vu.edu.au/document/view.php', ['query' => ['id' => 70]], 'external');

    return [
      'admin_req_link' => $admin_req_link,
    ];
  }

}
