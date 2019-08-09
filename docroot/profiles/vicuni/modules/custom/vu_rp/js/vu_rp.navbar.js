/**
 * @file
 * Behaviours for VU Research Profile node navbar.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';

  Drupal.behaviors.vuRpNodeNavbar = {
    attach: function (context, settings) {
      this.initTabs(context);

      this.initMobileTabs(context);

      this.initContactButtonAndModal(context);

      this.initAccordions(context);
    },

    initTabs: function (context) {
      // @todo: Replace this with proper tabs that can read from URL target.
      $('.js-researcher-profile-navbar-item', context).on('click', function () {
        var $this = $(this);
        $this.siblings().not($this).removeClass('researcher-profile-navbar-item-selected');
        $this.addClass('researcher-profile-navbar-item-selected');

        var sectionId = $(this).attr('id');
        var $section = $('article.researcher-profile #' + sectionId, context);
        $('.js-researcher-content-section', context).not($section).removeClass('js-researcher-content-section-selected');
        $section.addClass('js-researcher-content-section-selected');
      }).first().click();
    },

    initMobileTabs: function (context) {
      // @todo: Refactor this to use a single widget for all tabs.
      $('.researcher-profile-nav-container-select .selected', context).on('click', function () {
        $('.researcher-profile-nav-container-select .xs-navbar-item', context).slideToggle(100);
      });

      $('.researcher-profile-nav-container-select .xs-navbar-item').on('click', function () {
        var $this = $(this);
        $this.siblings().not($this).removeClass('active');
        $this.addClass('active');

        var sectionId = $this.attr('id');
        var sectionName = $this.text();
        $('.researcher-profile-nav-container-select .selected span').text(sectionName);
        $('.researcher-profile-nav-container-select .xs-navbar-item').hide(150);

        var $section = $('article.researcher-profile #' + sectionId, context);
        $('.js-researcher-content-section', context).not($section).removeClass('js-researcher-content-section-selected');
        $section.addClass('js-researcher-content-section-selected');
      }).first().click();
    },

    initContactButtonAndModal: function (context) {
      var pageTitle = $('title', context).first().text();
      var name = pageTitle.substring(0, pageTitle.indexOf('|')).trim();

      // Create Contact button in the header.
      $('.js-search-container', context).prepend('<button class="btn btn-secondary researcher-make-contact js-researcher-make-contact">Contact ' + name + '</button>');

      // Create Contact button in the footer.
      if ($(window).width() < 1000) {
        $('.js-back-to-top-target', context).prepend('<button class="btn btn-secondary researcher-make-contact js-researcher-make-contact">Contact ' + name + '</button>');
      }

      $('.js-researcher-make-contact', context).on('click', function () {
        $('.js-researcher-overview-contact-details-modal').modal({
          backdrop: 'static',
          keyboard: true,
          show: true
        });
      });
    },

    initAccordions: function (context) {
      // Need to find a better way to expand accordions by default.
      // @todo: place accordion related JS in a separate file.
      $('.node-type-researcher-profile #career div.show-more', context).on('click', function () {
        $(this).parent().find('table tr.more').slideToggle(400);
      });
    }
  };
}(jQuery));
