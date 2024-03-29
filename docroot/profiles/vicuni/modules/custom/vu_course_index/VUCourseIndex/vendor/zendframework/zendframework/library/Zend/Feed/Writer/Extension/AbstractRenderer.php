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

namespace Zend\Feed\Writer\Extension;

use DOMDocument;
use DOMElement;

/**
 */
abstract class AbstractRenderer implements RendererInterface {
  /**
   * @var DOMDocument
   */
  protected $dom = NULL;

  /**
   * @var mixed
   */
  protected $entry = NULL;

  /**
   * @var DOMElement
   */
  protected $base = NULL;

  /**
   * @var mixed
   */
  protected $container = NULL;

  /**
   * @var string
   */
  protected $type = NULL;

  /**
   * @var DOMElement
   */
  protected $rootElement = NULL;

  /**
   * Encoding of all text values
   *
   * @var string
   */
  protected $encoding = 'UTF-8';

  /**
   * Set the data container
   *
   * @param  mixed $container
   *
   * @return AbstractRenderer
   */
  public function setDataContainer($container) {
    $this->container = $container;
    return $this;
  }

  /**
   * Set feed encoding
   *
   * @param  string $enc
   *
   * @return AbstractRenderer
   */
  public function setEncoding($enc) {
    $this->encoding = $enc;
    return $this;
  }

  /**
   * Get feed encoding
   *
   * @return string
   */
  public function getEncoding() {
    return $this->encoding;
  }

  /**
   * Set DOMDocument and DOMElement on which to operate
   *
   * @param  DOMDocument $dom
   * @param  DOMElement $base
   *
   * @return AbstractRenderer
   */
  public function setDomDocument(DOMDocument $dom, DOMElement $base) {
    $this->dom = $dom;
    $this->base = $base;
    return $this;
  }

  /**
   * Get data container being rendered
   *
   * @return mixed
   */
  public function getDataContainer() {
    return $this->container;
  }

  /**
   * Set feed type
   *
   * @param  string $type
   *
   * @return AbstractRenderer
   */
  public function setType($type) {
    $this->type = $type;
    return $this;
  }

  /**
   * Get feedtype
   *
   * @return string
   */
  public function getType() {
    return $this->type;
  }

  /**
   * Set root element of document
   *
   * @param  DOMElement $root
   *
   * @return AbstractRenderer
   */
  public function setRootElement(DOMElement $root) {
    $this->rootElement = $root;
    return $this;
  }

  /**
   * Get root element
   *
   * @return DOMElement
   */
  public function getRootElement() {
    return $this->rootElement;
  }

  /**
   * Append namespaces to feed
   *
   * @return void
   */
  abstract protected function _appendNamespaces();
}
