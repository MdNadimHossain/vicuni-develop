<?php

/**
 * @file
 * In this section links template.
 */
?>
<?php if (isset($items) && count($items) > 0): ?>
  <ul>
    <?php foreach ($items as $item): ?>
      <li>
        <a href="<?php echo $item['link'] ?>">
          <h3 data-neon-onthispage="false" class="arrow-links-heading"><?php echo $item['title'] ?></h3>
          <?php if (!empty($item['teaser'])) : ?>
            <p class="ellipsis"><?php print render($item['teaser']); ?></p>
          <?php endif; ?>
        </a>
      </li>
    <?php endforeach ?>
  </ul>
<?php endif; ?>
