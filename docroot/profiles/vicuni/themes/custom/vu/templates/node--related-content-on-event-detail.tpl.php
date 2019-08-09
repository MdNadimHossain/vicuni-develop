<?php

/**
 * @file
 * Template for the related content on event view mode on page builder.
 */
?>
<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <a class="related-link" href="<?php print $node_url; ?>"><?php print $title; ?></a>
  <p><?php print $sidebar_related_content; ?></p>
</article>
