<?php

/**
 * @file
 * Drush commands for VU core.
 */

/**
 * Implements hook_drush_help().
 */
function vu_core_drush_help($section) {
  switch ($section) {
    case 'drush:vu-solr-index-delete':
      $help = dt('(vusid) Delete (not just clear) solr index.');
      break;
  }

  return $help;
}

/**
 * Implements hook_drush_command().
 */
function vu_core_drush_command() {
  return [
    'vu-solr-index-delete' => [
      'description' => dt('(vusid) Delete (not just clear) solr index.'),
      'aliases' => ['vusid'],
      'options' => [
        'dry-run' => 'Do not delete index, just display server information.',
      ],
    ],
  ];
}

/**
 * Callback for drush vu-solr-index-delete command.
 */
function drush_vu_core_vu_solr_index_delete() {
  $dryrun = drush_get_option('dry-run', FALSE);

  $th = [
    'Server ID',
    'Name',
    'Machine name',
    'Enabled',
    $dryrun === FALSE ? 'Deleted' : 'Would delete',
    'Options',
  ];

  $table = [$th];

  $solr_servers = search_api_server_load_multiple(FALSE, ['class' => 'acquia_search_service']);
  foreach ($solr_servers as $server_data) {
    $solr = $server_data->getSolrConnection();
    $server_options = $server_data->options;

    // Turn options array into a string for the table.
    $server_option_string = array_reduce(array_keys($server_options), function ($o, $i) use ($server_options) {
      return $o . $i . ': ' . $server_options[$i] . PHP_EOL;
    }, '');

    $tr = [
      $server_data->id,
      $server_data->name,
      $server_data->machine_name,
      $server_data->enabled ? 'Y' : 'N',
    ];

    if ($server_data->enabled) {
      $tr[] = 'Y';
      if ($dryrun === FALSE) {
        // Delete index entirely.
        $solr->deleteByQuery("*:*");
      }
    }
    else {
      $tr[] = 'N';
    }

    $tr[] = $server_option_string;
    $table[] = $tr;
  }
  drush_print_table($table, TRUE);
  if ($dryrun === FALSE) {
    drush_print(dt('Indexes deleted.'));
  }
  else {
    drush_print(dt('No indexes deleted.'));
  }
}
