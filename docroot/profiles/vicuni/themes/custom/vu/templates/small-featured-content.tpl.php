<?php

/**
 * @file
 * Small featured content.
 */
?>
<div class="featured-content slideshow">
  <div class="small-featured-content">
    <div class="featured-content-controller">
      <div class="featured-content-controller-wrapper dots"></div>
    </div>
    <div class="slideshow-slides">
      <?php
      foreach ($items as $item):
        $image = image_style_url('small_featured_content', $item->field_image[$item->language][0]['uri']);
        ?>
        <div>
          <figure>
            <a href="/node/<?php print $item->nid; ?>">
              <img src="<?php print $image ?>" alt=" ">
              <figcaption>
                <div class="caption-text">
                  <?php print $item->title; ?>
                </div>
              </figcaption>
            </a>
          </figure>
        </div>
        <?php
      endforeach;
      ?>
    </div>
  </div>
</div>
