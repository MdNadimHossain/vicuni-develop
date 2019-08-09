<?php

/**
 * @file
 * Theme implementation for shutter region.
 */
?>
<?php if ($content): ?>
  <div class="<?php print $classes; ?> modal js-shutter" id="region--shutter" tabindex="-1" role="dialog">
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
              <?php print $content; ?>
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
