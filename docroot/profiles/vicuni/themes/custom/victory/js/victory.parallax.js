/**
 * @file
 * Add Parallax to homepage carousel banner.
 */

/* global jQuery, window, Drupal */

(function ($, window, Drupal) {
  'use strict';
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.addParallax = {
    attach: function () {
      // Images to be positioned.
      var $parallaxItems = $('.js-parallax-container').find('img');

      // Wrapper to limit updates to one per animationframe.
      var queued = false;

      function queueUpdateParallax() {
        if (!queued) {
          window.requestAnimationFrame(updateParallax);
          queued = true;
        }
      }

      function updateParallax() {
        queued = false;
        var viewportTop = $(window).scrollTop();
        var viewportBottom = $(window).scrollTop() + $(window).height();
        var parallaxSpeed = -0.1;
        $parallaxItems.map(function () {
          var $parallaxItem = $(this);
          var $parent = $parallaxItem.parent();
          var containerTop = $parent.offset().top;
          var containerBottom = $parent.offset().top + $parent.height();
          var imgTranslate = ((containerTop - viewportTop) + (containerBottom - viewportBottom)) * parallaxSpeed;
          $parallaxItem.css('transform', 'translate3d(-50%, ' + imgTranslate + 'px, 0px)');
        });
      }

      if (window.matchMedia('(min-width: 1000px)').matches) {
        // Update on scroll.
        $(window).on('scroll', queueUpdateParallax);
        // Update carousel when the slides change.
        $('.carousel').on('slide.bs.carousel', queueUpdateParallax);
      }
    }
  };
}(jQuery, window, Drupal));
