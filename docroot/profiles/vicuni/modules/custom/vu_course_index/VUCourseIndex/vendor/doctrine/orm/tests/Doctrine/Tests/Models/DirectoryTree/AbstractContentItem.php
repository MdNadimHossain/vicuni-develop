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
 * and is licensed under the LGPL. For more information, see
 * <http://www.doctrine-project.org>.
 */

namespace Doctrine\Tests\Models\DirectoryTree;

/**
 * @MappedSuperclass
 */
abstract class AbstractContentItem {
  const CLASSNAME = __CLASS__;

  /**
   * @Id @Column(type="integer") @GeneratedValue
   */
  private $id;

  /**
   * @ManyToOne(targetEntity="Directory")
   */
  protected $parentDirectory;

  /** @column(type="string") */
  protected $name;

  /**
   * This field is transient and private on purpose
   *
   * @var bool
   */
  private $nodeIsLoaded = FALSE;

  /**
   * This field is transient on purpose
   *
   * @var mixed
   */
  public static $fileSystem;

  public function __construct(Directory $parentDir = NULL) {
    $this->parentDirectory = $parentDir;
  }

  public function getId() {
    return $this->id;
  }

  public function setName($name) {
    $this->name = $name;
  }

  public function getName() {
    return $this->name;
  }

  public function getParent() {
    return $this->parentDirectory;
  }

  /**
   * @return bool
   */
  public function getNodeIsLoaded() {
    return $this->nodeIsLoaded;
  }

  /**
   * @param bool $nodeIsLoaded
   */
  public function setNodeIsLoaded($nodeIsLoaded) {
    $this->nodeIsLoaded = (bool) $nodeIsLoaded;
  }
}
