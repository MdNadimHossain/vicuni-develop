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

namespace Doctrine\DBAL\Types;

use Doctrine\DBAL\Platforms\AbstractPlatform;

/**
 * Array Type which can be used for simple values.
 *
 * Only use this type if you are sure that your values cannot contain a ",".
 *
 * @since  2.3
 * @author Johannes M. Schmitt <schmittjoh@gmail.com>
 */
class SimpleArrayType extends Type {
  /**
   * {@inheritdoc}
   */
  public function getSQLDeclaration(array $fieldDeclaration, AbstractPlatform $platform) {
    return $platform->getClobTypeDeclarationSQL($fieldDeclaration);
  }

  /**
   * {@inheritdoc}
   */
  public function convertToDatabaseValue($value, AbstractPlatform $platform) {
    if (!$value) {
      return NULL;
    }

    return implode(',', $value);
  }

  /**
   * {@inheritdoc}
   */
  public function convertToPHPValue($value, AbstractPlatform $platform) {
    if ($value === NULL) {
      return array();
    }

    $value = (is_resource($value)) ? stream_get_contents($value) : $value;

    return explode(',', $value);
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return Type::SIMPLE_ARRAY;
  }

  /**
   * {@inheritdoc}
   */
  public function requiresSQLCommentHint(AbstractPlatform $platform) {
    return TRUE;
  }
}
