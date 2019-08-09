<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>

<?php if (!empty($content['quick_facts'])) : ?>
  <a class="quick-facts" title="<?php print $content['link_title']; ?>" href="<?php print $content['quick_facts']; ?>">
    <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
      <?php print $ds_content; ?>
    </<?php print $ds_content_wrapper ?>>
  </a>
<?php else : ?>
  <div class="quick-facts">
    <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
      <?php print $ds_content; ?>
    </<?php print $ds_content_wrapper ?>>
  </div>
<?php endif ?>
