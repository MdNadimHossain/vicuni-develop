<?php

/**
 * @file
 * Courses - VU Online - Promo block.
 */

/**
 * Class VuCoreVuoPromoCourseBlock.
 */
class VuCoreVuoPromoCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public static $info = 'VU Online - Promo block';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_vuo_promo';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    return $this->isVuOnline();
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $course_title = $this->course->title;

    return [
      'course_title' => $course_title,
    ];
  }

}
