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

namespace Zend\Console\RouteMatcher;

use Zend\Console\Exception;
use Zend\Validator\ValidatorInterface;
use Zend\Filter\FilterInterface;

class DefaultRouteMatcher implements RouteMatcherInterface {
  /**
   * Parts of the route.
   *
   * @var array
   */
  protected $parts;

  /**
   * Default values.
   *
   * @var array
   */
  protected $defaults;

  /**
   * Parameters' name aliases.
   *
   * @var array
   */
  protected $aliases;

  /**
   * @var ValidatorInterface[]
   */
  protected $validators = array();

  /**
   * @var FilterInterface[]
   */
  protected $filters = array();

  /**
   * Class constructor
   *
   * @param string $route
   * @param array $constraints
   * @param array $defaults
   * @param array $aliases
   * @param array $filters
   * @param ValidatorInterface[] $validators
   *
   * @throws Exception\InvalidArgumentException
   */
  public function __construct(
    $route,
    array $constraints = array(),
    array $defaults = array(),
    array $aliases = array(),
    array $filters = NULL,
    array $validators = NULL
  ) {
    $this->defaults = $defaults;
    $this->constraints = $constraints;
    $this->aliases = $aliases;

    if ($filters !== NULL) {
      foreach ($filters as $name => $filter) {
        if (!$filter instanceof FilterInterface) {
          throw new Exception\InvalidArgumentException('Cannot use ' . gettype($filters) . ' as filter for ' . __CLASS__);
        }
        $this->filters[$name] = $filter;
      }
    }

    if ($validators !== NULL) {
      foreach ($validators as $name => $validator) {
        if (!$validator instanceof ValidatorInterface) {
          throw new Exception\InvalidArgumentException('Cannot use ' . gettype($validator) . ' as validator for ' . __CLASS__);
        }
        $this->validators[$name] = $validator;
      }
    }

    $this->parts = $this->parseDefinition($route);
  }

