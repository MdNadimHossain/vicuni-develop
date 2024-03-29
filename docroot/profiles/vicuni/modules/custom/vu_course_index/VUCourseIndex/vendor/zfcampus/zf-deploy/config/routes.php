<?php
/**
 * @license   http://opensource.org/licenses/BSD-3-Clause BSD-3-Clause
 * @copyright Copyright (c) 2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 */

use Zend\Filter\Callback as CallbackFilter;
use ZF\Console\Filter\Explode as ExplodeFilter;
use ZF\Deploy\Deploy;

$extensions = Deploy::getValidExtensions();
array_walk($extensions, 'preg_quote');

$booleanFilter = new CallbackFilter(function ($value) {
  if ('off' === $value) {
    return FALSE;
  }
  return TRUE;
});

return array(
  array(
    'name' => 'self-update',
    'description' => 'The self-update command checks packages.zendframework.com for a newer
version, and, if found, downloads and installs the latest.',
    'short_description' => 'Updates zfdeploy.phar to the latest version',
    'defaults' => array(
      'self-update' => TRUE,
    ),
  ),
  array(
    'name' => 'build',
    'route' => 'build <package> [--target=] [--modules=] [--vendor|-v]:vendor [--composer=] [--gitignore=] [--configs=] [--deploymentxml=] [--zpkdata=] [--version=]',
    'description' => 'Create a deployment package named <package> based on the provided target directory.',
    'short_description' => 'Build a deployment package',
    'options_descriptions' => array(
      '<package>' => 'Name of the package file to create; suffix must be .zip, .tar, .tar.gz, .tgz, or .zpk',
      '--target' => 'The target directory of the application to package; defaults to current working directory',
      '--modules' => 'Comma-separated list of modules to include in build',
      '--vendor|-v' => 'Whether or not to include the vendor directory (disabled by default)',
      '--composer' => 'Whether or not to execute composer; "on" or "off" ("on" by default)',
      '--gitignore' => 'Whether or not to parse the .gitignore file to determine what files/folders to exclude; "on" or "off" ("on" by default)',
      '--configs' => 'Path to directory containing application config files to include in the package',
      '--deploymentxml' => 'Path to a custom deployment.xml to use when building a ZPK package',
      '--zpkdata' => 'Path to a directory containing ZPK package assets (deployment.xml, logo, scripts, etc.)',
      '--version' => 'Specific application version to use for a ZPK package',
    ),
    'constraints' => array(
      'package' => '#\.(' . implode('|', $extensions) . ')$#',
      'composer' => '/^(on|off)$/',
      'gitignore' => '/^(on|off)$/',
    ),
    'defaults' => array(
      'build' => TRUE,
      'composer' => TRUE,
      'configs' => FALSE,
      'deploymentxml' => NULL,
      'gitignore' => TRUE,
      'modules' => array(),
      'target' => getcwd(),
      'vendor' => FALSE,
      'version' => date('Y-m-d_H:i'),
      'zpkdata' => NULL,
    ),
    'filters' => array(
      'composer' => $booleanFilter,
      'gitignore' => $booleanFilter,
      'modules' => new ExplodeFilter(),
    ),
    'handler' => 'ZF\Deploy\Deploy',
  ),
);
