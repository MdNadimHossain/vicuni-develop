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
<div id="page-background" <?php print isset($subsites) && isset($subsites['background_url']) ? 'style="background-image: url(' . $subsites['background_url'] . ')"' : ''; ?>></div>

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

<div class="title-block container<?php print $subsite_abovetiles_class; ?><?php print $vicpoly_class; ?> <?php print $header_course_search_form_block_class; ?>">
  <div class="row">
    <div class="col-md-12">
      <?php print render($title_prefix); ?>
      <?php if (!empty($title) && !empty($heading_tag)): ?>
        <<?php echo $heading_tag ?> class="page-title <?php print _vu_get_page_title_class($title) ?>"><?php print $title; ?></<?php echo $heading_tag ?>>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if (isset($subsites) && (isset($subsites['above_tiles_block'])) && ($subsites['above_tiles_block']) && !empty($page['subsite_landing_above_tiles'])): ?>
        <?php print render($page['subsite_landing_above_tiles']); ?>
      <?php endif; ?>
      <?php if (!empty($header_course_search_form_block) && empty($kiosk)): ?>
        <?php print render($header_course_search_form_block); ?>
      <?php endif; ?>
      <?php if (!empty($breadcrumb) && !$kiosk): ?>
        <div class="breadcrumb-wrapper">
          <?php print $breadcrumb; ?>
        </div>
      <?php endif; ?>
      <?php if ($show_unit_search_button): ?>
        <div class="unit-search-button">
          <?php print l(t('New unit search'), 'units/search'); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($header_new_course_search_button)): ?>
        <div class="new-course-search-button">
          <?php print $header_new_course_search_button; ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($site_search_form)): ?>
        <div class="site-search-form">
          <?php print drupal_render($site_search_form); ?>
        </div>
      <?php endif; ?>
      <?php if ($is_vicpoly_course || $is_vicpoly_unit): ?>
        <a href="https://www.vupolytechnic.edu.au" class="<?php print $vicpoly_class; ?>__logo">
          <span>VUIT Logo</span>
        </a>
        <?php if ($is_vicpoly_course_content_type): ?>
          <a href="/courses/search?vuit=1&amp;<?php echo $vicpoly_search_filter; ?>" class="<?php print $vicpoly_class; ?>__search-button">Find another TAFE course</a>
        <?php elseif ($is_vicpoly_unit_content_type): ?>
          <a href="/courses/search?type=Unit&amp;vuit=1&amp;<?php echo $vicpoly_search_filter; ?>" class="<?php print $vicpoly_class; ?>__search-button">Find another TAFE unit</a>
        <?php endif; ?>
      <?php endif; ?>
      <?php if (!empty($share_links) && ($is_news || $is_event)): ?>
        <?php print $share_links; ?>
      <?php endif; ?>
    </div>
  </div>
</div>

<div class="main-container <?php print $container_class . ' ' . $mr_class; ?>">
  <?php print render($page['featured_content']); ?>
  <div class="row main-container-wrapper">
    <?php if ($has_left_sidebar): ?>
      <aside class="col-sm-4 sidebar-first-wrapper" role="complementary">
        <?php if (!empty($facets_region_header)): ?>
          <h3 class="facets-header"><?php echo $facets_region_header; ?></h3>
        <?php endif; ?>
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section class="main-content-wrapper<?php print (!$has_left_sidebar && !$subsite_sidebar_second) ? ' col-sm-12 no-sidebar' : ' col-sm-8 with-sidebar';
    print $sidebar_second_class; ?>">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <?php print render($action_links); ?>
      <?php endif; ?>
      <?php if (!empty($non_blue_header_title) && !$is_news): ?>
        <h1 class="node-title futura"><?php print $non_blue_header_title; ?></h1>
      <?php endif; ?>

      <?php hide($page['subsite_landing_below_tiles']); ?>
      <?php hide($page['subsite_landing_rhs']); ?>
      <?php print render($page['before_content']); ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($subsite_sidebar_second) && !empty($page['subsite_landing_rhs'])): ?>
      <aside class="sidebar-second-wrapper" role="complementary">
        <?php print render($page['subsite_landing_rhs']); ?>
      </aside>
    <?php endif; ?>
  </div>
  <?php if (isset($subsites) && (isset($subsites['below_tiles_blocks'])) && ($subsites['below_tiles_blocks']) && !empty($page['subsite_landing_below_tiles'])): ?>
    <div class="col-md-12">
      <?php print render($page['subsite_landing_below_tiles']); ?>
    </div>
  <?php endif; ?>
</div>
<?php print render($page['footer']); ?>
<?php if (!empty($page['shutter'])): ?>
  <?php print render($page['shutter']); ?>
<?php endif; ?>
