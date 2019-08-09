<?php

/**
 * @file
 * PW-5346 - Add Fee Calculator block to HE page.
 */

// Domestic & international student fees.
$page = node_load(10935136);

// Domestic student fees.
$domSection = paragraphs_item_load(139161);
$domSection->setHostEntity('node', $page, LANGUAGE_NONE, FALSE);

$rhsContents = $domSection->field_paragraphs_right[LANGUAGE_NONE];

$domSection->field_paragraphs_right[LANGUAGE_NONE] = [];

$feeCalcDomLink = new ParagraphsItemEntity([
  'field_name' => 'field_paragraphs_right',
  'bundle' => 'fee_calculator_link_dom',
]);
$feeCalcDomLink->setHostEntity('paragraphs_item', $domSection);

foreach ($rhsContents as $paragraphItem) {
  $domSection->field_paragraphs_right[LANGUAGE_NONE][] = $paragraphItem;
}

$feeCalcDomLink->save();

// Domestic & international student fees.
$page = node_load(10935136);

// International student fees.
$intSection = paragraphs_item_load(139171);
$intSection->setHostEntity('node', $page, LANGUAGE_NONE, FALSE);

$rhsContents = $intSection->field_paragraphs_right[LANGUAGE_NONE];

$intSection->field_paragraphs_right[LANGUAGE_NONE] = [];

$feeCalcIntLink = new ParagraphsItemEntity([
  'field_name' => 'field_paragraphs_right',
  'bundle' => 'fee_calculator_link_int',
]);
$feeCalcIntLink->setHostEntity('paragraphs_item', $intSection);

foreach ($rhsContents as $paragraphItem) {
  $intSection->field_paragraphs_right[LANGUAGE_NONE][] = $paragraphItem;
}

$feeCalcIntLink->save();

// Calculate your VET/TAFE fees.
$page = node_load(10935301);

// Type of place in a VET/TAFE course.
$targetSection = paragraphs_item_load(143376);
$targetSection->setHostEntity('node', $page, LANGUAGE_NONE, FALSE);

$feeCalcDomLink = new ParagraphsItemEntity([
  'field_name' => 'field_paragraphs_right',
  'bundle' => 'fee_calculator_link_dom',
]);
$feeCalcDomLink->setHostEntity('paragraphs_item', $targetSection);
$feeCalcDomLink->save();
