<?php
/**
 * @file
 * Template for topic pages content blocks.
 * This template is used for 2 field, top and main content.
 * Top content only can render 1 item, it's meant for video on header.
 */
?>
<?php if (!empty($items)): ?>
  <article class="row content-blocks <?php echo $additional_classes; ?>">
    <?php foreach ($items as $item): ?>
      <section class="col-xs-12 content-block">
        <?php if (empty($top_content) && !empty($item['title'])): ?>
          <div class="content-block__heading">
            <h2 id="<?php print $item['title_anchor_id']; ?>">
              <?php if (!empty($item['icon'])): ?>
                <i class="fa fa-<?php echo $item['icon'] ?>"></i>
              <?php endif; ?>
              <?php echo $item['title'] ?>
            </h2>
          </div>
        <?php endif; ?>
        <?php if (!empty($item['content'])): ?>
          <div class="content-block__content <?php print !empty($item['push_class']) ? $item['push_class'] : ''; ?> <?php if (!empty($item['content_class'])): echo $item['content_class']; endif; ?>">
            <?php print render($item['content']); ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($item['image'])): ?>
          <div class="content-block__media <?php print !empty($item['pull_class']) ? $item['pull_class'] : ''; ?> <?php echo $item['content_class']; ?>">
            <figure>
              <?php if (!empty($item['transcript']) && !empty($item['file_url'])): ?>
                <div class="video-thumbnail-wrapper">
                  <a class="noext colorbox-load" href="<?php echo $item['file_url']; ?>">
                    <?php print render($item['image']); ?>
                  </a>
                </div>
              <?php else: ?>
                <?php print render($item['image']); ?>
              <?php endif; ?>
              <?php if (!empty($item['caption'])): ?>
                <figcaption>
                  <?php if (empty($top_content)): ?>
                    <?php echo $item['caption']; ?>
                  <?php else: ?>
                    <a class="noext colorbox-load" href="<?php echo $item['file_url']; ?>">
                      <?php echo $item['caption']; ?>
                    </a>
                  <?php endif; ?>
                </figcaption>
              <?php endif; ?>
              <?php if (!empty($item['transcript']) && empty($top_content)): ?>
                <div class="video-transcript">
                  <?php if (empty($top_content)): ?>
                    <?php echo $item['transcript']; ?>
                  <?php else: ?>
                    <a class="noext colorbox-load" href="<?php echo $item['file_url']; ?>">
                      <?php echo $item['transcript']; ?>
                    </a>
                  <?php endif; ?>
                </div>
              <?php endif; ?>
            </figure>
          </div>
        <?php endif; ?>
      </section>
    <?php endforeach; ?>
  </article>
<?php endif; ?>
