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

namespace Doctrine\ORM\Query\AST\Functions;

use Doctrine\ORM\Query\Lexer;

/**
 * "MOD" "(" SimpleArithmeticExpression "," SimpleArithmeticExpression ")"
 *
 *
 * @link    www.doctrine-project.org
 * @since   2.0
 * @author  Guilherme Blanco <guilhermeblanco@hotmail.com>
 * @author  Jonathan Wage <jonwage@gmail.com>
 * @author  Roman Borschel <roman@code-factory.org>
 * @author  Benjamin Eberlei <kontakt@beberlei.de>
 */
class ModFunction extends FunctionNode {
  /**
   * @var \Doctrine\ORM\Query\AST\SimpleArithmeticExpression
   */
  public $firstSimpleArithmeticExpression;

  /**
   * @var \Doctrine\ORM\Query\AST\SimpleArithmeticExpression
   */
  public $secondSimpleArithmeticExpression;

  /**
   * @override
   */
  public function getSql(\Doctrine\ORM\Query\SqlWalker $sqlWalker) {
    return $sqlWalker->getConnection()->getDatabasePlatform()->getModExpression(
      $sqlWalker->walkSimpleArithmeticExpression($this->firstSimpleArithmeticExpression),
      $sqlWalker->walkSimpleArithmeticExpression($this->secondSimpleArithmeticExpression)
    );
  }

  /**
   * @override
   */
  public function parse(\Doctrine\ORM\Query\Parser $parser) {
    $parser->match(Lexer::T_IDENTIFIER);
    $parser->match(Lexer::T_OPEN_PARENTHESIS);

    $this->firstSimpleArithmeticExpression = $parser->SimpleArithmeticExpression();

    $parser->match(Lexer::T_COMMA);

    $this->secondSimpleArithmeticExpression = $parser->SimpleArithmeticExpression();

    $parser->match(Lexer::T_CLOSE_PARENTHESIS);
  }
}
