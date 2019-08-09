<?php
/**
 * @file
 * vu_rp.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function vu_rp_filter_default_formats() {
  $formats = array();

  // Exported format: Researcher.
  $formats['researcher'] = array(
    'format' => 'researcher',
    'name' => 'Researcher',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <h3> <h4> <h5> <h6> <address> <p> <h2> <hr> <table> <th> <tr> <td> <i> <small> <sub> <sup>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'media_filter' => array(
        'weight' => -40,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -36,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -34,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -33,
        'status' => 1,
        'settings' => array(
          'settings_source' => 'global',
          'local_paths' => '',
          'protocol_style' => 'full',
          'local_settings' => array(
            'protocol_style' => 'full',
            'local_paths' => '',
          ),
        ),
      ),
    ),
  );

  return $formats;
}
