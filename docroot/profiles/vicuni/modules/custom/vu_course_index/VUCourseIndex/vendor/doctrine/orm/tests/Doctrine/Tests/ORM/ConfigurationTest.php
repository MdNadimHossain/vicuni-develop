<?php

namespace Doctrine\Tests\ORM;

use Doctrine\Common\Proxy\AbstractProxyFactory;
use Doctrine\Common\Cache\ArrayCache;
use Doctrine\ORM\Mapping as AnnotationNamespace;
use Doctrine\ORM\Configuration;
use Doctrine\ORM\ORMException;
use ReflectionClass;
use PHPUnit_Framework_TestCase;

/**
 * Tests for the Configuration object
 *
 * @author Marco Pivetta <ocramius@gmail.com>
 */
class ConfigurationTest extends PHPUnit_Framework_TestCase {
  /**
   * @var Configuration
   */
  private $configuration;

  protected function setUp() {
    parent::setUp();
    $this->configuration = new Configuration();
  }

  public function testSetGetProxyDir() {
    $this->assertSame(NULL, $this->configuration->getProxyDir()); // defaults

    $this->configuration->setProxyDir(__DIR__);
    $this->assertSame(__DIR__, $this->configuration->getProxyDir());
  }

  public function testSetGetAutoGenerateProxyClasses() {
    $this->assertSame(AbstractProxyFactory::AUTOGENERATE_ALWAYS, $this->configuration->getAutoGenerateProxyClasses()); // defaults

    $this->configuration->setAutoGenerateProxyClasses(FALSE);
    $this->assertSame(AbstractProxyFactory::AUTOGENERATE_NEVER, $this->configuration->getAutoGenerateProxyClasses());

    $this->configuration->setAutoGenerateProxyClasses(TRUE);
    $this->assertSame(AbstractProxyFactory::AUTOGENERATE_ALWAYS, $this->configuration->getAutoGenerateProxyClasses());

    $this->configuration->setAutoGenerateProxyClasses(AbstractProxyFactory::AUTOGENERATE_FILE_NOT_EXISTS);
    $this->assertSame(AbstractProxyFactory::AUTOGENERATE_FILE_NOT_EXISTS, $this->configuration->getAutoGenerateProxyClasses());
  }

  public function testSetGetProxyNamespace() {
    $this->assertSame(NULL, $this->configuration->getProxyNamespace()); // defaults

    $this->configuration->setProxyNamespace(__NAMESPACE__);
    $this->assertSame(__NAMESPACE__, $this->configuration->getProxyNamespace());
  }

  public function testSetGetMetadataDriverImpl() {
    $this->assertSame(NULL, $this->configuration->getMetadataDriverImpl()); // defaults

    $metadataDriver = $this->getMock('Doctrine\Common\Persistence\Mapping\Driver\MappingDriver');
    $this->configuration->setMetadataDriverImpl($metadataDriver);
    $this->assertSame($metadataDriver, $this->configuration->getMetadataDriverImpl());
  }

  public function testNewDefaultAnnotationDriver() {
    $paths = array(__DIR__);
    $reflectionClass = new ReflectionClass(__NAMESPACE__ . '\ConfigurationTestAnnotationReaderChecker');

    $annotationDriver = $this->configuration->newDefaultAnnotationDriver($paths, FALSE);
    $reader = $annotationDriver->getReader();
    $annotation = $reader->getMethodAnnotation(
      $reflectionClass->getMethod('namespacedAnnotationMethod'),
      'Doctrine\ORM\Mapping\PrePersist'
    );
    $this->assertInstanceOf('Doctrine\ORM\Mapping\PrePersist', $annotation);

    $annotationDriver = $this->configuration->newDefaultAnnotationDriver($paths);
    $reader = $annotationDriver->getReader();
    $annotation = $reader->getMethodAnnotation(
      $reflectionClass->getMethod('simpleAnnotationMethod'),
      'Doctrine\ORM\Mapping\PrePersist'
    );
    $this->assertInstanceOf('Doctrine\ORM\Mapping\PrePersist', $annotation);
  }

  public function testSetGetEntityNamespace() {
    $this->configuration->addEntityNamespace('TestNamespace', __NAMESPACE__);
    $this->assertSame(__NAMESPACE__, $this->configuration->getEntityNamespace('TestNamespace'));
    $namespaces = array('OtherNamespace' => __NAMESPACE__);
    $this->configuration->setEntityNamespaces($namespaces);
    $this->assertSame($namespaces, $this->configuration->getEntityNamespaces());
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->getEntityNamespace('NonExistingNamespace');
  }

  public function testSetGetQueryCacheImpl() {
    $this->assertSame(NULL, $this->configuration->getQueryCacheImpl()); // defaults
    $queryCacheImpl = $this->getMock('Doctrine\Common\Cache\Cache');
    $this->configuration->setQueryCacheImpl($queryCacheImpl);
    $this->assertSame($queryCacheImpl, $this->configuration->getQueryCacheImpl());
  }

