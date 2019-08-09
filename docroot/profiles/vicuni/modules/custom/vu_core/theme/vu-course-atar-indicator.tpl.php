<?php

/**
 * @file
 * Template file for ATAR HE intro block.
 */
?>
<div class="atar-indicator">
  <h4>Importance of ATAR for this course</h4>
  <div class="indicator-container">
    <div class="indicator <?php print $atar ? 'active' : ''; ?>">
      <span>ATAR+</span>
      <p>We consider both ATAR and other criteria</p>
    </div>
  </div>
  <div class="indicator-container">
    <div class="indicator <?php print $atar ? '' : 'active'; ?>">
      <span class="na">NA</span>
      <p>ATAR is not a consideration. We use other criteria</p>
    </div>
  </div>
</div>
