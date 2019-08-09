<?php

/**
 * @file
 * Course browser template.
 */
$items_per_col = 5;
$count = 0;
if ($title): ?><h2 class="heading"><?php echo $title ?></h2><?php
endif; ?>
<div class="course-lists">
  <ul>
    <?php while ($count < $items_per_col) :
      $count++;
      $item = reset($topics);
      $path = key($topics);
      unset($topics[$path]);
      if (!empty($item)) : ?>
        <li>
          <a href="<?php echo $path . ($is_international ? '?audience=international' : ''); ?>"><?php echo $item; ?></a>
        </li>
        <?php
      endif;
    endwhile; ?>
  </ul>

  <ul>
    <?php
    while ($count < 2 * $items_per_col) :
      $count++;

      $item = reset($topics);
      $path = key($topics);
      unset($topics[$path]);
      if (!empty($item)) : ?>
        <li>
          <a href="<?php echo $path; ?>"><?php echo $item; ?></a>
        </li>
        <?php
      endif;
    endwhile; ?>
  </ul>
</div>
