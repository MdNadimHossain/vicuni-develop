<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInit9032bbd9551d37020d1dc7226a114212 {
  public static $files = array(
    '0e6d7bf4a5811bfa5cf40c5ccd6fae6a' => __DIR__ . '/..' . '/symfony/polyfill-mbstring/bootstrap.php',
  );

  public static $prefixLengthsPsr4 = array(
    'S' =>
      array(
        'Symfony\\Polyfill\\Mbstring\\' => 26,
        'Symfony\\Component\\Yaml\\' => 23,
        'Symfony\\Component\\Console\\' => 26,
      ),
    'D' =>
      array(
        'Doctrine\\Instantiator\\' => 22,
        'Doctrine\\Common\\Cache\\' => 22,
      ),
  );

  public static $prefixDirsPsr4 = array(
    'Symfony\\Polyfill\\Mbstring\\' =>
      array(
        0 => __DIR__ . '/..' . '/symfony/polyfill-mbstring',
      ),
    'Symfony\\Component\\Yaml\\' =>
      array(
        0 => __DIR__ . '/..' . '/symfony/yaml',
      ),
    'Symfony\\Component\\Console\\' =>
      array(
        0 => __DIR__ . '/..' . '/symfony/console',
      ),
    'Doctrine\\Instantiator\\' =>
      array(
        0 => __DIR__ . '/..' . '/doctrine/instantiator/src/Doctrine/Instantiator',
      ),
    'Doctrine\\Common\\Cache\\' =>
      array(
        0 => __DIR__ . '/..' . '/doctrine/cache/lib/Doctrine/Common/Cache',
      ),
  );

  public static $prefixesPsr0 = array(
    'Z' =>
      array(
        'Zend\\' =>
          array(
            0 => __DIR__ . '/..' . '/zendframework/zendframework/library',
          ),
        'ZendXml\\' =>
          array(
            0 => __DIR__ . '/..' . '/zendframework/zendxml/library',
          ),
        'ZendDiagnostics\\' =>
          array(
            0 => __DIR__ . '/..' . '/zendframework/zenddiagnostics/src',
          ),
        'ZendDiagnosticsTest\\' =>
          array(
            0 => __DIR__ . '/..' . '/zendframework/zenddiagnostics/tests',
          ),
        'ZFTool\\' =>
          array(
            0 => __DIR__ . '/..' . '/zendframework/zftool/src',
          ),
      ),
    'D' =>
      array(
        'Doctrine\\ORM\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/orm/lib',
          ),
        'Doctrine\\DBAL\\Migrations' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/migrations/lib',
          ),
        'Doctrine\\DBAL\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/dbal/lib',
          ),
        'Doctrine\\Common\\Lexer\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/lexer/lib',
          ),
        'Doctrine\\Common\\Inflector\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/inflector/lib',
          ),
        'Doctrine\\Common\\Collections\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/collections/lib',
          ),
        'Doctrine\\Common\\Annotations\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/annotations/lib',
          ),
        'Doctrine\\Common\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/common/lib',
          ),
        'DoctrineORMModule\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/doctrine-orm-module/src',
          ),
        'DoctrineModule\\' =>
          array(
            0 => __DIR__ . '/..' . '/doctrine/doctrine-module/src',
          ),
      ),
  );

  public static function getInitializer(ClassLoader $loader) {
    return \Closure::bind(function () use ($loader) {
      $loader->prefixLengthsPsr4 = ComposerStaticInit9032bbd9551d37020d1dc7226a114212::$prefixLengthsPsr4;
      $loader->prefixDirsPsr4 = ComposerStaticInit9032bbd9551d37020d1dc7226a114212::$prefixDirsPsr4;
      $loader->prefixesPsr0 = ComposerStaticInit9032bbd9551d37020d1dc7226a114212::$prefixesPsr0;
    }, NULL, ClassLoader::class);
  }
}
