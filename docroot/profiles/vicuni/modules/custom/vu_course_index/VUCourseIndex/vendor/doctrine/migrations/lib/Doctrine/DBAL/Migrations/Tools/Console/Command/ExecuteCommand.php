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
 * and is licensed under the LGPL. For more information, see
 * <http://www.doctrine-project.org>.
 */

namespace Doctrine\DBAL\Migrations\Tools\Console\Command;

use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputOption;

/**
 * Command for executing single migrations up or down manually.
 *
 * @license http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link    www.doctrine-project.org
 * @since   2.0
 * @author  Jonathan Wage <jonwage@gmail.com>
 */
class ExecuteCommand extends AbstractCommand {
  protected function configure() {
    $this
      ->setName('migrations:execute')
      ->setDescription('Execute a single migration version up or down manually.')
      ->addArgument('version', InputArgument::REQUIRED, 'The version to execute.', NULL)
      ->addOption('write-sql', NULL, InputOption::VALUE_NONE, 'The path to output the migration SQL file instead of executing it.')
      ->addOption('dry-run', NULL, InputOption::VALUE_NONE, 'Execute the migration as a dry run.')
      ->addOption('up', NULL, InputOption::VALUE_NONE, 'Execute the migration up.')
      ->addOption('down', NULL, InputOption::VALUE_NONE, 'Execute the migration down.')
      ->addOption('query-time', NULL, InputOption::VALUE_NONE, 'Time all the queries individually.')
      ->setHelp(<<<EOT
The <info>%command.name%</info> command executes a single migration version up or down manually:

    <info>%command.full_name% YYYYMMDDHHMMSS</info>

If no <comment>--up</comment> or <comment>--down</comment> option is specified it defaults to up:

    <info>%command.full_name% YYYYMMDDHHMMSS --down</info>

You can also execute the migration as a <comment>--dry-run</comment>:

    <info>%command.full_name% YYYYMMDDHHMMSS --dry-run</info>

You can output the would be executed SQL statements to a file with <comment>--write-sql</comment>:

    <info>%command.full_name% YYYYMMDDHHMMSS --write-sql</info>

Or you can also execute the migration without a warning message which you need to interact with:

    <info>%command.full_name% --no-interaction</info>
EOT
      );

    parent::configure();
  }

  public function execute(InputInterface $input, OutputInterface $output) {
    $version = $input->getArgument('version');
    $direction = $input->getOption('down') ? 'down' : 'up';

    $configuration = $this->getMigrationConfiguration($input, $output);
    $version = $configuration->getVersion($version);

    $timeAllqueries = $input->getOption('query-time');

    if ($path = $input->getOption('write-sql')) {
      $path = is_bool($path) ? getcwd() : $path;
      $version->writeSqlFile($path, $direction);
    }
    else {
      if ($input->isInteractive()) {
        $question = 'WARNING! You are about to execute a database migration that could result in schema changes and data lost. Are you sure you wish to continue? (y/n)';
        $execute = $this->askConfirmation($question, $input, $output);
      }
      else {
        $execute = TRUE;
      }

      if ($execute) {
        $version->execute($direction, (boolean) $input->getOption('dry-run'), $timeAllqueries);
      }
      else {
        $output->writeln('<error>Migration cancelled!</error>');
      }
    }
  }
}
