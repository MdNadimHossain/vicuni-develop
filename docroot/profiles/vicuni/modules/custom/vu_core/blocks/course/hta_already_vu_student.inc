<?php

/**
 * @file
 * Courses - How to Apply - Already a VU student block.
 */

/**
 * Class VuCoreHtaAlreadyVuStudentCourseBlock.
 */
class VuCoreHtaAlreadyVuStudentCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_GROUP_ALL ^ VU_CBS_AQF_DOC_DEGREE ^ VU_CBS_AQF_MASTERS_DEGREE_RESEARCH;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_CUSTOM;

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Ensure the course is open for direct applications.
    $this->courseIntake = $this->getCourseIntake();
    if ($this->courseIntake->isOpen('direct') && !$this->courseIntake->isApprenticeship()) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Already a VU student';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_already_vu_student';

}
