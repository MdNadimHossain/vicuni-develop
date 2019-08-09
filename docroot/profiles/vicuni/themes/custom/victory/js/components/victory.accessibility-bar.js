/**
 * @file
 * Homepage Collapsable Success Story.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';
  Drupal.behaviors.victoryAccessibilityBar = {
    attach: function (context, settings) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      // Keep all grouped screen reader elements visible if at least one of them
      // has focus.
      $('[data-sr-group-type="container"]', context).find('[data-sr-group-type="item"]').on('focus', function () {
        $(this).parents('[data-sr-group-type="container"]').find('[data-sr-group-type="item"]:not(.sr-only-focused)').addClass('sr-only-focused');
        // Notify everyone that screen-reader item received a focus.
        $(document).trigger('focus.sr-group-item', $(this));
      });

      // Remove all focused classes when close button is clicked. This allows
      // to preserve the bar element in the DOM and access it multiple times.
      $('[data-dismiss-sr]').click(function () {
        var $target = $($(this).attr('data-dismiss-sr'));
        $target.find('.sr-only-focused').removeClass('sr-only-focused');
      });
    }
  };
}(jQuery, Drupal));
