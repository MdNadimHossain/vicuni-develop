/**
 * @file
 * Legacy content accordions :(.
 */

/* global jQuery, Drupal */
(function ($, window, Drupal) {
  'use strict';

  Drupal.victory = Drupal.victory || {};
  Drupal.victory.victoryAccordion = {
    attach: function (context, settings) {
      // SVG icon for accordion expand/collapse.
      var iconMarkup = '<span aria-hidden="true" class="accordion-title-icon"><!--?xml version="1.0" encoding="UTF-8" standalone="no"?--><svg width="26px" height="26px" viewBox="0 0 26 26" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink"><g class="victory-svg__cross" fill="#B0B0B0"><path d="M12,12 L1.18181818,12 C0.529118023,12 0,12.4477153 0,13 C0,13.5522847 0.529118023,14 1.18181818,14 L12,14 L12,24.8181818 C12,25.470882 12.4477153,26 13,26 C13.5522847,26 14,25.470882 14,24.8181818 L14,14 L24.8181818,14 C25.470882,14 26,13.5522847 26,13 C26,12.4477153 25.470882,12 24.8181818,12 L14,12 L14,1.18181818 C14,0.529118023 13.5522847,0 13,0 C12.4477153,0 12,0.529118023 12,1.18181818 L12,12 Z" id="Combined-Shape"></path></g></svg></span>';
      // For generating the id from the heading.
      var toSlug = function (str) {
        str = str.replace(/[^a-zA-Z0-9\s]/g, '');
        str = str.toLowerCase();
        str = str.replace(/\s/g, '-');
        return str;
      };

      // Not all accordions are this crap.
      $('.accordion', context).each(function () {
        var $this = $(this);

        // If the markup is correct already we don't need to touch it.
        if ($this.find('.accordion-inner > .accordion-heading').length) {
          return;
        }
        // Possibly accordion heading?
        var $heading = $this.prev();

        // That's right. It's [H3 + div.accordion].
        if ($heading.prop('tagName') !== 'H3') {
          return;
        }

        // Remove inner anchor tag if present.
        if ($heading.find('a').attr('href') === '#') {
          var text = $heading.find('a').text();
          if (text !== 'undefined') {
            $heading.text(text);
          }
        }

        var id = $this.attr('id');
        // Give the accordion element an ID if it doesn't have one.
        if (typeof id === 'undefined') {
          id = 'goto-' + toSlug($heading.text());
          // ID exists, append counter.
          if ($('#' + id).length) {
            var i = 1;
            // Find the next available number.
            while ($('#' + id + '-' + (i)).length) {
              i++;
            }
            id += '-' + (i);
          }
          $this.attr('id', id);
        }

        var accordionSelector = '#' + id;
        var headingId = id + '-heading';
        var contentId = id + '-content';
        var contentSelector = '#' + contentId;

        // This just generates the markup to match the victory accordions.
        $this.wrapInner($('<div/>')
          .attr('id', contentId)
          .attr('aria-labelledby', headingId)
          .addClass('accordion-content')
          .addClass('collapse'));
        $this.wrapInner('<div class="accordion-inner"></div>');
        $heading.prependTo($this.find('.accordion-inner'));
        $heading.replaceWith(function () {
          return $('<h3/>', {
            html: $('<a/>')
              .attr('role', 'button')
              .attr('data-toggle', 'collapse')
              .attr('data-parent', accordionSelector)
              .attr('aria-expanded', 'false')
              .attr('aria-controls', contentId)
              .attr('href', contentSelector)
              .html(this.innerHTML + iconMarkup)
          }).attr('id', headingId);
        });
      });
    }
  };
})(jQuery, window, Drupal);
