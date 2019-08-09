<?php
/**
 * @file
 * This file contains functions related to featured content items.
 */

/**
 * Find and generate markup for featured content on this node.
 *
 * @param int $item_count
 *   How many featured content items are needed (hard max).
 * @param bool $target_only
 *   Only retrieve items that are specifically targeting the current node.
 *
 * @return string
 *   The rendered content.
 */
function vumain_featured_content_render($item_count = 5, $target_only = FALSE) {
  $content = '';
  $node = menu_get_object();

  if ($node && $node->nid) {

    // Check if this is a subsite that hides FC.
    if (!empty($node->language)) {
      $lang = $node->language;
      if (isset($node->field_page_subsite[$lang][0]['tid'])) {
        // Load settings from taxonomy.
        $term = taxonomy_term_load($node->field_page_subsite[$lang][0]['tid']);
        // Get the language.
        $lang = field_language('taxonomy_term', $term);
        // Hide featured content region.
        if (
          isset($term->field_subsite_hide_feat_content[$lang['field_subsite_hide_feat_content']][0]['value']) &&
          $term->field_subsite_hide_feat_content[$lang['field_subsite_hide_feat_content']][0]['value'] == 1
        ) {
          return;
        }
      }
    }

    // If landing page, level should always 1, ignore the menu assigment.
    if ($node->type == 'topic_pages') {
      $level = 1;
    }
    else {
      $level = vumain_current_menu_level();
    }

    switch ($level) {
      case 1:
        $items = vumain_featured_content_get_featured_entities($node, $item_count, 464, $target_only);
        // Provide printable variables for template.
        $data = array();
        foreach ($items as $item) {
          switch ($item->type) {
            case 'news':
            case 'success_story':
            case 'events':
              $teaser = field_view_field('node', $item, 'body',
                array(
                  'label' => 'hidden',
                  'type' => 'text_summary_or_trimmed',
                  'settings' => array('trim_length' => 150),
                )
              );
              // Get the language.
              $lang = $item->language;
              $data[] = array(
                'image' => theme_image_style(
                  array(
                    'style_name' => 'large_featured_content',
                    'path' => $item->field_image[$lang][0]['uri'],
                    'alt' => '',
                    'width' => NULL,
                    'height' => NULL,
                  )
                ),
                'title' => $item->title,
                'teaser' => text_summary(strip_tags(render($teaser)), NULL, 120),
                'url' => url('node/' . $item->nid),
              );
              break;
          }
        }
        return theme('large_featured_content', array('items' => $data));

      case 2:
      case 3:
      case 4:
        $items = vumain_featured_content_get_featured_entities($node, 3, 100, $target_only);
        return theme('small_featured_content', ['items' => $items]);
    }
  }

  return $content;
}

/**
 * Retrieves featured content for the target node.
 *
 * @param object $node
 *   Drupal node object.
 * @param int $item_count
 *   Items count to return.
 * @param int $min_width
 *   Don't return items with smaller images than this.
 * @param bool $target_only
 *   When we only want to get items that specifically target the passed node.
 *
 * @return array
 *   Array of fully loaded node objects.
 */
function vumain_featured_content_get_featured_entities($node, $item_count = 5, $min_width = 0, $target_only = FALSE) {
  // Note: We cannot use EntityFieldQuery for this because we need to
  // be able to query across multiple entities/types.
  $items = array();

  // Set the current date.
  $current_date = time();

  // Find items that target this node.
  _vumain_featured_content_get_featured_entities($items, $node, $item_count, $current_date, $min_width, 'target_node');

  // We only want to get items that specifically target the passed node.
  if ($target_only) {
    return $items;
  }

  // If the item count has not yet been reached.
  if (count($items) < $item_count) {
    // Find items that target the same area on the site.
    _vumain_featured_content_get_featured_entities($items, $node, $item_count, $current_date, $min_width, 'target_area');

    // If the item count has not yet been reached.
    if (count($items) < $item_count) {
      // Find all featured content items.
      _vumain_featured_content_get_featured_entities($items, $node, $item_count, $current_date, $min_width);
    }
  }

  return $items;
}

/**
 * Pseudo implements hook_entity_presave().
 */
function _vumain_featured_content_entity_presave($entity, $type) {
  if (property_exists($entity, 'type') && $entity->type == 'featured_content') {
    // Get the language.
    $lang = module_exists('entity_translation') ? $entity->language : LANGUAGE_NONE;
    $entity->field_content_area[$lang] = array();
    if (!empty($entity->field_destination_page[$lang])) {
      foreach ($entity->field_destination_page[$lang] as $index => $target) {
        $path = "node/{$target['target_id']}";
        $p1 = db_select('menu_links', 'ml')
          ->condition('ml.link_path', $path)
          ->fields('ml', array('p1'))
          ->execute()
          ->fetchField();
        // OK, now p1 is the level 1 mlid but we need the node id.
        if ($p1) {
          $l1_path = db_select('menu_links', 'ml')
            ->condition('ml.mlid', $p1)
            ->fields('ml', array('link_path'))
            ->execute()
            ->fetchField();
          if (preg_match(',^node/([0-9]+)$,', $l1_path, $matches)) {
            $entity->field_content_area[$lang][$index] = array('target_id' => $matches[1]);
          }
        }
      }
    }
  }
}

