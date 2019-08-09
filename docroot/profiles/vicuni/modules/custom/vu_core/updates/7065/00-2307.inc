<?php

/**
 * @file
 * Updates for [PW-2307].
 *
 * Remove the old campaign bean and add the new hero banner one.
 */

use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Feature;

$old_campaign_bean_delta = 'campaign-opportunity-and-success';

$bean = bean_load_delta($old_campaign_bean_delta);
if (!empty($bean)) {
  bean_delete($bean);
  General::messageSet('Deleted bean: ' . $old_campaign_bean_delta);
}

// Revert features.
Feature::revert('vu_core');

// Adds custom 'Hero banner' Bean.
$world_class_link = 'https://www.vu.edu.au/world-class';
$bean = bean_create(['type' => 'hero_title_box']);
$bean->label = 'World-class campaign';
$bean->title = '<none>';
$bean->delta = 'world-class-hero-title-box';
$bean->field_hero_banner_headline[LANGUAGE_NONE][0] = [
  'value' => t('Our MBA is ranked #2 in Victoria'),
];
$bean->field_hero_banner_message[LANGUAGE_NONE][0] = [
  'value' => t('Find out more about VU\'s <a href="@world-class-link" title="world-class courses" target="_blank">world-class courses</a>', ['@world-class-link' => $world_class_link]),
  'format' => 'filtered_html',
];

// Some file on our system.
if (variable_get('environment') != 'ci') {
  $directory = 'public://images/hero_title_box';
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

  $url = 'https://d6web.vu.edu.au/sites/default/files/hero-title-melbourne-cityscape-sunset.jpg';
  $image = file_get_contents($url);
  if (!empty($image)) {
    $file = file_save_data($image, $directory . '/hero-title-melbourne-cityscape-sunset.jpg', FILE_EXISTS_REPLACE);
    $bean->field_image[LANGUAGE_NONE][0] = (array) $file;
  }
  else {
    throw new DrupalUpdateException(t('The specified file was not found in the location: @url.', ['@url' => $url]));
  }
}
$bean->save();
