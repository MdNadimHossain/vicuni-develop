<?php

/**
 * @file
 * Theme implementation to wrap left nav menu blocks.
 *
 * This also adds Bootstrap collapsible wrapper for the menu.
 */
?>
<div class="<?php print $classes; ?>">
  <a class="collapse-trigger collapsed" data-toggle="collapse" data-target="#left-nav-collapse" aria-expanded="false" aria-controls="left-nav-collapse">In this section</a>
  <span class="collapse-trigger-text" aria-hidden="true">In this section</span>
  <div id="left-nav-collapse" class="collapse">
    <?php print render($content); ?>
  </div>
</div>
