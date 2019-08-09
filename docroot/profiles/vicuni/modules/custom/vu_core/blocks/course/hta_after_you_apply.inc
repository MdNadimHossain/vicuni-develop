<?php

/**
 * @file
 * Courses - How to Apply - After you apply block.
 */

/**
 * Class VuCoreHtaAfterYouApplyCourseBlock.
 */
class VuCoreHtaAfterYouApplyCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_YES;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE | VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - After you apply';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_after_you_apply';

}
