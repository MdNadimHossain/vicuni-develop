<?php

namespace CourseIndex\Controller;

use Zend\Mvc\Controller\AbstractActionController;
use Zend\Soap\AutoDiscover as SoapWsdlGenerator;
use Zend\Soap\Server as SoapServer;
use Zend\Soap\Server\DocumentLiteralWrapper;
use Doctrine\ORM\EntityManager;
use Zend\Authentication\Adapter\ValidatableAdapterInterface;
use Zend\View\Helper\ServerUrl;

/**
 *
 */
class CIServiceController extends AbstractActionController {
  protected $soap;
  protected $wsdlGenerator;
  protected $config;
  protected $em;

  /**
   *
   */
  public function __construct(SoapServer $soapServer, SoapWsdlGenerator $wsdlGenerator, EntityManager $em, ValidatableAdapterInterface $authAdapter, array $config) {
    // This should probably move to some other conf (like server_url in the local.php)
    $serverUrl = new ServerUrl();
    $host = $serverUrl->getHost();
    $endpoint = $config['ciservice']['endpoint_scheme'] . '://' . $host . $config['ciservice']['endpoint_path'];

    // Use the autodiscover to generate the WSDL.
    $wsdlGenerator
      ->setClass($config['ciservice']['WSDLClass'])
      // Same as server 'uri'.
      ->setUri($config['ciservice']['uri'])
      ->setServiceName('CIService');

    $wsdl = $wsdlGenerator->generate();
    $xml = $wsdl->toXML();
    $file = 'data://text/plain;base64,' . base64_encode($xml);

    // Use generated WSDL to configure SOAP server.
    $soapServer->setWSDL($file);
    $soapServer->registerFaultException('Doctrine\Common\Annotations\AnnotationException');
    $soapServer->setClassmap($config['ciservice']['classmap']);

    $soapServer->setObject(
      new DocumentLiteralWrapper(
      // Initialise class with entity manager.
        new $config['ciservice']['WSDLClass']($em, $authAdapter)
      )
    );

    $this->soap = $soapServer;
    $this->wsdlGenerator = $wsdlGenerator;
    $this->em = $em;
  }

  /**
   *
   */
  public function indexAction() {
    /** @var \Zend\Http\Response $response */
    $response = $this->response;
    $request = $this->getRequest();

    switch ($request->getMethod()) {
      case 'GET':
        $wsdl = $this->wsdlGenerator->generate();
        $response->getHeaders()
          ->addHeaderLine('Content-Type', 'text/xml; charset=UTF-8;');
        $response->setContent($wsdl->toXml());
        break;

      case 'POST':
        $this->soap->setReturnResponse(TRUE);
        try {
          $soapResponse = $this->soap->handle();

          if ($soapResponse instanceof \SoapFault || $soapResponse instanceof \Exception) {
            error_log('Exception caught in index controller (soap response):' . $soapResponse->getMessage());
            error_log($soapResponse->getTraceAsString());
            $soapResponse = "ERROR: " . $soapResponse->getMessage();
          }
        }
        catch (\Exception $e) {
          $soapResponse = "ERROR: " . $e->getMessage();
          error_log('Exception caught in index controller:' . $soapResponse->getMessage());
          error_log($e->getTraceAsString());
        }

        $response->getHeaders()
          ->addHeaderLine('Content-Type', 'application/xml');
        $response->setContent($soapResponse);
        break;

      default:
        $response->setStatusCode(405);
        $response->getHeaders()->addHeaderLine('Allow', 'GET,POST');
        break;
    }

    return $response;
  }

}
