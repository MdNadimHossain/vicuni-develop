<?php

/**
 * @file
 * Featured content region blocks.
 */
?>

<?php if('VU in your language' == $block->subject): ?>
  <section class="block-in-your-language">
<?php endif; ?>

<?php print $content; ?>

<?php if('VU in your language' == $block->subject): ?>
  </section>
<?php endif; ?>
