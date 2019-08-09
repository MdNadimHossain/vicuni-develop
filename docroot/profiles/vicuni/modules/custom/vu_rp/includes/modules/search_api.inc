<?php

/**
 * @file
 * Search API module integration.
 */

/**
 * Implements hook_search_api_solr_query_alter().
 */
function vu_rp_search_api_solr_query_alter(&$call_args, $query) {
  $search_index = $query->getIndex();
  if ($search_index->machine_name == VU_RP_SEARCH_INDEX) {
    $params = drupal_get_query_parameters();

    // Sort order.
    $sort = [
      $call_args['params']['sort'],
      'ss_alphasort_title asc',
    ];

    // Set query string.
    if (!empty($params['query'])) {
      $q = str_replace('+', ' ', urldecode($params['query']));
      $call_args['query'] = check_plain($q);
      $call_args['params']['sort'] = implode(',', $sort);
    }
    else {
      $call_args['params']['sort'] = 'ss_alphasort_title asc';
    }

    // Add in query field.
    $call_args['params']['qf'][] = 'tm_area_expertise^1.0';

    // Set search criteria.
    if (!empty($params['rpc'])) {
      if ($params['rpc'] === VU_RP_SEARCH_SUPERVISORS) {
        // Added priority for profiles that have supervisors.
        $call_args['params']['fq'][] = "bs_field_rp_sup_is_available:1 OR bs_supervisor_unknown:1";
        $call_args['params']['bq'][] = "bs_field_rp_sup_is_available:1^100";
        $call_args['params']['bq'][] = "bs_supervisor_unknown:1^1";
        // Add sort order.
        $call_args['params']['sort'] = implode(',', $sort);
      }
      elseif ($params['rpc'] === VU_RP_SEARCH_MEDIA_QUERIES) {
        $call_args['params']['fq'][] = "bs_field_media_ready:1 OR bs_field_rp_available_to_media:1";
      }
    }
  }
}

/**
 * Implements hook_search_api_solr_documents_alter().
 */
function vu_rp_search_api_solr_documents_alter(&$documents, $index) {
  if ($index->machine_name == VU_RP_SEARCH_INDEX) {
    foreach ($documents as $document) {
      $rp_tids = $document->getField('im_field_rp_expertise');
      if (!empty($rp_tids['value'])) {
        $terms = vu_rp_flatten_terms($rp_tids['value']);
        if (!empty($terms)) {
          $document->setField('tm_area_expertise', $terms);
        }
      }

      $sp_tids = $document->getField('im_field_staff_expertise');
      if (!empty($sp_tids['value'])) {
        $terms = vu_rp_flatten_terms($sp_tids['value']);
        if (!empty($terms)) {
          $document->setField('tm_area_expertise', $terms);
        }
      }

      $title = $document->getField('tm_title');

      // Solr rejects invalid and non-printable UTF8 characters so remove them.
      $body_value = $document->getField('tm_body$value');
      $content = $document->getField('content');
      $pattern = '/[\x00-\x1F\x80-\xFF]/';

      if (!empty($body_value['value'])) {
        $document->setField('tm_body$value', preg_replace($pattern, ' ', $body_value['value']));
      }
      if (!empty($content['value'])) {
        $document->setField('content', preg_replace($pattern, ' ', $content['value']));
      }

      // Set a new field to enable sorting by last name.
      if (!empty($title['value'])) {
        $document->setField('ss_alphasort_title', _vu_core_title_order($title['value']));
      }
    }
  }
}
