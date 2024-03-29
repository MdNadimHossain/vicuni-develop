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

namespace Doctrine\ORM\Query\AST;

/**
 * ArithmeticFactor ::= [("+" | "-")] ArithmeticPrimary
 *
 * @link    www.doctrine-project.org
 * @since   2.0
 * @author  Guilherme Blanco <guilhermeblanco@hotmail.com>
 * @author  Jonathan Wage <jonwage@gmail.com>
 * @author  Roman Borschel <roman@code-factory.org>
 */
class ArithmeticFactor extends Node {
  /**
   * @var mixed
   */
  public $arithmeticPrimary;

  /**
   * NULL represents no sign, TRUE means positive and FALSE means negative sign.
   *
   * @var null|boolean
   */
  public $sign;

  /**
   * @param mixed $arithmeticPrimary
   * @param null|bool $sign
   */
  public function __construct($arithmeticPrimary, $sign = NULL) {
    $this->arithmeticPrimary = $arithmeticPrimary;
    $this->sign = $sign;
  }

  /**
   * @return bool
   */
  public function isPositiveSigned() {
    return $this->sign === TRUE;
  }

  /**
   * @return bool
   */
  public function isNegativeSigned() {
    return $this->sign === FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function dispatch($sqlWalker) {
    return $sqlWalker->walkArithmeticFactor($this);
  }
}
