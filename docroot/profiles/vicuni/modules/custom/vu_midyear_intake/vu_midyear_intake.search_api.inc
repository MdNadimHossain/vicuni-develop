<?php
/**
 * @file
 * VU Midyear Intake Search API hooks.
 */

/**
 * Implements hook_search_api_query_alter()
 *
 * Conditionally add a facet to search when Mid-Year Intake is enabled.
 *
 * @param SearchApiQueryInterface $query
 */
function vu_midyear_intake_search_api_query_alter(SearchApiQueryInterface $query) {
  $search_index_name = variable_get('vu_midyear_intake_search_index', 'course_index');
  $search_index = $query->getIndex();
  // Only alter search query when using Search API Database.
  if ($search_index->machine_name == $search_index_name
    && $search_index->server == 'search_api_db_service'
  ) {
    if (!vu_midyear_intake_is_enabled()) {
      // Remove the facet on the fly if it exists.
      if ($facets = $query->getOption('search_api_facets')) {
        if (isset($facets['field_course_midyear_intake'])) {
          unset($facets['field_course_midyear_intake']);
          $query->setOption('search_api_facets', $facets);
        }
      }
    }
    else {
      // Always set the facet on.
      $q = drupal_get_query_parameters();
      if (!empty($q['type']) && $q['type'] == VU_MIDYEAR_INTAKE_SEARCH_TYPE) {
        $filter = $query->createFilter('AND');
        $filter->condition('field_course_midyear_intake', 1);
        $query->getFilter()->filter($filter);
      }
    }
  }
}

/**
 * Implements hook_search_api_solr_query_alter().
 *
 * Conditionally add a filter to Solr search query when Mid-Year Intake is
 * enabled.
 *
 * @param array $call_args
 * @param SearchApiQueryInterface $query
 */
function vu_midyear_intake_search_api_solr_query_alter(&$call_args, $query) {
  $search_index_name = variable_get('vu_midyear_intake_search_index', 'course_index');
  $search_index = $query->getIndex();

  if ($search_index->machine_name == $search_index_name) {
    if (!vu_midyear_intake_is_enabled() || vu_core_is_non_resident_search()) {
      if (!empty($call_args['params']['fq'])
        && $key = array_search('bs_field_course_midyear_intake:true', $call_args['params']['fq'])
      ) {
        unset($call_args['params']['fq'][$key]);
      }
    }
    else {
      $q = drupal_get_query_parameters();
      if (!empty($q['type']) && $q['type'] == VU_MIDYEAR_INTAKE_SEARCH_TYPE) {
        $call_args['params']['fq'][] = 'bs_field_course_midyear_intake:true';
      }
    }
  }
}
