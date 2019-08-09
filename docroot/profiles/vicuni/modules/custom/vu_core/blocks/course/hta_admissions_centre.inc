<?php

/**
 * @file
 * Courses - How to Apply - Admissions centre block.
 */

/**
 * Class VuCoreHtaAdmissionsCentreCourseBlock.
 */
class VuCoreHtaAdmissionsCentreCourseBlock extends vuCoreCourseBlockBase {

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
  public static $info = 'How to Apply - Admissions centre';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_admissions_centre';

}
