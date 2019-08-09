<?php

namespace Doctrine\Tests\Common\Proxy;

use Doctrine\Tests\DoctrineTestCase;
use Doctrine\Common\Proxy\ProxyDefinition;

class AbstractProxyFactoryTest extends DoctrineTestCase {
  public function testGenerateProxyClasses() {
    $metadata = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadata');
    $proxyGenerator = $this->getMock('Doctrine\Common\Proxy\ProxyGenerator', array(), array(), '', FALSE);

    $proxyGenerator
      ->expects($this->once())
      ->method('getProxyFileName');
    $proxyGenerator
      ->expects($this->once())
      ->method('generateProxyClass');

    $metadataFactory = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadataFactory');
    $proxyFactory = $this->getMockForAbstractClass(
      'Doctrine\Common\Proxy\AbstractProxyFactory',
      array($proxyGenerator, $metadataFactory, TRUE)
    );

    $proxyFactory
      ->expects($this->any())
      ->method('skipClass')
      ->will($this->returnValue(FALSE));

    $generated = $proxyFactory->generateProxyClasses(array($metadata), sys_get_temp_dir());

    $this->assertEquals(1, $generated, 'One proxy was generated');
  }

  public function testGetProxy() {
    $metadata = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadata');
    $proxy = $this->getMock('Doctrine\Common\Proxy\Proxy');
    $definition = new ProxyDefinition(get_class($proxy), array(), array(), NULL, NULL);
    $proxyGenerator = $this->getMock('Doctrine\Common\Proxy\ProxyGenerator', array(), array(), '', FALSE);
    $metadataFactory = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadataFactory');

    $metadataFactory
      ->expects($this->once())
      ->method('getMetadataFor')
      ->will($this->returnValue($metadata));

    $proxyFactory = $this->getMockForAbstractClass(
      'Doctrine\Common\Proxy\AbstractProxyFactory',
      array($proxyGenerator, $metadataFactory, TRUE)
    );

    $proxyFactory
      ->expects($this->any())
      ->method('createProxyDefinition')
      ->will($this->returnValue($definition));

    $generatedProxy = $proxyFactory->getProxy('Class', array('id' => 1));

    $this->assertInstanceOf(get_class($proxy), $generatedProxy);
  }

  public function testResetUnitializedProxy() {
    $metadata = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadata');
    $proxy = $this->getMock('Doctrine\Common\Proxy\Proxy');
    $definition = new ProxyDefinition(get_class($proxy), array(), array(), NULL, NULL);
    $proxyGenerator = $this->getMock('Doctrine\Common\Proxy\ProxyGenerator', array(), array(), '', FALSE);
    $metadataFactory = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadataFactory');

    $metadataFactory
      ->expects($this->once())
      ->method('getMetadataFor')
      ->will($this->returnValue($metadata));

    $proxyFactory = $this->getMockForAbstractClass(
      'Doctrine\Common\Proxy\AbstractProxyFactory',
      array($proxyGenerator, $metadataFactory, TRUE)
    );

    $proxyFactory
      ->expects($this->any())
      ->method('createProxyDefinition')
      ->will($this->returnValue($definition));

    $proxy
      ->expects($this->once())
      ->method('__isInitialized')
      ->will($this->returnValue(FALSE));
    $proxy
      ->expects($this->once())
      ->method('__setInitializer');
    $proxy
      ->expects($this->once())
      ->method('__setCloner');

    $proxyFactory->resetUninitializedProxy($proxy);
  }

  public function testDisallowsResettingInitializedProxy() {
    $proxyFactory = $this->getMockForAbstractClass('Doctrine\Common\Proxy\AbstractProxyFactory', array(), '', FALSE);
    $proxy = $this->getMock('Doctrine\Common\Proxy\Proxy');

    $proxy
      ->expects($this->any())
      ->method('__isInitialized')
      ->will($this->returnValue(TRUE));

    $this->setExpectedException('Doctrine\Common\Proxy\Exception\InvalidArgumentException');

    $proxyFactory->resetUninitializedProxy($proxy);
  }

  public function testMissingPrimaryKeyValue() {
    $metadata = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadata');
    $proxy = $this->getMock('Doctrine\Common\Proxy\Proxy');
    $definition = new ProxyDefinition(get_class($proxy), array('missingKey'), array(), NULL, NULL);
    $proxyGenerator = $this->getMock('Doctrine\Common\Proxy\ProxyGenerator', array(), array(), '', FALSE);
    $metadataFactory = $this->getMock('Doctrine\Common\Persistence\Mapping\ClassMetadataFactory');

    $metadataFactory
      ->expects($this->once())
      ->method('getMetadataFor')
      ->will($this->returnValue($metadata));

    $proxyFactory = $this->getMockForAbstractClass(
      'Doctrine\Common\Proxy\AbstractProxyFactory',
      array($proxyGenerator, $metadataFactory, TRUE)
    );

    $proxyFactory
      ->expects($this->any())
      ->method('createProxyDefinition')
      ->will($this->returnValue($definition));

    $this->setExpectedException('\OutOfBoundsException');

    $generatedProxy = $proxyFactory->getProxy('Class', array());
  }
}

