<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <a title="<?php print $content['link_title']; ?>" href="<?php print $content['feature_link']; ?>">
    <?php print $ds_content; ?>
  </a>

</<?php print $ds_content_wrapper ?>>
