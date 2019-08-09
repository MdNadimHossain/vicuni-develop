<?php
/**
 * @file
 * vu_rp.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vu_rp_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_researcher_profile';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_researcher_profile';
  $strongarm->value = '[researcher_profile:variation_first_name] [researcher_profile:variation_last_name]';
  $export['auto_entitylabel_pattern_node_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_researcher_profile';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_per_field_core';
  $strongarm->value = 1;
  $export['better_formats_per_field_core'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_researcher_profile';
  $strongarm->value = 0;
  $export['comment_anonymous_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_researcher_profile';
  $strongarm->value = 1;
  $export['comment_default_mode_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_researcher_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_researcher_profile';
  $strongarm->value = 1;
  $export['comment_form_location_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_researcher_profile';
  $strongarm->value = '0';
  $export['comment_preview_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_researcher_profile';
  $strongarm->value = '1';
  $export['comment_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_researcher_profile';
  $strongarm->value = 1;
  $export['comment_subject_field_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__researcher_profile';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'alternate_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'featured_entity' => array(
        'custom_settings' => FALSE,
      ),
      'fields' => array(
        'custom_settings' => FALSE,
      ),
      'inline_featured_content' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_with_read_more' => array(
        'custom_settings' => FALSE,
      ),
      'victory' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '1',
        ),
        'xmlsitemap' => array(
          'weight' => '2',
        ),
        'metatags' => array(
          'weight' => '5',
        ),
        'vu_rp_fb_like' => array(
          'weight' => '11',
        ),
        'vu_rp_dislike' => array(
          'weight' => '11',
        ),
        'markup_rp_your_name' => array(
          'weight' => '9',
        ),
        'markup_rp_contact_details' => array(
          'weight' => '20',
        ),
        'markup_rp_vu_role' => array(
          'weight' => '29',
        ),
        'markup_rp_your_photo' => array(
          'weight' => '34',
        ),
        'markup_rp_photo_desc' => array(
          'weight' => '34',
        ),
        'markup_rp_areas_of_expertise' => array(
          'weight' => '31',
        ),
        'markup_rp_your_biography' => array(
          'weight' => '33',
        ),
        'markup_rp_related_links' => array(
          'weight' => '35',
        ),
        'markup_rp_shorter_biography' => array(
          'weight' => '37',
        ),
        'markup_rp_qualifications' => array(
          'weight' => '41',
        ),
        'markup_rp_publication' => array(
          'weight' => '82',
        ),
        'markup_rp_funding' => array(
          'weight' => '88',
        ),
        'markup_rp_supervising' => array(
          'weight' => '92',
        ),
        'markup_rp_academic_role' => array(
          'weight' => '34',
        ),
        'markup_rp_industry_role' => array(
          'weight' => '37',
        ),
        'markup_rp_awards' => array(
          'weight' => '40',
        ),
        'markup_rp_keynotes' => array(
          'weight' => '43',
        ),
        'markup_rp_membership' => array(
          'weight' => '46',
        ),
        'markup_rp_media' => array(
          'weight' => '48',
        ),
        'markup_rp_acknowledge' => array(
          'weight' => '93',
        ),
        'markup_rp_other_supervision' => array(
          'weight' => '98',
        ),
        'markup_rp_name_expanded' => array(
          'weight' => '10',
        ),
        'markup_rp_teaching_experience' => array(
          'weight' => '100',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_researcher_profile';
  $strongarm->value = array();
  $export['menu_options_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_researcher_profile';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__researcher_profile';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_taxonomy_term__research_institutes';
  $strongarm->value = TRUE;
  $export['metatag_enable_taxonomy_term__research_institutes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_researcher_profile';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_researcher_profile';
  $strongarm->value = '1';
  $export['node_preview_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_researcher_profile';
  $strongarm->value = 0;
  $export['node_submitted_researcher_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_researcher_profile_pattern';
  $strongarm->value = 'research/[node:title]';
  $export['pathauto_node_researcher_profile_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_membership_levels_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_membership_levels_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_membership_organisations_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_membership_organisations_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_research_institutes_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_research_institutes_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vu_rp_helpdesk_email';
  $strongarm->value = 'researcher.profiles@vu.edu.au';
  $export['vu_rp_helpdesk_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_researcher_profile';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_researcher_profile'] = $strongarm;

  return $export;
}
