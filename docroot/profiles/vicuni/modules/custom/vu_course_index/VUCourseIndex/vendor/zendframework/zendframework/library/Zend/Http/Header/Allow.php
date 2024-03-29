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

namespace Zend\Http\Header;

use Zend\Http\Request;

/**
 * Allow Header
 *
 * @link       http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.7
 */
class Allow implements HeaderInterface {
  /**
   * List of request methods
   * true states that method is allowed, false - disallowed
   * By default GET and POST are allowed
   *
   * @var array
   */
  protected $methods = array(
    Request::METHOD_OPTIONS => FALSE,
    Request::METHOD_GET => TRUE,
    Request::METHOD_HEAD => FALSE,
    Request::METHOD_POST => TRUE,
    Request::METHOD_PUT => FALSE,
    Request::METHOD_DELETE => FALSE,
    Request::METHOD_TRACE => FALSE,
    Request::METHOD_CONNECT => FALSE,
    Request::METHOD_PATCH => FALSE,
  );

  /**
   * Create Allow header from header line
   *
   * @param string $headerLine
   *
   * @return Allow
   * @throws Exception\InvalidArgumentException
   */
  public static function fromString($headerLine) {
    list($name, $value) = GenericHeader::splitHeaderLine($headerLine);

    // check to ensure proper header type for this factory
    if (strtolower($name) !== 'allow') {
      throw new Exception\InvalidArgumentException('Invalid header line for Allow string: "' . $name . '"');
    }

    $header = new static();
    $header->disallowMethods(array_keys($header->getAllMethods()));
    $header->allowMethods(explode(',', $value));

    return $header;
  }

  /**
   * Get header name
   *
   * @return string
   */
  public function getFieldName() {
    return 'Allow';
  }

  /**
   * Get comma-separated list of allowed methods
   *
   * @return string
   */
  public function getFieldValue() {
    return implode(', ', array_keys($this->methods, TRUE, TRUE));
  }

  /**
   * Get list of all defined methods
   *
   * @return array
   */
  public function getAllMethods() {
    return $this->methods;
  }

  /**
   * Get list of allowed methods
   *
   * @return array
   */
  public function getAllowedMethods() {
    return array_keys($this->methods, TRUE, TRUE);
  }

  /**
   * Allow methods or list of methods
   *
   * @param array|string $allowedMethods
   *
   * @return Allow
   */
  public function allowMethods($allowedMethods) {
    foreach ((array) $allowedMethods as $method) {
      $method = trim(strtoupper($method));
      $this->methods[$method] = TRUE;
    }

    return $this;
  }

  /**
   * Disallow methods or list of methods
   *
   * @param array|string $disallowedMethods
   *
   * @return Allow
   */
  public function disallowMethods($disallowedMethods) {
    foreach ((array) $disallowedMethods as $method) {
      $method = trim(strtoupper($method));
      $this->methods[$method] = FALSE;
    }

    return $this;
  }

  /**
   * Convenience alias for @see disallowMethods()
   *
   * @param array|string $disallowedMethods
   *
   * @return Allow
   */
  public function denyMethods($disallowedMethods) {
    return $this->disallowMethods($disallowedMethods);
  }

  /**
   * Check whether method is allowed
   *
   * @param string $method
   *
   * @return bool
   */
  public function isAllowedMethod($method) {
    $method = trim(strtoupper($method));

    // disallow unknown method
    if (!isset($this->methods[$method])) {
      $this->methods[$method] = FALSE;
    }

    return $this->methods[$method];
  }

  /**
   * Return header as string
   *
   * @return string
   */
  public function toString() {
    return 'Allow: ' . $this->getFieldValue();
  }
}
