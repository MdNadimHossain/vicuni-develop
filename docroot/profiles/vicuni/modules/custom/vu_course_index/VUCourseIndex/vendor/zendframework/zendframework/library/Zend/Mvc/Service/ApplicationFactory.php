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

namespace Zend\Mvc\Service;

use Zend\Mvc\Application;
use Zend\ServiceManager\FactoryInterface;
use Zend\ServiceManager\ServiceLocatorInterface;

class ApplicationFactory implements FactoryInterface {
  /**
   * Create the Application service
   *
   * Creates a Zend\Mvc\Application service, passing it the configuration
   * service and the service manager instance.
   *
   * @param  ServiceLocatorInterface $serviceLocator
   *
   * @return Application
   */
  public function createService(ServiceLocatorInterface $serviceLocator) {
    return new Application($serviceLocator->get('Config'), $serviceLocator);
  }
}
