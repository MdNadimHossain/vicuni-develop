<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Code\Scanner;

use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Exception;
use Zend\Code\NameInformation;

class MethodScanner implements ScannerInterface {
  /**
   * @var bool
   */
  protected $isScanned = FALSE;

  /**
   * @var string
   */
  protected $docComment = NULL;

  /**
   * @var ClassScanner
   */
  protected $scannerClass = NULL;

  /**
   * @var string
   */
  protected $class = NULL;

  /**
   * @var string
   */
  protected $name = NULL;

  /**
   * @var int
   */
  protected $lineStart = NULL;

  /**
   * @var int
   */
  protected $lineEnd = NULL;

  /**
   * @var bool
   */
  protected $isFinal = FALSE;

  /**
   * @var bool
   */
  protected $isAbstract = FALSE;

  /**
   * @var bool
   */
  protected $isPublic = TRUE;

  /**
   * @var bool
   */
  protected $isProtected = FALSE;

  /**
   * @var bool
   */
  protected $isPrivate = FALSE;

  /**
   * @var bool
   */
  protected $isStatic = FALSE;

  /**
   * @var string
   */
  protected $body = '';

  /**
   * @var array
   */
  protected $tokens = array();

  /**
   * @var NameInformation
   */
  protected $nameInformation = NULL;

  /**
   * @var array
   */
  protected $infos = array();

  /**
   * @param  array $methodTokens
   * @param NameInformation $nameInformation
   */
  public function __construct(array $methodTokens, NameInformation $nameInformation = NULL) {
    $this->tokens = $methodTokens;
    $this->nameInformation = $nameInformation;
  }

  /**
   * @param  string $class
   *
   * @return MethodScanner
   */
  public function setClass($class) {
    $this->class = (string) $class;
    return $this;
  }

  /**
   * @param  ClassScanner $scannerClass
   *
   * @return MethodScanner
   */
  public function setScannerClass(ClassScanner $scannerClass) {
    $this->scannerClass = $scannerClass;
    return $this;
  }

  /**
   * @return MethodScanner
   */
  public function getClassScanner() {
    return $this->scannerClass;
  }

  /**
   * @return string
   */
  public function getName() {
    $this->scan();

    return $this->name;
  }

  /**
   * @return int
   */
  public function getLineStart() {
    $this->scan();

    return $this->lineStart;
  }

  /**
   * @return int
   */
  public function getLineEnd() {
    $this->scan();

    return $this->lineEnd;
  }

  /**
   * @return string
   */
  public function getDocComment() {
    $this->scan();

    return $this->docComment;
  }

  /**
   * @param  AnnotationManager $annotationManager
   *
   * @return AnnotationScanner
   */
  public function getAnnotations(AnnotationManager $annotationManager) {
    if (($docComment = $this->getDocComment()) == '') {
      return FALSE;
    }

    return new AnnotationScanner($annotationManager, $docComment, $this->nameInformation);
  }

  /**
   * @return bool
   */
  public function isFinal() {
    $this->scan();

    return $this->isFinal;
  }

  /**
   * @return bool
   */
  public function isAbstract() {
    $this->scan();

    return $this->isAbstract;
  }

  /**
   * @return bool
   */
  public function isPublic() {
    $this->scan();

    return $this->isPublic;
  }

  /**
   * @return bool
   */
  public function isProtected() {
    $this->scan();

    return $this->isProtected;
  }

  /**
   * @return bool
   */
  public function isPrivate() {
    $this->scan();

    return $this->isPrivate;
  }

  /**
   * @return bool
   */
  public function isStatic() {
    $this->scan();

    return $this->isStatic;
  }

  /**
   * @return int
   */
  public function getNumberOfParameters() {
    return count($this->getParameters());
  }

  /**
   * @param  bool $returnScanner
   *
   * @return array
   */
  public function getParameters($returnScanner = FALSE) {
    $this->scan();

    $return = array();

    foreach ($this->infos as $info) {
      if ($info['type'] != 'parameter') {
        continue;
      }

      if (!$returnScanner) {
        $return[] = $info['name'];
      }
      else {
        $return[] = $this->getParameter($info['name']);
      }
    }

    return $return;
  }

  /**
   * @param  int|string $parameterNameOrInfoIndex
   *
   * @return ParameterScanner
   * @throws Exception\InvalidArgumentException
   */
  public function getParameter($parameterNameOrInfoIndex) {
    $this->scan();

    if (is_int($parameterNameOrInfoIndex)) {
      $info = $this->infos[$parameterNameOrInfoIndex];
      if ($info['type'] != 'parameter') {
        throw new Exception\InvalidArgumentException('Index of info offset is not about a parameter');
      }
    }
    elseif (is_string($parameterNameOrInfoIndex)) {
      foreach ($this->infos as $info) {
        if ($info['type'] === 'parameter' && $info['name'] === $parameterNameOrInfoIndex) {
          break;
        }
        unset($info);
      }
      if (!isset($info)) {
        throw new Exception\InvalidArgumentException('Index of info offset is not about a parameter');
      }
    }

    $p = new ParameterScanner(
      array_slice($this->tokens, $info['tokenStart'], $info['tokenEnd'] - $info['tokenStart']),
      $this->nameInformation
    );
    $p->setDeclaringFunction($this->name);
    $p->setDeclaringScannerFunction($this);
    $p->setDeclaringClass($this->class);
    $p->setDeclaringScannerClass($this->scannerClass);
    $p->setPosition($info['position']);

    return $p;
  }

