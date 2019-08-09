<?php

/**
 * Base Field for VU Courses Fields.
 */
class VuCoursesFieldsBase {

  /**
   * Block cache mode.
   *
   * @var int
   */
  public static $cache = DRUPAL_CACHE_GLOBAL;

  /**
   * Human readable block name.
   *
   * @var null|string
   */
  public static $info = NULL;

  /**
   * Entity object for the field.
   *
   * @var null|\stdClass
   */
  public $entity = NULL;

  /**
   * Type of entity.
   *
   * @var null|string
   */
  public $entityType = NULL;

  /**
   * Bundle of the entity which the object relates to.
   *
   * @var null|string
   */
  public $bundle = NULL;

  /**
   * Information about the field passed form Display Suite.
   *
   * @var null|array
   */
  public $fieldInfo = NULL;

  /**
   * The theme to render.
   *
   * @var bool
   */
  public $theme = FALSE;

  /**
   * A list of allowed bundles this field can be used on.
   *
   * @var null|array
   */
  public $allowedBundles = NULL;

  /**
   * {@inheritdoc}
   */
  public function __construct($info) {
    $this->entity = $info['entity'];
    $this->entityType = $info['entity_type'];
    $this->bundle = $info['bundle'];
    $this->fieldInfo = $info;
  }

  /**
   * Extra conditions callback.
   *
   * @return bool
   *   TRUE if block should display, else FALSE.
   */
  public function condCallback() {
    if (is_array($this->allowedBundles) && !in_array($this->bundle, $this->allowedBundles)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Check if the block should be visible.
   *
   * @return bool
   *   TRUE if the block is visible, else FALSE.
   */
  public function isVisible() {
    return $this->condCallback();
  }

  /**
   * Build a list of default settings for this field.
   *
   * @return array
   *   An array of the default settings.
   */
  public static function defaults() {
    return [];
  }

  /**
   * Block view theme function variables.
   *
   * @return array
   *   The template variables for this block.
   */
  public function variables() {
    return [];
  }

  /**
   * Block view callback.
   *
   * @return array|bool
   *   The rendered result.
   *
   * @throws \Exception
   */
  public function view() {
    // Ensure a theme is defined for the output of this block.
    if (!$this->theme) {
      return FALSE;
    }
    return theme($this->theme, $this->variables());
  }

  /**
   * Build the current field.
   */
  public function build() {
    if ($this->isVisible()) {
      return $this->view();
    }
  }

  /**
   * Build settings form.
   */
  public function settings() {
    return [];
  }

}
