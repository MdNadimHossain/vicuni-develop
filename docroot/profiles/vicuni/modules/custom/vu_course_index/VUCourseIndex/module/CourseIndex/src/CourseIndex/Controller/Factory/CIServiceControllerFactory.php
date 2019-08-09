<?php
namespace CourseIndex\Controller\Factory;

use CourseIndex\Controller\CIServiceController;
use Zend\ServiceManager\ServiceLocatorInterface;
use Zend\ServiceManager\FactoryInterface;
use Zend\Authentication\Adapter\Digest as DigestAuthAdapter;

/**
 *
 */
class CIServiceControllerFactory implements FactoryInterface {

  /**
   *
   */
  public function createService(ServiceLocatorInterface $serviceLocator) {
    $sm = $serviceLocator->getServiceLocator();

    $soapServer = $sm->get('Soap\Server');
    $autodiscover = $sm->get('Soap\Wsdl');
    $conf = $sm->get('Config');
    $em = $sm->get('doctrine.entitymanager.orm_default');

    // Prepare authentication service to send to server.
    $authAdapter = new DigestAuthAdapter($conf['ciservice']['auth_file'], 'ciservice');

    $controller = new CIServiceController($soapServer, $autodiscover, $em, $authAdapter, $conf);

    return $controller;
  }

}
