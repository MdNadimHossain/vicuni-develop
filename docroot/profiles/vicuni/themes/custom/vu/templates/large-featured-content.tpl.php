<?php

/**
 * @file
 * Large featured content.
 */
?>

<section class="featured-content">
  <div class="level-1-featured-content">
    <div class="level-1-featured-content-controller">
      <div class="level-1-featured-content-controller-wrapper dots"></div>
      <div class="level-1-featured-content-controller-wrapper pause-play">
        <button class="pause-button fa fa-pause" tabindex="0">
          <span class="accessibility"><?php print t('Pause'); ?></span></button>
        <button class="play-button fa fa-play active" tabindex="0">
          <span class="accessibility"><?php print t('Play'); ?></span></button>
      </div>
    </div>
    <?php if (count($items)): ?>
      <ul class="items">
        <?php foreach ($items as $item): ?>
          <li>
            <a href="<?php print $item['url']; ?>">
              <figure>
                <?php print $item['image']; ?>
                <figcaption>
                  <h2><?php print $item['title']; ?></h2>
                  <p><?php print $item['teaser']; ?>...</p>
                  <span class="btn btn-primary">Read</span>
                </figcaption>
              </figure>
            </a>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>
  </div>
</section>
