<?php

/**
 * @file
 * Courses - How to apply - Apply for special admission / credits.
 */

/**
 * Class VuCoreHtaSpecialAdmissionCreditCourseBlock.
 */
class VuCoreHtaSpecialAdmissionCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE | VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_YES;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Apply for special admission / credit';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_special_admission_credit';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    /** @var \CourseIntakeList $intake */
    $intake = $this->getCourseIntake();
    if ($intake->isOpen() || ($intake->openDate('direct') || $intake->openDate('vtac'))) {
      return TRUE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $supplementary_information = '';
    $domestic_text = vu_core_extract_single_field_value($this->course, 'node', 'field_supplementary_inf_domestic');
    if (!empty($domestic_text)) {
      $supplementary_information = $domestic_text;
    }

    return [
      'supplementary_information' => $supplementary_information,
    ];
  }

}
