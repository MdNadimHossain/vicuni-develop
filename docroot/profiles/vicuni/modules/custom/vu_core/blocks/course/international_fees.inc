<?php

/**
 * @file
 * Courses - International Fees.
 */

/**
 * Class VuCoreInternationalFeesCourseBlock.
 */
class VuCoreInternationalFeesCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'VU International Fees';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_int_fees';

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $fees = vu_core_extract_single_field_value($this->course, 'node', 'field_international_fees');

    // Added logic in to handle cached values.
    // @TODO remove during code cleanup.
    $libxmlErrflag = libxml_use_internal_errors(TRUE);
    $is_xml = simplexml_load_string($fees);
    if (isset($is_xml->fee)) {
      $fees = vu_courses_international_fees_from_node($this->course);
    }

    libxml_use_internal_errors($libxmlErrflag);

    return [
      'fees' => render($fees),
    ];
  }

}
