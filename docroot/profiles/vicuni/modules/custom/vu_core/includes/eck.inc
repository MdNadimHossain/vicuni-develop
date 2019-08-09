<?php

/**
 * @file
 * Entity Construction Kit module integration.
 */

/**
 * Entity view callback for ECK entities.
 */
function vu_core_entity_eck_view_callback($entities, $view_mode, $langcode, $entity_type) {
  // Ensure that no full page view for ECK entities.
  if ('full' === $view_mode && arg(0) === $entity_type && !in_array($entity_type, ['contact_information'])) {
    return MENU_NOT_FOUND;
  }

  // Pass back through to the normal eck entity view callback.
  return eck__entity__view_callback($entities, $view_mode, $langcode, $entity_type);
}
