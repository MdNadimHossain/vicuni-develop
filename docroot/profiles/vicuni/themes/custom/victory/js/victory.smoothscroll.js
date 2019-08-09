/**
 * @file
 * JQuery SmoothScroll plugin.
 */

/**
 * Apply to links to anchors/IDs on the same page for smooth scrolling link behaviour.
 *
 * The preferred way to add this behaviour to a link or container is by adding a `data-smoothscroll` attribute to the element.
 */
(function ($, window, Drupal) {
  'use strict';

  Drupal.victory = Drupal.victory || {};
  Drupal.victory.smoothScroll = {
    attach: function () {
      calcOffset();
      callSmoothScroll();
      window.addEventListener('resize', function () {
        calcOffset();
      });
    }
  };

  function calcOffset() {
    // Calculate offset for smoothscroll.
    var offset = 0;
    if (window.matchMedia('(min-width: 1000px)').matches) {
      offset = $('.sticky-header').outerHeight();
    }
    else {
      offset = $('header[role="banner"]').outerHeight();
    }

    // Adjust offset if stick on page nav is present.
    if ($('.sticky-on-page-nav').length > 0 && window.matchMedia('(min-width: 1260px)').matches) {
      offset += $('.sticky-on-page-nav').outerHeight() + 38;
    }
    else if ($('.sticky-on-page-nav').length > 0) {
      offset += $('.sticky-on-page-nav').outerHeight() + 20;
    }
    Drupal.victory.smoothScroll.offset = offset;
  }

  function callSmoothScroll() {
    // Activate smooth scroll on targeted hrefs.
    $('[data-smoothscroll]').smoothScroll();
  }

  $.fn.smoothScroll = function () {

    // Grab all internal hrefs.
    $(this).each(function () {

      var $el = $(this);
      var sel = 'a[href^=#]';
      var _sel = $el.is(sel) ? null : sel;
      // We want to select children that match the selector,
      // or the current element if it matches the selector.
      $el.on('click', _sel, function () {
        // Mark as visited and unfocus.
        $(this).addClass('visited').blur();

        // Calculate offset again to capture height of open sticky nav.
        calcOffset();
        // Start event.
        $el.trigger('smoothscrollstart');

        // Determine target.
        var target = $('[id="' + decodeURIComponent(this.hash.slice(1)) + '"]');
        if (target.length > 0) {
          // Determine position.
          var targetOffset = target.offset().top - parseInt(Drupal.victory.smoothScroll.offset, 10);
          // Move the page.
          $('html,body').animate({
            scrollTop: targetOffset
          }, 800, 'swing', function () {
            $el.trigger('smoothscrollend');
          });
          return false;
        }
        return true;
      });
    });
    return this;
  };
}(jQuery, window, Drupal));
