<?php
/**
 * @file
 * vu_core.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function vu_core_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'courses_atar_profile_data';
  $feeds_importer->config = array(
    'name' => 'ATAR Student Profile Data',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'SharedImporterNodeProcessor',
      'config' => array(
        'use_importer_id' => 0,
        'use_feed_nid' => 0,
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'code',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'pastHighedStudents',
            'target' => 'field_he_study:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'pastHighedPercentage',
            'target' => 'field_he_study:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'pastVeStudents',
            'target' => 'field_ve_study:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'pastVePercentage',
            'target' => 'field_ve_study:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'pastSecondaryStudentsAtarOnly',
            'target' => 'field_se_atar_only:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'pastSecondaryAtarOnlyPercentage',
            'target' => 'field_se_atar_only:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'pastSecondaryStudentsAtarPlus',
            'target' => 'field_se_atar_plus:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'pastSecondaryAtarPlusPercentage',
            'target' => 'field_se_atar_plus:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'pastSecondaryStudentsNoAtar',
            'target' => 'field_se_na:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'pastSecondaryAtarNoAtarPercentage',
            'target' => 'field_se_na:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'pastWorklifeStudents',
            'target' => 'field_work_life:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'pastWorklifePercentage',
            'target' => 'field_work_life:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'pastinternational',
            'target' => 'field_international_study:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'pastInternationalPercentage',
            'target' => 'field_international_study:second',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'total',
            'target' => 'field_total_study:first',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'totalPercentage',
            'target' => 'field_total_study:second',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '0',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'courses',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['courses_atar_profile_data'] = $feeds_importer;

  return $export;
}
