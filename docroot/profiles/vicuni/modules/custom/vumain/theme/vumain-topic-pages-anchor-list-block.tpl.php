<?php
/**
 * @file
 * Template for topic pages anchor list.
 */
?>
<?php if (!empty($items)): ?>
  <div class="topic-intro__content">
    <ul class="anchor-list">
      <?php foreach ($items as $item): ?>
        <li class="anchor-list__link">
          <a href="#<?php print $item['anchor_id']; ?>">
            <i class="<?php print $item['icon_classes']; ?>"></i> <?php print $item['title'] ?>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
