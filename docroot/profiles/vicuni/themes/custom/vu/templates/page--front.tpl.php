<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<div id="fb-root"></div>
<div id="page-background"></div>

<header role="banner" class="js-fixed-mobile-header">
  <?php if (!empty($page['navigation'])): ?>
    <div id="navbar" class="<?php print $navbar_classes; ?>">
      <nav role="navigation" class="<?php print $container_class; ?>">
        <?php print render($page['navigation']); ?>
      </nav>
    </div>
  <?php endif; ?>

  <div class="header-menu-wrapper<?php print !empty($page['header_menu']) ? ' with-header-menu' : ''; ?>">
    <?php if (!empty($logo) || !empty($logo_svg)): ?>
      <div class="container">
        <a href="<?php print $front_page; ?>" title="<?php echo $site_name ?> home" class="logo js-responsive-menu-trigger-anchor" id="logo">
          <?php if (!empty($logo_svg)): ?>
            <?php print $logo_svg; ?>
          <?php else: ?>
            <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" class="no-js"/>
          <?php endif; ?>
        </a>
      </div>
    <?php endif; ?>
    <?php if (!empty($page['header_menu'])): ?>
      <?php print render($page['header_menu']); ?>
    <?php endif; ?>
  </div>

  <div class="container">
    <?php if (!empty($page['header'])): ?>
      <?php print render($page['header']); ?>
    <?php endif; ?>
  </div>
</header>

<?php if (!empty($messages)): ?>
  <div class="messages-wrapper container">
    <?php print $messages; ?>
  </div>
<?php endif; ?>

<a id="main-content"></a>

<?php if (!empty($page['featured_content'])): ?>
  <div class="slideshow-area container">
    <?php print render($page['featured_content']); ?>
  </div>
<?php endif; ?>
<div class="main-container <?php print $container_class . ' ' . $mr_class; ?>">
  <div class="main-container-wrapper">
    <section class="main-content-wrapper<?php print (!$has_left_sidebar && !$subsite_sidebar_second) ? ' no-sidebar' : '';
    print $sidebar_second_class; ?>">
      <?php if (!empty($page['homepage_content_top'])): ?>
        <div class="row homepage-content-top">
          <div class="col-md-12">
            <?php print render($page['homepage_content_top']); ?>
          </div>
        </div>
      <?php endif; ?>
      <div class="row homepage-bean-tiles">
        <?php if (!empty($page['homepage_bean_tiles'])): ?>
          <div class="col-md-12">
            <?php print render($page['homepage_bean_tiles']); ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="row homepage-bean-banners">
        <?php if (!empty($page['homepage_bean_banners'])): ?>
          <?php print render($page['homepage_bean_banners']); ?>
        <?php endif; ?>
      </div>
      <div class="row home-columns">
        <?php if (!empty($page['home_col_left'])): ?>
          <div class="col-sm-8">
            <?php print render($page['home_col_left']); ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($page['home_col_right'])): ?>
          <div class="col-sm-4 pl6">
            <?php print render($page['home_col_right']); ?>
          </div>
        <?php endif; ?>
      </div>
      <?php hide($page['subsite_landing_below_tiles']); ?>
      <?php hide($page['subsite_landing_rhs']); ?>
      <?php print render($page['before_content']); ?>
      <?php print render($page['content']); ?>
    </section>
  </div>
</div>

<?php if (!empty($page['home_social_media'])): ?>
  <div class="homepage-social-media-wrapper <?php print $container_class; ?>">
    <?php print render($page['home_social_media']); ?>
  </div>
<?php endif; ?>
<?php print render($page['footer']) ?>
<?php if (!empty($page['shutter'])): ?>
  <?php print render($page['shutter']); ?>
<?php endif; ?>
