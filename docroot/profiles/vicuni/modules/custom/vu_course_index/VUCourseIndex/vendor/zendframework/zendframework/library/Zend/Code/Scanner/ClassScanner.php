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

use Zend\Code\Annotation;
use Zend\Code\Exception;
use Zend\Code\NameInformation;

class ClassScanner implements ScannerInterface {
  /**
   * @var bool
   */
  protected $isScanned = FALSE;

  /**
   * @var string
   */
  protected $docComment = NULL;

  /**
   * @var string
   */
  protected $name = NULL;

  /**
   * @var string
   */
  protected $shortName = NULL;

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
  protected $isInterface = FALSE;

  /**
   * @var string
   */
  protected $parentClass = NULL;

  /**
   * @var string
   */
  protected $shortParentClass = NULL;

  /**
   * @var array
   */
  protected $interfaces = array();

  /**
   * @var array
   */
  protected $shortInterfaces = array();

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
   * @param  array $classTokens
   * @param  NameInformation|null $nameInformation
   *
   * @return ClassScanner
   */
  public function __construct(array $classTokens, NameInformation $nameInformation = NULL) {
    $this->tokens = $classTokens;
    $this->nameInformation = $nameInformation;
  }

  /**
   * Get annotations
   *
   * @param  Annotation\AnnotationManager $annotationManager
   *
   * @return Annotation\AnnotationCollection
   */
  public function getAnnotations(Annotation\AnnotationManager $annotationManager) {
    if (($docComment = $this->getDocComment()) == '') {
      return FALSE;
    }

    return new AnnotationScanner($annotationManager, $docComment, $this->nameInformation);
  }

  /**
   * Return documentation comment
   *
   * @return null|string
   */
  public function getDocComment() {
    $this->scan();

    return $this->docComment;
  }

  /**
   * Return documentation block
   *
   * @return false|DocBlockScanner
   */
  public function getDocBlock() {
    if (!$docComment = $this->getDocComment()) {
      return FALSE;
    }

    return new DocBlockScanner($docComment);
  }

  /**
   * Return a name of class
   *
   * @return null|string
   */
  public function getName() {
    $this->scan();
    return $this->name;
  }

  /**
   * Return short name of class
   *
   * @return null|string
   */
  public function getShortName() {
    $this->scan();
    return $this->shortName;
  }

  /**
   * Return number of first line
   *
   * @return int|null
   */
  public function getLineStart() {
    $this->scan();
    return $this->lineStart;
  }

  /**
   * Return number of last line
   *
   * @return int|null
   */
  public function getLineEnd() {
    $this->scan();
    return $this->lineEnd;
  }

  /**
   * Verify if class is final
   *
   * @return bool
   */
  public function isFinal() {
    $this->scan();
    return $this->isFinal;
  }

  /**
   * Verify if class is instantiable
   *
   * @return bool
   */
  public function isInstantiable() {
    $this->scan();
    return (!$this->isAbstract && !$this->isInterface);
  }

  /**
   * Verify if class is an abstract class
   *
   * @return bool
   */
  public function isAbstract() {
    $this->scan();
    return $this->isAbstract;
  }

  /**
   * Verify if class is an interface
   *
   * @return bool
   */
  public function isInterface() {
    $this->scan();
    return $this->isInterface;
  }

  /**
   * Verify if class has parent
   *
   * @return bool
   */
  public function hasParentClass() {
    $this->scan();
    return ($this->parentClass != NULL);
  }

  /**
   * Return a name of parent class
   *
   * @return null|string
   */
  public function getParentClass() {
    $this->scan();
    return $this->parentClass;
  }

  /**
   * Return a list of interface names
   *
   * @return array
   */
  public function getInterfaces() {
    $this->scan();
    return $this->interfaces;
  }

