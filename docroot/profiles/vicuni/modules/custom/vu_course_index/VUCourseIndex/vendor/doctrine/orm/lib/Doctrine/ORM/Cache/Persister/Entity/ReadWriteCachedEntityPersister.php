<?php

/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the MIT license. For more information, see
 * <http://www.doctrine-project.org>.
 */

namespace Doctrine\ORM\Cache\Persister\Entity;

use Doctrine\ORM\Persisters\Entity\EntityPersister;
use Doctrine\ORM\Mapping\ClassMetadata;
use Doctrine\ORM\EntityManagerInterface;
use Doctrine\ORM\Cache\ConcurrentRegion;
use Doctrine\ORM\Cache\EntityCacheKey;

/**
 * Specific read-write entity persister
 *
 * @author Fabio B. Silva <fabio.bat.silva@gmail.com>
 * @since 2.5
 */
class ReadWriteCachedEntityPersister extends AbstractEntityPersister {
  /**
   * @param \Doctrine\ORM\Persisters\Entity\EntityPersister $persister The
   *   entity persister to cache.
   * @param \Doctrine\ORM\Cache\ConcurrentRegion $region The entity cache
   *   region.
   * @param \Doctrine\ORM\EntityManagerInterface $em The entity manager.
   * @param \Doctrine\ORM\Mapping\ClassMetadata $class The entity metadata.
   */
  public function __construct(EntityPersister $persister, ConcurrentRegion $region, EntityManagerInterface $em, ClassMetadata $class) {
    parent::__construct($persister, $region, $em, $class);
  }

  /**
   * {@inheritdoc}
   */
  public function afterTransactionComplete() {
    $isChanged = TRUE;

    if (isset($this->queuedCache['update'])) {
      foreach ($this->queuedCache['update'] as $item) {
        $this->region->evict($item['key']);

        $isChanged = TRUE;
      }
    }

    if (isset($this->queuedCache['delete'])) {
      foreach ($this->queuedCache['delete'] as $item) {
        $this->region->evict($item['key']);

        $isChanged = TRUE;
      }
    }

    if ($isChanged) {
      $this->timestampRegion->update($this->timestampKey);
    }

    $this->queuedCache = array();
  }

  /**
   * {@inheritdoc}
   */
  public function afterTransactionRolledBack() {
    if (isset($this->queuedCache['update'])) {
      foreach ($this->queuedCache['update'] as $item) {
        $this->region->evict($item['key']);
      }
    }

    if (isset($this->queuedCache['delete'])) {
      foreach ($this->queuedCache['delete'] as $item) {
        $this->region->evict($item['key']);
      }
    }

    $this->queuedCache = array();
  }

  /**
   * {@inheritdoc}
   */
  public function delete($entity) {
    $key = new EntityCacheKey($this->class->rootEntityName, $this->uow->getEntityIdentifier($entity));
    $lock = $this->region->lock($key);

    if ($this->persister->delete($entity)) {
      $this->region->evict($key);
    }

    if ($lock === NULL) {
      return;
    }

    $this->queuedCache['delete'][] = array(
      'lock' => $lock,
      'key' => $key
    );
  }

  /**
   * {@inheritdoc}
   */
  public function update($entity) {
    $key = new EntityCacheKey($this->class->rootEntityName, $this->uow->getEntityIdentifier($entity));
    $lock = $this->region->lock($key);

    $this->persister->update($entity);

    if ($lock === NULL) {
      return;
    }

    $this->queuedCache['update'][] = array(
      'lock' => $lock,
      'key' => $key
    );
  }
}
