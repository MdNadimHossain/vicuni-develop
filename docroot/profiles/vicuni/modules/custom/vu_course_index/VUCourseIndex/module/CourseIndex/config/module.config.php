<?php

/**
 * @file
 */

namespace CourseIndex;

return array(
  'controllers' => array(
    'factories' => array(
      'CourseIndex\Controller\CIService' => 'CourseIndex\Controller\Factory\CIServiceControllerFactory',
    ),
  ),
  'router' => array(
    'routes' => array(
      'album' => array(
        'type' => 'literal',
        'options' => array(
          'route' => '/ciservice',
          'defaults' => array(
            'controller' => 'CourseIndex\Controller\CIService',
            'action' => 'index',
          ),
        ),
      ),
    ),
  ),
  'view_manager' => array(
    'display_not_found_reason' => TRUE,
    'display_exceptions' => TRUE,
    'doctype' => 'HTML5',
    'not_found_template' => 'error/404',
    'exception_template' => 'error/index',
    'template_map' => array(
      'layout/layout' => __DIR__ . '/../view/layout/blank.phtml',
      // 'application/index/index' => __DIR__ . '/../view/application/index/index.phtml',.
      'error/404' => __DIR__ . '/../view/error/404.phtml',
      'error/index' => __DIR__ . '/../view/error/index.phtml',
    ),
    'template_path_stack' => array(
      'album' => __DIR__ . '/../view',
    ),
  ),
  'doctrine' => array(
    'driver' => array(
      __NAMESPACE__ . '_driver' => array(
        'class' => 'Doctrine\ORM\Mapping\Driver\AnnotationDriver',
        'cache' => 'array',
        'paths' => array(__DIR__ . '/../src/' . __NAMESPACE__ . '/Entity'),
      ),
      'orm_default' => array(
        'drivers' => array(
          __NAMESPACE__ . '\Entity' => __NAMESPACE__ . '_driver',
        ),
      ),
    ),
  ),
  'service_manager' => array(
    'factories' => array(
      'Soap\Server' => 'CourseIndex\Service\SoapServerFactory',
      'Soap\Wsdl' => 'CourseIndex\Service\SoapWsdlFactory',
    ),
  ),
  'ciservice' => array(
    'WSDLClass' => '\CourseIndex\Server\CourseIndexSoapServer',
    'cache_key' => 'course_index_wsdl_cache',
    'endpoint_path' => '/ciservice',
    'endpoint_scheme' => 'https',
    'classmap' => array('\CourseIndex\Entity\CourseIntake' => '\CourseIndex\Entity\CourseIntake'),
    'auth_file' => __DIR__ . '/../data/auth/.htpasswd',
    'uri' => 'urn:ciservice.ws.vu.edu.au',
  ),
);
