<?php

/**
 * @file
 * Researcher contact.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_contact_info() {
  return [
    'info' => t('Researcher contact details'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_contact_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $email = vu_rp_extract_single_field_value('node', $node, 'field_rpa_email', 'email');
  $phone = vu_rp_extract_single_field_value('node', $node, 'field_rp_phone');
  $twitter = vu_rp_extract_single_field_value('node', $node, 'field_rp_twitter');
  $facebook = vu_rp_extract_single_field_value('node', $node, 'field_rp_facebook');
  $linkedin = vu_rp_extract_single_field_value('node', $node, 'field_rp_linkedin');
  $conversation = vu_rp_extract_single_field_value('node', $node, 'field_rp_conversation_profile', 'url');
  $orcid = vu_rp_extract_single_field_value('node', $node, 'field_rpa_orcid_id');

  $variables = [
    'email' => !empty($email) ? strtolower($email) : NULL,
    'phone' => !empty($phone) ? vu_core_format_phone($phone) : NULL,
    'phone_value' => !empty($phone) ? $phone : NULL,
    'twitter' => !empty($twitter) ? $twitter : NULL,
    'twitter_url' => !empty($twitter) ? 'http://twitter.com/' . $twitter : NULL,
    'facebook' => !empty($facebook) ? $facebook : NULL,
    'linkedin' => !empty($linkedin) ? $linkedin : NULL,
    'conversation' => !empty($conversation) ? $conversation : NULL,
    'orcid' => !empty($orcid) ? 'https://orcid.org/' . check_plain($orcid) : NULL,
  ];

  $output = theme('vu_rp_block_researcher_overview_contact', $variables);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
