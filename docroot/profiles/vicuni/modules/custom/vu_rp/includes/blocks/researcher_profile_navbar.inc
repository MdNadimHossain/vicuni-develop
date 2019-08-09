<?php

/**
 * @file
 * Profile navbar block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_navbar_info() {
  return [
    'info' => t('Researcher profile navbar'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_navbar_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();

  if (empty($node)) {
    return $render;
  }

  $email_value = vu_rp_extract_single_field_value('node', $node, 'field_rpa_email', 'email');
  $email = !empty($email_value) ? l(strtolower($email_value), 'mailto:' . $email_value) : NULL;

  $phone_value = vu_rp_extract_single_field_value('node', $node, 'field_rp_phone');
  $phone = !empty($phone_value) ? l(vu_core_format_phone($phone_value), 'tel:' . $phone_value) : NULL;

  $twitter_value = vu_rp_extract_single_field_value('node', $node, 'field_rp_twitter');
  $twitter = !empty($twitter_value) ? l($twitter_value, 'http://twitter.com/' . $twitter_value) : NULL;

  $facebook_value = vu_rp_extract_single_field_value('node', $node, 'field_rp_facebook');
  $facebook = !empty($facebook_value) ? l(t('facebook profile'), $facebook_value) : NULL;

  $linkedin_value = vu_rp_extract_single_field_value('node', $node, 'field_rp_linkedin');
  $linkedin = !empty($linkedin_value) ? l(t('LinkedIn profile'), $linkedin_value) : NULL;

  $conversation_value = vu_rp_extract_single_field_value('node', $node, 'field_rp_conversation_profile', 'url');
  $conversation = !empty($conversation_value) ? l(t('The Conversation profile'), $conversation_value) : NULL;

  $orcid_value = vu_rp_extract_single_field_value('node', $node, 'field_rpa_orcid_id');
  $orcid = !empty($orcid_value) ? l(t('View ORCID profile'), $orcid_value) : NULL;

  $variables = [
    'email' => $email,
    'phone' => $phone,
    'twitter' => $twitter,
    'facebook' => $facebook,
    'linkedin' => $linkedin,
    'conversation' => $conversation,
    'orcid' => $orcid,
  ];

  $output = theme('vu_rp_block_researcher_profile_navbar', $variables);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
      '#attached' => [
        'js' => [
          drupal_get_path('module', 'vu_rp') . '/js/vu_rp.node.js',
          drupal_get_path('module', 'vu_rp') . '/js/vu_rp.navbar.js',
        ],
      ],
    ],
  ];

  return $render;
}