/**
 * Pseudo implements hook_theme().
 */
function vumain_featured_content_theme() {
  $template_path = drupal_get_path('module', 'vumain') . '/theme';
  return array(
    'large_featured_content' => array(
      'variables' => array('items' => NULL),
      'template' => 'large-featured-content',
    ),
    'small_featured_content' => array(
      'variables' => array('items' => NULL),
      'template' => 'small-featured-content',
    ),
  );
}

/**
 * Fill the supplied array with featured content.
 *
 * @param array $items
 *   The array of node items.
 * @param object $node
 *   The node the featured content will be displayed on.
 * @param int $item_count
 *   The maximum number of featured content to fill $items with.
 * @param string $current_date
 *   String of the current date to use for limiting the query.
 * @param string $min_width
 *   Don't get items smaller then this.
 * @param string $type
 *   Should the featured content be only for the node, the area, or any FC.
 */
function _vumain_featured_content_get_featured_entities(array &$items, $node, $item_count, $current_date, $min_width, $type = 'any') {
  // Set the OR conditions.
  if(empty($node->nid)) return;
  $or_duration = db_or();
  $or_duration->isNull('fdffd.field_feature_duration_value')
    ->condition('fdffd.field_feature_duration_value', $current_date, '>=');

  $or_event_date = db_or();
  $or_event_date->isNull('fdfd.field_date_value')
    ->condition('fdfd.field_date_value', $current_date, '>=');

  // Only select news/media release that are less than one year old.
  $or_news_date = db_or();
  $or_news_date->isNull('fdfad.field_article_date_value')
    ->condition('fdfad.field_article_date_value', $current_date - 31536000, '>=');

  switch ($type) {
    case 'target_area':
      $query = db_select('field_data_field_content_area', 'target')
        ->distinct();
      $query->join('field_data_field_feature_on', 'source', 'target.entity_id = source.field_feature_on_target_id AND source.deleted = 0');
      break;

    case 'target_node':
    default:
      $query = db_select('field_data_field_destination_page', 'target')
        ->distinct();
      $query->join('field_data_field_feature_on', 'source', 'target.entity_id = source.field_feature_on_target_id AND source.deleted = 0');
      break;
  }

  // Join the relevant tables.
  $query->join('node', 'n', 'source.entity_id = n.nid AND n.status');
  $query->join('field_data_field_image', 'fdfi', 'source.entity_id = fdfi.entity_id AND fdfi.deleted = 0');
  $query->join('file_metadata', 'fm', 'fdfi.field_image_fid = fm.fid AND fm.name = :width', array('width' => 'width'));
  $query->leftJoin('field_data_field_date', 'fdfd', 'source.entity_id = fdfd.entity_id AND fdfd.deleted = 0');
  $query->leftJoin('field_data_field_article_date', 'fdfad', 'source.entity_id = fdfad.entity_id AND fdfad.deleted = 0');
  $query->leftJoin('field_data_field_feature_duration', 'fdffd', 'target.entity_id = fdffd.entity_id AND fdffd.deleted = 0');
  $query->leftJoin('field_data_field_new_tab_homepage_carousel', 'fdfnthc', 'target.entity_id = fdfnthc.entity_id AND fdfnthc.deleted = 0');

  // Get the relevant fields.
  $query->fields('n', array('nid'));
  $query->fields('fdfnthc', array('field_new_tab_homepage_carousel_value'));
  $query->addExpression('ABS(UNIX_TIMESTAMP()-COALESCE(fdfad.field_article_date_value, fdfd.field_date_value, n.created))', 'date_order');
  if ($type == 'target_node') {
    $query->condition('target.field_destination_page_target_id', $node->nid);
  }
  elseif ($type == 'target_area') {
    // Find items that target the same area on the site.
    $menu_active_trail = menu_get_active_trail();
    $area = end($menu_active_trail);
    $area = isset($area['p1']) ? $area['p1'] : '';
    // Get the menu link for this area.
    $link = menu_link_load($area);
    // Explode the path. We need to do this to get the nid.
    $explode = explode('node/', $link['link_path'], 2);
    // Get the destination nid.
    $destination_nid = !empty($explode[1]) ? $explode[1] : $node->nid;
    // Update the condition.
    $query->condition('target.field_content_area_target_id', $destination_nid);
  }
  $query->orderBy('date_order', 'ASC');

  // Set the relevant conditions.
  $query->condition('target.deleted', 0)
    ->condition('n.nid', $node->nid, '<>')
    ->condition('fm.value', $min_width, '>=')
    ->condition($or_duration)
    ->condition($or_event_date)
    ->condition($or_news_date)
    ->range(0, $item_count);
  // Get the result.
  $result = $query->execute();

  // Loop through the results.
  while ($row = $result->fetchAssoc()) {
    // Get the nid.
    $nid = $row['nid'];
    // Load each node only once.
    if (isset($items[$nid])) {
      continue;
    }
    // Update the items with the loaded node.
    $items[$nid] = node_load($nid);
    if ($items[$nid] !== FALSE) {
      $new_tab = empty($row['field_new_tab_homepage_carousel_value']) ? 0 : 1;
      $items[$nid]->featured_content_homepage_new_tab = $new_tab;
    }
    //
    // If we have reached the total amount.
    if (count($items) >= $item_count) {
      break;
    }
  }
}
