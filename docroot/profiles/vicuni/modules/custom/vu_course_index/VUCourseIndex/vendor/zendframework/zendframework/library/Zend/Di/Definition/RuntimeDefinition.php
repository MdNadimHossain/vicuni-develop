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

namespace Zend\Di\Definition;

use Zend\Code\Annotation\AnnotationCollection;
use Zend\Code\Reflection;
use Zend\Di\Di;

/**
 * Class definitions based on runtime reflection
 */
class RuntimeDefinition implements DefinitionInterface {

  /**
   * @var array
   */
  protected $classes = array();

  /**
   * @var bool
   */
  protected $explicitLookups = FALSE;

  /**
   * @var IntrospectionStrategy
   */
  protected $introspectionStrategy = NULL;

  /**
   * @var array
   */
  protected $injectionMethods = array();

  /**
   * Constructor
   *
   * @param null|IntrospectionStrategy $introspectionStrategy
   * @param array|null $explicitClasses
   */
  public function __construct(IntrospectionStrategy $introspectionStrategy = NULL, array $explicitClasses = NULL) {
    $this->introspectionStrategy = ($introspectionStrategy) ?: new IntrospectionStrategy();
    if ($explicitClasses) {
      $this->setExplicitClasses($explicitClasses);
    }
  }

  /**
   * @param  IntrospectionStrategy $introspectionStrategy
   *
   * @return void
   */
  public function setIntrospectionStrategy(IntrospectionStrategy $introspectionStrategy) {
    $this->introspectionStrategy = $introspectionStrategy;
  }

  /**
   * @return IntrospectionStrategy
   */
  public function getIntrospectionStrategy() {
    return $this->introspectionStrategy;
  }

  /**
   * Set explicit classes
   *
   * @param array $explicitClasses
   */
  public function setExplicitClasses(array $explicitClasses) {
    $this->explicitLookups = TRUE;
    foreach ($explicitClasses as $eClass) {
      $this->classes[$eClass] = TRUE;
    }
    $this->classes = $explicitClasses;
  }

  /**
   * @param string $class
   */
  public function forceLoadClass($class) {
    $this->processClass($class, TRUE);
  }

  /**
   * {@inheritDoc}
   */
  public function getClasses() {
    return array_keys($this->classes);
  }

  /**
   * {@inheritDoc}
   */
  public function hasClass($class) {
    if ($this->explicitLookups === TRUE) {
      return (array_key_exists($class, $this->classes));
    }

    return class_exists($class) || interface_exists($class);
  }

  /**
   * {@inheritDoc}
   */
  public function getClassSupertypes($class) {
    $this->processClass($class);
    return $this->classes[$class]['supertypes'];
  }

  /**
   * {@inheritDoc}
   */
  public function getInstantiator($class) {
    $this->processClass($class);
    return $this->classes[$class]['instantiator'];
  }

  /**
   * {@inheritDoc}
   */
  public function hasMethods($class) {
    $this->processClass($class);
    return (count($this->classes[$class]['methods']) > 0);
  }

  /**
   * {@inheritDoc}
   */
  public function hasMethod($class, $method) {
    $this->processClass($class);
    return isset($this->classes[$class]['methods'][$method]);
  }

  /**
   * {@inheritDoc}
   */
  public function getMethods($class) {
    $this->processClass($class);
    return $this->classes[$class]['methods'];
  }

  /**
   * {@inheritDoc}
   */
  public function hasMethodParameters($class, $method) {
    $this->processClass($class);
    return (array_key_exists($method, $this->classes[$class]['parameters']));
  }

  /**
   * {@inheritDoc}
   */
  public function getMethodParameters($class, $method) {
    $this->processClass($class);
    return $this->classes[$class]['parameters'][$method];
  }

  /**
   * @param string $class
   */
  protected function hasProcessedClass($class) {
    return array_key_exists($class, $this->classes) && is_array($this->classes[$class]);
  }

