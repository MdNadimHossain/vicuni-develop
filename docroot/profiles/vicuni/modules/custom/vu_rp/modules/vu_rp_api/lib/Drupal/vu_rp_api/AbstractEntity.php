<?php

namespace Drupal\vu_rp_api;

/**
 * Class AbstractEntity.
 *
 * @package Drupal\vu_rp_api
 */
abstract class AbstractEntity {

  /**
   * Entity machine type.
   *
   * @var string
   */
  protected $type;

  /**
   * Entity human-readable title.
   *
   * @var string
   */
  protected $title;

  /**
   * Entity name.
   *
   * @var string
   */
  protected $name;

  /**
   * AbstractEntity constructor.
   */
  public function __construct($type, $name, $title) {
    $this->type = $type;
    $this->name = $name;
    $this->title = $title;
  }

  /**
   * Title getter.
   */
  public function getTitle() {
    return $this->title;
  }

  /**
   * Title setter.
   */
  public function setTitle($title) {
    $this->title = $title;

    return $this;
  }

  /**
   * Name getter.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Name setter.
   */
  public function setName($name) {
    $this->name = $name;

    return $this;
  }

  /**
   * Type getter.
   */
  public function getType() {
    return $this->type;
  }

  /**
   * Type setter.
   */
  public function setType($type) {
    $this->type = $type;

    return $this;
  }

  /**
   * Post-create entity hook.
   *
   * Entities may define additional field mapping and processing after an entity
   * was created.
   *
   * @param array $info
   *   Array of collected information about entity through hook implementations.
   */
  public function postCreate($info) {
    // Intentionally blank.
  }

  /**
   * Return an array of required fields to define this entity.
   */
  public static function getRequiredFields() {
    return [
      'title',
    ];
  }

}
