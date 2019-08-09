<?php

/**
 * @file
 * Panels module integration.
 */

/**
 * Implements hook_panels_pane_content_alter().
 */
function vu_core_panels_pane_content_alter($content, $pane, $args, $contexts) {
  // Only alter on new theme.
  global $theme;
  if (!empty($content->content['bean'])) {
    $entity = reset($content->content['bean']);
    $bean_class = !empty($pane->css['css_class']) ? $pane->css['css_class'] . ' ' : '';
    $bean_class .= 'pane-bean pane-bean-bundle-' . str_replace('_', '-', $entity['#bundle']);
    $pane->css['css_class'] = $bean_class;
  }
  if ($theme == 'victory') {
    $node = vu_core_subsite_node_get();
    // Load settings from taxonomy.
    $subsite_metadata = vu_core_subsite_meta_get($node);
    if (vu_core_is_subsite() && $subsite_metadata) {
      switch ($pane->pid) {
        // Overrides the footer contact us block for subsites.
        case 'new-6f53b424-318a-402e-a1cc-614400a019d8':
          if ($subsite_metadata->field_override_contact_us) {
            unset($content->title);
            $content->content = $subsite_metadata->field_override_contact_us;
          }
          break;

        // Overrides the footer visit us block for subsites.
        case 'new-095e67c9-1d7c-4cfc-874b-745c45a36566':
          if ($subsite_metadata->field_override_contact_us) {
            unset($content->title);
            $content->content = '';
          }
          break;

        // Overrides the footer contact us block for vu-sydney subsites.
        case 'new-f9a19a98-c08d-4159-be53-56bf4b375a8c':
          if ($subsite_metadata->field_override_contact_us) {
            unset($content->title);
            $content->content = $subsite_metadata->field_override_contact_us;
          }
          break;

        // Overrides the footer visit us block for vu-sydney subsites.
        case 'new-728e9876-d24e-46fa-acde-9ee325185b2d':
          if ($subsite_metadata->field_override_campus_app) {
            unset($content->title);
            $content->content = $subsite_metadata->field_override_campus_app;
          }
          break;

        // Overrides the footer campus app block titile for subsites.
        case 'new-026426a8-ec53-4872-b1df-6e6d0662f41a':
          if ($subsite_metadata->field_override_campus_app) {
            unset($content->title);
          }
          break;

        // Overrides the footer social media links block titile for subsites.
        case 'new-2f35855e-28c1-4630-90e5-6a01a42d6e9d':
          if ($subsite_metadata->field_block_title) {
            $content->title = $subsite_metadata->field_block_title;
          }
          break;

      }
    }
  }
}
