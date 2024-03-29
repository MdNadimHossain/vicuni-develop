<?php

/**
 * @file
 */

use Zend\Mvc\Application;

date_default_timezone_set('Australia/Melbourne');
/**
 * This makes our life easier when dealing with paths. Everything is relative
 * to the application root now.
 */
chdir(dirname(__DIR__));

// Setup autoloading.
include 'init_autoloader.php';

// Run the application!
Application::init(include 'config/application.config.php')->run()->send();
