<?php

/**
 * @file
 * Search API module integration.
 */

/**
 * Implements hook_search_api_index_load().
 */
function vu_core_search_api_index_load($indexes) {
  // Check if we are dealing with features, either via the UI or CLI.
  $features = FALSE;
  if (arg(2) == 'features') {
    $features = TRUE;
  }
  elseif (drupal_is_cli() && function_exists('drush_main') && strpos(drush_get_context('command')['command'], 'features') === 0) {
    $features = TRUE;
  }

  // If we are dealing with features, set the `read_only` property to FALSE.
  if ($features) {
    foreach ($indexes as $index) {
      $index->read_only = "0";
    }
  }
}

/**
 * Implements hook_search_api_query_alter().
 *
 * Conditionally add a facet to search for b3 courses.
 */
function vu_core_search_api_query_alter(SearchApiQueryInterface $query) {

  $search_index = $query->getIndex();
  // Only alter search query when using Search API Database.
  if ($search_index->machine_name == 'course_index'
    && $search_index->server == 'search_api_db_service'
  ) {
    // Always set the facet on.
    $q = drupal_get_query_parameters();
    if (!empty($q['date'])) {
      $filter = $query->createFilter('AND');
      $filter->condition('commencement_date', filter_var($q['date'], FILTER_SANITIZE_STRING));
      $query->getFilter()->filter($filter);
    }
  }
}
