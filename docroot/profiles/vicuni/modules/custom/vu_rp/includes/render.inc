<?php

/**
 * @file
 * Render functions for VU Researcher Profile.
 */

/**
 * Implements hook_preprocess_page().
 */
function vu_rp_preprocess_page(&$variables) {
  $node = isset($variables['node']) && is_object($variables['node']) ? $variables['node'] : FALSE;
  if (!$node || $node->type != 'researcher_profile') {
    return;
  }

  $title = vu_rp_extract_single_field_value('node', $node, 'field_rp_title');
  $first_name = token_replace('[researcher_profile:variation_first_name]', ['node' => $node]);
  $last_name = token_replace('[researcher_profile:variation_last_name]', ['node' => $node]);
  $post_nominal = vu_rp_extract_single_field_value('node', $node, 'field_rp_post_nominal');
  $email = vu_rp_extract_single_field_value('node', $node, 'field_rpa_email', 'email');
  $is_photo = vu_rp_extract_single_field_value('node', $node, 'field_rp_use_photo');
  $institute = _vu_rp_preprocess_page_render_institute($node);
  $job_title = vu_rp_get_variation_value($node, 'field_rpa_job_title', 'field_rp_job_title', 'field_rp_job_title_variation');

  $photo = FALSE;
  if ($is_photo) {
    $photo_url = vu_rp_extract_single_field_value('node', $node, 'field_rp_photo', 'uri');
    if ($photo_url) {
      $photo = theme('image_style', [
        'style_name' => 'rp_title_photo',
        'path' => $photo_url,
        'attributes' => [
          'class' => 'js-researcher-photo',
        ],
      ]);
    }
  }

  if ($photo) {
    $variables['researcher_photo'] = $photo;
    $variables['title_box_feature_classes'][] = 'title-box__feature__with_photo';
  }

  $variables['title'] = implode(' ', array_filter([
    $title,
    $first_name,
    $last_name,
    $post_nominal,
  ]));
  $variables['title_sub1'] = $job_title;

  if ($institute) {
    $variables['title_sub2'] = t('<span>VU researcher at: !institute</span>', [
      '!institute' => $institute,
    ]);
  }

  if ($email) {
    $email = strtolower($email);
    $variables['title_sub3'] = l($email, 'mailto:' . $email);
  }
}

/**
 * Helper to render Research Institutes value.
 */
function _vu_rp_preprocess_page_render_institute($node, $as_link = FALSE) {
  $term = vu_rp_node_get_institute($node);
  if (!$term) {
    return FALSE;
  }
  $link = vu_core_extract_single_field_value($term, 'taxonomy_term', 'field_research_institutes_link', 'url');

  if ($as_link) {
    return [
      'link' => url($link),
      'link_label' => $term->name,
    ];
  }

  return $link ? l($term->name, $link) : $term->name;
}

/**
 * Render DOI link.
 *
 * @todo: Replace with a theme.
 */
function vu_rp_render_doi_link($doi) {
  if (empty($doi)) {
    return '';
  }

  return '<p>doi: ' . l($doi, 'https://doi.org/' . $doi) . '</p>';
}
