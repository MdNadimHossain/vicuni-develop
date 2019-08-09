<?php

/**
 * @file
 * Contains template for Course Search tabs on results page.
 */
?>

<ul class="nav nav-tabs">
  <li class="<?php print $active_tab == 'resident_url' ? 'active' : ''; ?>">
    <?php print $resident_url; ?>
  </li>
  <li class="<?php print $active_tab == 'non_resident_url' ? 'active' : ''; ?>">
    <?php print $non_resident_url; ?>
  </li>
</ul>
