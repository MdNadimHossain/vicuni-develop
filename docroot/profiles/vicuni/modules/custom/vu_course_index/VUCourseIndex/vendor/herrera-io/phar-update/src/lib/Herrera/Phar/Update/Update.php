<?php

namespace Herrera\Phar\Update;

use Herrera\Phar\Update\Exception\FileException;
use Herrera\Phar\Update\Exception\LogicException;
use KevinGH\Version\Version;
use Phar;
use SplFileObject;
use UnexpectedValueException;

/**
 * Manages an individual update.
 *
 * @author Kevin Herrera <kevin@herrera.io>
 */
class Update {
  /**
   * The temporary file path.
   *
   * @var string
   */
  private $file;

  /**
   * The name of the update file.
   *
   * @var string
   */
  private $name;

  /**
   * The URL where the public key can be downloaded from.
   *
   * @var string
   */
  private $publicKey;

  /**
   * The SHA1 file checksum.
   *
   * @var string
   */
  private $sha1;

  /**
   * The URL where the update can be downloaded from.
   *
   * @var string
   */
  private $url;

  /**
   * The version of the update.
   *
   * @var Version
   */
  private $version;

  /**
   * Sets the update information.
   *
   * @param string $name The name of the update file.
   * @param string $sha1 The SHA1 file checksum.
   * @param string $url The URL where the update can be downloaded from.
   * @param Version $version The version of the update.
   * @param string $key The URL where the public key can be downloaded
   *                         from.
   */
  public function __construct(
    $name,
    $sha1,
    $url,
    Version $version,
    $key = NULL
  ) {
    $this->name = $name;
    $this->publicKey = $key;
    $this->sha1 = $sha1;
    $this->url = $url;
    $this->version = $version;
  }

  /**
   * Copies the update file to the destination.
   *
   * @param string $file The target file.
   *
   * @throws Exception\Exception
   * @throws FileException If the file could not be replaced.
   */
  public function copyTo($file) {
    if (NULL === $this->file) {
      throw LogicException::create(
        'The update file has not been downloaded.'
      );
    }

    $mode = 0755;

    if (file_exists($file)) {
      $mode = fileperms($file) & 511;
    }

    if (FALSE === @copy($this->file, $file)) {
      throw FileException::lastError();
    }

    if (FALSE === @chmod($file, $mode)) {
      throw FileException::lastError();
    }

    $key = $file . '.pubkey';

    if (file_exists($this->file . '.pubkey')) {
      if (FALSE === @copy($this->file . '.pubkey', $key)) {
        throw FileException::lastError();
      }
    }
    elseif (file_exists($key)) {
      if (FALSE === @unlink($key)) {
        throw FileException::lastError();
      }
    }
  }

  /**
   * Cleans up by deleting the temporary update file.
   *
   * @throws FileException If the file could not be deleted.
   */
  public function deleteFile() {
    if ($this->file) {
      if (file_exists($this->file)) {
        if (FALSE === @unlink($this->file)) {
          throw FileException::lastError();
        }
      }

      if (file_exists($this->file . '.pubkey')) {
        if (FALSE === @unlink($this->file . '.pubkey')) {
          throw FileException::lastError();
        }
      }

      $dir = dirname($this->file);

      if (file_exists($dir)) {
        if (FALSE === @rmdir($dir)) {
          throw FileException::lastError();
        }
      }

      $this->file = NULL;
    }
  }

  /**
   * Downloads the update file to a temporary location.
   *
   * @return string The temporary file path.
   *
   * @throws Exception\Exception
   * @throws FileException            If the SHA1 checksum differs.
   * @throws UnexpectedValueException If the Phar is corrupt.
   */
  public function getFile() {
    if (NULL === $this->file) {
      unlink($this->file = tempnam(sys_get_temp_dir(), 'upd'));
      mkdir($this->file);

      $this->file .= DIRECTORY_SEPARATOR . $this->name;

      $in = new SplFileObject($this->url, 'rb', FALSE);
      $out = new SplFileObject($this->file, 'wb', FALSE);

      while (FALSE === $in->eof()) {
        $out->fwrite($in->fgets());
      }

      unset($in, $out);

      if ($this->publicKey) {
        $in = new SplFileObject($this->publicKey, 'r', FALSE);
        $out = new SplFileObject($this->file . '.pubkey', 'w', FALSE);

        while (FALSE === $in->eof()) {
          $out->fwrite($in->fgets());
        }

        unset($in, $out);
      }

      if ($this->sha1 !== ($sha1 = sha1_file($this->file))) {
        $this->deleteFile();

        throw FileException::create(
          'Mismatch of the SHA1 checksum (%s) of the downloaded file (%s).',
          $this->sha1,
          $sha1
        );
      }

      // double check
      try {
        new Phar($this->file);
      }
      catch (UnexpectedValueException $exception) {
        $this->deleteFile();

        throw $exception;
      }
    }

    return $this->file;
  }

  /**
   * Returns name of the update file.
   *
   * @return string The name.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Returns the URL where the public key can be downloaded from.
   *
   * @return string The URL.
   */
  public function getPublicKey() {
    return $this->publicKey;
  }

  /**
   * Returns the SHA1 file checksum.
   *
   * @return string The checksum.
   */
  public function getSha1() {
    return $this->sha1;
  }

  /**
   * Returns the URL where the update can be downloaded from.
   *
   * @return string The URL.
   */
  public function getUrl() {
    return $this->url;
  }

  /**
   * Returns the version of the update.
   *
   * @return Version The version.
   */
  public function getVersion() {
    return $this->version;
  }

  /**
   * Checks if this update is newer than the version given.
   *
   * @param Version $version The current version.
   *
   * @return boolean TRUE if the update is newer, FALSE if not.
   */
  public function isNewer(Version $version) {
    return $this->version->isGreaterThan($version);
  }
}
