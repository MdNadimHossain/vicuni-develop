<?php

/**
 * @file
 * Course essential VE duration block.
 */

/**
 * Class VuCoreVeDurationCourseBlock.
 */
class VuCoreVeDurationCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_ALL;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'VE Duration Block';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_ve_duration';

  /**
   * {@inheritdoc}
   */
  public function variables() {

    // Get VE course duration info.
    if (!vu_courses_is_international_course_url()) {
      if ($this->isMultipleAud()) {
        $ve_duration_text = '';
      }
      else {
        $ve_duration_text = vu_courses_duration_text($this->course);
      }
    }
    else {
      $ve_duration_text = vu_courses_duration_text($this->course);
    }

    return [
      've_duration_text' => $ve_duration_text,
    ];

  }

}
