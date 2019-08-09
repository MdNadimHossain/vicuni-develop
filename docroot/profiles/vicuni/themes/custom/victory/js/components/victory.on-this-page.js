/**
 * @file
 * On this page nav JS.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  // Migrated legacy VU theme slug function.
  function convert_title_to_anchor(h2_text) {
    var gotoText = h2_text.replace(/\s+/g, '-').replace(/[^A-Za-z0-9-]/, '').replace(/-+/, '-').toLowerCase();
    return 'goto-' + gotoText;
  }

  // Create a usable handler event for Overview.
  function overviewScrollEvent(e) {
    if ($('#block-vu-core-vu-on-page-nav__content li.active').length < 1) {
      // Reset title.
      $('#block-vu-core-vu-on-page-nav h2.block-title').html($('#block-vu-core-vu-on-page-nav h2.block-title').attr('data-title'));
      $(window).off('scroll', overviewScrollEvent);
    }
    else if ($('#block-vu-core-vu-on-page-nav__content li.active:first').text() !== 'Overview') {
      // Unbind.
      $(window).off('scroll', overviewScrollEvent);
    }

  }

  // Migrated legacy VU theme: convert headings to anchor list.
  function generate_list_for_anchor(headings) {
    var items = '';

    $(headings).each(function () {
      var heading_id = typeof ($(this).attr('id')) !== 'undefined' ? $(this).attr('id') : convert_title_to_anchor($(this).text());
      if (!$(this).hasClass('element-invisible') && !$(this).hasClass('exclude-onthispage') && $(this).is(':visible')) {
        var title = $(this).attr('data-short-title') ? $(this).attr('data-short-title') : $(this).text();
        if (heading_id !== 'goto-enquire-now') {
          items += '<li class="on-page-nav__' + heading_id + '"><a href="#' + heading_id + '" class="on_this_page" data-smoothscroll><span>' + title + '</span></a></li>';
        }
      }
    });

    if (items.length > 0) {
      // Apply the 'nav' class to the <ul> for the content region variant for the ScrollSpy functionality.
      var ul_class = '';
      if ($('.region-below-header #block-vu-core-vu-on-page-nav').length > 0) {
        ul_class = ' class="nav"';
      }

      return '<ul' + ul_class + '>' + items + '</ul>';
    }
  }

  var self = Drupal.behaviors.victoryOnThisPage = {
    BLOCK_ID: '.title-box__feature #block-vu-core-vu-on-page-nav',
    CONTENT_ID: '#block-vu-core-vu-on-page-nav__content',
    MAX_HEIGHT: 315,

    menu_items: null,
    mobile: window.matchMedia('(max-width: 767px)'),

    attach: function (context) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }

      // Populate legacy JS based menu.
      $('.node-type-courses ' + self.CONTENT_ID + ', .page-courses-international ' + self.CONTENT_ID).html(function () {
        var selector = '.node-type-courses div.main-content h2.victory-title__stripe, .page-courses-international div.main-content h2.victory-title__stripe';
        $(selector).each(function () {
          if (typeof $(this).attr('id') === 'undefined') {
            $(this).attr('id', convert_title_to_anchor($(this).text()));
          }
        });

        // Exclude sidebar h2. This currently has to target .col-md-4.
        $('.node-type-courses div.main-content .col-md-4 h2, .page-courses-international div.main-content .col-md-4 h2').addClass('exclude-onthispage');

        return generate_list_for_anchor(selector);
      });

      // Save initial menu state.
      if (self.menu_items === null) {
        self.menu_items = $(self.CONTENT_ID).html();
      }

      // Attach window resize handling.
      if ($('.region-below-header #block-vu-core-vu-on-page-nav', context).length < 1) {
        $(window).resize(function () {
          self.reflow();
        });
        self.reflow();
      }

      // Sticky behaviour.
      // Don't attempt to attach if AJAX response or on page nav present.
      if (context !== window.document || $('.sticky-on-page-nav').length || $('.region-below-header #block-vu-core-vu-on-page-nav', context).length < 1) {
        return;
      }

      var $srcOnPageNav = $('.region-below-header #block-vu-core-vu-on-page-nav', context);
      var $dstOnPageNav = $srcOnPageNav.clone().addClass('affix-top').appendTo('body');

      // Adjust tracking class.
      $('.on_this_page', $dstOnPageNav).addClass('on_this_page--sticky').removeClass('on_this_page');

      var offset = $srcOnPageNav.offset().top - $srcOnPageNav.outerHeight();
      $dstOnPageNav.addClass('sticky-on-page-nav js-offcanvas-canvas')
        .attr('data-spy', 'affix')
        .attr('data-offset-top', offset);

      // ScrollSpy functionality.
      $('body').attr('data-spy', 'scroll')
        .attr('data-target', '#block-vu-core-vu-on-page-nav__content')
        .attr('data-offset', $srcOnPageNav.outerHeight() + 95);
      $('#block-vu-core-vu-on-page-nav__content').on('activate.bs.scrollspy', function () {
        $('#block-vu-core-vu-on-page-nav h2.block-title').html($('li.active', this).text());
        // This is to reset the title of on this page when scrolling back to the top.
        if ($('li.active', this).text() === 'Overview') {
          $(window).on('scroll', overviewScrollEvent);
        }
      });

      // Synchronize nav collapse state.
      $('#block-vu-core-vu-on-page-nav').on('hide.bs.collapse', function () {
        $('.collapse', $dstOnPageNav).collapse('hide');
      }).on('show.bs.collapse', function () {
        $('.collapse', $dstOnPageNav).collapse('show');
      });

      // Collapse nav after smoothscroll.
      $('.main-content #block-vu-core-vu-on-page-nav__content a').bind('smoothscrollstart', function () {
        $('.main-content #block-vu-core-vu-on-page-nav .collapse').collapse('hide');
      });
      $('.sticky-on-page-nav #block-vu-core-vu-on-page-nav__content a').bind('smoothscrollstart', function () {
        $('.main-content #block-vu-core-vu-on-page-nav .collapse').collapse('hide');
      });
    },

    reflow: function () {
      // Restore default menu.
      $(self.CONTENT_ID).html(self.menu_items);

      // Re-flow the menu if necessary.
      if ($(self.BLOCK_ID).height() > self.MAX_HEIGHT) {
        // Build the extended menu using Bootstrap Collapse.
        var $more_menu = $('<ul id="block-vu-core-vu-on-page-nav__more" class="collapse">');
        $('<li><a class="more" data-toggle="collapse" href="#block-vu-core-vu-on-page-nav__more" aria-expanded="false" aria-controls="block-vu-core-vu-on-page-nav__more">More</a></li>').appendTo($(self.CONTENT_ID).find('ul'));

        // Move items from main menu to extended menu until main menu is less than maximum height.
        while ($(self.BLOCK_ID).height() > self.MAX_HEIGHT) {
          $more_menu.prepend($(self.CONTENT_ID).find('li')[$(self.CONTENT_ID).find('li').length - 2]);
        }

        // Attach tab navigation behaviour.
        $('li', $more_menu).last().bind('keydown', function (e) {
          if (e.keyCode === 9 && e.shiftKey === false) {
            $('#block-vu-core-vu-on-page-nav__more').collapse('hide');
          }
        });

        // Attach extended menu.
        $more_menu.appendTo(self.CONTENT_ID);
      }

      $(self.CONTENT_ID).find('[data-smoothscroll]').smoothScroll();
    }
  };
})(jQuery, Drupal);
