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
 * Type that maps a PHP array to a clob SQL type.
 *
 * @since 2.0
 */
class ArrayType extends Type {
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
    // @todo 3.0 - $value === null check to save real NULL in database
    return serialize($value);
  }

  /**
   * {@inheritdoc}
   */
  public function convertToPHPValue($value, AbstractPlatform $platform) {
    if ($value === NULL) {
      return NULL;
    }

    $value = (is_resource($value)) ? stream_get_contents($value) : $value;
    $val = unserialize($value);
    if ($val === FALSE && $value != 'b:0;') {
      throw ConversionException::conversionFailed($value, $this->getName());
    }

    return $val;
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return Type::TARRAY;
  }

  /**
   * {@inheritdoc}
   */
  public function requiresSQLCommentHint(AbstractPlatform $platform) {
    return TRUE;
  }
}
