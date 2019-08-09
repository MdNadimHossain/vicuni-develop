<?php

/*
 * This file is part of the Symfony package.
 *
 * (c) Fabien Potencier <fabien@symfony.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Symfony\Component\Console\Output;

use Symfony\Component\Console\Formatter\OutputFormatter;
use Symfony\Component\Console\Formatter\OutputFormatterInterface;

/**
 * NullOutput suppresses all output.
 *
 *     $output = new NullOutput();
 *
 * @author Fabien Potencier <fabien@symfony.com>
 * @author Tobias Schultze <http://tobion.de>
 */
class NullOutput implements OutputInterface {
  /**
   * {@inheritdoc}
   */
  public function setFormatter(OutputFormatterInterface $formatter) {
    // do nothing
  }

  /**
   * {@inheritdoc}
   */
  public function getFormatter() {
    // to comply with the interface we must return a OutputFormatterInterface
    return new OutputFormatter();
  }

  /**
   * {@inheritdoc}
   */
  public function setDecorated($decorated) {
    // do nothing
  }

  /**
   * {@inheritdoc}
   */
  public function isDecorated() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function setVerbosity($level) {
    // do nothing
  }

  /**
   * {@inheritdoc}
   */
  public function getVerbosity() {
    return self::VERBOSITY_QUIET;
  }

  public function isQuiet() {
    return TRUE;
  }

  public function isVerbose() {
    return FALSE;
  }

  public function isVeryVerbose() {
    return FALSE;
  }

  public function isDebug() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function writeln($messages, $options = self::OUTPUT_NORMAL) {
    // do nothing
  }

  /**
   * {@inheritdoc}
   */
  public function write($messages, $newline = FALSE, $options = self::OUTPUT_NORMAL) {
    // do nothing
  }
}
