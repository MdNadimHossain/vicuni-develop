<?php

/**
 * @file
 * Strip the CRICOS code from the field and display.
 */

/**
 * Class VuCoursesCricosLocationField.
 */
class VuCoursesCricosLocationField extends VuCoursesFieldsBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'CRICOS Location';


  /**
   * {@inheritdoc}
   */
  public $allowedBundles = ['courses'];

  /**
   * {@inheritdoc}
   */
  public function view() {
    $language = entity_language($this->entityType, $this->entity);
    $values = $this->entity->field_cricos_code[$language];
    $locations = [];

    foreach ($values as $value) {
      list(, $location) = _vu_core_split_cricos_code($value['safe_value']);

      $locations[] = $location;
    }

    $locations = array_unique($locations);
    $cricos_codes = [];
    foreach ($locations as $location) {
      $nodes = node_load_multiple(NULL, ["title" => $location, 'type' => 'campus']);
      $node = current($nodes);
      $alias = $node->path['alias'];
      // Rewrite each CRICOS as a link.
      if (isset($alias)) {
        $markup = '<a class="cricos-location" href="/' . $alias . '">' . $location . '</a>';
      }
      else {
        $markup = $location;
      }
      $cricos_codes[]['#markup'] = $markup;
    }
    $output = drupal_render($cricos_codes);

    if (strpos(strtolower($output), 'vu sydney') !== FALSE) {
      $output .= theme('location-vu-sydney-note', ['url' => url('vu-sydney/courses-at-vu-sydney')]);
    }

    return $output;
  }

}
