<?php

/**
 * @file
 * Template file for Funding details.
 */
?>
<?php if (count($content)): ?>
  <table>
    <tbody>
    <?php foreach ($content as $funding): ?>
      <tr>
        <td>
          <div class="funding-details">
            <strong><?php print $funding['title']; ?></strong>
          </div>
          <div class="funding-from">From: <?php print $funding['source']; ?></div>
          <?php if (!empty($funding['investigators'])): ?>
            <div class="funding-investigators">Investigators: <?php print $funding['investigators']; ?></div>
          <?php endif; ?>
          <div class="funding-period">For period: <?php print $funding['period']; ?></div>
        </td>
        <td><strong><?php print $funding['amount']; ?></strong></td>
      </tr>
    <?php endforeach; ?>
    </tbody>
  </table>
<?php endif; ?>
