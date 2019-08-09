<?php

/**
 * @file
 * PW-4767 - Enable bean_blocks_overview view.
 */

// A list of views (their view name) I want to disable.
$viewname = 'bean_blocks_overview';

// Grab list of views that are already disabled.
$views_status = variable_get('views_defaults', []);

// Add our views to be disabled to the list.
$views_status[$viewname] = FALSE;

// Reset the variable with the new list.
variable_set('views_defaults', $views_status);

// Empty cache now.
if (function_exists('views_invalidate_cache')) {
  views_invalidate_cache();
}
