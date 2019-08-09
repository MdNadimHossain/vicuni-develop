<?php

/**
 * @file
 * Generic helpers.
 *
 * Do not put any business logic in this file.
 */

/**
 * Wrapper on field_get_items().
 */
function vu_rp_extract_single_field_value($entity_type, $entity, $field_name, $value_key = 'value') {
  $items = field_get_items($entity_type, $entity, $field_name);
  if (!is_array($items)) {
    return FALSE;
  }
  $item = reset($items);

  return isset($item[$value_key]) ? $item[$value_key] : FALSE;
}

/**
 * Helper function to paragraph item values.
 */
function vu_rp_get_paragraph_item_values($node, $paragraph_field, $paragraph_bundle, $paragraph_fields, $default_target = 'value') {
  $wrapper = entity_metadata_wrapper('node', $node);
  $paragraph_items = $wrapper->$paragraph_field->value();
  $data = [];
  foreach ($paragraph_items as $paragraph_item) {
    $tmp = [];
    if ($paragraph_item->bundle() == $paragraph_bundle) {
      foreach ($paragraph_fields as $field => $params) {
        $field_key = isset($params['target']) ? $params['target'] : $default_target;

        $value = vu_rp_extract_single_field_value('paragraphs_item', $paragraph_item, $field, $field_key);

        switch ($field_key) {
          case 'tid':
            $term = taxonomy_term_load($value);
            $value = $term->name;
            break;

          case 'target_id':
            $term = taxonomy_term_load($value);
            $value = $term->name;
            break;
        }

        $tmp[$field] = $value;
      }
    }

    $data[] = $tmp;
  }

  return count($data) ? $data : NULL;
}

/**
 * Helper to get the variation value.
 *
 * @param object $node
 *   Node to get the value from.
 * @param string $original_field_name
 *   The name of the original field.
 * @param string $variation_field_name
 *   Optional name of the field with variation value. If not provided, only
 *   original field value will be returned.
 * @param string $variation_flag_field_name
 *   Optional name of the flag field that identifies if variation was enabled.
 *   If not provided, the flag is disregarded and variation field is used as if
 *   this flag is always set to TRUE.
 *
 * @return bool|mixed
 *   The field value.
 */
function vu_rp_get_variation_value($node, $original_field_name, $variation_field_name = FALSE, $variation_flag_field_name = TRUE) {
  $value = vu_rp_extract_single_field_value('node', $node, $original_field_name);

  // Trying to get original value.
  if (empty($value)) {
    return FALSE;
  }

  // Only use variation field if it is provided and if either variation flag
  // is defaulted to TRUE or it's field value is TRUE.
  // This allows to safely retrieve original value without using variation
  // values.
  if ($variation_field_name && ($variation_flag_field_name === TRUE || !empty(vu_rp_extract_single_field_value('node', $node, $variation_flag_field_name)))) {
    $variation_value = vu_rp_extract_single_field_value('node', $node, $variation_field_name);
    $value = !empty($variation_value) ? $variation_value : $value;
  }

  return $value;
}

/**
 * Helper to get the number of nodes of the specified type.
 */
function vu_rp_count_nodes_of_type($type) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $type)
    ->count();

  return $query->execute();
}

/**
 * Get the titles for terms.
 *
 * @param array $term_ids
 *   Array of term ids.
 *
 * @return array
 *   Array of terms titles.
 */
function vu_rp_flatten_terms($term_ids = [], $field = 'name') {
  $terms = [];
  if (empty($term_ids)) {
    return $terms;
  }

  foreach ($term_ids as $tid) {
    $term = taxonomy_term_load($tid);
    if ($term) {
      $terms[$tid] = $term->{$field};
    }
  }

  return $terms;
}

/**
 * Return the researcher_profile node object for the current path.
 *
 * @return object|bool
 *   Research profile node object or FALSE if not on research profile node.
 */
function vu_rp_get_researcher_profile_node() {
  $node = menu_get_object();

  return $node->type == 'researcher_profile' ? $node : FALSE;
}

/**
 * Helper to lookup researcher profile by user id.
 *
 * @note: This is a shorthand method. It does not return linked or not linked
 * nodes.
 */
function vu_rp_lookup_researcher_profile_by_uid($uid) {
  $staff_id = vu_core_get_staff_id_by_uid($uid);

  return vu_rp_get_researcher_profile_by_staff_id($staff_id);
}

/**
 * Get a researchers profile node by staff id.
 */
function vu_rp_get_researcher_profile_by_staff_id($staff_id) {
  $query = new \EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'researcher_profile');
  $query->fieldCondition('field_rpa_staff_id', 'value', $staff_id, '=');
  $result = $query->execute();

  $node = isset($result['node']) ? reset($result['node']) : FALSE;

  return $node ? node_load($node->nid) : FALSE;
}
