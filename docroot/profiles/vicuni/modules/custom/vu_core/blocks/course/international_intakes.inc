<?php

/**
 * @file
 * International intakes block.
 */

/**
 * Class VuCoreCourseFeesBlock.
 */
class VuCoreInternationalIntakesCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'International intakes';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_international_intakes';

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $intake = vu_core_extract_single_field_value($this->course, 'node', 'field_int_sem_int');

    // Added logic in to handle cached values.
    // @TODO remove during code cleanup.
    $libxmlErrflag = libxml_use_internal_errors(TRUE);
    $is_xml = simplexml_load_string($intake);
    if (isset($is_xml->semesterintake)) {
      $variables = [
        'node' => $this->course,
      ];

      $intake = vu_courses_international_intake_from_xml($variables);
    }

    libxml_use_internal_errors($libxmlErrflag);

    return [
      'intake' => $intake,
    ];
  }

}
