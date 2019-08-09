<?php

/**
 * @file
 * Contains FeedsExXml.
 */

/**
 * Parses XML documents with XPath.
 */
class VUImportsFeedsExXml extends FeedsExXml {

  /**
   * {@inheritdoc}
   */
  protected function executeSources($row, array $expressions, array $variable_map) {
    $item = [];
    $variables = [];

    foreach ($expressions as $machine_name => $expression) {
      // Variable substitution.
      $expression = strtr($expression, $variables);

      $result = $this->executeSourceExpression($machine_name, $expression, $row);

      if (!empty($this->config['sources'][$machine_name]['debug'])) {
        $this->debug($result, $machine_name);
      }

      $item[$machine_name] = $result;
      $variables[$variable_map[$machine_name]] = is_array($result) ? reset($result) : $result;
    }

    return $item;
  }

  /**
   * {@inheritdoc}
   */
  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $element_key) {
    switch ($element_key) {
      case 'parent:uid':
        if ($source->feed_nid && $node = node_load($source->feed_nid)) {
          return $node->uid;
        }
        break;

      case 'parent:nid':
        return $source->feed_nid;
    }

    $item = $result->currentItem();
    return isset($item[$element_key]) ? $item[$element_key] : NULL;
  }

}
