<?php

/**
 * @file
 * Update International semester.
 */

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'node');
$query->entityCondition('bundle', 'courses');
$query->fieldCondition('field_int_sem_int', 'value', '', '<>');
$results = $query->execute();

if (isset($results['node']) && !empty($results['node'])) {
  $nodes = entity_load('node', array_keys($results['node']));

  foreach ($nodes as $node) {
    $intake = vu_core_extract_single_field_value($node, 'node', 'field_int_sem_int');
    if (!empty($intake)) {
      $variables = [
        'node' => $node,
      ];

      $intake = vu_courses_international_intake_from_xml($variables);

      if (!empty($intake)) {
        $newNode = new StdClass();
        $newNode->nid = $node->nid;
        $newNode->type = $node->type;

        $newNode->field_int_sem_int[$node->language][0] = [
          'value' => $intake,
          'format' => 'filtered_html',
        ];

        field_attach_update('node', $newNode);

        entity_get_controller('node')
          ->resetCache([$node->nid]);
      }
    }
  }
}
