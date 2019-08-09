<?php

/**
 * @file
 * Captcha for webforms.
 */

if (module_exists('captcha_webform')) {

  $nids = db_select('node', 'n')
    ->fields('n', ['nid'])
    ->condition('type', 'webform')
    ->condition('status', 1)
    ->execute()
    ->fetchAllKeyed(0, 0);
  foreach ($nids as $nid) {
    db_insert('captcha_points')
      ->fields([
        'form_id' => 'webform_client_form_' . $nid,
        'captcha_type' => 'default',
      ])
      ->execute();
  }
}
