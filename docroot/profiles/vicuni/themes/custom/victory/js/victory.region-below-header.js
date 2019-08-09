/**
 * @file
 * Javascript behaviours for region below header section in course pages.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreRegionBelowHeader = {
    attach: function (context, settings) {
      var height = $('#block-ds-extras-course-essentials').height();
      var event_height = $('#event-essentials-block').height();
      var event_cta_height = $('#event-cta-button').height();
      function TabMarginCtaIntSwtch() {
        if ($(window).width() >= 768 && $(window).width() <= 999) {
          $('#block-vu-core-course-international-switcher').css('margin-top', (height - 119) + 'px');
          $('#block-vu-core-vu-cbs-hta-apply-cta').css('top', (height - 45) + 'px');
        }
      }

      function TabMarginIntSwtch() {
        if ($(window).width() >= 768 && $(window).width() <= 999) {
          $('#block-vu-core-course-international-switcher').css('margin-top', (height - 114) + 'px');
        }
      }

      $('#block-vu-core-vu-cbs-hta-apply-cta').css('top', (height - 20) + 'px');
      if ($('#block-vu-core-vu-cbs-hta-apply-cta').length) {
        $('#block-vu-core-course-international-switcher').css('margin-top', (height - 93) + 'px');
        $(window).load(TabMarginCtaIntSwtch);
      }
      else {
        $('#block-vu-core-course-international-switcher').css('margin-top', (height - 104) + 'px');
        $(window).load(TabMarginIntSwtch);
      }

      function EventContentMargin() {
        if ($('#event-cta-button').length) {
          if (($(window).width() < 768)) {
            $('.node-events.view-mode-victory').css('margin-top', ((event_height + event_cta_height) - 7) + 'px');
          }
          else {
            $('.node-events.view-mode-victory').css('margin-top', (event_height - 49) + 'px');
          }
        }
        else {
          if (($(window).width() < 768)) {
            $('.node-events.view-mode-victory').css('margin-top', ((event_height + 11)) + 'px');
          }
          else {
            $('.node-events.view-mode-victory').css('margin-top', (event_height - 44) + 'px');
          }
        }
      }

      if ($('#event-essentials-block').length) {
        if ($('#block-workbench-block.block.block-workbench.contextual-links-region').length) {
          $('#event-essentials-block').css({position: 'initial', width: '100%'});
          $('.node-events.view-mode-victory').css('margin-top', '0px');
          $('#event-cta-button').css('margin-bottom', 10 + 'px');
        }
        else {
          $(window).load(EventContentMargin);
        }
      }

      // Adding accordion class on event type page.
      function EventContentAccordion() {
        if ($('.node-type-events .event-content-left .accordion').length) {
          $('.accordion').parent().addClass('field-item-accordion');
        }
      }
      $(window).load(EventContentAccordion);

      // Adding class to the switcher when there is one version of a course.
      if ($('#block-vu-core-course-international-switcher .one-version-only').length) {
        $('#block-vu-core-course-international-switcher').addClass('one-version-of-course');
      }
    }
  };
})(jQuery);
