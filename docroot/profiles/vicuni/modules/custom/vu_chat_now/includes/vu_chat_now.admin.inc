<?php

/**
 * @file
 * Chat now admin functionality for the Victoria University Website.
 */

/**
 * Chat now admin form.
 */
function vu_chat_now_admin_form($form, &$form_state) {
  // Set the days of the week.
  $days = _vumain_get_week_days();
  // Make sure the keys and values are the same.
  $days = array_combine($days, $days);

  // Set the times.
  $times = [];
  $times['0'] = '-- : --';

  foreach (range(7, 24) as $hour) {
    foreach (range(0, 60, 30) as $minute) {
      $time = date(VU_CHAT_NOW_TIME_FORMAT, mktime($hour, $minute));
      $times[$time] = $time;
    }
  }

  foreach (range(1, 6) as $hour) {
    foreach (range(0, 60, 30) as $minute) {
      $time = date(VU_CHAT_NOW_TIME_FORMAT, mktime($hour, $minute));
      $times[$time] = $time;
    }
  }

  // Get the default options.
  $default_options = variable_get('vu_chat_now', []);

  $form['#tree'] = TRUE;

  $form['vu_chat_now'] = [
    '#theme' => 'vu_chat_now_admin_table',
  ];

  // Loop through the days.
  foreach ($days as $day) {
    // Update the 'Days Open'.
    $form['vu_chat_now'][$day]['days_open'] = [
      '#type' => 'checkbox',
      '#title' => $day,
      '#default_value' => !empty($default_options[$day]['days_open']) ? $default_options[$day]['days_open'] : 0,
    ];
    // Update the 'Start Times'.
    $form['vu_chat_now'][$day]['start_time'] = [
      '#type' => 'select',
      '#options' => $times,
      '#default_value' => !empty($default_options[$day]['start_time']) ? $default_options[$day]['start_time'] : '',
    ];
    // Update the 'End Times'.
    $form['vu_chat_now'][$day]['end_time'] = [
      '#type' => 'select',
      '#options' => $times,
      '#default_value' => !empty($default_options[$day]['end_time']) ? $default_options[$day]['end_time'] : '',
    ];
  }

  // Output the instructions.
  $form['instructions'] = [
    '#markup' => '<p>' . t('Place a checkmark next to each day that chat is open.<br>Select a start and end time for each day.') . '<br><br></p>',
  ];

  return system_settings_form($form);
}

/**
 * Chat now admin form: Validation.
 */
function vu_chat_now_admin_form_validate($form, &$form_state) {
  // Set default value for the number of open days.
  $open = 0;

  // Get the values.
  $values = $form_state['values'];

  // Loop through the values.
  foreach ($values['vu_chat_now'] as $day => $options) {
    // If the days_open value is not set.
    if (!$options['days_open']) {
      // Nothing to process, continue.
      continue;
    }

    // Increase the open days by one.
    $open++;

    // Get the start time.
    $start_time = $options['start_time'];
    // Get the end time.
    $end_time = $options['end_time'];

    // Set the args for the day.
    $args = [
      '@day' => $day,
    ];

    // Make sure start and end times are selected.
    if (empty($start_time) || empty($end_time)) {
      form_set_error("vu_chat_now][" . $day, t('Please select start and end times for @day', $args));
    }
    // Make sure the start time is before the end time.
    elseif (strtotime($start_time) > strtotime($end_time) || strtotime($start_time) == strtotime($end_time)) {
      form_set_error("vu_chat_now][" . $day, t('The start time must be earlier than the end time for @day', $args));
    }
  }

  // If there are no open days.
  if (!$open) {
    drupal_set_message(t('Warning - there are no selected open days for chatting.'), 'warning');
  }
}
