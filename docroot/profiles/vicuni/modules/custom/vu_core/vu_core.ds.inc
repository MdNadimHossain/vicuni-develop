<?php
/**
 * @file
 * vu_core.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function vu_core_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|basic_bean|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'basic_bean';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['bean|basic_bean|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|choose_vu|featured_entity';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'choose_vu';
  $ds_fieldsetting->view_mode = 'featured_entity';
  $ds_fieldsetting->settings = array(
    'field_choose_vu_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'featured-entity__image',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_choose_vu_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'featured-entity__link',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_choose_vu_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'featured-entity__text',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'featured-entity__title',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['bean|choose_vu|featured_entity'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|hero_banner|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'hero_banner';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_hero_banner_headline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'hero-banner__header',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hero_banner_message' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_hero_banner_note' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|hero_banner|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|hero_title_box|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'hero_title_box';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_hero_banner_headline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'hero-banner__header',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hero_banner_message' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|hero_title_box|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|promo|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'promo';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_promo_brand' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-sm-4 col-sm-push-8 col-md-3 col-md-push-9 logo',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_promo_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'link',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_promo_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['bean|promo|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'contact_information|contact_information|sidebar_contact_information';
  $ds_fieldsetting->entity_type = 'contact_information';
  $ds_fieldsetting->bundle = 'contact_information';
  $ds_fieldsetting->view_mode = 'sidebar_contact_information';
  $ds_fieldsetting->settings = array(
    'field_contact_area' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_contact_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Email',
        ),
      ),
    ),
    'field_contact_phone' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Phone',
        ),
      ),
    ),
    'field_contact_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['contact_information|contact_information|sidebar_contact_information'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|pane_featured_content|carousel';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'pane_featured_content';
  $ds_fieldsetting->view_mode = 'carousel';
  $ds_fieldsetting->settings = array(
    'field_featured_more' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'btn btn-secondary pull-right',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_fieldable_pane_paragraph' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lbw-el' => 'div',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'quick-facts__carousel carousel slide',
          'ow-def-cl' => FALSE,
          'ow-at' => 'data-ride="carousel"',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'row',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'col-sm-4 item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|pane_featured_content|carousel'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|pane_featured_content|collapsable_content';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'pane_featured_content';
  $ds_fieldsetting->view_mode = 'collapsable_content';
  $ds_fieldsetting->settings = array(
    'field_fieldable_pane_paragraph' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => '<div class="collapse-toggle"></div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'featured-entity__column col-sm-4',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|pane_featured_content|collapsable_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|pane_featured_content|full';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'pane_featured_content';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_fieldable_pane_paragraph' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'featured-entity__column col-sm-4',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|pane_featured_content|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'inline_entities|course_date_time|default';
  $ds_fieldsetting->entity_type = 'inline_entities';
  $ds_fieldsetting->bundle = 'course_date_time';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_short_date_times' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['inline_entities|course_date_time|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|courses|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'courses';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'qr_code' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'admission_additional_information' => array(
      'weight' => '28',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'admission_transparency_block_' => array(
      'weight' => '35',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'applications_due_date' => array(
      'weight' => '50',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'atar_minimum_entry' => array(
      'weight' => '39',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'audience_indicator' => array(
      'weight' => '34',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_careers_block_' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_entry_req_in' => array(
      'weight' => '22',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_entry_req_pg' => array(
      'weight' => '19',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_fee_calculator_link_dom' => array(
      'weight' => '38',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_fee_calculator_link_int' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_nationally_recognised_blo' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_pathway_credits_head' => array(
      'weight' => '29',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_pathways_in_block_' => array(
      'weight' => '23',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_pathways_out_block_' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_success_story_block_' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_admission_information' => array(
      'weight' => '20',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_admission_requirements_s' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_he' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_he_admin_req' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_information' => array(
      'weight' => '16',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_requirements' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_se' => array(
      'weight' => '23',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'courses_atar_vet' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_vet_admin_req' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_wl_admin_req' => array(
      'weight' => '26',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_atar_work_life' => array(
      'weight' => '25',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_course_fees' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_disclaimer' => array(
      'weight' => '33',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_how_to_apply_title' => array(
      'weight' => '31',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'courses_pathways_and_credits' => array(
      'weight' => '30',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_related_courses' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'courses_tafe_resources' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'domestic_intakes' => array(
      'weight' => '47',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'entry_req_ve' => array(
      'weight' => '21',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'first_year_model_info_block_' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'fym_banner_block' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'international_intakes' => array(
      'weight' => '41',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Intakes',
          'lb-el' => 'strong',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'materials_fee' => array(
      'weight' => '51',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'multiple_audience_block' => array(
      'weight' => '49',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'other_locations_block' => array(
      'weight' => '52',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'request_callback_block' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'short_dates_and_times' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'special_admission_ve' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'special_admission_worklife' => array(
      'weight' => '27',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'special_admissions_he' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'student_profile' => array(
      'weight' => '36',
      'label' => 'hidden',
      'format' => 'default',
    ),
    've_delivery_mode' => array(
      'weight' => '43',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    've_duration_block' => array(
      'weight' => '40',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'vu_core_international_fees' => array(
      'weight' => '48',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Fees',
          'lb-el' => 'strong',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-item',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'vu_course_block_hta_int_ebrochur' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'vu_courses_hta' => array(
      'weight' => '32',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'vuo_promo' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'vucrs_cricos_code' => array(
      'weight' => '54',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'CRICOS',
        ),
      ),
    ),
    'ds_supplementary_description' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'display' => 'fields',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'ds_supplementary_careers' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'display' => 'fields',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_duration' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'strong',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_imp_delivery_mode' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'strong',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_short_fees' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Fees',
          'lb-el' => 'strong',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_unit_code' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'VU course code',
        ),
      ),
    ),
    'field_college' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Offered by',
        ),
      ),
    ),
    'field_locations' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Location',
          'lb-el' => 'strong',
          'prefix' => '<div class="course-essential-block">',
          'suffix' => '</div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-course-essentials col-md-3 col-sm-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|courses|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|events|alternate_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'events';
  $ds_fieldsetting->view_mode = 'alternate_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Date',
        ),
      ),
    ),
    'field_event_campus' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Location',
        ),
      ),
    ),
    'field_location_tag' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Location',
        ),
      ),
    ),
  );
  $export['node|events|alternate_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|events|victory';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'events';
  $ds_fieldsetting->view_mode = 'victory';
  $ds_fieldsetting->settings = array(
    'multiple_event_dates' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'multiple_event_locations' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="event-essential col-md-4"><i class="fa fa-map-marker" aria-hidden="true"><span class="header">Where:</span></i>',
          'suffix' => '</div>',
        ),
      ),
    ),
    'social_media_links' => array(
      'weight' => '8',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Share this event',
          'lb-el' => 'span',
          'lb-cl' => 'share-media-text',
          'prefix' => '<div class="event-social-media-links">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="js-staff-image-target"></div><div class="event-body-text">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_contact_info' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Contact us',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'prefix' => '<div class="events-contact-us-info">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="event-essential col-md-4"><i class="fa fa-calendar" aria-hidden="true"><span class="header">When:</span></i>',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_cta_button' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div id="event-cta-button" class="btn btn-tertiary btn-apply">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_event_cost' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="event-essential col-md-4"><i class="fa fa-usd" aria-hidden="true"><span class="header">Cost:</span></i>',
          'suffix' => '</div>',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-event-cost',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|events|victory'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|alternate_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'alternate_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|news|alternate_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|news|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|victory';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'victory';
  $ds_fieldsetting->settings = array(
    'news_img_caption' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'news_see_all_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'view-more-news',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'social_media_links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_contact_info' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Contact us',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'news-contact-us-info',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|news|victory'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page_builder|victory';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page_builder';
  $ds_fieldsetting->view_mode = 'victory';
  $ds_fieldsetting->settings = array(
    'field_key_summary_box' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['node|page_builder|victory'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|staff_profile|victory';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'staff_profile';
  $ds_fieldsetting->view_mode = 'victory';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="js-staff-image-target"></div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-body',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_staff_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-envelope"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-field-staff-email',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_staff_fax' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-fax"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-field-staff-fax',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_staff_phone' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-phone"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-field-staff-phone',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_staff_porfolio' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Portfolios',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-field-staff-porfolio',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_staff_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Areas of expertise',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-field-staff-expertise',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'expertise-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'expertise-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|staff_profile|victory'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|success_story|alternate_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'success_story';
  $ds_fieldsetting->view_mode = 'alternate_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|success_story|alternate_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|success_story|featured_entity';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'success_story';
  $ds_fieldsetting->view_mode = 'featured_entity';
  $ds_fieldsetting->settings = array(
    'field_excerpt' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'featured-entity__text',
          'fis-at' => '',
          'fis-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'featured-entity__image',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_person_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => '<span> — </span>',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'field-name-field-person-name',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_course_studied' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_featured_tile_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-name-field-featured-tile-text',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'field-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|success_story|featured_entity'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|success_story|inline_featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'success_story';
  $ds_fieldsetting->view_mode = 'inline_featured_content';
  $ds_fieldsetting->settings = array(
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|success_story|inline_featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|success_story|teaser_with_read_more';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'success_story';
  $ds_fieldsetting->view_mode = 'teaser_with_read_more';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'link class' => '',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|success_story|teaser_with_read_more'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|success_story|victory';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'success_story';
  $ds_fieldsetting->view_mode = 'victory';
  $ds_fieldsetting->settings = array(
    'field_excerpt' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'success-story-excerpt',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-md-6 image-container',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_person_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'success-story-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_course_studied' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'success-story-courses',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|success_story|victory'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_set|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_set';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'unit_search' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|unit_set|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'unit_assessment' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'enquire_now_info' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'unit_search' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|unit|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|accordion|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'accordion';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['paragraphs_item|accordion|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|accordion|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'accordion';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'field_accordion_items' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['paragraphs_item|accordion|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|bean_ref_paragraph|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'bean_ref_paragraph';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_bean_entity_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['paragraphs_item|bean_ref_paragraph|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|campus_maps|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'campus_maps';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'campus_maps' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|campus_maps|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|chat_box|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'chat_box';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'vu_chat_box' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'victory_chat_box',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|chat_box|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|component_row|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'component_row';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'field_row_components' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Row',
        ),
      ),
    ),
  );
  $export['paragraphs_item|component_row|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|component_section|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'component_section';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_component_section_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'victory-title__stripe',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|component_section|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|component_section|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'component_section';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'field_component_section_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|component_section|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|course_browse|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'course_browse';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'vu_course_browse' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'victory_link_list',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|course_browse|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|course_search|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'course_search';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'vu_course_search' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|course_search|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|events|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'events';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'events_view' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|events|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|feature_link|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'feature_link';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_feature_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'featured-entity__link',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_feature_link_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'featured-entity__image',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_feature_link_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<p>',
          'suffix' => '</p>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'featured-entity__text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_feature_link_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<h3>',
          'suffix' => '</h3>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'featured-entity__title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|feature_link|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|featured_news_items|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'featured_news_items';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'featured_news_items' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'featured-news-items-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|featured_news_items|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|fee_calculator_link_dom|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'fee_calculator_link_dom';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'fee_calculator_link_dom' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|fee_calculator_link_dom|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|fee_calculator_link_int|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'fee_calculator_link_int';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'fee_calculator_link_int' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|fee_calculator_link_int|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|fee_calculator|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'fee_calculator';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'fee_calculator' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|fee_calculator|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|find_media_expert|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'find_media_expert';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'find_a_media_expert' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|find_media_expert|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|find_media_expert|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'find_media_expert';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'find_a_media_expert' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|find_media_expert|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|important_dates|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'important_dates';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'important_dates_view' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|important_dates|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|library_opening_hours|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'library_opening_hours';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'library_hours' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|library_opening_hours|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|library_search|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'library_search';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'library_search' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|library_search|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|link_external|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'link_external';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_link_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_link_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_link_icon' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'i',
        ),
      ),
    ),
  );
  $export['paragraphs_item|link_external|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|node_ref_paragraph|collapsable_content';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'node_ref_paragraph';
  $ds_fieldsetting->view_mode = 'collapsable_content';
  $ds_fieldsetting->settings = array(
    'field_node_entity_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['paragraphs_item|node_ref_paragraph|collapsable_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|node_ref_paragraph|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'node_ref_paragraph';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_node_entity_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['paragraphs_item|node_ref_paragraph|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|page_intro|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'page_intro';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'child_page_navigation_subsites' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'child_page_navigation' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|page_intro|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|page_intro|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'page_intro';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_paragraphs_right' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|page_intro|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|qflow|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'qflow';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_qflow_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'qflow-description',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_qflow_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'qflow-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|qflow|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|quick_facts|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'quick_facts';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_body_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<p>',
          'suffix' => '</p>',
        ),
      ),
    ),
    'field_header_one' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<h2>',
          'suffix' => '</h2>',
        ),
      ),
    ),
    'field_header_two' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<h3>',
          'suffix' => '</h3>',
        ),
      ),
    ),
  );
  $export['paragraphs_item|quick_facts|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|related_links|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'related_links';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_paragraph_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'victory-related-links',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|related_links|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|related_links|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'related_links';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'field_paragraph_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related',
        ),
      ),
    ),
  );
  $export['paragraphs_item|related_links|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|section|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'section';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_section_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'victory-title__stripe',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|section|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|section|paragraphs_editor_preview';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'section';
  $ds_fieldsetting->view_mode = 'paragraphs_editor_preview';
  $ds_fieldsetting->settings = array(
    'field_paragraphs_left' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_paragraphs_right' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_section_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'h3',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|section|paragraphs_editor_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|success_story|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'success_story';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_success_story' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['paragraphs_item|success_story|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function vu_core_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'admission_additional_information';
  $ds_field->label = 'Admission Additional Information';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_admission_req_other',
    'block_render' => '3',
  );
  $export['admission_additional_information'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'admission_transparency_block_';
  $ds_field->label = 'Admission transparency (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_admission_transparency',
    'block_render' => '1',
  );
  $export['admission_transparency_block_'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'admissions_requirements_statemen';
  $ds_field->label = 'Admissions requirements statement';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_ug_admission_requirements',
    'block_render' => '3',
  );
  $export['admissions_requirements_statemen'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'applications_due_date';
  $ds_field->label = 'Applications Due Date';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_app_due_date',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['applications_due_date'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'atar_minimum_entry';
  $ds_field->label = 'Atar Minimum Entry Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_min_entry',
    'block_render' => '1',
  );
  $export['atar_minimum_entry'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'atar_student_profile_data';
  $ds_field->label = 'Atar Student Profile Data';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_profile',
    'block_render' => '1',
  );
  $export['atar_student_profile_data'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'audience_indicator';
  $ds_field->label = 'Audience Indicator';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_audience_indicator',
    'block_render' => '3',
  );
  $export['audience_indicator'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'campus_maps';
  $ds_field->label = 'Campus maps';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'campus_maps|*';
  $ds_field->properties = array(
    'block' => 'vu_core|campus_maps',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['campus_maps'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'child_page_navigation';
  $ds_field->label = 'Child page navigation';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'menu_block|main-menu-child-page-nav',
    'block_render' => '3',
  );
  $export['child_page_navigation'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'child_page_navigation_subsites';
  $ds_field->label = 'Child page navigation subsites';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'menu_block|menu-subsites-child-page-nav',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['child_page_navigation_subsites'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_already_student_block';
  $ds_field->label = 'Already VU Student (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_already_student',
    'block_render' => '1',
  );
  $export['course_already_student_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_careers_block_';
  $ds_field->label = 'Course careers (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_careers',
    'block_render' => '1',
  );
  $export['course_careers_block_'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_careers_supplementary_blo';
  $ds_field->label = 'Course careers supplementary (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_careers_supplementary',
    'block_render' => '1',
  );
  $export['course_careers_supplementary_blo'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_entry_req_in';
  $ds_field->label = 'Course: Entry Req IN';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_entry_req_international',
    'block_render' => '3',
  );
  $export['course_entry_req_in'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_entry_req_pg';
  $ds_field->label = 'Course: Entry Req PG';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_entry_req_pg',
    'block_render' => '3',
  );
  $export['course_entry_req_pg'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_fee_calculator_link_dom';
  $ds_field->label = 'Course: Fee Calculator Link - Domestic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_course_fee_calc_link_dom',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['course_fee_calculator_link_dom'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_fee_calculator_link_int';
  $ds_field->label = 'Course: Fee Calculator Link - International';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_course_fee_calc_link_int',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['course_fee_calculator_link_int'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_how_to_apply_legacy_block';
  $ds_field->label = 'How to Apply legacy (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_how_to_apply_legacy',
    'block_render' => '1',
  );
  $export['course_how_to_apply_legacy_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_international_brochure_block';
  $ds_field->label = 'International Brochure (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_international_brochure',
    'block_render' => '1',
  );
  $export['course_international_brochure_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_nationally_recognised_blo';
  $ds_field->label = 'Course nationally recognised (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_nationally_recognised',
    'block_render' => '1',
  );
  $export['course_nationally_recognised_blo'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_pathway_credits_head';
  $ds_field->label = 'Course Pathway Credits Head';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_pathways_credits_intro',
    'block_render' => '1',
  );
  $export['course_pathway_credits_head'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_pathways_in_block_';
  $ds_field->label = 'Course pathways in (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_pathways_in',
    'block_render' => '1',
  );
  $export['course_pathways_in_block_'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_pathways_out_block_';
  $ds_field->label = 'Course pathways out (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_pathways_out',
    'block_render' => '1',
  );
  $export['course_pathways_out_block_'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_success_story_block_';
  $ds_field->label = 'Course success story (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_success_story',
    'block_render' => '1',
  );
  $export['course_success_story_block_'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_admission_information';
  $ds_field->label = 'Courses: Admission Information';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_admission_information',
    'block_render' => '3',
  );
  $export['courses_admission_information'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_admission_requirements_s';
  $ds_field->label = 'Courses: Admission Requirements Summary';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_admission_req_summary',
    'block_render' => '3',
  );
  $export['courses_admission_requirements_s'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_he';
  $ds_field->label = 'Courses: ATAR HE';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'panels_mini|courses_atar_he',
    'block_render' => '3',
  );
  $export['courses_atar_he'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_he_admin_req';
  $ds_field->label = 'Courses: ATAR HE Admin Req';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_requirements_he',
    'block_render' => '3',
  );
  $export['courses_atar_he_admin_req'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_information';
  $ds_field->label = 'Courses: ATAR Information';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_information',
    'block_render' => '3',
  );
  $export['courses_atar_information'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_requirements';
  $ds_field->label = 'Courses: Atar Requirements';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_requirements',
    'block_render' => '3',
  );
  $export['courses_atar_requirements'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_se';
  $ds_field->label = 'Courses: ATAR SE';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'panels_mini|courses_atar_se',
    'block_render' => '3',
  );
  $export['courses_atar_se'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_se_admin_req';
  $ds_field->label = 'Courses: ATAR SE Admin Req';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_requirements_se',
    'block_render' => '3',
  );
  $export['courses_atar_se_admin_req'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_vet';
  $ds_field->label = 'Courses: ATAR VET';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'panels_mini|courses_atar_vet',
    'block_render' => '3',
  );
  $export['courses_atar_vet'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_vet_admin_req';
  $ds_field->label = 'Courses: ATAR VET Admin Req';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_requirements_vet',
    'block_render' => '3',
  );
  $export['courses_atar_vet_admin_req'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_wl_admin_req';
  $ds_field->label = 'Courses: ATAR WL Admin Req';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_atar_requirements_wl',
    'block_render' => '3',
  );
  $export['courses_atar_wl_admin_req'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_atar_work_life';
  $ds_field->label = 'Courses: ATAR Work Life';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'panels_mini|courses_atar_work_life',
    'block_render' => '3',
  );
  $export['courses_atar_work_life'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_course_fees';
  $ds_field->label = 'Courses: Course fees';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_course_fees',
    'block_render' => '1',
  );
  $export['courses_course_fees'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_disclaimer';
  $ds_field->label = 'Courses disclaimer';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vumain|courses_disclaimer',
    'block_render' => '3',
  );
  $export['courses_disclaimer'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_how_to_apply_title';
  $ds_field->label = 'Courses: How to apply title';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_how_to_apply_title',
    'block_render' => '3',
  );
  $export['courses_how_to_apply_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_hta_after_you_apply';
  $ds_field->label = 'Courses: HTA: After you apply';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_after_you_apply',
    'block_render' => '3',
  );
  $export['courses_hta_after_you_apply'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_hta_closed';
  $ds_field->label = 'Courses: HTA: closed';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_closed',
    'block_render' => '1',
  );
  $export['courses_hta_closed'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_hta_mid_year';
  $ds_field->label = 'Courses: HTA: Mid-year';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_mid_year',
    'block_render' => '3',
  );
  $export['courses_hta_mid_year'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_hta_special_admission';
  $ds_field->label = 'Courses: HTA: special admission / credit';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_special_admission',
    'block_render' => '1',
  );
  $export['courses_hta_special_admission'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_hta_supplementary_forms';
  $ds_field->label = 'Courses: HTA: Supplementary Forms';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_supplementary_forms',
    'block_render' => '3',
  );
  $export['courses_hta_supplementary_forms'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_hta_tafe_lit_num_ass';
  $ds_field->label = 'Courses: HTA: TAFE literacy and numeracy assessment ';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_tafe_lit_num_ass',
    'block_render' => '3',
  );
  $export['courses_hta_tafe_lit_num_ass'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_pathways_and_credits';
  $ds_field->label = 'Courses: Pathways and credits';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_pathways_credits',
    'block_render' => '3',
  );
  $export['courses_pathways_and_credits'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_related_courses';
  $ds_field->label = 'Courses: Related courses';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'panels_mini|vu_courses_related',
    'block_render' => '1',
  );
  $export['courses_related_courses'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'courses_tafe_resources';
  $ds_field->label = 'Courses: Tafe Resources';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_tafe_resources',
    'block_render' => '1',
  );
  $export['courses_tafe_resources'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'delivery_mode_block';
  $ds_field->label = 'Delivery Mode Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_delivery_mode_block',
    'block_render' => '1',
  );
  $export['delivery_mode_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'domestic_intakes';
  $ds_field->label = 'Domestic intakes';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_domestic_intakes',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['domestic_intakes'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'enquire_now_info';
  $ds_field->label = 'Enquire now info';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'unit|*';
  $ds_field->properties = array(
    'block' => 'vu_core|enquire_now_info',
    'block_render' => '1',
  );
  $export['enquire_now_info'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'entry_req_ve';
  $ds_field->label = 'Entry Req VE';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_entry_req_ve',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['entry_req_ve'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'events_view';
  $ds_field->label = 'Events view';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'events|*';
  $ds_field->properties = array(
    'block' => 'views|d57e3a8bd1c9216068ed7676a9fee517',
    'block_render' => '3',
  );
  $export['events_view'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'featured_news_items';
  $ds_field->label = 'Featured news items';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'featured_news_items|*';
  $ds_field->properties = array(
    'block' => 'views|4156c722245bd8bd0195a010e8e3c1e1',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['featured_news_items'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fee_calculator';
  $ds_field->label = 'Fee Calculator';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'fee_calculator|*';
  $ds_field->properties = array(
    'block' => 'vu_core|fee_calculator',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['fee_calculator'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fee_calculator_link_dom';
  $ds_field->label = 'Fee Calculator Link - Domestic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'fee_calculator_link_dom|*';
  $ds_field->properties = array(
    'block' => 'vu_core|fee_calculator_link_dom',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['fee_calculator_link_dom'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fee_calculator_link_int';
  $ds_field->label = 'Fee Calculator Link - International';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'fee_calculator_link_int|*';
  $ds_field->properties = array(
    'block' => 'vu_core|fee_calculator_link_int',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['fee_calculator_link_int'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'find_a_media_expert';
  $ds_field->label = 'Find a media expert';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'find_media_expert|*';
  $ds_field->properties = array(
    'block' => 'vu_core|find_media_expert',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['find_a_media_expert'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'first_year_model_info_block_';
  $ds_field->label = 'First year model info (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|course_first_year_model_info',
    'block_render' => '3',
  );
  $export['first_year_model_info_block_'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fym_banner_block';
  $ds_field->label = 'FYM Banner Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|fym_banner_course_pages-block',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['fym_banner_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'important_dates_view';
  $ds_field->label = 'Important Dates View';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'important_dates|*';
  $ds_field->properties = array(
    'block' => 'views|important_dates_list-block',
    'block_render' => '3',
  );
  $export['important_dates_view'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'international_intakes';
  $ds_field->label = 'International Intakes';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_international_intakes',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['international_intakes'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'library_hours';
  $ds_field->label = 'Library Hours';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'library_opening_hours|*';
  $ds_field->properties = array(
    'block' => 'vu_core|library_opening_hours',
    'block_render' => '1',
  );
  $export['library_hours'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'library_search';
  $ds_field->label = 'Library search';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_library_search',
    'block_render' => '1',
  );
  $export['library_search'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'materials_fee';
  $ds_field->label = 'Materials Fee Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_materials_fee',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['materials_fee'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'multiple_audience_block';
  $ds_field->label = 'Multiple Audience Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_ce_multiple_audience',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['multiple_audience_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'multiple_event_dates';
  $ds_field->label = 'Multiple event dates';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'events|*';
  $ds_field->properties = array(
    'block' => 'vu_core|all_event_dates',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['multiple_event_dates'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'multiple_event_locations';
  $ds_field->label = 'Multiple event locations';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'events|*';
  $ds_field->properties = array(
    'block' => 'vu_core|all_event_locations',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['multiple_event_locations'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'news_img_caption';
  $ds_field->label = 'News img caption';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news|*';
  $ds_field->properties = array(
    'block' => 'vu_core|news_media_img_caption',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['news_img_caption'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'news_see_all_link';
  $ds_field->label = 'News see all link';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news|*';
  $ds_field->properties = array(
    'block' => 'vu_core|news_see_all',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['news_see_all_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'news_view_more_link';
  $ds_field->label = 'News view more link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div><a href="/about-vu/news-events/news">See all news articles</a></div>
',
      'format' => 'filtered_html',
    ),
    'use_token' => 0,
  );
  $export['news_view_more_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'other_locations_block';
  $ds_field->label = 'Other Locations Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_he_other_locations',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['other_locations_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'qr_code';
  $ds_field->label = 'QR code';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|qr_code',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['qr_code'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'request_callback_block';
  $ds_field->label = 'Request Callback (block)';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|course_request_callback',
    'block_render' => '1',
  );
  $export['request_callback_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'short_dates_and_times';
  $ds_field->label = 'Short course dates and times';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_short_course_date_time',
    'block_render' => '3',
  );
  $export['short_dates_and_times'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_media_links';
  $ds_field->label = 'Social media links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news|*
events|*';
  $ds_field->properties = array(
    'block' => 'vu_core|social_media_links',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['social_media_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'special_admission_ve';
  $ds_field->label = 'Special Admission VE';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_special_ad_pro_se',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['special_admission_ve'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'special_admission_worklife';
  $ds_field->label = 'Special Admission-worklife';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_special_ad_pro_se',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['special_admission_worklife'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'special_admissions_he';
  $ds_field->label = 'Special Admissions HE';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_special_ad_pro_se',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['special_admissions_he'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'student_profile';
  $ds_field->label = 'Student Profile';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_student_profile',
    'block_render' => '3',
  );
  $export['student_profile'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'unit_assessment';
  $ds_field->label = 'Unit assessment';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'unit|*';
  $ds_field->properties = array(
    'block' => 'vu_core|unit_assessment',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['unit_assessment'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'unit_search';
  $ds_field->label = 'Unit search';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|unit_search',
    'block_render' => '3',
  );
  $export['unit_search'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 've_delivery_mode';
  $ds_field->label = 'VE Delivery Mode';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_ve_delivery_mode',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['ve_delivery_mode'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 've_duration_block';
  $ds_field->label = 'VE Duration Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_ve_duration',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['ve_duration_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_chat_box';
  $ds_field->label = 'Chat Box';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'chat_box|*';
  $ds_field->properties = array(
    'block' => 'vu_chat_now|vu_chat_landing',
    'block_render' => '1',
  );
  $export['vu_chat_box'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_core_international_fees';
  $ds_field->label = 'International Fees';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_international_fees',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['vu_core_international_fees'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_course_block_hta_int_ebrochur';
  $ds_field->label = 'VU Course Block: HTA Int ebrochure';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_intntl_ebrochure',
    'block_render' => '1',
  );
  $export['vu_course_block_hta_int_ebrochur'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_course_bock_hta_already_vu_st';
  $ds_field->label = 'VU Course Bock: HTA Already VU student';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_hta_already_vu_student',
    'block_render' => '1',
  );
  $export['vu_course_bock_hta_already_vu_st'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_course_browse';
  $ds_field->label = 'Course browse';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'course_browse|*';
  $ds_field->properties = array(
    'block' => 'views|526c0145b016a941d871e12405aa0e65',
    'block_render' => '1',
  );
  $export['vu_course_browse'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_course_search';
  $ds_field->label = 'Course search';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'course_search|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_course_search',
    'block_render' => '1',
  );
  $export['vu_course_search'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vu_courses_hta';
  $ds_field->label = 'Courses: How to apply';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'panels_mini|vu_courses_hta',
    'block_render' => '3',
  );
  $export['vu_courses_hta'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vuo_promo';
  $ds_field->label = 'VU Online Promo';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'courses|*';
  $ds_field->properties = array(
    'block' => 'vu_core|vu_cbs_vuo_promo',
    'block_render' => '1',
  );
  $export['vuo_promo'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function vu_core_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|basic_bean|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'basic_bean';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_body',
      ),
    ),
    'fields' => array(
      'field_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|basic_bean|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|choose_vu|featured_entity';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'choose_vu';
  $ds_layout->view_mode = 'featured_entity';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_choose_vu_image',
        1 => 'title_field',
        2 => 'field_choose_vu_text',
        3 => 'field_choose_vu_link',
      ),
    ),
    'fields' => array(
      'field_choose_vu_image' => 'ds_content',
      'title_field' => 'ds_content',
      'field_choose_vu_text' => 'ds_content',
      'field_choose_vu_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'featured-entity' => 'featured-entity',
        'featured-entity--choose-vu' => 'featured-entity--choose-vu',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|choose_vu|featured_entity'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|choose_vu|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'choose_vu';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'field_choose_vu_image',
        2 => 'title_field',
        3 => 'field_choose_vu_text',
        4 => 'field_choose_vu_link',
        5 => 'revision',
      ),
      'hidden' => array(
        6 => 'redirect',
        7 => 'view_mode',
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'field_choose_vu_image' => 'ds_content',
      'title_field' => 'ds_content',
      'field_choose_vu_text' => 'ds_content',
      'field_choose_vu_link' => 'ds_content',
      'revision' => 'ds_content',
      'redirect' => 'hidden',
      'view_mode' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|choose_vu|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|fym_banner_type|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'fym_banner_type';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'title',
        2 => 'revision',
        5 => 'field_fym_logo',
        6 => 'field_fym_body_text',
      ),
      'hidden' => array(
        3 => 'view_mode',
        4 => 'redirect',
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'title' => 'ds_content',
      'revision' => 'ds_content',
      'view_mode' => 'hidden',
      'redirect' => 'hidden',
      'field_fym_logo' => 'ds_content',
      'field_fym_body_text' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|fym_banner_type|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|hero_banner|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'hero_banner';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'hero_banner';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_hero_banner_headline',
        1 => 'field_hero_banner_message',
        2 => 'field_hero_banner_note',
      ),
      'ds_image' => array(
        3 => 'field_image',
      ),
    ),
    'fields' => array(
      'field_hero_banner_headline' => 'ds_content',
      'field_hero_banner_message' => 'ds_content',
      'field_hero_banner_note' => 'ds_content',
      'field_image' => 'ds_image',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_image' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|hero_banner|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|hero_title_box|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'hero_title_box';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'hero_banner';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_hero_banner_headline',
        1 => 'field_hero_banner_message',
      ),
      'ds_image' => array(
        2 => 'field_image',
      ),
    ),
    'fields' => array(
      'field_hero_banner_headline' => 'ds_content',
      'field_hero_banner_message' => 'ds_content',
      'field_image' => 'ds_image',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_image' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|hero_title_box|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|hero_title_box|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'hero_title_box';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'title',
        2 => 'field_image',
        4 => 'field_hero_banner_headline',
        5 => 'field_hero_banner_message',
        6 => 'revision',
        7 => 'view_mode',
        8 => 'redirect',
      ),
      'hidden' => array(
        3 => 'field_hero_title_box_order',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'field_hero_title_box_order' => 'hidden',
      'field_hero_banner_headline' => 'ds_content',
      'field_hero_banner_message' => 'ds_content',
      'revision' => 'ds_content',
      'view_mode' => 'ds_content',
      'redirect' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|hero_title_box|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|promo|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'promo';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'vu_promo';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_promo_brand',
        1 => 'title_field',
        2 => 'field_promo_text',
        3 => 'field_promo_link',
      ),
    ),
    'fields' => array(
      'field_promo_brand' => 'ds_content',
      'title_field' => 'ds_content',
      'field_promo_text' => 'ds_content',
      'field_promo_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'brand-background' => 'brand-background',
        'victory-promo' => 'victory-promo',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|promo|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|promo|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'promo';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'field_promo_brand',
        2 => 'title_field',
        3 => 'field_promo_text',
        4 => 'field_promo_link',
        5 => 'revision',
      ),
      'hidden' => array(
        6 => 'view_mode',
        7 => 'redirect',
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'field_promo_brand' => 'ds_content',
      'title_field' => 'ds_content',
      'field_promo_text' => 'ds_content',
      'field_promo_link' => 'ds_content',
      'revision' => 'ds_content',
      'view_mode' => 'hidden',
      'redirect' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|promo|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|quick_facts|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'quick_facts';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'field_fact_icon',
        2 => 'title_field',
        3 => 'field_fact_description',
        4 => 'revision',
      ),
      'hidden' => array(
        5 => 'view_mode',
        6 => 'redirect',
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'field_fact_icon' => 'ds_content',
      'title_field' => 'ds_content',
      'field_fact_description' => 'ds_content',
      'revision' => 'ds_content',
      'view_mode' => 'hidden',
      'redirect' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|quick_facts|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'contact_information|contact_information|sidebar_contact_information';
  $ds_layout->entity_type = 'contact_information';
  $ds_layout->bundle = 'contact_information';
  $ds_layout->view_mode = 'sidebar_contact_information';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'contact_name',
        1 => 'field_contact_title',
        2 => 'field_contact_area',
        3 => 'field_contact_phone',
        4 => 'field_contact_email',
      ),
    ),
    'fields' => array(
      'contact_name' => 'ds_content',
      'field_contact_title' => 'ds_content',
      'field_contact_area' => 'ds_content',
      'field_contact_phone' => 'ds_content',
      'field_contact_email' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['contact_information|contact_information|sidebar_contact_information'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|pane_featured_content|carousel';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'pane_featured_content';
  $ds_layout->view_mode = 'carousel';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fieldable_pane_paragraph',
        1 => 'field_featured_more',
      ),
    ),
    'fields' => array(
      'field_fieldable_pane_paragraph' => 'ds_content',
      'field_featured_more' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['fieldable_panels_pane|pane_featured_content|carousel'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|pane_featured_content|collapsable_content';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'pane_featured_content';
  $ds_layout->view_mode = 'collapsable_content';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fieldable_pane_paragraph',
      ),
    ),
    'fields' => array(
      'field_fieldable_pane_paragraph' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'featured-content-pane' => 'featured-content-pane',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['fieldable_panels_pane|pane_featured_content|collapsable_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|pane_featured_content|default';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'pane_featured_content';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fieldable_pane_paragraph',
      ),
    ),
    'fields' => array(
      'field_fieldable_pane_paragraph' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['fieldable_panels_pane|pane_featured_content|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|pane_featured_content|full';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'pane_featured_content';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fieldable_pane_paragraph',
        1 => 'field_featured_more',
      ),
    ),
    'fields' => array(
      'field_fieldable_pane_paragraph' => 'ds_content',
      'field_featured_more' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'featured-content-pane' => 'featured-content-pane',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['fieldable_panels_pane|pane_featured_content|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|audio|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video_transcript',
        1 => 'file',
      ),
    ),
    'fields' => array(
      'field_video_transcript' => 'ds_content',
      'file' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|audio|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|document|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
      ),
    ),
    'fields' => array(
      'file' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|document|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
      ),
    ),
    'fields' => array(
      'file' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|video|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_video_transcript',
      ),
    ),
    'fields' => array(
      'file' => 'ds_content',
      'field_video_transcript' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|video|full';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
        1 => 'field_video_transcript',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'field_video_transcript' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|video|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'inline_entities|course_date_time|default';
  $ds_layout->entity_type = 'inline_entities';
  $ds_layout->bundle = 'course_date_time';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_short_date_times',
      ),
    ),
    'fields' => array(
      'field_short_date_times' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['inline_entities|course_date_time|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'inline_entities|featured_success_story|default';
  $ds_layout->entity_type = 'inline_entities';
  $ds_layout->bundle = 'featured_success_story';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_ref_success_story_feature',
        1 => 'field_excerpt',
        2 => 'field_read_more_text',
      ),
    ),
    'fields' => array(
      'field_ref_success_story_feature' => 'ds_content',
      'field_excerpt' => 'ds_content',
      'field_read_more_text' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['inline_entities|featured_success_story|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|campus|victory';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'campus';
  $ds_layout->view_mode = 'victory';
  $ds_layout->layout = 'panels-raw';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'field_page_paragraphs',
      ),
    ),
    'fields' => array(
      'field_page_paragraphs' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'middle' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|campus|victory'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|courses|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'courses';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'vu_course';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'introduction' => 'div',
      'overview_right' => 'div',
      'overview_right_lower_middle' => 'div',
      'tafe_resources_block' => 'div',
      'ds_content' => 'div',
      'careers' => 'div',
      'careers_right' => 'div',
      'first_year_model_info' => 'div',
      'fees_scholarships' => 'div',
      'admission_pathways' => 'div',
      'how_to_apply' => 'div',
      'bottom' => 'div',
      'admission_pathways_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|courses|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|courses|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'courses';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'vu_course';
  $ds_layout->settings = array(
    'regions' => array(
      'introduction' => array(
        0 => 'short_dates_and_times',
      ),
      'bottom' => array(
        1 => 'qr_code',
        44 => 'courses_disclaimer',
      ),
      'overview_right' => array(
        2 => 'request_callback_block',
        4 => 'vuo_promo',
        7 => 'vu_course_block_hta_int_ebrochur',
        9 => 'fym_banner_block',
        11 => 'course_fee_calculator_link_int',
      ),
      'admission_pathways' => array(
        3 => 'courses_atar_vet',
        5 => 'courses_atar_vet_admin_req',
        6 => 'courses_atar_he',
        8 => 'special_admission_ve',
        10 => 'courses_atar_he_admin_req',
        12 => 'special_admissions_he',
        23 => 'courses_atar_information',
        24 => 'courses_atar_requirements',
        25 => 'courses_admission_requirements_s',
        26 => 'course_entry_req_pg',
        27 => 'courses_admission_information',
        28 => 'entry_req_ve',
        29 => 'course_entry_req_in',
        30 => 'course_pathways_in_block_',
        31 => 'courses_atar_se',
        32 => 'group_secondary_education',
        33 => 'courses_atar_work_life',
        34 => 'group_vocational_training',
        35 => 'courses_atar_wl_admin_req',
        36 => 'group_higher_education',
        37 => 'special_admission_worklife',
        38 => 'group_work_life',
        39 => 'admission_additional_information',
      ),
      'overview_right_lower_middle' => array(
        13 => 'ds_supplementary_description',
        14 => 'courses_related_courses',
      ),
      'tafe_resources_block' => array(
        15 => 'courses_tafe_resources',
      ),
      'careers' => array(
        16 => 'course_careers_block_',
        17 => 'course_pathways_out_block_',
      ),
      'careers_right' => array(
        18 => 'course_success_story_block_',
        19 => 'ds_supplementary_careers',
        20 => 'course_nationally_recognised_blo',
      ),
      'first_year_model_info' => array(
        21 => 'first_year_model_info_block_',
      ),
      'fees_scholarships' => array(
        22 => 'courses_course_fees',
      ),
      'pathways_credits' => array(
        40 => 'course_pathway_credits_head',
        41 => 'courses_pathways_and_credits',
      ),
      'how_to_apply' => array(
        42 => 'courses_how_to_apply_title',
        43 => 'vu_courses_hta',
      ),
      'admission_pathways_right' => array(
        45 => 'audience_indicator',
        46 => 'admission_transparency_block_',
        47 => 'student_profile',
      ),
      'fees_scholarships_right' => array(
        48 => 'field_fees_section_right',
        49 => 'course_fee_calculator_link_dom',
      ),
      'course_essentials' => array(
        50 => 'atar_minimum_entry',
        51 => 've_duration_block',
        52 => 'international_intakes',
        53 => 'field_duration',
        54 => 've_delivery_mode',
        55 => 'field_locations',
        56 => 'field_imp_delivery_mode',
        57 => 'field_short_fees',
        58 => 'domestic_intakes',
        59 => 'vu_core_international_fees',
        60 => 'multiple_audience_block',
        61 => 'applications_due_date',
        62 => 'materials_fee',
        63 => 'other_locations_block',
      ),
      'title_area_course_information' => array(
        64 => 'field_unit_code',
        65 => 'vucrs_cricos_code',
        66 => 'field_college',
      ),
      'courses_title_box_feature' => array(
        67 => 'field_title_area_feature_image',
      ),
    ),
    'fields' => array(
      'short_dates_and_times' => 'introduction',
      'qr_code' => 'bottom',
      'request_callback_block' => 'overview_right',
      'courses_atar_vet' => 'admission_pathways',
      'vuo_promo' => 'overview_right',
      'courses_atar_vet_admin_req' => 'admission_pathways',
      'courses_atar_he' => 'admission_pathways',
      'vu_course_block_hta_int_ebrochur' => 'overview_right',
      'special_admission_ve' => 'admission_pathways',
      'fym_banner_block' => 'overview_right',
      'courses_atar_he_admin_req' => 'admission_pathways',
      'course_fee_calculator_link_int' => 'overview_right',
      'special_admissions_he' => 'admission_pathways',
      'ds_supplementary_description' => 'overview_right_lower_middle',
      'courses_related_courses' => 'overview_right_lower_middle',
      'courses_tafe_resources' => 'tafe_resources_block',
      'course_careers_block_' => 'careers',
      'course_pathways_out_block_' => 'careers',
      'course_success_story_block_' => 'careers_right',
      'ds_supplementary_careers' => 'careers_right',
      'course_nationally_recognised_blo' => 'careers_right',
      'first_year_model_info_block_' => 'first_year_model_info',
      'courses_course_fees' => 'fees_scholarships',
      'courses_atar_information' => 'admission_pathways',
      'courses_atar_requirements' => 'admission_pathways',
      'courses_admission_requirements_s' => 'admission_pathways',
      'course_entry_req_pg' => 'admission_pathways',
      'courses_admission_information' => 'admission_pathways',
      'entry_req_ve' => 'admission_pathways',
      'course_entry_req_in' => 'admission_pathways',
      'course_pathways_in_block_' => 'admission_pathways',
      'courses_atar_se' => 'admission_pathways',
      'group_secondary_education' => 'admission_pathways',
      'courses_atar_work_life' => 'admission_pathways',
      'group_vocational_training' => 'admission_pathways',
      'courses_atar_wl_admin_req' => 'admission_pathways',
      'group_higher_education' => 'admission_pathways',
      'special_admission_worklife' => 'admission_pathways',
      'group_work_life' => 'admission_pathways',
      'admission_additional_information' => 'admission_pathways',
      'course_pathway_credits_head' => 'pathways_credits',
      'courses_pathways_and_credits' => 'pathways_credits',
      'courses_how_to_apply_title' => 'how_to_apply',
      'vu_courses_hta' => 'how_to_apply',
      'courses_disclaimer' => 'bottom',
      'audience_indicator' => 'admission_pathways_right',
      'admission_transparency_block_' => 'admission_pathways_right',
      'student_profile' => 'admission_pathways_right',
      'field_fees_section_right' => 'fees_scholarships_right',
      'course_fee_calculator_link_dom' => 'fees_scholarships_right',
      'atar_minimum_entry' => 'course_essentials',
      've_duration_block' => 'course_essentials',
      'international_intakes' => 'course_essentials',
      'field_duration' => 'course_essentials',
      've_delivery_mode' => 'course_essentials',
      'field_locations' => 'course_essentials',
      'field_imp_delivery_mode' => 'course_essentials',
      'field_short_fees' => 'course_essentials',
      'domestic_intakes' => 'course_essentials',
      'vu_core_international_fees' => 'course_essentials',
      'multiple_audience_block' => 'course_essentials',
      'applications_due_date' => 'course_essentials',
      'materials_fee' => 'course_essentials',
      'other_locations_block' => 'course_essentials',
      'field_unit_code' => 'title_area_course_information',
      'vucrs_cricos_code' => 'title_area_course_information',
      'field_college' => 'title_area_course_information',
      'field_title_area_feature_image' => 'courses_title_box_feature',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'introduction' => 'div',
      'overview_right' => 'div',
      'overview_right_lower_middle' => 'div',
      'tafe_resources_block' => 'div',
      'ds_content' => 'div',
      'careers' => 'div',
      'careers_right' => 'div',
      'first_year_model_info' => 'div',
      'fees_scholarships' => 'div',
      'admission_pathways' => 'div',
      'pathways_credits' => 'div',
      'how_to_apply' => 'div',
      'bottom' => 'div',
      'admission_pathways_right' => 'div',
      'fees_scholarships_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|courses|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|events|alternate_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'alternate_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_date',
        2 => 'field_event_campus',
        3 => 'field_location_tag',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_date' => 'ds_content',
      'field_event_campus' => 'ds_content',
      'field_location_tag' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|events|alternate_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|events|victory';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'victory';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'group_event_essentials',
        1 => 'field_cta_button',
        2 => 'field_date',
        4 => 'multiple_event_locations',
        6 => 'field_event_cost',
      ),
      'left' => array(
        3 => 'body',
        5 => 'field_lhs_components',
        7 => 'multiple_event_dates',
      ),
      'right' => array(
        8 => 'field_rhs_components',
        9 => 'field_contact_info',
        10 => 'field_rhs_related_links',
        11 => 'social_media_links',
      ),
    ),
    'fields' => array(
      'group_event_essentials' => 'top',
      'field_cta_button' => 'top',
      'field_date' => 'top',
      'body' => 'left',
      'multiple_event_locations' => 'top',
      'field_lhs_components' => 'left',
      'field_event_cost' => 'top',
      'multiple_event_dates' => 'left',
      'field_rhs_components' => 'right',
      'field_contact_info' => 'right',
      'field_rhs_related_links' => 'right',
      'social_media_links' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|events|victory'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|alternate_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'alternate_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_article_date',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'field_article_date' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|news|alternate_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'responsive_57_bootstrap';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'body' => 'right',
    ),
  );
  $export['node|news|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|victory';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'victory';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
        1 => 'news_img_caption',
        2 => 'group_date_and_social',
        3 => 'body',
        4 => 'social_media_links',
        5 => 'field_article_date',
        6 => 'news_see_all_link',
      ),
      'right' => array(
        7 => 'field_contact_info',
        8 => 'field_rhs_components',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'news_img_caption' => 'left',
      'group_date_and_social' => 'left',
      'body' => 'left',
      'social_media_links' => 'left',
      'field_article_date' => 'left',
      'news_see_all_link' => 'left',
      'field_contact_info' => 'right',
      'field_rhs_components' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|news|victory'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page_builder|victory';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page_builder';
  $ds_layout->view_mode = 'victory';
  $ds_layout->layout = 'panels-raw';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'field_key_summary_box',
        1 => 'field_page_paragraphs',
      ),
    ),
    'fields' => array(
      'field_key_summary_box' => 'middle',
      'field_page_paragraphs' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'middle' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|page_builder|victory'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|staff_profile|victory';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'staff_profile';
  $ds_layout->view_mode = 'victory';
  $ds_layout->layout = 'vu_staff_profile';
  $ds_layout->settings = array(
    'regions' => array(
      'bottom' => array(
        0 => 'field_page_paragraphs',
      ),
      'left' => array(
        1 => 'body',
        2 => 'field_staff_porfolio',
        3 => 'field_staff_expertise',
      ),
      'right' => array(
        4 => 'field_staff_picture',
        5 => 'group_contact_us',
        6 => 'group_assistant_details',
        7 => 'field_staff_phone',
        8 => 'group_addition_info',
        9 => 'field_staff_fax',
        10 => 'field_staff_assistant_other',
        11 => 'field_staff_assistant_name',
        12 => 'field_staff_email',
        13 => 'field_staff_assistant_title',
        14 => 'group_contact_info',
      ),
    ),
    'fields' => array(
      'field_page_paragraphs' => 'bottom',
      'body' => 'left',
      'field_staff_porfolio' => 'left',
      'field_staff_expertise' => 'left',
      'field_staff_picture' => 'right',
      'group_contact_us' => 'right',
      'group_assistant_details' => 'right',
      'field_staff_phone' => 'right',
      'group_addition_info' => 'right',
      'field_staff_fax' => 'right',
      'field_staff_assistant_other' => 'right',
      'field_staff_assistant_name' => 'right',
      'field_staff_email' => 'right',
      'field_staff_assistant_title' => 'right',
      'group_contact_info' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|staff_profile|victory'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|success_story|alternate_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'success_story';
  $ds_layout->view_mode = 'alternate_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|success_story|alternate_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|success_story|featured_entity';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'success_story';
  $ds_layout->view_mode = 'featured_entity';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_excerpt',
        2 => 'group_person_details',
        3 => 'field_featured_tile_text',
        4 => 'field_person_name',
        5 => 'field_course_studied',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_excerpt' => 'ds_content',
      'group_person_details' => 'ds_content',
      'field_featured_tile_text' => 'ds_content',
      'field_person_name' => 'ds_content',
      'field_course_studied' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'featured-entity' => 'featured-entity',
        'featured-entity--success-story' => 'featured-entity--success-story',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|success_story|featured_entity'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|success_story|inline_featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'success_story';
  $ds_layout->view_mode = 'inline_featured_content';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|success_story|inline_featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|success_story|teaser_with_read_more';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'success_story';
  $ds_layout->view_mode = 'teaser_with_read_more';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|success_story|teaser_with_read_more'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|success_story|victory';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'success_story';
  $ds_layout->view_mode = 'victory';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_ss_intro',
        2 => 'body',
        3 => 'field_image',
        4 => 'group_ss_quote',
        5 => 'field_excerpt',
        6 => 'field_person_name',
        7 => 'field_course_studied',
      ),
      'right' => array(
        1 => 'field_related_links',
      ),
    ),
    'fields' => array(
      'group_ss_intro' => 'left',
      'field_related_links' => 'right',
      'body' => 'left',
      'field_image' => 'left',
      'group_ss_quote' => 'left',
      'field_excerpt' => 'left',
      'field_person_name' => 'left',
      'field_course_studied' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|success_story|victory'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_set|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_set';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'vu_unitsets';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
      ),
      'overview_rhs' => array(
        1 => 'unit_search',
      ),
      'details' => array(
        1 => 'field_locations',
        2 => 'field_unit_lev',
        3 => 'field_unit_s_type',
        4 => 'field_unit_code',
      ),
      'structure' => array(
        5 => 'field_structure',
        6 => 'field_cricos_code',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'unit_search' => 'overview_rhs',
      'field_locations' => 'details',
      'field_unit_lev' => 'details',
      'field_unit_s_type' => 'details',
      'field_unit_code' => 'details',
      'field_structure' => 'structure',
      'field_cricos_code' => 'structure',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'overview_rhs' => 'div',
      'details' => 'div',
      'structure' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|unit_set|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'vu_unit';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
      ),
      'overview_rhs' => array(
        1 => 'enquire_now_info',
        2 => 'unit_search',
      ),
      'details' => array(
        3 => 'field_unit_code',
        4 => 'field_unit_lev',
        5 => 'field_locations',
        6 => 'field_credit_points',
        7 => 'field_prerequisites',
        8 => 'field_co_requisites',
      ),
      'learning' => array(
        9 => 'field_learning_outcomes',
      ),
      'assessment' => array(
        10 => 'unit_assessment',
      ),
      'reading' => array(
        11 => 'field_required_reading',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'enquire_now_info' => 'overview_rhs',
      'unit_search' => 'overview_rhs',
      'field_unit_code' => 'details',
      'field_unit_lev' => 'details',
      'field_locations' => 'details',
      'field_credit_points' => 'details',
      'field_prerequisites' => 'details',
      'field_co_requisites' => 'details',
      'field_learning_outcomes' => 'learning',
      'unit_assessment' => 'assessment',
      'field_required_reading' => 'reading',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'overview_rhs' => 'div',
      'details' => 'div',
      'learning' => 'div',
      'assessment' => 'div',
      'reading' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|unit|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'vu_unit';
  $ds_layout->settings = array(
    'regions' => array(
      'introduction' => array(
        0 => 'body',
        1 => 'field_unit_id',
        2 => 'field_unit_code',
        3 => 'field_unit_lev',
        4 => 'field_credit_points',
        5 => 'field_learning_outcomes',
        6 => 'field_locations_special',
        7 => 'field_prerequisites',
        8 => 'field_college',
        9 => 'field_co_requisites',
        10 => 'field_required_reading',
        11 => 'field_locations',
        12 => 'comments',
      ),
      'overview_rhs' => array(
        0 => 'unit_search',
      ),
    ),
    'fields' => array(
      'body' => 'introduction',
      'field_unit_id' => 'introduction',
      'field_unit_code' => 'introduction',
      'field_unit_lev' => 'introduction',
      'field_credit_points' => 'introduction',
      'field_learning_outcomes' => 'introduction',
      'field_locations_special' => 'introduction',
      'field_prerequisites' => 'introduction',
      'field_college' => 'introduction',
      'field_co_requisites' => 'introduction',
      'field_required_reading' => 'introduction',
      'field_locations' => 'introduction',
      'comments' => 'introduction',
      'unit_search' => 'overview_rhs',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'overview_rhs' => 'div',
      'details' => 'div',
      'learning' => 'div',
      'assessment' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|unit|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|block_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'block_view';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'webform',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'webform' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|webform|block_view'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'webform',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'webform' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|webform|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|accordion|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'accordion';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_accordion';
  $ds_layout->settings = array(
    'regions' => array(
      'title' => array(
        0 => 'title_field',
      ),
      'ds_content' => array(
        1 => 'field_body',
      ),
    ),
    'fields' => array(
      'title_field' => 'title',
      'field_body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'title' => 'div',
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|accordion|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|accordion|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'accordion';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_body',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|accordion|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|bean_ref_paragraph|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'bean_ref_paragraph';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_bean_entity_ref',
      ),
    ),
    'fields' => array(
      'field_bean_entity_ref' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|bean_ref_paragraph|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|campus_maps|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'campus_maps';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'campus_maps',
      ),
    ),
    'fields' => array(
      'campus_maps' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|campus_maps|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|campus_maps|form';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'campus_maps';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_null1',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_null1' => 'ds_content',
      '_add_existing_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|campus_maps|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|chat_box|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'chat_box';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'vu_chat_box',
      ),
    ),
    'fields' => array(
      'vu_chat_box' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|chat_box|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|component_row|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'component_row';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'middle' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_row_components',
      ),
    ),
    'fields' => array(
      'field_row_components' => 'ds_content',
    ),
  );
  $export['paragraphs_item|component_row|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|component_row|form';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'component_row';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'hidden' => array(
        0 => 'field_row_layout',
        2 => '_add_existing_field',
      ),
      'left' => array(
        1 => 'field_row_components',
      ),
    ),
    'fields' => array(
      'field_row_layout' => 'hidden',
      'field_row_components' => 'left',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['paragraphs_item|component_row|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|component_row|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'component_row';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_row_components',
        1 => 'field_row_layout',
      ),
    ),
    'fields' => array(
      'field_row_components' => 'ds_content',
      'field_row_layout' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|component_row|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|component_section|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'component_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'vu_page_section_single_column';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_component_section_title',
      ),
      'middle' => array(
        1 => 'field_component_section_content',
      ),
    ),
    'fields' => array(
      'field_component_section_title' => 'top',
      'field_component_section_content' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'middle' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|component_section|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|component_section|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'component_section';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_component_section_title',
        1 => 'field_component_section_content',
      ),
    ),
    'fields' => array(
      'field_component_section_title' => 'ds_content',
      'field_component_section_content' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|component_section|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|course_browse|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'course_browse';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'vu_course_browse',
      ),
    ),
    'fields' => array(
      'vu_course_browse' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|course_browse|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|course_search|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'course_search';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'vu_course_search',
      ),
    ),
    'fields' => array(
      'vu_course_search' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|course_search|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|events|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'events_view',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'events_view' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|events|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|feature_link|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'feature_link';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_feature_link_container',
        1 => 'field_feature_link_image',
        2 => 'field_feature_link_title',
        3 => 'field_feature_link_text',
        4 => 'field_feature_link',
      ),
    ),
    'fields' => array(
      'group_feature_link_container' => 'ds_content',
      'field_feature_link_image' => 'ds_content',
      'field_feature_link_title' => 'ds_content',
      'field_feature_link_text' => 'ds_content',
      'field_feature_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'ds_content' => array(
        'featured-entity' => 'featured-entity',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|feature_link|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|featured_news_items|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'featured_news_items';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_title',
        1 => 'featured_news_items',
      ),
    ),
    'fields' => array(
      'field_title' => 'ds_content',
      'featured_news_items' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|featured_news_items|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|fee_calculator_link_dom|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'fee_calculator_link_dom';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'fee_calculator_link_dom',
      ),
    ),
    'fields' => array(
      'fee_calculator_link_dom' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|fee_calculator_link_dom|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|fee_calculator_link_int|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'fee_calculator_link_int';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'fee_calculator_link_int',
      ),
    ),
    'fields' => array(
      'fee_calculator_link_int' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|fee_calculator_link_int|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|fee_calculator|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'fee_calculator';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_international',
        1 => 'field_instructions',
        2 => 'fee_calculator',
      ),
    ),
    'fields' => array(
      'field_international' => 'ds_content',
      'field_instructions' => 'ds_content',
      'fee_calculator' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|fee_calculator|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|find_media_expert|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'find_media_expert';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_title',
        1 => 'field_description',
        2 => 'find_a_media_expert',
      ),
    ),
    'fields' => array(
      'field_title' => 'ds_content',
      'field_description' => 'ds_content',
      'find_a_media_expert' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|find_media_expert|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|find_media_expert|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'find_media_expert';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_title',
        1 => 'field_description',
        2 => 'find_a_media_expert',
      ),
    ),
    'fields' => array(
      'field_title' => 'ds_content',
      'field_description' => 'ds_content',
      'find_a_media_expert' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|find_media_expert|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|image|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_body',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|important_dates|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'important_dates';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'important_dates_view',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'important_dates_view' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|important_dates|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|key_summary_box|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'key_summary_box';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_icon',
        1 => 'field_header',
        2 => 'field_key_summary_body',
        3 => 'field_key_summary_link',
      ),
    ),
    'fields' => array(
      'field_icon' => 'ds_content',
      'field_header' => 'ds_content',
      'field_key_summary_body' => 'ds_content',
      'field_key_summary_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|key_summary_box|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|key_summary_component|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'key_summary_component';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_key_summary_row',
      ),
    ),
    'fields' => array(
      'field_key_summary_row' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|key_summary_component|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|large_logo|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'large_logo';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_large_logo_image',
      ),
    ),
    'fields' => array(
      'field_large_logo_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|large_logo|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|library_opening_hours|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'library_opening_hours';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'library_hours',
      ),
    ),
    'fields' => array(
      'library_hours' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|library_opening_hours|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|library_search|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'library_search';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'library_search',
      ),
    ),
    'fields' => array(
      'library_search' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|library_search|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|link_external|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'link_external';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_link_icon',
        1 => 'field_link_link',
        2 => 'field_link_text',
      ),
    ),
    'fields' => array(
      'field_link_icon' => 'ds_content',
      'field_link_link' => 'ds_content',
      'field_link_text' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|link_external|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|link_internal|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'link_internal';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_link_icon',
        1 => 'field_node_entity_ref',
        2 => 'field_link_text',
      ),
    ),
    'fields' => array(
      'field_link_icon' => 'ds_content',
      'field_node_entity_ref' => 'ds_content',
      'field_link_text' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|link_internal|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|map_component|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'map_component';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_map_component_row',
      ),
    ),
    'fields' => array(
      'field_map_component_row' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|map_component|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|map_location_details|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'map_location_details';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|map_location_details|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|node_ref_paragraph|collapsable_content';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'node_ref_paragraph';
  $ds_layout->view_mode = 'collapsable_content';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_node_entity_ref',
      ),
    ),
    'fields' => array(
      'field_node_entity_ref' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|node_ref_paragraph|collapsable_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|node_ref_paragraph|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'node_ref_paragraph';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_node_entity_ref',
      ),
    ),
    'fields' => array(
      'field_node_entity_ref' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|node_ref_paragraph|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|page_intro|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'page_intro';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_body',
        1 => 'child_page_navigation',
        2 => 'child_page_navigation_subsites',
      ),
      'right' => array(
        3 => 'field_paragraphs_right',
      ),
    ),
    'fields' => array(
      'field_body' => 'left',
      'child_page_navigation' => 'left',
      'child_page_navigation_subsites' => 'left',
      'field_paragraphs_right' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|page_intro|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|page_intro|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'page_intro';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_body',
      ),
      'right' => array(
        1 => 'field_paragraphs_right',
      ),
    ),
    'fields' => array(
      'field_body' => 'left',
      'field_paragraphs_right' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|page_intro|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|qflow|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'qflow';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_qflow_title',
        1 => 'field_qflow_description',
        2 => 'field_qflow_links',
      ),
    ),
    'fields' => array(
      'field_qflow_title' => 'ds_content',
      'field_qflow_description' => 'ds_content',
      'field_qflow_links' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|qflow|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|quick_facts|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'quick_facts';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_quick_facts_container',
        1 => 'field_icon',
        2 => 'field_header_one',
        3 => 'field_header_two',
        4 => 'field_body_text',
        5 => 'field_fact_links',
      ),
    ),
    'fields' => array(
      'group_quick_facts_container' => 'ds_content',
      'field_icon' => 'ds_content',
      'field_header_one' => 'ds_content',
      'field_header_two' => 'ds_content',
      'field_body_text' => 'ds_content',
      'field_fact_links' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'ds_content' => array(
        'featured-entity' => 'featured-entity',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|quick_facts|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|related_links|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'related_links';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_paragraph_links',
      ),
    ),
    'fields' => array(
      'field_paragraph_links' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|related_links|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|related_links|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'related_links';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_paragraph_links',
      ),
    ),
    'fields' => array(
      'field_paragraph_links' => 'ds_content',
    ),
  );
  $export['paragraphs_item|related_links|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|section|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_section_title',
      ),
      'left' => array(
        1 => 'field_paragraphs_left',
      ),
      'right' => array(
        2 => 'field_paragraphs_right',
      ),
    ),
    'fields' => array(
      'field_section_title' => 'top',
      'field_paragraphs_left' => 'left',
      'field_paragraphs_right' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|section|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|section|paragraphs_editor_preview';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'section';
  $ds_layout->view_mode = 'paragraphs_editor_preview';
  $ds_layout->layout = 'bootstrap_9_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_section_title',
      ),
      'left' => array(
        1 => 'field_paragraphs_left',
      ),
      'right' => array(
        2 => 'field_paragraphs_right',
      ),
    ),
    'fields' => array(
      'field_section_title' => 'top',
      'field_paragraphs_left' => 'left',
      'field_paragraphs_right' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|section|paragraphs_editor_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|small_logo|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'small_logo';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_small_logo_image',
      ),
    ),
    'fields' => array(
      'field_small_logo_image' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|small_logo|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|success_story|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'success_story';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_success_story',
      ),
    ),
    'fields' => array(
      'field_success_story' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|success_story|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|video|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_component_video',
      ),
    ),
    'fields' => array(
      'field_component_video' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|video|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function vu_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'alternate_teaser';
  $ds_view_mode->label = 'Alternate_teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['alternate_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'block_view';
  $ds_view_mode->label = 'Node block view';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['block_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'carousel';
  $ds_view_mode->label = 'Carousel';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['carousel'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'collapsable_content';
  $ds_view_mode->label = 'Collapsable Content';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['collapsable_content'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'featured_entity';
  $ds_view_mode->label = 'Featured entity';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'node' => 'node',
  );
  $export['featured_entity'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'fields';
  $ds_view_mode->label = 'Fields';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['fields'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image_with_caption';
  $ds_view_mode->label = 'Image with caption';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['image_with_caption'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'inline_featured_content';
  $ds_view_mode->label = 'Inline featured content';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['inline_featured_content'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'modal_video';
  $ds_view_mode->label = 'Modal video';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['modal_video'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'preprocess';
  $ds_view_mode->label = 'Preprocess';
  $ds_view_mode->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['preprocess'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sidebar_contact_information';
  $ds_view_mode->label = 'Sidebar Contact Information';
  $ds_view_mode->entities = array(
    'contact_information' => 'contact_information',
  );
  $export['sidebar_contact_information'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_with_read_more';
  $ds_view_mode->label = 'Teaser read more';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_with_read_more'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'victory';
  $ds_view_mode->label = 'Victory';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['victory'] = $ds_view_mode;

  return $export;
}
