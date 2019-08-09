/**
 * @file
 * Mobile menu.
 *
 * Heads up! This file uses plugin-like architecture for decoupled binding
 * with Drupal.behaviors.victoryMobileMenu.attach() as a centralised plugin
 * initialisation method.
 * Also, some elements are created using JS theme implementations.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';
  Drupal.victory = Drupal.victory || {};

  /**
   * Behaviours for responsive mobile menu.
   */
  Drupal.behaviors.victoryMobileMenu = {
    attach: function (context) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      // Container for menu to append to.
      var $menuContainer = $('body', context);
      // Anchor to render menu trigger.
      var $menuTriggerAnchor = $('.js-responsive-menu-trigger-anchor', context);

      // Make mobile header sticky.
      Drupal.victory.fixedBlock.init($('.js-fixed-mobile-header', context), {
        classFixed: 'fixed-mobile-header',
        classFixedContainer: 'with-fixed-mobile-header'
      });

      // Create mobile menu.
      var $nav = Drupal.victory.mobileMenu.init({
        context: context,
        linksSelectorsPrimaryMenu: [
          'header .menu-block-main-menu-level1 .menu'
        ],
        linksSelectorsPrimaryMenuIgnoreItems: [
          '.js-responsive-menu-ignore'
        ],
        linksSelectorsSecondaryMenu: [
          '#page-header .menu-block-main-menu-level2'
        ],
        linksSelectorsSecondaryMenuSubsite: [
          '#page-header .menu-block-menu-subsites-level2'
        ],
        linksSelectorsSecondaryMenuIgnoreItems: [
          '.section',
          '.close'
        ],
        linksSelectorsDropdownTrigger: [
          'header .menu-block-main-menu-level1 .menu li .js-menu-item-login'
        ],
        linksSelectorsDropdownItems: [
          '#block-menu-block-main-menu-tools .menu li a'
        ],
        linksSecondaryContainer: '#page-header .secondary .menu-block-wrapper',
        $container: $menuContainer
      });

      // Add off-canvas functionality for the menu.
      Drupal.victory.offCanvas.init({
        $container: $menuContainer,
        $triggerOpen: $(Drupal.theme('victoryOffcanvasTrigger', 'open', 'Menu')).insertAfter($menuTriggerAnchor, context),
        $triggerClose: $(Drupal.theme('victoryOffcanvasTrigger', 'close', 'Close')).appendTo($nav),
        $canvas: $menuContainer.children().filter('div, header, footer').not('.js-shutter, .region-page-bottom'),
        $right: $nav
      });
    }
  };

  /**
   * Plugin to generate mobile menu.
   */
  Drupal.victory.mobileMenu = {
    SELECTOR_SLIDER_ROOT: '.js-menu-root',
    SELECTOR_LEAF: '.leaf, .expanded',
    SELECTOR_LEAF_EXPANDED: '.expanded',
    SELECTOR_ACTIVE_TRAIL: '.active, .active-trail',
    SELECTOR_MENU_EXPANDED: '.js-menu-expanded',
    SELECTOR_MENU_WRAPPER: '.menu-wrapper',
    SELECTOR_LINK_FORWARD: '.js-forward-link',
    SELECTOR_LINK_BACK: '.js-back-link',
    SELECTOR_LINK_WRAPPER: '.js-link-wrapper',
    SELECTOR_LINK_PARENT_WRAPPER: '.js-parent-link-wrapper',
    SELECTOR_SKIP_ANIMATION: '.js-skip-animation',
    SELECTOR_DEPTH_PREFIX: 'depth-',
    SELECTOR_LEVEL_PREFIX: 'level-',
    init: function (config) {
      var self = this;

      self.config = config;
      // Swap secondary menu class for subsites.
      if ($(self.config.linksSecondaryContainer, self.config.context).hasClass('menu-block-menu-subsites-level2')) {
        self.config.linksSelectorsSecondaryMenu = self.config.linksSelectorsSecondaryMenuSubsite;
      }

      // Clone menu from existing primary and secondary menus.
      var $primary = $(self.config.linksSelectorsPrimaryMenu.join(','), self.config.context).clone();
      var $secondary = $(self.config.linksSelectorsSecondaryMenu.join(',') + '>' + self.SELECTOR_MENU_WRAPPER, self.config.context).clone();

      // Remove all ignored items from primary menu.
      $primary.find(self.config.linksSelectorsPrimaryMenuIgnoreItems.join(',')).parent().remove();
      // Remove all non-leaf items that are added for dropdown rendering.
      $secondary.find(self.config.linksSelectorsSecondaryMenuIgnoreItems.join(',')).remove();

      $primary.find(self.selectorToQuery(self.SELECTOR_ACTIVE_TRAIL, 'li')).addClass(self.SELECTOR_SLIDER_ROOT.substr(1)).append($secondary);

      // Add forward, parent and back links.
      $secondary.find(self.selectorToQuery(self.SELECTOR_LEAF, '', '>a')).each(function () {
        var $link = $(this);
        var $leaf = self.getLeaf($link);

        // Remove all data attributes that may have been assigned buy other
        // plugins from links.
        $.each($link.data(), function (idx) {
          $link.removeAttr('data-' + idx);
        });

        // Apply required markup to link itself to allow styling.
        $link.wrap(Drupal.theme('victoryMobileMenuLinkWrapper', $link));

        if (self.isLeafExpanded($leaf)) {
          // Inject current link as a parent for a child menu wrapper.
          self.getChildMenuWrapper($link).prepend(Drupal.theme('victoryMobileMenuParentLink', $link));

          // Inject parent link into child menu as a back button.
          var $parentLink = self.getParentLink($link);
          $parentLink = Drupal.theme('victoryMobileMenuBackLink', $parentLink);
          self.getChildMenuWrapper($link).prepend($parentLink);
          $parentLink.on('click', function () {
            self.hideSubmenu($(this));
          });

          // Add forward link.
          var $forwardLink = $(Drupal.theme('victoryMobileMenuForwardLink'));
          $link.after($forwardLink);
          $forwardLink.on('click', function () {
            self.showSubmenu($(this));
          });
        }
      });

      // Render nav.
      var $nav = $(Drupal.theme('victoryMobileMenuNav', $primary)).appendTo(config.$container);

      self.showActiveTrail($primary);

      // Re-run active trail once more to make sure that the longest menus
      // have the time to expand.
      setTimeout(function () {
        self.showActiveTrail($primary);
      }, 720);

      // Add dropdown menu, but only if both trigger and items exist.
      if ($(self.config.linksSelectorsDropdownTrigger).length > 0 && $(self.config.linksSelectorsDropdownItems).length > 0) {
        var linkDropdownTrigger = self.extractLinks(self.config.linksSelectorsDropdownTrigger);
        var linksDropdownItems = self.extractLinks(self.config.linksSelectorsDropdownItems);

        if (linksDropdownItems.length > 0) {
          // Render dropdown.
          $nav.prepend($(Drupal.theme('victoryMobileMenuDropdown', $(linkDropdownTrigger).get(0), self.linksToMenu(linksDropdownItems, self.SELECTOR_ACTIVE_TRAIL))));
        }
      }

      return $nav;
    },

    /**
     * Show submenu of the specified link.
     */
    showSubmenu: function ($link, skipAnimation) {
      var $leaf = this.getLeaf($link);
      $leaf.addClass(this.SELECTOR_MENU_EXPANDED.substr(1));
      if (skipAnimation) {
        $leaf.addClass(this.SELECTOR_SKIP_ANIMATION.substr(1));
      }
      this.getRootContainer($link).addClass(this.SELECTOR_DEPTH_PREFIX + this.getDepth($leaf));
      this.updateRootContainerHeight($link);
      if (skipAnimation) {
        $leaf.removeClass(this.SELECTOR_SKIP_ANIMATION.substr(1));
      }
    },

    /**
     * Hide submenu of the specified link.
     */
    hideSubmenu: function ($link) {
      var $leaf = this.getLeaf($link);
      $leaf.removeClass(this.SELECTOR_MENU_EXPANDED.substr(1));
      this.getRootContainer($link).removeClass(this.SELECTOR_DEPTH_PREFIX + this.getDepth($leaf));
      this.updateRootContainerHeight(this.getParentLink($link));
    },

    /**
     * Update root container height for specified link.
     */
    updateRootContainerHeight: function ($link) {
      var $menuWrapper = this.getChildMenuWrapper($link);
      if ($menuWrapper.is(':visible')) {
        var $rootContainer = this.getRootContainer($link);
        var $rootContainerLink = $rootContainer.find('>a');
        $rootContainer.height($menuWrapper.height() + $rootContainerLink.outerHeight(true));
      }
    },

    /**
     * Show active trail items for specified menu.
     */
    showActiveTrail: function ($menu) {
      var self = this;
      var $lastActiveTrail = $($menu.find(self.selectorToQuery(self.SELECTOR_LEAF)).filter(self.selectorToQuery('.active-trail')));
      $lastActiveTrail.each(function () {
        var $link = self.getLink($(this));
        // Show a leaf with children the same way as one of it's children (i.e.
        // leaf with children will be shown as a parent on the same slide
        // as it's childless children).
        $link = $(this).hasClass('leaf') ? self.getParentLink($link) : $link;
        self.showSubmenu($link, true);
      });
    },

    /**
     * Return current back link.
     */
    getCurrentBackLink: function ($menu) {
      return $menu.find(this.SELECTOR_MENU_EXPANDED + ':last').find(' > ' + self.SELECTOR_MENU_WRAPPER + ' > ' + this.SELECTOR_LINK_BACK);
    },

    /**
     * Get depth of specified leaf.
     */
    getDepth: function ($leaf) {
      var depth = 1;
      if ($leaf.length > 0) {
        var classes = $leaf.attr('class').split(' ').reverse();
        for (var i in classes) {
          if (classes[i].indexOf(this.SELECTOR_LEVEL_PREFIX) === 0) {
            depth = classes[i].substr(this.SELECTOR_LEVEL_PREFIX.length);
            break;
          }
        }
      }

      return depth;
    },

    /**
     * Get root container for specified link.
     */
    getRootContainer: function ($link) {
      return $link.parents(this.SELECTOR_SLIDER_ROOT + ':first');
    },

    /**
     * Get child menu wrapper for specified link.
     */
    getChildMenuWrapper: function ($link) {
      return this.getLeaf($link).find(this.SELECTOR_MENU_WRAPPER + ':first');
    },

    /**
     * Get link for leaf.
     */
    getLink: function ($leaf) {
      return $leaf.find(this.SELECTOR_LINK_WRAPPER + ' > a');
    },

    /**
     * Get leaf from link or another leaf element.
     */
    getLeaf: function ($el) {
      return $el.parents(this.selectorToQuery(this.SELECTOR_LEAF, '', ':first')).first();
    },

    /**
     * Check if provided leaf is expanded.
     */
    isLeafExpanded: function ($leaf) {
      return $leaf.is(this.SELECTOR_LEAF_EXPANDED);
    },

    /**
     * Get parent link for current link.
     */
    getParentLink: function ($link) {
      var $currentLeaf = this.getLeaf($link);
      var $parentLeaf = this.getLeaf($currentLeaf);
      return $parentLeaf.find('a:first');
    },

    /**
     * Extract links from specified selectors.
     *
     * @param {array} linksSelectors
     *   Array of jQuery selectors to extract links from.
     * @param {array|string} filterClasses
     *   Array or string of filter classes. If no classes provided - no
     *   filtering is used.
     *
     * @returns {Array}
     *   Array of extracted links.
     */
    extractLinks: function (linksSelectors, filterClasses) {
      filterClasses = filterClasses || false;
      var self = this;
      var links = [];
      for (var i = 0; i < linksSelectors.length; i++) {
        $(linksSelectors[i]).each(function () {
          var href = $(this).attr('href') ? $(this).attr('href') : '#';
          var cssClasses = !filterClasses || $(this).is(self.selectorToQuery(filterClasses)) ? $(this).attr('class') : '';
          links.push('<a href="' + href + '"' + (cssClasses !== '' ? ' class="' + cssClasses + '"' : '') + '>' + $(this).html() + '</a>');
        });
      }
      return links;
    },

    /**
     * Convert links to menu.
     *
     * @param {array} links
     *   Array of links.
     * @param {array|string} filterClasses
     *   Array or string of filter classes. If no classes provided - no
     *   filtering is used.
     *
     * @returns {string}
     *   HTML for menu list.
     */
    linksToMenu: function (links, filterClasses) {
      filterClasses = filterClasses || false;
      var self = this;
      var $ul = $('<ul></ul>');
      for (var i = 0; i < links.length; i++) {
        var cssClasses = !filterClasses || $(this).is(self.selectorToQuery(filterClasses)) ? $(this).attr('class') : '';
        $ul.append('<li' + (cssClasses !== '' ? ' class="' + cssClasses + '"' : '') + '>' + links[i] + '</li>');
      }
      return $ul.outerHTML();
    },

    /**
     * Convert selector to CSS query string.
     *
     * @param {string|array} classes
     *   Array or comma-separated list of classes.
     * @param {string} prefixQuery
     *   Optional prefix query string.
     * @param {string} suffixQuery
     *   Optional suffix query string.
     *
     * @returns {string}
     *   CSS query string.
     */
    selectorToQuery: function (classes, prefixQuery, suffixQuery) {
      classes = $.isArray(classes) ? classes : classes.split(',').map(function (classSelector) {
        return classSelector.trim().substr(1);
      });
      prefixQuery = prefixQuery || '';
      suffixQuery = suffixQuery || '';
      return classes.map(function (selector) {
        return prefixQuery + '.' + selector.trim() + suffixQuery;
      }).join(',');
    }
  };

  /**
   * Plugin for off-canvas functionality.
   */
  Drupal.victory.offCanvas = {

    /**
     * Init off-canvas behaviour.
     */
    init: function (config) {
      if (config.$right.length === 0) {
        return;
      }

      // Add all classes for styling.
      config.$container.addClass('js-offcanvas-container');
      config.$triggerOpen.addClass('js-offcanvas-trigger-open');
      config.$triggerClose.addClass('js-offcanvas-trigger-close');
      config.$canvas.addClass('js-offcanvas-canvas');
      config.$right.addClass('js-offcanvas-right');

      $(config.$triggerOpen).on('click', function () {
        if (!config.$container.hasClass('js-offcanvas-open')) {
          config.$container.mask({
            maskId: 'responsiveMenuOverlay',
            loadSpeed: 0,
            closeSpeed: 100,
            onBeforeLoad: function () {
              // Overlay needs to be a part of sliding canvas.
              this.getMask().addClass('js-offcanvas-canvas');

              this.getMask().on('touchstart.offcanvas touchmove.offcanvas', function (e) {
                e.stopPropagation();
              });
            },
            onLoad: function () {
              config.$container.addClass('js-offcanvas-open');
            },
            onClose: function () {
              config.$container.removeClass('js-offcanvas-open');
              this.getMask().off('touchstart.offcanvas touchmove.offcanvas');
              this.getMask().remove();
            }
          });
        }
      });

      $(config.$triggerClose).on('click', function () {
        if (config.$container.hasClass('js-offcanvas-open')) {
          config.$container.trigger('mask::close');
        }
      });
    },

    /**
     * Check that current device is iPhone or iPad.
     */
    isIDevice: function () {
      return navigator.userAgent.match(/iPhone/i) || navigator.userAgent.match(/iPod/i) || navigator.userAgent.match(/iPad/i);
    }
  };

  /**
   * Plugin to vertically fix block (make it sticky).
   */
  Drupal.victory.fixedBlock = {
    $element: $(),
    $siblings: $(),
    $container: $(),
    lastScroll: 0,
    config: {
      // Selector fo container of the block.
      selectorContainer: 'body',
      // Class to add when the block is fixed.
      classFixed: 'block-fixed',
      // Class to add to the container when the block is fixed.
      classFixedContainer: 'with-block-fixed'
    },

    /**
     * Init plugin.
     */
    init: function ($el, config) {
      var self = this;

      self.config = $.extend({}, self.config, config);

      self.$element = $el;
      self.$siblings = self.getSiblings(self.$element);
      self.$container = $(self.config.selectorContainer);

      // Trigger update if one of the siblings has an accessibility element that
      // receives a focus.
      $(document).on('focus.sr-group-item', function (evt, element) {
        if ($(element).parents().filter(self.$siblings).length > 0) {
          self.fixedBlockAnimationCallback();
          // Force update as scrolling may not occur.
          self.doUpdate();
        }
      });

      self.fixedBlockAnimationCallback();
      self.doUpdate();
    },

    /**
     * Get all siblings for currently active block element.
     */
    getSiblings: function ($el) {
      var $siblings = $();
      var $allSiblings = $('[data-fixed-block-target]', document);
      $allSiblings.each(function () {
        var selector = $(this).data('fixedBlockTarget');
        if ($(selector).is($el)) {
          $siblings = $siblings.add($(this));
        }
      });
      return $siblings;
    },

    /**
     * Sticky animation animation callback handler.
     *
     * This handler automatically loops on animframe as soon as it's invoked.
     */
    fixedBlockAnimationCallback: function () {
      var self = Drupal.victory.fixedBlock;
      window.requestAnimFrame(self.fixedBlockAnimationCallback);

      var scrollTop = $(window).scrollTop();

      // Don't advance if no scrolling has occurred.
      if (self.lastScroll === scrollTop) {
        return;
      }

      // Compensate for elastic scrolling.
      if (scrollTop < 0) {
        scrollTop = 0;
      }

      // Store last scroll position.
      Drupal.victory.fixedBlock.lastScroll = scrollTop;

      // Perform actual update.
      self.doUpdate();
    },

    /**
     * Perform block update.
     */
    doUpdate: function () {
      var self = Drupal.victory.fixedBlock;

      // Get the max vertical offset for the siblings with non-zero height.
      var siblingsTop = 0;
      self.$siblings.each(function () {
        var h = $(this).outerHeight(true);
        if (h > 0) {
          siblingsTop = Math.max(siblingsTop, h);
        }
      });

      if (self.lastScroll >= siblingsTop) {
        self.$element.addClass(self.config.classFixed);
        self.$container.addClass(self.config.classFixedContainer);
      }
      else {
        self.$element.removeClass(self.config.classFixed);
        self.$container.removeClass(self.config.classFixedContainer);
      }
    }
  };

  /**
   * Theme implementation for mobile menu navigation element.
   *
   * @param {string} ul
   *   HTML list with navigation items to insert.
   *
   * @returns {string}
   *   The markup for mobile menu navigation.
   */
  Drupal.theme.prototype.victoryMobileMenuNav = function (ul) {
    return $('<nav id="responsive-nav" class="navbar-collapse"></nav>').append($(ul));
  };

  /**
   * Theme implementation for mobile menu parent link.
   *
   * @param {object} $link
   *   Link object to use for parent menu link rendering.
   *
   * @returns {string}
   *   The markup for the mobile menu parent link.
   */
  Drupal.theme.prototype.victoryMobileMenuParentLink = function ($link) {
    var $newLink = $('<a></a>').addClass($link.attr('class')).attr('href', $link.attr('href')).html($link.html());
    return $('<div class="' + Drupal.victory.mobileMenu.SELECTOR_LINK_PARENT_WRAPPER.substr(1) + '"></div>').append($newLink);
  };

  /**
   * Theme implementation for mobile menu back link.
   *
   * @param {object} $link
   *   Link object to use for back menu link rendering.
   *
   * @returns {string}
   *   The markup for the mobile menu back link.
   */
  Drupal.theme.prototype.victoryMobileMenuBackLink = function ($link) {
    var text = $link.length > 0 ? $link.html() : '';
    return $('<span class="' + Drupal.victory.mobileMenu.SELECTOR_LINK_BACK.substr(1) + '">' + text + '</span>');
  };

  /**
   * Theme implementation for mobile menu forward link.
   *
   * @returns {string}
   *   The markup for the mobile menu forward link.
   */
  Drupal.theme.prototype.victoryMobileMenuForwardLink = function () {
    return '<span class="' + Drupal.victory.mobileMenu.SELECTOR_LINK_FORWARD.substr(1) + '"></span>';
  };

  /**
   * Theme implementation for mobile menu link wrapper.
   *
   * @param {object} $link
   *   Link object to use for menu link wrapper rendering.
   *
   * @returns {string}
   *   The markup for the mobile menu link wrapper.
   */
  Drupal.theme.prototype.victoryMobileMenuLinkWrapper = function ($link) {
    return '<div class="' + Drupal.victory.mobileMenu.SELECTOR_LINK_WRAPPER.substr(1) + '"></div>';
  };

  /**
   * Theme implementation for the dropdown menu.
   *
   * @param {object} trigger
   *   Trigger DOM object for a menu dropdown.
   * @param {array} itemsList
   *   Array of HTML markup for menu links.
   *
   * @returns {string}
   *   The markup for the dropdown menu.
   */
  Drupal.theme.prototype.victoryMobileMenuDropdown = function (trigger, itemsList) {
    var containerClass = 'menu-nav-dropdown';
    var itemsClass = 'menu-nav-dropdown-items';
    var itemsId = 'menu-nav-tools-collapse';
    var $itemsList;
    var bootstrapComponent = 'collapse';
    // Without playing with the attributes the page jumps to the anchor.
    var $trigger = $(trigger).attr({
      'role': 'button',
      'data-toggle': bootstrapComponent,
      'data-target': '#' + itemsId,
      'aria-expanded': 'false',
      'aria-controls': itemsId
    }).removeAttr('href');

    $itemsList = $(itemsList).addClass(itemsClass);

    return '<div class="' + containerClass + '">' + $trigger.outerHTML() + '<div id="' + itemsId + '" class="spacing-wrapper' + ' ' + bootstrapComponent + '">' + $itemsList.outerHTML() + '</div></div>';
  };

  /**
   * Theme implementation for the off-canvas trigger button.
   *
   * @param {string} type
   *   Trigger type: open or close.
   * @param {string} title
   *   Optional trigger title.
   *
   * @returns {string}
   *   The markup for the off-canvas trigger button.
   */
  Drupal.theme.prototype.victoryOffcanvasTrigger = function (type, title) {
    title = title || '';
    return '<button type="button" class="js-offcanvas-trigger js-offcanvas-trigger-' + type + '" aria-controls="#responsive-nav" aria-expanded="false"><span class="icon-bar"></span><span class="icon-bar"></span><span class="icon-bar"></span><span class="title">' + title + '</span></button>';
  };

  /**
   * Get outer HTML of jQuery element.
   */
  $.fn.outerHTML = $.fn.outerHTML || function (s) {
    return s
      ? this.before(s).remove()
      : jQuery('<p>').append(this.eq(0).clone()).html();
  };

  // Animation frames polyfill. Use this instead of resize and scroll events as
  // browsers will paint in queues which increases performance and device
  // battery life.
  window.requestAnimFrame = (function () {
    return window.requestAnimationFrame ||
      window.webkitRequestAnimationFrame ||
      window.mozRequestAnimationFrame ||
      function (callback) {
        window.setTimeout(callback, 1000 / 60);
      };
  }());
}(jQuery, Drupal));
