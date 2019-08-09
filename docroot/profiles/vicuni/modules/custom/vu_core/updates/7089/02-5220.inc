<?php

/**
 * @file
 * PW-5220 - Update search link.
 */

use Drupal\drupal_helpers\Menu;

Menu::updateItem('main-menu', ['link_title' => 'Search'], [
  'options' => [
    'attributes' => [
      'class' => [
        'search',
        'js-responsive-menu-ignore',
        'shutter-trigger',
      ],
      'aria-hidden' => TRUE,
      'aria-pressed' => FALSE,
      'data-toggle' => 'modal',
      'data-target' => '.region-shutter',
      'data-shutter-item-target' => '#block-vu-core-vu-funnelback-search',
    ],
  ],
]);
