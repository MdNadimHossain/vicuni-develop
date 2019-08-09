<?php

/**
 * @file
 * PW-3327 - Add all hero title box beans to the hero title box entityqueues.
 */

$entities = entity_load('bean', FALSE, ['type' => 'hero_title_box']);

usort($entities, function ($a, $b) {

  if ($a->field_hero_title_box_order[LANGUAGE_NONE][0]['value'] == $b->field_hero_title_box_order[LANGUAGE_NONE][0]['value']) {
    return 0;
  }
  elseif ($a->field_hero_title_box_order[LANGUAGE_NONE][0]['value'] > $b->field_hero_title_box_order[LANGUAGE_NONE][0]['value']) {
    return 1;
  }
  else {
    return -1;
  }
});

$subqueue = entityqueue_subqueue_load('hero_title_box');

$queue = entityqueue_queue_load($subqueue->queue);
$field_name = _entityqueue_get_target_field_name($queue->target_type);
$subqueue->{$field_name}[LANGUAGE_NONE] = [];

foreach ($entities as $bean) {
  $subqueue->{$field_name}[LANGUAGE_NONE][] = [
    'target_id' => $bean->bid,
  ];
}

entity_save('entityqueue_subqueue', $subqueue);
