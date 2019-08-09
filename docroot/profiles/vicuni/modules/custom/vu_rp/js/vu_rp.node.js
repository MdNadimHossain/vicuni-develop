/**
 * @file
 * Behaviours for VU Research Profile node.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';

  Drupal.behaviors.vuRpNode = {
    attach: function (context, settings) {
      this.initTableExpandCollapse(context);

      this.initPhoto(context);

      this.initAccordions(context);
    },

    initTableExpandCollapse: function (context) {
      $('.js-show-more-table-cell ', context).click(function (evt) {
        evt.preventDefault();
        var $this = $(this);

        var showMore = function ($el, searchText, replaceText, searchClass, replaceClass, displayRow) {
          var $text = $el.find('span');
          $text.text($text.text().replace(searchText, replaceText));
          $el.removeClass(searchText).addClass(replaceText);
          $el.find('i.fa').removeClass(searchClass).addClass(replaceClass);
          $el.prev().find('tbody tr:nth-child(3) ~ tr').css('display', displayRow);
        };

        if ($this.hasClass('more')) {
          showMore($this, 'more', 'less', 'fa-angle-down', 'fa-angle-up', 'table-row');
        }
        else {
          showMore($this, 'less', 'more', 'fa-angle-up', 'fa-angle-down', 'none');
        }
      });
    },

    initPhoto: function (context) {
      // Move researcher profile photo to the first tab and make it available
      // in mobile only.
      $('.js-researcher-photo:not(.processed)', context)
        .first()
        .addClass('processed')
        .clone()
        .addClass('visible-xs-inline')
        .prependTo('.js-researcher-photo-target')
        .wrap('<div class="researcher-photo-wrapper text-center"></div>');
    },

    initAccordions: function (context) {
      $('.js-accordion-wrapper', context).each(function () {
        var $this = $(this);
        var startOpen = false;
        if ($this.hasClass('js-accordion-state-open-xs') && $(window).width() < 1023) {
          startOpen = true;
        }

        if ($this.hasClass('js-accordion-state-open-md') && $(window).width() > 1023) {
          startOpen = true;
        }

        if (startOpen) {
          $('.accordion .accordion-inner h3 a', $this).click();
          $('.accordion-inner', $this).css('border-bottom', 'border-bottom: none !important');
        }
      });
    }
  };
}(jQuery));
