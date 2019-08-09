<?php

/**
 * @file
 * Updates for [PW-1447].
 */

use Drupal\drupal_helpers\Menu;

Menu::updateItem('main-menu', ['link_title' => 'Student email', 'external' => 1], [
  'options' => [
    'attributes' => [
      'class' => [
        'fa-prefix',
        'fa-envelope',
        'ext',
      ],
    ],
  ],
]);
