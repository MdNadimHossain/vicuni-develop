/**
 * @file
 * Homepage Hero title box.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryHeroTitleBox = {
    SELECTOR_HERO_TITLE_BOX: '.hero-title-box',
    SELECTOR_CAROUSEL: '.view-blocks-hero-title-box',
    SELECTOR_CAROUSEL_ITEM: '.views-row',
    SELECTOR_CAROUSEL_INDICATORS_PARENT: '.carousel-indicators',
    SELECTOR_CAROUSEL_INDICATOR: '.carousel-indicator',
    SELECTOR_CAROUSEL_CONTROL: '.carousel-control',
    attach: function (context, settings) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      $(window).on('ready', this.setOnReadyClass);
      this.initCarousel(context);
    },
    setOnReadyClass: function () {
      var self = Drupal.behaviors.victoryHeroTitleBox;
      var selector = self.SELECTOR_HERO_TITLE_BOX;
      $(selector).addClass(selector.substring(1) + '--loaded');
    },
    initCarousel: function (context) {
      var self = Drupal.behaviors.victoryHeroTitleBox;
      var $carousel = $(self.SELECTOR_CAROUSEL, context);
      // Initialise carousel behaviour.
      $carousel.once(function () {
        var $carouselItem = $(self.SELECTOR_CAROUSEL_ITEM, this);
        // Add the 'active' class on the first item.
        $(self.SELECTOR_CAROUSEL_ITEM, this).first().addClass('active');

        // Only show indicators if there are more than one slide.
        if ($carouselItem.length > 1) {
          // Build the carousel indicators.
          var indicators = $(self.SELECTOR_CAROUSEL_INDICATORS_PARENT, this);
          $.each($carouselItem, function (index) {
            var $li = $('<li>', {
              'class': self.SELECTOR_CAROUSEL_INDICATOR.substring(1),
              'role': 'link',
              'tabindex': 0,
              'data-target': self.SELECTOR_CAROUSEL,
              'data-slide-to': index
            });
            var $span = $('<span>', {class: 'sr-only'}).text('Featured item ' + (index + 1));
            $li.append($span);
            indicators.append($li);
          });

          // Build Play/Pause controls.
          var $pauseControl = $('<li>', {
            'class': 'carousel-control carousel-control--pause',
            'data-slide': 'pause'
          }).append('<a href="#"><span class="sr-only">Pause</span></a>');

          var $playControl = $('<li>', {
            'class': 'carousel-control carousel-control--play carousel-control--active',
            'data-slide': 'cycle'
          }).append('<a href="#"><span class="sr-only">Play</span></a>');

          // Append carousel indicators.
          indicators.append($pauseControl);
          indicators.append($playControl);

          $('li:first-child', indicators).addClass('active');
        }
      }).carousel({
        interval: 8000,
        pause: false
      });

      self.initCarouselControls();
    },

    initCarouselControls: function () {
      var self = Drupal.behaviors.victoryHeroTitleBox;
      var $carousel = $(self.SELECTOR_CAROUSEL);
      var $carouselControl = $(self.SELECTOR_CAROUSEL_CONTROL, $carousel);
      var $carouselIndicator = $(self.SELECTOR_CAROUSEL_INDICATOR, $carousel);

      // Adds support for pressing 'Enter' to navigate to a slide.
      $carouselIndicator.keypress(function (e) {
        if (e.which === 13) {
          var slide = $(this).data('slide-to');
          $(self.SELECTOR_CAROUSEL).carousel(slide);
        }
      });

      $carouselControl.click(function () {
        var self = Drupal.behaviors.victoryHeroTitleBox;
        var $carousel = $(self.SELECTOR_CAROUSEL);
        var $control = $(this);
        var activeClass = 'carousel-control--active';
        var $playControl = $('.carousel-control--play');
        var $pauseControl = $('.carousel-control--pause');
        var state = $control.data('slide');

        $(self.SELECTOR_CAROUSEL_CONTROL).removeClass(activeClass);
        $carousel.carousel(state);

        if (state === 'pause') {
          $pauseControl.addClass(activeClass);
        }
        else if (state === 'cycle') {
          $playControl.addClass(activeClass);
        }
      });
    }
  };
}(jQuery, Drupal));
