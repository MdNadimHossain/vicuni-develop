<?php

/**
 * @file
 * PW-5444 - Add custom field to search index.
 */

$index = search_api_index_load('course_index', TRUE);

$fields = [
  'options' => $index->options,
];

$fields['options']['fields']['course_duration_hours'] = [
  'type' => 'integer',
];

search_api_index_edit($index->id, $fields);

cache_clear_all('search_api', 'cache', TRUE);
