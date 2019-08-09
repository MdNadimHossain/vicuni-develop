<?php
namespace CourseIndex\Service;

use Zend\ServiceManager\FactoryInterface;
use Zend\ServiceManager\ServiceLocatorInterface;
use Zend\Soap\Wsdl\ComplexTypeStrategy\ArrayOfTypeSequence;
use Zend\Soap\AutoDiscover as SoapWsdlGenerator;

/**
 *
 */
class SoapWsdlFactory implements FactoryInterface {

  /**
   *
   */
  public function createService(ServiceLocatorInterface $serviceLocator) {
    $autodiscover = new SoapWsdlGenerator(new ArrayOfTypeSequence());
    $autodiscover
      ->setBindingStyle(array('style' => 'document'))
      ->setOperationBodyStyle(array('use' => 'literal'));

    return $autodiscover;
  }

}
