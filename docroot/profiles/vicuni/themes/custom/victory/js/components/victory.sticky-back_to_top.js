/**
 * @file
 * Behaviours for Sticky Back to Top widget.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryStickyBackToTop = {
    attach: function (context, settings) {
      // Don't attempt to attach if AJAX response or back to top widget present.
      if (context !== window.document || $('.sticky-b2t').length) {
        return;
      }

      // Attach Back to Top anchor.
      if ($('#top', context).length <= 0) {
        $(Drupal.theme('victoryBackToTopAnchor')).prependTo('body');
      }

      // Attach sticky Back to Top widget.
      var $btt = $(Drupal.theme('victoryStickyBackToTop')).appendTo('body');
      var $print = $(Drupal.theme('victoryStickyPrint')).appendTo('body.print-friendly');
      $btt.affix({
        offset: {
          top: function () {
            // If Sticky CTA and <= MD, passthrough to sticky CTA offset.
            if ($('.sticky-cta').length > 0 && window.matchMedia('(max-width: 999px)').matches) {
              return $('.sticky-cta').data('bs.affix').options.offset.top();
            }
            return (window.matchMedia('(max-width: 999px)').matches) ? 500 : 645;
          }
        }
      }).addClass('js-offcanvas-canvas js-back-to-top-target');

      $print.affix({
        offset: {
          top: function () {
            // If Sticky CTA and <= MD, passthrough to sticky CTA offset.
            return (window.matchMedia('(max-width: 999px)').matches) ? 500 : 645;
          }
        }
      }).addClass('js-offcanvas-canvas js-back-to-top-target');
      $('a.btn', $btt).on('mousedown', function () {
        // Track percentage down the page.
        $(this).attr('data-tracking2', Math.round(100 * $(window).scrollTop() / ($(document).height() - $(window).height())));

        // Track active section.
        if (typeof $('body').data('bs.scrollspy') !== 'undefined') {
          var data = $('body').data('bs.scrollspy');
          $(this).removeAttr('data-tracking3');
          if (typeof data.activeTarget !== 'undefined') {
            $(this).attr('data-tracking3', $(data.selector + '[href="' + data.activeTarget + '"] span:first').text());
          }
        }
      });

      $('.sticky-print').on('click', function () {
        window.print();
      });
    }
  };

  /**
   * Theme implementation for sticky Back to Top.
   *
   * @returns {string}
   *   Back to Top markup.
   */
  Drupal.theme.prototype.victoryStickyBackToTop = function () {
    return '<div class="sticky-btt"><a class="btn btn-primary" href="#top" title="Back to Top" data-smoothscroll data-tracking="back-to-top">Top</a></div>';
  };

  /**
   * Theme implementation for sticky print.
   *
   * @returns {string}
   *   Back to Top markup.
   */
  Drupal.theme.prototype.victoryStickyPrint = function () {
    return '<div class="sticky-print"><a class="btn btn-primary" title="Print" data-tracking="print-page">Print</a></div>';
  };

  /**
   * Theme implementation for Back to Top anchor.
   *
   * @returns {string}
   *   Back to Top anchor markup.
   */
  Drupal.theme.prototype.victoryBackToTopAnchor = function () {
    return '<a id="top" />';
  };

}(jQuery, Drupal));
