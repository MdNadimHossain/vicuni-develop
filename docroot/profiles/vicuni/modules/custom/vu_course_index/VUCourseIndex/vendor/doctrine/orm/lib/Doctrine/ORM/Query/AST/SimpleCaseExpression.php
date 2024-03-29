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
 * SimpleCaseExpression ::= "CASE" CaseOperand SimpleWhenClause
 * {SimpleWhenClause}* "ELSE" ScalarExpression "END"
 *
 * @since   2.2
 *
 * @link    www.doctrine-project.org
 * @author  Benjamin Eberlei <kontakt@beberlei.de>
 * @author  Guilherme Blanco <guilhermeblanco@hotmail.com>
 * @author  Jonathan Wage <jonwage@gmail.com>
 * @author  Roman Borschel <roman@code-factory.org>
 */
class SimpleCaseExpression extends Node {
  /**
   * @var PathExpression
   */
  public $caseOperand = NULL;

  /**
   * @var array
   */
  public $simpleWhenClauses = array();

  /**
   * @var mixed
   */
  public $elseScalarExpression = NULL;

  /**
   * @param PathExpression $caseOperand
   * @param array $simpleWhenClauses
   * @param mixed $elseScalarExpression
   */
  public function __construct($caseOperand, array $simpleWhenClauses, $elseScalarExpression) {
    $this->caseOperand = $caseOperand;
    $this->simpleWhenClauses = $simpleWhenClauses;
    $this->elseScalarExpression = $elseScalarExpression;
  }

  /**
   * {@inheritdoc}
   */
  public function dispatch($sqlWalker) {
    return $sqlWalker->walkSimpleCaseExpression($this);
  }
}
