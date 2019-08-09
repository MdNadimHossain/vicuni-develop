/**
 * @file
 * Marketo tracking script.
 */

(function () {
  'use strict';

  var didInit = false;
  var Munchkin = Munchkin || {};

  function initMunchkin() {
    if (didInit === false) {
      didInit = true;
      Munchkin.init('976-IJV-822', {
        cookieAnon: false
      });
    }
  }

  var s = document.createElement('script');
  s.type = 'text/javascript';
  s.async = true;
  s.src = '//munchkin.marketo.net/munchkin.js';
  s.onreadystatechange = function () {
    if (this.readyState === 'complete' || this.readyState === 'loaded') {
      initMunchkin();
    }
  };
  s.onload = initMunchkin;
  document.getElementsByTagName('head')[0].appendChild(s);
})();
