<?php

/**
 * @file
 * Theme implementation to display a single Drupal page.
 */
?>
<?php if (!empty($page['navigation'])): ?>
  <header role="banner" class="js-fixed-mobile-header">
    <?php print render($page['navigation']); ?>
  </header> <!-- /#navbar -->
<?php endif; ?>

<div class="main-container container-fluid">
  <a id="main-content"></a>
  <?php if ($pre_content): ?>
    <?php print $pre_content ?>
  <?php endif; ?>
  <?php if ($is_front): ?>
    <h1 class="sr-only sr-only-focusable">VU home</h1>
  <?php endif; ?>
  <?php if ($show_title_box): ?>
    <div id="title-box" class="<?php if(!empty($title_box_classes)):
      print implode(' ', $title_box_classes);
   endif; ?>">
      <div class="container">
        <div class="title-box row">
          <div class="col-sm-7 col-md-7 col-lg-7">
            <div class="row">
              <div class="title-box__breadcrumb col-sm-10 col-md-10 col-lg-10">
                <?php if (!empty($breadcrumb)): ?>
                  <?php print $breadcrumb; ?>
                <?php endif; ?>
              </div>
            </div>
            <div class="row">
              <div class="title-box__title col-sm-11 col-md-11 col-lg-12">
                <?php if (!empty($title)): ?>
                  <h1 class="page-header"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <?php if (!empty($title_sub1)): ?>
                  <div class="page-header-title-sub1"><?php print $title_sub1; ?></div>
                <?php endif; ?>
                <?php if (!empty($title_sub2)): ?>
                  <div class="page-header-title-sub2 top"><?php print $title_sub2; ?></div>
                <?php endif; ?>
                <?php if (!empty($title_sub3)): ?>
                  <div class="page-header-title-sub3 top"><?php print $title_sub3; ?></div>
                <?php endif; ?>
              </div>
            </div>
            <div class="row">
              <div class="title-box__bottom col-sm-10 col-md-12 col-lg-12">
                <div class="title-box__bottom-content">
                  <?php print render($page['title_box_bottom']); ?>
                  <?php if (!empty($title_sub2)): ?>
                    <div class="page-header-title-sub2 bottom"><?php print $title_sub2; ?></div>
                  <?php endif; ?>
                  <?php if (!empty($title_sub3)): ?>
                    <div class="page-header-title-sub3 bottom"><?php print $title_sub3; ?></div>
                  <?php endif; ?>
                </div>
                <div class="title-box__logo--top">
                  <?php print render($title_prefix); ?>
                </div>
              </div>
            </div>
          </div>
          <div class="title-box__feature<?php print !empty($title_box_feature_classes) ? ' ' . implode(' ', $title_box_feature_classes) : '' ?>">
            <div class="<?php print !empty($title_box_classes) ? implode(' ', $title_box_feature_inner_classes) : '' ?>" >
              <?php print render($page['title_box_feature']); ?>
            </div>
            <?php if (!empty($researcher_photo)): ?>
              <?php print $researcher_photo; ?>
            <?php endif; ?>
          </div>
          <div class="left-angled-shape col-sm-8"></div>
          <div class="right-angled-shape col-sm-push-12 hidden-xs"></div>
        </div>
      </div>
    </div>
  <?php endif; ?>
  <div class="main-content">
    <div class="row">
      <?php print render($page['below_header']); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <div class="container"><?php print render($tabs); ?></div>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <div class="container"><?php print render($page['help']); ?></div>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <div class="container"><ul class="action-links"><?php print render($action_links); ?></ul></div>
      <?php endif; ?>
    </div>
    <div class="row">
      <?php if (!empty($site_search_form)): ?>
        <div class="site-search-form section">
          <div class="container">
            <?php print drupal_render($site_search_form); ?>
          </div>
        </div>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
  </div>
</div>

<?php if (!empty($page['footer'])): ?>
  <footer class="footer">
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>

<?php if (!empty($page['shutter'])): ?>
  <?php print render($page['shutter']); ?>
<?php endif; ?>
