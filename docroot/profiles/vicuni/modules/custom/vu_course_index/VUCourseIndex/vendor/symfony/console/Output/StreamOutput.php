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

use Symfony\Component\Console\Exception\InvalidArgumentException;
use Symfony\Component\Console\Exception\RuntimeException;
use Symfony\Component\Console\Formatter\OutputFormatterInterface;

/**
 * StreamOutput writes the output to a given stream.
 *
 * Usage:
 *
 * $output = new StreamOutput(fopen('php://stdout', 'w'));
 *
 * As `StreamOutput` can use any stream, you can also use a file:
 *
 * $output = new StreamOutput(fopen('/path/to/output.log', 'a', false));
 *
 * @author Fabien Potencier <fabien@symfony.com>
 */
class StreamOutput extends Output {
  private $stream;

  /**
   * Constructor.
   *
   * @param resource $stream A stream resource
   * @param int $verbosity The verbosity level (one of the VERBOSITY constants
   *   in OutputInterface)
   * @param bool|null $decorated Whether to decorate messages (null for
   *   auto-guessing)
   * @param OutputFormatterInterface|null $formatter Output formatter instance
   *   (null to use default OutputFormatter)
   *
   * @throws InvalidArgumentException When first argument is not a real stream
   */
  public function __construct($stream, $verbosity = self::VERBOSITY_NORMAL, $decorated = NULL, OutputFormatterInterface $formatter = NULL) {
    if (!is_resource($stream) || 'stream' !== get_resource_type($stream)) {
      throw new InvalidArgumentException('The StreamOutput class needs a stream as its first argument.');
    }

    $this->stream = $stream;

    if (NULL === $decorated) {
      $decorated = $this->hasColorSupport();
    }

    parent::__construct($verbosity, $decorated, $formatter);
  }

  /**
   * Gets the stream attached to this StreamOutput instance.
   *
   * @return resource A stream resource
   */
  public function getStream() {
    return $this->stream;
  }

  /**
   * {@inheritdoc}
   */
  protected function doWrite($message, $newline) {
    if (FALSE === @fwrite($this->stream, $message . ($newline ? PHP_EOL : ''))) {
      // should never happen
      throw new RuntimeException('Unable to write output.');
    }

    fflush($this->stream);
  }

  /**
   * Returns true if the stream supports colorization.
   *
   * Colorization is disabled if not supported by the stream:
   *
   *  -  Windows before 10.0.10586 without Ansicon, ConEmu or Mintty
   *  -  non tty consoles
   *
   * @return bool true if the stream supports colorization, false otherwise
   */
  protected function hasColorSupport() {
    if (DIRECTORY_SEPARATOR === '\\') {
      return
        0 >= version_compare('10.0.10586', PHP_WINDOWS_VERSION_MAJOR . '.' . PHP_WINDOWS_VERSION_MINOR . '.' . PHP_WINDOWS_VERSION_BUILD)
        || FALSE !== getenv('ANSICON')
        || 'ON' === getenv('ConEmuANSI')
        || 'xterm' === getenv('TERM');
    }

    return function_exists('posix_isatty') && @posix_isatty($this->stream);
  }
}