<?php

/**
 * @file
 * Courses - How to apply - Closed.
 */

/**
 * Class VuCoreHtaClosedCourseBlock.
 */
class VuCoreHtaClosedCourseBlock extends VuCoreCourseBlockBase {

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
  public $condOpen = VU_CBS_OPEN_NO;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_GROUP_ALL ^ VU_CBS_AQF_DOC_DEGREE ^ VU_CBS_AQF_MASTERS_DEGREE_RESEARCH;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Closed';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_closed';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $variables = [];
    $course_wrapper = entity_metadata_wrapper('node', $this->course);
    $study_area = $course_wrapper->field_study_topic_area[0]->value();

    $study_area_title = $study_area->title;
    $study_area_path = drupal_get_path_alias('node/' . $study_area->nid);
    $variables['study_area_link'] = t('other <a href="@href">@title</a> courses', [
      '@href' => $study_area_path,
      '@title' => $study_area_title,
    ]);

    return $variables;
  }

}