  /**
   * @param string $class
   * @param bool $forceLoad
   */
  protected function processClass($class, $forceLoad = FALSE) {
    if (!$forceLoad && $this->hasProcessedClass($class)) {
      return;
    }
    $strategy = $this->introspectionStrategy; // localize for readability

    /** @var $rClass \Zend\Code\Reflection\ClassReflection */
    $rClass = new Reflection\ClassReflection($class);
    $className = $rClass->getName();
    $matches = NULL; // used for regex below

    // setup the key in classes
    $this->classes[$className] = array(
      'supertypes' => array(),
      'instantiator' => NULL,
      'methods' => array(),
      'parameters' => array()
    );

    $def = &$this->classes[$className]; // localize for brevity

    // class annotations?
    if ($strategy->getUseAnnotations() == TRUE) {
      $annotations = $rClass->getAnnotations($strategy->getAnnotationManager());

      if (($annotations instanceof AnnotationCollection)
        && $annotations->hasAnnotation('Zend\Di\Definition\Annotation\Instantiator')
      ) {
        // @todo Instantiator support in annotations
      }
    }

    $rTarget = $rClass;
    $supertypes = array();
    do {
      $supertypes = array_merge($supertypes, $rTarget->getInterfaceNames());
      if (!($rTargetParent = $rTarget->getParentClass())) {
        break;
      }
      $supertypes[] = $rTargetParent->getName();
      $rTarget = $rTargetParent;
    } while (TRUE);

    $def['supertypes'] = $supertypes;

    if ($def['instantiator'] == NULL) {
      if ($rClass->isInstantiable()) {
        $def['instantiator'] = '__construct';
      }
    }

    if ($rClass->hasMethod('__construct')) {
      $def['methods']['__construct'] = Di::METHOD_IS_CONSTRUCTOR; // required
      $this->processParams($def, $rClass, $rClass->getMethod('__construct'));
    }

    foreach ($rClass->getMethods(Reflection\MethodReflection::IS_PUBLIC) as $rMethod) {

      $methodName = $rMethod->getName();

      if ($rMethod->getName() === '__construct' || $rMethod->isStatic()) {
        continue;
      }

      if ($strategy->getUseAnnotations() == TRUE) {
        $annotations = $rMethod->getAnnotations($strategy->getAnnotationManager());

        if (($annotations instanceof AnnotationCollection)
          && $annotations->hasAnnotation('Zend\Di\Definition\Annotation\Inject')
        ) {

          // use '@inject' and search for parameters
          $def['methods'][$methodName] = Di::METHOD_IS_EAGER;
          $this->processParams($def, $rClass, $rMethod);
          continue;
        }
      }

      $methodPatterns = $this->introspectionStrategy->getMethodNameInclusionPatterns();

      // matches a method injection pattern?
      foreach ($methodPatterns as $methodInjectorPattern) {
        preg_match($methodInjectorPattern, $methodName, $matches);
        if ($matches) {
          $def['methods'][$methodName] = Di::METHOD_IS_OPTIONAL; // check ot see if this is required?
          $this->processParams($def, $rClass, $rMethod);
          continue 2;
        }
      }

      // method
      // by annotation
      // by setter pattern,
      // by interface

    }

    $interfaceInjectorPatterns = $this->introspectionStrategy->getInterfaceInjectionInclusionPatterns();

    // matches the interface injection pattern
    /** @var $rIface \ReflectionClass */
    foreach ($rClass->getInterfaces() as $rIface) {
      foreach ($interfaceInjectorPatterns as $interfaceInjectorPattern) {
        preg_match($interfaceInjectorPattern, $rIface->getName(), $matches);
        if ($matches) {
          foreach ($rIface->getMethods() as $rMethod) {
            if (($rMethod->getName() === '__construct') || !count($rMethod->getParameters())) {
              // constructor not allowed in interfaces
              // Don't call interface methods without a parameter (Some aware interfaces define setters in ZF2)
              continue;
            }
            $def['methods'][$rMethod->getName()] = Di::METHOD_IS_AWARE;
            $this->processParams($def, $rClass, $rMethod);
          }
          continue 2;
        }
      }
    }
  }

  /**
   * @param array $def
   * @param \Zend\Code\Reflection\ClassReflection $rClass
   * @param \Zend\Code\Reflection\MethodReflection $rMethod
   */
  protected function processParams(&$def, Reflection\ClassReflection $rClass, Reflection\MethodReflection $rMethod) {
    if (count($rMethod->getParameters()) === 0) {
      return;
    }

    $methodName = $rMethod->getName();

    // @todo annotations here for alternate names?

    $def['parameters'][$methodName] = array();

    foreach ($rMethod->getParameters() as $p) {

      /** @var $p \ReflectionParameter */
      $actualParamName = $p->getName();

      $fqName = $rClass->getName() . '::' . $rMethod->getName() . ':' . $p->getPosition();

      $def['parameters'][$methodName][$fqName] = array();

      // set the class name, if it exists
      $def['parameters'][$methodName][$fqName][] = $actualParamName;
      $def['parameters'][$methodName][$fqName][] = ($p->getClass() !== NULL) ? $p->getClass()
        ->getName() : NULL;
      $def['parameters'][$methodName][$fqName][] = !($optional = $p->isOptional() && $p->isDefaultValueAvailable());
      $def['parameters'][$methodName][$fqName][] = $optional ? $p->getDefaultValue() : NULL;
    }
  }
}
