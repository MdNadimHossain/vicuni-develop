<?php

namespace VicUni\Driver;

use Drupal\Driver\Exception\BootstrapException;
use Drupal\Driver\Exception\UnsupportedDriverActionException;
use VicUni\Driver\Cores\Drupal7;

/**
 * Class DrupalDriver.
 *
 * @package VicUni\Driver
 */
// @codingStandardsIgnoreLine
class DrupalDriver extends \Drupal\Driver\DrupalDriver {

  /**
   * If drupal has been bootstrapped.
   *
   * @var bool
   */
  protected $bootstrapped = FALSE;

  /**
   * Drupal root directory.
   *
   * @var bool|string
   */
  protected $drupalRoot = FALSE;

  /**
   * Drupal uri.
   *
   * @var string
   */
  protected $uri;

  /**
   * {@inheritdoc}
   */
  public function __construct($drupal_root, $uri) {
    $this->drupalRoot = realpath($drupal_root);

    if (!$this->drupalRoot) {
      throw new BootstrapException(sprintf('No Drupal installation found at %s', $drupal_root));
    }
    $this->uri = $uri;
    $this->version = $this->getDrupalVersion();
  }

  /**
   * {@inheritdoc}
   */
  public function setCoreFromVersion() {
    $core = '\VicUni\Driver\Cores\Drupal' . $this->getDrupalVersion();
    $this->core = new $core($this->drupalRoot, $this->uri);
  }

  /**
   * {@inheritdoc}
   */
  public function bootstrap() {
    $this->getCore()->bootstrap();
    $this->bootstrapped = TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function isBootstrapped() {
    // Assume the blackbox is always bootstrapped.
    return $this->bootstrapped;
  }

  /**
   * {@inheritdoc}
   */
  public function getDrupalVersion() {
    if (!isset($this->version)) {
      // Support 6, 7 and 8.
      $version_constant_paths = [
        // Drupal 6.
        '/modules/system/system.module',
        // Drupal 7.
        '/includes/bootstrap.inc',
        // Drupal 8.
        '/autoload.php',
        '/core/includes/bootstrap.inc',
      ];

      if ($this->drupalRoot === FALSE) {
        throw new BootstrapException('`drupal_root` parameter must be defined.');
      }

      // So, some modules *ahem*context*ahem* don't check before using this.
      $_SERVER['QUERY_STRING'] = isset($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';

      foreach ($version_constant_paths as $path) {
        if (file_exists($this->drupalRoot . $path)) {
          require_once $this->drupalRoot . $path;
        }
      }
      if (defined('VERSION')) {
        $version = VERSION;
      }
      elseif (defined('\Drupal::VERSION')) {
        $version = \Drupal::VERSION;
      }
      else {
        throw new BootstrapException('Unable to determine Drupal core version. Supported versions are 6, 7, and 8.');
      }

      // Extract the major version from VERSION.
      $version_parts = explode('.', $version);
      if (is_numeric($version_parts[0])) {
        $this->version = (integer) $version_parts[0];
      }
      else {
        throw new BootstrapException(sprintf('Unable to extract major Drupal core version from version string %s.', $version));
      }
    }

    return $this->version;
  }

  /**
   * Create a drupal session for the user.
   *
   * @param \stdClass $user
   *   The user to login.
   *
   * @return array
   *   The created session.
   *
   * @throws \Drupal\Driver\Exception\UnsupportedDriverActionException
   */
  public function userLogin(\stdClass $user) {
    if ($this->getCore() instanceof Drupal7) {
      return $this->getCore()->userLogin($user);
    }
    else {
      throw new UnsupportedDriverActionException('Calling userLogin is only supported in the VicUni Drupal 7 driver core.', $this);
    }
  }

  /**
   * Remove a drupal session for the user.
   *
   * @param \stdClass $user
   *   The user to logout.
   * @param string $session_id
   *   The session id.
   *
   * @throws \Drupal\Driver\Exception\UnsupportedDriverActionException
   *
   * @internal param \stdClass $sessionUser The user to logout.*   The user to logout.
   */
  public function userLogout(\stdClass $user, $session_id) {
    if ($this->getCore() instanceof Drupal7) {
      $this->getCore()->userLogout($user, $session_id);
    }
    else {
      throw new UnsupportedDriverActionException('Calling userLogin is only supported in the VicUni Drupal 7 driver core.', $this);
    }
  }

  /**
   * Get the path to the drupal install.
   *
   * @return string
   *   The drupal root path.
   */
  public function getDrupalRoot() {
    return $this->drupalRoot;
  }

}
