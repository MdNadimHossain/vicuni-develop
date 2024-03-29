<?php

namespace Herrera\Phar\Update\Tests;

use Herrera\Phar\Update\Manifest;
use Herrera\Json\Exception\JsonException;
use Herrera\Phar\Update\Update;
use Herrera\PHPUnit\TestCase;
use KevinGH\Version\Version;

class ManifestTest extends TestCase {
  /** @var Manifest */
  private $manifest;

  /** @var Update */
  private $v1;

  /** @var Update */
  private $v1p;

  /** @var Update */
  private $v2;

  public function testFindRecent() {
    $version = Version::create('1.0.0');

    $this->assertSame(
      $this->v1,
      $this->manifest->findRecent($version, TRUE)
    );
    $this->assertSame(
      $this->v1p,
      $this->manifest->findRecent(
        Version::create('2.0.0-alpha.1'),
        TRUE,
        TRUE
      )
    );
    $this->assertSame($this->v2, $this->manifest->findRecent($version));
  }

  public function testFindRecentNone() {
    $this->assertNull(
      $this->manifest->findRecent(Version::create('5.0.0'))
    );
  }

  public function testGetUpdates() {
    $this->assertSame(
      array($this->v1, $this->v1p, $this->v2),
      $this->manifest->getUpdates()
    );
  }

  public function testLoad() {
    $data = json_encode(array(
      array(
        'name' => 'test.phar',
        'publicKey' => 'http://example.com/test-1.2.3.phar.pubkey',
        'sha1' => 'abcdefabcdefabcdefabcdefabcdefabcdefabcd',
        'url' => 'http://example.com/test-1.2.3.phar',
        'version' => '1.2.3',
      ),
      array(
        'name' => 'test.phar',
        'publicKey' => 'http://example.com/test-4.5.6.phar.pubkey',
        'sha1' => '0123456789012345678901234567890123456789',
        'url' => 'http://example.com/test-4.5.6.phar',
        'version' => '4.5.6'
      )
    ));

    try {
      $updates = Manifest::load($data)->getUpdates();
    }
    catch (JsonException $exception) {
      print_r($exception->getErrors());
      throw $exception;
    }

    $this->assertEquals(
      'http://example.com/test-4.5.6.phar.pubkey',
      $updates[0]->getPublicKey()
    );
    $this->assertEquals(
      'http://example.com/test-1.2.3.phar.pubkey',
      $updates[1]->getPublicKey()
    );
  }

  public function testLoadFile() {
    file_put_contents($file = $this->createFile(), json_encode(array(
      array(
        'name' => 'test.phar',
        'sha1' => 'abcdefabcdefabcdefabcdefabcdefabcdefabcd',
        'url' => 'http://example.com/test-1.2.3.phar',
        'version' => '1.2.3'
      ),
      array(
        'name' => 'test.phar',
        'sha1' => '0123456789012345678901234567890123456789',
        'url' => 'http://example.com/test-4.5.6.phar',
        'version' => '4.5.6'
      )
    )));

    try {
      $updates = Manifest::loadFile($file)->getUpdates();
    }
    catch (JsonException $exception) {
      print_r($exception->getErrors());
      throw $exception;
    }

    $this->assertEquals(
      '0123456789012345678901234567890123456789',
      $updates[0]->getSha1()
    );
    $this->assertEquals(
      'abcdefabcdefabcdefabcdefabcdefabcdefabcd',
      $updates[1]->getSha1()
    );
  }

  protected function setUp() {
    $this->v1 = new Update(
      'test.phar',
      '0123456789012345678901234567890123456789',
      'http://example.com/test.phar',
      Version::create('1.2.3')
    );

    $this->v1p = new Update(
      'test.phar',
      '0123456789012345678901234567890123456789',
      'http://example.com/test.phar',
      Version::create('2.0.0-alpha.2')
    );

    $this->v2 = new Update(
      'test.phar',
      '0123456789012345678901234567890123456789',
      'http://example.com/test.phar',
      Version::create('4.5.6')
    );

    $this->manifest = new Manifest(array(
      $this->v1,
      $this->v1p,
      $this->v2
    ));
  }
}
