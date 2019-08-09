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

namespace Zend\View\Helper;

/**
 * Helper for returning the current server URL (optionally with request URI)
 */
class ServerUrl extends AbstractHelper {
  /**
   * Host (including port)
   *
   * @var string
   */
  protected $host;

  /**
   * Port
   *
   * @var int
   */
  protected $port;

  /**
   * Scheme
   *
   * @var string
   */
  protected $scheme;

  /**
   * Whether or not to query proxy servers for address
   *
   * @var bool
   */
  protected $useProxy = FALSE;

  /**
   * View helper entry point:
   * Returns the current host's URL like http://site.com
   *
   * @param  string|bool $requestUri [optional] if true, the request URI
   *                                     found in $_SERVER will be appended
   *                                     as a path. If a string is given, it
   *                                     will be appended as a path. Default
   *                                     is to not append any path.
   *
   * @return string
   */
  public function __invoke($requestUri = NULL) {
    if ($requestUri === TRUE) {
      $path = $_SERVER['REQUEST_URI'];
    }
    elseif (is_string($requestUri)) {
      $path = $requestUri;
    }
    else {
      $path = '';
    }

    return $this->getScheme() . '://' . $this->getHost() . $path;
  }

  /**
   * Detect the host based on headers
   *
   * @return void
   */
  protected function detectHost() {
    if ($this->setHostFromProxy()) {
      return;
    }

    if (isset($_SERVER['HTTP_HOST']) && !empty($_SERVER['HTTP_HOST'])) {
      // Detect if the port is set in SERVER_PORT and included in HTTP_HOST
      if (isset($_SERVER['SERVER_PORT'])) {
        $portStr = ':' . $_SERVER['SERVER_PORT'];
        if (substr($_SERVER['HTTP_HOST'], 0 - strlen($portStr), strlen($portStr)) == $portStr) {
          $this->setHost(substr($_SERVER['HTTP_HOST'], 0, 0 - strlen($portStr)));
          return;
        }
      }

      $this->setHost($_SERVER['HTTP_HOST']);

      return;
    }

    if (!isset($_SERVER['SERVER_NAME']) || !isset($_SERVER['SERVER_PORT'])) {
      return;
    }

    $name = $_SERVER['SERVER_NAME'];
    $this->setHost($name);
  }

  /**
   * Detect the port
   *
   * @return null
   */
  protected function detectPort() {
    if ($this->setPortFromProxy()) {
      return;
    }

    if (isset($_SERVER['SERVER_PORT']) && $_SERVER['SERVER_PORT']) {
      $this->setPort($_SERVER['SERVER_PORT']);
      return;
    }
  }

  /**
   * Detect the scheme
   *
   * @return null
   */
  protected function detectScheme() {
    if ($this->setSchemeFromProxy()) {
      return;
    }

    switch (TRUE) {
      case (isset($_SERVER['HTTPS']) && ($_SERVER['HTTPS'] == 'on' || $_SERVER['HTTPS'] === TRUE)):
      case (isset($_SERVER['HTTP_SCHEME']) && ($_SERVER['HTTP_SCHEME'] == 'https')):
      case (443 === $this->getPort()):
        $scheme = 'https';
        break;
      default:
        $scheme = 'http';
        break;
    }

    $this->setScheme($scheme);
  }

  /**
   * Detect if a proxy is in use, and, if so, set the host based on it
   *
   * @return bool
   */
  protected function setHostFromProxy() {
    if (!$this->useProxy) {
      return FALSE;
    }

    if (!isset($_SERVER['HTTP_X_FORWARDED_HOST']) || empty($_SERVER['HTTP_X_FORWARDED_HOST'])) {
      return FALSE;
    }

    $host = $_SERVER['HTTP_X_FORWARDED_HOST'];
    if (strpos($host, ',') !== FALSE) {
      $hosts = explode(',', $host);
      $host = trim(array_pop($hosts));
    }
    if (empty($host)) {
      return FALSE;
    }
    $this->setHost($host);

    return TRUE;
  }

  /**
   * Set port based on detected proxy headers
   *
   * @return bool
   */
  protected function setPortFromProxy() {
    if (!$this->useProxy) {
      return FALSE;
    }

    if (!isset($_SERVER['HTTP_X_FORWARDED_PORT']) || empty($_SERVER['HTTP_X_FORWARDED_PORT'])) {
      return FALSE;
    }

    $port = $_SERVER['HTTP_X_FORWARDED_PORT'];
    $this->setPort($port);

    return TRUE;
  }

  /**
   * Set the current scheme based on detected proxy headers
   *
   * @return bool
   */
  protected function setSchemeFromProxy() {
    if (!$this->useProxy) {
      return FALSE;
    }

    if (isset($_SERVER['SSL_HTTPS'])) {
      $sslHttps = strtolower($_SERVER['SSL_HTTPS']);
      if (in_array($sslHttps, array('on', 1))) {
        $this->setScheme('https');
        return TRUE;
      }
    }

    if (!isset($_SERVER['HTTP_X_FORWARDED_PROTO']) || empty($_SERVER['HTTP_X_FORWARDED_PROTO'])) {
      return FALSE;
    }

    $scheme = trim(strtolower($_SERVER['HTTP_X_FORWARDED_PROTO']));
    if (empty($scheme)) {
      return FALSE;
    }

    $this->setScheme($scheme);

    return TRUE;
  }

  /**
   * Sets host
   *
   * @param  string $host
   *
   * @return ServerUrl
   */
  public function setHost($host) {
    $port = $this->getPort();
    $scheme = $this->getScheme();

    if (($scheme == 'http' && (NULL === $port || $port == 80))
      || ($scheme == 'https' && (NULL === $port || $port == 443))
    ) {
      $this->host = $host;
      return $this;
    }

    $this->host = $host . ':' . $port;

    return $this;
  }

  /**
   * Returns host
   *
   * @return string
   */
  public function getHost() {
    if (NULL === $this->host) {
      $this->detectHost();
    }

    return $this->host;
  }

  /**
   * Set server port
   *
   * @param  int $port
   *
   * @return ServerUrl
   */
  public function setPort($port) {
    $this->port = (int) $port;

    return $this;
  }

  /**
   * Retrieve the server port
   *
   * @return int|null
   */
  public function getPort() {
    if (NULL === $this->port) {
      $this->detectPort();
    }

    return $this->port;
  }

  /**
   * Sets scheme (typically http or https)
   *
   * @param  string $scheme
   *
   * @return ServerUrl
   */
  public function setScheme($scheme) {
    $this->scheme = $scheme;

    return $this;
  }

  /**
   * Returns scheme (typically http or https)
   *
   * @return string
   */
  public function getScheme() {
    if (NULL === $this->scheme) {
      $this->detectScheme();
    }

    return $this->scheme;
  }

  /**
   * Set flag indicating whether or not to query proxy servers
   *
   * @param  bool $useProxy
   *
   * @return ServerUrl
   */
  public function setUseProxy($useProxy = FALSE) {
    $this->useProxy = (bool) $useProxy;

    return $this;
  }
}
