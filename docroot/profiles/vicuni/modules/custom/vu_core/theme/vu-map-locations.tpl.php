<?php

/**
 * @file
 * Contains iamge caption for news and media.
 */
?>
<a href="#map-component-container" data-position="<?php print $position; ?>" data-lat-long="<?php print $lat_long; ?>" class="place-name">
  <?php if(!empty($title)): ?>
    <span class="location-title"><?php print $title; ?></span>
  <?php endif; ?>
  <span class="address">
    <?php if(!empty($campus_building)): ?>
      <?php print $campus_building . ', '; ?>
    <?php endif; ?>
    <?php print $address; ?>
  </span>
</a>
