<?php

/**
 * @file
 * Overrides the inline entity form controller for ECK Entities.
 */

/**
 * A class override to provide revisioning for ECK Inline Entities.
 */
class VUMainEckInlineEntityFormController extends EckInlineEntityFormController {

  /**
   * Create a new revisionable inline eck entity.
   *
   * Make each save a new entity, this will then save the new entity id back
   * to the new draft of the node, ensuring a functional revisioning system
   * without actual revisions.
   *
   * @param object $entity
   *   The entity to save.
   * @param array $context
   *   Available keys:
   *    - parent_entity_type: The type of the parent entity.
   *    - parent_entity: The parent entity.
   */
  public function save($entity, $context) {
    unset($entity->id);
    $entity->is_new = TRUE;
    entity_save($this->entityType, $entity);
  }

}
