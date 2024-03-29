<?php

/*
 * This file is part of the Symfony package.
 *
 * (c) Fabien Potencier <fabien@symfony.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Symfony\Component\Console\Descriptor;

use Symfony\Component\Console\Application;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Exception\CommandNotFoundException;

/**
 * @author Jean-François Simon <jeanfrancois.simon@sensiolabs.com>
 *
 * @internal
 */
class ApplicationDescription {
  const GLOBAL_NAMESPACE = '_global';

  /**
   * @var Application
   */
  private $application;

  /**
   * @var null|string
   */
  private $namespace;

  /**
   * @var array
   */
  private $namespaces;

  /**
   * @var Command[]
   */
  private $commands;

  /**
   * @var Command[]
   */
  private $aliases;

  /**
   * Constructor.
   *
   * @param Application $application
   * @param string|null $namespace
   */
  public function __construct(Application $application, $namespace = NULL) {
    $this->application = $application;
    $this->namespace = $namespace;
  }

  /**
   * @return array
   */
  public function getNamespaces() {
    if (NULL === $this->namespaces) {
      $this->inspectApplication();
    }

    return $this->namespaces;
  }

  /**
   * @return Command[]
   */
  public function getCommands() {
    if (NULL === $this->commands) {
      $this->inspectApplication();
    }

    return $this->commands;
  }

  /**
   * @param string $name
   *
   * @return Command
   *
   * @throws CommandNotFoundException
   */
  public function getCommand($name) {
    if (!isset($this->commands[$name]) && !isset($this->aliases[$name])) {
      throw new CommandNotFoundException(sprintf('Command %s does not exist.', $name));
    }

    return isset($this->commands[$name]) ? $this->commands[$name] : $this->aliases[$name];
  }

  private function inspectApplication() {
    $this->commands = array();
    $this->namespaces = array();

    $all = $this->application->all($this->namespace ? $this->application->findNamespace($this->namespace) : NULL);
    foreach ($this->sortCommands($all) as $namespace => $commands) {
      $names = array();

      /** @var Command $command */
      foreach ($commands as $name => $command) {
        if (!$command->getName()) {
          continue;
        }

        if ($command->getName() === $name) {
          $this->commands[$name] = $command;
        }
        else {
          $this->aliases[$name] = $command;
        }

        $names[] = $name;
      }

      $this->namespaces[$namespace] = array(
        'id' => $namespace,
        'commands' => $names
      );
    }
  }

  /**
   * @param array $commands
   *
   * @return array
   */
  private function sortCommands(array $commands) {
    $namespacedCommands = array();
    $globalCommands = array();
    foreach ($commands as $name => $command) {
      $key = $this->application->extractNamespace($name, 1);
      if (!$key) {
        $globalCommands['_global'][$name] = $command;
      }
      else {
        $namespacedCommands[$key][$name] = $command;
      }
    }
    ksort($namespacedCommands);
    $namespacedCommands = array_merge($globalCommands, $namespacedCommands);

    foreach ($namespacedCommands as &$commandsSet) {
      ksort($commandsSet);
    }
    // unset reference to keep scope clear
    unset($commandsSet);

    return $namespacedCommands;
  }
}