  /**
   * Parse a route definition.
   *
   * @param  string $def
   *
   * @return array
   * @throws Exception\InvalidArgumentException
   */
  protected function parseDefinition($def) {
    $def = trim($def);
    $pos = 0;
    $length = strlen($def);
    $parts = array();
    $unnamedGroupCounter = 1;

    while ($pos < $length) {
      /**
       * Optional value param, i.e.
       *    [SOMETHING]
       */
      if (preg_match('/\G\[(?P<name>[A-Z][A-Z0-9\_\-]*?)\](?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => strtolower($m['name']),
          'literal' => FALSE,
          'required' => FALSE,
          'positional' => TRUE,
          'hasValue' => TRUE,
        );
      }
      /**
       * Mandatory value param, i.e.
       *   SOMETHING
       */
      elseif (preg_match('/\G(?P<name>[A-Z][A-Z0-9\_\-]*?)(?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => strtolower($m['name']),
          'literal' => FALSE,
          'required' => TRUE,
          'positional' => TRUE,
          'hasValue' => TRUE,
        );
      }
      /**
       * Optional literal param, i.e.
       *    [something]
       */
      elseif (preg_match('/\G\[ *?(?P<name>[a-zA-Z][a-zA-Z0-9\_\-]*?) *?\](?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'literal' => TRUE,
          'required' => FALSE,
          'positional' => TRUE,
          'hasValue' => FALSE,
        );
      }
      /**
       * Optional value param, syntax 2, i.e.
       *    [<something>]
       */
      elseif (preg_match('/\G\[ *\<(?P<name>[a-zA-Z][a-zA-Z0-9\_\-]*?)\> *\](?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'literal' => FALSE,
          'required' => FALSE,
          'positional' => TRUE,
          'hasValue' => TRUE,
        );
      }
      /**
       * Mandatory value param, i.e.
       *    <something>
       */
      elseif (preg_match('/\G\< *(?P<name>[a-zA-Z][a-zA-Z0-9\_\-]*?) *\>(?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'literal' => FALSE,
          'required' => TRUE,
          'positional' => TRUE,
          'hasValue' => TRUE,
        );
      }
      /**
       * Mandatory literal param, i.e.
       *   something
       */
      elseif (preg_match('/\G(?P<name>[a-zA-Z][a-zA-Z0-9\_\-]*?)(?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'literal' => TRUE,
          'required' => TRUE,
          'positional' => TRUE,
          'hasValue' => FALSE,
        );
      }
      /**
       * Mandatory long param
       *    --param=
       *    --param=whatever
       */
      elseif (preg_match('/\G--(?P<name>[a-zA-Z0-9][a-zA-Z0-9\_\-]+)(?P<hasValue>=\S*?)?(?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'short' => FALSE,
          'literal' => FALSE,
          'required' => TRUE,
          'positional' => FALSE,
          'hasValue' => !empty($m['hasValue']),
        );
      }
      /**
       * Optional long flag
       *    [--param]
       */
      elseif (preg_match(
        '/\G\[ *?--(?P<name>[a-zA-Z0-9][a-zA-Z0-9\_\-]+) *?\](?: +|$)/s', $def, $m, 0, $pos
      )) {
        $item = array(
          'name' => $m['name'],
          'short' => FALSE,
          'literal' => FALSE,
          'required' => FALSE,
          'positional' => FALSE,
          'hasValue' => FALSE,
        );
      }
      /**
       * Optional long param
       *    [--param=]
       *    [--param=whatever]
       */
      elseif (preg_match(
        '/\G\[ *?--(?P<name>[a-zA-Z0-9][a-zA-Z0-9\_\-]+)(?P<hasValue>=\S*?)? *?\](?: +|$)/s', $def, $m, 0, $pos
      )) {
        $item = array(
          'name' => $m['name'],
          'short' => FALSE,
          'literal' => FALSE,
          'required' => FALSE,
          'positional' => FALSE,
          'hasValue' => !empty($m['hasValue']),
        );
      }
      /**
       * Mandatory short param
       *    -a
       *    -a=i
       *    -a=s
       *    -a=w
       */
      elseif (preg_match('/\G-(?P<name>[a-zA-Z0-9])(?:=(?P<type>[ns]))?(?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'short' => TRUE,
          'literal' => FALSE,
          'required' => TRUE,
          'positional' => FALSE,
          'hasValue' => !empty($m['type']) ? $m['type'] : NULL,
        );
      }
      /**
       * Optional short param
       *    [-a]
       *    [-a=n]
       *    [-a=s]
       */
      elseif (preg_match('/\G\[ *?-(?P<name>[a-zA-Z0-9])(?:=(?P<type>[ns]))? *?\](?: +|$)/s', $def, $m, 0, $pos)) {
        $item = array(
          'name' => $m['name'],
          'short' => TRUE,
          'literal' => FALSE,
          'required' => FALSE,
          'positional' => FALSE,
          'hasValue' => !empty($m['type']) ? $m['type'] : NULL,
        );
      }
      /**
       * Optional literal param alternative
       *    [ something | somethingElse | anotherOne ]
       *    [ something | somethingElse | anotherOne ]:namedGroup
       */
      elseif (preg_match('/
                \G
                \[
                    (?P<options>
                        (?:
                            \ *?
                            (?P<name>[a-zA-Z][a-zA-Z0-9_\-]*?)
                            \ *?
                            (?:\||(?=\]))
                            \ *?
                        )+
                    )
                \]
                (?:\:(?P<groupName>[a-zA-Z0-9]+))?
                (?:\ +|$)
                /sx', $def, $m, 0, $pos
      )
      ) {
        // extract available options
        $options = preg_split('/ *\| */', trim($m['options']), 0, PREG_SPLIT_NO_EMPTY);

        // remove dupes
        array_unique($options);

        // prepare item
        $item = array(
          'name' => isset($m['groupName']) ? $m['groupName'] : 'unnamedGroup' . $unnamedGroupCounter++,
          'literal' => TRUE,
          'required' => FALSE,
          'positional' => TRUE,
          'alternatives' => $options,
          'hasValue' => FALSE,
        );
      }

      /**
       * Required literal param alternative
       *    ( something | somethingElse | anotherOne )
       *    ( something | somethingElse | anotherOne ):namedGroup
       */
      elseif (preg_match('/
                \G
                \(
                    (?P<options>
                        (?:
                            \ *?
                            (?P<name>[a-zA-Z][a-zA-Z0-9_\-]+)
                            \ *?
                            (?:\||(?=\)))
                            \ *?
                        )+
                    )
                \)
                (?:\:(?P<groupName>[a-zA-Z0-9]+))?
                (?:\ +|$)
                /sx', $def, $m, 0, $pos
      )) {
        // extract available options
        $options = preg_split('/ *\| */', trim($m['options']), 0, PREG_SPLIT_NO_EMPTY);

        // remove dupes
        array_unique($options);

        // prepare item
        $item = array(
          'name' => isset($m['groupName']) ? $m['groupName'] : 'unnamedGroupAt' . $unnamedGroupCounter++,
          'literal' => TRUE,
          'required' => TRUE,
          'positional' => TRUE,
          'alternatives' => $options,
          'hasValue' => FALSE,
        );
      }
      /**
       * Required long/short flag alternative
       *    ( --something | --somethingElse | --anotherOne | -s | -a )
       *    ( --something | --somethingElse | --anotherOne | -s | -a ):namedGroup
       */
      elseif (preg_match('/
                \G
                \(
                    (?P<options>
                        (?:
                            \ *?
                            \-+(?P<name>[a-zA-Z0-9][a-zA-Z0-9_\-]*?)
                            \ *?
                            (?:\||(?=\)))
                            \ *?
                        )+
                    )
                \)
                (?:\:(?P<groupName>[a-zA-Z0-9]+))?
                (?:\ +|$)
                /sx', $def, $m, 0, $pos
      )) {
        // extract available options
        $options = preg_split('/ *\| */', trim($m['options']), 0, PREG_SPLIT_NO_EMPTY);

        // remove dupes
        array_unique($options);

        // remove prefix
        array_walk($options, function (&$val, $key) {
          $val = ltrim($val, '-');
        });

        // prepare item
        $item = array(
          'name' => isset($m['groupName']) ? $m['groupName'] : 'unnamedGroupAt' . $unnamedGroupCounter++,
          'literal' => FALSE,
          'required' => TRUE,
          'positional' => FALSE,
          'alternatives' => $options,
          'hasValue' => FALSE,
        );
      }
      /**
       * Optional flag alternative
       *    [ --something | --somethingElse | --anotherOne | -s | -a ]
       *    [ --something | --somethingElse | --anotherOne | -s | -a ]:namedGroup
       */
      elseif (preg_match('/
                \G
                \[
                    (?P<options>
                        (?:
                            \ *?
                            \-+(?P<name>[a-zA-Z0-9][a-zA-Z0-9_\-]*?)
                            \ *?
                            (?:\||(?=\]))
                            \ *?
                        )+
                    )
                \]
                (?:\:(?P<groupName>[a-zA-Z0-9]+))?
                (?:\ +|$)
                /sx', $def, $m, 0, $pos
      )) {
        // extract available options
        $options = preg_split('/ *\| */', trim($m['options']), 0, PREG_SPLIT_NO_EMPTY);

        // remove dupes
        array_unique($options);

        // remove prefix
        array_walk($options, function (&$val, $key) {
          $val = ltrim($val, '-');
        });

        // prepare item
        $item = array(
          'name' => isset($m['groupName']) ? $m['groupName'] : 'unnamedGroupAt' . $unnamedGroupCounter++,
          'literal' => FALSE,
          'required' => FALSE,
          'positional' => FALSE,
          'alternatives' => $options,
          'hasValue' => FALSE,
        );
      }
      else {
        throw new Exception\InvalidArgumentException(
          'Cannot understand Console route at "' . substr($def, $pos) . '"'
        );
      }

      $pos += strlen($m[0]);
      $parts[] = $item;
    }

    return $parts;
  }

  /**
   * Returns list of names representing single parameter
   *
   * @param string $name
   *
   * @return string
   */
  private function getAliases($name) {
    $namesToMatch = array($name);
    foreach ($this->aliases as $alias => $canonical) {
      if ($name == $canonical) {
        $namesToMatch[] = $alias;
      }
    }
    return $namesToMatch;
  }

  /**
   * Returns canonical name of a parameter
   *
   * @param string $name
   *
   * @return string
   */
  private function getCanonicalName($name) {
    if (isset($this->aliases[$name])) {
      return $this->aliases[$name];
    }
    return $name;
  }

  /**
   * Match parameters against route passed to constructor
   *
   * @param array $params
   *
   * @return array|null
   */
  public function match($params) {
    $matches = array();

    /*
     * Extract positional and named parts
     */
    $positional = $named = array();
    foreach ($this->parts as &$part) {
      if ($part['positional']) {
        $positional[] = &$part;
      }
      else {
        $named[] = &$part;
      }
    }

    /*
     * Scan for named parts inside Console params
     */
    foreach ($named as &$part) {
      /*
       * Prepare match regex
       */
      if (isset($part['alternatives'])) {
        // an alternative of flags
        $regex = '/^\-+(?P<name>';

        $alternativeAliases = array();
        foreach ($part['alternatives'] as $alternative) {
          $alternativeAliases[] = '(?:' . implode('|', $this->getAliases($alternative)) . ')';
        }

        $regex .= join('|', $alternativeAliases);

        if ($part['hasValue']) {
          $regex .= ')(?:\=(?P<value>.*?)$)?$/';
        }
        else {
          $regex .= ')$/i';
        }
      }
      else {
        // a single named flag
        $name = '(?:' . implode('|', $this->getAliases($part['name'])) . ')';

        if ($part['short'] === TRUE) {
          // short variant
          if ($part['hasValue']) {
            $regex = '/^\-' . $name . '(?:\=(?P<value>.*?)$)?$/i';
          }
          else {
            $regex = '/^\-' . $name . '$/i';
          }
        }
        elseif ($part['short'] === FALSE) {
          // long variant
          if ($part['hasValue']) {
            $regex = '/^\-{2,}' . $name . '(?:\=(?P<value>.*?)$)?$/i';
          }
          else {
            $regex = '/^\-{2,}' . $name . '$/i';
          }
        }
      }

      /*
       * Look for param
       */
      $value = $param = NULL;
      for ($x = 0, $count = count($params); $x < $count; $x++) {
        if (preg_match($regex, $params[$x], $m)) {
          // found param
          $param = $params[$x];

          // prevent further scanning of this param
          array_splice($params, $x, 1);

          if (isset($m['value'])) {
            $value = $m['value'];
          }

          if (isset($m['name'])) {
            $matchedName = $this->getCanonicalName($m['name']);
          }

          break;
        }
      }

      if (!$param) {
        /*
         * Drop out if that was a mandatory param
         */
        if ($part['required']) {
          return NULL;
        }

        /*
         * Continue to next positional param
         */
        else {
          continue;
        }
      }

      /*
       * Value for flags is always boolean
       */
      if ($param && !$part['hasValue']) {
        $value = TRUE;
      }

      /*
       * Try to retrieve value if it is expected
       */
      if ((NULL === $value || "" === $value) && $part['hasValue']) {
        if ($x < count($params) + 1 && isset($params[$x])) {
          // retrieve value from adjacent param
          $value = $params[$x];

          // prevent further scanning of this param
          array_splice($params, $x, 1);
        }
        else {
          // there are no more params available
          return NULL;
        }
      }

      /*
       * Validate the value against constraints
       */
      if ($part['hasValue'] && isset($this->constraints[$part['name']])) {
        if (
        !preg_match($this->constraints[$part['name']], $value)
        ) {
          // constraint failed
          return NULL;
        }
      }

      /*
       * Store the value
       */
      if ($part['hasValue']) {
        $matches[$part['name']] = $value;
      }
      else {
        $matches[$part['name']] = TRUE;
      }

      /*
       * If there are alternatives, fill them
       */
      if (isset($part['alternatives'])) {
        if ($part['hasValue']) {
          foreach ($part['alternatives'] as $alt) {
            if ($alt === $matchedName && !isset($matches[$alt])) {
              $matches[$alt] = $value;
            }
            elseif (!isset($matches[$alt])) {
              $matches[$alt] = NULL;
            }
          }
        }
        else {
          foreach ($part['alternatives'] as $alt) {
            if ($alt === $matchedName && !isset($matches[$alt])) {
              $matches[$alt] = isset($this->defaults[$alt]) ? $this->defaults[$alt] : TRUE;
            }
            elseif (!isset($matches[$alt])) {
              $matches[$alt] = FALSE;
            }
          }
        }
      }
    }

    /*
     * Scan for left-out flags that should result in a mismatch
     */
    foreach ($params as $param) {
      if (preg_match('#^\-+#', $param)) {
        return NULL; // there is an unrecognized flag
      }
    }

    /*
     * Go through all positional params
     */
    $argPos = 0;
    foreach ($positional as &$part) {
      /*
       * Check if param exists
       */
      if (!isset($params[$argPos])) {
        if ($part['required']) {
          // cannot find required positional param
          return NULL;
        }
        else {
          // stop matching
          break;
        }
      }

      $value = $params[$argPos];

      /*
       * Check if literal param matches
       */
      if ($part['literal']) {
        if (
          (isset($part['alternatives']) && !in_array($value, $part['alternatives'])) ||
          (!isset($part['alternatives']) && $value != $part['name'])
        ) {
          return NULL;
        }
      }

      /*
       * Validate the value against constraints
       */
      if ($part['hasValue'] && isset($this->constraints[$part['name']])) {
        if (
        !preg_match($this->constraints[$part['name']], $value)
        ) {
          // constraint failed
          return NULL;
        }
      }

      /*
       * Store the value
       */
      if ($part['hasValue']) {
        $matches[$part['name']] = $value;
      }
      elseif (isset($part['alternatives'])) {
        // from all alternatives set matching parameter to TRUE and the rest to FALSE
        foreach ($part['alternatives'] as $alt) {
          if ($alt == $value) {
            $matches[$alt] = isset($this->defaults[$alt]) ? $this->defaults[$alt] : TRUE;
          }
          else {
            $matches[$alt] = FALSE;
          }
        }

        // set alternatives group value
        $matches[$part['name']] = $value;
      }
      elseif (!$part['required']) {
        // set optional parameter flag
        $name = $part['name'];
        $matches[$name] = isset($this->defaults[$name]) ? $this->defaults[$name] : TRUE;
      }

      /*
       * Advance to next argument
       */
      $argPos++;
    }

    /*
     * Check if we have consumed all positional parameters
     */
    if ($argPos < count($params)) {
      return NULL; // there are extraneous params that were not consumed
    }

    /*
     * Any optional flags that were not entered have value false
     */
    foreach ($this->parts as &$part) {
      if (!$part['required'] && !$part['hasValue']) {
        if (!isset($matches[$part['name']])) {
          $matches[$part['name']] = FALSE;
        }
        // unset alternatives also should be false
        if (isset($part['alternatives'])) {
          foreach ($part['alternatives'] as $alt) {
            if (!isset($matches[$alt])) {
              $matches[$alt] = FALSE;
            }
          }
        }
      }
    }

    // run filters
    foreach ($matches as $name => $value) {
      if (isset($this->filters[$name])) {
        $matches[$name] = $this->filters[$name]->filter($value);
      }
    }

    // run validators
    $valid = TRUE;
    foreach ($matches as $name => $value) {
      if (isset($this->validators[$name])) {
        $valid &= $this->validators[$name]->isValid($value);
      }
    }

    if (!$valid) {
      return NULL;
    }

    return array_replace($this->defaults, $matches);
  }
}
