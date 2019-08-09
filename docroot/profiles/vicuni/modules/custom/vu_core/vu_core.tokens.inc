<?php

/**
 * @file
 * Token integration for VU Core feature.
 */

/**
 * Implements hook_token_info().
 */
function vu_core_token_info() {
  $info = [];
  // First specify token type(s).
  $info['types']['revision'] = [
    'name' => t('Revisions'),
    'description' => t('Tokens related to revisions of individual content items, or "node revisions".'),
    'needs-data' => 'node',
  ];

  // Legacy token type.
  $info['types']['legacy'] = [
    'name' => t('Legacy tokens'),
    'description' => t('Legacy tokens from D6.'),
  ];

  // Library hours token type(s).
  $info['types']['library-hours'] = [
    'name' => t('Library Hours Today'),
    'description' => t('Tokens to show the library opening hours for today'),
  ];

  // Then specify the tokens.
  $info['tokens']['revision']['revision-author'] = [
    'name' => t('Revision author'),
    'description' => t('The author (or editor) of the revision'),
    'type' => 'user',
  ];
  $info['tokens']['revision']['revision-body'] = [
    'name' => t('Revision body'),
    'description' => t('The main body text of the revision'),
  ];
  $info['tokens']['revision']['revision-created'] = [
    'name' => t('Revision timestamp'),
    'description' => t('The date and time the revision was created.'),
    'type' => 'date',
  ];
  $info['tokens']['revision']['revision-title'] = [
    'name' => t('Revision title'),
    'description' => t('The title of the revision'),
  ];
  $info['tokens']['revision']['revision-vid'] = [
    'name' => t('Revision ID'),
    'description' => t('The unique ID of the revision'),
  ];

  // Legacy tokens.
  $info['tokens']['legacy']['connect-with-us'] = [
    'name' => t('Connect with us'),
    'description' => t('Renders connect with us block.'),
  ];

  return $info;
}

/**
 * Implements hook_tokens().
 */
function vu_core_tokens($type, $tokens, array $data = [], array $options = []) {
  $replacements = [];
  if ($type == 'library-hours') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'flinders':
          $id = 3208;
          break;

        case 'king':
          $id = 3209;
          break;

        case 'queen':
          $id = 3210;
          break;

        case 'footscrayNicholson':
          $id = 3211;
          break;

        case 'footscrayPark':
          $id = 3190;
          break;

        case 'stAlbans':
          $id = 3212;
          break;

        case 'sunshine':
          $id = 3213;
          break;

        case 'werribee':
          $id = 3214;
          break;

      }

      $replacements[$original] = "<div id='api_hours_today_iid1131_lid$id'></div>";
      drupal_add_js("https://api3-au.libcal.com/api_hours_today.php?iid=1131&lid=$id&format=js&context=object",
        [
          'type' => 'external',
          'scope' => 'footer',
        ]
      );
    }
  }

  if ($type != 'revision') {
    return $replacements;
  }

  if (!empty($data['revision'])) {
    $revision = $data['revision'];
  }
  elseif (!empty($data['entity']) && $data['entity_type'] == 'node') {
    // When Token module is enabled.
    $revision = $data['entity'];
  }
  elseif (!empty($data['node'])) {
    $revision = $data['node'];
  }
  else {
    return $replacements;
  }

  $sanitize = !empty($options['sanitize']);

  foreach ($tokens as $name => $original) {
    switch ($name) {
      case 'revision-title':
        $title = $revision->title;
        $replacements[$original] = $sanitize ? check_plain($title) : $title;
        break;

      case 'revision-body':
        $text = reset($revision->body);
        $text = $text[0]['value'];
        $replacements[$original] = $sanitize ? check_plain($text) : $text;
        break;

      case 'revision-vid':
        $replacements[$original] = $revision->vid;
        break;

      // Default values for the chained tokens handled below.
      case 'revision-author':
        $author = user_load($revision->revision_uid);
        $name = format_username($author);
        $replacements[$original] = $sanitize ? check_plain($name) : $name;
        break;

      case 'revision-created':
        $langcode = empty($options['language']->language) ? LANGUAGE_NONE : $options['language']->language;
        $replacements[$original] = format_date($revision->revision_timestamp, 'medium', '', NULL, $langcode);
        break;

      // Legacy tokens.
      case 'connect-with-us':
        $replacements[$original] = theme('vumain_connect_with_us_icons');
        break;
    }
  }

  // Chained tokens for revision author and revision timestamp.
  // These fan out into sub-token fields, e.g revision-author:mail etc.
  if ($author_tokens = token_find_with_prefix($tokens, 'revision-author')) {
    $author = user_load($revision->revision_uid);
    $replacements += token_generate('user', $author_tokens, ['user' => $author], $options);
  }

  if ($created_tokens = token_find_with_prefix($tokens, 'revision-created')) {
    $replacements += token_generate('date', $created_tokens, ['date' => $revision->revision_timestamp], $options);
  }

  return $replacements;
}

/**
 * Implements hook_tokens_alter().
 */
function vu_core_tokens_alter(array &$replacements, array $context) {
  // Remove 'vu-home' from menu path.
  if (isset($replacements['[node:menu-link:parents:join-path]'])) {
    $parts = explode('/', $replacements['[node:menu-link:parents:join-path]']);
    if ('vu-home' == $parts[0]) {
      array_shift($parts);
    }
    $replacements['[node:menu-link:parents:join-path]'] = implode('/', $parts);
  }
}
