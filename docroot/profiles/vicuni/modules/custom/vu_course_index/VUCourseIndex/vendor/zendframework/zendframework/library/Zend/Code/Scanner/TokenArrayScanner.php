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

class TokenArrayScanner implements ScannerInterface {
  /**
   * @var bool
   */
  protected $isScanned = FALSE;

  /**
   * @var array
   */
  protected $tokens = array();

  /**
   * @var null
   */
  protected $docComment = NULL;

  /**
   * @var NameInformation
   */
  protected $nameInformation = NULL;

  /**
   * @var array
   */
  protected $infos = array();

  /**
   * @var AnnotationManager
   */
  protected $annotationManager = NULL;

  /**
   * @param null|array $tokens
   * @param null|AnnotationManager $annotationManager
   */
  public function __construct($tokens, AnnotationManager $annotationManager = NULL) {
    $this->tokens = $tokens;
    $this->annotationManager = $annotationManager;
  }

  /**
   * @return AnnotationManager
   */
  public function getAnnotationManager() {
    return $this->annotationManager;
  }

  /**
   * Get doc comment
   *
   * @todo Assignment of $this->docComment should probably be done in scan()
   *       and then $this->getDocComment() just retrieves it.
   *
   * @return string
   */
  public function getDocComment() {
    foreach ($this->tokens as $token) {
      $type = $token[0];
      $value = $token[1];
      if (($type == T_OPEN_TAG) || ($type == T_WHITESPACE)) {
        continue;
      }
      elseif ($type == T_DOC_COMMENT) {
        $this->docComment = $value;

        return $this->docComment;
      }
      else {
        // Only whitespace is allowed before file docblocks
        return;
      }
    }
  }

  /**
   * @return array
   */
  public function getNamespaces() {
    $this->scan();

    $namespaces = array();
    foreach ($this->infos as $info) {
      if ($info['type'] == 'namespace') {
        $namespaces[] = $info['namespace'];
      }
    }

    return $namespaces;
  }

  /**
   * @param  null|string $namespace
   *
   * @return array|null
   */
  public function getUses($namespace = NULL) {
    $this->scan();

    return $this->getUsesNoScan($namespace);
  }

  /**
   * @return array
   */
  public function getIncludes() {
    $this->scan();
    // @todo Implement getIncludes() in TokenArrayScanner
  }

