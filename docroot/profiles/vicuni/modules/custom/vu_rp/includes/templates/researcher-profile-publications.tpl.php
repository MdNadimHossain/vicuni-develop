<?php

/**
 * @file
 * Template file for Publications.
 */
?>
<?php if (count($content)): ?>
  <table>
    <thead>
    <tr>
      <th>Year</th>
      <th>Citation</th>
    </tr>
    </thead>
    <tbody>
    <?php foreach ($content as $publication): ?>
      <tr>
        <td><?php print $publication['year']; ?></td>
        <td>
          <?php if (!empty($publication['citation'])) : ?>
            <?php print $publication['citation']; ?>
          <?php endif; ?>
          <?php if (!empty($publication['link'])): ?>
            <?php print $publication['link']; ?>
          <?php endif; ?>
        </td>
      </tr>
    <?php endforeach; ?>
    </tbody>
  </table>
<?php endif; ?>
