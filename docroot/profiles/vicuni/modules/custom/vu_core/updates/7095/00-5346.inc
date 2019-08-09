<?php

/**
 * @file
 * PW-5346 - Create the "Fee calculator" page.
 */

use Drupal\drupal_helpers\Feature;

// Revert features.
Feature::revert('vu_core', 'field_base');
Feature::revert('vu_core', 'field_group');
Feature::revert('vu_core', 'field_instance');

// Create the Fee Calculator page.
$page = entity_create('node', [
  'type' => 'page_builder',
  'status' => NODE_PUBLISHED,
]);

$pageMetadata = entity_metadata_wrapper('node', $page);

$pageMetadata->title->set('Fee calculator');
$pageMetadata->body->summary->set('Use the fee calculator to get an indicator of what your course and unit fees could be.');
$pageMetadata->field_theme->set('victory');
$pageMetadata->save();

// Fee Calculator section.
$componentSectionHostEntity = node_load($page->nid);

$componentSection = new ParagraphsItemEntity(['field_name' => 'field_page_paragraphs', 'bundle' => 'component_section']);
$componentSection->setHostEntity('node', $componentSectionHostEntity);
$componentSection->save();

$firstRowHostEntity = paragraphs_item_load($componentSection->item_id);

$firstRow = new ParagraphsItemEntity(['field_name' => 'field_component_section_content', 'bundle' => 'component_row']);
$firstRow->setHostEntity('paragraphs_item', $firstRowHostEntity);
$firstRow->save();

$feeCalculatorHostEntity = paragraphs_item_load($firstRow->item_id);

$feeCalculator = new ParagraphsItemEntity(['field_name' => 'field_row_components', 'bundle' => 'fee_calculator']);
$feeCalculator->setHostEntity('paragraphs_item', $feeCalculatorHostEntity);
$feeCalculator->save();

// Contact Us section.
$componentSectionHostEntity = node_load($page->nid);

$componentSection = new ParagraphsItemEntity(['field_name' => 'field_page_paragraphs', 'bundle' => 'component_section']);
$componentSection->field_component_section_title[LANGUAGE_NONE][]['value'] = 'Contact us';
$componentSection->setHostEntity('node', $componentSectionHostEntity);
$componentSection->save();

$secondRowHostEntity = paragraphs_item_load($componentSection->item_id);

$secondRow = new ParagraphsItemEntity(['field_name' => 'field_component_section_content', 'bundle' => 'component_row']);
$secondRow->setHostEntity('paragraphs_item', $secondRowHostEntity);
$secondRow->save();

$contactUsLinksHostEntity = paragraphs_item_load($secondRow->item_id);

$contactUsLinks = new ParagraphsItemEntity(['field_name' => 'field_row_components', 'bundle' => 'related_links']);
$contactUsLinks->field_paragraph_links_style[LANGUAGE_NONE][]['value'] = 'contact';
$contactUsLinks->field_hide_title[LANGUAGE_NONE][]['value'] = TRUE;
$contactUsLinks->setHostEntity('paragraphs_item', $contactUsLinksHostEntity);
$contactUsLinks->save();

// Phone.
$phoneHostEntity = paragraphs_item_load($contactUsLinks->item_id);

$phone = new ParagraphsItemEntity(['field_name' => 'field_paragraph_links', 'bundle' => 'link_phone_number']);
$phone->field_international_phone_number[LANGUAGE_NONE][]['value'] = '+61399196100';
$phone->field_link_icon[LANGUAGE_NONE][]['value'] = 'fa-phone';
$phone->field_link_title[LANGUAGE_NONE][]['value'] = 'Phone +61 9919 6100';
$phone->setHostEntity('paragraphs_item', $phoneHostEntity);
$phone->save();

// AskVU.
$askvuHostEntity = paragraphs_item_load($contactUsLinks->item_id);

$askvu = new ParagraphsItemEntity(['field_name' => 'field_paragraph_links', 'bundle' => 'link_external']);
$askvu->field_link_icon[LANGUAGE_NONE][]['value'] = 'fa-comments';
$askvu->field_link_link[LANGUAGE_NONE][] = [
  'title' => 'Ask us a question',
  'url' => 'https://askvu.vu.edu.au/',
];
$askvu->setHostEntity('paragraphs_item', $askvuHostEntity);
$askvu->save();

// VUHQ.
$vuhqHostEntity = paragraphs_item_load($contactUsLinks->item_id);

$vuhq = new ParagraphsItemEntity(['field_name' => 'field_paragraph_links', 'bundle' => 'link_internal']);
$vuhq->field_link_icon[LANGUAGE_NONE][]['value'] = 'fa-university';
$vuhq->field_link_title[LANGUAGE_NONE][]['value'] = 'VUHQ (student service centres)';
$vuhq->field_node_entity_ref[LANGUAGE_NONE][]['target_id'] = 10888946;
$vuhq->setHostEntity('paragraphs_item', $vuhqHostEntity);
$vuhq->save();

// Live Chat.
$livechatHostEntity = paragraphs_item_load($contactUsLinks->item_id);

$livechat = new ParagraphsItemEntity(['field_name' => 'field_paragraph_links', 'bundle' => 'link_external']);
$livechat->field_link_icon[LANGUAGE_NONE][]['value'] = 'fa-users';
$livechat->field_link_link[LANGUAGE_NONE][] = [
  'title' => 'Chat with our staff',
  'url' => 'https://gotovu.custhelp.com/app/home?initchat=true',
];
$livechat->setHostEntity('paragraphs_item', $livechatHostEntity);
$livechat->save();

// Set up Fee Calculator page routing.
$menuItem = [
  'menu_name' => 'main-menu',
  'plid' => '2638971',
  'link_path' => 'node/' . $page->nid,
  'link_title' => 'Fee calculator',
];
menu_link_save($menuItem);

menu_cache_clear_all();

$pageLoad = node_load($page->nid);
$pageLoad->path['pathauto'] = 1;
node_save($pageLoad);