  /**
   * Return a list of constant names
   *
   * @return array
   */
  public function getConstantNames() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'constant') {
        continue;
      }

      $return[] = $info['name'];
    }

    return $return;
  }

  /**
   * Return a list of constants
   *
   * @param  bool $namesOnly Set false to return instances of ConstantScanner
   *
   * @return array|ConstantScanner[]
   */
  public function getConstants($namesOnly = TRUE) {
    if (TRUE === $namesOnly) {
      trigger_error('Use method getConstantNames() instead', E_USER_DEPRECATED);
      return $this->getConstantNames();
    }

    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'constant') {
        continue;
      }

      $return[] = $this->getConstant($info['name']);
    }

    return $return;
  }

  /**
   * Return a single constant by given name or index of info
   *
   * @param  string|int $constantNameOrInfoIndex
   *
   * @throws Exception\InvalidArgumentException
   * @return bool|ConstantScanner
   */
  public function getConstant($constantNameOrInfoIndex) {
    $this->scan();

    if (is_int($constantNameOrInfoIndex)) {
      $info = $this->infos[$constantNameOrInfoIndex];
      if ($info['type'] != 'constant') {
        throw new Exception\InvalidArgumentException('Index of info offset is not about a constant');
      }
    }
    elseif (is_string($constantNameOrInfoIndex)) {
      $constantFound = FALSE;
      foreach ($this->infos as $info) {
        if ($info['type'] === 'constant' && $info['name'] === $constantNameOrInfoIndex) {
          $constantFound = TRUE;
          break;
        }
      }
      if (!$constantFound) {
        return FALSE;
      }
    }
    else {
      throw new Exception\InvalidArgumentException('Invalid constant name of info index type.  Must be of type int or string');
    }
    if (!isset($info)) {
      return FALSE;
    }
    $p = new ConstantScanner(
      array_slice($this->tokens, $info['tokenStart'], $info['tokenEnd'] - $info['tokenStart'] + 1),
      $this->nameInformation
    );
    $p->setClass($this->name);
    $p->setScannerClass($this);
    return $p;
  }

  /**
   * Verify if class has constant
   *
   * @param  string $name
   *
   * @return bool
   */
  public function hasConstant($name) {
    $this->scan();

    foreach ($this->infos as $info) {
      if ($info['type'] === 'constant' && $info['name'] === $name) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Return a list of property names
   *
   * @return array
   */
  public function getPropertyNames() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'property') {
        continue;
      }

      $return[] = $info['name'];
    }

    return $return;
  }

  /**
   * Return a list of properties
   *
   * @return PropertyScanner
   */
  public function getProperties() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'property') {
        continue;
      }

      $return[] = $this->getProperty($info['name']);
    }

    return $return;
  }

  /**
   * Return a single property by given name or index of info
   *
   * @param  string|int $propertyNameOrInfoIndex
   *
   * @throws Exception\InvalidArgumentException
   * @return bool|PropertyScanner
   */
  public function getProperty($propertyNameOrInfoIndex) {
    $this->scan();

    if (is_int($propertyNameOrInfoIndex)) {
      $info = $this->infos[$propertyNameOrInfoIndex];
      if ($info['type'] != 'property') {
        throw new Exception\InvalidArgumentException('Index of info offset is not about a property');
      }
    }
    elseif (is_string($propertyNameOrInfoIndex)) {
      $propertyFound = FALSE;
      foreach ($this->infos as $info) {
        if ($info['type'] === 'property' && $info['name'] === $propertyNameOrInfoIndex) {
          $propertyFound = TRUE;
          break;
        }
      }
      if (!$propertyFound) {
        return FALSE;
      }
    }
    else {
      throw new Exception\InvalidArgumentException('Invalid property name of info index type.  Must be of type int or string');
    }
    if (!isset($info)) {
      return FALSE;
    }
    $p = new PropertyScanner(
      array_slice($this->tokens, $info['tokenStart'], $info['tokenEnd'] - $info['tokenStart'] + 1),
      $this->nameInformation
    );
    $p->setClass($this->name);
    $p->setScannerClass($this);
    return $p;
  }

  /**
   * Verify if class has property
   *
   * @param  string $name
   *
   * @return bool
   */
  public function hasProperty($name) {
    $this->scan();

    foreach ($this->infos as $info) {
      if ($info['type'] === 'property' && $info['name'] === $name) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Return a list of method names
   *
   * @return array
   */
  public function getMethodNames() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'method') {
        continue;
      }

      $return[] = $info['name'];
    }

    return $return;
  }

  /**
   * Return a list of methods
   *
   * @return MethodScanner[]
   */
  public function getMethods() {
    $this->scan();

    $return = array();
    foreach ($this->infos as $info) {
      if ($info['type'] != 'method') {
        continue;
      }

      $return[] = $this->getMethod($info['name']);
    }

    return $return;
  }

  /**
   * Return a single method by given name or index of info
   *
   * @param  string|int $methodNameOrInfoIndex
   *
   * @throws Exception\InvalidArgumentException
   * @return MethodScanner
   */
  public function getMethod($methodNameOrInfoIndex) {
    $this->scan();

    if (is_int($methodNameOrInfoIndex)) {
      $info = $this->infos[$methodNameOrInfoIndex];
      if ($info['type'] != 'method') {
        throw new Exception\InvalidArgumentException('Index of info offset is not about a method');
      }
    }
    elseif (is_string($methodNameOrInfoIndex)) {
      $methodFound = FALSE;
      foreach ($this->infos as $info) {
        if ($info['type'] === 'method' && $info['name'] === $methodNameOrInfoIndex) {
          $methodFound = TRUE;
          break;
        }
      }
      if (!$methodFound) {
        return FALSE;
      }
    }
    if (!isset($info)) {
      // @todo find a way to test this
      die('Massive Failure, test this');
    }
    $m = new MethodScanner(
      array_slice($this->tokens, $info['tokenStart'], $info['tokenEnd'] - $info['tokenStart'] + 1),
      $this->nameInformation
    );
    $m->setClass($this->name);
    $m->setScannerClass($this);

    return $m;
  }

  /**
   * Verify if class has method by given name
   *
   * @param  string $name
   *
   * @return bool
   */
  public function hasMethod($name) {
    $this->scan();

    foreach ($this->infos as $info) {
      if ($info['type'] === 'method' && $info['name'] === $name) {
        return TRUE;
      }
    }

    return FALSE;
  }

  public static function export() {
    // @todo
  }

  public function __toString() {
    // @todo
  }

  /**
   * Scan tokens
   *
   * @return void
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
    $infoIndex = 0;
    $braceCount = 0;

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
        $lastTokenArray = $token;
        list($tokenType, $tokenContent, $tokenLine) = $token;
      }

      return $tokenIndex;
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

    switch ($tokenType) {

      case T_DOC_COMMENT:

        $this->docComment = $tokenContent;
        goto SCANNER_CONTINUE;
      //goto no break needed

      case T_FINAL:
      case T_ABSTRACT:
      case T_CLASS:
      case T_INTERFACE:

        // CLASS INFORMATION

        $classContext = NULL;
        $classInterfaceIndex = 0;

        SCANNER_CLASS_INFO_TOP:

        if (is_string($tokens[$tokenIndex + 1]) && $tokens[$tokenIndex + 1] === '{') {
          goto SCANNER_CLASS_INFO_END;
        }

        $this->lineStart = $tokenLine;

        switch ($tokenType) {

          case T_FINAL:
            $this->isFinal = TRUE;
            goto SCANNER_CLASS_INFO_CONTINUE;
          //goto no break needed

          case T_ABSTRACT:
            $this->isAbstract = TRUE;
            goto SCANNER_CLASS_INFO_CONTINUE;
          //goto no break needed

          case T_INTERFACE:
            $this->isInterface = TRUE;
          //fall-through
          case T_CLASS:
            $this->shortName = $tokens[$tokenIndex + 2][1];
            if ($this->nameInformation && $this->nameInformation->hasNamespace()) {
              $this->name = $this->nameInformation->getNamespace() . '\\' . $this->shortName;
            }
            else {
              $this->name = $this->shortName;
            }
            goto SCANNER_CLASS_INFO_CONTINUE;
          //goto no break needed

          case T_NS_SEPARATOR:
          case T_STRING:
            switch ($classContext) {
              case T_EXTENDS:
                $this->shortParentClass .= $tokenContent;
                break;
              case T_IMPLEMENTS:
                $this->shortInterfaces[$classInterfaceIndex] .= $tokenContent;
                break;
            }
            goto SCANNER_CLASS_INFO_CONTINUE;
          //goto no break needed

          case T_EXTENDS:
          case T_IMPLEMENTS:
            $classContext = $tokenType;
            if (($this->isInterface && $classContext === T_EXTENDS) || $classContext === T_IMPLEMENTS) {
              $this->shortInterfaces[$classInterfaceIndex] = '';
            }
            elseif (!$this->isInterface && $classContext === T_EXTENDS) {
              $this->shortParentClass = '';
            }
            goto SCANNER_CLASS_INFO_CONTINUE;
          //goto no break needed

          case NULL:
            if ($classContext == T_IMPLEMENTS && $tokenContent == ',') {
              $classInterfaceIndex++;
              $this->shortInterfaces[$classInterfaceIndex] = '';
            }
        }

        SCANNER_CLASS_INFO_CONTINUE:

        if ($MACRO_TOKEN_ADVANCE() === FALSE) {
          goto SCANNER_END;
        }
        goto SCANNER_CLASS_INFO_TOP;

        SCANNER_CLASS_INFO_END:

        goto SCANNER_CONTINUE;
    }

    if ($tokenType === NULL && $tokenContent === '{' && $braceCount === 0) {

      $braceCount++;
      if ($MACRO_TOKEN_ADVANCE() === FALSE) {
        goto SCANNER_END;
      }

      SCANNER_CLASS_BODY_TOP:

      if ($braceCount === 0) {
        goto SCANNER_CLASS_BODY_END;
      }

      switch ($tokenType) {

        case T_CONST:

          $infos[$infoIndex] = array(
            'type' => 'constant',
            'tokenStart' => $tokenIndex,
            'tokenEnd' => NULL,
            'lineStart' => $tokenLine,
            'lineEnd' => NULL,
            'name' => NULL,
            'value' => NULL,
          );

          SCANNER_CLASS_BODY_CONST_TOP:

          if ($tokenContent === ';') {
            goto SCANNER_CLASS_BODY_CONST_END;
          }

          if ($tokenType === T_STRING && NULL === $infos[$infoIndex]['name']) {
            $infos[$infoIndex]['name'] = $tokenContent;
          }

          SCANNER_CLASS_BODY_CONST_CONTINUE:

          if ($MACRO_TOKEN_ADVANCE() === FALSE) {
            goto SCANNER_END;
          }
          goto SCANNER_CLASS_BODY_CONST_TOP;

          SCANNER_CLASS_BODY_CONST_END:

          $MACRO_INFO_ADVANCE();
          goto SCANNER_CLASS_BODY_CONTINUE;
        //goto no break needed

        case T_DOC_COMMENT:
        case T_PUBLIC:
        case T_PROTECTED:
        case T_PRIVATE:
        case T_ABSTRACT:
        case T_FINAL:
        case T_VAR:
        case T_FUNCTION:

          $infos[$infoIndex] = array(
            'type' => NULL,
            'tokenStart' => $tokenIndex,
            'tokenEnd' => NULL,
            'lineStart' => $tokenLine,
            'lineEnd' => NULL,
            'name' => NULL,
          );

          $memberContext = NULL;
          $methodBodyStarted = FALSE;

          SCANNER_CLASS_BODY_MEMBER_TOP:

          if ($memberContext === 'method') {
            switch ($tokenContent) {
              case '{':
                $methodBodyStarted = TRUE;
                $braceCount++;
                goto SCANNER_CLASS_BODY_MEMBER_CONTINUE;
              //goto no break needed
              case '}':
                $braceCount--;
                goto SCANNER_CLASS_BODY_MEMBER_CONTINUE;
            }
          }

          if ($memberContext !== NULL) {
            if (
              ($memberContext === 'property' && $tokenContent === ';')
              || ($memberContext === 'method' && $methodBodyStarted && $braceCount === 1)
              || ($memberContext === 'method' && $this->isInterface && $tokenContent === ';')
            ) {
              goto SCANNER_CLASS_BODY_MEMBER_END;
            }
          }

          switch ($tokenType) {

            case T_CONST:
              $memberContext = 'constant';
              $infos[$infoIndex]['type'] = 'constant';
              goto SCANNER_CLASS_BODY_CONST_CONTINUE;
            //goto no break needed

            case T_VARIABLE:
              if ($memberContext === NULL) {
                $memberContext = 'property';
                $infos[$infoIndex]['type'] = 'property';
                $infos[$infoIndex]['name'] = ltrim($tokenContent, '$');
              }
              goto SCANNER_CLASS_BODY_MEMBER_CONTINUE;
            //goto no break needed

            case T_FUNCTION:
              $memberContext = 'method';
              $infos[$infoIndex]['type'] = 'method';
              goto SCANNER_CLASS_BODY_MEMBER_CONTINUE;
            //goto no break needed

            case T_STRING:
              if ($memberContext === 'method' && NULL === $infos[$infoIndex]['name']) {
                $infos[$infoIndex]['name'] = $tokenContent;
              }
              goto SCANNER_CLASS_BODY_MEMBER_CONTINUE;
            //goto no break needed
          }

          SCANNER_CLASS_BODY_MEMBER_CONTINUE:

          if ($MACRO_TOKEN_ADVANCE() === FALSE) {
            goto SCANNER_END;
          }
          goto SCANNER_CLASS_BODY_MEMBER_TOP;

          SCANNER_CLASS_BODY_MEMBER_END:

          $memberContext = NULL;
          $MACRO_INFO_ADVANCE();
          goto SCANNER_CLASS_BODY_CONTINUE;
        //goto no break needed

        case NULL: // no type, is a string

          switch ($tokenContent) {
            case '{':
              $braceCount++;
              goto SCANNER_CLASS_BODY_CONTINUE;
            //fall-through
            case '}':
              $braceCount--;
              goto SCANNER_CLASS_BODY_CONTINUE;
          }
      }

      SCANNER_CLASS_BODY_CONTINUE:

      if ($braceCount === 0 || $MACRO_TOKEN_ADVANCE() === FALSE) {
        goto SCANNER_CONTINUE;
      }
      goto SCANNER_CLASS_BODY_TOP;

      SCANNER_CLASS_BODY_END:

      goto SCANNER_CONTINUE;
    }

    SCANNER_CONTINUE:

    if ($tokenContent === '}') {
      $this->lineEnd = $tokenLine;
    }

    if ($MACRO_TOKEN_ADVANCE() === FALSE) {
      goto SCANNER_END;
    }
    goto SCANNER_TOP;

    SCANNER_END:

    // process short names
    if ($this->nameInformation) {
      if ($this->shortParentClass) {
        $this->parentClass = $this->nameInformation->resolveName($this->shortParentClass);
      }
      if ($this->shortInterfaces) {
        foreach ($this->shortInterfaces as $siIndex => $si) {
          $this->interfaces[$siIndex] = $this->nameInformation->resolveName($si);
        }
      }
    }
    else {
      $this->parentClass = $this->shortParentClass;
      $this->interfaces = $this->shortInterfaces;
    }

    $this->isScanned = TRUE;

    return;
  }
}
