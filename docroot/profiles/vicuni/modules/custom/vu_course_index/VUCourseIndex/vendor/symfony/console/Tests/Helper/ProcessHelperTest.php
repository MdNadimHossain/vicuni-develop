<?php

/*
 * This file is part of the Symfony package.
 *
 * (c) Fabien Potencier <fabien@symfony.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Symfony\Component\Console\Tests\Helper;

use Symfony\Component\Console\Helper\DebugFormatterHelper;
use Symfony\Component\Console\Helper\HelperSet;
use Symfony\Component\Console\Output\StreamOutput;
use Symfony\Component\Console\Helper\ProcessHelper;
use Symfony\Component\Process\Process;

class ProcessHelperTest extends \PHPUnit_Framework_TestCase {
  /**
   * @dataProvider provideCommandsAndOutput
   */
  public function testVariousProcessRuns($expected, $cmd, $verbosity, $error) {
    $helper = new ProcessHelper();
    $helper->setHelperSet(new HelperSet(array(new DebugFormatterHelper())));
    $output = $this->getOutputStream($verbosity);
    $helper->run($output, $cmd, $error);
    $this->assertEquals($expected, $this->getOutput($output));
  }

  public function testPassedCallbackIsExecuted() {
    $helper = new ProcessHelper();
    $helper->setHelperSet(new HelperSet(array(new DebugFormatterHelper())));
    $output = $this->getOutputStream(StreamOutput::VERBOSITY_NORMAL);

    $executed = FALSE;
    $callback = function () use (&$executed) {
      $executed = TRUE;
    };

    $helper->run($output, 'php -r "echo 42;"', NULL, $callback);
    $this->assertTrue($executed);
  }

  public function provideCommandsAndOutput() {
    $successOutputVerbose = <<<EOT
  RUN  php -r "echo 42;"
  RES  Command ran successfully

EOT;
    $successOutputDebug = <<<EOT
  RUN  php -r "echo 42;"
  OUT  42
  RES  Command ran successfully

EOT;
    $successOutputDebugWithTags = <<<EOT
  RUN  php -r "echo '<info>42</info>';"
  OUT  <info>42</info>
  RES  Command ran successfully

EOT;
    $successOutputProcessDebug = <<<EOT
  RUN  'php' '-r' 'echo 42;'
  OUT  42
  RES  Command ran successfully

EOT;
    $syntaxErrorOutputVerbose = <<<EOT
  RUN  php -r "fwrite(STDERR, 'error message');usleep(50000);fwrite(STDOUT, 'out message');exit(252);"
  RES  252 Command did not run successfully

EOT;
    $syntaxErrorOutputDebug = <<<EOT
  RUN  php -r "fwrite(STDERR, 'error message');usleep(500000);fwrite(STDOUT, 'out message');exit(252);"
  ERR  error message
  OUT  out message
  RES  252 Command did not run successfully

EOT;

    $errorMessage = 'An error occurred';
    if ('\\' === DIRECTORY_SEPARATOR) {
      $successOutputProcessDebug = str_replace("'", '"', $successOutputProcessDebug);
    }

    return array(
      array('', 'php -r "echo 42;"', StreamOutput::VERBOSITY_VERBOSE, NULL),
      array(
        $successOutputVerbose,
        'php -r "echo 42;"',
        StreamOutput::VERBOSITY_VERY_VERBOSE,
        NULL
      ),
      array(
        $successOutputDebug,
        'php -r "echo 42;"',
        StreamOutput::VERBOSITY_DEBUG,
        NULL
      ),
      array(
        $successOutputDebugWithTags,
        'php -r "echo \'<info>42</info>\';"',
        StreamOutput::VERBOSITY_DEBUG,
        NULL
      ),
      array('', 'php -r "syntax error"', StreamOutput::VERBOSITY_VERBOSE, NULL),
      array(
        $syntaxErrorOutputVerbose,
        'php -r "fwrite(STDERR, \'error message\');usleep(50000);fwrite(STDOUT, \'out message\');exit(252);"',
        StreamOutput::VERBOSITY_VERY_VERBOSE,
        NULL
      ),
      array(
        $syntaxErrorOutputDebug,
        'php -r "fwrite(STDERR, \'error message\');usleep(500000);fwrite(STDOUT, \'out message\');exit(252);"',
        StreamOutput::VERBOSITY_DEBUG,
        NULL
      ),
      array(
        $errorMessage . PHP_EOL,
        'php -r "fwrite(STDERR, \'error message\');usleep(50000);fwrite(STDOUT, \'out message\');exit(252);"',
        StreamOutput::VERBOSITY_VERBOSE,
        $errorMessage
      ),
      array(
        $syntaxErrorOutputVerbose . $errorMessage . PHP_EOL,
        'php -r "fwrite(STDERR, \'error message\');usleep(50000);fwrite(STDOUT, \'out message\');exit(252);"',
        StreamOutput::VERBOSITY_VERY_VERBOSE,
        $errorMessage
      ),
      array(
        $syntaxErrorOutputDebug . $errorMessage . PHP_EOL,
        'php -r "fwrite(STDERR, \'error message\');usleep(500000);fwrite(STDOUT, \'out message\');exit(252);"',
        StreamOutput::VERBOSITY_DEBUG,
        $errorMessage
      ),
      array(
        $successOutputProcessDebug,
        array('php', '-r', 'echo 42;'),
        StreamOutput::VERBOSITY_DEBUG,
        NULL
      ),
      array(
        $successOutputDebug,
        new Process('php -r "echo 42;"'),
        StreamOutput::VERBOSITY_DEBUG,
        NULL
      ),
    );
  }

  private function getOutputStream($verbosity) {
    return new StreamOutput(fopen('php://memory', 'r+', FALSE), $verbosity, FALSE);
  }

  private function getOutput(StreamOutput $output) {
    rewind($output->getStream());

    return stream_get_contents($output->getStream());
  }
}
