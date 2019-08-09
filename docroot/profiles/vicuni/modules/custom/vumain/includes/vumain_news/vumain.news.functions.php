<?php
/**
 * @file
 * Contains functions related to News content type.
 */

/**
 * To return theme pre-processes.
 */
function vumain_news_theme() {
  $template_path = drupal_get_path('module', 'vumain');
  return array(
    'social_media_links' => array(
      'path' => $template_path,
      'template' => 'theme/social-media-links',
      'arguments' => array(
        'title' => NULL,
        'node_type' => '',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vumain_news_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'full') {
    $related_in_links = _vumain_news_process_related_links($variables['node']->field_related_in_link, $variables['node']);
    $related_ext_links = _vumain_news_process_related_links($variables['node']->field_related_ex_link, $variables['node'], TRUE);
    $variables['related_links'] = array_merge($related_in_links, $related_ext_links);
    $variables['social_media_links'] = theme('social_media_links', array(
      'title' => $variables['title'],
      'node_type' => 'story',
    ));
  }
}

/**
 * Processes related links in news.
 *
 * @param $related_links
 *
 * @todo: Provide description and update type above
 *
 * @param $node
 *
 * @todo: Provide description and update type above
 *
 * @param bool $is_external
 *
 * @todo: Provide description and update type above
 *
 * @return array
 *
 * @todo: Provide description
 */
function _vumain_news_process_related_links($related_links, $node, $is_external = FALSE) {
  $links = array();

  if (empty($related_links)) {
    return $links;
  }

  $nodes = array();
  foreach ($related_links[$node->language] as $key => $value) {
    $nodes[] = $value;
  }

  foreach ($nodes as $key => $value) {
    $node = $value['entity'];
    // Get the language.
    $lang = $node->language;
    $links[$node->nid]['title'] = $node->title;
    $links[$node->nid]['excerpt'] = !$is_external ? truncate_utf8($node->body[$lang][0]['safe_value'], 153, TRUE, TRUE) : '';
    $links[$node->nid]['url'] = !$is_external ? url('node/' . $node->nid) : $node->field_link[$lang][0]['url'];
  }
  return $links;
}
