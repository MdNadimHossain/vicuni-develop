<?php

/**
 * @file
 * Acknowledgement of country block template.
 */
?>
<div class="container">
  <div class="row">
    <div <?php print drupal_attributes($attributes_col1); ?>>
      <?php print theme('image', [
        'path' => drupal_get_path('theme', 'vu') . '/images/australian-aboriginal-flag.png',
        'alt' => 'Australian Aboriginal flag',
      ]); ?>
    </div>
    <div <?php print drupal_attributes($attributes_col2); ?>>
      <h3 class="footer-aoc-title"><?php print l(t('Acknowledgement of country'), 'about-us/vision-mission/acknowledgement-of-country'); ?></h3>
      <p class="footer-aoc-message">
        <?php print $acknowledgement; ?>
      </p>
    </div>
  </div>
</div>
