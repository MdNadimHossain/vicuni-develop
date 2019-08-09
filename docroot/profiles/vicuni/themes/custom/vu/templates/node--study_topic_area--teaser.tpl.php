<?php

/**
 * @file
 * Template form teaser of study topic area content type.
 */

$url_query = drupal_get_query_parameters();
if (isset($url_query['audience']) && $url_query['audience'] == 'international') {
  $node_url .= "?audience=international";
}
?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <a href="<?php print $node_url; ?>">
    <?php if (!empty($title)): ?>
      <span class="title">
        <?php print $title; ?>
      </span>
    <?php endif; ?>
    <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    hide($content['field_success_story']);
    hide($content['field_inter_success_story']);
    ?>
    <?php print render($content); ?>
  </a>
</article>
