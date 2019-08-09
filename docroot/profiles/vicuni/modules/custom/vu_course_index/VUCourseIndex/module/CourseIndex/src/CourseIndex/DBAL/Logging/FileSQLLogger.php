<?php
use Doctrine\DBAL\Logging\SQLLogger;

namespace CourseIndex\DBAL\Logging;

/**
 * A SQL logger that logs to the standard output using echo/var_dump.
 *
 * @link www.doctrine-project.org
 *
 * @since 2.0
 *
 * @author Benjamin Eberlei <kontakt@beberlei.de>
 * @author Guilherme Blanco <guilhermeblanco@hotmail.com>
 * @author Jonathan Wage <jonwage@gmail.com>
 * @author Roman Borschel <roman@code-factory.org>
 */
class FileSQLLogger implements SQLLogger {

  /**
   * {@inheritdoc}
   */
  public function startQuery($sql, array $params = NULL, array $types = NULL) {
    file_put_contents('/tmp/foo.txt', $sql . PHP_EOL, FILE_APPEND);

    if ($params) {
      ob_start();
      var_dump($params);
      $a = ob_get_contents();
      ob_end_clean();
      file_put_contents('/tmp/foo.txt', $a . PHP_EOL, FILE_APPEND);
    }

    if ($types) {
      ob_start();
      var_dump($types);
      $a = ob_get_contents();
      ob_end_clean();
      file_put_contents('/tmp/foo.txt', $a . PHP_EOL, FILE_APPEND);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function stopQuery() {
  }

}