  /**
   * @return string
   */
  public function getBody() {
    $this->scan();

    return $this->body;
  }

  public static function export() {
    // @todo
  }

  public function __toString() {
    $this->scan();

    return var_export($this, TRUE);
  }

  protected function scan() {
    if ($this->isScanned) {
      return;
    }

    if (!$this->tokens) {
      throw new Exception\RuntimeException('No tokens were provided');
    }

    /**
     * Variables & Setup
     */

    $tokens = &$this->tokens; // localize
    $infos = &$this->infos; // localize
    $tokenIndex = NULL;
    $token = NULL;
    $tokenType = NULL;
    $tokenContent = NULL;
    $tokenLine = NULL;
    $infoIndex = 0;
    $parentCount = 0;

    /*
     * MACRO creation
     */
    $MACRO_TOKEN_ADVANCE = function () use (&$tokens, &$tokenIndex, &$token, &$tokenType, &$tokenContent, &$tokenLine) {
      static $lastTokenArray = NULL;
      $tokenIndex = ($tokenIndex === NULL) ? 0 : $tokenIndex + 1;
      if (!isset($tokens[$tokenIndex])) {
        $token = FALSE;
        $tokenContent = FALSE;
        $tokenType = FALSE;
        $tokenLine = FALSE;

        return FALSE;
      }
      $token = $tokens[$tokenIndex];
      if (is_string($token)) {
        $tokenType = NULL;
        $tokenContent = $token;
        $tokenLine = $tokenLine + substr_count(
            $lastTokenArray[1],
            "\n"
          ); // adjust token line by last known newline count
      }
      else {
        list($tokenType, $tokenContent, $tokenLine) = $token;
      }

      return $tokenIndex;
    };
    $MACRO_INFO_START = function () use (&$infoIndex, &$infos, &$tokenIndex, &$tokenLine) {
      $infos[$infoIndex] = array(
        'type' => 'parameter',
        'tokenStart' => $tokenIndex,
        'tokenEnd' => NULL,
        'lineStart' => $tokenLine,
        'lineEnd' => $tokenLine,
        'name' => NULL,
        'position' => $infoIndex + 1, // position is +1 of infoIndex
      );
    };
    $MACRO_INFO_ADVANCE = function () use (&$infoIndex, &$infos, &$tokenIndex, &$tokenLine) {
      $infos[$infoIndex]['tokenEnd'] = $tokenIndex;
      $infos[$infoIndex]['lineEnd'] = $tokenLine;
      $infoIndex++;

      return $infoIndex;
    };

    /**
     * START FINITE STATE MACHINE FOR SCANNING TOKENS
     */

    // Initialize token
    $MACRO_TOKEN_ADVANCE();

    SCANNER_TOP:

    $this->lineStart = ($this->lineStart) ?: $tokenLine;

    switch ($tokenType) {
      case T_DOC_COMMENT:
        $this->lineStart = NULL;
        if ($this->docComment === NULL && $this->name === NULL) {
          $this->docComment = $tokenContent;
        }
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_FINAL:
        $this->isFinal = TRUE;
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_ABSTRACT:
        $this->isAbstract = TRUE;
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_PUBLIC:
        // use defaults
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_PROTECTED:
        $this->isProtected = TRUE;
        $this->isPublic = FALSE;
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_PRIVATE:
        $this->isPrivate = TRUE;
        $this->isPublic = FALSE;
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_STATIC:
        $this->isStatic = TRUE;
        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case T_VARIABLE:
      case T_STRING:

        if ($tokenType === T_STRING && $parentCount === 0) {
          $this->name = $tokenContent;
        }

        if ($parentCount === 1) {
          if (!isset($infos[$infoIndex])) {
            $MACRO_INFO_START();
          }
          if ($tokenType === T_VARIABLE) {
            $infos[$infoIndex]['name'] = ltrim($tokenContent, '$');
          }
        }

        goto SCANNER_CONTINUE_SIGNATURE;
      //goto (no break needed);

      case NULL:

        switch ($tokenContent) {
          case '&':
            if (!isset($infos[$infoIndex])) {
              $MACRO_INFO_START();
            }
            goto SCANNER_CONTINUE_SIGNATURE;
          //goto (no break needed);
          case '(':
            $parentCount++;
            goto SCANNER_CONTINUE_SIGNATURE;
          //goto (no break needed);
          case ')':
            $parentCount--;
            if ($parentCount > 0) {
              goto SCANNER_CONTINUE_SIGNATURE;
            }
            if ($parentCount === 0) {
              if ($infos) {
                $MACRO_INFO_ADVANCE();
              }
              $context = 'body';
            }
            goto SCANNER_CONTINUE_BODY;
          //goto (no break needed);
          case ',':
            if ($parentCount === 1) {
              $MACRO_INFO_ADVANCE();
            }
            goto SCANNER_CONTINUE_SIGNATURE;
        }
    }

    SCANNER_CONTINUE_SIGNATURE:

    if ($MACRO_TOKEN_ADVANCE() === FALSE) {
      goto SCANNER_END;
    }
    goto SCANNER_TOP;

    SCANNER_CONTINUE_BODY:

    $braceCount = 0;
    while ($MACRO_TOKEN_ADVANCE() !== FALSE) {
      if ($tokenContent == '}') {
        $braceCount--;
      }
      if ($braceCount > 0) {
        $this->body .= $tokenContent;
      }
      if ($tokenContent == '{') {
        $braceCount++;
      }
      $this->lineEnd = $tokenLine;
    }

    SCANNER_END:

    $this->isScanned = TRUE;

    return;
  }
}
