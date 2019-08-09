<?php

/**
 * @file
 * Chat now preprocess functions.
 */

/**
 * Template preprocess: vu_chat_now_times.
 */
function vu_chat_now_preprocess_vu_chat_now_times(&$variables) {
  _vu_chat_now_times($variables);
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vu_chat_now_preprocess_vu_any_question_block(&$variables) {
  _vu_chat_now_times($variables);
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vu_chat_now_preprocess_vu_chat_box_landing_pages(&$variables) {
  vu_chat_now_preprocess_vu_chat_footer($variables);

  // Landing pages changes.
  $variables['online_chat_hours'] = t("View online chat hours");

  // Message on cached pages.
  drupal_add_js(['vu_chat_landing_pages' => 1], 'setting');
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vu_chat_now_preprocess_vu_chat_footer(&$variables) {
  drupal_add_js(libraries_get_path('moment') . '/min/moment-with-locales.min.js', ['weight' => -2]);
  drupal_add_js(libraries_get_path('moment-timezone') . '/builds/moment-timezone-with-data.min.js', ['weight' => -1]);
  drupal_add_js(drupal_get_path('module', 'vu_chat_now') . '/js/vu_chat_footer.js');

  $times = _vu_chat_now_return_times_open();

  // Get current chat state for provided time config.
  $chat_state = _vu_chat_now_get_chat_state($times);

  $vars = [];
  $vars['is_open'] = $chat_state['is_open'];
  $vars['open_title'] = t('Chat now');
  $vars['close_title'] = t('Chat closed');
  $vars['open_message'] = t('Chat with us online');
  $vars['close_message'] = t('Chat is currently closed');
  $vars['url'] = 'https://gotovu.custhelp.com/app/home?initchat=true';

  if ($chat_state['start'] && $chat_state['finish']) {
    $vars['start'] = date("ga", strtotime($chat_state['start']));
    $vars['finish'] = date("ga", strtotime($chat_state['finish']));
    $vars['weekday'] = substr($chat_state['weekday'], 0, 3);
  }

  $vars['hours_open_title'] = t("Today's chat hours:");
  $vars['hours_close_title'] = t('Chat will reopen:');
  $vars['hours_timezone'] = date('I') === '1' ? t('AEDT') : t('AEST');

  // Add all variables to JS settings to have access to them from JS in order
  // to replace content on the client side. This is required to update chat
  // message on cached pages.
  drupal_add_js(['vu_chat_footer' => $vars + ['times' => $times]], 'setting');
  $variables += $vars;

}

/**
 * General functionality.
 */
function _vu_chat_now_times(&$variables) {
  // Work out the timezone.
  if (date('I') === '1') {
    $timezone = 'AEDT';
  }
  else {
    $timezone = 'AEST';
  }

  // Set default value/s.
  $open_times = [];

  // Get all the days of the week.
  $days = _vumain_get_week_days();

  // Get the open days.
  $days_open = _vu_chat_now_return_times_open();

  // If there is at least one open day.
  if (!empty($days_open)) {
    $output = [];

    // Loop through all the days of the week.
    foreach ($days as $i => $day) {
      // If this day has an open time.
      if (array_key_exists($day, $days_open) && $i > 0) {
        $yesterday = $days[$i - 1];
        // Consecutive days.
        if (array_key_exists($yesterday, $days_open)) {
          if (date('w', strtotime($yesterday)) == (date('w', strtotime($day) - 1))) {
            // Not the same times, so split up this range of days.
            if (!_vu_chat_now_compare_times($days_open[$yesterday], $days_open[$day])) {
              $output[] = '#';
            }
          }
        }
      }

      // Update the output.
      $output[] = array_key_exists($day, $days_open) ? $day : '#';
    }

    // Clean up separate days.
    $output = implode('#', $output);
    $output = trim($output, '#');

    // Split into ranges: days that are two or more apart.
    $output = preg_split('/##+/', $output, NULL, PREG_SPLIT_NO_EMPTY);

    // Hyphenate ranges and produce array of collated days/times.
    foreach ($output as $day_string) {
      // Update the output of the day string (in the format Monday-Wednesday).
      $day_string = preg_replace('/#(\w+#)*/', '-', $day_string);

      // Get the individual day.
      $day = explode('-', $day_string);
      $day = $day[0];
      // Get times for each day.
      $times = [
        $days_open[$day]['start_time'],
        $days_open[$day]['end_time'],
      ];
      // Update the open times.
      $open_times[$day_string] = $times;
    }
  }

  // Add the variable/s to the template.
  $variables['timezone'] = $timezone;
  $variables['open_times'] = $open_times;

  drupal_add_js(libraries_get_path('moment') . '/min/moment-with-locales.min.js', ['weight' => -2]);
  drupal_add_js(libraries_get_path('moment-timezone') . '/builds/moment-timezone-with-data.min.js', ['weight' => -1]);
  drupal_add_js(drupal_get_path('module', 'vu_chat_now') . '/js/vu_chat_now.js');

  // Add availability to JS settings.
  $open_message = t('Chat online with one of our friendly staff.');
  $close_message = t('Online chat is currently unavailable.');
  $chat_days = [
    'chat_now' => [
      'dates' => _vu_chat_now_return_times_open(),
      'open_message' => $open_message,
      'close_message' => $close_message,
    ],
  ];
  drupal_add_js($chat_days, 'setting');
}
