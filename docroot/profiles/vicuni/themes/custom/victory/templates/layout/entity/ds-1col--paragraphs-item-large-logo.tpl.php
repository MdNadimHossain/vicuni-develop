<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>

<?php if (!empty($content['large_logo_link'])) : ?>
  <div class="large-logo-container"><a class="large_logo_link" title="<?php print $content['link_title']; ?>" href="<?php print $content['large_logo_link']; ?>">
    <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
      <?php print $ds_content; ?>
    </<?php print $ds_content_wrapper ?>></div>
  </a>
<?php else : ?>
  <div class="large-logo-container"><<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
    <?php print $ds_content; ?>
  </<?php print $ds_content_wrapper ?>></div>
<?php endif ?>
