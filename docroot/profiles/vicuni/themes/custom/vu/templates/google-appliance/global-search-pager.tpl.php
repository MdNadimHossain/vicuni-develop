<?php

/**
 * @file
 * Theme file for Search results pager.
 */
?>
<?php if (isset($pager_links) && count($pager_links)): ?>
  <div class="pagination">
    <ul>
      <?php if (isset($prev_link)): ?>
        <li class="prev">
          <a class="search-navigation" href="<?php echo $prev_link; ?>">&larr; Previous</a>
        </li>
      <?php else: ?>
          <li class="prev disabled">
            <a class="search-navigation" href="#">&larr; Previous</a></li>
      <?php endif; ?>

      <?php foreach ($pager_links as $page => $link): ?>
        <?php if ($page == $current_page): ?>
          <li class="active">
            <a class="search-navigation" href="#"><?php echo $page; ?></a></li>
        <?php else: ?>
          <li>
            <a class="search-navigation" href="<?php echo $link; ?>" rel="nofollow"><?php echo $page; ?></a>
          </li>
        <?php endif; ?>
      <?php endforeach; ?>

      <?php if (isset($next_link)): ?>
        <li class="next">
          <a class="search-navigation" href="<?php echo $next_link; ?>">Next &rarr;</a>
        </li>
      <?php else: ?>
          <li class="next disabled">
            <a class="search-navigation" href="#">Next &rarr;</a></li>
      <?php endif; ?>
    </ul>
  </div>
<?php endif; ?>
