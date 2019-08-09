<?php

namespace Drupal\vu_rp_api\Endpoint;

use Drupal\vu_rp_api\Exception;

/**
 * Class FieldMapper.
 *
 * Map entity data to the schema expected by provider.
 *
 * @package Drupal\vu_rp_api\Endpoint
 */
class FieldMapper {

  const TYPE_INTEGER = 1;

  const TYPE_DECIMAL = 1 << 1;

  const TYPE_STRING = 1 << 2;

  const TYPE_BOOLEAN = 1 << 3;

  const TYPE_ARRAY = 1 << 4;

  const TYPE_NULL = 1 << 5;

  const PRIMARY_KEY = 1 << 10;

  /**
   * Field mapping schema definition.
   *
   * @var array
   */
  protected $schema;

  /**
   * FieldMapper constructor.
   *
   * @param array $schema
   *   Field mapping schema definition.
   */
  public function __construct($schema) {
    $this->setSchema($schema);
  }

  /**
   * Get field mapping schema definition.
   *
   * @param bool $strip_root
   *   Flag to strip root schema fields.
   *
   * @return array
   *   Schema map.
   */
  public function getSchema($strip_root = FALSE) {
    return $strip_root ? $this->findRoot($this->schema) : $this->schema;
  }

  /**
   * Find root of the schema.
   */
  public function findRoot($schema) {
    foreach ($schema as $v) {
      if (!empty($v['children'] && !empty($v['is_root']))) {
        return $this->findRoot($v['children']);
      }
    }

    return $schema;
  }

  /**
   * Find root path.
   */
  public function findRootPath($schema = NULL) {
    $path = [];

    $schema = $schema ? $schema : $this->schema;
    foreach ($schema as $k => $v) {
      if (!empty($v['children'] && !empty($v['is_root']))) {
        $path[] = $k;

        $return = $this->findRootPath($v['children']);
        if ($return) {
          $path = array_merge($path, $return);
        }
      }
    }

    return $path;
  }

  /**
   * Set field mapping schema definition.
   */
  public function setSchema($schema) {
    $schema = $this->normaliseSchema($schema);
    $this->schema = $schema;

    return $this;
  }

  /**
   * Normalise and validate schema.
   */
  protected function normaliseSchema($schema) {
    $root_path_items = 0;
    foreach ($schema as $k => $v) {
      $schema[$k] = $this->defaultFieldStructure($schema[$k]);

      if (is_array($schema[$k]) && !empty($schema[$k]['children'])) {
        $schema[$k]['children'] = $this->normaliseSchema($schema[$k]['children']);
      }

      $root_path_items += $schema[$k]['is_root'];
    }

    if ($root_path_items > 1) {
      throw new Exception('Invalid schema: there can be only 1 field with root path within the same level');
    }

    return $schema;
  }

  /**
   * Render schema.
   *
   * @return string
   *   Rendered schema.
   */
  public function renderSchema() {
    return $this->renderSchemaList($this->getSchema());
  }

  /**
   * Helper to recursively render a list of field types in schema.
   */
  protected function renderSchemaList($list, $depth = 0) {
    $prefix = str_repeat('    ', $depth);
    $lines = [];
    foreach ($list as $name => $value) {
      $lines[] = sprintf('%s"%s":', $prefix, $name);
      $subprefix = $prefix . '  ';
      $lines[] = sprintf('%s"Type": "%s"', $subprefix, $this->renderType($value['type']));
      if (!empty($value['callback'])) {
        $lines[] = sprintf('%s"Callback": "%s"', $subprefix, $this->renderCallback($value['callback']));
      }
      if (!empty($value['value_key'])) {
        $lines[] = sprintf('%s"Value key": "%s"', $subprefix, $value['value_key']);
      }
      $lines[] = sprintf('%s"Is primary": "%s"', $subprefix, $value['is_primary'] ? 'true' : 'false');
      $lines[] = sprintf('%s"Is root": "%s"', $subprefix, $value['is_root'] ? 'true' : 'false');
      if (!empty($value['children'])) {
        $lines[] = sprintf('%s"Children":', $subprefix);
        $lines[] = $this->renderSchemaList($value['children'], $depth + 1);
      }
    }

    return implode(PHP_EOL, $lines);
  }

