<?php

/**
 * @file
 * Template file for funnelback results.
 *
 * Available variables:
 * - $total: The total number of the results.
 * - $summary: Summary block render array.
 * - $query: Search query string.
 * - $breadcrumb: Breadcrumb block render array.
 * - $spell: Spell block render array.
 * - $curator: Curator block render array.
 * - $items: A array of single result render array.
 * - $pager: Pager render array.
 * - $no_result_text: Text string to be displayed when there is no result.
 * @see victory_preprocess_funnelback_results()
 */
?>

<div id="funnelback-results-page" class="section">
  <div class="header">
    <h2 class="victory-title__stripe">Search results</h2>
  </div>
  <div class="container">
    <?php if ($total > 0): ?>

      <?php print render($summary); ?>

      <?php print render($breadcrumb); ?>

      <?php print render($curator); ?>

    <?php endif; ?>

    <?php
      // Always show spelling options.
      print render($spell);
    ?>

    <?php if ($total > 0): ?>

      <ul id="funnelback-results">
        <?php foreach ($items as $item): ?>
          <li class="funnelback-result">
            <?php print render($item); ?>
          </li>
        <?php endforeach; ?>
      </ul>

    <?php else: ?>

      <div class="no-result-text">
        <?php print $no_result_text; ?>
      </div>

    <?php endif; ?>
    <?php print render($pager) ?>
  </div>
</div>
