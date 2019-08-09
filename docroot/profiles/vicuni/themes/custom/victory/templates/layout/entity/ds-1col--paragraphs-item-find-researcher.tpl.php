<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
  <?php print $ds_content; ?>
  <?php if($content['researcher_link']): ?>
    <div class="researcher-link">
      <a href="<?php print $content['researcher_link']; ?>">Find a researcher</a>
    </div>
  <?php endif; ?>
</<?php print $ds_content_wrapper ?>>
