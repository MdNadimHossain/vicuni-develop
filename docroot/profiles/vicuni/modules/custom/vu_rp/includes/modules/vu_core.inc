<?php

/**
 * @file
 * VU Core module integration.
 */

/**
 * Implements hook_vu_core_taxonomy_term_page_access().
 */
function vu_rp_vu_core_taxonomy_term_page_access($permission, $taxonomy_term) {
  $rp_vocabs = [
    'membership_levels',
    'membership_organisations',
    'research_institutes',
  ];

  // Prohibit access to term pages from RP vocabularies to anonymous users.
  return in_array($taxonomy_term->vocabulary_machine_name, $rp_vocabs) ? !user_is_anonymous() : NULL;
}
