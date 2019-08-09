<?php

/**
 * @file
 * Chat footer template.
 */
?>

<div class="vu-chat-footer">
  <div class="chat-link-wrapper">
    <?php if ($is_open): ?>
      <a class="bubble js-chat-status-title noext" href="<?php print $url; ?>">
        <?php print $open_title; ?>
      </a>
      <strong>
        <p>
          <?php print l($open_message, $url, ['attributes' => ['class' => 'js-chat-status-message noext']]); ?>
        </p>
      </strong>
    <?php else: ?>
      <span class="bubble js-chat-status-title">
        <?php print $close_title; ?>
      </span>
      <strong>
        <p>
          <span class="js-chat-status-message"><?php print $close_message; ?></span>
        </p>
      </strong>
    <?php endif; ?>
  </div>
  <div>
    <div class="hours-title js-chat-hours-title">
      <?php if ($start && $finish): ?>
        <?php print $is_open ? $hours_open_title : $hours_close_title; ?>
      <?php endif; ?>
    </div>
    <div class="hours-values">
        <span class="js-chat-hours">
          <?php if ($start && $finish): ?>
            <?php print $weekday; ?>, <?php print $start; ?> &ndash; <?php print $finish; ?> (<?php print $hours_timezone; ?>)
          <?php endif; ?>
        </span>
    </div>
  </div>
</div>
