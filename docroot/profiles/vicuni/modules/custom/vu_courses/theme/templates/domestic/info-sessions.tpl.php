<?php

/**
 * @file
 * Domestic info sessions template.
 */
?>
<?php if (!empty($info_sessions)): ?>
  <h3>
    <i class="fa fa-lg fa-info-circle"></i> <?php print t('Information sessions'); ?>
  </h3>

  <p>
    <?php $count = count($info_sessions); ?>
    <?php print format_plural($count, '<a href="@href">Information sessions</a>', 'Information sessions', [
      '@href' => $info_sessions[0]['url'],
    ]); ?> are being held to give you the chance to learn more about studying
    this course. Anyone interested is encouraged to attend.
  </p>

  <?php if ($count > 1) : ?>
    <p><?php print t('Sessions are running across several locations'); ?>:</p>

    <ul>
      <?php foreach ($info_sessions as $event): ?>
        <?php if (!empty($event['location'])) : ?>
          <li>
            <?php print t('<a href="@href">sessions at @location</a>', [
              '@href' => $event['url'],
              '@location' => $event['location'],
            ]); ?>
          </li>
        <?php endif; ?>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
<?php endif ?>
