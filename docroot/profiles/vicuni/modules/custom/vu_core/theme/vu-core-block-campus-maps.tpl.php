<?php

/**
 * @file
 * Campus maps.
 */
?>
<div class="campus-maps">
  <div class="locations">
    <?php print $locations; ?>
  </div>
  <div class="maps-container">
    <div class="location-details">
      <a class="campus-link" tabindex=-1 target="_blank" href="<?php print $campus_name; ?>">
        <span class="fa map-marker"></span>
        <span class="location-title"><?php print $campus_title; ?></span>
        <span>-</span>
        <span class="location-addr"><?php print $campus_addr; ?></span>
      </a>
    </div>
    <section class="campus-location-maps">
      <div id="campus-location-map"></div>
    </section>
  </div>
</div>
