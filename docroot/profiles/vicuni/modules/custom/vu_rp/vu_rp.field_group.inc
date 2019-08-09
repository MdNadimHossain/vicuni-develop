<?php
/**
 * @file
 * vu_rp.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function vu_rp_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research_profile|node|researcher_profile|form';
  $field_group->group_name = 'group_research_profile';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Research profile',
    'weight' => '4',
    'children' => array(
      0 => 'group_rp_biography_expertise',
      1 => 'group_rp_career',
      2 => 'group_rp_funding',
      3 => 'group_rp_personal_details',
      4 => 'group_rp_publications',
      5 => 'group_rp_supervising_teaching',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-researcher-profile field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_research_profile|node|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rp_biography_expertise|node|researcher_profile|form';
  $field_group->group_name = 'group_rp_biography_expertise';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_research_profile';
  $field_group->data = array(
    'label' => 'Biography & expertise',
    'weight' => '5',
    'children' => array(
      0 => 'field_rp_available_to_media',
      1 => 'field_rp_biography',
      2 => 'field_rp_expertise',
      3 => 'field_rp_qualification',
      4 => 'field_rp_related_links',
      5 => 'field_rp_shorter_biography',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rp_biography_expertise|node|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rp_career|node|researcher_profile|form';
  $field_group->group_name = 'group_rp_career';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_research_profile';
  $field_group->data = array(
    'label' => 'Career',
    'weight' => '9',
    'children' => array(
      0 => 'field_rp_academic_roles',
      1 => 'field_rp_awards',
      2 => 'field_rp_has_academic_roles',
      3 => 'field_rp_has_awards',
      4 => 'field_rp_has_key_industry',
      5 => 'field_rp_has_keynote_invitations',
      6 => 'field_rp_has_media_appearances',
      7 => 'field_rp_has_memberships',
      8 => 'field_rp_industry_roles',
      9 => 'field_rp_keynotes',
      10 => 'field_rp_media',
      11 => 'field_rp_memberships',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rp-career field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_rp_career|node|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rp_funding|node|researcher_profile|form';
  $field_group->group_name = 'group_rp_funding';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_research_profile';
  $field_group->data = array(
    'label' => 'Funding',
    'weight' => '7',
    'children' => array(
      0 => 'field_rp_has_ota',
      1 => 'field_rp_ota',
      2 => 'field_rpa_funding',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rp-funding field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rp_funding|node|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rp_personal_details|node|researcher_profile|form';
  $field_group->group_name = 'group_rp_personal_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_research_profile';
  $field_group->data = array(
    'label' => 'Personal details',
    'weight' => '4',
    'children' => array(
      0 => 'field_rp_conversation_profile',
      1 => 'field_rp_facebook',
      2 => 'field_rp_first_name',
      3 => 'field_rp_institute_best_align',
      4 => 'field_rp_institute_primary',
      5 => 'field_rp_job_title',
      6 => 'field_rp_job_title_variation',
      7 => 'field_rp_last_name',
      8 => 'field_rp_linkedin',
      9 => 'field_rp_name_variation',
      10 => 'field_rp_phone',
      11 => 'field_rp_photo',
      12 => 'field_rp_post_nominal',
      13 => 'field_rp_title',
      14 => 'field_rp_twitter',
      15 => 'field_rp_use_photo',
      16 => 'field_rpa_email',
      17 => 'field_rpa_first_name',
      18 => 'field_rpa_job_title',
      19 => 'field_rpa_last_name',
      20 => 'field_rpa_middle_name',
      21 => 'field_rpa_orcid_id',
      22 => 'field_rpa_preferred_name',
      23 => 'field_rpa_staff_id',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rp_personal_details|node|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rp_publications|node|researcher_profile|form';
  $field_group->group_name = 'group_rp_publications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_research_profile';
  $field_group->data = array(
    'label' => 'Publications',
    'weight' => '6',
    'children' => array(
      0 => 'field_rp_research_repo_link',
      1 => 'field_rpa_publications',
      2 => 'field_rpc_publication_count',
      3 => 'field_rpc_publication_type_count',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rp-publications field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rp_publications|node|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rp_supervising_teaching|node|researcher_profile|form';
  $field_group->group_name = 'group_rp_supervising_teaching';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_research_profile';
  $field_group->data = array(
    'label' => 'Supervising & teaching',
    'weight' => '8',
    'children' => array(
      0 => 'field_rp_sup_is_available',
      1 => 'field_rp_sup_other',
      2 => 'field_rp_teaching_experience',
      3 => 'field_rpa_sup_completed',
      4 => 'field_rpa_sup_current',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rp-supervising-teaching field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rp_supervising_teaching|node|researcher_profile|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Biography & expertise');
  t('Career');
  t('Funding');
  t('Personal details');
  t('Publications');
  t('Research profile');
  t('Supervising & teaching');

  return $field_groups;
}
