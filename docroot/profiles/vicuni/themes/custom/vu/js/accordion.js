// Reusable accordion plugin for VU theme.
(function(window, $) {
  'use strict';
  Drupal.behaviors.vu_accordion = {
    attach: function(context, settings) {
      $.fn.accordion = function(options) {
        // Settings can be overridden by passing in `options` object.
        // If you don't want a particular control set it to `false`.
        $.fn.accordion.defaultSettings = {
          className: 'accordion',
          toggleElement: 'H3',
          toggleIcon: false
        };
        var settings = $.extend(true, {}, $.fn.accordion.defaultSettings, options);
        var clickHandler = function() {
          var state = {};
          var toggle = $(this).hasClass('accordion-heading') ? $(this) : $(this).parents('.accordion-container').find('.accordion-heading');
          var data_target = toggle.attr('data-target').replace('#', '');
          var accordion = $(toggle.attr('data-target'));
          var open = !accordion.hasClass('in') ? 1 : 0; // Should we open the
          // accordion?
          state[data_target] = open;
          $.bbq.pushState(state);
          toggle.toggleClass('open');

          if ($(toggle).find('span.text-toggle').length > 0) {
            if ($(toggle).hasClass('open')) {
              $(toggle).find('span.text-toggle').html($(toggle).find('span.text-toggle').attr('data-text-toggle-off'));
            }
            else {
              $(toggle).find('span.text-toggle').html($(toggle).find('span.text-toggle').attr('data-text-toggle-on'));
            }
          }

        };

        function toSlug(str) {
          str = str.replace(/[^a-zA-Z0-9\s]/g, '');
          str = str.toLowerCase();
          str = str.replace(/\s/g, '-');
          return str;
        }

        this.each(function(i) {
          var $accordion = $(this);
          var $inner_class = settings.className + '-inner';

          // Get the preceding heading to toggle accordion on/off.
          var $toggle = $accordion.prev();

          // Make it collapsible.
          $accordion.addClass('collapse');

          // Append the accordion's inner container if it does not exist.
          if ($accordion.children('.' + $inner_class).length == 0) {
            $accordion.wrapInner("<div class='" + $inner_class + "'></div>");
          }
          if ($toggle.length <= 0) {
            // Continue to next accordion by returning non-false.
            return true;
          }
          // Give the accordion element an ID if it doesn't have one.
          if (typeof $accordion.attr('id') === 'undefined') {
            var id = 'goto-' + toSlug($toggle.text());
            // ID exists, append counter.
            if ($('#' + id).length) {
              id += '-' + (i);
            }
            $accordion.attr('id', id);
          }
          // Assign attributes to toggle element.
          if (settings.toggleIcon) {
            $toggle.prepend('<i class="fa fa-plus-circle fa-sm"></i><i class="fa fa-minus-circle fa-sm"></i>');
          }
          $toggle.on('click', clickHandler)
            .attr('data-toggle', 'collapse')
            .attr('data-target', '#' + $accordion.attr('id'))
            .addClass(settings.className + '-heading');
        });
        var closeButton = $('.accordion .close-link a');
        closeButton.on('click', clickHandler)
          .on('click', function() {
            $(this).parents('.accordion').toggleClass('in');
          });
        return this;
      };

      // Activate all accordions!
      $('.accordion', context).accordion();

      // Maintain the accordion state on page reload.
      $(window).on('load', function() {
        // If there is a single accordion in the hash we scroll to it
        // but if there are 0 or more than one we don't.

        // Let's start by getting all the non-zero IDs from the hash
        // that refer to accordions.
        var hash = $.deparam.fragment();
        var $openAccordions = Object.keys(hash).reduce(function($acc, key) {
          if (hash[key] !== '0') {
            return $acc.add($('.accordion#' + key));
          }
          return $acc;
        }, $());

        // Now if there is only 1 item we can scroll to it.
        if ($openAccordions.length === 1) {
          $('html, body', context).animate({
            scrollTop: ($openAccordions.prev().offset().top - 5)
          }, 200);
        }
      });

      // Maintain accordion state when browser back button is clicked.
      $(window).on('hashchange', function() {
        // Iterate over all accordions and open if $bbq state is set
        $('.accordion', context).each(function() {
          var open = $.bbq.getState($(this).attr('id'), true) || 0;
          if (open > 0) {
            var toggle = $(this, context).prev();
            $(this, context).addClass('in');
            toggle.addClass('open').find('span.text-toggle').html($(toggle).find('span.text-toggle').attr('data-text-toggle-off'));
          }
        });
      }).trigger('hashchange');
    }
  }
}(window, window.jQuery));
