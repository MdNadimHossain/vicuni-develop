<?php

/**
 * @file
 * Courses - How to Apply - Direct closed.
 */

/**
 * Class VuCoreHtaDirectClosedCourseBlock.
 */
class VuCoreHtaDirectClosedCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_ALL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Direct closed';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_direct_closed';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Ensure the course is closed.
    $this->courseIntake = $this->getCourseIntake();
    $direct_future = $this->courseIntake->isClosed('direct') && $this->courseIntake->nextDate('direct');
    if (!$this->courseIntake->isOpen('direct') && !$direct_future && $this->isVuOnline()) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $after_apply_block = new VuCoreHtaAfterYouApplyCourseBlock($this->course);
    $after_apply_content = $after_apply_block->view();
    $after_apply_text = '';
    if (isset($after_apply_content['content'])) {
      $after_apply_text = $after_apply_content['content'];
    }

    $vtac_open = $this->courseIntake->isOpen('vtac');
    $is_online = $this->isVuOnline();

    $direct_class = (!$vtac_open && !$is_online) ? 'col-md-12' : 'col-md-6';

    return [
      'after_apply' => $after_apply_text,
      'direct_class' => $direct_class,
    ];
  }

}
