<?php

/**
 * @file
 * Updates for [PW-2364].
 *
 * Adds the new hero banner bean.
 */

use Drupal\drupal_helpers\Feature;

// Revert features.
Feature::revert('vu_core');

$content = [
  [
    'title' => t('Top 20 globally in sport'),
    'delta' => 'top-20-sport-hero-banner',
    'text' => t('Find out more about why VU are <a href="@link" title="leaders in sport" target="_blank">leaders in sport</a>'),
    'link' => '/study-at-vu/why-choose-vu/leaders-in-sport',
    'note' => t('Source: Shanghai Ranking, Academic Ranking of World Universities.'),
    'image' => 'https://d6web.vu.edu.au/sites/default/files/top-20-sport.jpg',
  ],
  [
    'title' => t('A study model designed to help you succeed'),
    'delta' => 'first-year-model-hero-banner',
    'text' => t('Find out more about our <a href="@link" title="first-year model" target="_blank">first-year model</a>'),
    'link' => '/about-vu/university-profile/teaching-learning-at-vu/our-first-year-model',
    'note' => '',
    'image' => 'https://d6web.vu.edu.au/sites/default/files/first-year-study-model.jpg',
  ],
];

foreach ($content as $values) {
  $bean = bean_create(['type' => 'hero_banner']);
  $bean->label = 'Hero banner - ' . $values['title'];
  $bean->title = '<none>';
  $bean->delta = $values['delta'];
  $bean->field_hero_banner_headline[LANGUAGE_NONE][0] = [
    'value' => $values['title'],
  ];

  $bean->field_hero_banner_message[LANGUAGE_NONE][0] = [
    'value' => str_replace('@link', $values['link'], $values['text']),
    'format' => 'filtered_html',
  ];

  if (!empty($values['note'])) {
    $bean->field_hero_banner_note[LANGUAGE_NONE][0] = [
      'value' => $values['note'],
    ];
  }

  // Some file on our system.
  if (variable_get('environment') != 'ci') {
    $directory = 'public://images/hero_banner';
    file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    $image = file_get_contents($values['image']);
    if (!empty($image)) {
      $file_name = basename($values['image']);
      $file = file_save_data($image, $directory . '/' . $file_name, FILE_EXISTS_REPLACE);
      $bean->field_image[LANGUAGE_NONE][0] = (array) $file;
    }
    else {
      throw new DrupalUpdateException(t('The specified file was not found in the location: @url.', ['@url' => $values['image']]));
    }
  }
  $bean->save();
}
