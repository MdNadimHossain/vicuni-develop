<?php

/**
 * @file
 * News item template.
 * @todo: Fix all custom sidebar handling by converting related links to blocks
 * and place them with context.
 */
?>

<?php if (empty($media_release) && $view_mode == 'full'): ?>
<div class="<?php echo $row_class; ?>"><!-- $media_release -->
  <div class="news-leftcol-wrapper <?php echo $col_class; ?>"><!-- news-leftcol-wrapper -->
    <h1 class="node-title futura"><?php print $title; ?></h1>
<?php endif; ?>
    <article id="node-<?php print $node->nid; ?>" class="news clear-block node<?php print !$status ? ' node-unpublished' : ''; ?>">
      <?php if (!empty($secondary_tasks)): ?>
        <?php print $secondary_tasks; ?>
      <?php endif; ?>
      <div class="news__date">
        <?php if ($media_release): ?>
          <?php print render($mr_date); ?>
        <?php else: ?>
          <?php print render($content['field_article_date']); ?>
        <?php endif; ?>
      </div>

      <?php if (!$media_release): ?>
        <?php if (!empty($content['field_image'])): ?>
          <div class="news__img">
            <?php print render($content['field_image']) ?>
          </div>
        <?php endif; ?>
      <?php endif; ?>

      <div class="news__content">
        <?php print render($content['body']); ?>
        <?php if ($media_release && (!empty($content['field_contact_info']))): ?>
          <div class="mr__contact-info">
            <strong><?php print t('Media Contact'); ?>:</strong>
            <?php print render($content['field_contact_info']); ?>
          </div>
        <?php endif; ?>
      </div>

      <?php if ($media_release): ?>
        <p class="news-media-see-all">
          <a href="/about-vu/news-events/media-releases"><?php print t('See all media releases'); ?></a>
        </p>
      <?php else: ?>
        <p class="news-media-see-all">
          <a href="/about-vu/news-events/news"><?php print t('See all news'); ?></a></p>
      <?php endif; ?>
    </article>

<?php if (empty($media_release) && $view_mode == 'full'): ?>
  </div><!-- end news-leftcol-wrapper -->

  <aside class="news__col news__col--right col-sm-4">
    <?php if (!empty($content['field_contact_info'])): ?>
      <div class="news__contact-info contact-info">
        <h2 class="side-block-title"><?php print t('Contact us'); ?></h2>
        <?php print render($content['field_contact_info']); ?>
      </div>
    <?php endif; ?>
    <?php if (isset($content['field_related_in_link']) || isset($content['field_related_external_links'])): ?>
      <div class="event-related-links news__related">
        <h2 class="side-block-title"><?php print t('Related'); ?></h2>
        <?php print render($content['field_related_in_link']); ?>
        <?php print render($content['field_related_external_links']); ?>
      </div>
    <?php endif; ?>
  </aside>
</div><!-- end $media_release -->
<?php endif; ?>
