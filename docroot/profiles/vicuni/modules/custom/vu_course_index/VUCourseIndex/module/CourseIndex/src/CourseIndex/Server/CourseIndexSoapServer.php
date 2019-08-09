<?php
namespace CourseIndex\Server;

use Zend\Soap\Exception\InvalidArgumentException as InvalidSoapArgumentException;
use Doctrine\ORM\EntityManager;
use Zend\Authentication\Adapter\ValidatableAdapterInterface;
use CourseIndex\Entity\CourseIntake;

/**
 * Class CourseIndexSoapServer.
 */
class CourseIndexSoapServer {
  protected $authenticated = FALSE;
  protected $em;
  protected $authAdapter;

  /**
   *
   */
  public function __construct(EntityManager $em, ValidatableAdapterInterface $authAdapter) {
    $this->em = $em;
    $this->authAdapter = $authAdapter;
  }

  /**
   *
   */
  protected function checkAuthentication() {
    if (!$this->authenticated) {
      throw new InvalidSoapArgumentException('Not Authorised');
    }
  }

  /**
   * WS-Security Authentication function.
   *
   * @param StdClass $UsernameToken
   *
   * @return bool
   *
   * @throws InvalidSoapArgumentException
   */
  public function Security($UsernameToken) {
    // Store username for logging.
    $result = $this->authAdapter
      ->setIdentity($UsernameToken->Username)
      ->setCredential($UsernameToken->Password)->authenticate();

    if ($result->isValid()) {
      $this->authenticated = TRUE;
    }
    else {
      throw new InvalidSoapArgumentException('Not Authorised');
    }
    return TRUE;
  }

  /**
   * Add a course index entry row.
   *
   * @param \CourseIndex\Entity\CourseIntake $entry
   *
   * @return string
   *
   * @throws InvalidSoapArgumentException
   */
  public function CourseIndexUpdate($entry) {
    $this->checkAuthentication();

    $courseIntake = new CourseIntake();

    foreach ($entry as $property => $value) {
      // This is only just a little bit magic.
      if (property_exists($courseIntake, $property)) {
        $method = 'set' . $property;
        $courseIntake->$method($value);
      }
    }

    $this->em->persist($courseIntake);
    $this->em->flush($courseIntake);

    return $courseIntake->getId();
  }

  /**
   * Confirm an individual update to commit it.
   *
   * @param string $id
   *
   * @throws \Zend\Soap\Exception\InvalidArgumentException
   *
   * @return bool
   */
  public function confirmUpdate($id) {
    $this->checkAuthentication();
    if (!is_numeric($id)) {
      throw new InvalidSoapArgumentException('ID is not numeric');
    }
    $intakeRepository = $this->em->getRepository('CourseIndex\Entity\CourseIntake');
    // $this->em->getRepository('CourseIndex\EntityRepository\CourseIntakeRepository')
    $courseIntake = $intakeRepository
      ->findOneBy(array(
        'id' => $id,
        'intake_enabled' => FALSE,
      ));

    if (!$courseIntake) {
      return FALSE;
    }
    if ($intakeRepository->isLatestVersion($courseIntake)) {
      $previousIntakes = $intakeRepository->findPreviousIncarnations($courseIntake);
      $this->em->beginTransaction();
      foreach ($previousIntakes as $previousIntake) {
        $previousIntake->setIntakeEnabled(FALSE);
      }
      $courseIntake->setIntakeEnabled(TRUE);
      $this->em->commit();
      $this->em->flush();
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Cancel an individual update to roll it back.
   *
   * @param string $id
   *
   * @return bool
   */
  public function cancelUpdate($id) {
    $this->checkAuthentication();

    return TRUE;
  }

}
