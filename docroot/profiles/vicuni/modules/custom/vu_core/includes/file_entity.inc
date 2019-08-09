<?php

/**
 * @file
 * File entity module integration.
 */

/**
 * Implements hook_file_entity_access().
 */
function vu_core_file_entity_access($op, $file, $account) {
  // Allow access to Video file type.
  if ('view' === $op && 'video' === $file->type) {
    return FILE_ENTITY_ACCESS_ALLOW;
  }
}
