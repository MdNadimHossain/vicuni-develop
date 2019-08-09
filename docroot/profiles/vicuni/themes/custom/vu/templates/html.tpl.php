<?php

/**
 * @file
 * Theme implementation to display the basic html structure of a single page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $html_attributes:  String of attributes for the html element. It can be
 *   manipulated through the variable $html_attributes_array from preprocess
 *   functions.
 * - $html_attributes_array: An array of attribute values for the HTML element.
 *   It is flattened into a string within the variable $html_attributes.
 * - $body_attributes:  String of attributes for the BODY element. It can be
 *   manipulated through the variable $body_attributes_array from preprocess
 *   functions.
 * - $body_attributes_array: An array of attribute values for the BODY element.
 *   It is flattened into a string within the variable $body_attributes.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string
 *   parts
 *   that were used to generate the $head_title variable, already prepared to
 *   be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other
 *   dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see bootstrap_preprocess_html()
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup templates
 */
?><!DOCTYPE html>
<html<?php print $html_attributes; ?><?php print $rdf_namespaces; ?>>
<head>
  <link rel="profile" href="<?php print $grddl_profile; ?>"/>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
  <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <?php print $scripts; ?>
  <link href="//maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet">
  <script src="//use.typekit.net/vnw2lhd.js"></script>
  <script type="text/javascript">try {
      Typekit.load();
    } catch (e) {
    }</script>
</head>
<body<?php print $body_attributes; ?>>
<?php if (!empty($page_prefix)): ?>
  <?php print $page_prefix; ?>
<?php endif; ?>
<div id="skip-link" class="js-sr-group-container" aria-hidden="false" data-fixed-block-target=".js-fixed-mobile-header">
  <div class="container">
    <div class="column-left">
      <a href="#main-content" class="skip-to-main-content sr-only sr-only-focusable js-sr-group-item" role="link"><?php print t('Skip to content'); ?></a>
      <span class="sr-only sr-only-focusable js-sr-group-item" data-sr-group-type="item"><?php print t('|');?></span>
      <a href="/search/vu" class="skip-to-search sr-only search js-responsive-menu-ignore shutter-trigger js-sr-group-item" data-toggle="modal" data-sr-group-type="item" data-target=".region-shutter" data-shutter-item-target="#block-vu-core-vu-funnelback-search" role="link"><?php print t('Skip to search');?></a>
    </div>
    <div class="column-right">
      <a href="/about-us/vision-mission/accessibility-of-our-website" class="accessibility-information sr-only sr-only-focusable js-sr-group-item" role="link"><?php print t('Accessibility information'); ?></a>
      <button type="button" class="close sr-only js-sr-group-item" data-target="#skip-link" data-dismiss="alert" role="button">
        <span aria-hidden="true">&times;</span><span class="sr-only">Close</span>
      </button>
    </div>
  </div>
</div>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>
</body>
</html>