  /**
   * Default field structure for each field definition.
   */
  public function defaultFieldStructure($info = []) {
    $defaults = [
      // Node type.
      'type' => FieldMapper::TYPE_STRING,
      // Destination field name.
      'field' => NULL,
      // Value key within the destination field.
      'value_key' => 'value',
      // Callback to retrieve destination value.
      'callback' => [$this, 'defaultFieldCallback'],
      // Use the value of this field as a primary key.
      'is_primary' => FALSE,
      // Use as a part of the root path to the required fields.
      'is_root' => FALSE,
      // Array of children, if any.
      'children' => [],
    ];

    $info = is_array($info) ? $info : ['field' => $info];

    // Filter key by allowed keys.
    $info = array_intersect_key($info, $defaults);

    // Automatically cast arrays.
    if (!empty($info['children'])) {
      $info['type'] = self::TYPE_ARRAY;
    }

    // Special treatment for arrays: we do not want to provide default callback.
    if (isset($info['type']) && $info['type'] == self::TYPE_ARRAY) {
      unset($defaults['callback']);
      unset($defaults['value_key']);
    }

    $info += $defaults;

    return $info;
  }

  /**
   * Default field callback.
   *
   * @param mixed $data
   *   Full data.
   * @param string $source_field
   *   The name of the source field.
   * @param mixed $source_value
   *   The value of the source field.
   * @param object $node
   *   Drupal node to set values on.
   * @param string $dst_field
   *   Destination field name in Drupal.
   * @param string $dst_value_key
   *   Destination field value key in Drupal.
   */
  public function defaultFieldCallback($data, $source_field, $source_value, $node, $dst_field, $dst_value_key) {
    $node->{$dst_field}[LANGUAGE_NONE][0][$dst_value_key] = $source_value;
    if ($dst_value_key == 'value') {
      $node->{$dst_field}[LANGUAGE_NONE][0]['safe_value'] = $source_value;
    }
  }

  /**
   * Render field type as a sting.
   */
  protected function renderType($type) {
    $output = '';

    $type = is_array($type) ? self::TYPE_ARRAY : $type;

    $has_null = FALSE;
    if ($type & self::TYPE_NULL) {
      $type -= self::TYPE_NULL;
      $has_null = TRUE;
    }

    switch ($type) {
      case $type & self::TYPE_INTEGER:
        $output = 'integer';
        break;

      case $type & self::TYPE_DECIMAL:
        $output = 'decimal';
        break;

      case $type & self::TYPE_STRING:
        $output = 'string';
        break;

      case $type & self::TYPE_BOOLEAN:
        $output = 'boolean';
        break;

      case $type & self::TYPE_ARRAY:
        $output = 'array';
        break;
    }

    if ($has_null) {
      $output .= '|null';
    }

    return $output;
  }

  /**
   * Helper to render callback as a string.
   */
  protected function renderCallback($callback) {
    if (is_string($callback)) {
      return $callback;
    }

    if (is_array($callback) && count($callback) == 2) {
      return (is_string($callback[0]) ? $callback[0] : get_class($callback[0])) . '::' . $callback[1];
    }

    throw new Exception('Invalid callback format');
  }

  /**
   * Validate provided entity's schema.
   */
  public function validateResponseSchema($data) {
    // @todo: Implement this.
    return TRUE;
  }

  /**
   * Helper to get an array of primary keys.
   *
   * Note that this only traverses root level of the schema. I.e., compound keys
   * can be set only as root level items.
   *
   * @return array
   *   Array of primary keys.
   */
  public function getPrimaryKeyFields() {
    return array_filter($this->getSchema(TRUE), function ($v) {
      return !empty($v['is_primary']);
    });
  }

}
