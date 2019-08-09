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

namespace Zend\Dom;

use DOMDocument;

/**
 * Class used to initialize DomDocument from string, with proper verifications
 */
class Document {
  /**#@+
   * Document types
   */
  const DOC_HTML = 'DOC_HTML';
  const DOC_XHTML = 'DOC_XHTML';
  const DOC_XML = 'DOC_XML';
  /**#@-*/

  /**
   * Raw document
   *
   * @var string
   */
  protected $stringDocument;

  /**
   * DOMDocument generated from raw string document
   *
   * @var DOMDocument
   */
  protected $domDocument;

  /**
   * Type of the document provided
   *
   * @var string
   */
  protected $type;

  /**
   * Error list generated from transformation of document to DOMDocument
   *
   * @var array
   */
  protected $errors = array();

  /**
   * XPath namespaces
   *
   * @var array
   */
  protected $xpathNamespaces = array();

  /**
   * XPath PHP Functions
   *
   * @var mixed
   */
  protected $xpathPhpFunctions;

  /**
   * Constructor
   *
   * @param string|null $document String containing the document
   * @param string|null $type Force the document to be of a certain type,
   *   bypassing setStringDocument's detection
   * @param string|null $encoding Encoding for the document (used for
   *   DOMDocument generation)
   */
  public function __construct($document = NULL, $type = NULL, $encoding = NULL) {
    $this->setStringDocument($document, $type, $encoding);
  }

  /**
   * Get raw set document
   *
   * @return string|null
   */
  public function getStringDocument() {
    return $this->stringDocument;
  }

  /**
   * Set raw document
   *
   * @param string|null $document
   * @param string|null $forcedType Type for the provided document (see
   *   constants)
   * @param string|null $forcedEncoding Encoding for the provided document
   *
   * @return self
   */
  protected function setStringDocument($document, $forcedType = NULL, $forcedEncoding = NULL) {
    $type = static::DOC_HTML;
    if (strstr($document, 'DTD XHTML')) {
      $type = static::DOC_XHTML;
    }

    // Breaking XML declaration to make syntax highlighting work
    if ('<' . '?xml' == substr(trim($document), 0, 5)) {
      $type = static::DOC_XML;
      if (preg_match('/<html[^>]*xmlns="([^"]+)"[^>]*>/i', $document, $matches)) {
        $this->xpathNamespaces[] = $matches[1];
        $type = static::DOC_XHTML;
      }
    }

    // Unsetting previously registered DOMDocument
    $this->domDocument = NULL;
    $this->stringDocument = !empty($document) ? $document : NULL;

    $this->setType($forcedType ?: (!empty($document) ? $type : NULL));
    $this->setEncoding($forcedEncoding);
    $this->setErrors(array());

    return $this;
  }

  /**
   * Get raw document type
   *
   * @return string|null
   */
  public function getType() {
    return $this->type;
  }

  /**
   * Set raw document type
   *
   * @param  string $type
   *
   * @return self
   */
  protected function setType($type) {
    $this->type = $type;

    return $this;
  }

  /**
   * Get DOMDocument generated from set raw document
   *
   * @return DOMDocument
   * @throws Exception\RuntimeException If cannot get DOMDocument; no document
   *   registered
   */
  public function getDomDocument() {
    if (NULL === ($stringDocument = $this->getStringDocument())) {
      throw new Exception\RuntimeException('Cannot get DOMDocument; no document registered');
    }

    if (NULL === $this->domDocument) {
      $this->domDocument = $this->getDomDocumentFromString($stringDocument);
    }

    return $this->domDocument;
  }

  /**
   * Set DOMDocument
   *
   * @param  DOMDocument $domDocument
   *
   * @return self
   */
  protected function setDomDocument(DOMDocument $domDocument) {
    $this->domDocument = $domDocument;

    return $this;
  }

  /**
   * Get set document encoding
   *
   * @return string|null
   */
  public function getEncoding() {
    return $this->encoding;
  }

  /**
   * Set raw document encoding for DOMDocument generation
   *
   * @param  string|null $encoding
   *
   * @return self
   */
  public function setEncoding($encoding) {
    $this->encoding = $encoding;

    return $this->encoding;
  }

  /**
   * Get DOMDocument generation errors
   *
   * @return array
   */
  public function getErrors() {
    return $this->errors;
  }

  /**
   * Set document errors from DOMDocument generation
   *
   * @param  array $errors
   *
   * @return self
   */
  protected function setErrors($errors) {
    $this->errors = $errors;

    return $this;
  }

  /**
   * Get DOMDocument from set raw document
   *
   * @return DOMDocument
   * @throws Exception\RuntimeException
   */
  protected function getDomDocumentFromString($stringDocument) {
    libxml_use_internal_errors(TRUE);
    libxml_disable_entity_loader(TRUE);

    $encoding = $this->getEncoding();
    $domDoc = NULL === $encoding ? new DOMDocument('1.0') : new DOMDocument('1.0', $encoding);
    $type = $this->getType();

    switch ($type) {
      case static::DOC_XML:
        $success = $domDoc->loadXML($stringDocument);
        foreach ($domDoc->childNodes as $child) {
          if ($child->nodeType === XML_DOCUMENT_TYPE_NODE) {
            throw new Exception\RuntimeException(
              'Invalid XML: Detected use of illegal DOCTYPE'
            );
          }
        }
        break;
      case static::DOC_HTML:
      case static::DOC_XHTML:
      default:
        $success = $domDoc->loadHTML($stringDocument);
        break;
    }

    $errors = libxml_get_errors();
    if (!empty($errors)) {
      $this->setErrors($errors);
      libxml_clear_errors();
    }

    libxml_disable_entity_loader(FALSE);
    libxml_use_internal_errors(FALSE);

    if (!$success) {
      throw new Exception\RuntimeException(sprintf('Error parsing document (type == %s)', $type));
    }

    return $domDoc;
  }

  /**
   * Get Document's registered XPath namespaces
   *
   * @return array
   */
  public function getXpathNamespaces() {
    return $this->xpathNamespaces;
  }

  /**
   * Register XPath namespaces
   *
   * @param  array $xpathNamespaces
   *
   * @return void
   */
  public function registerXpathNamespaces($xpathNamespaces) {
    $this->xpathNamespaces = $xpathNamespaces;
  }


  /**
   * Get Document's registered XPath PHP Functions
   *
   * @return string|null
   */
  public function getXpathPhpFunctions() {
    return $this->xpathPhpFunctions;
  }

  /**
   * Register PHP Functions to use in internal DOMXPath
   *
   * @param  bool $xpathPhpFunctions
   *
   * @return void
   */
  public function registerXpathPhpFunctions($xpathPhpFunctions = TRUE) {
    $this->xpathPhpFunctions = $xpathPhpFunctions;
  }
}
