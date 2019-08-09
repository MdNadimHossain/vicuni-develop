<?php

/**
 * @file
 * Spell suggestion template.
 *
 * Available variables:
 * - $spell: An array of spell information.
 */
?>
<?php if (!empty($spell)): ?>
  <div id="funnelback-spell">
    <p>Did you mean:
      <?php foreach ($spell as $suggestion): ?>
        <a href='/search/vu/<?php print $suggestion['text'] ?>'><b><?php print $suggestion['text'] ?></b></a>?
      <?php endforeach; ?>
    </p>
  </div>
<?php endif; ?>
