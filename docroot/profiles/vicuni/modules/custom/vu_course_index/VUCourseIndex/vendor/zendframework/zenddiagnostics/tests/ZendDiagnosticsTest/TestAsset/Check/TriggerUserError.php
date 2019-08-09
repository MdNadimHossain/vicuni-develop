<?php
/**
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
namespace ZendDiagnosticsTest\TestAsset\Check;

use ZendDiagnostics\Check\AbstractCheck;

class TriggerUserError extends AbstractCheck {
  protected $label = '';

  protected $message;
  protected $severity;

  protected $result = TRUE;

  public function __construct($message, $severity, $result = TRUE) {
    $this->message = $message;
    $this->severity = $severity;
    $this->result = $result;
  }

  public function check() {
    trigger_error($this->message, $this->severity);

    return $this->result;
  }
}