  public function testSetGetHydrationCacheImpl() {
    $this->assertSame(NULL, $this->configuration->getHydrationCacheImpl()); // defaults
    $queryCacheImpl = $this->getMock('Doctrine\Common\Cache\Cache');
    $this->configuration->setHydrationCacheImpl($queryCacheImpl);
    $this->assertSame($queryCacheImpl, $this->configuration->getHydrationCacheImpl());
  }

  public function testSetGetMetadataCacheImpl() {
    $this->assertSame(NULL, $this->configuration->getMetadataCacheImpl()); // defaults
    $queryCacheImpl = $this->getMock('Doctrine\Common\Cache\Cache');
    $this->configuration->setMetadataCacheImpl($queryCacheImpl);
    $this->assertSame($queryCacheImpl, $this->configuration->getMetadataCacheImpl());
  }

  public function testAddGetNamedQuery() {
    $dql = 'SELECT u FROM User u';
    $this->configuration->addNamedQuery('QueryName', $dql);
    $this->assertSame($dql, $this->configuration->getNamedQuery('QueryName'));
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->getNamedQuery('NonExistingQuery');
  }

  public function testAddGetNamedNativeQuery() {
    $sql = 'SELECT * FROM user';
    $rsm = $this->getMock('Doctrine\ORM\Query\ResultSetMapping');
    $this->configuration->addNamedNativeQuery('QueryName', $sql, $rsm);
    $fetched = $this->configuration->getNamedNativeQuery('QueryName');
    $this->assertSame($sql, $fetched[0]);
    $this->assertSame($rsm, $fetched[1]);
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->getNamedQuery('NonExistingQuery');
  }

  /**
   * Configures $this->configuration to use production settings.
   *
   * @param string $skipCache Do not configure a cache of this type, either
   *   "query" or "metadata".
   */
  protected function setProductionSettings($skipCache = FALSE) {
    $this->configuration->setAutoGenerateProxyClasses(AbstractProxyFactory::AUTOGENERATE_NEVER);

    $cache = $this->getMock('Doctrine\Common\Cache\Cache');

    if ('query' !== $skipCache) {
      $this->configuration->setQueryCacheImpl($cache);
    }

    if ('metadata' !== $skipCache) {
      $this->configuration->setMetadataCacheImpl($cache);
    }
  }

