<?php
/**
 * @file
 * vu_rp.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function vu_rp_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|researcher_profile|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'researcher_profile';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'rp_academic_roles' => array(
      'weight' => '16',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_awards' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_contact_details' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_current_supervisions' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_funding_related_links' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_fundings' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_industry_roles' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_is_supervising' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_key_details' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_keynotes' => array(
      'weight' => '19',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_media_appearance' => array(
      'weight' => '21',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_memberships' => array(
      'weight' => '20',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_organisation_to_ackn' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_overview_related_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_past_supervisions' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_publications' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_qualifications' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_supervision' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rp_supervision_related_l' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|researcher_profile|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|find_researcher|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'find_researcher';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'find_researcher' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['paragraphs_item|find_researcher|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function vu_rp_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'find_researcher';
  $ds_field->label = 'Find a researcher';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $ds_field->ui_limit = 'find_researcher|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_search',
    'block_render' => '3',
    'block_visibility' => 0,
  );
  $export['find_researcher'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_contact_details';
  $ds_field->label = 'Researcher contact details';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_contact',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_contact_details'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_current_supervisions';
  $ds_field->label = 'Researcher current supervisions';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_sup_curr',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_current_supervisions'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_is_supervising';
  $ds_field->label = 'Researcher is supervising';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_is_super',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_is_supervising'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_key_details';
  $ds_field->label = 'Researcher key details';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_key_details',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_key_details'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_organisation_to_ackn';
  $ds_field->label = 'Researcher organisation to acknowledge';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_fund_ackn',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_organisation_to_ackn'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_overview_related_link';
  $ds_field->label = 'Researcher overview related links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_ov_links',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_overview_related_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_past_supervisions';
  $ds_field->label = 'Researcher past supervisions';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_sup_compl',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_past_supervisions'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_publications';
  $ds_field->label = 'Researcher publications';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_pubs',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_publications'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_qualifications';
  $ds_field->label = 'Researcher qualifications';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_qs',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['researcher_qualifications'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_academic_roles';
  $ds_field->label = 'Researcher academic roles';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_ac_roles',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_academic_roles'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_awards';
  $ds_field->label = 'Researcher awards';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_awards',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_awards'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_funding_related_links';
  $ds_field->label = 'Researcher funding related links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_fund_links',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_funding_related_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_fundings';
  $ds_field->label = 'Researcher fundings';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_fundings',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_fundings'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_industry_roles';
  $ds_field->label = 'Researcher industry roles';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_in_roles',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_industry_roles'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_keynotes';
  $ds_field->label = 'Researcher keynotes';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_keynotes',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_keynotes'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_media_appearance';
  $ds_field->label = 'Researcher media';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_media',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_media_appearance'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_memberships';
  $ds_field->label = 'Researcher memberships';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_memberships',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_memberships'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_supervision';
  $ds_field->label = 'Researcher supervision';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_is_super',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_supervision'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rp_supervision_related_l';
  $ds_field->label = 'Researcher supervision related links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'researcher_profile|*';
  $ds_field->properties = array(
    'block' => 'vu_rp|researcher_profile_sup_links',
    'block_render' => '1',
    'block_visibility' => 0,
  );
  $export['rp_supervision_related_l'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function vu_rp_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|researcher_profile|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'researcher_profile';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'vu_rp';
  $ds_layout->settings = array(
    'regions' => array(
      'overview_key_details' => array(
        0 => 'researcher_key_details',
        1 => 'researcher_is_supervising',
      ),
      'overview_right' => array(
        2 => 'researcher_contact_details',
      ),
      'overview_about' => array(
        3 => 'field_rp_biography',
      ),
      'overview_middle_right' => array(
        4 => 'researcher_overview_related_link',
      ),
      'overview_qualifications' => array(
        5 => 'researcher_qualifications',
      ),
      'publications' => array(
        6 => 'researcher_publications',
      ),
      'funding' => array(
        7 => 'rp_fundings',
      ),
      'funding_right' => array(
        8 => 'rp_funding_related_links',
      ),
      'funding_bottom' => array(
        9 => 'researcher_organisation_to_ackn',
      ),
      'supervising_left' => array(
        10 => 'rp_supervision',
        11 => 'researcher_current_supervisions',
        12 => 'researcher_past_supervisions',
      ),
      'supervising_right' => array(
        13 => 'rp_supervision_related_l',
      ),
      'supervising_middle' => array(
        14 => 'field_rp_sup_other',
      ),
      'supervising_bottom' => array(
        15 => 'field_rp_teaching_experience',
      ),
      'career' => array(
        16 => 'rp_academic_roles',
        17 => 'rp_industry_roles',
        18 => 'rp_awards',
        19 => 'rp_keynotes',
        20 => 'rp_memberships',
        21 => 'rp_media_appearance',
      ),
    ),
    'fields' => array(
      'researcher_key_details' => 'overview_key_details',
      'researcher_is_supervising' => 'overview_key_details',
      'researcher_contact_details' => 'overview_right',
      'field_rp_biography' => 'overview_about',
      'researcher_overview_related_link' => 'overview_middle_right',
      'researcher_qualifications' => 'overview_qualifications',
      'researcher_publications' => 'publications',
      'rp_fundings' => 'funding',
      'rp_funding_related_links' => 'funding_right',
      'researcher_organisation_to_ackn' => 'funding_bottom',
      'rp_supervision' => 'supervising_left',
      'researcher_current_supervisions' => 'supervising_left',
      'researcher_past_supervisions' => 'supervising_left',
      'rp_supervision_related_l' => 'supervising_right',
      'field_rp_sup_other' => 'supervising_middle',
      'field_rp_teaching_experience' => 'supervising_bottom',
      'rp_academic_roles' => 'career',
      'rp_industry_roles' => 'career',
      'rp_awards' => 'career',
      'rp_keynotes' => 'career',
      'rp_memberships' => 'career',
      'rp_media_appearance' => 'career',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'overview_key_details' => 'div',
      'overview_right' => 'div',
      'overview_about' => 'div',
      'overview_middle_right' => 'div',
      'overview_qualifications' => 'div',
      'publications' => 'div',
      'funding' => 'div',
      'funding_right' => 'div',
      'funding_bottom' => 'div',
      'supervising_left' => 'div',
      'supervising_right' => 'div',
      'supervising_middle' => 'div',
      'supervising_bottom' => 'div',
      'career' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|researcher_profile|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|find_researcher|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'find_researcher';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'find_researcher',
      ),
    ),
    'fields' => array(
      'find_researcher' => 'ds_content',
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
  $export['paragraphs_item|find_researcher|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|find_researcher|form';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'find_researcher';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_researcher_link',
        1 => 'field_null',
      ),
      'hidden' => array(
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_researcher_link' => 'ds_content',
      'field_null' => 'ds_content',
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
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|find_researcher|form'] = $ds_layout;

  return $export;
}
