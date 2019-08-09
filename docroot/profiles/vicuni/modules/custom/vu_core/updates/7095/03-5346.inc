<?php

/**
 * @file
 * PW-5346 - Add "fee type" taxonomy items.
 */

// Commonwealth Supported Place.
$cspPage = node_load(10891976);

$cspSection = paragraphs_item_load(4306);
$cspSection->setHostEntity('node', $cspPage, LANGUAGE_NONE, FALSE);

$cspLink = new ParagraphsItemEntity(['field_name' => 'field_paragraphs_right', 'bundle' => 'fee_calculator_link_dom']);
$cspLink->setHostEntity('paragraphs_item', $cspSection);
$cspLink->save();

// Full Fee.
$fullFeePage = node_load(10891981);

$fullFeeSection = paragraphs_item_load(4366);
$fullFeeSection->setHostEntity('node', $fullFeePage, LANGUAGE_NONE, FALSE);

$fullFeeLink = new ParagraphsItemEntity(['field_name' => 'field_paragraphs_right', 'bundle' => 'fee_calculator_link_dom']);
$fullFeeLink->setHostEntity('paragraphs_item', $fullFeeSection);
$fullFeeLink->save();

// International.
$internationalPage = node_load(10891966);

$internationalSection = paragraphs_item_load(4481);
$internationalSection->setHostEntity('node', $internationalPage, LANGUAGE_NONE, FALSE);

$internationalLink = new ParagraphsItemEntity(['field_name' => 'field_paragraphs_right', 'bundle' => 'fee_calculator_link_int']);
$internationalLink->setHostEntity('paragraphs_item', $internationalSection);
$internationalLink->save();
