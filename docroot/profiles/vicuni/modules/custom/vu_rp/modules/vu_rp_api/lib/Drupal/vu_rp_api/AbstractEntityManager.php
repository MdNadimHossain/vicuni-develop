<?php

namespace Drupal\vu_rp_api;

use Drupal\vu_rp_api\Config\ConfigManager;

/**
 * Class AbstractEntityManager.
 *
 * Factory for available entities.
 */
abstract class AbstractEntityManager {

  /**
   * The configuration manager.
   *
   * @var \Drupal\vu_rp_api\Config\ConfigManager
   */
  protected $configManager;

  /**
   * Array of entities to manage.
   *
   * @var \Drupal\vu_rp_api\AbstractEntity[]
   */
  protected $entities;

  /**
   * ProviderManager constructor.
   *
   * @param \Drupal\vu_rp_api\Config\ConfigManager $configManager
   *   Config manager.
   */
  public function __construct(ConfigManager $configManager) {
    $this->configManager = $configManager;
  }

  /**
   * Return entity type (machine name).
   */
  abstract protected function getEntityType();

  /**
   * Get all entities.
   *
   * @param bool $reset
   *   Optional flag to reset internal cache and re-instantiate entities.
   *
   * @return \Drupal\vu_rp_api\AbstractEntity[]
   *   Array of fully loaded entities.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If entity structure s malformed.
   */
  public function getAll($reset = FALSE) {
    if ($this->entities && !$reset) {
      return $this->entities;
    }

    $class_name = $this->buildEntityClass($this->getEntityType());
    $infos = $this->collectInfo();
    foreach ($infos as $name => $info) {
      $title = is_array($info) && isset($info['title']) ? $info['title'] : $info;
      if (!is_string($title)) {
        throw new Exception('Malformed entity information structure');
      }
      if (in_array('Drupal\vu_rp_api\ConfigurableEntityTrait', class_uses($class_name))) {
        $config = $this->configManager->getConfig($this->getEntityType(), $name);
        /** @var \Drupal\vu_rp_api\AbstractEntity $entity */
        $entity = new $class_name($this->getEntityType(), $name, $title, $this->configManager, $config);
      }
      else {
        $entity = new $class_name($this->getEntityType(), $name, $title);
      }
      $entity->postCreate($info);
      $this->entities[$name] = $entity;
    }

    return $this->entities;
  }

  /**
   * Get single matched entity by type.
   *
   * @param string $type
   *   Entity type.
   *
   * @return \Drupal\vu_rp_api\AbstractEntity|null
   *   A single entity.
   */
  public function getSingle($type) {
    $all = $this->getAll();

    return isset($all[$type]) ? $all[$type] : NULL;
  }

  /**
   * Get currently active entities.
   *
   * @return \Drupal\vu_rp_api\AbstractEntity[]
   *   Array of currently stored entities.
   */
  public function getCurrent() {
    $all = $this->getAll();
    $current = $this->configManager->getStoredEntityIds($this->getEntityType());

    return array_intersect_key($all, array_flip($current));
  }

  /**
   * Get single currently stored entity.
   *
   * @return \Drupal\vu_rp_api\AbstractEntity
   *   Currently stored entities.
   */
  public function getCurrentSingle() {
    $current = $this->getCurrent();

    return count($current) > 0 ? reset($current) : NULL;
  }

  /**
   * Get form key for a currently stored entity.
   */
  public function getCurrentFormKey() {
    return $this->configManager->buildConfigKey($this->getEntityType());
  }

  /**
   * Helper to get form options for currently managed entities.
   */
  public function getFormOptions() {
    $options = [];

    $all = $this->getAll();
    foreach ($all as $entity) {
      $options[$entity->getName()] = $entity->getTitle();
    }

    return $options;
  }

  /**
   * Collect info about entities.
   *
   * @return array
   *   Information about entities.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If entity info hook does not provide enough required fields defined in
   *   specific's entity class.
   *
   * @see vu_rp_api_ENTITYs()
   */
  protected function collectInfo() {
    $hook = 'vu_rp_api_' . $this->getEntityType() . 's';

    $info = module_invoke_all($hook);

    $entity_class = $this->buildEntityClass($this->getEntityType());

    $required_fields = call_user_func([$entity_class, 'getRequiredFields']);
    $missing_fields = array_intersect_key($info, array_flip($required_fields));
    if (!empty($missing_fields)) {
      throw new Exception(sprintf('Missing required field(s) "%s" in "%s" entity info hook', implode(', ', $missing_fields), $this->getEntityType()));
    }

    return $info;
  }

  /**
   * Build entity class from entity type.
   *
   * @param string $type
   *   Entity type.
   *
   * @return string
   *   Class name.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If the class does not exist.
   *   If the class does not extend AbstractEntity class.
   */
  protected function buildEntityClass($type) {
    $parent_class_name = __NAMESPACE__ . '\AbstractEntity';
    $class_name = Utilities::toCamelCase($type, TRUE);
    $class_name = __NAMESPACE__ . '\\' . $class_name . '\\' . $class_name;
    if (!class_exists($class_name)) {
      throw new Exception(sprintf('Class "%s" does not exist', $class_name));
    }
    elseif (!in_array($parent_class_name, class_parents($class_name))) {
      throw new Exception(sprintf('"%s" class exists, but it does not extend "%s" class', $class_name, $parent_class_name));
    }

    return $class_name;
  }

}
