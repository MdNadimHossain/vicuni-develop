<?php

/**
 * @file
 * System alert box template.
 */
?>
<div class="system-alert-box <?php print $style; ?>">
  <div class="system-alert-box__heading">
    <i class="fa <?php print $icon; ?>"></i>
    <h3 class="title-text"><?php print $title; ?></h3>
  </div>
  <div class="system-alert-box__message">
    <p><?php print $text; ?></p>
  </div>
</div>
