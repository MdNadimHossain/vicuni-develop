<?php

/**
 * @file
 * Search summary template.
 *
 * Available variables:
 * - $summary: An array of summary information.
 */
?>
<div id="funnelback-summary">
  <div class="result-count">
    Found <?php print $summary['total'] ?> results
    for '<?php print $summary['query']; ?>'
  </div>
</div>
