<?php

/**
 * @file
 * Updates for [PW-2509].
 *
 * Retroactively 410 previously published pages.
 */

$vu_core_410_paths = variable_get('vu_core_410_paths', []);
$query = db_select('workbench_moderation_node_history', 'w');
$query->join('node', 'n', 'n.nid = w.nid');
$nodes = $query
  ->fields('w', ['nid'])
  ->condition('n.status', FALSE)
  ->condition('w.is_current', TRUE)
  ->condition('w.published', FALSE)
  ->condition('w.state', 'draft')
  ->execute()
  ->fetchCol(0);
foreach ($nodes as $nid) {
  $was_published = (bool) db_select('workbench_moderation_node_history', 'w')
    ->fields('w')
    ->condition('nid', $nid)
    ->condition('state', 'published')
    ->execute()
    ->rowCount();
  if ($was_published) {
    $vu_core_410_paths["node/{$nid}"] = "node/{$nid}";
  }
}
variable_set('vu_core_410_paths', $vu_core_410_paths);
