<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>

<?php if (!empty($content['key_summary_link'])) : ?>
  <a class="key-summary-link" title="<?php print $content['link_title']; ?>" href="<?php print $content['key_summary_link']; ?>">
    <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
      <div class="key-summary-content"><?php print $ds_content; ?></div>
    </<?php print $ds_content_wrapper ?>>
  </a>
<?php else : ?>
  <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
    <div class="key-summary-content"><?php print $ds_content; ?></div>
  </<?php print $ds_content_wrapper ?>>
<?php endif ?>
