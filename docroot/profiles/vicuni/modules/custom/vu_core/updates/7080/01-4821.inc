<?php

/**
 * @file
 * Updates for PW-4821.
 *
 * Deleting international duration field on course.
 */

if ($instance = field_info_instance('node', 'field_imp_inter_duration', 'courses')) {
  field_delete_instance($instance);
}
