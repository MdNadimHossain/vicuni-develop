<?php

/**
 * @file
 * Victory 12 column panel style plugin template.
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<div class="<?php print $classes; ?>" <?php print $id; ?> <?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <<?php print $title_heading; ?><?php print $title_attributes; ?>><?php print $title; ?></<?php print $title_heading; ?>>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="container">
    <?php if ($pane_prefix): ?>
      <?php print $pane_prefix; ?>
    <?php endif; ?>

    <?php if ($admin_links): ?>
      <?php print $admin_links; ?>
    <?php endif; ?>

    <?php if ($feeds): ?>
      <div class="feed">
        <?php print $feeds; ?>
      </div>
    <?php endif; ?>

    <div class="pane-content">
      <?php print render($content); ?>
    </div>

    <?php if ($links): ?>
      <div class="links">
        <?php print $links; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <div class="more-link">
        <?php print $more; ?>
      </div>
    <?php endif; ?>

    <?php if ($pane_suffix): ?>
      <?php print $pane_suffix; ?>
    <?php endif; ?>
  </div>
</div>
