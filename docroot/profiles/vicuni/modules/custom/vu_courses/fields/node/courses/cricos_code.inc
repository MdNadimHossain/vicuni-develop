<?php

/**
 * @file
 * Strip the CRICOS code from the field and display.
 */

/**
 * Class VuCoursesCricosCodeField.
 */
class VuCoursesCricosCodeField extends VuCoursesFieldsBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'CRICOS Code';

  /**
   * {@inheritdoc}
   */
  public $allowedBundles = ['courses'];

  /**
   * {@inheritdoc}
   */
  public function view() {
    $output = '';

    $language = entity_language($this->entityType, $this->entity);
    if (isset($this->entity->field_cricos_code[$language])) {
      $values = $this->entity->field_cricos_code[$language];

      $codes = [];
      foreach ($values as $value) {
        list($code,) = _vu_core_split_cricos_code($value['safe_value']);
        $codes[] = $code;
      }

      $output = implode(array_unique($codes), ', ');
    }

    return $output;
  }

}