  /**
   * @return array
   */
  public function getClassNames() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'class') {
        continue;
      }

      $return[] = $info['name'];
    }

    return $return;
  }

  /**
   * @return ClassScanner[]
   */
  public function getClasses() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'class') {
        continue;
      }

      $return[] = $this->getClass($info['name']);
    }

    return $return;
  }

  /**
   * Return the class object from this scanner
   *
   * @param  string|int $name
   *
   * @throws Exception\InvalidArgumentException
   * @return ClassScanner
   */
  public function getClass($name) {
    $this->scan();

    if (is_int($name)) {
      $info = $this->infos[$name];
      if ($info['type'] != 'class') {
        throw new Exception\InvalidArgumentException('Index of info offset is not about a class');
      }
    }
    elseif (is_string($name)) {
      $classFound = FALSE;
      foreach ($this->infos as $info) {
        if ($info['type'] === 'class' && $info['name'] === $name) {
          $classFound = TRUE;
          break;
        }
      }

      if (!$classFound) {
        return FALSE;
      }
    }

    return new ClassScanner(
      array_slice(
        $this->tokens,
        $info['tokenStart'],
        ($info['tokenEnd'] - $info['tokenStart'] + 1)
      ), // zero indexed array
      new NameInformation($info['namespace'], $info['uses'])
    );
  }

  /**
   * @param  string $className
   *
   * @return bool|null|NameInformation
   */
  public function getClassNameInformation($className) {
    $this->scan();

    $classFound = FALSE;
    foreach ($this->infos as $info) {
      if ($info['type'] === 'class' && $info['name'] === $className) {
        $classFound = TRUE;
        break;
      }
    }

    if (!$classFound) {
      return FALSE;
    }

    if (!isset($info)) {
      return NULL;
    }

    return new NameInformation($info['namespace'], $info['uses']);
  }

  /**
   * @return array
   */
  public function getFunctionNames() {
    $this->scan();
    $functionNames = array();
    foreach ($this->infos as $info) {
      if ($info['type'] == 'function') {
        $functionNames[] = $info['name'];
      }
    }

    return $functionNames;
  }

  /**
   * @return array
   */
  public function getFunctions() {
    $this->scan();

    $functions = array();
    foreach ($this->infos as $info) {
      if ($info['type'] == 'function') {
        // @todo $functions[] = new FunctionScanner($info['name']);
      }
    }

    return $functions;
  }

  /**
   * Export
   *
   * @param $tokens
   */
  public static function export($tokens) {
    // @todo
  }

  public function __toString() {
    // @todo
  }

  /**
   * Scan
   *
   * @todo: $this->docComment should be assigned for valid docblock during
   *        the scan instead of $this->getDocComment() (starting with
   *        T_DOC_COMMENT case)
   *
   * @throws Exception\RuntimeException
   */
  protected function scan() {
    if ($this->isScanned) {
      return;
    }

    if (!$this->tokens) {
      throw new Exception\RuntimeException('No tokens were provided');
    }

    /**
     * Define PHP 5.4 'trait' token constant.
     */
    if (!defined('T_TRAIT')) {
      define('T_TRAIT', 42001);
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
    $namespace = NULL;
    $docCommentIndex = FALSE;
    $infoIndex = 0;

    /*
     * MACRO creation
     */
    $MACRO_TOKEN_ADVANCE = function () use (&$tokens, &$tokenIndex, &$token, &$tokenType, &$tokenContent, &$tokenLine) {
      $tokenIndex = ($tokenIndex === NULL) ? 0 : $tokenIndex + 1;
      if (!isset($tokens[$tokenIndex])) {
        $token = FALSE;
        $tokenContent = FALSE;
        $tokenType = FALSE;
        $tokenLine = FALSE;

        return FALSE;
      }
      if (is_string($tokens[$tokenIndex]) && $tokens[$tokenIndex] === '"') {
        do {
          $tokenIndex++;
        } while (!(is_string($tokens[$tokenIndex]) && $tokens[$tokenIndex] === '"'));
      }
      $token = $tokens[$tokenIndex];
      if (is_array($token)) {
        list($tokenType, $tokenContent, $tokenLine) = $token;
      }
      else {
        $tokenType = NULL;
        $tokenContent = $token;
      }

      return $tokenIndex;
    };
    $MACRO_TOKEN_LOGICAL_START_INDEX = function () use (&$tokenIndex, &$docCommentIndex) {
      return ($docCommentIndex === FALSE) ? $tokenIndex : $docCommentIndex;
    };
    $MACRO_DOC_COMMENT_START = function () use (&$tokenIndex, &$docCommentIndex) {
      $docCommentIndex = $tokenIndex;

      return $docCommentIndex;
    };
    $MACRO_DOC_COMMENT_VALIDATE = function () use (&$tokenType, &$docCommentIndex) {
      static $validTrailingTokens = NULL;
      if ($validTrailingTokens === NULL) {
        $validTrailingTokens = array(
          T_WHITESPACE,
          T_FINAL,
          T_ABSTRACT,
          T_INTERFACE,
          T_CLASS,
          T_FUNCTION
        );
      }
      if ($docCommentIndex !== FALSE && !in_array($tokenType, $validTrailingTokens)) {
        $docCommentIndex = FALSE;
      }

      return $docCommentIndex;
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

    if ($token === FALSE) {
      goto SCANNER_END;
    }

    // Validate current doc comment index
    $MACRO_DOC_COMMENT_VALIDATE();

    switch ($tokenType) {

      case T_DOC_COMMENT:

        $MACRO_DOC_COMMENT_START();
        goto SCANNER_CONTINUE;
      //goto no break needed

      case T_NAMESPACE:

        $infos[$infoIndex] = array(
          'type' => 'namespace',
          'tokenStart' => $MACRO_TOKEN_LOGICAL_START_INDEX(),
          'tokenEnd' => NULL,
          'lineStart' => $token[2],
          'lineEnd' => NULL,
          'namespace' => NULL,
        );

        // start processing with next token
        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }

        SCANNER_NAMESPACE_TOP:

        if ($tokenType === NULL && $tokenContent === ';' || $tokenContent === '{') {
          goto SCANNER_NAMESPACE_END;
        }

        if ($tokenType === T_WHITESPACE) {
          goto SCANNER_NAMESPACE_CONTINUE;
        }

        if ($tokenType === T_NS_SEPARATOR || $tokenType === T_STRING) {
          $infos[$infoIndex]['namespace'] .= $tokenContent;
        }

        SCANNER_NAMESPACE_CONTINUE:

        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }
        goto SCANNER_NAMESPACE_TOP;

        SCANNER_NAMESPACE_END:

        $namespace = $infos[$infoIndex]['namespace'];

        $MACRO_INFO_ADVANCE();
        goto SCANNER_CONTINUE;
      //goto no break needed

      case T_USE:

        $infos[$infoIndex] = array(
          'type' => 'use',
          'tokenStart' => $MACRO_TOKEN_LOGICAL_START_INDEX(),
          'tokenEnd' => NULL,
          'lineStart' => $tokens[$tokenIndex][2],
          'lineEnd' => NULL,
          'namespace' => $namespace,
          'statements' => array(
            0 => array(
              'use' => NULL,
              'as' => NULL
            )
          ),
        );

        $useStatementIndex = 0;
        $useAsContext = FALSE;

        // start processing with next token
        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }

        SCANNER_USE_TOP:

        if ($tokenType === NULL) {
          if ($tokenContent === ';') {
            goto SCANNER_USE_END;
          }
          elseif ($tokenContent === ',') {
            $useAsContext = FALSE;
            $useStatementIndex++;
            $infos[$infoIndex]['statements'][$useStatementIndex] = array(
              'use' => NULL,
              'as' => NULL
            );
          }
        }

        // ANALYZE
        if ($tokenType !== NULL) {

          if ($tokenType == T_AS) {
            $useAsContext = TRUE;
            goto SCANNER_USE_CONTINUE;
          }

          if ($tokenType == T_NS_SEPARATOR || $tokenType == T_STRING) {
            if ($useAsContext == FALSE) {
              $infos[$infoIndex]['statements'][$useStatementIndex]['use'] .= $tokenContent;
            }
            else {
              $infos[$infoIndex]['statements'][$useStatementIndex]['as'] = $tokenContent;
            }
          }
        }

        SCANNER_USE_CONTINUE:

        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }
        goto SCANNER_USE_TOP;

        SCANNER_USE_END:

        $MACRO_INFO_ADVANCE();
        goto SCANNER_CONTINUE;
      //goto no break needed

      case T_INCLUDE:
      case T_INCLUDE_ONCE:
      case T_REQUIRE:
      case T_REQUIRE_ONCE:

        // Static for performance
        static $includeTypes = array(
          T_INCLUDE => 'include',
          T_INCLUDE_ONCE => 'include_once',
          T_REQUIRE => 'require',
          T_REQUIRE_ONCE => 'require_once'
        );

        $infos[$infoIndex] = array(
          'type' => 'include',
          'tokenStart' => $MACRO_TOKEN_LOGICAL_START_INDEX(),
          'tokenEnd' => NULL,
          'lineStart' => $tokens[$tokenIndex][2],
          'lineEnd' => NULL,
          'includeType' => $includeTypes[$tokens[$tokenIndex][0]],
          'path' => '',
        );

        // start processing with next token
        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }

        SCANNER_INCLUDE_TOP:

        if ($tokenType === NULL && $tokenContent === ';') {
          goto SCANNER_INCLUDE_END;
        }

        $infos[$infoIndex]['path'] .= $tokenContent;

        SCANNER_INCLUDE_CONTINUE:

        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }
        goto SCANNER_INCLUDE_TOP;

        SCANNER_INCLUDE_END:

        $MACRO_INFO_ADVANCE();
        goto SCANNER_CONTINUE;
      //goto no break needed

      case T_FUNCTION:
      case T_FINAL:
      case T_ABSTRACT:
      case T_CLASS:
      case T_INTERFACE:
      case T_TRAIT:

        $infos[$infoIndex] = array(
          'type' => ($tokenType === T_FUNCTION) ? 'function' : 'class',
          'tokenStart' => $MACRO_TOKEN_LOGICAL_START_INDEX(),
          'tokenEnd' => NULL,
          'lineStart' => $tokens[$tokenIndex][2],
          'lineEnd' => NULL,
          'namespace' => $namespace,
          'uses' => $this->getUsesNoScan($namespace),
          'name' => NULL,
          'shortName' => NULL,
        );

        $classBraceCount = 0;

        // start processing with current token

        SCANNER_CLASS_TOP:

        // process the name
        if ($infos[$infoIndex]['shortName'] == ''
          && (($tokenType === T_CLASS || $tokenType === T_INTERFACE || $tokenType === T_TRAIT) && $infos[$infoIndex]['type'] === 'class'
            || ($tokenType === T_FUNCTION && $infos[$infoIndex]['type'] === 'function'))
        ) {
          $infos[$infoIndex]['shortName'] = $tokens[$tokenIndex + 2][1];
          $infos[$infoIndex]['name'] = (($namespace != NULL) ? $namespace . '\\' : '') . $infos[$infoIndex]['shortName'];
        }

        if ($tokenType === NULL) {
          if ($tokenContent == '{') {
            $classBraceCount++;
          }
          if ($tokenContent == '}') {
            $classBraceCount--;
            if ($classBraceCount === 0) {
              goto SCANNER_CLASS_END;
            }
          }
        }

        SCANNER_CLASS_CONTINUE:

        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }
        goto SCANNER_CLASS_TOP;

        SCANNER_CLASS_END:

        $MACRO_INFO_ADVANCE();
        goto SCANNER_CONTINUE;
    }

    SCANNER_CONTINUE:

    if ($MACRO_TOKEN_ADVANCE() === FALSE) {
      goto SCANNER_END;
    }
    goto SCANNER_TOP;

    SCANNER_END:

    /**
     * END FINITE STATE MACHINE FOR SCANNING TOKENS
     */

    $this->isScanned = TRUE;
  }

  /**
   * Check for namespace
   *
   * @param string $namespace
   *
   * @return bool
   */
  public function hasNamespace($namespace) {
    $this->scan();

    foreach ($this->infos as $info) {
      if ($info['type'] == 'namespace' && $info['namespace'] == $namespace) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * @param  string $namespace
   *
   * @return null|array
   * @throws Exception\InvalidArgumentException
   */
  protected function getUsesNoScan($namespace) {
    $namespaces = array();
    foreach ($this->infos as $info) {
      if ($info['type'] == 'namespace') {
        $namespaces[] = $info['namespace'];
      }
    }

    if ($namespace === NULL) {
      $namespace = array_shift($namespaces);
    }
    elseif (!is_string($namespace)) {
      throw new Exception\InvalidArgumentException('Invalid namespace provided');
    }
    elseif (!in_array($namespace, $namespaces)) {
      return NULL;
    }

    $uses = array();
    foreach ($this->infos as $info) {
      if ($info['type'] !== 'use') {
        continue;
      }
      foreach ($info['statements'] as $statement) {
        if ($info['namespace'] == $namespace) {
          $uses[] = $statement;
        }
      }
    }

    return $uses;
  }
}
