<?php

/**
 * @file
 * Template file for the funnelback pager.
 *
 * Available variables:
 * - $summary: An array of result summary information.
 */
?>
<div class="no-of-results">
  <?php if ($summary['total'] > 0): ?>
    <div class="result-text">
      Results <?php print $summary['start'] ?> - <?php print $summary['end'] ?> of <?php print $summary['total'] ?>
    </div>
  <?php else: ?>
    <div class="no-result-text">
      <p class="no-result-header">No results found</p>
      <p class="no-result-body">Your search - <strong><?php print $summary['query']; ?></strong> - did not match any documents.</p>
      <p class="no-result-suggestions">
        Suggestions:
        <ul>
          <li>Make sure all words are spelled correctly.</li>
          <li>Try different keywords.</li>
          <li>Try more general keywords.</li>
          <li>Try fewer keywords.</li>
        </ul>
      </p>
    </div>
  <?php endif ?>

  <?php if (count($pager['pages']) > 1): ?>
    <ul class="funnelback-pager">

      <?php if (isset($pager['first']) && !$pager['first']): ?>
        <li class="pager-prev"><a href="<?php print $pager['prev_link'] ?>">← <span class="prev-text">Previous</span></a></li>
      <?php else: ?>
      <li class="pager-prev">← <span class="prev-text">Previous</span></li>
      <?php endif ?>

      <?php foreach($pager['pages'] as $page): ?>

        <?php if ($page['current']): ?>
          <li class="pager-current"><?php print $page['title'] ?></li>
        <?php else: ?>
          <li class="pager-item"><a href="<?php print $page['link'] ?>"><?php print $page['title'] ?></a></li>
        <?php endif; ?>

      <?php endforeach ?>

      <?php if (isset($pager['last']) && !$pager['last']): ?>
        <li class="pager-next"><a href="<?php print $pager['next_link'] ?>"><span class="next-text">Next</span> →</a></li>
      <?php else: ?>
        <li class="pager-next"><span class="next-text">Next</span> →</li>
      <?php endif ?>

    </ul>
  <?php endif ?>
</div>
