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

namespace Doctrine\ORM\Tools\Console\Command\SchemaTool;

use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Doctrine\ORM\Tools\SchemaTool;

/**
 * Command to create the database schema for a set of classes based on their
 * mappings.
 *
 * @link    www.doctrine-project.org
 * @since   2.0
 * @author  Benjamin Eberlei <kontakt@beberlei.de>
 * @author  Guilherme Blanco <guilhermeblanco@hotmail.com>
 * @author  Jonathan Wage <jonwage@gmail.com>
 * @author  Roman Borschel <roman@code-factory.org>
 */
class CreateCommand extends AbstractCommand {
  /**
   * {@inheritdoc}
   */
  protected function configure() {
    $this
      ->setName('orm:schema-tool:create')
      ->setDescription(
        'Processes the schema and either create it directly on EntityManager Storage Connection or generate the SQL output.'
      )
      ->setDefinition(array(
        new InputOption(
          'dump-sql', NULL, InputOption::VALUE_NONE,
          'Instead of trying to apply generated SQLs into EntityManager Storage Connection, output them.'
        )
      ))
      ->setHelp(<<<EOT
Processes the schema and either create it directly on EntityManager Storage Connection or generate the SQL output.

<comment>Hint:</comment> If you have a database with tables that should not be managed
by the ORM, you can use a DBAL functionality to filter the tables and sequences down
on a global level:

    \$config->setFilterSchemaAssetsExpression(\$regexp);
EOT
      );
  }

  /**
   * {@inheritdoc}
   */
  protected function executeSchemaCommand(InputInterface $input, OutputInterface $output, SchemaTool $schemaTool, array $metadatas) {
    if ($input->getOption('dump-sql')) {
      $sqls = $schemaTool->getCreateSchemaSql($metadatas);
      $output->writeln(implode(';' . PHP_EOL, $sqls) . ';');
    }
    else {
      $output->writeln('ATTENTION: This operation should not be executed in a production environment.' . PHP_EOL);

      $output->writeln('Creating database schema...');
      $schemaTool->createSchema($metadatas);
      $output->writeln('Database schema created successfully!');
    }

    return 0;
  }
}
