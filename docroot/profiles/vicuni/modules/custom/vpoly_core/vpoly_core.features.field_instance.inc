<?php
/**
 * @file
 * vpoly_core.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function vpoly_core_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'course_information_session_links-tafe_info_session_link-field_info_session_link'.
  $field_instances['course_information_session_links-tafe_info_session_link-field_info_session_link'] = array(
    'bundle' => 'tafe_info_session_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please add the full url for the course information session page. For example: https://www.vu.edu.au/victoriapolytechnic/events/business-legal-leadership-it-application-sessions.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'course_information_session_links',
    'field_name' => 'field_info_session_link',
    'label' => 'Information session link',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'course_information_session_links-tafe_info_session_link-field_related_courses'.
  $field_instances['course_information_session_links-tafe_info_session_link-field_related_courses'] = array(
    'bundle' => 'tafe_info_session_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'course_information_session_links',
    'field_name' => 'field_related_courses',
    'label' => 'Related courses',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 33,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Information session link');
  t('Please add the full url for the course information session page. For example: https://www.vu.edu.au/victoriapolytechnic/events/business-legal-leadership-it-application-sessions.');
  t('Related courses');

  return $field_instances;
}
