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
 * Type that maps an SQL TIME to a PHP DateTime object.
 *
 * @since 2.0
 */
class TimeType extends Type {
  /**
   * {@inheritdoc}
   */
  public function getName() {
    return Type::TIME;
  }

  /**
   * {@inheritdoc}
   */
  public function getSQLDeclaration(array $fieldDeclaration, AbstractPlatform $platform) {
    return $platform->getTimeTypeDeclarationSQL($fieldDeclaration);
  }

  /**
   * {@inheritdoc}
   */
  public function convertToDatabaseValue($value, AbstractPlatform $platform) {
    return ($value !== NULL)
      ? $value->format($platform->getTimeFormatString()) : NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function convertToPHPValue($value, AbstractPlatform $platform) {
    if ($value === NULL || $value instanceof \DateTime) {
      return $value;
    }

    $val = \DateTime::createFromFormat('!' . $platform->getTimeFormatString(), $value);
    if (!$val) {
      throw ConversionException::conversionFailedFormat($value, $this->getName(), $platform->getTimeFormatString());
    }

    return $val;
  }
}
