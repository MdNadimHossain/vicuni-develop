/**
 * @file
 * Behaviours for Sticky CTA widget.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryStickyCTAs = {
    attach: function (context, settings) {
      // Don't attempt to attach if AJAX response or header present.
      if (context !== window.document || $('.sticky-cta').length) {
        return;
      }
      var $cta = $(Drupal.theme('victoryStickyCTA')).appendTo('body');

      if ($('.btn-apply', $cta).length > 0) {
        $('.btn-apply', $cta).attr('data-tracking', 'apply-sticky-cta');
      }
      else {
        $('.btn-register-interest', $cta).attr('data-tracking', 'register-sticky-cta');
      }

      $cta.affix({
        offset: {
          top: function () {
            var offset = (window.matchMedia('(min-width: 768px)').matches) ? 50 : 100;
            var offsetenquire = (window.matchMedia('(min-width: 768px)').matches) ? 30 : 100;
            if ($('.apply-block__button-container').length) {
              return $('.apply-block__button-container').offset().top + $('.apply-block__button-container').outerHeight() - offset;
            }
            else {
              return $('#block-vu-core-course-international-switcher').offset().top + $('#block-vu-core-course-international-switcher').outerHeight() - offsetenquire;
            }
          }
        }
      }).addClass('js-offcanvas-canvas');

      // Toggle class when sticky CTA toggled.
      $cta.on('affixed.bs.affix', function () {
        $('body').addClass('with-fixed-cta');
      }).on('affixed-top.bs.affix', function () {
        $('body').removeClass('with-fixed-cta');
      });
      $('body').addClass('with-fixed-cta');
    }
  };

  /**
   * Theme implementation for sticky CTA.
   *
   * @returns {string}
   *   CTA markup.
   */
  Drupal.theme.prototype.victoryStickyCTA = function () {
    var $cta = $('.apply-block__button-container');
    var enquire = '';
    var markup = '';
    if ($((('.btn-apply', $cta).length > 0) || (('.btn-apply-modal-open', $cta).length > 0)) && $('#goto-enquire-now').length > 0) {
      enquire = '<a href="#goto-enquire-now" class="btn btn-secondary" data-smoothscroll data-tracking="enquire-sticky-cta">Enquire</a>';
    }
    if ($('.apply-block__button-container').length) {
      markup = '<div class="sticky-cta">' + $cta.html() + enquire + '</div>';
    }
    else {
      markup = '<div class="sticky-cta">' + enquire + '</div>';
    }

    return markup;
  };
}(jQuery, Drupal));
