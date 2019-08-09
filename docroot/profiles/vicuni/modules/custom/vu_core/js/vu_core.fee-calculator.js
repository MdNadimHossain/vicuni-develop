(function ($, Drupal) {
  'use strict';
  Drupal.behaviors.feeCalculator = {
    firefoxHoveringOverSearchResults: false,
    searchRequestHandler: null,
    attach: function () {
      var self = this;

      var $domesticBtn = $('#btn-domestic');
      var $internationalBtn = $('#btn-international');
      var $internationalField = $('#international-field');

      $domesticBtn.click(function () {
        $(this).addClass('active');
        $internationalBtn.removeClass('active');
        $internationalField.val(0);
        $('#residential-modal-residency').text('Australian residents');
        self.redrawForm();

        $('#fee-results-0').addClass('fee-results--visible');
        $('#fee-results-1').removeClass('fee-results--visible');

        $('#fee-search-query-label-text').text('I want to search fees by');

        self.processDisclaimers();
        self.checkMyCalculatedFeesButton();
      });

      $internationalBtn.click(function () {
        $(this).addClass('active');
        $domesticBtn.removeClass('active');
        $internationalField.val(1);
        $('#residential-modal-residency').text('International students');
        self.redrawForm();

        $('#fee-results-0').removeClass('fee-results--visible');
        $('#fee-results-1').addClass('fee-results--visible');

        $('#fee-search-query-label-text').text('I want to search fees for');

        self.processDisclaimers();
        self.checkMyCalculatedFeesButton();
      });

      $('[name=sector]').change(function () {
        if ($(this).val() === 'HE') {
          $('#cohort-year-field').show();
        }
        else {
          $('#cohort-year-field').hide();
        }
      });

      var $footer = $('footer');

      // Residency Info modal
      var $residentialInfoModalButton = $('.js-residency-btn-modal');
      var $residencyInfoModal = $('#residency-info-modal');
      $footer.after($residencyInfoModal);

      $residentialInfoModalButton.click(function () {
        $residencyInfoModal.modal('show');
      });

      $residencyInfoModal.on('hidden.bs.modal', function () {
        $residentialInfoModalButton.focus();
      });

      // Fee Type Info modal
      var $feeTypeInfoModalButton = $('.js-fee-type-btn-modal');
      var $feeTypeInfoModal = $('#fee-type-info-modal');
      $footer.after($feeTypeInfoModal);

      $feeTypeInfoModalButton.click(function () {
        $feeTypeInfoModal.modal('show');
      });

      $feeTypeInfoModal.on('hidden.bs.modal', function () {
        $feeTypeInfoModalButton.focus();
      });

      $('#fee-calculator-form').submit(function (event) {
        event.preventDefault();
      });

      var $elementsToHide = $('#fee-search-results-loading, #fee-search-results-no-results, #fee-search-results');

      $('#fee-search-container').focusout(function (event) {
        var $targetElement = $(event.relatedTarget);
        if ($targetElement.length === 0) {
          if (!self.firefoxHoveringOverSearchResults) {
            $elementsToHide.hide();
          }
        }
        else {
          if (!$targetElement.hasClass('fee-search-result') && $targetElement.attr('id') !== 'fee-search-query') {
            $elementsToHide.hide();
          }
        }
      });

      // I want to search fees by...
      self.initialiseSearchQueryField();

      self.handleMyCalculatedFeesButton();
    },
    handleMyCalculatedFeesButton: function () {
      var $feeButtonContainer = $('.calculated-fees-button-container');
      var $feesButton = $('.calculated-fees-button');
      var $pageHeader = $('#page-header');

      function positionMyCalculatedFeesButton() {
        var windowScrollTop = $(window).scrollTop();
        var headerHeight = $pageHeader.height();

        if (windowScrollTop >= $feeButtonContainer.offset().top - headerHeight) {
          var offset = jQuery('.main-container').offset().top - headerHeight;

          $feesButton.addClass('affix').css('top', windowScrollTop - offset);
        }
        else {
          $feesButton.removeClass('affix');
        }
      }

      $(window).scroll(positionMyCalculatedFeesButton);

      $(window).resize(positionMyCalculatedFeesButton);

      $feesButton.click(function () {
        if ($feesButton.hasClass('affix')) {
          $('html, body').animate({
            scrollTop: $('.fee-form-container').offset().top - $pageHeader.height()
          }, 600);
        }
        else {
          $('html, body').animate({
            scrollTop: $('.fee-results-container').offset().top - $pageHeader.height() - $feesButton.height()
          }, 600);
        }
      });
    },
    redrawForm: function () {
      var self = this;

      var international = $('#international-field').val();
      if (international === '1') {
        $('#fee-type-field').hide();
        $('#sector-field').show();
        $('#cohort-year-field').show();
        $('#fee-context-field').hide();
        $('#fee-search-query-field').removeClass('col-sm-9').addClass('col-sm-12');
        $('#fee-search-query').attr('placeholder', self.getSearchQueryPlaceholderText());
      }
      else {
        $('#fee-type-field').show();
        $('#sector-field').hide();
        $('#cohort-year-field').hide();
        $('#fee-context-field').show();
        $('#fee-search-query-field').removeClass('col-sm-12').addClass('col-sm-9');
        $('#fee-search-query').attr('placeholder', self.getSearchQueryPlaceholderText());
      }
    },
    checkMyCalculatedFeesButton: function () {
      var international = $('#international-field').val();

      var resultCount = $('#fee-results-' + international).find('table tbody tr').length;
      if (resultCount === 0) {
        $('.calculated-fees-button')
          .prop('disabled', true)
          .addClass('calculated-fees-button--disabled');

        $('.fee-count').text('(' + resultCount + ')');
      }
      else {
        $('.calculated-fees-button')
          .prop('disabled', false)
          .removeClass('calculated-fees-button--disabled');

        $('.fee-count').text('(' + resultCount + ')');
      }
    },
    initialiseSearchQueryField: function () {
      var self = this;

      var $searchQuery = $('#fee-search-query');

      var $feeContextSelect = $('#fee-context');

      $feeContextSelect.change(function () {
        $searchQuery.attr('placeholder', self.getSearchQueryPlaceholderText());
      });

      var $feeSearchResults = $('#fee-search-results');
      var $feeSearchResultsLoading = $('#fee-search-results-loading');
      var $feeSearchResultsNoResults = $('#fee-search-results-no-results');

      $searchQuery.keyup(function (event) {
        switch (event.which) {
          case 9:
          case 16:
          case 37:
          case 39:
            break;
          case 27:
            $feeSearchResults.hide();
            $feeSearchResultsLoading.hide();
            $feeSearchResultsNoResults.hide();
            break;
          default:
            var searchQuery = event.target.value;
            var trimmedSearchQuery = searchQuery.trim();
            if (trimmedSearchQuery && trimmedSearchQuery.length > 2) {
              $feeSearchResults.hide();
              $feeSearchResultsNoResults.hide();
              self.performSearchQuery(trimmedSearchQuery);
            }
            else {
              if (self.searchRequestHandler) {
                self.searchRequestHandler.abort();
              }

              $feeSearchResultsLoading.hide();
              $feeSearchResults.hide();
              $feeSearchResultsNoResults.hide();
            }
        }
      });

      $searchQuery.blur(function (event) {
        if (self.searchRequestHandler) {
          self.searchRequestHandler.abort();
        }
      });
    },
    performSearchQuery: function (searchQuery) {
      var self = this;

      $('#fee-search-results-loading').show();

      self.searchRequestHandler = $.ajax({
        method: 'GET',
        url: self.getSearchEndpoint(),
        data: self.getRequestQueryParams(searchQuery),
        beforeSend: function () {
          if (self.searchRequestHandler) {
            self.searchRequestHandler.abort();
          }
        },
        success: function (data) {
          $('#fee-search-results-loading').hide();
          self.buildResultsList(data);
        }
      });
    },
    getSearchEndpoint: function () {
      if ($('#international-field').val() === '0' && $('#fee-context').val() === 'unit') {
        return '/fees/search/unit';
      }
      return '/fees/search/course';
    },
    getRequestQueryParams: function (searchQuery) {
      var international = $('#international-field').val();

      var queryParams = {
        query: searchQuery,
        international: international,
        feeYear: $('[name=fee-year]:checked').val()
      };

      if (international === '1') {
        var sector = $('[name=sector]:checked').val();
        queryParams['sector'] = sector;
        if (sector === 'HE') {
          queryParams['cohortYear'] = $('#cohort-year').val();
        }
      }
      else {
        queryParams['feeType'] = $('#fee-type').val();
      }

      return queryParams;
    },
    buildResultsList: function (results) {
      var self = this;

      if (results.length === 0) {
        $('#fee-search-results-no-results').show();
        return;
      }

      var $feeSearchResults = $('#fee-search-results');

      $feeSearchResults.show();

      $feeSearchResults.empty();

      results.forEach(function (result) {
        var context = $('#fee-context').val();

        var buttonTitle = result.course_code + ' - ' + result.course_title;
        if (result.is_international !== '1' && context === 'unit') {
          buttonTitle = result.unit_code + ' - ' + result.unit_title;
        }

        var $button = $('<button type="button" class="list-group-item fee-search-result" role="option" aria-selected="false">' + buttonTitle + '</button>');

        $button.keyup(function (event) {
          if (event.which === 27) {
            $('#fee-search-query').focus();
            $feeSearchResults.hide();
          }
        });

        $button.hover(function () {
          self.firefoxHoveringOverSearchResults = true;
        }, function () {
          self.firefoxHoveringOverSearchResults = false;
        });

        $button.blur(function (event) {
          $(this).attr('aria-selected', false);
        });

        $button.focus(function (event) {
          $(this).attr('aria-selected', true);
        });

        $button.click(function () {
          $('#fee-search-results').hide();

          if (result.is_international === '1') {
            switch (result.sector) {
              case 'HE':
                self.addTableRow(
                  'fee-results-1-course-' + result.sector + '-' + result.cohort_year,
                  result.nid,
                  result.fee,
                  result.year,
                  result.course_code,
                  result.course_title,
                  result.disclaimers,
                  [result.credit_points, result.eftsl]
                );
                break;
              case 'VE':
                self.addTableRow(
                  'fee-results-1-course-' + result.sector,
                  result.nid,
                  result.fee,
                  result.year,
                  result.course_code,
                  result.course_title,
                  result.disclaimers,
                  [result.contact_hours]
                );
                break;
            }
          }
          else {
            switch (context) {
              case 'unit':
                switch (result.sector) {
                  case 'HE':
                    self.addTableRow(
                      'fee-results-0-unit-' + result.fee_type,
                      result.nid,
                      result.fee,
                      result.year,
                      result.unit_code,
                      result.unit_title,
                      result.disclaimers,
                      [result.credit_points, result.eftsl]
                    );
                    break;
                  case 'VE':
                    var unitHourlyRate = self.formatMoney(parseFloat(result.hourly_rate));

                    self.addTableRow(
                      'fee-results-0-unit-' + result.fee_type,
                      result.nid,
                      result.fee,
                      result.year,
                      result.unit_code,
                      result.unit_title,
                      result.disclaimers,
                      [result.contact_hours, unitHourlyRate]
                    );
                    break;
                }
                break;
              case 'course':
                switch (result.sector) {
                  case 'HE':
                    self.addTableRow(
                      'fee-results-0-course-' + result.fee_type,
                      result.nid,
                      result.fee,
                      result.year,
                      result.course_code,
                      result.course_title,
                      result.disclaimers,
                      [result.credit_points, result.eftsl]
                    );
                    break;
                  case 'VE':
                    var hourlyRate = self.formatMoney(parseFloat(result.hourly_rate));

                    self.addTableRow(
                      'fee-results-0-course-' + result.fee_type,
                      result.nid,
                      result.fee,
                      result.year,
                      result.course_code,
                      result.course_title,
                      result.disclaimers,
                      [result.contact_hours, hourlyRate]
                    );
                    break;
                }
            }
          }
        });

        $feeSearchResults.append($button);
      });
    },
    addTableRow: function (tableId, feeId, fee, year, code, title, disclaimers, columns) {
      var self = this;

      var $table = $('#' + tableId);
      $table.show();

      var $tbody = $table.find('tbody');

      var $row = $tbody.find('tr[data-id=' + feeId + ']');
      if ($row.length === 0) {
        $row = $(
          '<tr data-id="' + feeId + '" data-fee="' + fee + '">' +
            '<td>' + year + '</td>' +
            '<td>' + code + '</td>' +
            '<td class="course-title">' + title + '</td>' +
            columns.reduce(function (accumulator, column) {
              return accumulator + '<td>' + column + '</td>';
            }, '') +
            '<td class="fee-value">' +
              '<div class="fee-value-content">' +
                '<span>' + self.formatMoney(parseFloat(fee)) + '</span>' +
                '<span class="disclaimers" data-disclaimers="[' + disclaimers.toString() + ']"></span>' +
              '</div>' +
            '</td>' +
            '<td class="actions"></td>' +
          '</tr>'
        );

        var $removeButton = $('<button class="btn-remove-fee"></button>');
        $removeButton.click(function () {
          $row.remove();

          if ($tbody.find('tr').length === 0) {
            $table.hide();
          }

          self.checkMyCalculatedFeesButton();
          self.processDisclaimers();
          self.calculateTableTotal(tableId);
        });
        $row.find('.actions').append($removeButton);

        $tbody.append($row);

        self.checkMyCalculatedFeesButton();
        self.processDisclaimers();
        self.calculateTableTotal(tableId);
      }
    },
    processDisclaimers: function () {
      var $disclaimers = $('.fee-results--visible .fee-value .disclaimers');

      // All the visible disclaimers.
      var disclaimers = [];

      // Generate a collection of all the visible disclaimers.
      $disclaimers.each(function (index, element) {
        // Iterate through all disclaimers for this fee.
        $(element).data('disclaimers').forEach(function (disclaimerId) {
          // Add the disclaimer to our collection if it doesn't yet exist.
          if (disclaimers.indexOf(disclaimerId) === -1) {
            disclaimers.push(disclaimerId);
          }
        });
      });

      // Append disclaimer to fee.
      $disclaimers.empty();
      $disclaimers.each(function (index, element) {
        var feeDisclaimers = $(element).data('disclaimers');

        var disclaimerIndices = [];
        disclaimers.forEach(function (currentDisclaimerId, index) {
          if (feeDisclaimers.indexOf(currentDisclaimerId) > -1) {
            disclaimerIndices.push(index + 1);
          }
        });

        if (disclaimerIndices.length > 0) {
          $(element).text('[' + disclaimerIndices.join() + ']');
        }
        else {
          $(element).text('');
        }
      });

      // Show disclaimer in the calculator footer.
      if (disclaimers.length > 0) {
        $('.fee-disclaimers-container').show();
        $('.fee-disclaimer-item').each(function (index, element) {
          var $feeDisclaimerItem = $(element);

          var disclaimerId = $feeDisclaimerItem.data('disclaimerId');
          var disclaimerIndex = disclaimers.indexOf(disclaimerId);
          if (disclaimerIndex === -1) {
            $feeDisclaimerItem.removeAttr('data-display-number');
            $feeDisclaimerItem.css('order', '');
            $feeDisclaimerItem.hide();
          }
          else {
            $feeDisclaimerItem.attr('data-display-number', disclaimerIndex + 1);
            $feeDisclaimerItem.css('order', disclaimerIndex + 1);
            $feeDisclaimerItem.show();
          }
        });
      }
      else {
        $('.fee-disclaimers-container').hide();
      }
    },
    calculateTableTotal: function (tableId) {
      var self = this;

      var $table = $('#' + tableId);

      var $tbody = $table.find('tbody');

      var grandTotal = 0;
      $tbody.find('tr').each(function () {
        grandTotal += parseFloat($(this).data('fee'));
      });
      var $grandTotal = $table.find('.grand-total');
      $grandTotal.text(self.formatMoney(grandTotal));
    },
    getSearchQueryPlaceholderText: function () {
      if ($('#international-field').val() === '1') {
        return 'Enter course code or name';
      }

      switch ($('#fee-context').val()) {
        case 'course':
          return 'Enter course code or name';
        case 'unit':
          return 'Enter unit code or name';
        default:
          return '';
      }
    },
    formatMoney: function (value) {
      return '$' + value.toFixed(2).replace(/\d(?=(\d{3})+\.)/g, '$&,');
    }
  };
}(jQuery, Drupal));
