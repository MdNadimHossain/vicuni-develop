<?php

/**
 * @file
 * Step to provision Research Profiles demo content.
 */

use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Random;

/**
 * Provisions Pages test pages.
 */
function vu_rp_demo_provision_step_researcher_profiles() {
  $count_nodes = 5;

  for ($i = 0; $i < $count_nodes; $i++) {
    $api_data = _vu_rp_demo_random_api_researcher();
    $author = vu_rp_demo_random_user();
    $name_variation = rand(0, 1);

    $job_title_variation = rand(0, 1);

    $use_photo = rand(0, 1);
    $is_published = rand(0, 1) ? NODE_PUBLISHED : NODE_NOT_PUBLISHED;
    $has_preferred_name = !empty($api_data['preferredName']);

    $log_items = [
      'idx' => ($i + 1),
      'Status' => $is_published ? 'P' : 'D',
      'User' => $author->uid . '-' . vu_rp_demo_get_role_from_user($author),
      'Pref Name' => $has_preferred_name ? 'Y' : 'N',
      'Name Var' => $name_variation ? 'Y' : 'N',
      'Photo' => $use_photo ? 'Y' : 'N',
    ];

    $node = (object) NULL;
    $node->type = 'researcher_profile';
    $node->uid = $author->uid;
    $node->created = REQUEST_TIME;
    $node->changed = REQUEST_TIME;
    $node->status = $is_published;
    $node->workbench_moderation_state_new = $is_published ? 'published' : 'draft';
    $node->comment = 0;
    $node->promote = 0;
    $node->moderate = 0;
    $node->sticky = 0;

    vu_rp_demo_set_field_value($api_data['staffID'], $node, 'field_rpa_staff_id');
    vu_rp_demo_set_field_value($api_data['firstName'], $node, 'field_rpa_first_name');
    vu_rp_demo_set_field_value($api_data['secondName'], $node, 'field_rpa_middle_name');
    vu_rp_demo_set_field_value($api_data['lastName'], $node, 'field_rpa_last_name');
    vu_rp_demo_set_field_value($api_data['preferredName'], $node, 'field_rpa_preferred_name');

    vu_rp_demo_set_field_value($name_variation, $node, 'field_rp_name_variation');
    if ($name_variation) {
      vu_rp_demo_set_field_value('FNV_' . Random::name(), $node, 'field_rp_first_name');
      vu_rp_demo_set_field_value('LNV_' . Random::name(), $node, 'field_rp_last_name');
    }

    // This field also comes from API, but it is not mapped to be populated.
    $title = vu_rp_demo_random_array_item([
      'Dr',
      'Professor',
      'Associate Professor',
      'Eur Ing',
      'Dean Laureate',
      'The Hon.',
      'The Hon. Justice',
      'Magistrate',
      'Judge',
    ]);
    vu_rp_demo_set_field_value('PN_' . Random::name(rand(2, 5)), $node, 'field_rp_post_nominal');
    vu_rp_demo_set_field_value($title, $node, 'field_rp_title');

    vu_rp_demo_set_field_value($api_data['email'], $node, 'field_rpa_email', 'email');
    vu_rp_demo_set_field_value(Random::phone(), $node, 'field_rp_phone');

    $log_items['Twitter'] = 'N';
    if (rand(0, 10) % 3) {
      vu_rp_demo_set_field_value('@' . Random::name(), $node, 'field_rp_twitter');
      $log_items['Twitter'] = 'Y';
    }

    $log_items['Facebook'] = 'N';
    if (rand(0, 10) % 3) {
      vu_rp_demo_set_field_value('https://facebook.com/' . Random::path(), $node, 'field_rp_facebook');
      $log_items['Facebook'] = 'Y';
    }

    $log_items['Linkedin'] = 'N';
    if (rand(0, 10) % 3) {
      vu_rp_demo_set_field_value('https://linkedin.com/' . Random::path(), $node, 'field_rp_linkedin');
      $log_items['Linkedin'] = 'Y';
    }

    $log_items['ConvProf'] = 'N';
    if (rand(0, 10) % 3) {
      vu_rp_demo_set_field_value('https://conv-prof-' . Random::path() . '.com/' . Random::path(), $node, 'field_rp_conversation_profile', 'url');
      $log_items['ConvProf'] = 'Y';
    }

    vu_rp_demo_set_field_value($api_data['orcID'], $node, 'field_rpa_orcid_id');

    $institute_tid = vu_rp_demo_random_term('research_institutes')->tid;
    vu_rp_demo_set_field_value($institute_tid, $node, 'field_rp_institute_primary', 'target_id');
    $log_items['Institute ID'] = $institute_tid;

    vu_rp_demo_set_field_value($api_data['jobTitle'], $node, 'field_rpa_job_title');

    vu_rp_demo_set_field_value($job_title_variation, $node, 'field_rp_job_title_variation');
    $log_items['Job Title Var'] = 'N';
    if ($job_title_variation) {
      vu_rp_demo_set_field_value('JT_var_' . Random::name(), $node, 'field_rp_job_title');
      $log_items['Job Title Var'] = 'Y';
    }

    vu_rp_demo_set_field_value($use_photo, $node, 'field_rp_use_photo');
    if ($use_photo) {
      $photo_file = vu_rp_demo_random_image_placeholder([
        'width' => 600,
        'height' => 500,
        'text' => 'Photo of ' . $api_data['firstName'] . ' ' . $api_data['secondName'],
      ]);
      vu_rp_demo_set_field_value($photo_file->fid, $node, 'field_rp_photo', 'fid');
    }

    $expertise_tids = _vu_rp_demo_random_field_expertise($node);
    $log_items['Expertise TIDs'] = implode(', ', $expertise_tids);
    $log_items['Expertise TIDs'] .= ' (' . count($expertise_tids) . ')';

    vu_rp_demo_set_field_value('BIO_' . vu_rp_demo_random_lipsum(30), $node, 'field_rp_biography', 'value', 0);
    vu_rp_demo_set_field_value('researcher', $node, 'field_rp_biography', 'format', 0);

    $log_items['Related Links'] = _vu_rp_demo_random_field_related_links($node);

    vu_rp_demo_set_field_value('BIO_short_' . vu_rp_demo_random_lipsum(15), $node, 'field_rp_shorter_biography');

    $is_available_to_media = rand(0, 1);
    vu_rp_demo_set_field_value($is_available_to_media, $node, 'field_rp_available_to_media');
    $log_items['Is avail to media'] = $is_available_to_media ? 'Y' : 'N';

    $log_items['Qualifications'] = _vu_rp_demo_random_field_qualifications($node);

    $log_items['Research Repo Link'] = 'N';
    if (rand(0, 10) % 3) {
      vu_rp_demo_set_field_value('https://' . Random::path() . '.com', $node, 'field_rp_research_repo_link', 'url');
      $log_items['Research Repo Link'] = 'Y';
    }

    $log_items['Pubs count'] = 0;
    $log_items['Pubs DOI count'] = 0;
    if (!empty($api_data['publications'])) {
      $publications_count = count($api_data['publications']);
      vu_rp_demo_set_field_value($publications_count, $node, 'field_rpc_publication_count');
      $log_items['Pubs count'] = $publications_count;

      $count_per_type = [];
      foreach ($api_data['publications'] as $publication) {
        _vu_rp_api_publications_paragraph_create($publication, $node);
        $log_items['Pubs DOI count'] = !empty($publication['DOI']) ? $log_items['Pubs DOI count'] + 1 : $log_items['Pubs DOI count'];
        $count_per_type[$publication['type']] = isset($count_per_type[$publication['type']]) ? $count_per_type[$publication['type']] + 1 : 1;
      }

      $count_per_type_value = [];
      foreach ($count_per_type as $type => $count) {
        $count_per_type_value[] = $type . ': ' . rand($count, $count + 30);
      }
      vu_rp_demo_set_field_value(implode(PHP_EOL, $count_per_type_value), $node, 'field_rpc_publication_type_count');
      $log_items['Pubs count per type'] = implode(', ', $count_per_type_value);
    }

    $log_items['Funding Count'] = vu_rp_api_field_callback_funding($api_data['grantDetails'], '', '', $node, '', '');

    $log_items['OTA'] = _vu_rp_demo_random_field_organisations($node);

    $can_supervise = rand(0, 1);
    vu_rp_demo_set_field_value($can_supervise, $node, 'field_rp_sup_is_available');
    $log_items['Can supervise'] = $can_supervise ? 'Y' : 'N';

    $log_items['Completed supervision'] = _vu_rp_api_supervision_paragraph_create($node, $api_data['HDRDetails'], FALSE);
    $log_items['Current supervision'] = _vu_rp_api_supervision_paragraph_create($node, $api_data['HDRDetails'], TRUE);

    $log_items['Supervised other'] = 'N';
    if (rand(0, 10) % 3) {
      vu_rp_demo_set_field_value(Random::lipsum(30), $node, 'field_rp_sup_other');
      $log_items['Supervised other'] = 'Y';
    }

    vu_rp_demo_set_field_value(Random::lipsum(35), $node, 'field_rp_teaching_experience', 'value', 0);
    vu_rp_demo_set_field_value('researcher', $node, 'field_rp_teaching_experience', 'format', 0);

    $log_items['Academic roles'] = _vu_rp_demo_random_field_academic_roles($node);

    $log_items['Industry roles'] = _vu_rp_demo_random_field_industry_roles($node);

    $log_items['Awards'] = _vu_rp_demo_random_field_awards($node);

    $log_items['Keynotes'] = _vu_rp_demo_random_field_keynotes($node);

    $log_items['Media'] = _vu_rp_demo_random_field_media($node);

    $log_items['Memberships'] = _vu_rp_demo_random_field_memberships($node);

    $node->log = vu_rp_demo_make_log($log_items);
    node_save($node);

    General::messageSet(format_string('Created page "@title" (nid: @nid)', [
      '@title' => $node->title,
      '@nid' => $node->nid,
    ]));

    vu_rp_demo_record_add('node', 'researcher_profile', $node->nid);
  }
}

/**
 * Helper to get a role from the user.
 */
function vu_rp_demo_get_role_from_user($user) {
  $role_names = [
    'Researcher' => 'Researcher',
    'Researcher Profile Admin' => 'Admin',
    'Researcher Profile Approver' => 'Approver',
  ];

  $ret = FALSE;
  foreach ($role_names as $role_name => $role_shortening) {
    $role = user_role_load_by_name($role_name);
    if (user_has_role($role->rid, $user)) {
      $ret = $role_shortening;
      break;
    }
  }

  return $ret;
}
