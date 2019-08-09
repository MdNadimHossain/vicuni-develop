<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>

<?php if (!empty($content['small_logo_link'])) : ?>
  <div class="small-logo-container"><a class="small_logo_link" title="<?php print $content['link_title']; ?>" href="<?php print $content['small_logo_link']; ?>">
    <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
      <?php print $ds_content; ?>
    </<?php print $ds_content_wrapper ?>>
  </a></div>
<?php else : ?>
  <div class="small-logo-container"><<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
    <?php print $ds_content; ?>
  </<?php print $ds_content_wrapper ?>></div>
<?php endif ?>
