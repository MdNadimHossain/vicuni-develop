/**
 * @file
 * Client-side formatting of chat opening times.
 *
 * This is required to support cached pages.
 */

/* global jQuery, Drupal, moment */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.vuChatFooter = {
    attach: function (context, settings) {
      if (!moment || typeof settings['vu_chat_footer'] === 'undefined') {
        return;
      }

      this.initTimezone();

      // Add Australia/Melbourne to the zones.
      if (!moment.tz.zone('Australia/Melbourne')) {
        moment.tz.add('Australia/Melbourne|AEST AEDT|-a0 -b0|0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101|-293lX xcX 10jd0 yL0 1cN0 1cL0 1fB0 19X0 17c10 LA0 1C00 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 U00 1qM0 WM0 1qM0 11A0 1tA0 U00 1tA0 U00 1tA0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 WM0 1qM0 11A0 1o00 11A0 1o00 11A0 1o00 11A0 1qM0 WM0 11A0 1o00 1qM0 11A0 1o00 11A0 1o00 11A0 1qM0 WM0 1qM0 11A0 1o00 WM0 1qM0 14o0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0|39e5');
      }

      // Set Local Time.
      var local_time = moment().tz('Australia/Melbourne');
      $('.chat-now-local-time').html(local_time.format('dddd DD MMMM h:mma') + ' ' + local_time.zoneAbbr());

      var times = settings.vu_chat_footer.times || {};
      times = this.sortTimes(times);
      var state = this.getState(times);

      var title = state.isOpen ? settings.vu_chat_footer.open_title : settings.vu_chat_footer.close_title;
      var message = state.isOpen ? settings.vu_chat_footer.open_message : settings.vu_chat_footer.close_message;
      var hoursTitle = state.isOpen ? settings.vu_chat_footer.hours_open_title : settings.vu_chat_footer.hours_close_title;
      var timezone = local_time.zoneAbbr();
      var format = 1;
      var url = state.isOpen ? settings.vu_chat_footer.url : '';

      $('.js-chat-status-title', context).text(title);
      $('.js-chat-status-message', context).text(message);
      $('.js-chat-status-title', context).attr('href', url);

      $('.js-chat-status-title').on('click', function (e) {
        if ($(this).hasClass('chat-close') || ($(this).text() === 'Chat closed')) {
          e.preventDefault();
        }
      });

      if (settings.vu_chat_footer.start && settings.vu_chat_footer.finish) {
        $('.js-chat-hours-title', context).text(hoursTitle);
        $('.vu-chat-footer .js-chat-hours', context).html(this.renderHours(state.weekday, settings.vu_chat_footer.start, settings.vu_chat_footer.finish, timezone, format));

        // Landing pages specific.
        if (typeof settings['vu_chat_landing_pages'] !== 'undefined') {
          format = state.isOpen ? 2 : 3;
          $('.vu-chat-landing-pages .js-chat-hours', context).html(this.renderHours(state.weekday, settings.vu_chat_footer.start, settings.vu_chat_footer.finish, timezone, format));

          // Handle chat class.
          if (state.isOpen) {
            $('.vu-chat-landing-pages .js-chat-status-title', context).removeClass('chat-close');
          }
          else {
            if (!$('.vu-chat-landing-pages .js-chat-status-title', context).hasClass('chat-close')) {
              $('.vu-chat-landing-pages .js-chat-status-title', context).addClass('chat-close');
            }
          }
        }
      }
    },

    /**
     * Render hours string.
     */
    renderHours: function (weekday, start, finish, timezone, format) {
      // Change output for landing.
      switch (format) {
        case 1:
          return weekday.substring(0, 3) + ', ' + start + ' &ndash; ' + finish + ' (' + timezone + ')';

        case 2:
          return start + ' &ndash; ' + finish + ' (' + timezone + ')';

        case 3:
          return weekday.substring(0, 3) + ', ' + start + ' &ndash; ' + finish + ' (' + timezone + ')';

      }
    },

    /**
     * Init current server timezone.
     */
    initTimezone: function () {
      // Add Australia/Melbourne to the zones.
      if (!moment.tz.zone('Australia/Melbourne')) {
        moment.tz.add('Australia/Melbourne|AEST AEDT|-a0 -b0|0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101|-293lX xcX 10jd0 yL0 1cN0 1cL0 1fB0 19X0 17c10 LA0 1C00 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 Oo0 1zc0 Oo0 1zc0 U00 1qM0 WM0 1qM0 11A0 1tA0 U00 1tA0 U00 1tA0 Oo0 1zc0 Oo0 1zc0 Rc0 1zc0 Oo0 1zc0 WM0 1qM0 11A0 1o00 11A0 1o00 11A0 1o00 11A0 1qM0 WM0 11A0 1o00 1qM0 11A0 1o00 11A0 1o00 11A0 1qM0 WM0 1qM0 11A0 1o00 WM0 1qM0 14o0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1cM0 1fA0 1cM0 1cM0 1cM0 1cM0|39e5');
      }
    },

    /**
     * Get Australian date for today.
     */
    getTodayDate: function () {
      return moment().tz('Australia/Melbourne');
    },

    /**
     * Get today day of the week.
     */
    getTodayWeekday: function (now) {
      return now ? now.format('dddd') : this.getTodayDate().format('dddd');
    },

    /**
     * Get next week day.
     */
    getNextWeekday: function (times, now) {
      now = now || this.getTodayDate();
      now = now.clone();
      for (var i = 1; i < 8; i++) {
        var nextDay = now.add(1, 'days').format('dddd');
        if (this.getTimesForWeekday(times, nextDay)) {
          return nextDay;
        }
      }
      return false;
    },

    /**
     * Get hours for current day.
     */
    getTodayHours: function (times, now) {
      now = now || this.getTodayDate();
      var weekday = this.getTodayWeekday(now);

      return this.getTimesForWeekday(times, weekday);
    },

    /**
     * Get hours for next weekday.
     */
    getNextWeekdayHours: function (times, now) {
      var weekday = this.getNextWeekday(times, now);
      return this.getTimesForWeekday(times, weekday);
    },

    /**
     * Get chat state.
     */
    getState: function (times, now) {
      var state = {
        isOpen: null,
        start: null,
        finish: null,
        weekday: null
      };

      now = now || this.getTodayDate();
      var todayHours = this.getTodayHours(times, now);
      if (!todayHours) {
        state.weekday = this.getNextWeekday(times, now);
        hours = this.getNextWeekdayHours(times, now);
        state.isOpen = false;
        if (hours !== null) {
          state.start = 'start_time' in hours ? hours['start_time'] : null;
          state.finish = 'end_time' in hours ? hours['end_time'] : null;
        }
        return state;
      }

      var start = moment.tz(now.format('DD-MM-YY') + ' ' + todayHours['start_time'], ['DD-MM-YY h:m a'], 'Australia/Melbourne');
      var finish = moment.tz(now.format('DD-MM-YY') + ' ' + todayHours['end_time'], ['DD-MM-YY h:m a'], 'Australia/Melbourne');

      if (!start || !finish) {
        return false;
      }

      if (start > finish) {
        return false;
      }

      var hours;
      if (now.isBefore(start)) {
        hours = todayHours;
        state.isOpen = false;
        state.weekday = this.getTodayWeekday(now);
      }
      else if (now.isAfter(finish)) {
        hours = this.getNextWeekdayHours(times, now);
        state.isOpen = false;
        state.weekday = this.getNextWeekday(times, now);
      }
      else {
        hours = todayHours;
        state.isOpen = true;
        state.weekday = this.getTodayWeekday(now);
      }
      state.start = 'start_time' in hours ? hours['start_time'] : null;
      state.finish = 'end_time' in hours ? hours['end_time'] : null;

      return state;
    },

    /**
     * Sort times according to the order of the days of the week.
     */
    sortTimes: function (times) {
      var newTimes = [];
      var weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'];
      for (var idx in weekdays) {
        if (weekdays[idx] in times) {
          newTimes.push($.extend({}, times[weekdays[idx]], {weekday: weekdays[idx]}));
        }
      }
      return newTimes;
    },

    /**
     * Get times for specified day.
     */
    getTimesForWeekday: function (times, weekday) {
      var dayTimes = null;
      for (var idx in times) {
        if (times[idx].weekday === weekday) {
          dayTimes = times[idx];
          break;
        }
      }
      return dayTimes;
    }
  };
}(jQuery, Drupal));
