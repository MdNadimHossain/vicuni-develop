/**
 * @file
 * Behaviours for Main menu.
 *
 * Note that dropdown behaviours are handled by Bootstrap functionality.
 *
 * Read about how menu is built in header_secondary-navigation.scss.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';

  Drupal.behaviors.vuMainMenu = {
    SELECTOR_DROPDOWN_TRIGGER: '.level-2',
    SELECTOR_MENU: '.menu',
    SELECTOR_MENU_WRAPPER: '.menu-wrapper',
    SELECTOR_ACTIVE_TRAIL: '.active-trail',
    SELECTOR_MENU_LEAF: '.leaf',
    SELECTOR_MENU_LEAF_HOVER: '.js-mouse-over',
    SELECTOR_MENU_LEAF_HOVER_START: '.js-mouse-over-start',
    SELECTOR_MENU_SECTION: '.section',
    SELECTOR_USE_HEIGHT: '.js-use-height',
    DURATION_OPEN: 720,
    DURATION_CLOSE: 200,
    HOVERINTENT_TIMEOUT: 300,
    attach: function (context, settings) {
      // Explicitly specify container as parent with pre-defined selectors.
      var $dropdownTriggers = this.getChildMenu($('.region-header-menu .menu-level-2', context)).find('>' + this.SELECTOR_DROPDOWN_TRIGGER);
      if ($dropdownTriggers.length === 0) {
        return;
      }

      // Init close button.
      this.initCloseButton($dropdownTriggers);

      // Init overlay integration.
      this.initOverlay($dropdownTriggers);

      // Get the tallest menu among all visible menus, revealed by mouse over.
      this.initDropdownMenu($dropdownTriggers);
    },

    /**
     * Init close button.
     *
     * @param {object} $dropdownTriggers
     *   Dropdown trigger elements.
     */
    initCloseButton: function ($dropdownTriggers) {
      var $menu = this.getChildMenu($dropdownTriggers);
      $menu.addClass('js-close-target');
      $(Drupal.theme('vuMainMenuCloseButton', 'js-close-target')).appendTo($menu);
    },

    /**
     * Init overlay integration.
     *
     * @param {object} $dropdownTriggers
     *   Dropdown trigger elements.
     */
    initOverlay: function ($dropdownTriggers) {
      // Show the overlay when the dropdown is start to open and remove it when
      // it is closed, but track last clicked element to make sure that overlay
      // is closed only when current item (or close button) is clicked.
      var lastClicked = null;
      $dropdownTriggers
        .on('click focus', function (evt) {
          lastClicked = evt.currentTarget;
          $('div.sticky-header').addClass('sticky-header--hidden');
        })
        .on('shown.bs.dropdown', function () {
          $dropdownTriggers.mask({
            maskId: 'mainMenuOverlay',
            zIndex: 200,
            onClose: function () {
              this.getMask().remove();
              $('div.sticky-header').removeClass('sticky-header--hidden');
            }
          });
        })
        .on('hide.bs.dropdown', function (evt) {
          if (lastClicked === evt.currentTarget) {
            $(document).mask.close();
          }
        });
    },

    /**
     * Init dropdown behaviours.
     *
     * @param {object} $dropdownTriggers
     *   Dropdown trigger elements.
     */
    initDropdownMenu: function ($dropdownTriggers) {
      var self = this;

      // Change the event that we're binding to to 'show' because 'shown' does
      // not correctly pass the relatedTarget property of the event.
      $dropdownTriggers.on('show.bs.dropdown', function (evt) {
        var $dropdown = self.getChildMenuWrapper($(evt.target));

        // Initiate default open state, but only when the dropdown is fully
        // opened.
        $dropdown.one('bsTransitionEnd', $.proxy(function () {
          var $currentDropdown = $(this);

          // Set default dropdown state and show active trail items.
          self.setDefaultDropdownState($currentDropdown);
          self.processActiveTrail($currentDropdown);

          // Reset dropdown state on mouseleave.
          $currentDropdown.on('mouseleave', function () {
            self.setDefaultDropdownState($(this));
            self.removeAllStartHoverStates($(this));
          });
        }, $dropdown)).emulateTransitionEnd(self.DURATION_OPEN / 2);

        // Reset hover stack every time dropdown opens.
        self.resetHoverStack($dropdown);

        // Bind setting of the menu heights on mouse move and leave.
        var $links = $dropdown.find('a').not('.js-processed').addClass('js-processed');
        $links.each(function () {
          // Bind hoverintent to each leaf, but sections (see below).
          // We are binding to leaves instead of links as leaves are used for
          // expanding children menus.
          self.getLeaf($(this)).filter(':not(' + self.SELECTOR_MENU_SECTION + ')').hoverIntent({
            // Set interval during which a cursor outside of an item is
            // considered still inside. If a mouse returns to the element
            // within this interval, neither 'out' nor 'over' callbacks are
            // called again.
            timeout: self.HOVERINTENT_TIMEOUT,
            over: function () {
              var $leaf = $(this);
              var $link = self.getLink($leaf);
              var $currentDropdown = self.getCurrentDropdown($link);
              // Since hoverInit does not provide an ability to cancel
              // event bubbling, we have to maintain our own stack of
              // hover events for currently hovered item to prevent bubbling to
              // parent items (i.e. when a child is hovered, we do not need
              // hover event to fire for parents).
              if (self.matchesHoverStack($currentDropdown, $leaf)) {
                return;
              }

              // Add current leaf to the hover stack.
              self.addToHoverStack($dropdown, $leaf);

              self.removeAllStartHoverStates($currentDropdown);

              // Add hover state.
              self.addHoverState($link);

              // Set height for current link.
              self.setCurrentDropdownHeight($link);
            },
            out: function () {
              var $leaf = $(this);
              var $link = self.getLink($leaf);
              var $currentDropdown = self.getCurrentDropdown($link);

              // Remove hover state.
              self.removeHoverState($link);
              self.resetHoverStack($currentDropdown);
            }
          });

          // Special treatment for section links.
          self.getLeaf($(this)).filter(self.SELECTOR_MENU_SECTION).find('a:first').on('mouseenter', function () {
            var $link = $(this);
            var $currentDropdown = self.getCurrentDropdown($link);

            self.removeAllStartHoverStates($currentDropdown);

            // Add hover state.
            self.addHoverState($link);

            // Set height for current link.
            self.setCurrentDropdownHeight($link);
          }).on('mouseleave', function () {
            var $link = $(this);
            var $currentDropdown = self.getCurrentDropdown($link);

            // Remove hover state.
            self.removeHoverState($link);
            self.resetHoverStack($currentDropdown);
          });
        });
      }).on('hide.bs.dropdown', function (evt) {
        var $dropdown = self.getChildMenuWrapper($(evt.target));
        // Unbind all events.
        $dropdown.off('mouseleave');
        $dropdown.find('a.js-processed').removeClass('js-processed').off('mouseenter mouseleave');

        // Reset heights for all dropdowns.
        self.resetAllDropdownHeights($dropdown);
      });
    },

    /**
     * Get link to leaf.
     */
    getLink: function ($leaf) {
      return $leaf.find('>a:first');
    },

    /**
     * Get leaf from link.
     */
    getLeaf: function ($link) {
      return $link.parents('li:first');
    },

    /**
     * Add hover state for a link.
     */
    addHoverState: function ($link) {
      var $leaf = this.getLeaf($link);
      $leaf.parents('li').not(this.SELECTOR_DROPDOWN_TRIGGER).addClass(this.SELECTOR_MENU_LEAF_HOVER.substring(1));
      $leaf.addClass(this.SELECTOR_MENU_LEAF_HOVER.substring(1));
    },

    /**
     * Remove hover state from a link.
     */
    removeHoverState: function ($link) {
      var $leaf = this.getLeaf($link);
      $leaf.removeClass(this.SELECTOR_MENU_LEAF_HOVER.substring(1));
      // Remove from all children as well.
      $leaf.find('li' + this.SELECTOR_MENU_LEAF_HOVER).removeClass(this.SELECTOR_MENU_LEAF_HOVER.substring(1));
    },

    /**
     * Add starting hover state for a link.
     */
    addStartHoverState: function ($link) {
      this.getLeaf($link).not(this.SELECTOR_MENU_LEAF_HOVER_START).addClass(this.SELECTOR_MENU_LEAF_HOVER_START.substr(1));
    },

    /**
     * Remove all starting hover states for dropdown.
     */
    removeAllStartHoverStates: function ($dropdown) {
      $dropdown.find(this.SELECTOR_MENU_LEAF_HOVER_START).removeClass(this.SELECTOR_MENU_LEAF_HOVER_START.substr(1));
    },

    /**
     * Set default dropdown state.
     */
    setDefaultDropdownState: function ($dropdown) {
      var $defaultLink = $dropdown.find('a:first');
      this.setCurrentDropdownHeight($defaultLink);
    },

    /**
     * Add leaf to a hover stack for current dropdown.
     */
    addToHoverStack: function ($dropdown, $leaf) {
      var stack = this.getHoverStack($dropdown);
      stack.push($leaf);
      $dropdown.data('hoverStack', stack);
      return stack;
    },

    /**
     * Get hover stack for current dropdown.
     */
    getHoverStack: function ($dropdown) {
      var stack = $dropdown.data('hoverStack');
      return stack || [];
    },

    /**
     * Reset hover stack for current dropdown.
     */
    resetHoverStack: function ($dropdown) {
      $dropdown.data('hoverStack', []);
    },

    /**
     * Match provided leaf to elements in hover stack for current dropdown.
     *
     * Match is based on special criteria, not simple existence in stack.
     */
    matchesHoverStack: function ($dropdown, $leaf) {
      var stack = this.getHoverStack($dropdown);
      for (var i in stack) {
        // Match found if current leaf is a parent of an item in the stack
        // or already in the stack.
        if ($leaf.is(stack[i]) || stack[i].parents().filter($leaf).length > 0) {
          return true;
        }
      }
      return false;
    },

    /**
     * Process active trail links for the dropdown.
     */
    processActiveTrail: function ($dropdown) {
      var self = this;

      var $links = $dropdown.find('a').filter(this.SELECTOR_ACTIVE_TRAIL);

      // Add start hover state.
      $links.each(function () {
        self.addStartHoverState($(this));
      });

      // Set height to the last item of the active trail.
      var $lastLink = $links.last();
      if ($lastLink.length > 0) {
        self.setCurrentDropdownHeight($lastLink);
      }
    },

    /**
     * Set dropdown height for a specified link.
     */
    setCurrentDropdownHeight: function ($link) {
      var self = this;
      var $currentDropdown = self.getCurrentDropdown($link);

      // Calculate max height for the visible parents.
      var $parents = self.getCurrentMenus($link);
      var maxHeightParents = self.calcMaxHeight($parents);

      // Calculate max height for the visible immediate children.
      var $children = this.getChildMenu($link.parent()).filter(function () {
        return $(this).css('visibility') !== 'hidden';
      });
      var maxHeightChildren = self.calcMaxHeight($children);

      // Calculate max height for all other elements that have special class.
      var $extras = $currentDropdown.find(self.SELECTOR_USE_HEIGHT);
      var maxHeightExtras = self.calcMaxHeight($extras);

      // Set the height of the current dropdown to the max height of parents and
      // children menus.
      self.setDropdownHeight($currentDropdown, Math.max(maxHeightParents, maxHeightChildren, maxHeightExtras));
    },

    /**
     * Reset heights of all dropdowns.
     */
    resetAllDropdownHeights: function ($element) {
      var self = this;
      $element.parents(this.SELECTOR_MENU).first().find('>' + this.SELECTOR_DROPDOWN_TRIGGER).each(function () {
        self.getChildMenuWrapper($(this)).removeAttr('style');
      });
    },

    /**
     * Return current menu for a specified link.
     */
    getCurrentMenu: function ($link) {
      return this.getCurrentMenus($link).first();
    },

    /**
     * Return current and all parent menus for a specified link.
     */
    getCurrentMenus: function ($link) {
      return $link.parents(this.SELECTOR_MENU + ':visible').not(':last');
    },

    /**
     * Return current dropdown for a specified link.
     */
    getCurrentDropdown: function ($link) {
      return this.getChildMenuWrapper($link.parents(this.SELECTOR_DROPDOWN_TRIGGER));
    },

    /**
     * Return immediate child menu for a specified element.
     */
    getChildMenu: function ($element) {
      return $element.find('>' + this.SELECTOR_MENU_WRAPPER + '>' + this.SELECTOR_MENU);
    },

    /**
     * Return immediate child menu wrapper for a specified element.
     */
    getChildMenuWrapper: function ($element) {
      return this.getChildMenu($element).parents(this.SELECTOR_MENU_WRAPPER).first();
    },

    /**
     * Set dropdown height.
     */
    setDropdownHeight: function ($dropdown, height) {
      $dropdown.css('min-height', height);
    },

    /**
     * Calculate max height for a set of provided elements.
     */
    calcMaxHeight: function ($elements) {
      var maxHeight = 0;
      $elements.each(function () {
        var height = $(this).outerHeight(true);
        if (height > maxHeight) {
          maxHeight = height;
        }
      });
      return maxHeight;
    }
  };

  /**
   * Render the close button.
   *
   * @param {string} target
   *   Close target query.
   *
   * @returns {string}
   *   The markup for the toggle button.
   */
  Drupal.theme.prototype.vuMainMenuCloseButton = function (target) {
    return '<button type="button" class="close" data-target="' + target + '" data-dismiss="alert" role="button">' +
      '<span aria-hidden="true">&times;</span><span class="sr-only">Close</span>' +
      '</button>';
  };
}(jQuery));
