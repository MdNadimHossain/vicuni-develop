<?php

/**
 * @file
 * Courses - Entry Requirements VE.
 */

/**
 * Class VuCoreEntryReqVECourseBlock.
 */
class VuCoreEntryReqVECourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Entry Requirements VE';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_entry_req_ve';

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $entry_req_ve = vu_core_extract_single_field_value($this->course, 'node', 'field_entry_requirements_ve');

    return [
      'entry_requirements' => $entry_req_ve,
    ];
  }

}
