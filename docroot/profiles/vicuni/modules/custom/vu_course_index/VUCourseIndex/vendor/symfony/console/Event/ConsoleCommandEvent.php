<?php

/*
 * This file is part of the Symfony package.
 *
 * (c) Fabien Potencier <fabien@symfony.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Symfony\Component\Console\Event;

/**
 * Allows to do things before the command is executed, like skipping the
 * command or changing the input.
 *
 * @author Fabien Potencier <fabien@symfony.com>
 */
class ConsoleCommandEvent extends ConsoleEvent {
  /**
   * The return code for skipped commands, this will also be passed into the
   * terminate event.
   */
  const RETURN_CODE_DISABLED = 113;

  /**
   * Indicates if the command should be run or skipped.
   *
   * @var bool
   */
  private $commandShouldRun = TRUE;

  /**
   * Disables the command, so it won't be run.
   *
   * @return bool
   */
  public function disableCommand() {
    return $this->commandShouldRun = FALSE;
  }

  /**
   * Enables the command.
   *
   * @return bool
   */
  public function enableCommand() {
    return $this->commandShouldRun = TRUE;
  }

  /**
   * Returns true if the command is runnable, false otherwise.
   *
   * @return bool
   */
  public function commandShouldRun() {
    return $this->commandShouldRun;
  }
}
