<?php

/**
 * @file
 * Template file for Funding Organisations to acknowledge.
 */
?>
<?php if (!empty($content)): ?>
  <p>
    Many thanks to the following organisations for their support and essential contributions to my research:
  </p>
  <ul>
    <?php foreach ($content as $item): ?>
      <li>
        <?php if (!empty($item['field_rp_ota_link'])): ?>
          <a href="<?php print $item['field_rp_ota_link']; ?>"><?php print $item['field_rp_ota_name']; ?></a>
        <?php else: ?>
          <?php print $item['field_rp_ota_name']; ?>
        <?php endif ?>
        <?php if (!empty($item['field_rp_ota_description'])): ?>
          <p>
            <?php print $item['field_rp_ota_description']; ?>
          </p>
        <?php endif ?>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
