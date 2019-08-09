<?php

/**
 * @file
 * Chat footer template.
 */
?>

<div class="vu-chat-landing-pages">
  <div class="chat-link-wrapper">
    <?php if ($is_open): ?>
      <a class="bubble js-chat-status-title noext" href="<?php print $url; ?>">
        <?php print $open_title; ?>
      </a>
      <strong>
        <p>
          <span class="js-chat-status-message"><?php print $open_message; ?></span>
        </p>
      </strong>
    <?php else: ?>
      <a class="bubble js-chat-status-title chat-close noext">
        <?php print $close_title; ?>
      </a>
      <strong>
        <p>
          <span class="js-chat-status-message"><?php print $close_message; ?></span>
        </p>
      </strong>
    <?php endif; ?>
  </div>
  <div class="chat-time-info">
    <div class="hours-title js-chat-hours-title">
      <?php if ($start && $finish): ?>
        <?php print $is_open ? $hours_open_title : $hours_close_title; ?>
      <?php endif; ?>
    </div>
    <div class="hours-values">
        <span class="js-chat-hours">
          <?php if ($start && $finish): ?>
            <?php if ($is_open): ?>
              <?php print $start; ?> &ndash; <?php print $finish; ?> (<?php print $hours_timezone; ?>)
            <?php else: ?>
              <?php print $weekday; ?>, <?php print $start; ?> &ndash; <?php print $finish; ?> (<?php print $hours_timezone; ?>)
            <?php endif; ?>
          <?php endif; ?>
        </span>
    </div>
  </div>
  <div class="local-time">
    <strong>Local time: </strong>
    <span class="chat-now-local-time"><?php print date('l d F g:ia T', time()) . ' ' . $hours_timezone; ?></span>
  </div>
</div>
