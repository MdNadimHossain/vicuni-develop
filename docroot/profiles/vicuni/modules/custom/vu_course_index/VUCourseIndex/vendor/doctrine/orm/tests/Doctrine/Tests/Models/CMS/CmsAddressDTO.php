<?php

namespace Doctrine\Tests\Models\CMS;

class CmsAddressDTO {
  public $country;
  public $city;
  public $zip;

  public function __construct($country = NULL, $city = NULL, $zip = NULL) {
    $this->country = $country;
    $this->city = $city;
    $this->zip = $zip;
  }
}
