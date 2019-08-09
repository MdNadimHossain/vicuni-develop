<?php

/**
 * @file
 * Courses - ATAR Minimum Entry block.
 */
?>
<strong>ATAR:</strong>
<div class="atar-min-entry-data">
  <?php if($atar_value) : ?>
     <?php print $atar_heading . ' ' . $atar_value ?>
  <?php else : ?>
    <?php print $atar_heading?>
  <?php endif; ?>
</div>
<div class="atar-min-entry-more" data-smoothscroll>
  <?php print $atar_more_link_text?> <a href="#admission" class="atar-min-entry-more-a">More about ATAR</a>
</div>
