<?php

/**
 * @file
 * Feeds Tamper process definitions.
 *
 * This tamper process will determine the value for the Domestic field.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_domestic',
  'callback' => 'vu_imports_domestic_callback',
  'name'     => 'Domestic',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * User options.
 */
function vu_imports_domestic($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_domestic_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Feeds tamper plugin callback.
 */
function vu_imports_domestic_callback($source, $item_key, $element_key, &$field, $settings) {
  // Set TRUE when the import file isn't the International import, identified by
  // the presence of the `international_offered` source item.
  $field = is_null($source->current_item['international_offered']);

  // If international feed, ensure domestic version stays available.
  if (!$field) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'courses')
      ->fieldCondition('field_unit_code', 'value', $source->current_item['coursecode'])
      ->fieldCondition('field_domestic', 'value', 1)
      ->execute();
    if (isset($result['node']) && !empty($result['node'])) {
      $field = TRUE;
      return;
    }
  }

  // If course is currently not offerred for domestic, don't change it.
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'courses')
    ->fieldCondition('field_unit_code', 'value', $source->current_item['coursecode'])
    ->fieldCondition('field_domestic', 'value', 0)
    ->execute();
  if (isset($result['node']) && !empty($result['node'])) {
    $field = FALSE;
    return;
  }
}
