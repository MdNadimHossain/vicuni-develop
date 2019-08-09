<?php

/**
 * @file
 * Default theme implementation for entities.
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
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <div id="campus-map-small"></div>
    <p class="campus-name">
      <span id="loc-title"><?php print $title; ?></span>
      <span class="org"><?php print $content['field_address']['#items'][0]['organisation_name']; ?></span>
      <span class="premise"><?php print $content['field_address']['#items'][0]['premise']; ?></span>
      <span id="address-line1"><?php print $content['field_address']['#items'][0]['thoroughfare']; ?></span>
      <span id="address-line2"><?php print $content['field_address']['#items'][0]['locality'] . ' ' . $content['field_address']['#items'][0]['administrative_area'] . ' ' . $content['field_address']['#items'][0]['postal_code']; ?></span>
    </p>
  </div>
</div>
