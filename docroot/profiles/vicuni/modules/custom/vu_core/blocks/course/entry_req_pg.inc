<?php

/**
 * @file
 * Courses - Entry Requirements PG.
 */

/**
 * Class VuCoreEntryReqtPgCourseBlock.
 */
class VuCoreEntryReqPgCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Entry Requirements PG';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_entry_req_pg';

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_MASTERS_DEGREE | VU_CBS_AQF_GRAD_DIPLOMA | VU_CBS_AQF_GRAD_CERT | VU_CBS_AQF_DOC_DEGREE | VU_CBS_AQF_MASTERS_DEGREE_RESEARCH;

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $entry_req_pg = vu_core_extract_single_field_value($this->course, 'node', 'field_entry_requirements_pg');
    $essential_requirements = vu_core_extract_single_field_value($this->course, 'node', 'field_additional_requirements', 'safe_value');

    return [
      'entry_requirements' => $entry_req_pg,
      'essential_requirements' => $essential_requirements,
    ];
  }

}
