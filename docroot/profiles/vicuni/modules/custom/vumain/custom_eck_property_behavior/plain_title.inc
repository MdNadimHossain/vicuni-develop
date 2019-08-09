<?php
/**
 * @file
 * The plain title behavior makes a property out as plain text.
 *
 * 1) When then entity is view, we set the page title to be the
 *    properties value.
 * 2) We set the property as the label of the entity.
 * 3) The property can be entered by the user with a text field.
 * 4) The property is displayed as an h1 tag.
 */

$plugin = array(
  'label' => "Plain title",
  'entity_view' => 'plain_title_property_entity_view',
  'entity_info' => 'plain_title_property_entity_info',
  'default_widget' => 'plain_title_property_widget',
  'default_formatter' => 'plain_title_property_formatter',
);

/**
 * How to input a title.
 */
function plain_title_property_widget($property, $vars) {
  $entity = $vars['entity'];
  $title = _plain_title_property_extract_title($entity, $property);
  return array(
    '#type' => 'textfield',
    '#title' => $vars['properties'][$property]['label'],
    '#maxlength' => 255,
    '#default_value' => $title,
    '#required' => TRUE,
  );
}

/**
 * Display the title as an h1.
 */
function plain_title_property_formatter($property, $vars) {
  $entity = $vars['entity'];
  $title = _plain_title_property_extract_title($entity, $property);
  return array('#markup' => "<div class='entity-title'>{$title}</div>");
}

/**
 * When we are viewing the entity, set the pages title.
 */
function plain_title_property_entity_view($property, $vars) {
  $entity = $vars['entity'];
  $title = _plain_title_property_extract_title($entity, $property);

  if (empty($title)) {
    $entity_id = entity_id($entity->entityType(), $entity);
    $title = "{$entity->entityType()} : {$entity_id}";
  }

  $uri = entity_uri($entity->entityType(), $entity);
  if ($uri['path'] == current_path()) {
    drupal_set_title($title);
  }
}

/**
 * Make whatever property is using the title behavior, the label.
 */
function plain_title_property_entity_info($property, $var) {
  $info = $var;
  unset($info['label callback']);
  $info['entity keys']['label'] = $property;

  return $info;
}

/**
 * Helper function that gets the title from an entity.
 *
 * @param object $entity
 *   an entity object.
 * @param string $property
 *   the name of the property that contains the title.
 *
 * @return string
 *   The title of the entity.
 */
function _plain_title_property_extract_title($entity, $property) {
  $title = "";
  if (isset($entity->{$property})) {
    $title = $entity->{$property};
  }

  return $title;
}
