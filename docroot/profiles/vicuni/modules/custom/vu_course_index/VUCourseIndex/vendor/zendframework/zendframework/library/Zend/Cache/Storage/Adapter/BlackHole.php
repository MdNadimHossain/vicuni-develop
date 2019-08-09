<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Cache\Storage\Adapter;

use stdClass;
use Zend\Cache\Storage\AvailableSpaceCapableInterface;
use Zend\Cache\Storage\Capabilities;
use Zend\Cache\Storage\ClearByNamespaceInterface;
use Zend\Cache\Storage\ClearByPrefixInterface;
use Zend\Cache\Storage\ClearExpiredInterface;
use Zend\Cache\Storage\FlushableInterface;
use Zend\Cache\Storage\IterableInterface;
use Zend\Cache\Storage\OptimizableInterface;
use Zend\Cache\Storage\StorageInterface;
use Zend\Cache\Storage\TaggableInterface;
use Zend\Cache\Storage\TotalSpaceCapableInterface;

class BlackHole implements
  StorageInterface,
  AvailableSpaceCapableInterface,
  ClearByNamespaceInterface,
  ClearByPrefixInterface,
  ClearExpiredInterface,
  FlushableInterface,
  IterableInterface,
  OptimizableInterface,
  TaggableInterface,
  TotalSpaceCapableInterface {
  /**
   * Capabilities of this adapter
   *
   * @var null|Capabilities
   */
  protected $capabilities = NULL;

  /**
   * Marker to change capabilities
   *
   * @var null|object
   */
  protected $capabilityMarker;

  /**
   * options
   *
   * @var null|AdapterOptions
   */
  protected $options;

  /**
   * Constructor
   *
   * @param  null|array|\Traversable|AdapterOptions $options
   */
  public function __construct($options = NULL) {
    if ($options) {
      $this->setOptions($options);
    }
  }

  /**
   * Set options.
   *
   * @param array|\Traversable|AdapterOptions $options
   *
   * @return StorageInterface Fluent interface
   */
  public function setOptions($options) {
    if ($this->options !== $options) {
      if (!$options instanceof AdapterOptions) {
        $options = new AdapterOptions($options);
      }

      if ($this->options) {
        $this->options->setAdapter(NULL);
      }
      $options->setAdapter($this);
      $this->options = $options;
    }
    return $this;
  }

  /**
   * Get options
   *
   * @return AdapterOptions
   */
  public function getOptions() {
    if (!$this->options) {
      $this->setOptions(new AdapterOptions());
    }
    return $this->options;
  }

  /**
   * Get an item.
   *
   * @param  string $key
   * @param  bool $success
   * @param  mixed $casToken
   *
   * @return mixed Data on success, null on failure
   */
  public function getItem($key, & $success = NULL, & $casToken = NULL) {
    $success = FALSE;
    return NULL;
  }

  /**
   * Get multiple items.
   *
   * @param  array $keys
   *
   * @return array Associative array of keys and values
   */
  public function getItems(array $keys) {
    return array();
  }

  /**
   * Test if an item exists.
   *
   * @param  string $key
   *
   * @return bool
   */
  public function hasItem($key) {
    return FALSE;
  }

  /**
   * Test multiple items.
   *
   * @param  array $keys
   *
   * @return array Array of found keys
   */
  public function hasItems(array $keys) {
    return array();
  }

  /**
   * Get metadata of an item.
   *
   * @param  string $key
   *
   * @return array|bool Metadata on success, false on failure
   */
  public function getMetadata($key) {
    return FALSE;
  }

  /**
   * Get multiple metadata
   *
   * @param  array $keys
   *
   * @return array Associative array of keys and metadata
   */
  public function getMetadatas(array $keys) {
    return array();
  }

  /**
   * Store an item.
   *
   * @param  string $key
   * @param  mixed $value
   *
   * @return bool
   */
  public function setItem($key, $value) {
    return FALSE;
  }

  /**
   * Store multiple items.
   *
   * @param  array $keyValuePairs
   *
   * @return array Array of not stored keys
   */
  public function setItems(array $keyValuePairs) {
    return array_keys($keyValuePairs);
  }

  /**
   * Add an item.
   *
   * @param  string $key
   * @param  mixed $value
   *
   * @return bool
   */
  public function addItem($key, $value) {
    return FALSE;
  }

  /**
   * Add multiple items.
   *
   * @param  array $keyValuePairs
   *
   * @return array Array of not stored keys
   */
  public function addItems(array $keyValuePairs) {
    return array_keys($keyValuePairs);
  }

  /**
   * Replace an existing item.
   *
   * @param  string $key
   * @param  mixed $value
   *
   * @return bool
   */
  public function replaceItem($key, $value) {
    return FALSE;
  }

  /**
   * Replace multiple existing items.
   *
   * @param  array $keyValuePairs
   *
   * @return array Array of not stored keys
   */
  public function replaceItems(array $keyValuePairs) {
    return array_keys($keyValuePairs);
  }

  /**
   * Set an item only if token matches
   *
   * It uses the token received from getItem() to check if the item has
   * changed before overwriting it.
   *
   * @param  mixed $token
   * @param  string $key
   * @param  mixed $value
   *
   * @return bool
   */
  public function checkAndSetItem($token, $key, $value) {
    return FALSE;
  }

  /**
   * Reset lifetime of an item
   *
   * @param  string $key
   *
   * @return bool
   */
  public function touchItem($key) {
    return FALSE;
  }

  /**
   * Reset lifetime of multiple items.
   *
   * @param  array $keys
   *
   * @return array Array of not updated keys
   */
  public function touchItems(array $keys) {
    return $keys;
  }

  /**
   * Remove an item.
   *
   * @param  string $key
   *
   * @return bool
   */
  public function removeItem($key) {
    return FALSE;
  }

  /**
   * Remove multiple items.
   *
   * @param  array $keys
   *
   * @return array Array of not removed keys
   */
  public function removeItems(array $keys) {
    return $keys;
  }

  /**
   * Increment an item.
   *
   * @param  string $key
   * @param  int $value
   *
   * @return int|bool The new value on success, false on failure
   */
  public function incrementItem($key, $value) {
    return FALSE;
  }

  /**
   * Increment multiple items.
   *
   * @param  array $keyValuePairs
   *
   * @return array Associative array of keys and new values
   */
  public function incrementItems(array $keyValuePairs) {
    return array();
  }

  /**
   * Decrement an item.
   *
   * @param  string $key
   * @param  int $value
   *
   * @return int|bool The new value on success, false on failure
   */
  public function decrementItem($key, $value) {
    return FALSE;
  }

  /**
   * Decrement multiple items.
   *
   * @param  array $keyValuePairs
   *
   * @return array Associative array of keys and new values
   */
  public function decrementItems(array $keyValuePairs) {
    return array();
  }

  /**
   * Capabilities of this storage
   *
   * @return Capabilities
   */
  public function getCapabilities() {
    if ($this->capabilities === NULL) {
      // use default capabilities only
      $this->capabilityMarker = new stdClass();
      $this->capabilities = new Capabilities($this, $this->capabilityMarker);
    }
    return $this->capabilities;
  }

  /* AvailableSpaceCapableInterface */

  /**
   * Get available space in bytes
   *
   * @return int|float
   */
  public function getAvailableSpace() {
    return 0;
  }

  /* ClearByNamespaceInterface */

  /**
   * Remove items of given namespace
   *
   * @param string $namespace
   *
   * @return bool
   */
  public function clearByNamespace($namespace) {
    return FALSE;
  }

  /* ClearByPrefixInterface */

  /**
   * Remove items matching given prefix
   *
   * @param string $prefix
   *
   * @return bool
   */
  public function clearByPrefix($prefix) {
    return FALSE;
  }

  /* ClearExpiredInterface */

  /**
   * Remove expired items
   *
   * @return bool
   */
  public function clearExpired() {
    return FALSE;
  }

  /* FlushableInterface */

  /**
   * Flush the whole storage
   *
   * @return bool
   */
  public function flush() {
    return FALSE;
  }

  /* IterableInterface */

  /**
   * Get the storage iterator
   *
   * @return KeyListIterator
   */
  public function getIterator() {
    return new KeyListIterator($this, array());
  }

  /* OptimizableInterface */

  /**
   * Optimize the storage
   *
   * @return bool
   */
  public function optimize() {
    return FALSE;
  }

  /* TaggableInterface */

  /**
   * Set tags to an item by given key.
   * An empty array will remove all tags.
   *
   * @param string $key
   * @param string[] $tags
   *
   * @return bool
   */
  public function setTags($key, array $tags) {
    return FALSE;
  }

  /**
   * Get tags of an item by given key
   *
   * @param string $key
   *
   * @return string[]|FALSE
   */
  public function getTags($key) {
    return FALSE;
  }

  /**
   * Remove items matching given tags.
   *
   * If $disjunction only one of the given tags must match
   * else all given tags must match.
   *
   * @param string[] $tags
   * @param  bool $disjunction
   *
   * @return bool
   */
  public function clearByTags(array $tags, $disjunction = FALSE) {
    return FALSE;
  }

  /* TotalSpaceCapableInterface */

  /**
   * Get total space in bytes
   *
   * @return int|float
   */
  public function getTotalSpace() {
    return 0;
  }
}
