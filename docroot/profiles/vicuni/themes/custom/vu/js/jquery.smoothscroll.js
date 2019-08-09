/**
 * jQuery SmoothScroll plugin
 *
 * Apply to links to anchors/IDs on the same page for smooth scrolling
 * link behaviour.
 *
 * The preferred way to add this behaviour to a link or container is by adding
 * a `data-smoothscroll` attribute to the element.
 */
(function($, window, undefined) {

  'use strict';

  $.fn.smoothScroll = function(offset) {

    // Grab all internal hrefs
    $(this).each(function() {

      var $el = $(this);
      var sel = 'a[href^=#]';
      var _sel = $el.is(sel) ? null : sel;
      // We want to select children that match the selector,
      // or the current element if it matches the selector.
      $el.on('click', _sel, function() {
        // Mark as visited and unfocus
        $(this).addClass('visited').blur();

        // Start event
        $el.trigger('smoothscrollstart');

        // Determine target
        var target = $('[id="' + decodeURIComponent(this.hash.slice(1)) + '"]');
        if (target.length > 0) {
          // Determine position
          var targetOffset = target.offset().top - parseInt(offset, 10);
          // Move the page
          $('html,body').animate({
            scrollTop: targetOffset
          }, 450, 'swing', function() {
            $el.trigger('smoothscrollend');
          });
          return false;
        }
        return true;
      });
    });
    return this;
  };

  $(function() {

    // Activate smooth scroll on targeted hrefs
    $('[data-smoothscroll]').smoothScroll(0);

  });

}(window.jQuery, window));
