<?php
namespace CourseIndex\Entity;
/**
 *
 */
class AbstractEntity {

  /**
   *
   */
  public function __call($method, $parameters) {
    $prefix = substr($method, 0, 3);

    $var = Self::camelcase2underscore(strtolower(substr(str_replace($prefix, '', $method), 0, 1)) . substr($method, 4, strlen($method)));

    if (property_exists($this, $var)) {
      if (strcasecmp($prefix, 'set') == 0) {
        $this->$var = $parameters[0];
      }
      elseif (strcasecmp($prefix, 'get') == 0) {
        return $this->$var;
      }
    }
    else {
      // Property doesn't exist.
      throw new \Exception("Property $method does not exist");
    }
  }

  /**
   *
   */
  public static function camelcase2underscore($name) {
    return strtolower(preg_replace('/([a-z])([A-Z])/', '$1_$2', $name));
  }

}
