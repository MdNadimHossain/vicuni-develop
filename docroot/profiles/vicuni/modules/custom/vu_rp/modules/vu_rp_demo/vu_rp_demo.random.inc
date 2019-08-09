<?php

/**
 * @file
 * VU Researcher Profile Demo random generators.
 */

use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Random;

/**
 * Return "Lorem Ipsum" content with cache support.
 */
function vu_rp_demo_random_lipsum($count = 10, $type = 'words', $html = FALSE) {
  if (empty($count)) {
    return '';
  }
  $items = &drupal_static(__FUNCTION__, []);

  $cid = implode('__', [$count, $type, (int) $html]);
  if (empty($items[$cid])) {
    $items[$cid] = Random::lipsum($count, $type, $html);
  }

  return $items[$cid];
}

/**
 * Helper to get single random array item.
 */
function vu_rp_demo_random_array_item($array) {
  $array_items = Random::arrayItems($array, 1);

  return reset($array_items);
}

/**
 * Helper to randomly distribute values into array of set length.
 */
function vu_rp_demo_random_distribute_values_percentage($values, $total, $min, $max) {
  $count = floor($total * rand($min, $max) / 100);

  shuffle($values);

  $out = array_fill(0, $total, NULL);
  $keys = Random::arrayItems(array_keys($out), $count);
  $values = array_slice($values, 0, min(count($values), $count, $total));

  $out = array_combine($keys, $values) + $out;
  ksort($out);

  return $out;
}

/**
 * Get random user by optional role name.
 */
function vu_rp_demo_random_user($role_name = FALSE) {
  $users = vu_rp_demo_random_users_all($role_name);

  return vu_rp_demo_random_array_item($users);
}

/**
 * Get all demo users.
 */
function vu_rp_demo_random_users_all($role_name = FALSE) {
  $uids = vu_rp_demo_record_get_all('user', 'user');

  $role = FALSE;
  if ($role_name) {
    $role = user_role_load_by_name($role_name);
  }

  $users = [];
  foreach ($uids as $uid) {
    $user = user_load($uid);

    if (!$user) {
      continue;
    }

    if ($role_name) {
      if ($role && user_has_role($role->rid, $user)) {
        $users[$user->uid] = $user;
      }
    }
    else {
      $users[$user->uid] = $user;
    }
  }

  return $users;
}

/**
 * Generate a placeholder image and store it as a managed file.
 *
 * @param array $options
 *   Array of options for generation:
 *   - filename: (string) Optional image file name. If not provided, random name
 *     will be used.
 *   - width: (int) Image width.
 *   - height: (int) Image height.
 *   - color: (string) Font color in HEX format (#ffffff).
 *   - background: (string) Background color in HEX format (#666666).
 *   - format: (string) One of the following: gif, jpg, png. Defaults to 'png'.
 *   - text: (string) Text to place on the image. Defaults to dimensions (WxH).
 *
 * @return bool|object
 *   Created file object or FALSE if there was an error creating or saving an
 *   image.
 */
function vu_rp_demo_random_image_placeholder(array $options = []) {
  $options += [
    'width' => 350,
    'height' => 200,
    'color' => '#ffffff',
    'background' => '#666666',
    'text' => '',
    'format' => 'png',
    'filename' => '',
  ];

  // Normalise options.
  $options['color'] = ltrim($options['color'], '#');
  $options['background'] = ltrim($options['background'], '#');
  $options['text'] = urlencode($options['text']);
  $options['format'] = '.' . ltrim($options['format'], '.');

  // Provide random file name.
  $filename = !empty($options['filename']) ? 'public://' . $options['filename'] : 'public://' . Random::name() . $options['format'];
  // Make sure that there is an extension.
  $filename = empty(pathinfo($filename, PATHINFO_EXTENSION)) ? $filename . $options['format'] : $filename;

  $options = array_combine(array_map(function ($value) {
    return '@' . $value;
  }, array_keys($options)), $options);

  $url = format_string('http://via.placeholder.com/@widthx@height/@background/@color.@format?text=@text', $options);

  $result = drupal_http_request($url);
  if (property_exists($result, 'error') && !empty($result->error)) {
    General::messageSet(format_string('Unable to create a placeholder file: @error', [
      '@error' => $result->error,
    ]));

    return FALSE;
  }

  $file = file_save_data($result->data, $filename);

  return $file;
}

/**
 * Generate Video placeholder file.
 *
 * @param string $url
 *   Optional video URL.
 *
 * @return bool|object
 *   Created video file object or FALSE if unable to create a file.
 */
function vu_rp_demo_random_video_placeholder($title = '', $url = '', $unique = FALSE) {
  $url = !empty($url) ? $url : 'https://www.youtube.com/watch?v=aBTAE9xCSGg#action=share';
  $url = !$unique ? $url : $url . rand(10000, 1000000);
  $file = file_uri_to_object('oembed://' . drupal_encode_path($url));
  $file->filename = !empty($title) ? $title : 'Video placeholder';
  file_save($file);

  return $file;
}

/**
 * Helper to get single random taxonomy term form specified vocabulary.
 */
function vu_rp_demo_random_term($vocabulary) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  if (!$vocabulary) {
    return FALSE;
  }

  $terms = taxonomy_get_tree($vocabulary->vid);

  return vu_rp_demo_random_array_item($terms);
}

/**
 * Create media token for file.
 *
 * Note, that this replicates Media's token generation that happens in JS.
 *
 * @param int $fid
 *   File id to generate toke for.
 * @param array $options
 *   Array of token options with sensible defaults.
 * @param array $attributes
 *   Array of custom attributes for generated HTML after a token is processed
 *   by Media's filter.
 *
 * @return string
 *   Generated token markup.
 */
function _vu_rp_demo_random_media_token($fid, array $options = [], array $attributes = []) {
  $attributes += [
    'classes' => 'media-element file-default',
  ];

  $defaults = [
    'fid' => $fid,
    'view_mode' => 'wysiwyg',
    'type' => 'media',
    'fields' => [
      'format' => 'default',
      'field_file_image_alt_text[und][0][value]' => '',
      'field_file_image_title_text[und][0][value]' => '',
      'alignment' => '',
    ],
    'attributes' => $attributes,
  ];

  $data = drupal_array_merge_deep($defaults, $options);

  return '[[' . drupal_json_encode($data) . ']]';
}
