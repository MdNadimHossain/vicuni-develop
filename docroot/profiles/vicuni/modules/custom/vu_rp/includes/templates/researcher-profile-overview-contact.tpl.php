<?php

/**
 * @file
 * Template file for Contact links.
 */
?>
<div class="list__style--tools" id="researcher-overview-contact-details-related">
  <div class="victory-researcher-profile-related-links">
    <ul>
      <?php if ($email): ?>
        <li>
          <a href="mailto:<?php print $email; ?>" class="no-arrow noext">
            <div class="icon"><i class="fa fa-envelope"></i></i></div>
            <div class="text"><span class="title"><?php print $email; ?></span>
            </div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
      <?php if ($phone): ?>
        <li>
          <a href="tel:<?php print $phone_value; ?>" class="no-arrow noext">
            <div class="icon"><i class="fa fa-phone"></i></i></div>
            <div class="text"><span class="title"><?php print $phone; ?></span>
            </div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
      <?php if ($twitter): ?>
        <li>
          <a href="<?php print $twitter_url; ?>" target="_blank" class="noext">
            <div class="icon"><i class="fa fa-twitter"></i></div>
            <div class="text">
              <span class="title"><?php print $twitter; ?></span></div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
      <?php if ($facebook): ?>
        <li>
          <a href="<?php print $facebook; ?>" target="_blank" class="noext">
            <div class="icon"><i class="fa fa-facebook-official"></i></div>
            <div class="text">
              <span class="title">Facebook profile</span></div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
      <?php if ($linkedin): ?>
        <li>
          <a href="<?php print $linkedin; ?>" target="_blank" class="noext">
            <div class="icon"><i class="fa fa-linkedin-square"></i></div>
            <div class="text">
              <span class="title">LinkedIn profile</span></div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
      <?php if ($conversation): ?>
        <li>
          <a href="<?php print $conversation; ?>" target="_blank" class="noext">
            <div class="icon conversation"></div>
            <div class="text">
              <span class="title">The Conversation profile</span></div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
      <?php if ($orcid): ?>
        <li>
          <a href="<?php print $orcid; ?>" class="noext">
            <div class="icon orcid"></div>
            <div class="text"><span class="title">View ORCID profile</span>
            </div>
            <div class="arrow"></div>
          </a>
        </li>
      <?php endif; ?>
    </ul>
  </div>
</div>
