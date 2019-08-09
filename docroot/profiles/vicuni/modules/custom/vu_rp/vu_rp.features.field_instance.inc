<?php
/**
 * @file
 * vu_rp.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function vu_rp_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'comment-comment_node_researcher_profile-comment_body'.
  $field_instances['comment-comment_node_researcher_profile-comment_body'] = array(
    'bundle' => 'comment_node_researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_academic_roles'.
  $field_instances['node-researcher_profile-field_rp_academic_roles'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 48,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 102,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_academic_roles',
    'label' => 'Academic roles',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => 'rp_academic_role',
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 45,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 70,
        'related_links' => 29,
        'rp_academic_role' => 30,
        'rp_award' => 73,
        'rp_funding' => 32,
        'rp_industry_roles' => 75,
        'rp_keynote' => 76,
        'rp_media_appearance' => 77,
        'rp_membership' => 78,
        'rp_ota' => 79,
        'rp_publication' => 33,
        'rp_supervision' => 35,
        'section' => 36,
        'success_story' => 37,
        'system_alert_box' => 38,
        'video' => 39,
        'wysiwyg' => 40,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Academic roles',
      'title_multiple' => 'Academic roles',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 38,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_available_to_media'.
  $field_instances['node-researcher_profile-field_rp_available_to_media'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 80,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_available_to_media',
    'label' => '4. Are you available for media queries?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_awards'.
  $field_instances['node-researcher_profile-field_rp_awards'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 54,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 101,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_awards',
    'label' => 'Awards',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => 'rp_award',
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 47,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 72,
        'related_links' => 29,
        'rp_academic_role' => 30,
        'rp_award' => 31,
        'rp_funding' => 33,
        'rp_industry_roles' => 34,
        'rp_keynote' => 78,
        'rp_media_appearance' => 79,
        'rp_membership' => 80,
        'rp_ota' => 81,
        'rp_publication' => 35,
        'rp_supervision' => 37,
        'section' => 38,
        'success_story' => 39,
        'system_alert_box' => 40,
        'video' => 41,
        'wysiwyg' => 42,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Award',
      'title_multiple' => 'Awards',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_biography'.
  $field_instances['node-researcher_profile-field_rp_biography'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 'researcher',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_biography',
    'label' => 'Your biography',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filter_token' => 0,
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'migrated_content' => 0,
          'php_code' => 0,
          'plain_text' => 0,
          'researcher' => 'researcher',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filter_token' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'migrated_content' => array(
              'weight' => -6,
            ),
            'php_code' => array(
              'weight' => -5,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
            'researcher' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 3000,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_conversation_profile'.
  $field_instances['node-researcher_profile-field_rp_conversation_profile'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To include a link to your profile on the Conversation, copy and paste the URL of your profile. Please ensure https:// is included in the link.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 114,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 88,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_conversation_profile',
    'label' => '9. The Conversation profile link',
    'required' => 0,
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
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_expertise'.
  $field_instances['node-researcher_profile-field_rp_expertise'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 72,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 83,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_expertise',
    'label' => 'Areas of expertise',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => 0,
        'entityreference_autocreate' => array(
          'active' => 1,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_facebook'.
  $field_instances['node-researcher_profile-field_rp_facebook'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To include a link to your facebook page, copy and paste the URL for your page. Please ensure https:// is included in the link.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 79,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_facebook',
    'label' => '7. Facebook profile link',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_first_name'.
  $field_instances['node-researcher_profile-field_rp_first_name'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 101,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 76,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_first_name',
    'label' => 'First name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_has_academic_roles'.
  $field_instances['node-researcher_profile-field_rp_has_academic_roles'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'You can include current or past roles.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 91,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 86,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_academic_roles',
    'label' => '1. Provide at least one key academic role?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_has_awards'.
  $field_instances['node-researcher_profile-field_rp_has_awards'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 93,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 97,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_awards',
    'label' => '3. Do you have any awards to add?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_has_key_industry'.
  $field_instances['node-researcher_profile-field_rp_has_key_industry'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 92,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 71,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_key_industry',
    'label' => '2. Do you have any key industry, community or government roles to add?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 39,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_has_keynote_invitations'.
  $field_instances['node-researcher_profile-field_rp_has_keynote_invitations'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 94,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 72,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_keynote_invitations',
    'label' => '4. Do you have any invited keynote speeches to add?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 43,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_has_media_appearances'.
  $field_instances['node-researcher_profile-field_rp_has_media_appearances'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 95,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_media_appearances',
    'label' => '6. Do you have any media appearances to add?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 47,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_has_memberships'.
  $field_instances['node-researcher_profile-field_rp_has_memberships'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 115,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_memberships',
    'label' => '5. Do you have any professional memberships to add?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_has_ota'.
  $field_instances['node-researcher_profile-field_rp_has_ota'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 107,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 75,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_has_ota',
    'label' => '1. Do you have any organisations to acknowledge?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 92,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_industry_roles'.
  $field_instances['node-researcher_profile-field_rp_industry_roles'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 50,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 103,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_industry_roles',
    'label' => 'Industry roles',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => 'rp_industry_roles',
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 46,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 71,
        'related_links' => 29,
        'rp_academic_role' => 30,
        'rp_award' => 74,
        'rp_funding' => 32,
        'rp_industry_roles' => 33,
        'rp_keynote' => 77,
        'rp_media_appearance' => 78,
        'rp_membership' => 79,
        'rp_ota' => 80,
        'rp_publication' => 34,
        'rp_supervision' => 36,
        'section' => 37,
        'success_story' => 38,
        'system_alert_box' => 39,
        'video' => 40,
        'wysiwyg' => 41,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Industry roles',
      'title_multiple' => 'Industry roles',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_institute_best_align'.
  $field_instances['node-researcher_profile-field_rp_institute_best_align'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 116,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_institute_best_align',
    'label' => 'Which VU research institute does your research best align to',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 28,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_institute_primary'.
  $field_instances['node-researcher_profile-field_rp_institute_primary'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 71,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 87,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_institute_primary',
    'label' => '11. Which VU research institute do you belong to?',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_job_title'.
  $field_instances['node-researcher_profile-field_rp_job_title'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<b>**</b>This Field is limited to 120 characters.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 118,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_job_title',
    'label' => 'Your position at VU',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_job_title_variation'.
  $field_instances['node-researcher_profile-field_rp_job_title_variation'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 105,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 78,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_job_title_variation',
    'label' => 'Do you wish to provide a more descriptive or accurate position?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_keynotes'.
  $field_instances['node-researcher_profile-field_rp_keynotes'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 57,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 100,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_keynotes',
    'label' => 'Keynote speaker invitations',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => 'rp_keynote',
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 48,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 73,
        'related_links' => 29,
        'rp_academic_role' => 30,
        'rp_award' => 31,
        'rp_funding' => 33,
        'rp_industry_roles' => 34,
        'rp_keynote' => 35,
        'rp_media_appearance' => 80,
        'rp_membership' => 81,
        'rp_ota' => 82,
        'rp_publication' => 36,
        'rp_supervision' => 38,
        'section' => 39,
        'success_story' => 40,
        'system_alert_box' => 41,
        'video' => 42,
        'wysiwyg' => 43,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Keynote',
      'title_multiple' => 'Keynotes',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_last_name'.
  $field_instances['node-researcher_profile-field_rp_last_name'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 102,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 80,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_last_name',
    'label' => 'Last name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_linkedin'.
  $field_instances['node-researcher_profile-field_rp_linkedin'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To include a link to your LinkedIn profile, copy and paste the URL for your profile. Please ensure https:// is included in the link.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 81,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_linkedin',
    'label' => '8. Linkedin profile link',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_media'.
  $field_instances['node-researcher_profile-field_rp_media'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 62,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 98,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_media',
    'label' => 'Media appearances',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => 'rp_media_appearance',
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 50,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 75,
        'related_links' => 29,
        'rp_academic_role' => 30,
        'rp_award' => 31,
        'rp_funding' => 33,
        'rp_industry_roles' => 34,
        'rp_keynote' => 35,
        'rp_media_appearance' => 36,
        'rp_membership' => 37,
        'rp_ota' => 84,
        'rp_publication' => 38,
        'rp_supervision' => 40,
        'section' => 41,
        'success_story' => 42,
        'system_alert_box' => 43,
        'video' => 44,
        'wysiwyg' => 45,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Media appearance',
      'title_multiple' => 'Media appearances',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 48,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_memberships'.
  $field_instances['node-researcher_profile-field_rp_memberships'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 59,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 99,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_memberships',
    'label' => 'Professional memberships',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => 'rp_membership',
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 49,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 74,
        'related_links' => 29,
        'rp_academic_role' => 30,
        'rp_award' => 31,
        'rp_funding' => 33,
        'rp_industry_roles' => 34,
        'rp_keynote' => 35,
        'rp_media_appearance' => 81,
        'rp_membership' => 36,
        'rp_ota' => 83,
        'rp_publication' => 37,
        'rp_supervision' => 39,
        'section' => 40,
        'success_story' => 41,
        'system_alert_box' => 42,
        'video' => 43,
        'wysiwyg' => 44,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Membership',
      'title_multiple' => 'Memberships',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_name_variation'.
  $field_instances['node-researcher_profile-field_rp_name_variation'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 100,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 84,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_name_variation',
    'label' => 'Do you wish to use',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_ota'.
  $field_instances['node-researcher_profile-field_rp_ota'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 108,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_ota',
    'label' => 'Organisation to acknowledge',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => 'rp_ota',
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 5,
        'chat_box' => 6,
        'component_row' => 7,
        'component_section' => 8,
        'course_browse' => 9,
        'course_search' => 10,
        'events' => 11,
        'existing_event' => 12,
        'external_link' => 13,
        'feature_link' => 15,
        'featured_news_items' => 14,
        'find_media_expert' => 16,
        'image' => 17,
        'image_background' => 18,
        'important_dates' => 19,
        'internal_link' => 20,
        'library_opening_hours' => 21,
        'library_search' => 22,
        'link_external' => 23,
        'link_internal' => 24,
        'link_phone_number' => 25,
        'new_event' => 26,
        'node_ref_paragraph' => 27,
        'page_intro' => 28,
        'promo_banner' => 29,
        'quick_facts' => 30,
        'related_links' => 31,
        'rp_academic_role' => 32,
        'rp_award' => 33,
        'rp_funding' => 34,
        'rp_industry_roles' => 35,
        'rp_keynote' => 36,
        'rp_media_appearance' => 37,
        'rp_membership' => 38,
        'rp_ota' => 39,
        'rp_publication' => 40,
        'rp_supervision' => 41,
        'section' => 42,
        'success_story' => 43,
        'system_alert_box' => 44,
        'video' => 45,
        'wysiwyg' => 46,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Organisation to acknowledge',
      'title_multiple' => 'Organisations to acknowledge',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 93,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_phone'.
  $field_instances['node-researcher_profile-field_rp_phone'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 113,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 85,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_phone',
    'label' => '5. Phone number',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_photo'.
  $field_instances['node-researcher_profile-field_rp_photo'] = array(
    'bundle' => 'researcher_profile',
    'deleted' => 0,
    'description' => '<p>Your photo will appear in both your profile and search results. The system will automatically scale, re-size or crop to fit the space required.</p>
<p>Before you upload the image file make sure the:</p>
<ul>
<li>image is landscape orientation</li>
<li>image size is minimum 800px width</li>
<li>file size is less than 500KB</li>
<li>file format is .jpg or .jpeg</li>
<li>file name follows the convention [givenname]-[familyname].jpg e.g. peter-dawkins.jpg</li>
</ul>
<p>Note there should be no spaces in the file name - use a dash instead and only use lowercase letters.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 74,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_photo',
    'label' => 'Upload photo',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'rp/photo',
      'file_extensions' => 'jpg jpeg',
      'max_filesize' => '5MB',
      'max_resolution' => '',
      'min_resolution' => '300x300',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_post_nominal'.
  $field_instances['node-researcher_profile-field_rp_post_nominal'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You can include national honours and orders or legal awards.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 108,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_post_nominal',
    'label' => '3. Post nominal letters',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_qualification'.
  $field_instances['node-researcher_profile-field_rp_qualification'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 104,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_qualification',
    'label' => 'Qualification',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_related_links'.
  $field_instances['node-researcher_profile-field_rp_related_links'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 75,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 89,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_related_links',
    'label' => 'Related links',
    'required' => 0,
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
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 255,
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
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_research_repo_link'.
  $field_instances['node-researcher_profile-field_rp_research_repo_link'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Find your full list of publications on the VU Research Repository page, then copy and paste the URL',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 76,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 90,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_research_repo_link',
    'label' => '1. What is the link to your full list of publications on the VU Research Repository?',
    'required' => 0,
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
      'enable_tokens' => 0,
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
      'weight' => 88,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_shorter_biography'.
  $field_instances['node-researcher_profile-field_rp_shorter_biography'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Maximum 60 words, less than 50 preferred. No special formatting or hyperlinks can be included.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 110,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_shorter_biography',
    'label' => '3. Provide a short description of you',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'migrated_content' => 'migrated_content',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'researcher' => 'researcher',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'migrated_content' => array(
              'weight' => -6,
            ),
            'php_code' => array(
              'weight' => -5,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
            'researcher' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 400,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 36,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_sup_is_available'.
  $field_instances['node-researcher_profile-field_rp_sup_is_available'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Based on your answer a flag will be displayed indicating your availability and searches for a supervisor will or won\'t include your profile.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 79,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 95,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_sup_is_available',
    'label' => '1. Are you available to supervise research students at VU?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 97,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_sup_other'.
  $field_instances['node-researcher_profile-field_rp_sup_other'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'e.g. For your completed supervisions provide a summary of the number of students, the study level, institution and your role. If you\'ve supervised international students (either on-shore or in another country), you may wish to include this.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 106,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_sup_other',
    'label' => '4. If you have supervised research students at other organisations please provide some details of your experience',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 100,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rp_teaching_experience'.
  $field_instances['node-researcher_profile-field_rp_teaching_experience'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 'researcher',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 63,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_teaching_experience',
    'label' => 'Teaching activities & experience',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filter_token' => 0,
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'migrated_content' => 0,
          'php_code' => 0,
          'plain_text' => 0,
          'researcher' => 'researcher',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filter_token' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'migrated_content' => array(
              'weight' => -6,
            ),
            'php_code' => array(
              'weight' => -5,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
            'researcher' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 3000,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 101,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_title'.
  $field_instances['node-researcher_profile-field_rp_title'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will appear to the left of your first name e.g. Dr, Professor',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 107,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_title',
    'label' => '2. Your title',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_twitter'.
  $field_instances['node-researcher_profile-field_rp_twitter'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To include a link to your Twitter profile, provide your Twitter handle e.g. @JaneRoberts',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 91,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_twitter',
    'label' => '6. Twitter handle',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rp_use_photo'.
  $field_instances['node-researcher_profile-field_rp_use_photo'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 81,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 92,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rp_use_photo',
    'label' => '13. Do you wish to include a photo on the VU website?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_email'.
  $field_instances['node-researcher_profile-field_rpa_email'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 110,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 93,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_email',
    'label' => '4. Email address',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_first_name'.
  $field_instances['node-researcher_profile-field_rpa_first_name'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 96,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 94,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_first_name',
    'label' => 'First name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_funding'.
  $field_instances['node-researcher_profile-field_rpa_funding'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 105,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_funding',
    'label' => 'Funding',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => 'rp_funding',
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 41,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'quick_facts' => 66,
        'related_links' => 29,
        'rp_academic_role' => 68,
        'rp_award' => 69,
        'rp_funding' => 30,
        'rp_industry_roles' => 71,
        'rp_keynote' => 72,
        'rp_media_appearance' => 73,
        'rp_membership' => 74,
        'rp_ota' => 75,
        'rp_publication' => 31,
        'rp_supervision' => 77,
        'section' => 32,
        'success_story' => 33,
        'system_alert_box' => 34,
        'video' => 35,
        'wysiwyg' => 36,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Funding',
      'title_multiple' => 'Fundings',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 91,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_job_title'.
  $field_instances['node-researcher_profile-field_rpa_job_title'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The VU system has your position as:',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 103,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 96,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_job_title',
    'label' => '12. What is your primary position at VU?',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_last_name'.
  $field_instances['node-researcher_profile-field_rpa_last_name'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 97,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 82,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_last_name',
    'label' => 'Last name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_middle_name'.
  $field_instances['node-researcher_profile-field_rpa_middle_name'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 98,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_middle_name',
    'label' => 'Middle name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_orcid_id'.
  $field_instances['node-researcher_profile-field_rpa_orcid_id'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To include a link to your ORCID profile, provide your ORCID identifier. e.g. 0000-0002-1825-0096',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 109,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_orcid_id',
    'label' => '10. ORCID identifier',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rpa_preferred_name'.
  $field_instances['node-researcher_profile-field_rpa_preferred_name'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 99,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 68,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_preferred_name',
    'label' => 'Preferred first name',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_publications'.
  $field_instances['node-researcher_profile-field_rpa_publications'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 106,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_publications',
    'label' => 'Publications',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'related_links' => -1,
        'rp_funding' => -1,
        'rp_publication' => 'rp_publication',
        'rp_supervision' => -1,
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'chat_box' => 5,
        'component_row' => 6,
        'component_section' => 7,
        'course_browse' => 8,
        'course_search' => 9,
        'events' => 10,
        'existing_event' => 11,
        'external_link' => 12,
        'feature_link' => 14,
        'featured_news_items' => 13,
        'find_media_expert' => 15,
        'image' => 16,
        'image_background' => 17,
        'important_dates' => 18,
        'internal_link' => 19,
        'library_opening_hours' => 20,
        'library_search' => 21,
        'link_external' => 22,
        'link_internal' => 23,
        'link_phone_number' => 24,
        'new_event' => 25,
        'node_ref_paragraph' => 26,
        'page_intro' => 27,
        'promo_banner' => 28,
        'related_links' => 29,
        'rp_funding' => 65,
        'rp_publication' => 30,
        'rp_supervision' => 67,
        'section' => 31,
        'success_story' => 32,
        'system_alert_box' => 33,
        'video' => 34,
        'wysiwyg' => 35,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'publication',
      'title_multiple' => 'Publications',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 91,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_staff_id'.
  $field_instances['node-researcher_profile-field_rpa_staff_id'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 112,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_staff_id',
    'label' => 'Staff ID',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 9,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_sup_completed'.
  $field_instances['node-researcher_profile-field_rpa_sup_completed'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 88,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_sup_completed',
    'label' => 'Completed supervision',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => 'rp_supervision',
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 5,
        'chat_box' => 6,
        'component_row' => 7,
        'component_section' => 8,
        'course_browse' => 9,
        'course_search' => 10,
        'events' => 11,
        'existing_event' => 12,
        'external_link' => 13,
        'feature_link' => 15,
        'featured_news_items' => 14,
        'find_media_expert' => 16,
        'image' => 17,
        'image_background' => 18,
        'important_dates' => 19,
        'internal_link' => 20,
        'library_opening_hours' => 21,
        'library_search' => 22,
        'link_external' => 23,
        'link_internal' => 24,
        'link_phone_number' => 25,
        'new_event' => 26,
        'node_ref_paragraph' => 27,
        'page_intro' => 28,
        'promo_banner' => 29,
        'quick_facts' => 30,
        'related_links' => 31,
        'rp_academic_role' => 32,
        'rp_award' => 33,
        'rp_funding' => 34,
        'rp_industry_roles' => 35,
        'rp_keynote' => 36,
        'rp_media_appearance' => 37,
        'rp_membership' => 38,
        'rp_ota' => 84,
        'rp_publication' => 39,
        'rp_supervision' => 40,
        'section' => 41,
        'success_story' => 42,
        'system_alert_box' => 43,
        'video' => 44,
        'wysiwyg' => 45,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Completed supervision',
      'title_multiple' => 'Completed supervisions',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 98,
    ),
  );

  // Exported field_instance: 'node-researcher_profile-field_rpa_sup_current'.
  $field_instances['node-researcher_profile-field_rpa_sup_current'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 90,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpa_sup_current',
    'label' => 'Current supervision',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'accordion' => -1,
        'bean_ref_paragraph' => -1,
        'block_ref_paragraph' => -1,
        'campus_maps' => -1,
        'chat_box' => -1,
        'component_row' => -1,
        'component_section' => -1,
        'course_browse' => -1,
        'course_search' => -1,
        'events' => -1,
        'existing_event' => -1,
        'external_link' => -1,
        'feature_link' => -1,
        'featured_news_items' => -1,
        'find_media_expert' => -1,
        'image' => -1,
        'image_background' => -1,
        'important_dates' => -1,
        'internal_link' => -1,
        'library_opening_hours' => -1,
        'library_search' => -1,
        'link_external' => -1,
        'link_internal' => -1,
        'link_phone_number' => -1,
        'new_event' => -1,
        'node_ref_paragraph' => -1,
        'page_intro' => -1,
        'promo_banner' => -1,
        'quick_facts' => -1,
        'related_links' => -1,
        'rp_academic_role' => -1,
        'rp_award' => -1,
        'rp_funding' => -1,
        'rp_industry_roles' => -1,
        'rp_keynote' => -1,
        'rp_media_appearance' => -1,
        'rp_membership' => -1,
        'rp_ota' => -1,
        'rp_publication' => -1,
        'rp_supervision' => 'rp_supervision',
        'section' => -1,
        'success_story' => -1,
        'system_alert_box' => -1,
        'video' => -1,
        'wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'accordion' => 2,
        'bean_ref_paragraph' => 3,
        'block_ref_paragraph' => 4,
        'campus_maps' => 5,
        'chat_box' => 6,
        'component_row' => 7,
        'component_section' => 8,
        'course_browse' => 9,
        'course_search' => 10,
        'events' => 11,
        'existing_event' => 12,
        'external_link' => 13,
        'feature_link' => 15,
        'featured_news_items' => 14,
        'find_media_expert' => 16,
        'image' => 17,
        'image_background' => 18,
        'important_dates' => 19,
        'internal_link' => 20,
        'library_opening_hours' => 21,
        'library_search' => 22,
        'link_external' => 23,
        'link_internal' => 24,
        'link_phone_number' => 25,
        'new_event' => 26,
        'node_ref_paragraph' => 27,
        'page_intro' => 28,
        'promo_banner' => 29,
        'quick_facts' => 30,
        'related_links' => 31,
        'rp_academic_role' => 32,
        'rp_award' => 33,
        'rp_funding' => 34,
        'rp_industry_roles' => 35,
        'rp_keynote' => 36,
        'rp_media_appearance' => 37,
        'rp_membership' => 38,
        'rp_ota' => 84,
        'rp_publication' => 39,
        'rp_supervision' => 40,
        'section' => 41,
        'success_story' => 42,
        'system_alert_box' => 43,
        'video' => 44,
        'wysiwyg' => 45,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Current supervision',
      'title_multiple' => 'Current supervisions',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 99,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rpc_publication_count'.
  $field_instances['node-researcher_profile-field_rpc_publication_count'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 109,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpc_publication_count',
    'label' => 'Publication count',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 89,
    ),
  );

  // Exported field_instance:
  // 'node-researcher_profile-field_rpc_publication_type_count'.
  $field_instances['node-researcher_profile-field_rpc_publication_type_count'] = array(
    'bundle' => 'researcher_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 117,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_rpc_publication_type_count',
    'label' => 'Publication count per type',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 90,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-find_researcher-field_researcher_link'.
  $field_instances['paragraphs_item-find_researcher-field_researcher_link'] = array(
    'bundle' => 'find_researcher',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Display \'Find a researcher\' Link.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_researcher_link',
    'label' => 'Enable researcher Link',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_academic_role-field_rp_ar_organisation'.
  $field_instances['paragraphs_item-rp_academic_role-field_rp_ar_organisation'] = array(
    'bundle' => 'rp_academic_role',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ar_organisation',
    'label' => 'Organisation',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_academic_role-field_rp_ar_period'.
  $field_instances['paragraphs_item-rp_academic_role-field_rp_ar_period'] = array(
    'bundle' => 'rp_academic_role',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 9,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ar_period',
    'label' => 'Period',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-50:+0',
      ),
      'type' => 'date_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_academic_role-field_rp_ar_role'.
  $field_instances['paragraphs_item-rp_academic_role-field_rp_ar_role'] = array(
    'bundle' => 'rp_academic_role',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ar_role',
    'label' => 'Role/position held',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_award-field_rp_a_award_name'.
  $field_instances['paragraphs_item-rp_award-field_rp_a_award_name'] = array(
    'bundle' => 'rp_award',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_a_award_name',
    'label' => 'Award name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_award-field_rp_a_organisation'.
  $field_instances['paragraphs_item-rp_award-field_rp_a_organisation'] = array(
    'bundle' => 'rp_award',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_a_organisation',
    'label' => 'Organisation making award',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_award-field_rp_a_organisation_link'.
  $field_instances['paragraphs_item-rp_award-field_rp_a_organisation_link'] = array(
    'bundle' => 'rp_award',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_a_organisation_link',
    'label' => 'Link to organisation',
    'required' => 0,
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_award-field_rp_a_year'.
  $field_instances['paragraphs_item-rp_award-field_rp_a_year'] = array(
    'bundle' => 'rp_award',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_a_year',
    'label' => 'Year awarded',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-50:+0',
      ),
      'type' => 'date_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_funding-field_rp_fund_amount'.
  $field_instances['paragraphs_item-rp_funding-field_rp_fund_amount'] = array(
    'bundle' => 'rp_funding',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_fund_amount',
    'label' => 'Funding amount',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 25,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_funding-field_rp_fund_investigators'.
  $field_instances['paragraphs_item-rp_funding-field_rp_fund_investigators'] = array(
    'bundle' => 'rp_funding',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_fund_investigators',
    'label' => 'Investigators',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_funding-field_rp_fund_period_duration'.
  $field_instances['paragraphs_item-rp_funding-field_rp_fund_period_duration'] = array(
    'bundle' => 'rp_funding',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 17,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_fund_period_duration',
    'label' => 'Duration',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-9:+5',
      ),
      'type' => 'date_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_funding-field_rp_fund_sources'.
  $field_instances['paragraphs_item-rp_funding-field_rp_fund_sources'] = array(
    'bundle' => 'rp_funding',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_fund_sources',
    'label' => 'Source',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filter_token' => 0,
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'migrated_content' => 0,
          'php_code' => 0,
          'plain_text' => 0,
          'researcher' => 'researcher',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filter_token' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'migrated_content' => array(
              'weight' => -7,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'researcher' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_funding-field_rp_project_title'.
  $field_instances['paragraphs_item-rp_funding-field_rp_project_title'] = array(
    'bundle' => 'rp_funding',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_project_title',
    'label' => 'Project title',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_industry_roles-field_rp_ir_organisation'.
  $field_instances['paragraphs_item-rp_industry_roles-field_rp_ir_organisation'] = array(
    'bundle' => 'rp_industry_roles',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ir_organisation',
    'label' => 'Organisation',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_industry_roles-field_rp_ir_period'.
  $field_instances['paragraphs_item-rp_industry_roles-field_rp_ir_period'] = array(
    'bundle' => 'rp_industry_roles',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 10,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ir_period',
    'label' => 'Period',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-50:+3',
      ),
      'type' => 'date_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_industry_roles-field_rp_ir_role'.
  $field_instances['paragraphs_item-rp_industry_roles-field_rp_ir_role'] = array(
    'bundle' => 'rp_industry_roles',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ir_role',
    'label' => 'Role/position held',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_keynote-field_rp_k_details'.
  $field_instances['paragraphs_item-rp_keynote-field_rp_k_details'] = array(
    'bundle' => 'rp_keynote',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_k_details',
    'label' => 'Further details including the inviting organisation or conference and location',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_keynote-field_rp_k_title'.
  $field_instances['paragraphs_item-rp_keynote-field_rp_k_title'] = array(
    'bundle' => 'rp_keynote',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_k_title',
    'label' => 'Title of your keynote speech',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_keynote-field_rp_k_year'.
  $field_instances['paragraphs_item-rp_keynote-field_rp_k_year'] = array(
    'bundle' => 'rp_keynote',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_k_year',
    'label' => 'Year',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-25:+0',
      ),
      'type' => 'date_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_media_appearance-field_rp_ma_date'.
  $field_instances['paragraphs_item-rp_media_appearance-field_rp_ma_date'] = array(
    'bundle' => 'rp_media_appearance',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ma_date',
    'label' => 'Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-50:+0',
      ),
      'type' => 'date_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_media_appearance-field_rp_ma_link'.
  $field_instances['paragraphs_item-rp_media_appearance-field_rp_ma_link'] = array(
    'bundle' => 'rp_media_appearance',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ma_link',
    'label' => 'Link to media appearance',
    'required' => 0,
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_media_appearance-field_rp_ma_summary'.
  $field_instances['paragraphs_item-rp_media_appearance-field_rp_ma_summary'] = array(
    'bundle' => 'rp_media_appearance',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ma_summary',
    'label' => 'Summary details including the media outlet',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_media_appearance-field_rp_ma_title'.
  $field_instances['paragraphs_item-rp_media_appearance-field_rp_ma_title'] = array(
    'bundle' => 'rp_media_appearance',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ma_title',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_membership-field_rp_m_organisation'.
  $field_instances['paragraphs_item-rp_membership-field_rp_m_organisation'] = array(
    'bundle' => 'rp_membership',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_m_organisation',
    'label' => 'Organisation name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => 1,
        'entityreference_autocreate' => array(
          'active' => 1,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_membership-field_rp_m_role'.
  $field_instances['paragraphs_item-rp_membership-field_rp_m_role'] = array(
    'bundle' => 'rp_membership',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_m_role',
    'label' => 'Your role/membership level',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => 0,
        'entityreference_autocreate' => array(
          'active' => 1,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_ota-field_rp_ota_description'.
  $field_instances['paragraphs_item-rp_ota-field_rp_ota_description'] = array(
    'bundle' => 'rp_ota',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ota_description',
    'label' => 'Description of support provided',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'migrated_content' => 'migrated_content',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'researcher' => 'researcher',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'migrated_content' => array(
              'weight' => -6,
            ),
            'php_code' => array(
              'weight' => -5,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
            'researcher' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 400,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_ota-field_rp_ota_link'.
  $field_instances['paragraphs_item-rp_ota-field_rp_ota_link'] = array(
    'bundle' => 'rp_ota',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ota_link',
    'label' => 'Link to organisation',
    'required' => 0,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_ota-field_rp_ota_name'.
  $field_instances['paragraphs_item-rp_ota-field_rp_ota_name'] = array(
    'bundle' => 'rp_ota',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_ota_name',
    'label' => 'Organisation name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_publication-field_rpa_p_doi'.
  $field_instances['paragraphs_item-rp_publication-field_rpa_p_doi'] = array(
    'bundle' => 'rp_publication',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rpa_p_doi',
    'label' => 'DOI',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_publication-field_rpa_p_type'.
  $field_instances['paragraphs_item-rp_publication-field_rpa_p_type'] = array(
    'bundle' => 'rp_publication',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rpa_p_type',
    'label' => 'Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-rp_publication-field_rpa_p_year'.
  $field_instances['paragraphs_item-rp_publication-field_rpa_p_year'] = array(
    'bundle' => 'rp_publication',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 10,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rpa_p_year',
    'label' => 'Year',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_publication-field_rpc_p_citation'.
  $field_instances['paragraphs_item-rp_publication-field_rpc_p_citation'] = array(
    'bundle' => 'rp_publication',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rpc_p_citation',
    'label' => 'Citation',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_supervision-field_rp_sup_role'.
  $field_instances['paragraphs_item-rp_supervision-field_rp_sup_role'] = array(
    'bundle' => 'rp_supervision',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_sup_role',
    'label' => 'Your role',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_supervision-field_rp_sup_students'.
  $field_instances['paragraphs_item-rp_supervision-field_rp_sup_students'] = array(
    'bundle' => 'rp_supervision',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_sup_students',
    'label' => 'Number of students',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-rp_supervision-field_rp_sup_study_level'.
  $field_instances['paragraphs_item-rp_supervision-field_rp_sup_study_level'] = array(
    'bundle' => 'rp_supervision',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rp_sup_study_level',
    'label' => 'Study level',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-research_institutes-field_research_institutes_abbr'.
  $field_instances['taxonomy_term-research_institutes-field_research_institutes_abbr'] = array(
    'bundle' => 'research_institutes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_research_institutes_abbr',
    'label' => 'Abbreviation',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-research_institutes-field_research_institutes_is_f'.
  $field_instances['taxonomy_term-research_institutes-field_research_institutes_is_f'] = array(
    'bundle' => 'research_institutes',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_research_institutes_is_f',
    'label' => 'Is flagship institute',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-research_institutes-field_research_institutes_link'.
  $field_instances['taxonomy_term-research_institutes-field_research_institutes_link'] = array(
    'bundle' => 'research_institutes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Link to internal or external Research Institute page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_research_institutes_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
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
      'enable_tokens' => 0,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => 'standard_fields',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_rp_nid'.
  $field_instances['user-user-field_rp_nid'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_rp_nid',
    'label' => 'Researcher Profile',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => 0,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'user-user-field_rp_optin'.
  $field_instances['user-user-field_rp_optin'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_rp_optin',
    'label' => 'Researcher profile opt-in',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'user-user-field_rp_optout_timestamp'.
  $field_instances['user-user-field_rp_optout_timestamp'] = array(
    'bundle' => 'user',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_rp_optout_timestamp',
    'label' => 'Researcher profile opt-out date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 43,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('1. Are you available to supervise research students at VU?');
  t('1. Do you have any organisations to acknowledge?');
  t('1. Provide at least one key academic role?');
  t('1. What is the link to your full list of publications on the VU Research Repository?');
  t('10. ORCID identifier');
  t('11. Which VU research institute do you belong to?');
  t('12. What is your primary position at VU?');
  t('13. Do you wish to include a photo on the VU website?');
  t('2. Do you have any key industry, community or government roles to add?');
  t('2. Your title');
  t('3. Do you have any awards to add?');
  t('3. Post nominal letters');
  t('3. Provide a short description of you');
  t('4. Are you available for media queries?');
  t('4. Do you have any invited keynote speeches to add?');
  t('4. Email address');
  t('4. If you have supervised research students at other organisations please provide some details of your experience');
  t('5. Do you have any professional memberships to add?');
  t('5. Phone number');
  t('6. Do you have any media appearances to add?');
  t('6. Twitter handle');
  t('7. Facebook profile link');
  t('8. Linkedin profile link');
  t('9. The Conversation profile link');
  t('<b>**</b>This Field is limited to 120 characters.');
  t('<p>Your photo will appear in both your profile and search results. The system will automatically scale, re-size or crop to fit the space required.</p>
<p>Before you upload the image file make sure the:</p>
<ul>
<li>image is landscape orientation</li>
<li>image size is minimum 800px width</li>
<li>file size is less than 500KB</li>
<li>file format is .jpg or .jpeg</li>
<li>file name follows the convention [givenname]-[familyname].jpg e.g. peter-dawkins.jpg</li>
</ul>
<p>Note there should be no spaces in the file name - use a dash instead and only use lowercase letters.</p>');
  t('Abbreviation');
  t('Academic roles');
  t('Areas of expertise');
  t('Award name');
  t('Awards');
  t('Based on your answer a flag will be displayed indicating your availability and searches for a supervisor will or won\'t include your profile.');
  t('Citation');
  t('Comment');
  t('Completed supervision');
  t('Current supervision');
  t('DOI');
  t('Date');
  t('Description of support provided');
  t('Display \'Find a researcher\' Link.');
  t('Do you wish to provide a more descriptive or accurate position?');
  t('Do you wish to use');
  t('Duration');
  t('Enable researcher Link');
  t('Find your full list of publications on the VU Research Repository page, then copy and paste the URL');
  t('First name');
  t('Funding');
  t('Funding amount');
  t('Further details including the inviting organisation or conference and location');
  t('Industry roles');
  t('Investigators');
  t('Is flagship institute');
  t('Keynote speaker invitations');
  t('Last name');
  t('Link');
  t('Link to internal or external Research Institute page.');
  t('Link to media appearance');
  t('Link to organisation');
  t('Maximum 60 words, less than 50 preferred. No special formatting or hyperlinks can be included.');
  t('Media appearances');
  t('Middle name');
  t('Number of students');
  t('Organisation');
  t('Organisation making award');
  t('Organisation name');
  t('Organisation to acknowledge');
  t('Period');
  t('Preferred first name');
  t('Professional memberships');
  t('Project title');
  t('Publication count');
  t('Publication count per type');
  t('Publications');
  t('Qualification');
  t('Related links');
  t('Researcher Profile');
  t('Researcher profile opt-in');
  t('Researcher profile opt-out date');
  t('Role/position held');
  t('Source');
  t('Staff ID');
  t('Study level');
  t('Summary details including the media outlet');
  t('Teaching activities & experience');
  t('The VU system has your position as:');
  t('This will appear to the left of your first name e.g. Dr, Professor');
  t('Title');
  t('Title of your keynote speech');
  t('To include a link to your LinkedIn profile, copy and paste the URL for your profile. Please ensure https:// is included in the link.');
  t('To include a link to your ORCID profile, provide your ORCID identifier. e.g. 0000-0002-1825-0096');
  t('To include a link to your Twitter profile, provide your Twitter handle e.g. @JaneRoberts');
  t('To include a link to your facebook page, copy and paste the URL for your page. Please ensure https:// is included in the link.');
  t('To include a link to your profile on the Conversation, copy and paste the URL of your profile. Please ensure https:// is included in the link.');
  t('Type');
  t('Upload photo');
  t('Which VU research institute does your research best align to');
  t('Year');
  t('Year awarded');
  t('You can include current or past roles.');
  t('You can include national honours and orders or legal, academic and professional awards.');
  t('Your biography');
  t('Your position at VU');
  t('Your role');
  t('Your role/membership level');
  t('e.g. For your completed supervisions provide a summary of the number of students, the study level, institution and your role. If you\'ve supervised international students (either on-shore or in another country), you may wish to include this.');

  return $field_instances;
}
