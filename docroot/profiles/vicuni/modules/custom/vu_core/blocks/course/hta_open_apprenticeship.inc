<?php

/**
 * @file
 * Courses - How to Apply - Open - Apprenticeship block.
 */

/**
 * Class VuCoreHtaOpenApprenticeshipCourseBlock.
 */
class VuCoreHtaOpenApprenticeshipCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_YES;

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Ensure the course is an apprenticeship.
    $this->courseIntake = $this->getCourseIntake();
    if ($this->courseIntake->isApprenticeship()) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Open - Apprenticeships';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_open_apprenticeship';

}
