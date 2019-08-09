<?php

/**
 * @file
 * Custom rule actions related to link management.
 */

/**
 * Implements hook_rules_action_info().
 */
function link_management_rules_action_info() {
  return [
    'email_linked_pages' => [
      'label' => t('Email linked pages'),
      'group' => t('VU'),
      'parameter' => [
        'node' => [
          'type' => 'node',
          'label' => t('Current Node'),
        ],
      ],
      'base' => 'link_management_rules_action_email_linked_pages',
    ],
  ];
}
