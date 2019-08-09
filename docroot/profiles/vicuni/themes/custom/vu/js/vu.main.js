/**
 * @file
 * Main VU behaviors.
 */

/* global jQuery, Drupal, google */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.vuMain = {
    attach: function (context, settings) {
      $('body', context).removeClass('no-js');

      $('body').extLinks();

      $('.popover-trigger').popover({
        html: true,
        content: function () {
          return $($(this).attr('data-popover-content')).html();
        },
        container: 'body'
      });

      // Convert heading text to anchor friendly.
      function convert_title_to_anchor(h2_text) {
        var gotoText = h2_text.replace(/\s+/g, '-').replace(/[^A-Za-z0-9-]/, '').replace(/-+/, '-').toLowerCase();
        return 'goto-' + gotoText;
      }

      // Generate headings to anchor list.
      function generate_list_for_anchor(headings) {
        var items = '';
        $(headings).each(function () {
          var heading_id = typeof ($(this).attr('id')) !== 'undefined' ? $(this).attr('id') : convert_title_to_anchor($(this).text());
          if (!$(this).hasClass('element-invisible') && !$(this).hasClass('exclude-onthispage')) {
            items += '<div class="field-item"><a href="#' + heading_id + '">' + $(this).text() + '</a></div>';
          }
        });

        if (items.length > 0) {
          return items;
        }
      }

      // Dynamically generate “on this page” list for page builder and campus
      // housing content types.
      if ($('body').is('.node-type-campus-housing, .node-type-page-builder')) {
        $('.field-name-field-on-this-page .field-items').html(function () {
          var $headings = $('.region-content h2')
            .not('[data-neon-onthispage="false"]')
            .not('.accordion-heading')
            .not('.in-this-section > h2');
          $headings.each(function () {
            $(this).attr('id', convert_title_to_anchor($(this).text()));
          });

          return generate_list_for_anchor($headings);
        });
      }

      // Generate on this page link on fly for course page.
      $('.node-type-courses .field-name-field-on-this-page .field-items, .page-courses-international .field-name-field-on-this-page .field-items').html(function () {
        var selector = '.node-type-courses .region-content h2, .page-courses-international .region-content h2';
        $(selector).each(function () {
          if (typeof $(this).attr('id') === 'undefined') {
            $(this).attr('id', convert_title_to_anchor($(this).text()));
          }
        });

        // Exclude sidebar h2.
        $('.node-type-courses .region-content .right-sidebar h2, .page-courses-international .region-content .right-sidebar h2').addClass('exclude-onthispage');

        return generate_list_for_anchor(selector);
      });

      // Generate on this page link on fly for unit and unitsets.
      $('.field-name-field-on-this-page-on-fly').html(function () {
        jQuery('.unitsets-content-wrapper h2').each(function () {
          // Modify the title id attribute.
          var id = jQuery(this).text();
          var id_text = id;
          jQuery(this).attr('id', convert_title_to_anchor(id));

          // Add to on this page wrapper.
          jQuery('.field-name-field-on-this-page-on-fly .field-items').append('<div class="field-item"><a href="#' + convert_title_to_anchor(id) + '">' + id_text + '</a></div>');
        });
        jQuery('.field-name-field-on-this-page-on-fly .field-items').append('<div class="field-item"><a href="#goto-where-to-next">Where to next?</a></div>');
      });

      $('.field-name-field-on-this-page a, .aside-cta-box a[href^="#"], .node-topic-pages .anchor-list a').smoothScroll(60);

      $('.slideshow .homepage-featured-content .slideshow-slides').slick({
        infinite: true,
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: false,
        autoplay: true,
        autoplaySpeed: 8000,
        speed: 500,
        fade: true,
        dots: true,
        centerMode: true,
        appendDots: $('.featured-content-controller .dots'),
        customPaging: function (slider, i) {
          return '<button class="fa fa-circle" type="button" data-role="none" role="button" aria-required="false" tabindex="0"><span class="accessibility">' + (i + 1) + '</span></button>';
        }
      });

      // Play button.
      $('.featured-content-controller .play-button').click(function () {
        if ($('.pause-button').hasClass('active')) {
          $('.pause-button').removeClass('active');
          $(this).addClass('active');
          $('.slick-slider').slick('slickNext').slick('slickPlay').slick('setOption', 'pauseOnHover', true);
        }
      });

      // Pause button.
      $('.featured-content-controller .pause-button').click(function () {
        if ($('.play-button').hasClass('active')) {
          $('.play-button').removeClass('active');
          $(this).addClass('active');
          $('.slick-slider').slick('slickPause').slick('setOption', 'pauseOnHover', false);
        }
      });

      // Init slick on level 1.
      $('.level-1-featured-content ul', context).slick({
        dots: true,
        autoplay: true,
        autoplaySpeed: 8000,
        speed: 500,
        fade: true,
        arrows: false,
        appendDots: $('.level-1-featured-content-controller .dots'),
        customPaging: function (slider, i) {
          return '<button class="fa fa-circle" type="button" data-role="none" role="button" aria-required="false" tabindex="0"><span class="accessibility">' + (i + 1) + '</span></button>';
        }
      });

      // Play and pause button events.
      // Play button.
      $('.level-1-featured-content .play-button').click(function () {
        if ($('.pause-button').hasClass('active')) {
          $('.pause-button').removeClass('active');
          $(this).addClass('active');
          $('.slick-slider').slick('slickNext').slick('slickPlay').slick('setOption', 'pauseOnHover', true);
        }
      });

      // Pause button.
      $('.level-1-featured-content .pause-button').click(function () {
        if ($('.play-button').hasClass('active')) {
          $('.play-button').removeClass('active');
          $(this).addClass('active');
          $('.slick-slider').slick('slickPause').slick('setOption', 'pauseOnHover', false);
        }
      });

      // Level 2 and below FC.
      $('.slideshow .small-featured-content .slideshow-slides').slick({
        infinite: false,
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        autoplay: false,
        autoplaySpeed: 8000,
        speed: 300,
        fade: false,
        dots: true,
        centerMode: true,
        variableWidth: true,
        appendDots: $('.featured-content-controller .dots'),
        customPaging: function (slider, i) {
          return '<button class="fa fa-circle" type="button" data-role="none" role="button" aria-required="false" tabindex="0"><span class="accessibility">' + (i + 1) + '</span></button>';
        }
      });

      // Set resizeTimer to empty so it resets on page load.
      var resizeTimer;
      // Add a window resize function to target mobile behaviours.
      $(window).resize(function () {
        clearTimeout(resizeTimer);
        resizeTimer = setTimeout(resizeFunction, 250);
      });

      // Add a mobile class on load and resize.
      if ($(window).width() < 481) {
        $('body').addClass('window-sm');
        // Change campus sidebar boxes to an accordion on mobile.
        $('.campuses_sidebar_menu h2.block-title').on('click', function () {
          $('.campuses_sidebar_menu .menu-block-wrapper').slideToggle();
        });
      }

      // Feature Tile resizing.
      if ($('body.front').length > 0) {
        var $featureTile = $('.region-home-col-right .bean-feature-tile:last-child');
        if ($featureTile.length > 0) {
          if ($(window).width() >= 768) {
            // Check home page column heights.
            calculateFeatureTileHeight($featureTile);
          }
        }
      }

      function resizeFunction() {
        var winWidth = $(window).width();

        if (winWidth < 481) {
          $('body').addClass('window-sm');
          // Change campus sidebar boxes to an accordion on mobile.
          $('.campuses_sidebar_menu h2.block-title').on('click', function () {
            $('.campuses_sidebar_menu .menu-block-wrapper').slideToggle();
          });
        }
        else {
          $('body').removeClass('window-sm');
        }

        // Feature Tile resizing.
        if ($('body.front').length > 0) {
          var $featureTile = $('.region-home-col-right .bean-feature-tile:last-child');
          if ($featureTile.length > 0) {
            if (winWidth < 768) {
              $featureTile[0].style.paddingBottom = '';
            }
            else {
              calculateFeatureTileHeight($featureTile);
            }
          }
        }
      }

      function calculateFeatureTileHeight($featureTile) {
        var $left = $('.region-home-col-left').parent('.col-sm-8').height();
        var $right = $('.region-home-col-right').parent('.col-sm-4').height();

        // The padding bottom affects the total height.
        // If it's been manually set, remove this from the tested value.
        if ($featureTile.length > 0) {
          var padding_bottom = parseInt($featureTile.css('padding-bottom'), 10);
          if (padding_bottom > 54) {
            $right -= (padding_bottom - 54);
          }
        }

        if ($left > $right) {
          var $diff = $left - $right;
          var $bottom_pad = 54 + $diff;
          $featureTile[0].style.paddingBottom = $bottom_pad + 'px';
        }
        else {
          $featureTile[0].style.paddingBottom = '';
        }
      }

      // Make right side letters column sticky on page scroll, and highlighted.
      var $nav_group = $('.nav-group-az');
      var $nav_group_lis = $nav_group.find('li');
      var activeClass = 'active';

      function setActive($a) {
        if ($a.length && !$a.parent().is('.' + activeClass)) {
          $nav_group.find('li').removeClass(activeClass);
          $a.parent('li').addClass(activeClass);
        }
      }

      function setHighlightInterval() {
        return window.setInterval(function () {
          var $inview = $('.course-list-group:in-viewport:first').next();
          var $inviewId = '#' + $inview.attr('id');
          var $letter = $inviewId.substr($inviewId.length - 1);
          if ($.isNumeric($letter)) {
            $letter = 'a';
          }
          var $link = $nav_group_lis.find('a').filter('.letter-' + $letter);
          setActive($link);
        }, 500);
      }

      $nav_group
        .smoothScroll(0)
        .on('smoothscrollstart', function () {
          window.clearInterval($(this).data('highlightInterval'));
        })
        .on('smoothscrollend', function () {
          window.clearInterval($(this).data('highlightInterval'));
          $(this).data('highlightInterval', setHighlightInterval());
        })
        .data('highlightInterval', setHighlightInterval())
        .on('click', 'a', function () {
          setActive($(this));
        });

      var setStickyStatus = function () {
        $nav_group.each(function () {
          var $this = $(this);
          if ($this.parent('.tab-pane').hasClass('active')) {
            $this.stick_in_parent({
              offset_top: 20
            });
          }
          else {
            $this.trigger('sticky_kit:detach');
          }
        });
      };
      setStickyStatus();
      $('#block-vumain-course-list a[data-toggle="tab"]').on('shown.bs.tab', function () {
        setStickyStatus();
      });

      // Reformat markup for accordion on course page.
      if ($('.node-type-courses #description').length) {
        $('.node-type-courses #description .accordion').each(function () {
          $(this).prev().addClass('accordion-heading');
        });
      }
      var current = $();
      $('.node-type-courses #description .accordion-heading, .node-type-courses #description .accordion').each(function () {
        var $this = $(this);
        if ($this.hasClass('accordion-heading')) {
          current = $('<div class="accordion-container entity-accordion-item accordion-item-accordion-item"></div>').insertBefore(this);
        }
        current.append(this);
      });

      /* replicate existing accordions */
      $('.view-content > h3.view-heading').each(function () {
        $(this).nextUntil('.view-content > h3.view-heading').wrapAll('<div class="view-group"/>');

      });

      $('.entity-accordion-item > h2 > a').on('click', function (e) {
        e.preventDefault();
      });

      // Add hover class to homepage Tafe button.
      $('body.front .link-courses a.special-cta__link').hover(function () {
        $(this).closest('.link-courses').addClass('cta__hover');
      }, function () {
        $(this).closest('.link-courses').removeClass('cta__hover');
      });
      // Adds tooltip.
      $('[data-toggle="tooltip"]').tooltip();

      // Truncates overflowing texts and adds ellipsis to the end of the text.
      $('.in-this-section .ellipsis, .view-success-stories .field-content .excerpt').ellipsis({
        // Force ellipsis after 2 lines.
        lines: 2,
        // Class used for ellipsis wrapper and to namespace 'ellip' line.
        ellipClass: 'ellip',
        // Update on window resize. Default is false.
        responsive: true
      });

      // Add FA classes to sidebar lists, exclude the first i within first p.
      // It's meant for block background.
      var $sidebar = $('.sidebar-box', context);
      $sidebar.each(function () {
        var icons = $(this).find('i[class*="fa-"]');
        if (icons.length > 0 && !$(this).hasClass('sidebar-box--text-light-blue-bg')) {
          $(this).find('ul').addClass('fa-ul');
          icons.addClass('fa fa-li');
        }

        // Remove fa-li class.
        $(this).find('p:first-child i, .content-block__content > i').removeClass('fa-li');
      });

      // Automatically add span tag to h4 tag on important dates.
      $('.sidebar-box--important-dates li h4').each(function () {
        $(this).html($(this).html().replace(/\s([A-z]+)$/g, ' <span>$1</span>'));
      });

      // Make full testimonial tile clickable.
      function testimonial_click() {
        var href = $(this).find('.field-name-title a').attr('href');
        if (href.length > 1) {
          location.href = href;
        }
      }

      $('.tb-megamenu-column .vumain-latest-testimonial', context).on('click', testimonial_click);

      // Generate small interactive google maps on events pages.
      if ($('#campus-map-small').length) {
        var customIcon = 'http://oi39.tinypic.com/2zdnm8z.jpg';
        var zoom = 14;
        var address;
        var latLong;
        var mapType = google.maps.MapTypeId.ROADMAP;
        var markerTitle = '';
        if ($('#address-line2').length) {
          address = $('#address-line1').text() + ', ' + $('#address-line2').text();
        }
        if (typeof Drupal.settings.event_campus !== 'undefined') {
          if (typeof Drupal.settings.event_campus.address !== 'undefined') {
            address = Drupal.settings.event_campus.address;
          }
          if (typeof Drupal.settings.event_campus.zoom !== 'undefined') {
            zoom = Drupal.settings.event_campus.zoom;
          }
          if (typeof Drupal.settings.event_campus.title !== 'undefined') {
            markerTitle = Drupal.settings.event_campus.title;
          }
          if (typeof Drupal.settings.event_campus.lat_long !== 'undefined') {
            latLong = Drupal.settings.event_campus.lat_long;
          }
        }
        if (typeof address !== 'undefined') {
          var geocoder = new google.maps.Geocoder();
          geocoder.geocode({
            address: address
          }, function (results, status) {
            if (status === google.maps.GeocoderStatus.OK) {
              latLong = results[0].geometry.location;
            }
          });
        }
        else {
          if (typeof latLong === 'undefined' || !latLong[0]) {
            return;
          }
          latLong = new google.maps.LatLng(latLong[0].lat, latLong[0].long);
        }
        google.maps.event.addDomListener(window, 'load', function () {
          var mapOptions = {
            scrollwheel: false,
            zoom: zoom,
            center: latLong,
            mapTypeId: mapType
          };
          var map = new google.maps.Map(document.getElementById('campus-map-small'), mapOptions);

          new google.maps.Marker({
            position: latLong,
            map: map,
            icon: customIcon,
            title: markerTitle
          });
        });
      }

      // Keep all grouped screen reader elements visible if at least one of them
      // has focus.
      $('.js-sr-group-container', context).find('.js-sr-group-item').on('focus', function () {
        $(this).parents('.js-sr-group-container').find('.js-sr-group-item:not(.sr-only-focused)').addClass('sr-only-focused');
        // Notify everyone that screen-reader item received a focus.
        $(document).trigger('focus.sr-group-item', $(this));
      });
    }
  };
}(jQuery, Drupal));
