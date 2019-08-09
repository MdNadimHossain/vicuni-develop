<?php

/**
 * @file
 * Administrative page callbacks for VU Researcher Profiles Log module.
 */

/**
 * Page callback to view log record.
 */
function vu_rp_log_record_view_callback($id) {
  $output = '';

  $record = vu_rp_log_record_load($id);

  $items = [
    'Event' => $record['event'],
    'Timestamp' => format_date(intval($record['timestamp']), 'short'),
    'Severity' => $record['severity'],
    'Message' => '<pre><code style="font-size: .8em">' . htmlspecialchars($record['message']) . '</code></pre>',
  ];

  foreach ($items as $title => $item) {
    $output .= '<div>';
    $output .= '<h2>' . $title . '</h2>';
    $output .= '<p>' . $item . '</p>';
    $output .= '</div>';
  }

  $output .= '<div class="admin-panel">';
  $output .= l(t('<- Back to the log'), 'admin/config/researcher-profile/log');
  $output .= '</div>';

  return $output;
}

/**
 * Menu callback to clear all log records.
 */
function vu_rp_log_record_clear_callback() {
  vu_rp_log_record_delete_all();
  drupal_set_message(t('Log records successfully cleared.'));
  drupal_goto('admin/config/researcher-profile/log');
}
