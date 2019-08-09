<?php

/**
 * Tafe Resources.
 */

/**
 * Class VuCoreTafeResourcesCourseBlock.
 */
class VuCoreTafeResourcesCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Tafe Resources';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_core_tafe_resources_info_box';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    return isset($this->course->field_unit_lev[$this->course->language]) && $this->course->field_unit_lev[$this->course->language][0]['value'] === 'tafe';
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $free_tafe_value = vu_core_extract_single_field_value($this->course, 'node', 'field_free_tafe');
    $variables = [
      'title' => t('TAFE resources'),
      'tafe_info_session_url' => '',
      'free_tafe_value' => $free_tafe_value,
    ];

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'course_information_session_links')
      ->entityCondition('bundle', 'tafe_info_session_link')
      ->fieldCondition('field_related_courses', 'target_id', $this->course->nid)
      ->range(0, 1);
    $result = $query->execute();
    if (!empty($result)) {
      $entity_id = array_keys($result['course_information_session_links'])[0];
      $entity = entity_load_single('course_information_session_links', $entity_id);
      $variables['tafe_info_session_url'] = !empty($entity->field_info_session_link[LANGUAGE_NONE][0]['url']) ? check_url($entity->field_info_session_link[LANGUAGE_NONE][0]['url']) : '';
    }

    return $variables;
  }

}
