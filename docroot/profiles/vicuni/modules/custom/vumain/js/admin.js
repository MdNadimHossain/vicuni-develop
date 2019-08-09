/**
 * @file
 * Contains admin related JS functions.
 */
(function ($, Drupal) {
  Drupal.behaviors.vumain_admin = {
    attach: function (context, settings) {
      // Listen for autocompleteSelect event,
      // and remove [nid:NODE_ID] when user selects from auto-complete list.
      $('input[name^="field_related_link[und]"]', context).once().on('autocompleteSelect', function (e, node) {
        $element = $(this);
        var val = $(node).data('autocompleteValue');
        var match = val.match(/(\[nid:\d+\])/i);
        // Set the value without the nid
        $element.val(val.replace(match[0], ''));
      });
    }
  };

  /**
   * Handler for the "keydown" event. Overwrites default to scroll with key nav.
   */
  Drupal.jsAC = Drupal.jsAC || {};
  Drupal.jsAC.prototype = Drupal.jsAC.prototype || {};
  Drupal.jsAC.prototype.onkeydown = function (input, e) {
    if (!e) {
      e = window.event;
    }
    switch (e.keyCode) {
      case 40: // down arrow.
        this.selectDown();
        $('#autocomplete').scrollTop($('#autocomplete').scrollTop() + $(this.selected).position().top);
        return false;
      case 38: // up arrow.
        this.selectUp();
        $('#autocomplete').scrollTop($('#autocomplete').scrollTop() + $(this.selected).position().top);
        return false;
      default: // All other keys.
        return true;
    }
  };

  /**
   * Highlights a suggestion. Overwrites default to remove selection from <li>.
   */
  Drupal.jsAC.prototype.highlight = function (node) {
    $('#autocomplete li').removeClass('selected');
    $(node).addClass('selected');
    this.selected = node;
    $(this.ariaLive).html($(this.selected).html());
  };

}(jQuery, Drupal));
