<?php
namespace CourseIndex\Service;

use Zend\ServiceManager\FactoryInterface;
use Zend\ServiceManager\ServiceLocatorInterface;
use Zend\Soap\Server;

/**
 *
 */
class SoapServerFactory implements FactoryInterface {

  /**
   *
   */
  public function createService(ServiceLocatorInterface $serviceLocator) {
    $server = new Server(NULL, array(
      'soap_version' => SOAP_1_2,
      'encoding' => 'UTF-8',
    ));

    $server->registerFaultException(
      array(
        '\Zend\Soap\Exception\InvalidArgumentException',
        '\Zend\Authentication\Adapter\Exception\InvalidArgumentException',
        '\Zend\Authentication\Adapter\Exception\RuntimeException',
        '\Zend\Authentication\Adapter\Exception\UnexpectedValueException',
      ));

    return $server;
  }

}
