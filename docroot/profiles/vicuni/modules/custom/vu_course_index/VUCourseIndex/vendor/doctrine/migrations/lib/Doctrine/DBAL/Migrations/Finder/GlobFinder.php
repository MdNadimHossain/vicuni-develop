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

namespace Doctrine\DBAL\Migrations\Finder;

/**
 * A MigrationFinderInterface implementation that uses `glob` and some special
 * file and class names to load migrations from a directory.
 *
 * The migrations are expected to reside in files with the filename
 * `VersionYYYYMMDDHHMMSS.php`. Each file should contain one class named
 * `VersionYYYYMMDDHHMMSS`.
 *
 * @since   1.0.0-alpha3
 */
final class GlobFinder extends AbstractFinder {
  /**
   * {@inheritdoc}
   */
  public function findMigrations($directory, $namespace = NULL) {
    $dir = $this->getRealPath($directory);

    $files = glob(rtrim($dir, '/') . '/Version*.php');

    return $this->loadMigrations($files, $namespace);
  }
}
