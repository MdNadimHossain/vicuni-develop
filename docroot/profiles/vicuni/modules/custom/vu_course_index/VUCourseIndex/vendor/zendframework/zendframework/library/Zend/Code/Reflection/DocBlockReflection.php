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

namespace Zend\Code\Reflection;

use Reflector;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as DocBlockTagInterface;
use Zend\Code\Reflection\DocBlock\TagManager as DocBlockTagManager;
use Zend\Code\Scanner\DocBlockScanner;

class DocBlockReflection implements ReflectionInterface {
  /**
   * @var Reflector
   */
  protected $reflector = NULL;

  /**
   * @var string
   */
  protected $docComment = NULL;

  /**
   * @var DocBlockTagManager
   */
  protected $tagManager = NULL;

  /**#@+
   * @var int
   */
  protected $startLine = NULL;
  protected $endLine = NULL;
  /**#@-*/

  /**
   * @var string
   */
  protected $cleanDocComment = NULL;

  /**
   * @var string
   */
  protected $longDescription = NULL;

  /**
   * @var string
   */
  protected $shortDescription = NULL;

  /**
   * @var array
   */
  protected $tags = array();

  /**
   * @var bool
   */
  protected $isReflected = FALSE;

  /**
   * Export reflection
   *
   * Required by the Reflector interface.
   *
   * @todo   What should this do?
   * @return void
   */
  public static function export() {
  }

  /**
   * @param  Reflector|string $commentOrReflector
   * @param  null|DocBlockTagManager $tagManager
   *
   * @throws Exception\InvalidArgumentException
   * @return DocBlockReflection
   */
  public function __construct($commentOrReflector, DocBlockTagManager $tagManager = NULL) {
    if (!$tagManager) {
      $tagManager = new DocBlockTagManager();
      $tagManager->initializeDefaultTags();
    }
    $this->tagManager = $tagManager;

    if ($commentOrReflector instanceof Reflector) {
      $this->reflector = $commentOrReflector;
      if (!method_exists($commentOrReflector, 'getDocComment')) {
        throw new Exception\InvalidArgumentException('Reflector must contain method "getDocComment"');
      }
      /* @var MethodReflection $commentOrReflector */
      $this->docComment = $commentOrReflector->getDocComment();

      // determine line numbers
      $lineCount = substr_count($this->docComment, "\n");
      $this->startLine = $this->reflector->getStartLine() - $lineCount - 1;
      $this->endLine = $this->reflector->getStartLine() - 1;
    }
    elseif (is_string($commentOrReflector)) {
      $this->docComment = $commentOrReflector;
    }
    else {
      throw new Exception\InvalidArgumentException(sprintf(
        '%s must have a (string) DocComment or a Reflector in the constructor',
        get_class($this)
      ));
    }

    if ($this->docComment == '') {
      throw new Exception\InvalidArgumentException('DocComment cannot be empty');
    }

    $this->reflect();
  }

  /**
   * Retrieve contents of DocBlock
   *
   * @return string
   */
  public function getContents() {
    $this->reflect();

    return $this->cleanDocComment;
  }

  /**
   * Get start line (position) of DocBlock
   *
   * @return int
   */
  public function getStartLine() {
    $this->reflect();

    return $this->startLine;
  }

  /**
   * Get last line (position) of DocBlock
   *
   * @return int
   */
  public function getEndLine() {
    $this->reflect();

    return $this->endLine;
  }

  /**
   * Get DocBlock short description
   *
   * @return string
   */
  public function getShortDescription() {
    $this->reflect();

    return $this->shortDescription;
  }

  /**
   * Get DocBlock long description
   *
   * @return string
   */
  public function getLongDescription() {
    $this->reflect();

    return $this->longDescription;
  }

  /**
   * Does the DocBlock contain the given annotation tag?
   *
   * @param  string $name
   *
   * @return bool
   */
  public function hasTag($name) {
    $this->reflect();
    foreach ($this->tags as $tag) {
      if ($tag->getName() == $name) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Retrieve the given DocBlock tag
   *
   * @param  string $name
   *
   * @return DocBlockTagInterface|false
   */
  public function getTag($name) {
    $this->reflect();
    foreach ($this->tags as $tag) {
      if ($tag->getName() == $name) {
        return $tag;
      }
    }

    return FALSE;
  }

  /**
   * Get all DocBlock annotation tags
   *
   * @param  string $filter
   *
   * @return DocBlockTagInterface[]
   */
  public function getTags($filter = NULL) {
    $this->reflect();
    if ($filter === NULL || !is_string($filter)) {
      return $this->tags;
    }

    $returnTags = array();
    foreach ($this->tags as $tag) {
      if ($tag->getName() == $filter) {
        $returnTags[] = $tag;
      }
    }

    return $returnTags;
  }

  /**
   * Parse the DocBlock
   *
   * @return void
   */
  protected function reflect() {
    if ($this->isReflected) {
      return;
    }

    $docComment = $this->docComment; // localize variable

    // create a clean docComment
    $this->cleanDocComment = preg_replace("#[ \t]*(?:/\*\*|\*/|\*)[ ]{0,1}(.*)?#", '$1', $docComment);
    $this->cleanDocComment = ltrim($this->cleanDocComment, "\r\n"); // @todo should be changed to remove first and last empty line

    $scanner = new DocBlockScanner($docComment);
    $this->shortDescription = ltrim($scanner->getShortDescription());
    $this->longDescription = ltrim($scanner->getLongDescription());

    foreach ($scanner->getTags() as $tag) {
      $this->tags[] = $this->tagManager->createTag(ltrim($tag['name'], '@'), ltrim($tag['value']));
    }

    $this->isReflected = TRUE;
  }

  public function toString() {
    $str = "DocBlock [ /* DocBlock */ ] {" . PHP_EOL . PHP_EOL;
    $str .= "  - Tags [" . count($this->tags) . "] {" . PHP_EOL;

    foreach ($this->tags as $tag) {
      $str .= "    " . $tag;
    }

    $str .= "  }" . PHP_EOL;
    $str .= "}" . PHP_EOL;

    return $str;
  }

  /**
   * Serialize to string
   *
   * Required by the Reflector interface
   *
   * @return string
   */
  public function __toString() {
    return $this->toString();
  }
}
