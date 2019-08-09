<?php

/**
 * @file
 * Code for the VU Researcher Profile API data render functions.
 *
 * Render functions responsible for flattening field data into values before
 * storing them in Drupal DB.
 */

/**
 * Helper to create publication citation.
 */
function _vu_rp_api_render_publication_citation($data) {
  $output = '';

  if (empty($data)) {
    return $output;
  }

  switch ($data['type']) {
    case 'Book':
      $output = _vu_rp_api_render_publications_citation_book($data);
      break;

    case 'Book Chapter':
      $output = _vu_rp_api_render_publications_citation_book_chapter($data);
      break;

    case 'Journal article':
      $output = _vu_rp_api_render_publications_citation_journal_article($data);
      break;

    case 'Research Report':
    case 'Commissioned Research Report':
      $output = _vu_rp_api_render_publications_citation_research_report($data);
      break;

    case 'Conference Paper':
      $output = _vu_rp_api_render_publications_citation_conference_paper($data);
      break;
  }

  return $output;
}

/**
 * Helper to create publication citation for Book.
 */
function _vu_rp_api_render_publications_citation_book($data) {
  $output = '';

  $authors = _vu_rp_api_render_publications_authors($data['authors']);
  $authors_line = _vu_rp_api_render_publications_authors_list($authors);

  $output .= rtrim($authors_line, '.') . '.';

  $editor = !empty($data['editor']) ? $data['editor'] : NULL;
  $editors_parsed = $editor ? _vu_rp_api_render_publications_authors([$editor]) : [];
  $editor_parsed = reset($editors_parsed);
  $is_author_editor = FALSE;
  foreach ($authors as $author) {
    if ($editor_parsed['last_name'] == $author['last_name']) {
      $is_author_editor = TRUE;
      break;
    }
  }

  if ($is_author_editor) {
    $output .= count($authors) > 1 ? ' (Eds.).' : ' (Ed.).';
  }

  $output .= ' (' . date('ymd', strtotime($data['publicationDate'])) . ').';

  $output .= ' <em>' . $data['title'] . '</em>.';

  if (!empty($data['edition'])) {
    $output = rtrim($output, '.');
    $output .= ' (' . $data['edition'] . ').';
  }

  if (!$is_author_editor && count($editors_parsed) > 0) {
    $output .= ' ' . _vu_rp_api_render_publications_authors_list([$editor_parsed]) . (count($editors_parsed) > 1 ? ' (Eds.).' : ' (Ed.).');
  }

  if (!empty($data['location'])) {
    $output .= ' ' . $data['location'] . ':';
  }

  if (!empty($data['publisher'])) {
    $output .= ' ' . $data['publisher'] . '.';
  }

  return $output;
}

/**
 * Helper to create publication citation for Book Chapter.
 */
function _vu_rp_api_render_publications_citation_book_chapter($data) {
  $output = '';

  $authors = _vu_rp_api_render_publications_authors($data['authors']);
  $authors_line = _vu_rp_api_render_publications_authors_list($authors);

  $output .= rtrim($authors_line, '.') . '.';

  $editor = !empty($data['editor']) ? $data['editor'] : NULL;
  $editors_parsed = $editor ? _vu_rp_api_render_publications_authors([$editor]) : [];
  $editor_parsed = reset($editors_parsed);

  $output .= ' (' . date('ymd', strtotime($data['publicationDate'])) . ').';
  $output .= ' <em>' . $data['title'] . '</em>.';

  if (count($editors_parsed) > 0) {
    $output = rtrim($output, '.');
    $output .= ' In ' . _vu_rp_api_render_publications_authors_list([$editor_parsed]) . (count($editors_parsed) > 1 ? ' (Eds.).' : ' (Ed.).');
  }

  if (!empty($data['edition'])) {
    $output = rtrim($output, '.');
    $output .= ' (' . $data['edition'] . ').';
  }

  $output = rtrim($output, '.');
  if (!empty($data['paginationBegin']) && !empty($data['paginationEnd'])) {
    $output .= ' (pp. ' . $data['paginationBegin'] . '-' . $data['paginationEnd'] . ').';
  }

  if (!empty($data['location'])) {
    $output .= ' ' . $data['location'] . ':';
  }

  if (!empty($data['publisher'])) {
    $output .= ' ' . $data['publisher'] . '.';
  }

  return $output;
}

/**
 * Helper to create publication citation for Journal Article.
 */