  public function testEnsureProductionSettings() {
    $this->setProductionSettings();
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsQueryCache() {
    $this->setProductionSettings('query');
    $this->setExpectedException('Doctrine\ORM\ORMException', 'Query Cache is not configured.');
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsMetadataCache() {
    $this->setProductionSettings('metadata');
    $this->setExpectedException('Doctrine\ORM\ORMException', 'Metadata Cache is not configured.');
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsQueryArrayCache() {
    $this->setProductionSettings();
    $this->configuration->setQueryCacheImpl(new ArrayCache());
    $this->setExpectedException(
      'Doctrine\ORM\ORMException',
      'Query Cache uses a non-persistent cache driver, Doctrine\Common\Cache\ArrayCache.');
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsMetadataArrayCache() {
    $this->setProductionSettings();
    $this->configuration->setMetadataCacheImpl(new ArrayCache());
    $this->setExpectedException(
      'Doctrine\ORM\ORMException',
      'Metadata Cache uses a non-persistent cache driver, Doctrine\Common\Cache\ArrayCache.');
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsAutoGenerateProxyClassesAlways() {
    $this->setProductionSettings();
    $this->configuration->setAutoGenerateProxyClasses(AbstractProxyFactory::AUTOGENERATE_ALWAYS);
    $this->setExpectedException('Doctrine\ORM\ORMException', 'Proxy Classes are always regenerating.');
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsAutoGenerateProxyClassesFileNotExists() {
    $this->setProductionSettings();
    $this->configuration->setAutoGenerateProxyClasses(AbstractProxyFactory::AUTOGENERATE_FILE_NOT_EXISTS);
    $this->setExpectedException('Doctrine\ORM\ORMException', 'Proxy Classes are always regenerating.');
    $this->configuration->ensureProductionSettings();
  }

  public function testEnsureProductionSettingsAutoGenerateProxyClassesEval() {
    $this->setProductionSettings();
    $this->configuration->setAutoGenerateProxyClasses(AbstractProxyFactory::AUTOGENERATE_EVAL);
    $this->setExpectedException('Doctrine\ORM\ORMException', 'Proxy Classes are always regenerating.');
    $this->configuration->ensureProductionSettings();
  }

  public function testAddGetCustomStringFunction() {
    $this->configuration->addCustomStringFunction('FunctionName', __CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getCustomStringFunction('FunctionName'));
    $this->assertSame(NULL, $this->configuration->getCustomStringFunction('NonExistingFunction'));
    $this->configuration->setCustomStringFunctions(array('OtherFunctionName' => __CLASS__));
    $this->assertSame(__CLASS__, $this->configuration->getCustomStringFunction('OtherFunctionName'));
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->addCustomStringFunction('concat', __CLASS__);
  }

  public function testAddGetCustomNumericFunction() {
    $this->configuration->addCustomNumericFunction('FunctionName', __CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getCustomNumericFunction('FunctionName'));
    $this->assertSame(NULL, $this->configuration->getCustomNumericFunction('NonExistingFunction'));
    $this->configuration->setCustomNumericFunctions(array('OtherFunctionName' => __CLASS__));
    $this->assertSame(__CLASS__, $this->configuration->getCustomNumericFunction('OtherFunctionName'));
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->addCustomNumericFunction('abs', __CLASS__);
  }

  public function testAddGetCustomDatetimeFunction() {
    $this->configuration->addCustomDatetimeFunction('FunctionName', __CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getCustomDatetimeFunction('FunctionName'));
    $this->assertSame(NULL, $this->configuration->getCustomDatetimeFunction('NonExistingFunction'));
    $this->configuration->setCustomDatetimeFunctions(array('OtherFunctionName' => __CLASS__));
    $this->assertSame(__CLASS__, $this->configuration->getCustomDatetimeFunction('OtherFunctionName'));
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->addCustomDatetimeFunction('date_add', __CLASS__);
  }

  public function testAddGetCustomHydrationMode() {
    $this->assertSame(NULL, $this->configuration->getCustomHydrationMode('NonExisting'));
    $this->configuration->addCustomHydrationMode('HydrationModeName', __CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getCustomHydrationMode('HydrationModeName'));
  }

  public function testSetCustomHydrationModes() {
    $this->configuration->addCustomHydrationMode('HydrationModeName', __CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getCustomHydrationMode('HydrationModeName'));

    $this->configuration->setCustomHydrationModes(
      array(
        'AnotherHydrationModeName' => __CLASS__
      )
    );

    $this->assertNull($this->configuration->getCustomHydrationMode('HydrationModeName'));
    $this->assertSame(__CLASS__, $this->configuration->getCustomHydrationMode('AnotherHydrationModeName'));
  }

  public function testSetGetClassMetadataFactoryName() {
    $this->assertSame('Doctrine\ORM\Mapping\ClassMetadataFactory', $this->configuration->getClassMetadataFactoryName());
    $this->configuration->setClassMetadataFactoryName(__CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getClassMetadataFactoryName());
  }

  public function testAddGetFilters() {
    $this->assertSame(NULL, $this->configuration->getFilterClassName('NonExistingFilter'));
    $this->configuration->addFilter('FilterName', __CLASS__);
    $this->assertSame(__CLASS__, $this->configuration->getFilterClassName('FilterName'));
  }

  public function setDefaultRepositoryClassName() {
    $this->assertSame('Doctrine\ORM\EntityRepository', $this->configuration->getDefaultRepositoryClassName());
    $repositoryClass = 'Doctrine\Tests\Models\DDC753\DDC753CustomRepository';
    $this->configuration->setDefaultRepositoryClassName($repositoryClass);
    $this->assertSame($repositoryClass, $this->configuration->getDefaultRepositoryClassName());
    $this->setExpectedException('Doctrine\ORM\ORMException');
    $this->configuration->setDefaultRepositoryClassName(__CLASS__);
  }

  public function testSetGetNamingStrategy() {
    $this->assertInstanceOf('Doctrine\ORM\Mapping\NamingStrategy', $this->configuration->getNamingStrategy());
    $namingStrategy = $this->getMock('Doctrine\ORM\Mapping\NamingStrategy');
    $this->configuration->setNamingStrategy($namingStrategy);
    $this->assertSame($namingStrategy, $this->configuration->getNamingStrategy());
  }

  public function testSetGetQuoteStrategy() {
    $this->assertInstanceOf('Doctrine\ORM\Mapping\QuoteStrategy', $this->configuration->getQuoteStrategy());
    $quoteStrategy = $this->getMock('Doctrine\ORM\Mapping\QuoteStrategy');
    $this->configuration->setQuoteStrategy($quoteStrategy);
    $this->assertSame($quoteStrategy, $this->configuration->getQuoteStrategy());
  }

  /**
   * @group DDC-1955
   */
  public function testSetGetEntityListenerResolver() {
    $this->assertInstanceOf('Doctrine\ORM\Mapping\EntityListenerResolver', $this->configuration->getEntityListenerResolver());
    $this->assertInstanceOf('Doctrine\ORM\Mapping\DefaultEntityListenerResolver', $this->configuration->getEntityListenerResolver());
    $resolver = $this->getMock('Doctrine\ORM\Mapping\EntityListenerResolver');
    $this->configuration->setEntityListenerResolver($resolver);
    $this->assertSame($resolver, $this->configuration->getEntityListenerResolver());
  }

  /**
   * @group DDC-2183
   */
  public function testSetGetSecondLevelCacheConfig() {
    $mockClass = $this->getMock('Doctrine\ORM\Cache\CacheConfiguration');

    $this->assertNull($this->configuration->getSecondLevelCacheConfiguration());
    $this->configuration->setSecondLevelCacheConfiguration($mockClass);
    $this->assertEquals($mockClass, $this->configuration->getSecondLevelCacheConfiguration());
  }
}

class ConfigurationTestAnnotationReaderChecker {
  /** @PrePersist */
  public function simpleAnnotationMethod() {
  }

  /** @AnnotationNamespace\PrePersist */
  public function namespacedAnnotationMethod() {
  }
}
