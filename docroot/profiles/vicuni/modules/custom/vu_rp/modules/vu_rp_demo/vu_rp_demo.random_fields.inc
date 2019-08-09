<?php

/**
 * @file
 * VU Researcher Profile Demo random field data.
 *
 * This is used to create Drupal fields manual data.
 */

use Drupal\drupal_helpers\Random;

/**
 * Set value in field_rp_ota field.
 */
function _vu_rp_demo_random_field_organisations($node) {
  $organisation_count = 0;

  if (empty($node)) {
    return $organisation_count;
  }

  $is_acknowledge = rand(0, 1);
  vu_rp_demo_set_field_value($is_acknowledge, $node, 'field_rp_has_ota');
  if ($is_acknowledge) {
    $organisation_count = rand(1, 10);
    for ($i = 0; $i < $organisation_count; $i++) {
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_ota', 'bundle' => 'rp_ota']);
      vu_rp_demo_set_field_value('OTA_ORG#' . ($i + 1) . '_' . Random::name(), $paragraph, 'field_rp_ota_name');
      vu_rp_demo_set_field_value('https://org-link-' . ($i + 1) . '-' . Random::lipsum(1) . '.com', $paragraph, 'field_rp_ota_link', 'url');
      vu_rp_demo_set_field_value('OTA_DESC#' . ($i + 1) . '_' . Random::lipsum(20), $paragraph, 'field_rp_ota_description');
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return $organisation_count;
}

/**
 * Set value in field_rp_academic_roles field.
 */
function _vu_rp_demo_random_field_academic_roles($node) {
  $academic_roles_count = 0;

  if (empty($node)) {
    return $academic_roles_count;
  }

  $has_academic_roles = rand(0, 1);
  vu_rp_demo_set_field_value($has_academic_roles, $node, 'field_rp_has_academic_roles');
  if ($has_academic_roles) {
    $academic_roles_count = rand(1, 10);
    for ($i = 0; $i < $academic_roles_count; $i++) {
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_academic_roles', 'bundle' => 'rp_academic_role']);
      vu_rp_demo_set_field_value('AR_ROLE#' . ($i + 1) . '_' . Random::lipsum(rand(1, 5)), $paragraph, 'field_rp_ar_role');
      vu_rp_demo_set_field_value('AR_ORG#' . ($i + 1) . '_' . Random::lipsum(rand(1, 4)), $paragraph, 'field_rp_ar_organisation');
      $date_start = rand(strtotime('now - 5 years'), strtotime('now - 2 years'));
      $date_end = rand(strtotime('now - 2 years'), strtotime('now'));
      $paragraph->field_rp_ar_period[LANGUAGE_NONE][0] = [
        'value' => date('Y-m-d H:i:s', $date_start),
        'value2' => date('Y-m-d H:i:s', $date_end),
        'timezone' => 'Australia/Melbourne',
        'timezone_db' => 'Australia/Melbourne',
        'date_type' => 'datetime',
      ];
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return $academic_roles_count;
}

/**
 * Set value in field_rp_industry_roles field.
 */
function _vu_rp_demo_random_field_industry_roles($node) {
  $industry_role_count = 0;
  if (empty($node)) {
    return $industry_role_count;
  }

  $has_key_industry = rand(0, 1);
  vu_rp_demo_set_field_value($has_key_industry, $node, 'field_rp_has_key_industry');
  if ($has_key_industry) {
    $industry_role_count = rand(1, 10);
    for ($i = 0; $i < $industry_role_count; $i++) {
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_industry_roles', 'bundle' => 'rp_industry_roles']);
      vu_rp_demo_set_field_value('IR_ROLE#' . ($i + 1) . '_' . Random::lipsum(rand(1, 4)), $paragraph, 'field_rp_ir_role');
      vu_rp_demo_set_field_value('IR_ORG#' . ($i + 1) . '_' . Random::lipsum(rand(1, 4)), $paragraph, 'field_rp_ir_organisation');
      $date_start = rand(strtotime('now - 5 years'), strtotime('now - 2 years'));
      $date_end = rand(strtotime('now - 2 years'), strtotime('now'));
      $paragraph->field_rp_ir_period[LANGUAGE_NONE][0] = [
        'value' => date('Y-m-d H:i:s', $date_start),
        'value2' => date('Y-m-d H:i:s', $date_end),
        'timezone' => 'Australia/Melbourne',
        'timezone_db' => 'Australia/Melbourne',
        'date_type' => 'datetime',
      ];
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return $industry_role_count;
}

/**
 * Set value in field_rp_awards field.
 */
function _vu_rp_demo_random_field_awards($node) {
  $awards_count = 0;

  if (empty($node)) {
    return $awards_count;
  }

  $has_awards = rand(0, 1);
  vu_rp_demo_set_field_value($has_awards, $node, 'field_rp_has_awards');
  if ($has_awards) {
    $awards_count = rand(1, 10);
    for ($i = 0; $i < $awards_count; $i++) {
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_awards', 'bundle' => 'rp_award']);
      vu_rp_demo_set_field_value('AW_NAME#' . ($i + 1) . '_' . Random::lipsum(rand(1, 5)), $paragraph, 'field_rp_a_award_name');
      vu_rp_demo_set_field_value('AW_ORG#' . ($i + 1) . '_' . Random::lipsum(rand(1, 4)), $paragraph, 'field_rp_a_organisation');
      vu_rp_demo_set_field_value('https://aw-org-link-' . ($i + 1) . '-' . Random::lipsum(1) . '.com', $paragraph, 'field_rp_a_organisation_link', 'url');
      $date = rand(strtotime('now - 5 years'), strtotime('now'));
      $paragraph->field_rp_a_year[LANGUAGE_NONE][0] = [
        'value' => date('Y-m-d H:i:s', $date),
        'timezone' => 'Australia/Melbourne',
        'timezone_db' => 'Australia/Melbourne',
        'date_type' => 'datetime',
      ];
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return $awards_count;
}

/**
 * Set value in field_rp_keynotes field.
 */
function _vu_rp_demo_random_field_keynotes($node) {
  $keynote_count = 0;

  if (empty($node)) {
    return $keynote_count;
  }

  $has_keynote = rand(0, 1);
  vu_rp_demo_set_field_value($has_keynote, $node, 'field_rp_has_keynote_invitations');
  if ($has_keynote) {
    $keynote_count = rand(1, 10);
    for ($i = 0; $i < $keynote_count; $i++) {
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_keynotes', 'bundle' => 'rp_keynote']);
      $date = rand(strtotime('now - 5 years'), strtotime('now'));
      $paragraph->field_rp_k_year[LANGUAGE_NONE][0] = [
        'value' => date('Y-m-d H:i:s', $date),
        'timezone' => 'Australia/Melbourne',
        'timezone_db' => 'Australia/Melbourne',
        'date_type' => 'datetime',
      ];
      vu_rp_demo_set_field_value('KEYNOTE_TITLE#' . ($i + 1) . '_' . Random::lipsum(rand(1, 6)), $paragraph, 'field_rp_k_title');
      vu_rp_demo_set_field_value('KEYNOTE_DET#' . ($i + 1) . '_' . Random::lipsum(rand(5, 25)), $paragraph, 'field_rp_k_details');
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return $keynote_count;
}

/**
 * Set value in field_rp_media field.
 */
function _vu_rp_demo_random_field_media($node) {
  $media_count = 0;

  if (empty($node)) {
    return $media_count;
  }

  $has_media_appearances = rand(0, 1);
  vu_rp_demo_set_field_value($has_media_appearances, $node, 'field_rp_has_media_appearances');
  if ($has_media_appearances) {
    $media_count = rand(1, 10);
    for ($i = 0; $i < $media_count; $i++) {
      $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_media', 'bundle' => 'rp_media_appearance']);
      $date = rand(strtotime('now - 5 years'), strtotime('now'));
      $paragraph->field_rp_ma_date[LANGUAGE_NONE][0] = [
        'value' => date('Y-m-d H:i:s', $date),
        'timezone' => 'Australia/Melbourne',
        'timezone_db' => 'Australia/Melbourne',
        'date_type' => 'datetime',
      ];
      vu_rp_demo_set_field_value('MEDIA_TITLE#' . ($i + 1) . '_' . Random::lipsum(rand(1, 5)), $paragraph, 'field_rp_ma_title');
      vu_rp_demo_set_field_value('MEDIA_SUM#' . ($i + 1) . '_' . Random::lipsum(rand(5, 25)), $paragraph, 'field_rp_ma_summary');
      vu_rp_demo_set_field_value('https://media-link-' . ($i + 1) . '-' . Random::lipsum(1) . '.com', $paragraph, 'field_rp_ma_link', 'url');
      $paragraph->setHostEntity('node', $node);
      $paragraph->save(TRUE);
    }
  }

  return $media_count;
}

/**
 * Set value in field_rp_memberships field.
 */
function _vu_rp_demo_random_field_memberships($node) {
  $memberships_count = 0;

  if (empty($node)) {
    return $memberships_count;
  }

  $has_memberships = rand(0, 1);
  vu_rp_demo_set_field_value($has_memberships, $node, 'field_rp_has_memberships');
  if ($has_memberships) {
    if (rand(0, 10) % 3) {
      $memberships_count = rand(1, 10);
      for ($i = 0; $i < $memberships_count; $i++) {
        $paragraph = new ParagraphsItemEntity(['field_name' => 'field_rp_memberships', 'bundle' => 'rp_membership']);
        vu_rp_demo_set_field_value(vu_rp_demo_random_term('membership_organisations')->tid, $paragraph, 'field_rp_m_organisation', 'target_id');
        vu_rp_demo_set_field_value(vu_rp_demo_random_term('membership_levels')->tid, $paragraph, 'field_rp_m_role', 'target_id');
        $paragraph->setHostEntity('node', $node);
        $paragraph->save(TRUE);
      }
    }
  }

  return $memberships_count;
}

/**
 * Set value in field_rp_qualification field.
 */
function _vu_rp_demo_random_field_qualifications($node) {
  $qualification_count = rand(1, 5);

  for ($i = 0; $i < $qualification_count; $i++) {
    vu_rp_demo_set_field_value('QUALIFICATION#' . ($i + 1) . '_' . Random::lipsum(rand(1, 4)) . '?', $node, 'field_rp_qualification', 'value', $i);
  }

  return $qualification_count;
}

/**
 * Create expertise entries.
 */
function _vu_rp_demo_random_field_expertise($node) {
  $tids = [];

  $count = rand(0, 10);
  for ($i = 0; $i < $count; $i++) {
    $tid = vu_rp_demo_random_term('expertise')->tid;
    vu_rp_demo_set_field_value($tid, $node, 'field_rp_expertise', 'target_id');
    $tids[] = $tid;
  }

  return $tids;
}

/**
 * Set field value in field_rp_related_links field.
 */
function _vu_rp_demo_random_field_related_links($node) {
  if (empty($node)) {
    return 0;
  }

  $related_links_count = rand(0, 3);

  for ($i = 0; $i < $related_links_count; $i++) {
    $node->field_rp_related_links[LANGUAGE_NONE][] = [
      'url' => 'https://' . Random::path() . '.com',
      'title' => 'RL#' . ($i + 1) . '_' . Random::lipsum(rand(2, 5)),
    ];
  }

  return $related_links_count;
}
