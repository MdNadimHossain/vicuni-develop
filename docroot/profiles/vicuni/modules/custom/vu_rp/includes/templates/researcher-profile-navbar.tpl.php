<?php

/**
 * @file
 * Researcher profile Navbar.
 */
?>
<!-- Sample block to include modal -->
<div class="modal fade bg-dark js-researcher-overview-contact-details-modal" id="researcher-overview-contact-details-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"></button>
        <div class="researcher-contact-details-modal">
          <h3>Choose your preferred contact method:</h3>
          <?php if ($email): ?>
            <div class="text">
              <div class="icon"><i class="fa fa-envelope"></i></div>
              <span class="title"><?php print $email ?></span></div>
          <?php endif; ?>
          <?php if ($phone): ?>
            <div class="text">
              <div class="icon"><i class="fa fa-phone"></i></div>
              <span class="title"><?php print $phone ?></span></div>
          <?php endif; ?>
          <?php if ($twitter): ?>
            <div class="text">
              <div class="icon"><i class="fa fa-twitter"></i></div>
              <span class="title"><?php print $twitter ?></span></div>
          <?php endif; ?>
          <?php if ($facebook): ?>
            <div class="text">
              <div class="icon"><i class="fa fa-facebook-official"></i></div>
              <span class="title"><?php print $facebook ?></span></div>
          <?php endif; ?>
          <?php if ($linkedin): ?>
            <div class="text">
              <div class="icon"><i class="fa fa-linkedin-square"></i></div>
              <span class="title"><?php print $linkedin ?></span></div>
          <?php endif; ?>
          <?php if ($conversation): ?>
            <div class="text">
              <div class="icon conversation"></div>
              </i><span class="title"><?php print $conversation ?></span></div>
          <?php endif; ?>
          <?php if ($orcid): ?>
            <div class="text">
              <div class="icon orcid"></div>
              <span class="title"><?php print $orcid ?></span></div>
          <?php endif; ?>
          <div class="contact-bottom">
            <span>Alternatively to find someone else in VU Research you may wish to:</span>
            <ul>
              <li>View the list of key <a href="#">VU Research contacts</a></li>
              <li><a href="#">Find a Researcher</a></li>
            </ul>
          </div>
        </div>
        <div class="dismiss-modal">
          <button tabindex="0" class="close-text" data-dismiss="modal">Close
          </button>
        </div>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<!-- following will be the end content of this block tpl -->
<div class="vu-vp-block-researcher-profile-navbar clearfix">
  <div class="container">
    <div class="nav-container">
      <div id="overview" class="researcher-profile-navbar-item js-researcher-profile-navbar-item">
        <span>Overview</span></div>
      <div id="publications" class="researcher-profile-navbar-item js-researcher-profile-navbar-item">
        <span>Key publications</span>
      </div>
      <div id="research-funding" class="researcher-profile-navbar-item js-researcher-profile-navbar-item">
        <span>Research funding</span></span>
      </div>
      <div id="supervising" class="researcher-profile-navbar-item js-researcher-profile-navbar-item">
        <span>Supervising & teaching</span>
      </div>
      <div id="career" class="researcher-profile-navbar-item js-researcher-profile-navbar-item">
        <span>Career</span></div>
    </div>
    <div class="researcher-profile-nav-container-xs">
      <div class="researcher-profile-nav-container-select">
        <div id="selection" class="selection selected">Section:
          <span id="selected-section">Overview</span>
          <div class="direction"><i class="fa fa-angle-down"></i></div>
        </div>
        <div id="overview" class="xs-navbar-item">Overview</div>
        <div id="publications" class="xs-navbar-item">Key publications</div>
        <div id="research-funding" class="xs-navbar-item">Research funding</div>
        <div id="supervising" class="xs-navbar-item">Supervising & teaching
        </div>
        <div id="career" class="xs-navbar-item">Career</div>
      </div>
    </div>
  </div>
</div>
