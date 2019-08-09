<?php

/**
 * @file
 * Template for a Victory navigation panel layout.
 *
 * This template provides a custom "victory_navigation" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['primary']: The Primary menu pane region.
 *   $content['secondary']: The Secondary menu pane region.
 *   $content['shutters']: A region for any shutters.
 */
?>
<div id="page-header" class="header-wrapper<?php print !empty($content['secondary']) ? ' with-header-content' : ''; ?>">
  <?php if (!empty($content['primary'])): ?>
    <div class="primary<?php print $is_subsite ? ' subsite' : ' '; ?>">
      <?php print $content['primary']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($logo) || !empty($logo_svg)): ?>
    <div class="container logo-wrapper">
      <a href="<?php print $front_page; ?>"
         title="<?php echo $site_name ?> home"
         class="logo js-responsive-menu-trigger-anchor" id="logo">
        <?php if (!empty($logo_svg)): ?>
          <?php print $logo_svg; ?>
        <?php else: ?>
          <img src="<?php print $logo ?>"
               alt="<?php print $site_name_and_slogan ?>"
               title="<?php print $site_name_and_slogan ?>"
               class="no-js"/>
        <?php endif; ?>
      </a>
      <div class="page-title hidden-md hidden-lg"><div class="inner"><span><?php print drupal_get_title() ?></span></div></div>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['secondary'])): ?>
    <div class="secondary">
      <?php print render($content['secondary']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['shutter'])): ?>
    <div class="region-shutter modal js-shutter" id="region--shutter" tabindex="-1" role="dialog">
      <div class="modal-dialog js-shutter-dialog collapse" role="document">
        <?php if ($alt_logo): ?>
          <div class="js-shutter-header">
            <div class="container">
              <div class="row">
                <div class="col-md-12">
                  <?php print render($alt_logo); ?>
                </div>
              </div>
            </div>
          </div>
        <?php endif; ?>
        <div class="js-shutter-content">
          <div class="container">
            <div class="row">
              <div class="col-md-12 js-shutter-items">
                <?php print $content['shutter']; ?>
              </div>
            </div>
          </div>
        </div>
        <div class="js-shutter-footer">
          <div class="container">
            <div class="row">
              <div class="col-md-12 button-container">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                  <span class="sr-only">Close</span>
                </button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div> <!-- /#page-header -->
