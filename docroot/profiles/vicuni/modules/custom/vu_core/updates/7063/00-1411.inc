<?php

/**
 * @file
 * Updates for [PW-1411].
 *
 * Updates published nodes incorrectly marked as drafts in workbench moderation.
 */

use Drupal\drupal_helpers\General;

// Show some information about the nodes to be updated.
$select_query = db_select('workbench_moderation_node_history', 'h');
$select_query->fields('n', ['nid', 'vid', 'title', 'type']);
$select_query->innerJoin('node', 'n', 'n.nid = h.nid AND n.vid = h.vid');
$select_query->condition('n.status', 1);
$moderation_state = db_or()
  ->condition('h.published', 1, '<>')
  ->condition('h.state', 'published', '<>');
$select_query->condition($moderation_state);
$select_query->condition('h.is_current', 1);

$result = $select_query->execute();
$selected_rows = $result->rowCount();

General::messageSet("$selected_rows published nodes to be updated to published in workbench.");
General::messageSet('============ [nid|vid] Title (type) ============');

foreach ($result as $node) {
  General::messageSet(sprintf('[%s|%s] %s (%s)', $node->nid, $node->vid, $node->title, $node->type));
}
General::messageSet('============');
General::messageSet('Performing update.');

// Run a query to set the status to match what's in the node table.
// Ignore phpcs warning because db_update doesn't support any join methods.
// @codingStandardsIgnoreStart
$rows_affected = db_query("UPDATE
  {workbench_moderation_node_history} h
INNER JOIN
  {node} n
ON
  n.nid = h.nid AND n.vid = h.vid
SET
  h.published = 1,
  h.state = 'published',
  h.from_state = 'published'
WHERE 
  n.status
AND
  (not h.published OR h.state <> 'published')
AND
  is_current", [], ['return' => Database::RETURN_AFFECTED]);
// @codingStandardsIgnoreEnd

General::messageSet("Updated $rows_affected rows from broken state to published.");
