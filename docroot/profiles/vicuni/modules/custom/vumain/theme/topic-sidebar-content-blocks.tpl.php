<?php
/**
 * @file
 * Template for topic pages sidebar content blocks.
 */
?>
<?php if (!empty($items)): ?>
  <article class="sidebar-content-blocks">
  <?php foreach ($items as $item): ?>
  <section class="row sidebar-box content-block row-no-padding <?php echo $item['block_class']; ?>">
    <?php if (!$item['hide_title']): ?>
      <div class="content-block__heading">
        <h3>
          <?php if (!empty($item['icon'])): ?>
            <i class="fa fa-<?php echo $item['icon'] ?>"></i>
          <?php endif; ?>
          <?php echo $item['title'] ?>
        </h3>
      </div>
    <?php endif; ?>
    <?php
      $block_class = !empty($item['block_class']) ? $item['block_class'] : '';
      $content_class = !empty($item['content_class']) ? $item['content_class'] : '';
      $colored_list_modifier = !empty($item['block_class']) && $item['block_class'] == 'sidebar-box--colored-list' ? 'content-block__content--colored-list' : '';
    ?>
    <div class="content-block__content <?php echo $colored_list_modifier;?> <?php echo $content_class;?>">
      <?php if (in_array($block_class, [
        'sidebar-box--important-dates',
        'sidebar-box--key-research-tools',
      ])): ?>
        <i class="fa fa-bookmark fa-5x"></i>
      <?php endif; ?>
      <?php print render($item['content']); ?>
    </div>
  </section>
  <?php endforeach; ?>
  </article>
<?php endif; ?>
