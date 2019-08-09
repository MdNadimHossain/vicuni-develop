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

namespace Zend\Serializer\Adapter;

abstract class AbstractAdapter implements AdapterInterface {
  /**
   * @var AdapterOptions
   */
  protected $options = NULL;

  /**
   * Constructor
   *
   * @param array|\Traversable|AdapterOptions $options
   */
  public function __construct($options = NULL) {
    if ($options !== NULL) {
      $this->setOptions($options);
    }
  }

  /**
   * Set adapter options
   *
   * @param  array|\Traversable|AdapterOptions $options
   *
   * @return AbstractAdapter
   */
  public function setOptions($options) {
    if (!$options instanceof AdapterOptions) {
      $options = new AdapterOptions($options);
    }

    $this->options = $options;
    return $this;
  }

  /**
   * Get adapter options
   *
   * @return AdapterOptions
   */
  public function getOptions() {
    if ($this->options === NULL) {
      $this->options = new AdapterOptions();
    }
    return $this->options;
  }
}
