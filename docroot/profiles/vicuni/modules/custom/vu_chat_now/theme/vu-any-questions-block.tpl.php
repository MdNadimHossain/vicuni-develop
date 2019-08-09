<?php

/**
 * @file
 * Chat opening times template.
 */
?>

<div class="contact-us-any-questions link-to-chat-inner">
  <h2><?php print t('Any questions?') ?></h2>
  <p class="message"><?php print t('Chat online with one of our friendly staff.') ?></p>
  <p class="chat-link-wrapper">
    <a class="chat-link tooltip-content" href="https://gotovu.custhelp.com/app/home?initchat=true">
      Chat now!
    </a>
  </p>
  <p>
    <a href="https://gotovu.custhelp.com/app/home?initchat=true">
      View online chat hours
    </a>
  </p>
  <p>
    <strong>Local time</strong><br>
    <span class="chat-now-local-time">
      <?php print date('l d F g:ia', time()) . ' ' . $timezone; ?>
    </span>
  </p>
</div>
