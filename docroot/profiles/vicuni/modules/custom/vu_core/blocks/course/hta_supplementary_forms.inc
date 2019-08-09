<?php

/**
 * @file
 * Courses - How to Apply - Supplementary Forms block.
 */

/**
 * Class VuCoreHtaSupplementaryFormsCourseBlock.
 */
class VuCoreHtaSupplementaryFormsCourseBlock extends vuCoreCourseBlockBase {

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
  public static $info = 'How to Apply - Supplementary Forms';

  /**
   * Supplementary forms.
   *
   * @var array
   */
  protected $supplementaryForms = [];

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_supplementary_forms';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Ensure the course is either open or will be in the future.
    $this->courseIntake = $this->getCourseIntake();
    if ($this->courseIntake->isClosed() && !($this->courseIntake->openDate('vtac') || $this->courseIntake->openDate('direct'))) {
      return FALSE;
    }

    // Return TRUE if has supplementary forms.
    return !empty($this->getSupplementaryForms());
  }

  /**
   * Get Supplementary forms.
   *
   * @return array
   *   The supplementary forms.
   */
  public function getSupplementaryForms() {
    if (empty($this->supplementaryForms)) {
      $this->supplementaryForms = array_map(
        'vu_course_index_supplementary_form_link',
        array_merge(
          $this->courseIntake->supplementaryForms(),
          $this->courseIntake->refereeReports()
        )
      );
    }

    return $this->supplementaryForms;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'supplementary_forms' => $this->getSupplementaryForms(),
    ];
  }

}
