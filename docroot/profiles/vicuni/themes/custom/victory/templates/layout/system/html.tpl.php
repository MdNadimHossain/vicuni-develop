<?php

/**
 * @file
 * Victory theme implementation to display the basic html structure.
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
  <script src="https://cdn.jsdelivr.net/html5shiv/3.7.3/html5shiv-printshiv.min.js"></script>
  <![endif]-->
  <?php print $scripts; ?>
</head>
<body<?php print $body_attributes; ?>>
<?php if (!empty($page_prefix)): ?>
  <?php print $page_prefix; ?>
<?php endif; ?>
<div id="skip-link" aria-hidden="false" data-sr-group-type="container" data-fixed-block-target=".js-fixed-mobile-header">
  <div class="container">
    <div class="column-left">
      <a href="#main-content" class="skip-to-main-content sr-only sr-only-focusable" data-sr-group-type="item" role="link"><?php print t('Skip to content');?></a>
      <span class="sr-only sr-only-focusable" data-sr-group-type="item"><?php print t('|');?></span>
      <a href="/search/vu" class="skip-to-search sr-only search js-responsive-menu-ignore shutter-trigger" data-toggle="modal" data-sr-group-type="item" data-target=".region-shutter" data-shutter-item-target="#block-vu-core-vu-funnelback-search" role="link"><?php print t('Skip to search');?></a>
    </div>
    <div class="column-right">
      <a href="/about-us/vision-mission/accessibility-of-our-website" class="accessibility-information sr-only sr-only-focusable" data-sr-group-type="item" role="link"><?php print t('Accessibility information'); ?></a>
      <button type="button" class="close sr-only" data-sr-group-type="item" data-dismiss-sr="#skip-link" role="button">
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
