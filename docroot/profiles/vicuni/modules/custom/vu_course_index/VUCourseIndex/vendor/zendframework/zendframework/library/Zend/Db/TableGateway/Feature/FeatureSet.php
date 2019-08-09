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

namespace Zend\Db\TableGateway\Feature;

use Zend\Db\TableGateway\AbstractTableGateway;
use Zend\Db\TableGateway\TableGatewayInterface;

class FeatureSet {
  const APPLY_HALT = 'halt';

  protected $tableGateway = NULL;

  /**
   * @var AbstractFeature[]
   */
  protected $features = array();

  /**
   * @var array
   */
  protected $magicSpecifications = array();

  public function __construct(array $features = array()) {
    if ($features) {
      $this->addFeatures($features);
    }
  }

  public function setTableGateway(AbstractTableGateway $tableGateway) {
    $this->tableGateway = $tableGateway;
    foreach ($this->features as $feature) {
      $feature->setTableGateway($this->tableGateway);
    }
    return $this;
  }

  public function getFeatureByClassName($featureClassName) {
    $feature = FALSE;
    foreach ($this->features as $potentialFeature) {
      if ($potentialFeature instanceof $featureClassName) {
        $feature = $potentialFeature;
        break;
      }
    }
    return $feature;
  }

  public function addFeatures(array $features) {
    foreach ($features as $feature) {
      $this->addFeature($feature);
    }
    return $this;
  }

  public function addFeature(AbstractFeature $feature) {
    if ($this->tableGateway instanceof TableGatewayInterface) {
      $feature->setTableGateway($this->tableGateway);
    }
    $this->features[] = $feature;
    return $this;
  }

  public function apply($method, $args) {
    foreach ($this->features as $feature) {
      if (method_exists($feature, $method)) {
        $return = call_user_func_array(array($feature, $method), $args);
        if ($return === self::APPLY_HALT) {
          break;
        }
      }
    }
  }

  /**
   * @param string $property
   *
   * @return bool
   */
  public function canCallMagicGet($property) {
    return FALSE;
  }

  /**
   * @param string $property
   *
   * @return mixed
   */
  public function callMagicGet($property) {
    $return = NULL;
    return $return;
  }

  /**
   * @param string $property
   *
   * @return bool
   */
  public function canCallMagicSet($property) {
    return FALSE;
  }

  /**
   * @param $property
   * @param $value
   *
   * @return mixed
   */
  public function callMagicSet($property, $value) {
    $return = NULL;
    return $return;
  }

  /**
   * @param string $method
   *
   * @return bool
   */
  public function canCallMagicCall($method) {
    return FALSE;
  }

  /**
   * @param string $method
   * @param array $arguments
   *
   * @return mixed
   */
  public function callMagicCall($method, $arguments) {
    $return = NULL;
    return $return;
  }
}
