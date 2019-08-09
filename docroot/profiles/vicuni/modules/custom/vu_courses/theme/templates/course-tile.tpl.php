<?php

/**
 * @file
 * Course tile template.
 */
if (vu_feature_switches_switch_state($feature)): ?>
  <iframe class="campaign-tile" height="131px" width="365px" src="<?php echo $url ?>" scrolling="no"></iframe>
<?php endif ?>
