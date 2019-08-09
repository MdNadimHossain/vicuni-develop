(function($) {
  'use strict';

  $(function() {
    var js;
    var fjs = document.getElementsByTagName('script')[0];
    if (document.getElementById('facebook-jssdk')) {
      return;
    }
    js = document.createElement('script');
    js.id = 'facebook-jssdk';
    js.src = '//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.5&appId=428326074000298';
    fjs.parentNode.insertBefore(js, fjs);
  });
}(window.jQuery));
