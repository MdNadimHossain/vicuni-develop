<?php

/**
 * @file
 * ATAR Student Profile.
 */

/**
 * Class VuCoreStudentProfileCourseBlock.
 */
class VuCoreDeliveryModeBlockCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Delivery Mode Block';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_delivery_mode_block';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    if (vu_feature_switches_switch_state('courses-admission-transparency')) {
      // Ensure that this works for only HE diploma courses.
      if ($this->getCourseAqf() == VU_CBS_AQF_DIPLOMA) {
        if ($this->getCourseType() != VU_CBS_TYPE_HE) {
          return FALSE;
        }
      }

      return TRUE;
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {

    // Get Atar Minimum data.
    $delivery_mode_data = vu_core_get_delivery_mode_data($this->course);

    $variables = [
      'data' => $delivery_mode_data,
    ];

    return $variables;
  }

}

/**
 * Get/Customise the Atar Minimum Data.
 */
function vu_core_get_delivery_mode_data($course) {

  $wrapper = entity_metadata_wrapper('node', $course);
  $value = $wrapper->field_imp_delivery_mode->value();
  // Add comma if multi-valued.
  $data = implode(', ', $value);
  return $data;

}
