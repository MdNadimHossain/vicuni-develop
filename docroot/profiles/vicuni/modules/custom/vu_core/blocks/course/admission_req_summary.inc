<?php

/**
 * @file
 * Courses - Admission Requirements Summary.
 */

/**
 * Class VuCoreAdmissionReqSummaryCourseBlock.
 */
class VuCoreAdmissionReqSummaryCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Admission Requirements Summary';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_admin_req_summary';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Do not display for undergrad courses if switch is on.
    if (vu_feature_switches_switch_state('courses-admission-transparency') &&
       ($this->isUndergrad()  ||
       ($this->getCourseType() == VU_CBS_TYPE_HE &&
       $this->getCourseAqf() == VU_CBS_AQF_DIPLOMA))) {
      return FALSE;
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $non_award = $this->getCourseType() === VU_CBS_TYPE_NA;

    return [
      'non_award' => $non_award,
    ];
  }

}
