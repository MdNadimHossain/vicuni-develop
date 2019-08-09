/**
 * @file
 * Provides a 'mask' overlay.
 *
 * The core of this plugin is from jQuery Tools.
 * @see https://github.com/jquerytools/jquerytools/tree/master/src/toolbox.
 */

(function ($) {
  'use strict';

  var tool;

  tool = $.tool = {

    conf: {
      maskId: 'exposeMask',
      loadSpeed: 'slow',
      closeSpeed: 'fast',
      closeOnClick: true,
      closeOnEsc: true,

      // CSS settings.
      zIndex: 9998,
      opacity: 0.25,
      startOpacity: 0,
      color: '#333333',

      // Callbacks.
      onLoad: null,
      onClose: null
    }
  };

  function call(fn) {
    if (fn) {
      return fn.call($.mask);
    }
  }

  var mask;
  var loaded;
  var config;

  $.mask = {

    load: function (conf, els) {
      // Is the mask already loaded?
      if (loaded) {
        return this;
      }

      // Set configuration.
      if (typeof conf === 'string') {
        conf = {color: conf};
      }

      // Use latest config.
      conf = conf || config;

      config = conf = $.extend($.extend({}, tool.conf), conf);

      // Get the mask.
      mask = $('#' + conf.maskId);

      // Or create it.
      if (!mask.length) {
        mask = $('<div/>').attr('id', conf.maskId);
        $('body').append(mask);
      }

      // Set position and dimensions.
      mask.css({
        position: 'absolute',
        top: 0,
        left: 0,
        width: '100%',
        height: '100%',
        display: 'none',
        opacity: conf.startOpacity,
        zIndex: conf.zIndex
      });

      if (conf.color) {
        mask.css('backgroundColor', conf.color);
      }

      // onBeforeLoad.
      if (call(conf.onBeforeLoad) === false) {
        return this;
      }

      // 'esc' button.
      if (conf.closeOnEsc) {
        $(document).on('keydown.mask', function (e) {
          if (parseInt(e.keyCode) === 27) {
            $.mask.close(e);
          }
        });
      }

      // Mask click closes.
      if (conf.closeOnClick) {
        mask.on('click.mask', function (e) {
          $.mask.close(e);
        });
      }

      // Reveal mask.
      mask.css({display: 'block'}).fadeTo(conf.loadSpeed, conf.opacity, function () {
        call(conf.onLoad);
        loaded = 'full';
      });

      loaded = true;
      return this;
    },

    close: function () {
      if (loaded) {

        // onBeforeClose.
        if (call(config.onBeforeClose) === false) {
          return this;
        }

        mask.fadeOut(config.closeSpeed, function () {
          call(config.onClose);
          loaded = false;
        });

        // Declare the mask closed.
        $(document).trigger('mask::closed');

        // Unbind various event listeners.
        $(document).off('keydown.mask');
        mask.off('click.mask');
      }

      return this;
    },

    getMask: function () {
      return mask;
    },

    isLoaded: function (fully) {
      return fully ? loaded === 'full' : loaded;
    },

    getConf: function () {
      return config;
    }
  };

  $(window).on('mask::open', function (event) {
    $(document).mask();
  });

  $(window).on('mask::close', function (event) {
    $(document).mask.close();
  });

  $.fn.mask = function (conf) {
    $.mask.load(conf);
    return this;
  };

  $.fn.mask.isLoaded = function () {
    $.mask.isLoaded();
    return this;
  };

  $.fn.mask.close = function () {
    $.mask.close();
    return this;
  };

  $.fn.mask.getMask = function () {
    $.mask.getMask();
    return this;
  };

})(jQuery);
