/**
 * @file
 * Homepage Collapsable Success Story.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victorySuccessStoryCollasable = {
    HEIGHT_RESET: 'auto',
    SELECTOR_SUCCESS_STORY_ITEM: '.success_story_collapsable',
    SELECTOR_PARENT_CONTAINER: '.featured-content-pane',
    SELECTOR_TOGGLE_CLASS: '.collapse-toggle',
    SELECTOR_ROW: '.row',
    SHOW_MORE_TEXT: 'Show more success stories',
    SHOW_LESS_TEXT: 'Show less success stories',
    $toggle: '',
    $row: '',
    attach: function (context, settings) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      var $parentContainer = $(this.SELECTOR_SUCCESS_STORY_ITEM, context).closest(this.SELECTOR_PARENT_CONTAINER);
      this.$toggle = $parentContainer.find(this.SELECTOR_TOGGLE_CLASS);
      this.$row = $parentContainer.find(this.SELECTOR_ROW);

      // Attach media query behaviour.s.
      var media_query = window.matchMedia('(max-width: 767px)');
      this.media_query_response(media_query);
      media_query.addListener(this.media_query_response);

      this.initCollapseToggle();
    },

    media_query_response: function (media_query) {
      var self = Drupal.behaviors.victorySuccessStoryCollasable;
      var $row = self.$row;
      var $toggle = self.$toggle;

      if (media_query.matches) {
        var height = self.getDefaultHeight($row);

        // Set default state of row element on mobile.
        self.setCollapsedRowDefaults($row, $toggle, height);

        $toggle.text(self.SHOW_MORE_TEXT).show();
      }
      else {
        self.removeCollapsedRowDefaults($row, $toggle, self.HEIGHT_RESET);
        $toggle.attr('data-collapsed', 'false');
        $toggle.text('').hide();
      }
    },

    setCollapsedRowDefaults: function ($row, $toggle, height) {
      var collapsedRowHeight = height * 0.55;
      $toggle.text(this.SHOW_MORE_TEXT);
      $row.css('height', collapsedRowHeight);
      $row.addClass('row--collapsed');
    },

    removeCollapsedRowDefaults: function ($row, $toggle, height) {
      $toggle.hide();
      $row.css('height', height);
      $row.removeClass('row--collapsed');
    },

    getDefaultHeight: function ($row) {
      var child_height = 0;
      $row.children('.col-sm-4').each(function () {
        child_height += $(this).outerHeight(true);
      });
      return child_height;
    },

    initCollapseToggle: function () {
      var self = Drupal.behaviors.victorySuccessStoryCollasable;
      var $row = this.$row;
      var $toggle = this.$toggle;

      $toggle.on('click', function () {
        if (!$(this).attr('data-collapsed') || $(this).attr('data-collapsed') === 'false') {
          self.removeCollapsedRowDefaults($row, $toggle, self.HEIGHT_RESET);
          $(this).attr('data-collapsed', 'true');
        }
        else if ($(this).attr('data-collapsed') === 'true') {
          self.setCollapsedRowDefaults($row, $toggle, self.getDefaultHeight($row));
          $(this).attr('data-collapsed', 'false');
        }
      });
    }
  };
})(jQuery, Drupal);
