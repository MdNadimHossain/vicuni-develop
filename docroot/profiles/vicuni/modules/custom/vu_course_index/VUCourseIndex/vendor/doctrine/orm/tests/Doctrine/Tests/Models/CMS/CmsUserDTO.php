<?php

namespace Doctrine\Tests\Models\CMS;

class CmsUserDTO {
  public $name;
  public $email;
  public $address;
  public $phonenumbers;

  public function __construct($name = NULL, $email = NULL, $address = NULL, $phonenumbers = NULL) {
    $this->name = $name;
    $this->email = $email;
    $this->address = $address;
    $this->phonenumbers = $phonenumbers;
  }
}
