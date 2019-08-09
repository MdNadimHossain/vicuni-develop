<?php

/**
 * @file
 * Default theme implementation for the search stats.
 *
 * @see
 *  template_preprocess_google_appliance_search_stats().
 */
?>
<div class="container-inline google-appliance-search-stats">
  <?php print t('Results @first - @last of @total', $stat_entries); ?>
</div>
