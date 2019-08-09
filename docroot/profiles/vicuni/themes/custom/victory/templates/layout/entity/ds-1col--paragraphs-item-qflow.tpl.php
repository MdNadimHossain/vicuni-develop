<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
  <div class="qflow-container <?php print !$is_open ? 'hide' : ' '; ?>">
      <div class="virtual-ticket">
        <?php if (!empty($virtual_queue_link)): ?>
          <a class="qflow-virtual-ticket ticket-icon" href=<?php print $virtual_queue_link; ?> target="_blank">   
            <div class="ticket-icon-text">Join our virtual queue</div>
          </a>
        <?php endif; ?>
      </div>
      <?php print $ds_content; ?>
  </div>
</<?php print $ds_content_wrapper ?>>
