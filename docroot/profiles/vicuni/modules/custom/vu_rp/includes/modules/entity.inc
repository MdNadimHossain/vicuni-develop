<?php

/**
 * @file
 * Entity module integration.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function vu_rp_entity_property_info_alter(&$info) {
  // Add custom field to staff profile.
  // This is added to all existing staff profile nodes to save
  // the supervision status. This value isnt present on
  // existing nodes and is needed to filter search results.
  if (isset($info['node']['bundles']['staff_profile']['properties'])) {
    $properties = &$info['node']['bundles']['staff_profile']['properties'];
    $properties['supervisor_unknown'] = [
      'label' => t('Supervisor Unknown'),
      'description' => t('Supervisor Status'),
      'type' => 'boolean',
      'getter callback' => 'vu_rp_get_supervisor_status',
    ];
  }
}

/**
 * Property info callback to get supervisor unknown status.
 *
 * @param stdclass $item
 *   Node object.
 *
 * @return true
 *   Returns true for staf profiles.
 */
function vu_rp_get_supervisor_status($item) {
  if ($item->type == 'staff_profile') {
    return TRUE;
  }

  return NULL;
}
