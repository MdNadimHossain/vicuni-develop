<?php

/**
 * @file
 * Updated Info session links.
 */

$rows = db_select('field_data_field_info_session_link', 'd')
  ->fields('d', ['entity_id', 'field_info_session_link_url'])
  ->condition('field_info_session_link_url', '%' . db_like('victoriapolytechnic') . '%', 'LIKE')
  ->execute()
  ->fetchAll();

foreach ($rows as $row) {

  $updatedLink = str_replace('victoriapolytechnic', 'vupolytechnic', $row->field_info_session_link_url);
  if (!empty($updatedLink)) {
    db_update('field_data_field_info_session_link')
      ->fields(['field_info_session_link_url' => $updatedLink])
      ->condition('entity_id', $row->entity_id)
      ->execute();
  }

}
