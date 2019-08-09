/**
 * @file
 */

/* global jQuery, Drupal, moment */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.vu_chat_now = {
    attach: function (context, settings) {
      // Add Australia/Melbourne to the zones.
      if (!moment.tz.zone('Australia/Melbourne')) {
        moment.tz.add('Australia/Melbourne|AEST AEDT|-a0 -b0|0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101|-293lX xcX 10jd0 yL0 1cN0 1cL0 1fB0 19X0 17c10 LA0 1C00 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 U00 1qM0 WM0 1qM0 11A0 1tA0 U00 1tA0 U00 1tA0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 WM0 1qM0 11A0 1o00 11A0 1o00 11A0 1o00 11A0 1qM0 WM0 11A0 1o00 1qM0 11A0 1o00 11A0 1o00 11A0 1qM0 WM0 1qM0 11A0 1o00 WM0 1qM0 14o0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0|39e5');
      }

      // Set Local Time.
      var local_time = moment().tz('Australia/Melbourne');
      $('.chat-now-local-time').html(local_time.format('dddd DD MMMM hh:mma') + ' ' + local_time.zoneAbbr());

      // Chat now - button display.
      function is_chat_available() {
        if (typeof settings['chat_now'] !== 'undefined') {
          // Get today.
          var today = moment().tz('Australia/Melbourne');
          var t_day = today.format('dddd');
          var dates = settings['chat_now'].dates;
          var timetable_day = null;

          // Check for today in the results.
          for (var day in dates) {
            if (day === t_day) {
              timetable_day = day;
              break;
            }
          }
          if (timetable_day != null) {
            // Find if chat is available right now.
            var today_str = today.format('DD-MM-YY');
            var start = dates[timetable_day].start_time;
            var end = dates[timetable_day].end_time;
            var t_start = moment.tz(today_str + ' ' + start, ['DD-MM-YY h:m a'], 'Australia/Melbourne');
            var t_end = moment.tz(today_str + ' ' + end, ['DD-MM-YY h:m a'], 'Australia/Melbourne');
            var chat_available = today.isBetween(t_start, t_end, null, '[]');
            return chat_available;
          }
          else {
            return false;
          }
        }
      }

      // Toggle the '.open' / '.closed' class on chat link.
      if (is_chat_available()) {
        $('.link-to-chat-inner').addClass('open').removeClass('closed');
        $('.link-to-chat-inner > .message').text(settings['chat_now'].open_message);
      }
      else {
        $('.link-to-chat-inner').addClass('closed').removeClass('open');
        $('.link-to-chat-inner > .message').text(settings['chat_now'].close_message);
      }
    }
  };
}(jQuery, Drupal));
