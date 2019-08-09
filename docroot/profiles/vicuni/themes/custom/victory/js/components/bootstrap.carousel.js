/**
 * @file
 * Carousel activation.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryBootstrapCarousel = {
    attach: function (context, settings) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      var $carousel = $('.carousel', context);
      // Initialise carousel behaviour.
      $carousel.once(function () {
        // Add the 'active' class on the first item.
        $('.item:first-child', this).addClass('active');

        // Build the controls.
        var controls = $('<ol class="carousel-indicators"></ol>');
        $.each($('.item', this), function (index) {
          controls.append('<li data-target=".carousel" data-slide-to="' + index + '"></li>');
        });
        $('li:first-child', controls).addClass('active');
        $carousel.append(controls.get(0));
      }).carousel();

      // Attach media query behaviour.
      var media_query = window.matchMedia('(max-width: 767px)');
      this.media_query_response(media_query);
      media_query.addListener(this.media_query_response);
    },

    media_query_response: function (media_query) {
      $('.carousel').each(function () {
        $('.item', this).css('height', 'auto').parent().removeClass('carousel-inner');
        if (media_query.matches) {
          var maxHeight = 0;
          $('.item', this).parent().addClass('carousel-inner').end().each(function () {
            // Take height of biggest item.
            $(this).css('height', 'auto');
            maxHeight = $(this).height() > maxHeight ? $(this).height() : maxHeight;
          });
          $('.item', this).height(maxHeight);
        }
      });
    }
  };
}(jQuery, Drupal));
