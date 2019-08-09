<?php

/**
 * @file
 * Workflow moderation module integration.
 */

/**
 * Implements hook_vu_core_query_alter().
 */
function workbench_moderation_vu_core_query_alter(QueryAlterableInterface $query) {
  // Re-order the workflow moderation table to order by timestamp.
  if ($query instanceof PagerDefault && key($query->getOrderBy()) == 'r.vid') {
    $order =& $query->getOrderBy();
    unset($order['r.vid']);
    $query->orderBy('r.timestamp', 'DESC')->orderBy('r.vid', 'DESC');
  }
}

/**
 * Implements hook_vu_core_node_presave().
 */
function workbench_moderation_vu_core_node_presave_alter($node) {
  if (isset($node->nid)) {
    $vu_core_410_paths = variable_get('vu_core_410_paths', []);
    $is_410 = isset($vu_core_410_paths["node/{$node->nid}"]);

    // If page is unpublished, ensure it gets 410'd.
    if (isset($node->workbench_moderation['published']) && !$node->status && !$is_410) {
      $vu_core_410_paths["node/{$node->nid}"] = "node/{$node->nid}";
      variable_set('vu_core_410_paths', $vu_core_410_paths);
    }

    // If page is published, ensure it doesn't get 410'd.
    elseif (!isset($node->workbench_moderation['published']) && $node->status && $is_410) {
      unset($vu_core_410_paths["node/{$node->nid}"]);
      variable_set('vu_core_410_paths', $vu_core_410_paths);
    }
  }

  if (isset($node->_timestamp)) {
    $node->timestamp = $node->_timestamp;
  }
}

/**
 * Implements hook_block_view_alter().
 */
function workbench_moderation_vu_core_block_view_alter(&$data, $block) {
  if (empty($block->bid) || $block->bid !== 'workbench-block' || $block->module !== 'workbench') {
    return;
  }
  $data['content']['#markup'] = '<div class="container">' . $data['content']['#markup'] . '</div>';
}
