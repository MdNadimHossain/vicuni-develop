<?php

/**
 * @file
 * Default theme implementation for displaying Google Search Appliance results.
 *
 * This template collects each invocation of theme_google_appliance_result().
 * This and the child template are dependent on one another sharing the
 * markup for the results listing.
 *
 * @see template_preprocess_google_appliance_results()
 * @see template_preprocess_google_appliance_result()
 * @see google-appliance-result.tpl.php
 */
?>
<?php if (count($search_results)): ?>
  <p class="showing-summary">
    <?php print t("Found !total results for '<em>!query</em>'.", [
      '!total' => $total_results,
      '!query' => $query,
    ]); ?>
  </p>
  <?php if (!empty($spelling_suggestion)): ?>
    <?php print $spelling_suggestion; ?>
  <?php endif; ?>
  <?php echo $synonyms; ?>
  <?php if (!empty($keymatch_results)) : ?>
    <ul class="keymatch-results google-appliance-keymatch-results">
      <?php print $keymatch_results; ?>
    </ul>
  <?php endif; ?>
  <ol start="<?php echo isset($range_from) ? $range_from : 1; ?>" class="search-results google-appliance-results">
    <?php print $search_results; ?>
  </ol>
  <div class="pager-summary">
    <p><?php print $search_stats; ?></p>
    <?php if (!(isset($page) && $page == 1 && $duplicates_removed)): ?>
      <?php print $pager; ?>
    <?php endif ?>
  </div>
<?php else: ?>
  <h1>No results found</h1>
  <?php if (!empty($spelling_suggestion)): ?>
    <?php print $spelling_suggestion; ?>
  <?php endif; ?>
  <?php if (isset($show_synonyms) && $show_synonyms) : ?>
    <div class="synonyms google-appliance-synonyms">
      <span class="p"><?php print $synonyms_label ?></span>
      <ul><?php print $synonyms; ?></ul>
    </div>
  <?php endif; ?>
  <?php if (!empty($keymatch_results)) : ?>
    <ul class="keymatch-results google-appliance-keymatch-results">
      <?php print $keymatch_results; ?>
    </ul>
  <?php endif; ?>
  <p>
    Your search <?php print $query ? ' - <strong>' . $query . '</strong> - ' : '' ?> did not match any documents.
  </p>
  <p>Suggestions:</p>
  <ul>
    <li>Make sure all words are spelled correctly.</li>
    <li>Try different keywords.</li>
    <li>Try more general keywords.</li>
    <li>Try fewer keywords</li>
  </ul>
<?php endif; ?>
