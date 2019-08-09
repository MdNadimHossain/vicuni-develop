<?php

/**
 * @file
 * List field predefined options module integration.
 */

/**
 * Implements hook_list_option_info().
 */
function vu_core_list_option_info() {
  $info['brands'] = [
    'label' => t('Brands'),
    'callback' => 'vu_core_list_options_brand',
  ];

  $info['theme'] = [
    'label' => t('Theme'),
    'callback' => 'vu_core_list_options_theme',
  ];

  $info['link_styles'] = [
    'label' => t('Link styles'),
    'callback' => 'vu_core_list_options_link_styles',
  ];

  $info['icons'] = [
    'label' => t('Font Awesome icons'),
    'callback' => 'vu_core_list_options_icons',
  ];

  $info['days'] = [
    'label' => t('Days'),
    'callback' => 'vu_core_list_options_days',
  ];

  $info['time'] = [
    'label' => t('Time'),
    'callback' => 'vu_core_list_options_time',
  ];

  return $info;
}

/**
 * Callback for the 'brands' list options.
 *
 * @return array
 *   The list options array.
 */
function vu_core_list_options_brand() {
  return [
    'centenary' => t('VU - Centenary'),
    'vicpoly' => t('Victoria Polytechnic'),
  ];
}

/**
 * Callback for the 'theme' list options.
 *
 * @param array $field
 *   The field.
 * @param mixed $instance
 *   The field instance.
 * @param string $entity_type
 *   The entity type.
 * @param object $entity
 *   The entity.
 *
 * @return array
 *   The list options array.
 */
function vu_core_list_options_theme($field, $instance, $entity_type, $entity) {
  $options = [
    'vu' => t('2015 theme'),
    'victory' => t('2017 theme'),
  ];

  // If we're in Behat, return keys as value.
  if (is_object($instance) && get_class($instance) == 'Drupal\Driver\Fields\Drupal7\ListTextHandler') {
    foreach ($options as $key => &$value) {
      $value = $key;
    }
  }

  return $options;
}

/**
 * Callback for the 'link_styles' list options.
 *
 * @return array
 *   The list options array.
 */
function vu_core_list_options_link_styles() {
  return [
    'tools' => t('Tools'),
    'contact' => t('Contact Us'),
  ];
}

/**
 * Callback for the 'icons' list options.
 *
 * @return array
 *   The list options array.
 */
function vu_core_list_options_icons() {
  return [
    'fa-exclamation-triangle' => 'Alert triangle',
    'fa-book' => 'Book',
    'fa-bullhorn' => 'Bull horn',
    'fa-calendar' => 'Calendar',
    'fa-check' => 'Checkmark',
    'fa-cogs' => 'Cogs',
    'fa-comments' => 'Comments',
    'fa-dollar' => 'Dollar',
    'fa-flask' => 'Flask',
    'fa-folder-o' => 'Folder',
    'fa-globe' => 'Globe',
    'fa-graduation-cap' => 'Graduation cap',
    'fa-info-circle' => 'Info circle',
    'fa-laptop' => 'Laptop',
    'fa-life-ring' => 'Life ring',
    'fa-map-marker' => 'Map marker',
    'fa-map-signs' => 'Map signs',
    'fa-pencil-square' => 'Pencil square',
    'fa-phone' => 'Phone',
    'fa-plane' => 'Plane',
    'fa-search' => 'Search',
    'fa-trophy' => 'Trophy',
    'fa-university' => 'University',
    'fa-user' => 'User',
    'fa-users' => 'Users',
  ];
}

/**
 * Callback for the 'days' list options.
 *
 * @return array
 *   The list options array.
 */
function vu_core_list_options_days() {
  $days = _vumain_get_week_days();
  return array_combine($days, $days);
}

/**
 * Callback for the 'time' list options.
 *
 * @return array
 *   The list options array.
 */
function vu_core_list_options_time() {
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

  return array_combine($times, $times);
}
