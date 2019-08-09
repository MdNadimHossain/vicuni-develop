<?php

/**
 * @file
 * Chat opening times template.
 */
?>

<div class="link-to-chat-inner">
  <h2><?php print t('Any questions?'); ?></h2>
  <p class="chat-link-wrapper">
    <a class="chat-link tooltip-content" href="https://gotovu.custhelp.com/app/home?initchat=true">Chat now!</a>
  </p>
</div>

<?php if (!empty($open_times)): ?>
  <h3><?php print t('Chat hours'); ?></h3>
  <?php foreach ($open_times as $days => $times) : ?>
    <p class="days">
      <?php echo $days ?> <?php echo $times[0] ?> - <?php echo $times[1] . ' ' . $timezone; ?>
    </p>
  <?php endforeach; ?>
<?php else: ?>
  <p>
    <a href="https://gotovu.custhelp.com/app/chat/chat_launch">View online chat hours</a>
  </p>
<?php endif; ?>

<p>
  <strong>Local time</strong><br><span class="chat-now-local-time"><?php print date('l d F, g:ia', time()) . ' ' . $timezone; ?></span>
</p>
