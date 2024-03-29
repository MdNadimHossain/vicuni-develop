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
 * Query DOM structures based on CSS selectors and/or XPath
 *
 * @deprecated
 * @see \Zend\Dom\Document\Query
 */
class Query {
  /**#@+
   * Document types
   */
  const DOC_XML = 'docXml';
  const DOC_HTML = 'docHtml';
  const DOC_XHTML = 'docXhtml';
  /**#@-*/

  /**
   * @var string
   */
  protected $document;

  /**
   * DOMDocument errors, if any
   *
   * @var false|array
   */
  protected $documentErrors = FALSE;

  /**
   * Document type
   *
   * @var string
   */
  protected $docType;

  /**
   * Document encoding
   *
   * @var null|string
   */
  protected $encoding;

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
   * @param null|string $document
   * @param null|string $encoding
   */
  public function __construct($document = NULL, $encoding = NULL) {
    $this->setEncoding($encoding);
    $this->setDocument($document);
  }

  /**
   * Set document encoding
   *
   * @param  string $encoding
   *
   * @return Query
   */
  public function setEncoding($encoding) {
    $this->encoding = (NULL === $encoding) ? NULL : (string) $encoding;
    return $this;
  }

  /**
   * Get document encoding
   *
   * @return null|string
   */
  public function getEncoding() {
    return $this->encoding;
  }

  /**
   * Set document to query
   *
   * @param  string $document
   * @param  null|string $encoding Document encoding
   *
   * @return Query
   */
  public function setDocument($document, $encoding = NULL) {
    if (0 === strlen($document)) {
      return $this;
    }
    // breaking XML declaration to make syntax highlighting work
    if ('<' . '?xml' == substr(trim($document), 0, 5)) {
      if (preg_match('/<html[^>]*xmlns="([^"]+)"[^>]*>/i', $document, $matches)) {
        $this->xpathNamespaces[] = $matches[1];
        return $this->setDocumentXhtml($document, $encoding);
      }
      return $this->setDocumentXml($document, $encoding);
    }
    if (strstr($document, 'DTD XHTML')) {
      return $this->setDocumentXhtml($document, $encoding);
    }
    return $this->setDocumentHtml($document, $encoding);
  }

  /**
   * Register HTML document
   *
   * @param  string $document
   * @param  null|string $encoding Document encoding
   *
   * @return Query
   */
  public function setDocumentHtml($document, $encoding = NULL) {
    $this->document = (string) $document;
    $this->docType = self::DOC_HTML;
    if (NULL !== $encoding) {
      $this->setEncoding($encoding);
    }
    return $this;
  }

  /**
   * Register XHTML document
   *
   * @param  string $document
   * @param  null|string $encoding Document encoding
   *
   * @return Query
   */
  public function setDocumentXhtml($document, $encoding = NULL) {
    $this->document = (string) $document;
    $this->docType = self::DOC_XHTML;
    if (NULL !== $encoding) {
      $this->setEncoding($encoding);
    }
    return $this;
  }

  /**
   * Register XML document
   *
   * @param  string $document
   * @param  null|string $encoding Document encoding
   *
   * @return Query
   */
  public function setDocumentXml($document, $encoding = NULL) {
    $this->document = (string) $document;
    $this->docType = self::DOC_XML;
    if (NULL !== $encoding) {
      $this->setEncoding($encoding);
    }
    return $this;
  }

  /**
   * Retrieve current document
   *
   * @return string
   */
  public function getDocument() {
    return $this->document;
  }

  /**
   * Get document type
   *
   * @return string
   */
  public function getDocumentType() {
    return $this->docType;
  }

  /**
   * Get any DOMDocument errors found
   *
   * @return false|array
   */
  public function getDocumentErrors() {
    return $this->documentErrors;
  }

  /**
   * Perform a CSS selector query
   *
   * @param  string $query
   *
   * @return NodeList
   */
  public function execute($query) {
    $xpathQuery = Document\Query::cssToXpath($query);
    return $this->queryXpath($xpathQuery, $query);
  }

  /**
   * Perform an XPath query
   *
   * @param  string|array $xpathQuery
   * @param  string|null $query CSS selector query
   *
   * @throws Exception\RuntimeException
   * @return NodeList
   */
  public function queryXpath($xpathQuery, $query = NULL) {
    if (NULL === ($document = $this->getDocument())) {
      throw new Exception\RuntimeException('Cannot query; no document registered');
    }

    $encoding = $this->getEncoding();
    libxml_use_internal_errors(TRUE);
    libxml_disable_entity_loader(TRUE);
    if (NULL === $encoding) {
      $domDoc = new DOMDocument('1.0');
    }
    else {
      $domDoc = new DOMDocument('1.0', $encoding);
    }
    $type = $this->getDocumentType();
    switch ($type) {
      case self::DOC_XML:
        $success = $domDoc->loadXML($document);
        foreach ($domDoc->childNodes as $child) {
          if ($child->nodeType === XML_DOCUMENT_TYPE_NODE) {
            throw new Exception\RuntimeException(
              'Invalid XML: Detected use of illegal DOCTYPE'
            );
          }
        }
        break;
      case self::DOC_HTML:
      case self::DOC_XHTML:
      default:
        $success = $domDoc->loadHTML($document);
        break;
    }
    $errors = libxml_get_errors();
    if (!empty($errors)) {
      $this->documentErrors = $errors;
      libxml_clear_errors();
    }
    libxml_disable_entity_loader(FALSE);
    libxml_use_internal_errors(FALSE);

    if (!$success) {
      throw new Exception\RuntimeException(sprintf('Error parsing document (type == %s)', $type));
    }

    $nodeList = $this->getNodeList($domDoc, $xpathQuery);
    return new NodeList($query, $xpathQuery, $domDoc, $nodeList);
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
   * Register PHP Functions to use in internal DOMXPath
   *
   * @param  bool $xpathPhpFunctions
   *
   * @return void
   */
  public function registerXpathPhpFunctions($xpathPhpFunctions = TRUE) {
    $this->xpathPhpFunctions = $xpathPhpFunctions;
  }

  /**
   * Prepare node list
   *
   * @param  DOMDocument $document
   * @param  string|array $xpathQuery
   *
   * @return array
   * @throws \ErrorException If query cannot be executed
   */
  protected function getNodeList($document, $xpathQuery) {
    $xpath = new DOMXPath($document);
    foreach ($this->xpathNamespaces as $prefix => $namespaceUri) {
      $xpath->registerNamespace($prefix, $namespaceUri);
    }
    if ($this->xpathPhpFunctions) {
      $xpath->registerNamespace("php", "http://php.net/xpath");
      ($this->xpathPhpFunctions === TRUE) ?
        $xpath->registerPHPFunctions()
        : $xpath->registerPHPFunctions($this->xpathPhpFunctions);
    }
    $xpathQuery = (string) $xpathQuery;

    $nodeList = $xpath->queryWithErrorException($xpathQuery);
    return $nodeList;
  }
}
