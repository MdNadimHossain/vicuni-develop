<?php
/**
 * @file
 * Global Configuration Override.
 *
 * You can use this file for overridding configuration values from modules, etc.
 * You would place values in here that are agnostic to the environment and not
 * sensitive to security.
 *
 * @NOTE: In practice, this file will typically be INCLUDED in your source
 * control, so do not include passwords or other sensitive information in this
 * file.
 */

if (isset($_ENV['AH_SITE_GROUP']) && isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  define('DRUPAL_ROOT', '/var/www/html/' . $_ENV['AH_SITE_GROUP'] . '.' . $_ENV['AH_SITE_ENVIRONMENT'] . '/docroot');
}
else {
  define('DRUPAL_ROOT', $_SERVER['DOCUMENT_ROOT']);
}

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_CONFIGURATION);

global $databases;

return array(
  'doctrine' => array(
    'connection' => array(
      'orm_default' => array(
        'driverClass' => 'Doctrine\DBAL\Driver\PDOMySql\Driver',
        'params' => array(
          'host' => $databases['default']['default']['host'],
          'port' => $databases['default']['default']['port'],
          'user' => $databases['default']['default']['username'],
          'password' => $databases['default']['default']['password'],
          'dbname' => $databases['default']['default']['database'],
        ),
      ),
    ),
  ),
);
