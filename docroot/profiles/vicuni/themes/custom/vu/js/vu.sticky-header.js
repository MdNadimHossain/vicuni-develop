/**
 * @file
 * Behaviours for Sticky header widget.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.vuStickyHeader = {
    attach: function (context, settings) {
      var offset = $('header[role="banner"]', document).offset().top + $('header[role="banner"]', document).outerHeight();
      var $header = $(Drupal.theme('stickyHeader')).appendTo('body');
      $header.attr('data-spy', 'affix');
      $header.attr('data-offset-top', offset);

      var $logo = $('#logo').clone().addClass('diamond-only');
      $logo.appendTo($header.find('.logo-container'));

      // Use node title or fallback to html <title> tag value.
      var pageTitle = $('.node-title', context).first().text().trim();
      if (pageTitle === '') {
        pageTitle = $('title', context).text();
        pageTitle = pageTitle.substring(0, pageTitle.indexOf('|')).trim();
      }
      $header.find('.page-title').text(pageTitle);

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
  Drupal.theme.prototype.stickyHeader = function () {
    var markup =
      '<div class="sticky-header">' +
      '  <div class="container">' +
      '    <div class="row">' +
      '      <div class="col-md-1 logo-container"></div>' +
      '      <div class="col-md-10 page-title"></div>' +
      '      <div class="col-md-1 search-container"></div>' +
      '    </div>' +
      '  </div>' +
      '</div>';

    return markup;
  };
}(jQuery, Drupal));
