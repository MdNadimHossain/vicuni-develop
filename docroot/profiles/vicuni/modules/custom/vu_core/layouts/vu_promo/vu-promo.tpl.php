<?php

/**
 * @file
 * VU promo template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes; ?> clearfix <?php print $extra_class_names; ?>" <?php print $click_event; ?>>

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<?php print render($content['field_promo_brand']); ?>

<div class="col-sm-8 col-sm-pull-4 col-md-6 col-md-pull-3">
  <?php print render($content['title_field']); ?>
  <?php print render($content['field_promo_text']); ?>
  <?php print render($content['field_promo_link']); ?>
</div>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
