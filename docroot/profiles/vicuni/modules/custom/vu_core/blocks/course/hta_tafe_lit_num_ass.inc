<?php

/**
 * @file
 * Courses - How to Apply - TAFE literacy and numeracy assessment block.
 */

/**
 * Class VuCoreHtaTafeLitNumAssCourseBlock.
 */
class VuCoreHtaTafeLitNumAssCourseBlock extends vuCoreCourseBlockBase {

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
  public static $info = 'How to Apply - TAFE literacy and numeracy assessment';

  /**
   * {@inheritdoc}
   */
  public function view() {
    $element = [
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Prior to enrolment, all applicants will be required to complete a literacy and numeracy assessment to assist with determining eligibility and to identify learning support needs.'),
    ];

    return [
      'subject' => NULL,
      'content' => render($element),
    ];
  }

}
