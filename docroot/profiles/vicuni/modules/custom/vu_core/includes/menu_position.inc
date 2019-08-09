<?php

/**
 * @file
 * Menu position module integration.
 */

/**
 * Implements hook_menu_position_rule_alter().
 */
function vu_core_menu_position_rule_alter(&$rule, array &$context, &$rule_matches, &$set_breadcrumb) {
  // Disable the rule if we're looking at a node with a certain id.
  if (isset($context['node'])) {
    if (($context['node']->type == 'news') || ($context['node']->type == 'events')) {
      global $theme;
      if ($theme == 'vu') {
        $rule_matches = FALSE;
      }
    }
  }
}
