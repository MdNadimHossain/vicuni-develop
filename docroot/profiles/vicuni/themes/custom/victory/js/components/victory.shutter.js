/**
 * @file
 * Behaviours for Shutter widget.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryShutter = {
    attach: function (context, settings) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      var self = this;

      // Init shutter widget.
      var $shutter = self.initShutter($('.js-shutter', context));

      $shutter
        .on('shown.shutter', function () {
          self.resetSearch();

          if (self.isIDevice()) {
            $('body').data('lastScroll', $(window).scrollTop());
            window.scrollTo(0, 0);
          }
        })
        .on('hidden.shutter', function () {
          if (self.isIDevice()) {
            var lastScroll = $('body').data('lastScroll');
            if (lastScroll) {
              setTimeout(function () {
                window.scrollTo(0, lastScroll);
              }, 100);
            }
          }
        });

      // Bind custom shutter close button's click.
      $('.js-shutter-close', $shutter).on('click', function () {
        var $shutter = $(this).parents('.js-shutter');
        $shutter.modal('hide');
      });

      // Workaround for Marketo timing bug.
      //
      // If Marketo/munchkin is configured to track a link that is a modal trigger,
      // intermittently the default action (open the href) will be triggered.
      //
      // The workaround here is to change the href so Marketo doesn't try to track
      // the click.
      var $loginLink = $('[data-shutter-item-target="#block-menu-block-main-menu-tools"]');
      $loginLink.attr('href', '#' + $loginLink.attr('href'));

      // Clone search button to mobile menu bar.
      $('[data-shutter-item-target="#block-vu-core-vu-funnelback-search"]', context).clone().insertAfter('.js-responsive-menu-trigger-anchor');


      var $searchLink = $('[data-shutter-item-target="#block-vu-core-vu-funnelback-search"]');
      $searchLink.attr('href', '#' + $searchLink.attr('href'));
    },

    /**
     * Init shutter widget.
     */
    initShutter: function ($shutter) {
      var self = this;

      // Add default classes to all items.
      $shutter.find('.js-shutter-items').children(':not(.js-shutter-item)').addClass('js-shutter-item');

      $shutter.on('show.bs.modal.victoryShutter', function (event) {
        // Show items for this trigger when modal is about to be fully opened.
        self.shutterShowItems($(this), $(event.relatedTarget));
      }).on('shown.bs.modal.victoryShutter', function () {
        // Expand shutter when modal is fully opened.
        self.shutterExpand($(this));
      }).on('hide.bs.modal.victoryShutter', function (event) {
        // Close shutter when modal is closed.
        self.shutterCollapse($(this), event);
      });

      return $shutter;
    },

    /**
     * Expand specified shutter.
     */
    shutterExpand: function ($shutter) {
      var $dialog = $shutter.find('.js-shutter-dialog');
      $dialog.collapse('show');
      var e = $.Event('shown.shutter');
      $shutter.trigger(e);
    },

    /**
     * Collapse specified shutter.
     */
    shutterCollapse: function ($shutter, event) {
      var $dialog = $shutter.find('.js-shutter-dialog');

      if ($dialog.hasClass('in')) {
        event.preventDefault();
        $dialog.collapse('hide');
        setTimeout(function () {
          $shutter.modal('hide');
        }, jQuery.fn.collapse.prototype.constructor.Constructor.TRANSITION_DURATION);
      }
      else {
        var e = $.Event('hidden.shutter');
        $shutter.trigger(e);
      }
    },

    /**
     * Show items for specified shutter.
     */
    shutterShowItems: function ($shutter, $trigger) {
      var $recipient = $($trigger.data('shutter-item-target'));
      $shutter.find('.js-shutter-item').not($recipient).removeClass('js-shutter-item-shown');
      $recipient.addClass('js-shutter-item-shown');
    },

    /**
     * Search block customisations.
     */
    resetSearch: function ($target) {
      var $search = $('#block-vu-core-vu-funnelback-search').find('input[name="query"]');
      $search.val('');
      $search.focus();
    },

    /**
     * Check that current device is iPhone or iPad.
     */
    isIDevice: function () {
      return navigator.userAgent.match(/iPhone/i) || navigator.userAgent.match(/iPod/i) || navigator.userAgent.match(/iPad/i);
    }
  };
}(jQuery, Drupal));
