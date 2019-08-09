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

namespace Zend\Feed;

class Uri {
  /**
   * @var string
   */
  protected $fragment;

  /**
   * @var string
   */
  protected $host;

  /**
   * @var string
   */
  protected $pass;

  /**
   * @var string
   */
  protected $path;

  /**
   * @var int
   */
  protected $port;

  /**
   * @var string
   */
  protected $query;

  /**
   * @var string
   */
  protected $scheme;

  /**
   * @var string
   */
  protected $user;

  /**
   * @var bool
   */
  protected $valid;

  /**
   * Valid schemes
   */
  protected $validSchemes = array(
    'http',
    'https',
    'file',
  );

  /**
   * @param  string $uri
   */
  public function __construct($uri) {
    $parsed = parse_url($uri);
    if (FALSE === $parsed) {
      $this->valid = FALSE;
      return;
    }

    $this->scheme = isset($parsed['scheme']) ? $parsed['scheme'] : NULL;
    $this->host = isset($parsed['host']) ? $parsed['host'] : NULL;
    $this->port = isset($parsed['port']) ? $parsed['port'] : NULL;
    $this->user = isset($parsed['user']) ? $parsed['user'] : NULL;
    $this->pass = isset($parsed['pass']) ? $parsed['pass'] : NULL;
    $this->path = isset($parsed['path']) ? $parsed['path'] : NULL;
    $this->query = isset($parsed['query']) ? $parsed['query'] : NULL;
    $this->fragment = isset($parsed['fragment']) ? $parsed['fragment'] : NULL;
  }

  /**
   * Create an instance
   *
   * Useful for chained validations
   *
   * @param  string $uri
   *
   * @return self
   */
  public static function factory($uri) {
    return new static($uri);
  }

  /**
   * Retrieve the host
   *
   * @return string
   */
  public function getHost() {
    return $this->host;
  }

  /**
   * Retrieve the URI path
   *
   * @return string
   */
  public function getPath() {
    return $this->path;
  }

  /**
   * Retrieve the scheme
   *
   * @return string
   */
  public function getScheme() {
    return $this->scheme;
  }

  /**
   * Is the URI valid?
   *
   * @return bool
   */
  public function isValid() {
    if (FALSE === $this->valid) {
      return FALSE;
    }

    if ($this->scheme && !in_array($this->scheme, $this->validSchemes)) {
      return FALSE;
    }

    if ($this->host) {
      if ($this->path && substr($this->path, 0, 1) != '/') {
        return FALSE;
      }
      return TRUE;
    }

    // no host, but user and/or port... what?
    if ($this->user || $this->port) {
      return FALSE;
    }

    if ($this->path) {
      // Check path-only (no host) URI
      if (substr($this->path, 0, 2) == '//') {
        return FALSE;
      }
      return TRUE;
    }

    if (!($this->query || $this->fragment)) {
      // No host, path, query or fragment - this is not a valid URI
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Is the URI absolute?
   *
   * @return bool
   */
  public function isAbsolute() {
    return ($this->scheme !== NULL);
  }
}
