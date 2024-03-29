<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Cache\Storage\Adapter;

use stdClass;
use Zend\Cache\Exception;
use Zend\Cache\Storage\AvailableSpaceCapableInterface;
use Zend\Cache\Storage\Capabilities;
use Zend\Cache\Storage\ClearByNamespaceInterface;
use Zend\Cache\Storage\ClearByPrefixInterface;
use Zend\Cache\Storage\ClearExpiredInterface;
use Zend\Cache\Storage\FlushableInterface;
use Zend\Cache\Storage\IterableInterface;
use Zend\Cache\Storage\TaggableInterface;
use Zend\Cache\Storage\TotalSpaceCapableInterface;

class Memory extends AbstractAdapter implements
  AvailableSpaceCapableInterface,
  ClearByPrefixInterface,
  ClearByNamespaceInterface,
  ClearExpiredInterface,
  FlushableInterface,
  IterableInterface,
  TaggableInterface,
  TotalSpaceCapableInterface {
  /**
   * Data Array
   *
   * Format:
   * array(
   *     <NAMESPACE> => array(
   *         <KEY> => array(
   *             0 => <VALUE>
   *             1 => <MICROTIME>
   *             ['tags' => <TAGS>]
   *         )
   *     )
   * )
   *
   * @var array
   */
  protected $data = array();

  /**
   * Set options.
   *
   * @param  array|\Traversable|MemoryOptions $options
   *
   * @return Memory
   * @see    getOptions()
   */
  public function setOptions($options) {
    if (!$options instanceof MemoryOptions) {
      $options = new MemoryOptions($options);
    }

    return parent::setOptions($options);
  }

  /**
   * Get options.
   *
   * @return MemoryOptions
   * @see setOptions()
   */
  public function getOptions() {
    if (!$this->options) {
      $this->setOptions(new MemoryOptions());
    }
    return $this->options;
  }

  /* TotalSpaceCapableInterface */

  /**
   * Get total space in bytes
   *
   * @return int|float
   */
  public function getTotalSpace() {
    return $this->getOptions()->getMemoryLimit();
  }

  /* AvailableSpaceCapableInterface */

  /**
   * Get available space in bytes
   *
   * @return int|float
   */
  public function getAvailableSpace() {
    $total = $this->getOptions()->getMemoryLimit();
    $avail = $total - (float) memory_get_usage(TRUE);
    return ($avail > 0) ? $avail : 0;
  }

  /* IterableInterface */

  /**
   * Get the storage iterator
   *
   * @return KeyListIterator
   */
  public function getIterator() {
    $ns = $this->getOptions()->getNamespace();
    $keys = array();

    if (isset($this->data[$ns])) {
      foreach ($this->data[$ns] as $key => & $tmp) {
        if ($this->internalHasItem($key)) {
          $keys[] = $key;
        }
      }
    }

    return new KeyListIterator($this, $keys);
  }

  /* FlushableInterface */

  /**
   * Flush the whole storage
   *
   * @return bool
   */
  public function flush() {
    $this->data = array();
    return TRUE;
  }

  /* ClearExpiredInterface */

  /**
   * Remove expired items
   *
   * @return bool
   */
  public function clearExpired() {
    $ttl = $this->getOptions()->getTtl();
    if ($ttl <= 0) {
      return TRUE;
    }

    $ns = $this->getOptions()->getNamespace();
    if (!isset($this->data[$ns])) {
      return TRUE;
    }

    $data = &$this->data[$ns];
    foreach ($data as $key => & $item) {
      if (microtime(TRUE) >= $data[$key][1] + $ttl) {
        unset($data[$key]);
      }
    }

    return TRUE;
  }

  /* ClearByNamespaceInterface */

  public function clearByNamespace($namespace) {
    $namespace = (string) $namespace;
    if ($namespace === '') {
      throw new Exception\InvalidArgumentException('No namespace given');
    }

    unset($this->data[$namespace]);
    return TRUE;
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
    $prefix = (string) $prefix;
    if ($prefix === '') {
      throw new Exception\InvalidArgumentException('No prefix given');
    }

    $ns = $this->getOptions()->getNamespace();
    if (!isset($this->data[$ns])) {
      return TRUE;
    }

    $prefixL = strlen($prefix);
    $data = &$this->data[$ns];
    foreach ($data as $key => & $item) {
      if (substr($key, 0, $prefixL) === $prefix) {
        unset($data[$key]);
      }
    }

    return TRUE;
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
    $ns = $this->getOptions()->getNamespace();
    if (!$this->data[$ns]) {
      return FALSE;
    }

    $data = &$this->data[$ns];
    if (isset($data[$key])) {
      $data[$key]['tags'] = $tags;
      return TRUE;
    }

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
    $ns = $this->getOptions()->getNamespace();
    if (!$this->data[$ns]) {
      return FALSE;
    }

    $data = &$this->data[$ns];
    if (!isset($data[$key])) {
      return FALSE;
    }

    return isset($data[$key]['tags']) ? $data[$key]['tags'] : array();
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
    $ns = $this->getOptions()->getNamespace();
    if (!$this->data[$ns]) {
      return TRUE;
    }

    $tagCount = count($tags);
    $data = &$this->data[$ns];
    foreach ($data as $key => & $item) {
      if (isset($item['tags'])) {
        $diff = array_diff($tags, $item['tags']);
        if (($disjunction && count($diff) < $tagCount) || (!$disjunction && !$diff)) {
          unset($data[$key]);
        }
      }
    }

    return TRUE;
  }

  /* reading */

  /**
   * Internal method to get an item.
   *
   * @param  string $normalizedKey
   * @param  bool $success
   * @param  mixed $casToken
   *
   * @return mixed Data on success, null on failure
   * @throws Exception\ExceptionInterface
   */
  protected function internalGetItem(& $normalizedKey, & $success = NULL, & $casToken = NULL) {
    $options = $this->getOptions();
    $ns = $options->getNamespace();
    $success = isset($this->data[$ns][$normalizedKey]);
    if ($success) {
      $data = &$this->data[$ns][$normalizedKey];
      $ttl = $options->getTtl();
      if ($ttl && microtime(TRUE) >= ($data[1] + $ttl)) {
        $success = FALSE;
      }
    }

    if (!$success) {
      return NULL;
    }

    $casToken = $data[0];
    return $data[0];
  }

  /**
   * Internal method to get multiple items.
   *
   * @param  array $normalizedKeys
   *
   * @return array Associative array of keys and values
   * @throws Exception\ExceptionInterface
   */
  protected function internalGetItems(array & $normalizedKeys) {
    $options = $this->getOptions();
    $ns = $options->getNamespace();
    if (!isset($this->data[$ns])) {
      return array();
    }

    $data = &$this->data[$ns];
    $ttl = $options->getTtl();
    $now = microtime(TRUE);

    $result = array();
    foreach ($normalizedKeys as $normalizedKey) {
      if (isset($data[$normalizedKey])) {
        if (!$ttl || $now < ($data[$normalizedKey][1] + $ttl)) {
          $result[$normalizedKey] = $data[$normalizedKey][0];
        }
      }
    }

    return $result;
  }

  /**
   * Internal method to test if an item exists.
   *
   * @param  string $normalizedKey
   *
   * @return bool
   */
  protected function internalHasItem(& $normalizedKey) {
    $options = $this->getOptions();
    $ns = $options->getNamespace();
    if (!isset($this->data[$ns][$normalizedKey])) {
      return FALSE;
    }

    // check if expired
    $ttl = $options->getTtl();
    if ($ttl && microtime(TRUE) >= ($this->data[$ns][$normalizedKey][1] + $ttl)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Internal method to test multiple items.
   *
   * @param array $normalizedKeys
   *
   * @return array Array of found keys
   */
  protected function internalHasItems(array & $normalizedKeys) {
    $options = $this->getOptions();
    $ns = $options->getNamespace();
    if (!isset($this->data[$ns])) {
      return array();
    }

    $data = &$this->data[$ns];
    $ttl = $options->getTtl();
    $now = microtime(TRUE);

    $result = array();
    foreach ($normalizedKeys as $normalizedKey) {
      if (isset($data[$normalizedKey])) {
        if (!$ttl || $now < ($data[$normalizedKey][1] + $ttl)) {
          $result[] = $normalizedKey;
        }
      }
    }

    return $result;
  }

  /**
   * Get metadata of an item.
   *
   * @param  string $normalizedKey
   *
   * @return array|bool Metadata on success, false on failure
   * @throws Exception\ExceptionInterface
   *
   * @triggers getMetadata.pre(PreEvent)
   * @triggers getMetadata.post(PostEvent)
   * @triggers getMetadata.exception(ExceptionEvent)
   */
  protected function internalGetMetadata(& $normalizedKey) {
    if (!$this->internalHasItem($normalizedKey)) {
      return FALSE;
    }

    $ns = $this->getOptions()->getNamespace();
    return array(
      'mtime' => $this->data[$ns][$normalizedKey][1],
    );
  }

  /* writing */

  /**
   * Internal method to store an item.
   *
   * @param  string $normalizedKey
   * @param  mixed $value
   *
   * @return bool
   * @throws Exception\ExceptionInterface
   */
  protected function internalSetItem(& $normalizedKey, & $value) {
    $options = $this->getOptions();

    if (!$this->hasAvailableSpace()) {
      $memoryLimit = $options->getMemoryLimit();
      throw new Exception\OutOfSpaceException(
        "Memory usage exceeds limit ({$memoryLimit})."
      );
    }

    $ns = $options->getNamespace();
    $this->data[$ns][$normalizedKey] = array($value, microtime(TRUE));

    return TRUE;
  }

  /**
   * Internal method to store multiple items.
   *
   * @param  array $normalizedKeyValuePairs
   *
   * @return array Array of not stored keys
   * @throws Exception\ExceptionInterface
   */
  protected function internalSetItems(array & $normalizedKeyValuePairs) {
    $options = $this->getOptions();

    if (!$this->hasAvailableSpace()) {
      $memoryLimit = $options->getMemoryLimit();
      throw new Exception\OutOfSpaceException(
        "Memory usage exceeds limit ({$memoryLimit})."
      );
    }

    $ns = $options->getNamespace();
    if (!isset($this->data[$ns])) {
      $this->data[$ns] = array();
    }

    $data = &$this->data[$ns];
    $now = microtime(TRUE);
    foreach ($normalizedKeyValuePairs as $normalizedKey => $value) {
      $data[$normalizedKey] = array($value, $now);
    }

    return array();
  }

  /**
   * Add an item.
   *
   * @param  string $normalizedKey
   * @param  mixed $value
   *
   * @return bool
   * @throws Exception\ExceptionInterface
   */
  protected function internalAddItem(& $normalizedKey, & $value) {
    $options = $this->getOptions();

    if (!$this->hasAvailableSpace()) {
      $memoryLimit = $options->getMemoryLimit();
      throw new Exception\OutOfSpaceException(
        "Memory usage exceeds limit ({$memoryLimit})."
      );
    }

    $ns = $options->getNamespace();
    if (isset($this->data[$ns][$normalizedKey])) {
      return FALSE;
    }

    $this->data[$ns][$normalizedKey] = array($value, microtime(TRUE));
    return TRUE;
  }

  /**
   * Internal method to add multiple items.
   *
   * @param  array $normalizedKeyValuePairs
   *
   * @return array Array of not stored keys
   * @throws Exception\ExceptionInterface
   */
  protected function internalAddItems(array & $normalizedKeyValuePairs) {
    $options = $this->getOptions();

    if (!$this->hasAvailableSpace()) {
      $memoryLimit = $options->getMemoryLimit();
      throw new Exception\OutOfSpaceException(
        "Memory usage exceeds limit ({$memoryLimit})."
      );
    }

    $ns = $options->getNamespace();
    if (!isset($this->data[$ns])) {
      $this->data[$ns] = array();
    }

    $result = array();
    $data = &$this->data[$ns];
    $now = microtime(TRUE);
    foreach ($normalizedKeyValuePairs as $normalizedKey => $value) {
      if (isset($data[$normalizedKey])) {
        $result[] = $normalizedKey;
      }
      else {
        $data[$normalizedKey] = array($value, $now);
      }
    }

    return $result;
  }

  /**
   * Internal method to replace an existing item.
   *
   * @param  string $normalizedKey
   * @param  mixed $value
   *
   * @return bool
   * @throws Exception\ExceptionInterface
   */
  protected function internalReplaceItem(& $normalizedKey, & $value) {
    $ns = $this->getOptions()->getNamespace();
    if (!isset($this->data[$ns][$normalizedKey])) {
      return FALSE;
    }
    $this->data[$ns][$normalizedKey] = array($value, microtime(TRUE));

    return TRUE;
  }

  /**
   * Internal method to replace multiple existing items.
   *
   * @param  array $normalizedKeyValuePairs
   *
   * @return array Array of not stored keys
   * @throws Exception\ExceptionInterface
   */
  protected function internalReplaceItems(array & $normalizedKeyValuePairs) {
    $ns = $this->getOptions()->getNamespace();
    if (!isset($this->data[$ns])) {
      return array_keys($normalizedKeyValuePairs);
    }

    $result = array();
    $data = &$this->data[$ns];
    foreach ($normalizedKeyValuePairs as $normalizedKey => $value) {
      if (!isset($data[$normalizedKey])) {
        $result[] = $normalizedKey;
      }
      else {
        $data[$normalizedKey] = array($value, microtime(TRUE));
      }
    }

    return $result;
  }

  /**
   * Internal method to reset lifetime of an item
   *
   * @param  string $normalizedKey
   *
   * @return bool
   * @throws Exception\ExceptionInterface
   */
  protected function internalTouchItem(& $normalizedKey) {
    $ns = $this->getOptions()->getNamespace();

    if (!isset($this->data[$ns][$normalizedKey])) {
      return FALSE;
    }

    $this->data[$ns][$normalizedKey][1] = microtime(TRUE);
    return TRUE;
  }

  /**
   * Internal method to remove an item.
   *
   * @param  string $normalizedKey
   *
   * @return bool
   * @throws Exception\ExceptionInterface
   */
  protected function internalRemoveItem(& $normalizedKey) {
    $ns = $this->getOptions()->getNamespace();
    if (!isset($this->data[$ns][$normalizedKey])) {
      return FALSE;
    }

    unset($this->data[$ns][$normalizedKey]);

    // remove empty namespace
    if (!$this->data[$ns]) {
      unset($this->data[$ns]);
    }

    return TRUE;
  }

  /**
   * Internal method to increment an item.
   *
   * @param  string $normalizedKey
   * @param  int $value
   *
   * @return int|bool The new value on success, false on failure
   * @throws Exception\ExceptionInterface
   */
  protected function internalIncrementItem(& $normalizedKey, & $value) {
    $ns = $this->getOptions()->getNamespace();
    $data = &$this->data[$ns];
    if (isset($data[$normalizedKey])) {
      $data[$normalizedKey][0] += $value;
      $data[$normalizedKey][1] = microtime(TRUE);
      $newValue = $data[$normalizedKey][0];
    }
    else {
      // initial value
      $newValue = $value;
      $data[$normalizedKey] = array($newValue, microtime(TRUE));
    }

    return $newValue;
  }

  /**
   * Internal method to decrement an item.
   *
   * @param  string $normalizedKey
   * @param  int $value
   *
   * @return int|bool The new value on success, false on failure
   * @throws Exception\ExceptionInterface
   */
  protected function internalDecrementItem(& $normalizedKey, & $value) {
    $ns = $this->getOptions()->getNamespace();
    $data = &$this->data[$ns];
    if (isset($data[$normalizedKey])) {
      $data[$normalizedKey][0] -= $value;
      $data[$normalizedKey][1] = microtime(TRUE);
      $newValue = $data[$normalizedKey][0];
    }
    else {
      // initial value
      $newValue = -$value;
      $data[$normalizedKey] = array($newValue, microtime(TRUE));
    }

    return $newValue;
  }

  /* status */

  /**
   * Internal method to get capabilities of this adapter
   *
   * @return Capabilities
   */
  protected function internalGetCapabilities() {
    if ($this->capabilities === NULL) {
      $this->capabilityMarker = new stdClass();
      $this->capabilities = new Capabilities(
        $this,
        $this->capabilityMarker,
        array(
          'supportedDatatypes' => array(
            'NULL' => TRUE,
            'boolean' => TRUE,
            'integer' => TRUE,
            'double' => TRUE,
            'string' => TRUE,
            'array' => TRUE,
            'object' => TRUE,
            'resource' => TRUE,
          ),
          'supportedMetadata' => array('mtime'),
          'minTtl' => 1,
          'maxTtl' => PHP_INT_MAX,
          'staticTtl' => FALSE,
          'ttlPrecision' => 0.05,
          'expiredRead' => TRUE,
          'maxKeyLength' => 0,
          'namespaceIsPrefix' => FALSE,
          'namespaceSeparator' => '',
        )
      );
    }

    return $this->capabilities;
  }

  /* internal */

  /**
   * Has space available to store items?
   *
   * @return bool
   */
  protected function hasAvailableSpace() {
    $total = $this->getOptions()->getMemoryLimit();

    // check memory limit disabled
    if ($total <= 0) {
      return TRUE;
    }

    $free = $total - (float) memory_get_usage(TRUE);
    return ($free > 0);
  }
}
