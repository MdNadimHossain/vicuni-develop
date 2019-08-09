<?php

/**
 * @file
 * Template for On page navigation block.
 */
?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="container">

    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <a href="#<?php print $block_html_id; ?>__content" data-toggle="collapse" aria-expanded="false" aria-controls="<?php print $block_html_id; ?>__content">
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      </a>
    <?php endif;?>
    <?php print render($title_suffix); ?>

    <div class="collapse" id="<?php print $block_html_id; ?>__content">
      <?php print $content ?>
    </div>

  </div>
</section>
