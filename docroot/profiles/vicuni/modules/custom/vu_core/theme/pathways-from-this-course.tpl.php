<?php

/**
 * @file
 * Template file for pathways from this course block.
 */
?>
<?php if ($pathway_count > 0): ?>
  <p>
    <?php print t('On completion of this course you will be guaranteed entry into the following @degrees and in some cases receive credit for your study:', [
      '@degrees' => format_plural($pathway_count, 'degree', 'degrees'),
    ]); ?>
  </p>
  <?php foreach ($pathways as $pathway): ?>
    <?php print theme('pathway', ['pathway' => $pathway]); ?>
  <?php endforeach; ?>
<?php endif; ?>
<?php if (!empty($pathways_information)): ?>
  <?php print $pathways_information; ?>
<?php endif; ?>
<p>Find out more about our study <a href="/pathways-to-vu">pathways to VU</a></p>
