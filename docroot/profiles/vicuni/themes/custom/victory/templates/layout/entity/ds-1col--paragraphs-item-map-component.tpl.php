<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>

<div id="map-component-container" class="map-component <?php print ($full_width) ? 'full-width' : ''; ?> <?php print ($left_menu) ? 'left-menu' : ''; ?>">
  <div class="map-component-container">
    <section class="map-component-location">
      <div aria-hidden="true" id="map-component-section" ></div>
      <div id="map-component-content"></div>
    </section>
  </div>
  <div class="map-component-places ">
    <?php print $locations; ?>
  </div>
</div>
