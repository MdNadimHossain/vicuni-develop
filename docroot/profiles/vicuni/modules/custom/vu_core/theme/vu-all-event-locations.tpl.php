<?php

/**
 * @file
 * Template for all event locations.
 */
?>
<div id="event_essential_locations">
  <?php if (!empty($multiple_locations)): ?>
    <?php print $multiple_locations; ?>
    <br>
  <?php else: ?>
    Multiple locations <br>
  <?php endif; ?>
  <a href="#map-component-section">View map</a>
</div>
