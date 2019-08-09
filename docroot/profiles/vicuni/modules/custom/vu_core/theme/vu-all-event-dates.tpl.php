<?php

/**
 * @file
 * Template for all event dates.
 */
?>

<?php if ($multiple_dates): ?>
  <div id="all-event-dates-content">
    <div class="event-dates-title">
      <h3><i class="fa fa-calendar" aria-hidden="true"></i>All event dates</h3>
    </div>
    <?php print $multiple_dates; ?>
  </div>
<?php endif; ?>
<?php if ($cta_title): ?>
  <div id="cta_link_content">
    <a href="<?php print $cta_url; ?>" class="ext"><?php print $cta_title; ?></a>
  </div>
<?php endif; ?>
