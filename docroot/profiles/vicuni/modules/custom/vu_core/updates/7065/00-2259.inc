<?php

/**
 * @file
 * Updates for [PW-2259].
 *
 * Updates course title to remove course code from TAFE course titles.
 */

use Drupal\drupal_helpers\General;

General::messageSet('Removing course code from TAFE and short course titles.');
// This updates published TAFE and short courses.
// We ignore coding standards because this query can't be written as db_update.
// @codingStandardsIgnoreStart
$row_count = db_query(
  "UPDATE 
    {node_revision} nr
    INNER JOIN 
      {node} n 
        ON 
          n.nid = nr.nid 
    INNER JOIN 
      {field_revision_field_unit_lev} l 
        ON
          n.vid = l.revision_id
    SET 
      nr.title = SUBSTRING(nr.title, LOCATE(' - ', nr.title) + 3),
      n.title = SUBSTRING(nr.title, LOCATE(' - ', nr.title) + 3)
    WHERE
        n.type='courses' 
      AND
        n.status = 1
      AND 
        l.field_unit_lev_value IN ('tafe', 'short')
      AND 
        nr.vid >= n.vid
      AND 
        nr.title REGEXP BINARY :regex",
  [':regex' => '^[A-Z0-9]{4,12} - '],
  ['return' => Database::RETURN_AFFECTED]
);
// @codingStandardsIgnoreEnd

General::messageSet("Updated $row_count titles (current and pending revisions).");

// Remove the field that was used to generate the alias.
field_delete_field('field_url_alias_title');
field_purge_batch(0);
