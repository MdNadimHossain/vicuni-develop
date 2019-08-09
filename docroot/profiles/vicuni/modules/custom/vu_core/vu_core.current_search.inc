<?php
/**
 * @file
 * vu_core.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function vu_core_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'course_search';
  $item->label = 'Course Search';
  $item->settings = array(
    'items' => array(
      'result_count' => array(
        'id' => 'text',
        'label' => 'Result Count',
        'text' => 'Showing [facetapi_results:result-count] @search-type-single for \'<em>[facetapi_results:keys]</em>\'.',
        'plural' => 1,
        'text_plural' => 'Showing [facetapi_results:result-count] @search-type-plural for \'<em>[facetapi_results:keys]</em>\'.',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'p',
        'css' => 1,
        'classes' => 'results-count',
        'weight' => '-49',
      ),
      'result_count_without_keyword' => array(
        'id' => 'text',
        'label' => 'Result Count Without Keyword',
        'text' => 'Showing [facetapi_results:result-count] @search-type-single.',
        'plural' => 1,
        'text_plural' => 'Showing [facetapi_results:result-count] @search-type-plural.',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'p',
        'css' => 1,
        'classes' => 'results-count',
        'weight' => '-48',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'Active items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 0,
        'css' => 1,
        'classes' => 'active-filters-list',
        'nofollow' => 1,
        'weight' => '-47',
      ),
      'reset_filters' => array(
        'id' => 'reset_filters',
        'label' => 'Reset Filters',
        'text' => '×',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '-46',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['course_search'] = $item;

  return $export;
}
