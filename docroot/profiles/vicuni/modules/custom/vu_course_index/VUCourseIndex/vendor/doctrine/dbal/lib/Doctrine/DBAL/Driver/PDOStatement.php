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

namespace Doctrine\DBAL\Driver;

/**
 * The PDO implementation of the Statement interface.
 * Used by all PDO-based drivers.
 *
 * @since 2.0
 */
class PDOStatement extends \PDOStatement implements Statement {
  /**
   * Protected constructor.
   */
  protected function __construct() {
  }

  /**
   * {@inheritdoc}
   */
  public function setFetchMode($fetchMode, $arg2 = NULL, $arg3 = NULL) {
    // This thin wrapper is necessary to shield against the weird signature
    // of PDOStatement::setFetchMode(): even if the second and third
    // parameters are optional, PHP will not let us remove it from this
    // declaration.
    try {
      if ($arg2 === NULL && $arg3 === NULL) {
        return parent::setFetchMode($fetchMode);
      }

      if ($arg3 === NULL) {
        return parent::setFetchMode($fetchMode, $arg2);
      }

      return parent::setFetchMode($fetchMode, $arg2, $arg3);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function bindValue($param, $value, $type = \PDO::PARAM_STR) {
    try {
      return parent::bindValue($param, $value, $type);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function bindParam($column, &$variable, $type = \PDO::PARAM_STR, $length = NULL, $driverOptions = NULL) {
    try {
      return parent::bindParam($column, $variable, $type, $length, $driverOptions);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function execute($params = NULL) {
    try {
      return parent::execute($params);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function fetch($fetchMode = NULL, $cursorOrientation = NULL, $cursorOffset = NULL) {
    try {
      if ($fetchMode === NULL && $cursorOrientation === NULL && $cursorOffset === NULL) {
        return parent::fetch();
      }

      if ($cursorOrientation === NULL && $cursorOffset === NULL) {
        return parent::fetch($fetchMode);
      }

      if ($cursorOffset === NULL) {
        return parent::fetch($fetchMode, $cursorOrientation);
      }

      return parent::fetch($fetchMode, $cursorOrientation, $cursorOffset);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function fetchAll($fetchMode = NULL, $fetchArgument = NULL, $ctorArgs = NULL) {
    try {
      if ($fetchMode === NULL && $fetchArgument === NULL && $ctorArgs === NULL) {
        return parent::fetchAll();
      }

      if ($fetchArgument === NULL && $ctorArgs === NULL) {
        return parent::fetchAll($fetchMode);
      }

      if ($ctorArgs === NULL) {
        return parent::fetchAll($fetchMode, $fetchArgument);
      }

      return parent::fetchAll($fetchMode, $fetchArgument, $ctorArgs);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function fetchColumn($columnIndex = 0) {
    try {
      return parent::fetchColumn($columnIndex);
    }
    catch (\PDOException $exception) {
      throw new PDOException($exception);
    }
  }
}
