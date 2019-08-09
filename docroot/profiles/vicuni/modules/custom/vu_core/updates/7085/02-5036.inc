<?php

/**
 * @file
 * Update international fees.
 */

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'node');
$query->entityCondition('bundle', 'courses');
$query->fieldCondition('field_international_fees', 'value', '', '<>');
$results = $query->execute();

if (isset($results['node']) && !empty($results['node'])) {
  $nodes = entity_load('node', array_keys($results['node']));

  foreach ($nodes as $node) {

    $int_fee = vu_core_extract_single_field_value($node, 'node', 'field_international_fees');
    if (!empty($int_fee)) {

      $fees = vu_courses_international_fees_from_node($node);
      if (!empty($fees)) {

        $newNode = new StdClass();
        $newNode->nid = $node->nid;
        $newNode->type = $node->type;

        $newNode->field_international_fees[$node->language][0] = [
          'value' => $fees,
          'format' => 'filtered_html',
        ];

        field_attach_update('node', $newNode);

        entity_get_controller('node')
          ->resetCache([$node->nid]);
      }
    }
  }
}
