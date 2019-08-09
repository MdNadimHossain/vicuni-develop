<?php

/**
 * @file
 * PW-5057 - VU sydney contact us.
 */

// Save contact us menu link.
$term = taxonomy_get_term_by_name('VU Sydney', 'subsites');
if (!empty($term)) {
  $term = reset($term);
  $term->field_subsite_contact_us[LANGUAGE_NONE][0]['url'] = 'vu-sydney/contact-vu-sydney';
  taxonomy_term_save($term);
}

// Save menu item to enable altering of item.
$mlid = vu_core_get_mlid_by_alias('contact-us');
if (!empty($mlid)) {

  $item = menu_link_load($mlid);
  if (!empty($item)) {
    menu_link_save($item);
  }
}
menu_cache_clear_all();
