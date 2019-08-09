<?php

/**
 * @file
 * Course fees block (NEW).
 */

/**
 * Class VuCoreCourseFeesBlock.
 */
class VuCoreCourseFeesCourseBlock extends vuCoreCourseBlockBase {
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
  public $condType = VU_CBS_TYPE_ALL ^ VU_CBS_TYPE_NA;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Course fees';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_fees_he';

  /**
   * The fees.
   *
   * @var array
   */
  public $fees = ['fee_type' => FALSE];

  /**
   * The fee type.
   *
   * @var string
   */
  protected $feeType = '';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $this->courseIntake = $this->getCourseIntake();

    if ($this->courseIntake->isTafe()) {
      $this->fees['fee_type'] = 'VET';
      return $this->fees;
    }

    $this->feeType = $this->courseIntake->getFeeType();

    if ($this->feeType) {
      $this->fees['fee_type'] = preg_replace(
        ['/HEFULLFEE/', '/GOVTFUND/'],
        ['Full-fee', 'Commonwealth Supported Place (CSP)'],
        $this->feeType
      );
    }

    return $this->fees;
  }

  /**
   * {@inheritdoc}
   */
  public function view() {
    if (VU_CBS_TYPE_VE === $this->courseType) {
      $this->theme = 'vu_course_fees_tafe';
    }

    return [
      'subject' => NULL,
      'content' => theme($this->theme, $this->variables()),
    ];
  }

}
