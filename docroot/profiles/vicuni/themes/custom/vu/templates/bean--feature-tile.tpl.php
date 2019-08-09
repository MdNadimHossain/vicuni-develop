<?php

/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available,
 *   where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes . ' ' . $img_class; ?> clearfix"<?php print $attributes; ?>>

  <div class="content clearfix"<?php print $content_attributes; ?>>
    <h2>
      <?php if ($link_path): ?>
        <a class="featured-tile-link" href="/<?php print $link_path; ?>"><?php print $title; ?></a>
      <?php else: ?>
        <?php print $title; ?>
      <?php endif; ?>
    </h2>

    <?php if ($img_class && $link_path): ?>
      <a class="img-wrapper" href="/<?php print $link_path; ?>"><?php print render($content['field_featured_tile_image']); ?></a>
    <?php else: ?>
      <?php if ($img_class): ?>
        <div class="img-wrapper">
          <?php print render($content['field_featured_tile_image']); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>
    <?php print render($content['field_featured_tile_text']); ?>

  </div>
  <div class="dotted-leader">
    <div>
    </div>
