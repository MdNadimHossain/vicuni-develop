<?php
/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the MIT license. For more information, see
 * <http://www.doctrine-project.org>.
 */

namespace DoctrineModuleTest\ServiceFactory;

use DoctrineModuleTest\ServiceManagerTestCase;
use PHPUnit_Framework_TestCase;

/**
 * Test that verifies that services are defined correctly
 *
 * @license MIT
 * @link    http://www.doctrine-project.org/
 * @author  Marco Pivetta <ocramius@gmail.com>
 */
class ModuleDefinedServicesTest extends PHPUnit_Framework_TestCase {
  /**
   * @var \Zend\ServiceManager\ServiceLocatorInterface
   */
  protected $serviceManager;

  /**
   * {@inheritDoc}
   */
  public function setUp() {
    $serviceManagerUtil = new ServiceManagerTestCase();
    $this->serviceManager = $serviceManagerUtil->getServiceManager();
  }

  /**
   * Verifies that the module defines the correct services
   *
   * @dataProvider getServicesThatShouldBeDefined
   */
  public function testModuleDefinedServices($serviceName, $defined) {
    $this->assertSame($defined, $this->serviceManager->has($serviceName));
  }

  /**
   * Verifies that the module defines the correct services
   *
   * @dataProvider getServicesThatCanBeFetched
   */
  public function testModuleFetchedService($serviceName, $expectedClass) {
    $this->assertInstanceOf($expectedClass, $this->serviceManager->get($serviceName));
  }

  /**
   * Verifies that the module defines the correct services
   *
   * @dataProvider getServicesThatCannotBeFetched
   */
  public function testModuleInvalidService($serviceName) {
    $this->setExpectedException('Zend\ServiceManager\Exception\ServiceNotFoundException');

    $this->serviceManager->get($serviceName);
  }

  /**
   * @return array
   */
  public function getServicesThatShouldBeDefined() {
    return array(
      array('doctrine.cache.array', TRUE),
      array('doctrine.cache.apc', TRUE),
      array('doctrine.cache.filesystem', TRUE),
      array('doctrine.cache.memcache', TRUE),
      array('doctrine.cache.memcached', TRUE),
      array('doctrine.cache.redis', TRUE),
      array('doctrine.cache.wincache', TRUE),
      array('doctrine.cache.xcache', TRUE),
      array('doctrine.cache.zenddata', TRUE),
      array('doctrine.authenticationadapter.orm_default', TRUE),
      array('doctrine.authenticationstorage.orm_default', TRUE),
      array('doctrine.authenticationservice.orm_default', TRUE),
      array('doctrine.authenticationadapter.odm_default', TRUE),
      array('doctrine.authenticationstorage.odm_default', TRUE),
      array('doctrine.authenticationservice.odm_default', TRUE),
      array('foo', FALSE),
      array('foo.bar', FALSE),
      array('foo.bar.baz', FALSE),
      array('doctrine', FALSE),
      array('doctrine.foo', FALSE),
      array('doctrine.foo.bar', FALSE),
      array('doctrine.cache.bar', FALSE),
      //array('doctrine.cache.zendcachestorage'),
    );
  }

  /**
   * @return array
   */
  public function getServicesThatCanBeFetched() {
    return array(
      array('doctrine.cache.array', 'Doctrine\Common\Cache\ArrayCache'),
    );
  }

  /**
   * @return array
   */
  public function getServicesThatCannotBeFetched() {
    return array(
      array('foo'),
      array('foo.bar'),
      array('foo.bar.baz'),
      array('doctrine'),
      array('doctrine.foo'),
      array('doctrine.foo.bar'),
      array('doctrine.cache.bar'),
    );
  }
}
