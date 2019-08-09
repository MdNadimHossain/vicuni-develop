/**
 * @file
 * Behaviours for Sticky header widget.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryStickyHeader = {
    attach: function (context, settings) {
      // Don't attempt to attach if AJAX response or header present.
      if (context !== window.document || $('.sticky-header').length) {
        return;
      }
      var offset = $('header[role="banner"]', context).offset().top + $('header[role="banner"]', context).outerHeight();
      var $header = $(Drupal.theme('victoryStickyHeader')).appendTo('body');
      $header.attr('data-spy', 'affix');
      $header.attr('data-offset-top', offset);

      var $logo = $('#logo').clone().addClass('diamond-only');
      $logo.appendTo($header.find('.logo-container'));

      // Use node title or fallback to html <title> tag value.
      var pageTitle = $('.node-title', context).first().text().trim();
      if (pageTitle === '') {
        pageTitle = $('title', context).first().text();
        pageTitle = pageTitle.substring(0, pageTitle.indexOf('|')).trim();
      }
      $header.find('.page-title span').text(pageTitle);

      var $searchTrigger = $('.nav [data-shutter-item-target="#block-vu-core-vu-funnelback-search"]', context).first().clone();
      $searchTrigger.appendTo($header.find('.search-container'));
    }
  };

  /**
   * Theme implementation for sticky header.
   *
   * @returns {string}
   *   Header markup.
   */
  Drupal.theme.prototype.victoryStickyHeader = function () {
    var markup =
      '<div class="sticky-header"><div class="container"><div class="col-md-7 col-lg-8"><div class="logo-container"></div><div class="page-title"><span></span></div></div><div class="col-md-5 col-lg-4 search-container js-search-container"></div></div></div>';

    return markup;
  };
}(jQuery, Drupal));
