<?php
/**
 * @file
 * vu_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function vu_core_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_addition_info|node|staff_profile|victory';
  $field_group->group_name = 'group_addition_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'victory';
  $field_group->parent_name = 'group_contact_us';
  $field_group->data = array(
    'label' => 'Assistant Additional info',
    'weight' => '10',
    'children' => array(
      0 => 'field_staff_assistant_other',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Assistant Additional info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-addition-info field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_addition_info|node|staff_profile|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assistant_details|node|staff_profile|victory';
  $field_group->group_name = 'group_assistant_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'victory';
  $field_group->parent_name = 'group_contact_us';
  $field_group->data = array(
    'label' => 'Contact details',
    'weight' => '8',
    'children' => array(
      0 => 'field_staff_assistant_name',
      1 => 'field_staff_assistant_title',
      2 => 'group_contact_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-assistant-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_assistant_details|node|staff_profile|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info|node|staff_profile|victory';
  $field_group->group_name = 'group_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'victory';
  $field_group->parent_name = 'group_assistant_details';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '13',
    'children' => array(
      0 => 'field_staff_email',
      1 => 'field_staff_fax',
      2 => 'field_staff_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-contact-info field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_info|node|staff_profile|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_us|node|staff_profile|victory';
  $field_group->group_name = 'group_contact_us';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'victory';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '5',
    'children' => array(
      0 => 'group_addition_info',
      1 => 'group_assistant_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-contact-us field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_us|node|staff_profile|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contract_info|node|content_housing|form';
  $field_group->group_name = 'group_contract_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus_housing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_extra_fields';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_contact_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contract-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contract_info|node|content_housing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_admissions|node|courses|form';
  $field_group->group_name = 'group_course_admissions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_details';
  $field_group->data = array(
    'label' => 'Admissions & pathways',
    'weight' => '9',
    'children' => array(
      0 => 'field_imp_admission_requirements',
      1 => 'field_inter_lang_requirements',
      2 => 'field_additional_requirements',
      3 => 'field_atar_indicator',
      4 => 'field_additional_information',
      5 => 'field_admission_requirements_he',
      6 => 'field_admission_requirements_se',
      7 => 'field_admission_requirements_vet',
      8 => 'field_admission_requirements_wl',
      9 => 'field_atar_minimum_entry',
      10 => 'field_atar_profile_data',
      11 => 'field_entry_requirements_in',
      12 => 'field_entry_requirements_pg',
      13 => 'field_he_study',
      14 => 'field_international_study',
      15 => 'field_se_atar_only',
      16 => 'field_se_atar_plus',
      17 => 'field_se_na',
      18 => 'field_total_study',
      19 => 'field_ve_study',
      20 => 'field_work_life',
      21 => 'field_entry_requirements_ve',
      22 => 'field_atar_adjustment',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-admissions field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_admissions|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_apply|node|courses|form';
  $field_group->group_name = 'group_course_apply';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_details';
  $field_group->data = array(
    'label' => 'How to apply',
    'weight' => '6',
    'children' => array(
      0 => 'field_how_to_apply',
      1 => 'field_int_sem_int',
      2 => 'field_how_to_apply_title',
      3 => 'field_course_start_date',
      4 => 'field_sup_application_info',
      5 => 'field_supplementary_date_info',
      6 => 'field_supplementary_inf_domestic',
      7 => 'field_supplementary_inf_int',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-apply field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_apply|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_careers|node|courses|form';
  $field_group->group_name = 'group_course_careers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_details';
  $field_group->data = array(
    'label' => 'Careers',
    'weight' => '5',
    'children' => array(
      0 => 'field_career',
      1 => 'field_imp_career',
      2 => 'field_related_success_stories',
      3 => 'field_supplementary_career_info',
      4 => 'field_career_opportunities_title',
      5 => 'field_pathways_information',
      6 => 'field_pathways_cams',
      7 => 'field_career_opportunities',
      8 => 'field_para_supp_career_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-careers field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_careers|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_details|node|courses|form';
  $field_group->group_name = 'group_course_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course Details',
    'weight' => '25',
    'children' => array(
      0 => 'group_course_admissions',
      1 => 'group_course_apply',
      2 => 'group_course_careers',
      3 => 'group_course_fees',
      4 => 'group_course_overview',
      5 => 'group_course_structure',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-course-details field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_course_details|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_fees|node|courses|form';
  $field_group->group_name = 'group_course_fees';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_details';
  $field_group->data = array(
    'label' => 'Fees & scholarships',
    'weight' => '8',
    'children' => array(
      0 => 'field_additional_costs',
      1 => 'field_international_fees',
      2 => 'field_short_fees',
      3 => 'field_fees_section_right',
      4 => 'field_free_tafe',
      5 => 'field_materials_fee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-fees field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_fees|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_overview|node|courses|form';
  $field_group->group_name = 'group_course_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_details';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '4',
    'children' => array(
      0 => 'field_imp_desc',
      1 => 'field_imp_intro',
      2 => 'field_related_courses',
      3 => 'field_short_dates_times',
      4 => 'field_sidebar_content',
      5 => 'field_description_editable',
      6 => 'field_location_other_editable',
      7 => 'field_introduction',
      8 => 'field_paragraphs_left',
      9 => 'field_paragraphs_right',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-overview field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_overview|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_structure|node|courses|form';
  $field_group->group_name = 'group_course_structure';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_details';
  $field_group->data = array(
    'label' => 'Structure',
    'weight' => '7',
    'children' => array(
      0 => 'field_completion_rules',
      1 => 'field_course_units',
      2 => 'field_imp_object',
      3 => 'field_imp_prereq_units',
      4 => 'field_imp_structure',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-structure field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_structure|node|courses|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_and_social|node|news|victory';
  $field_group->group_name = 'group_date_and_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'victory';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and social links',
    'weight' => '2',
    'children' => array(
      0 => 'field_article_date',
      1 => 'social_media_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and social links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-date-and-social',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_and_social|node|news|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|events|form';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_extra_fields';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '40',
    'children' => array(
      0 => 'field_contact_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_contact|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_essentials|node|events|victory';
  $field_group->group_name = 'group_event_essentials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'victory';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Essentials',
    'weight' => '0',
    'children' => array(
      0 => 'field_date',
      1 => 'field_event_cost',
      2 => 'multiple_event_locations',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Event Essentials',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-event-essentials',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_event_essentials|node|events|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_feature_on|node|events|form';
  $field_group->group_name = 'group_event_feature_on';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_featured';
  $field_group->data = array(
    'label' => 'Pages to Feature On',
    'weight' => '69',
    'children' => array(
      0 => 'field_feature_on',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-feature-on field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_feature_on|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_featured|node|events|form';
  $field_group->group_name = 'group_event_featured';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_extra_fields';
  $field_group->data = array(
    'label' => 'Featured Content',
    'weight' => '42',
    'children' => array(
      0 => 'field_audience',
      1 => 'group_event_feature_on',
      2 => 'group_info_sess',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-featured field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_featured|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_location|node|events|form';
  $field_group->group_name = 'group_event_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme_vu';
  $field_group->data = array(
    'label' => 'Event Location',
    'weight' => '6',
    'children' => array(
      0 => 'field_location_desc',
      1 => 'field_legacy_location',
      2 => 'field_location',
      3 => 'field_event_campus',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_location|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_related|node|events|form';
  $field_group->group_name = 'group_event_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme_vu';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '7',
    'children' => array(
      0 => 'field_related_external_links',
      1 => 'field_related_in_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_related|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_expert_guide|node|staff_profile|form';
  $field_group->group_name = 'group_expert_guide';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_staff_extra_fields';
  $field_group->data = array(
    'label' => 'Expert guide',
    'weight' => '17',
    'children' => array(
      0 => 'field_media_ready',
      1 => 'field_staff_search_snippet',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-expert-guide field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_expert_guide|node|staff_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extra_fields|node|campus_housing|form';
  $field_group->group_name = 'group_extra_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus_housing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Extra Fields',
    'weight' => '5',
    'children' => array(
      0 => 'group_contract_info',
      1 => 'group_location_info',
      2 => 'group_related_links',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-extra-fields field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_extra_fields|node|campus_housing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extra_fields|node|events|form';
  $field_group->group_name = 'group_extra_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Extra Fields',
    'weight' => '8',
    'children' => array(
      0 => 'group_event_contact',
      1 => 'group_event_featured',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-extra-fields field-group-tabs',
      ),
    ),
  );
  $field_groups['group_extra_fields|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_link_container|paragraphs_item|feature_link|default';
  $field_group->group_name = 'group_feature_link_container';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'feature_link';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Container',
    'weight' => '0',
    'children' => array(
      0 => 'field_feature_link',
      1 => 'field_feature_link_image',
      2 => 'field_feature_link_text',
      3 => 'field_feature_link_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Container',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-feature-link-container featured-entity featured-entity--choose-vu',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_feature_link_container|paragraphs_item|feature_link|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_higher_education|node|courses|full';
  $field_group->group_name = 'group_higher_education';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Applicants with higher education study',
    'weight' => '26',
    'children' => array(
      0 => 'courses_atar_he',
      1 => 'courses_atar_he_admin_req',
      2 => 'special_admissions_he',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Applicants with higher education study',
      'instance_settings' => array(
        'classes' => 'group-higher-education field-group-accordion-item accordion',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_higher_education|node|courses|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_sess|node|events|form';
  $field_group->group_name = 'group_info_sess';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_featured';
  $field_group->data = array(
    'label' => 'Course information session',
    'weight' => '71',
    'children' => array(
      0 => 'field_cours_feat_dom',
      1 => 'field_cours_feat_int',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info-sess field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_info_sess|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_info|node|content_housing|form';
  $field_group->group_name = 'group_location_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus_housing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_extra_fields';
  $field_group->data = array(
    'label' => 'Location Information',
    'weight' => '8',
    'children' => array(
      0 => 'field_location',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-location-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_location_info|node|content_housing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|page_builder|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page_builder';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '7',
    'children' => array(
      0 => 'field_facebook_images',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_metadata|node|page_builder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_details|node|success_story|featured_entity';
  $field_group->group_name = 'group_person_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'featured_entity';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'field_person_name',
      1 => 'field_course_studied',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'featured-entity__person-details',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_person_details|node|success_story|featured_entity'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_details|node|success_story|featured_node';
  $field_group->group_name = 'group_person_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'featured_node';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'field_person_name',
      1 => 'field_course_studied',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'featured-entity__person-details',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_person_details|node|success_story|featured_node'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quick_facts_container|paragraphs_item|quick_facts|default';
  $field_group->group_name = 'group_quick_facts_container';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'quick_facts';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Container',
    'weight' => '0',
    'children' => array(
      0 => 'field_body_text',
      1 => 'field_fact_links',
      2 => 'field_header_one',
      3 => 'field_icon',
      4 => 'field_header_two',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Container',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-quick-facts-container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_quick_facts_container|paragraphs_item|quick_facts|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_links|node|content_housing|form';
  $field_group->group_name = 'group_related_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus_housing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_extra_fields';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '7',
    'children' => array(
      0 => 'field_related_in_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-links field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_links|node|content_housing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secondary_education|node|courses|full';
  $field_group->group_name = 'group_secondary_education';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Applicants with recent secondary education (within the last 2 years)',
    'weight' => '24',
    'children' => array(
      0 => 'courses_atar_se',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Applicants with recent secondary education (within the last 2 years)',
      'instance_settings' => array(
        'classes' => 'group-secondary-education field-group-accordion-item accordion',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_secondary_education|node|courses|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_links|taxonomy_term|subsites|form';
  $field_group->group_name = 'group_social_media_links';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'subsites';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Override Social Links Footer',
    'weight' => '16',
    'children' => array(
      0 => 'field_block_title',
      1 => 'field_override_social_media_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-media-links field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_social_media_links|taxonomy_term|subsites|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ss_intro|node|success_story|victory';
  $field_group->group_name = 'group_ss_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'victory';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Success story intro',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'group_ss_quote',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Success story intro',
      'instance_settings' => array(
        'id' => '',
        'classes' => ' group-ss-intro field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_ss_intro|node|success_story|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ss_quote|node|success_story|victory';
  $field_group->group_name = 'group_ss_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'victory';
  $field_group->parent_name = 'group_ss_intro';
  $field_group->data = array(
    'label' => 'Success story quote',
    'weight' => '3',
    'children' => array(
      0 => 'field_excerpt',
      1 => 'field_person_name',
      2 => 'field_course_studied',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Success story quote',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-ss-quote field-group-div col-md-6',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_ss_quote|node|success_story|victory'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_assistants|node|staff_profile|form';
  $field_group->group_name = 'group_staff_assistants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_staff_extra_fields';
  $field_group->data = array(
    'label' => 'Assistants',
    'weight' => '15',
    'children' => array(
      0 => 'field_staff_assistant_name',
      1 => 'field_staff_assistant_other',
      2 => 'field_staff_assistant_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-staff-assistants field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_staff_assistants|node|staff_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_contact|node|staff_profile|form';
  $field_group->group_name = 'group_staff_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_staff_extra_fields';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '16',
    'children' => array(
      0 => 'field_staff_email',
      1 => 'field_staff_fax',
      2 => 'field_staff_phone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-staff-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_staff_contact|node|staff_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_extra_fields|node|staff_profile|form';
  $field_group->group_name = 'group_staff_extra_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Extra fields',
    'weight' => '10',
    'children' => array(
      0 => 'group_expert_guide',
      1 => 'group_staff_assistants',
      2 => 'group_staff_contact',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-staff-extra-fields field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_staff_extra_fields|node|staff_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_victory|node|campus|form';
  $field_group->group_name = 'group_theme_victory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2017 theme',
    'weight' => '6',
    'children' => array(
      0 => 'field_nav_block_style',
      1 => 'field_page_paragraphs',
      2 => 'field_title_area_feature',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2017 theme',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-theme-victory field-group-htab',
        'description' => 'Authors: Edit the page as it appears when you opened it (i.e. don\'t switch the theme between 2017 and 2015). Email webcontent@vu.edu.au if you have any questions.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_theme_victory|node|campus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_victory|node|events|form';
  $field_group->group_name = 'group_theme_victory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2017 theme',
    'weight' => '67',
    'children' => array(
      0 => 'field_cta_button',
      1 => 'field_event_cost',
      2 => 'field_lhs_components',
      3 => 'field_location_tag',
      4 => 'field_rhs_components',
      5 => 'field_rhs_related_links',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2017 theme',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-theme-victory field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_theme_victory|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_victory|node|page_builder|form';
  $field_group->group_name = 'group_theme_victory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page_builder';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2017 theme',
    'weight' => '34',
    'children' => array(
      0 => 'field_page_paragraphs',
      1 => 'field_title_area_feature',
      2 => 'field_nav_block_style',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2017 theme',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-theme-victory field-group-htab',
        'description' => 'Authors: Edit the page as it appears when you opened it (i.e. don\'t switch the theme between 2017 and 2015). Email webcontent@vu.edu.au if you have any questions.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_theme_victory|node|page_builder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_victory|node|success_story|form';
  $field_group->group_name = 'group_theme_victory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2017 theme',
    'weight' => '47',
    'children' => array(
      0 => 'field_related_links',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2017 theme',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-theme-victory field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_theme_victory|node|success_story|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_vu|node|campus|form';
  $field_group->group_name = 'group_theme_vu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2015 theme',
    'weight' => '5',
    'children' => array(
      0 => 'field_contact_info',
      1 => 'field_introduction',
      2 => 'field_location',
      3 => 'field_related_in_link',
      4 => 'field_campus_image',
      5 => 'field_campus_video',
      6 => 'field_facilities_services',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2015 theme',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-theme-vu field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_theme_vu|node|campus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_vu|node|events|form';
  $field_group->group_name = 'group_theme_vu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2015 theme',
    'weight' => '68',
    'children' => array(
      0 => 'field_cust_when',
      1 => 'group_event_location',
      2 => 'group_event_related',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2015 theme',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-theme-vu field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_theme_vu|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_vu|node|page_builder|form';
  $field_group->group_name = 'group_theme_vu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page_builder';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2015 theme',
    'weight' => '33',
    'children' => array(
      0 => 'body',
      1 => 'field_page_lvl_1_thumbnail_image',
      2 => 'field_page_sections',
      3 => 'field_page_subsite',
      4 => 'field_international_body',
      5 => 'field_page_introduction',
      6 => 'field_related_link',
      7 => 'field_image',
      8 => 'field_feature_on',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2015 theme',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-theme-vu field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_theme_vu|node|page_builder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme_vu|node|success_story|form';
  $field_group->group_name = 'group_theme_vu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_theme';
  $field_group->data = array(
    'label' => '2015 theme',
    'weight' => '46',
    'children' => array(
      0 => 'field_feature_on',
      1 => 'field_related_link',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2015 theme',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-theme-vu field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_theme_vu|node|success_story|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme|node|campus|form';
  $field_group->group_name = 'group_theme';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Theme',
    'weight' => '3',
    'children' => array(
      0 => 'group_theme_victory',
      1 => 'group_theme_vu',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-theme field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_theme|node|campus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme|node|events|form';
  $field_group->group_name = 'group_theme';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Theme',
    'weight' => '7',
    'children' => array(
      0 => 'group_theme_victory',
      1 => 'group_theme_vu',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-theme field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_theme|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme|node|page_builder|form';
  $field_group->group_name = 'group_theme';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page_builder';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Theme',
    'weight' => '2',
    'children' => array(
      0 => 'group_theme_victory',
      1 => 'group_theme_vu',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-theme field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_theme|node|page_builder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme|node|success_story|form';
  $field_group->group_name = 'group_theme';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'success_story';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Theme',
    'weight' => '12',
    'children' => array(
      0 => 'group_theme_vu',
      1 => 'group_theme_victory',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-theme field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_theme|node|success_story|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_extra_fields|node|topic_pages|form';
  $field_group->group_name = 'group_topic_extra_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic_pages';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_topic_related';
  $field_group->data = array(
    'label' => 'Extra fields',
    'weight' => '40',
    'children' => array(
      0 => 'field_related_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_topic_extra_fields|node|topic_pages|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_related|node|topic_pages|form';
  $field_group->group_name = 'group_topic_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic_pages';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '11',
    'children' => array(
      0 => 'group_topic_extra_fields',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_topic_related|node|topic_pages|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vocational_training|node|courses|full';
  $field_group->group_name = 'group_vocational_training';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Applicants with vocational education and training (VET/TAFE) study',
    'weight' => '25',
    'children' => array(
      0 => 'courses_atar_vet',
      1 => 'courses_atar_vet_admin_req',
      2 => 'special_admission_ve',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Applicants with vocational education and training (VET/TAFE) study',
      'instance_settings' => array(
        'classes' => 'group-vocational-training field-group-accordion-item accordion',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_vocational_training|node|courses|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webhook_config|node|webform|form';
  $field_group->group_name = 'group_webhook_config';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Webhook Configuration',
    'weight' => '43',
    'children' => array(
      0 => 'field_webhook_url',
      1 => 'field_webhook_submission_method',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-webhook-config field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_webhook_config|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work_life|node|courses|full';
  $field_group->group_name = 'group_work_life';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Applicants with work & life experience',
    'weight' => '27',
    'children' => array(
      0 => 'courses_atar_wl_admin_req',
      1 => 'courses_atar_work_life',
      2 => 'special_admission_worklife',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Applicants with work & life experience',
      'instance_settings' => array(
        'classes' => 'group-work-life field-group-accordion-item accordion',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_work_life|node|courses|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('2015 theme');
  t('2017 theme');
  t('Admissions & pathways');
  t('Applicants with higher education study');
  t('Applicants with recent secondary education (within the last 2 years)');
  t('Applicants with vocational education and training (VET/TAFE) study');
  t('Applicants with work & life experience');
  t('Assistant Additional info');
  t('Assistants');
  t('Careers');
  t('Contact');
  t('Contact Information');
  t('Contact details');
  t('Container');
  t('Course Details');
  t('Course information session');
  t('Date and social links');
  t('Event Essentials');
  t('Event Location');
  t('Expert guide');
  t('Extra Fields');
  t('Extra fields');
  t('Featured Content');
  t('Fees & scholarships');
  t('Group');
  t('How to apply');
  t('Location Information');
  t('Meta data');
  t('Override Social Links Footer');
  t('Overview');
  t('Pages to Feature On');
  t('Related');
  t('Structure');
  t('Success story intro');
  t('Success story quote');
  t('Theme');
  t('Webhook Configuration');

  return $field_groups;
}
