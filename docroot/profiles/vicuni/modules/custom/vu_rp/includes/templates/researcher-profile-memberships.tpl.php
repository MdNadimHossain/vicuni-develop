<?php

/**
 * @file
 * Template file for Memberships.
 */
?>
<?php if (count($content)): ?>
  <div class="section research-career-memberships" id="research-career-memberships">
    <h2 class="victory-title__stripe">Professional memberships</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-10">
          <ul>
            <?php foreach ($content as $membership): ?>
              <li><?php print $membership['field_rp_m_role']; ?>, <?php print $membership['field_rp_m_organisation']; ?></li>
            <?php endforeach; ?>
          </ul>
        </div>
        <div class="col-md-push-1 col-md-1"></div>
      </div>
    </div>
  </div>
<?php endif; ?>
