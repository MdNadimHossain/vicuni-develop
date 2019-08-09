<?php

/**
 * @file
 * International info sessions template.
 */
if (!empty($info_sessions)):

  $count = count($info_sessions); ?>

  <h3><i class="fa fa-lg fa-info-circle"></i> Meet us in your country</h3>

  <p>Our international application advisers will be available to speak to you about your study options at the following event<?php if ($count) {
      echo 's';
 } ?>:</p>

  <p>
    <?php echo format_plural(
      $count,
      'Our international application advisers will be available to speak to you about your study options at the following event',
      'Our international application advisers will be available to speak to you about your study options at the following events'
    ); ?>:
  </p>

  <ul>
    <?php
    foreach ($info_sessions as $event) : ?>
      <?php if (!$event['location']) {
        continue;
      } ?>
      <li>
        <a href="<?php echo $event['url']; ?>"><?php echo check_plain($event['title']); ?></a><?php echo check_plain(render($event['when'])); ?>
      </li>
    <?php endforeach; ?>
  </ul>

<?php endif; ?>
