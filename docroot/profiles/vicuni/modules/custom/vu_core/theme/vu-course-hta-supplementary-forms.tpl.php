<?php

/**
 * @file
 * Courses - How to Apply - Supplementary forms block.
 */
?>

<?php if (count($supplementary_forms) > 1): ?>
<p>
  All applicants must complete the following supplementary forms:
  <ul>
    <?php foreach ($supplementary_forms as $link): ?>
    <li><?php print $link ?></li>
    <?php endforeach; ?>
  </ul>
</p>
<?php elseif (count($supplementary_forms) == 1): ?>
<p>
  All applicants must complete an <?php print current($supplementary_forms) ?>.
</p>
<?php endif ?>
