/**
 * @file
 * Behaviours for VU Research Profile node form.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';

  Drupal.behaviors.vuRpNodeForm = {
    attach: function (context) {
      this.initTabs(context);

      this.initPhoto(context);

      this.initEntityReferenceAutocompleteRemoveIds('[id^=edit-field-rp-expertise-und-].form-text, [id^=edit-field-rp-memberships-und-].form-text', context);

      this.initExpanded(context);
    },

    initTabs: function (context) {
      $('.horizontal-tab-button a', context).once().click(function (evt) {
        evt.preventDefault();
        $(this).parent().addClass('selected');
        $(this).parent().siblings().removeClass('selected');
        var index = $(this).parent('li').attr('tabindex');
        $('.horizontal-tabs-panes', context).find('fieldset.horizontal-tabs-pane').eq(index).show();
        $('.horizontal-tabs-panes', context).find('fieldset.horizontal-tabs-pane').eq(index).siblings().hide();
      });

    },

    initPhoto: function (context) {
      $('.load-photo-section .field-markup-no-expanded', context).hide();

      $('.form-item-field-rp-use-photo-und input[type="radio"]', context).change(function () {
        if ($('.load-photo-section .field-markup-no-expanded', context).is(':hidden')) {
          $('.load-photo-section .field-markup-no-expanded').show();
        }
        else {
          $('.load-photo-section .field-markup-no-expanded').hide();
        }
      });
    },

    initEntityReferenceAutocompleteRemoveIds: function (selector, context) {
      $(selector, context).each(function () {
        var $this = $(this);
        // Replace value on page load.
        if ($this.val()) {
          var val = $this.val();
          var match = val.match(/\((.*?)\)$/);
          if (match) {
            $this.data('real-value', val);
            if (match.length > 0) {
              $this.val(val.replace(' ' + match[0], ''));
            }
          }
        }

        // Bind to autocomplete events.
        $this.once().on('autocompleteSelect', function (e, node) {
          var val = $(node).data('autocompleteValue');
          var match = val.match(/\((.*?)\)$/);
          $this.data('real-value', val);
          $this.val(val.replace(' ' + match[0], ''));
        });
      });
    },

    initExpanded: function (context) {
      $('.field-markup-expanded', context).once().click(function () {
        var text = $(this).hasClass('open') ? 'Show' : 'Hide';
        $(this).toggleClass('open');
        $(this).find('h1').children('span').text(text);
      });
    }
  };
}(jQuery));