function _vu_rp_api_render_publications_citation_journal_article($data) {
  $output = '';

  $authors = _vu_rp_api_render_publications_authors($data['authors']);
  $authors_line = _vu_rp_api_render_publications_authors_list($authors);

  $output .= rtrim($authors_line, '.') . '.';

  $output .= ' (' . date('ymd', strtotime($data['publicationDate'])) . ').';

  $output .= ' ' . $data['title'] . '.';

  $output .= ' <em>' . $data['journalTitle'] . '</em>,';

  if (!empty($data['volume'])) {
    $output .= ' ' . $data['volume'];
  }
  if (!empty($data['issue'])) {
    $output .= '(' . $data['issue'] . '),';
  }

  if (!empty($data['paginationBegin']) && !empty($data['paginationEnd'])) {
    $output .= ' (' . $data['paginationBegin'] . '-' . $data['paginationEnd'] . ').';
  }

  return $output;
}

/**
 * Helper to create publication citation for Research Report.
 */
function _vu_rp_api_render_publications_citation_research_report($data) {
  $output = '';

  $authors = _vu_rp_api_render_publications_authors($data['authors']);
  $authors_line = _vu_rp_api_render_publications_authors_list($authors);

  $output .= rtrim($authors_line, '.') . '.';

  $output .= ' (' . date('ymd', strtotime($data['publicationDate'])) . ').';

  $output .= ' <em>' . $data['title'] . '</em>.';

  if (!empty($data['location'])) {
    $output .= ' ' . $data['location'] . ':';
  }

  if (!empty($data['publisher'])) {
    $output .= ' ' . $data['publisher'] . '.';
  }

  return $output;
}

/**
 * Helper to create publication citation for Conference Paper.
 */
function _vu_rp_api_render_publications_citation_conference_paper($data) {
  $output = '';

  $authors = _vu_rp_api_render_publications_authors($data['authors']);
  $authors_line = _vu_rp_api_render_publications_authors_list($authors);

  $output .= rtrim($authors_line, '.') . '.';

  $editor = !empty($data['editor']) ? $data['editor'] : NULL;
  $editors_parsed = $editor ? _vu_rp_api_render_publications_authors([$editor]) : [];
  $editor_parsed = reset($editors_parsed);

  $output .= ' (' . date('ymd', strtotime($data['publicationDate'])) . ').';
  $output .= ' ' . $data['titleOfPaper'];

  if (count($editors_parsed) > 0) {
    $output = rtrim($output, '.');
    $output .= ' In ' . _vu_rp_api_render_publications_authors_list([$editor_parsed]) . (count($editors_parsed) > 1 ? ' (Eds.),' : ' (Ed.),');
  }

  if (!empty($data['titleOfConf'])) {
    $output .= ' Paper presented at ' . $data['titleOfConf'] . '.';
  }

  if (!empty($data['paginationBegin']) && !empty($data['paginationEnd'])) {
    $output = rtrim($output, '.');
    $output .= ' (pp. ' . $data['paginationBegin'] . '-' . $data['paginationEnd'] . ').';
  }

  if (!empty($data['location'])) {
    $output .= ' ' . $data['location'] . ':';
  }

  if (!empty($data['publisher'])) {
    $output .= ' ' . $data['publisher'] . '.';
  }

  return $output;
}

/**
 * Helper to parse publication authors into a list.
 */
function _vu_rp_api_render_publications_authors($authors) {
  $authors_parsed = [];

  if (empty($authors)) {
    return $authors_parsed;
  }

  foreach ($authors as $author) {
    $author_parsed['first_name'] = '';
    $author_parsed['middle_name'] = '';

    $parts = explode(' ', $author);
    $author_parsed['last_name'] = reset($parts);
    $initials = isset($parts[1]) ? $parts[1] : '';

    // Parse initials into names.
    for ($i = 0; $i < strlen($initials); $i++) {
      if (empty($author_parsed['first_name']) || ctype_lower($initials[$i]) && empty($author_parsed['middle_name'])) {
        $author_parsed['first_name'] .= vu_rp_api_convert_strings($initials[$i]);
      }
      else {
        $author_parsed['middle_name'] .= vu_rp_api_convert_strings($initials[$i]);
      }
    }

    $authors_parsed[] = $author_parsed;
  }

  return $authors_parsed;
}

/**
 * Helper to render a list of authors.
 */
function _vu_rp_api_render_publications_authors_list($authors) {
  if (empty($authors)) {
    return '';
  }

  $items = [];
  foreach ($authors as $k => $author) {
    $line = '';
    $line .= $author['last_name'];
    if (!empty($author['first_name'])) {
      $line .= ', ' . $author['first_name'] . '.';
    }
    if (!empty($author['middle_name'])) {
      $line .= ' ' . $author['middle_name'] . '.';
    }
    if (count($authors) > 1 && $k == count($authors) - 1) {
      $line = '& ' . $line;
    }
    $items[] = $line;
  }

  return implode(', ', $items);
}
