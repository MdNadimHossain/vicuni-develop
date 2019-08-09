<?php
/**
 * @file
 * vu_core.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function vu_core_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'hero_title_box';
  $queue->label = 'Hero Title Box';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'bean';
  $queue->settings = array(
    'target_bundles' => array(
      'hero_title_box' => 'hero_title_box',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['hero_title_box'] = $queue;

  return $export;
}
