<?php

namespace CourseIndex\Entity;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass="CourseIndex\EntityRepository\CourseIntakeRepository")
 * @ORM\Table(name="course_intake",indexes={@ORM\Index(name="find_latest", columns={"course_code",
 *   "intake_enabled"})})
 */
class CourseIntake extends AbstractEntity {
  /**
   * @ORM\Id
   * @ORM\GeneratedValue(strategy="AUTO")
   * @ORM\Column(type="integer")
   */
  protected $id;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,name="course_index_id")
   */
  public $CourseIndexId;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=4,name="academic_year")
   */
  public $AcademicYear;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,name="academic_calendar_type")
   */
  public $AcademicCalendarType;
  /**
   * @var int
   * @ORM\Column(type="integer",nullable=false,length=10,name="academic_calendar_sequence_number")
   */
  public $AcademicCalendarSequenceNum;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=false,name="academic_start_date")
   */
  public $AcademicStartDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=false,name="academic_end_date")
   */
  public $AcademicEndDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="course_srt_dt")
   */
  public $CommencementDate;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,name="teaching_cal_type")
   */
  public $TeachingCalendarType;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,name="teach_perd_desc")
   */
  public $TeachPeriodDescription;
  /**
   * @var string
   * @ORM\Column(type="integer",nullable=false,length=16,name="aqf_level")
   */
  public $AQFLevel;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=1,name="is_mid_year_intake")
   */
  public $IsMidYearIntake;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=15,name="admissions_calendar_type")
   */
  public $AdmissionsCalendarType;
  /**
   * @var int
   * @ORM\Column(type="integer",nullable=false,name="admissions_calendar_sequence_number")
   */
  public $AdmissionsCalendarSequenceNum;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=false,name="admissions_start_date")
   */
  public $AdmissionsStartDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="early_admissions_end_date")
   */
  public $EarlyAdmissionsEndDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=false,name="admissions_end_date")
   */
  public $AdmissionsEndDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="vtac_open_date")
   */
  public $VtacOpenDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="vtac_timely_date")
   */
  public $VtacTimelyDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="vtac_late_date")
   */
  public $VtacLateDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="vtac_very_late_date")
   */
  public $VtacVeryLateDate;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="admissions_category")
   */
  public $AdmissionCategory;
  /**
   * @var int
   * @ORM\Column(type="integer",nullable=false,name="course_offering_id")
   */
  public $CourseOfferingID;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="sector_code")
   */
  public $SectorCode;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="course_code")
   */
  public $CourseCode;
  /**
   * @var string
   * @ORM\Column(type="smallint",nullable=false,name="course_version")
   */
  public $CourseVersion;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=100,name="course_name")
   */
  public $CourseName;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=1,name="is_vtac_course")
   */
  public $IsVTACCourse;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="location")
   */
  public $Location;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=2,name="attendance_type")
   */
  public $AttendanceType;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=2,name="attendance_mode")
   */
  public $AttendanceMode;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,length=60,name="course_type")
   */
  public $CourseType;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="place_type")
   */
  public $PlaceType;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,length=10,name="specialisation_code")
   */
  public $SpecialisationCode;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,length=90,name="specialisation_name")
   */
  public $SpecialisationName;
  /**
   * @var string
   * @ORM\Column(type="smallint",nullable=true,name="unit_set_version")
   */
  public $UnitSetVersion;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="application_start_date")
   */
  public $ApplicationStartDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="application_end_date")
   */
  public $ApplicationEndDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="early_application_end_date")
   */
  public $EarlyApplicationEndDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="vtac_start_date")
   */
  public $VTACStartDate;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=true,name="vtac_end_date")
   */
  public $VTACEndDate;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="course_intake_status")
   */
  public $CourseIntakeStatus;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=10,name="college")
   */
  public $College;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=60,name="college_name")
   */
  public $CollegeName;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=1,name="is_admissions_centre_available")
   */
  public $IsAdmissionCentreAvailable;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,length=200,name="additional_requirements")
   */
  public $AdditionalRequirements;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=true,length=20,name="vtac_course_code")
   */
  public $VTACCourseCode;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=20,name="application_entry_method")
   */
  public $ApplEntryMethod;
  /**
   * @var string[]
   * @ORM\Column(type="string",nullable=true,length=500,name="supplementary_forms")
   */
  public $SupplementaryForms = NULL;
  /**
   * @var string[]
   * @ORM\Column(type="string",nullable=true,length=200,name="referee_reports")
   */
  public $RefereeReports = NULL;
  /**
   * @var string
   * @ORM\Column(type="string",nullable=false,length=1,name="expression_of_interest")
   */
  public $ExpressionOfInterest;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=false,name="updated_date_time")
   */
  public $UpdatedDateTime;
  /**
   * @var string
   * @ORM\Column(type="datetime",nullable=false,name="published_date")
   */
  public $PublishedDate;
  /**
   * @ORM\Column(type="datetime",nullable=true)
   */
  protected $created_date_time;
  /**
   * @ORM\Column(type="boolean")
   */
  protected $intake_enabled = 0;

  /**
   *
   */
  public function __construct() {
    $this->created_date_time = new \DateTime();
  }

  /**
   * @param int $AcademicCalendarSequenceNum
   */
  public function setAcademicCalendarSequenceNum($AcademicCalendarSequenceNum) {
    $this->AcademicCalendarSequenceNum = $AcademicCalendarSequenceNum;
  }

  /**
   * @param string $AcademicCalendarType
   */
  public function setAcademicCalendarType($AcademicCalendarType) {
    $this->AcademicCalendarType = $AcademicCalendarType;
  }

  /**
   * @param string $AcademicEndDate
   */
  public function setAcademicEndDate($AcademicEndDate) {
    $this->AcademicEndDate = $this->convertToDateTime($AcademicEndDate);
  }

  /**
   * @param string $AcademicStartDate
   */
  public function setAcademicStartDate($AcademicStartDate) {
    $this->AcademicStartDate = $this->convertToDateTime($AcademicStartDate);
  }

  /**
   * @param string $AcademicYear
   */
  public function setAcademicYear($AcademicYear) {
    $this->AcademicYear = $AcademicYear;
  }

  /**
   * @param string $AdditionalRequirements
   */
  public function setAdditionalRequirements($AdditionalRequirements) {
    $this->AdditionalRequirements = $AdditionalRequirements;
  }

  /**
   * @param string $AdmissionCategory
   */
  public function setAdmissionCategory($AdmissionCategory) {
    $this->AdmissionCategory = $AdmissionCategory;
  }

  /**
   * @param int $AdmissionsCalendarSequenceNum
   */
  public function setAdmissionsCalendarSequenceNum($AdmissionsCalendarSequenceNum) {
    $this->AdmissionsCalendarSequenceNum = $AdmissionsCalendarSequenceNum;
  }

  /**
   * @param string $AdmissionsCalendarType
   */
  public function setAdmissionsCalendarType($AdmissionsCalendarType) {
    $this->AdmissionsCalendarType = $AdmissionsCalendarType;
  }

  /**
   * @param string $AdmissionsEndDate
   */
  public function setAdmissionsEndDate($AdmissionsEndDate) {
    $this->AdmissionsEndDate = $this->convertToDateTime($AdmissionsEndDate);
  }

  /**
   * @param string $AdmissionsStartDate
   */
  public function setAdmissionsStartDate($AdmissionsStartDate) {
    $this->AdmissionsStartDate = $this->convertToDateTime($AdmissionsStartDate);
  }

  /**
   * @param string $ApplicationEndDate
   */
  public function setApplicationEndDate($ApplicationEndDate) {
    $this->ApplicationEndDate = $this->convertToDateTime($ApplicationEndDate);
  }

  /**
   * @param string $ApplicationStartDate
   */
  public function setApplicationStartDate($ApplicationStartDate) {
    $this->ApplicationStartDate = $this->convertToDateTime($ApplicationStartDate);
  }

  /**
   * @param string $AQFLevel
   */
  public function setAQFLevel($AQFLevel) {
    $this->AQFLevel = $AQFLevel;
  }

  /**
   * @param string $AttendanceMode
   */
  public function setAttendanceMode($AttendanceMode) {
    $this->AttendanceMode = $AttendanceMode;
  }

  /**
   * @param string $AttendanceType
   */
  public function setAttendanceType($AttendanceType) {
    $this->AttendanceType = $AttendanceType;
  }

  /**
   * @param string $College
   */
  public function setCollege($College) {
    $this->College = $College;
  }

  /**
   * @param string $CollegeName
   */
  public function setCollegeName($CollegeName) {
    $this->CollegeName = $CollegeName;
  }

  /**
   * @param string $CourseCode
   */
  public function setCourseCode($CourseCode) {
    $this->CourseCode = $CourseCode;
  }

  /**
   * @param string $CommencementDate
   */
  public function setCommencementDate($CommencementDate) {
    $this->CommencementDate = $this->convertToDateTime($CommencementDate);
  }

  /**
   * @param string $CourseIndexId
   */
  public function setCourseIndexId($CourseIndexId) {
    $this->CourseIndexId = $CourseIndexId;
  }

  /**
   * @param string $CourseIntakeStatus
   */
  public function setCourseIntakeStatus($CourseIntakeStatus) {
    $this->CourseIntakeStatus = $CourseIntakeStatus;
  }

  /**
   * @param string $CourseName
   */
  public function setCourseName($CourseName) {
    $this->CourseName = $CourseName;
  }

  /**
   * @param int $CourseOfferingID
   */
  public function setCourseOfferingID($CourseOfferingID) {
    $this->CourseOfferingID = $CourseOfferingID;
  }

  /**
   * @param string $CourseType
   */
  public function setCourseType($CourseType) {
    $this->CourseType = $CourseType;
  }

  /**
   * @param string $CourseVersion
   */
  public function setCourseVersion($CourseVersion) {
    $this->CourseVersion = $CourseVersion;
  }

  /**
   * @param string $EarlyAdmissionsEndDate
   */
  public function setEarlyAdmissionsEndDate($EarlyAdmissionsEndDate) {
    $this->EarlyAdmissionsEndDate = $this->convertToDateTime($EarlyAdmissionsEndDate);
  }

  /**
   * @param string $EarlyApplicationEndDate
   */
  public function setEarlyApplicationEndDate($EarlyApplicationEndDate) {
    $this->EarlyApplicationEndDate = $this->convertToDateTime($EarlyApplicationEndDate);
  }

  /**
   * @param string $IsAdmissionCentreAvailable
   */
  public function setIsAdmissionCentreAvailable($IsAdmissionCentreAvailable) {
    $this->IsAdmissionCentreAvailable = $IsAdmissionCentreAvailable;
  }

  /**
   * @param string $IsMidYearIntake
   */
  public function setIsMidYearIntake($IsMidYearIntake) {
    $this->IsMidYearIntake = $IsMidYearIntake;
  }

  /**
   * @param string $IsVTACCourse
   */
  public function setIsVTACCourse($IsVTACCourse) {
    $this->IsVTACCourse = $IsVTACCourse;
  }

  /**
   * @param string $Location
   */
  public function setLocation($Location) {
    $this->Location = $Location;
  }

  /**
   * @param string $PlaceType
   */
  public function setPlaceType($PlaceType) {
    $this->PlaceType = $PlaceType;
  }

  /**
   * @param string $PublishedDate
   */
  public function setPublishedDate($PublishedDate) {
    $this->PublishedDate = $this->convertToDateTime($PublishedDate);
  }

  /**
   * @param string $SectorCode
   */
  public function setSectorCode($SectorCode) {
    $this->SectorCode = $SectorCode;
  }

  /**
   * @param string $SpecialisationCode
   */
  public function setSpecialisationCode($SpecialisationCode) {
    $this->SpecialisationCode = $SpecialisationCode;
  }

  /**
   * @param string $SpecialisationName
   */
  public function setSpecialisationName($SpecialisationName) {
    $this->SpecialisationName = $SpecialisationName;
  }

  /**
   * @param string $TeachingCalendarType
   */
  public function setTeachingCalendarType($TeachingCalendarType) {
    $this->TeachingCalendarType = $TeachingCalendarType;
  }

  /**
   * @param string $TeachPeriodDescription
   */
  public function setTeachPeriodDescription($TeachPeriodDescription) {
    $this->TeachPeriodDescription = $TeachPeriodDescription;
  }

  /**
   * @param string $UnitSetVersion
   */
  public function setUnitSetVersion($UnitSetVersion) {
    $this->UnitSetVersion = $UnitSetVersion;
  }

  /**
   * @param string $UpdatedDateTime
   */
  public function setUpdatedDateTime($UpdatedDateTime) {
    $this->UpdatedDateTime = $this->convertToDateTime($UpdatedDateTime);
  }

  /**
   * @param string $VTACEndDate
   */
  public function setVTACEndDate($VTACEndDate) {
    $this->VTACEndDate = $this->convertToDateTime($VTACEndDate);
  }

  /**
   * @param string $VTACStartDate
   */
  public function setVTACStartDate($VTACStartDate) {
    $this->VTACStartDate = $this->convertToDateTime($VTACStartDate);
  }

  /**
   * @param string $VtacLateDate
   */
  public function setVtacLateDate($VtacLateDate) {
    $this->VtacLateDate = $this->convertToDateTime($VtacLateDate);
  }

  /**
   * @param string $VtacOpenDate
   */
  public function setVtacOpenDate($VtacOpenDate) {
    $this->VtacOpenDate = $this->convertToDateTime($VtacOpenDate);
  }

  /**
   * @param string $VtacTimelyDate
   */
  public function setVtacTimelyDate($VtacTimelyDate) {
    $this->VtacTimelyDate = $this->convertToDateTime($VtacTimelyDate);
  }

  /**
   * @param string $VtacVeryLateDate
   */
  public function setVtacVeryLateDate($VtacVeryLateDate) {
    $this->VtacVeryLateDate = $this->convertToDateTime($VtacVeryLateDate);
  }

  /**
   * @param string $ApplEntryMethod
   */
  public function setApplEntryMethod($ApplEntryMethod) {
    $this->ApplEntryMethod = $ApplEntryMethod;
  }

  /**
   * @param string $ExpressionOfInterest
   */
  public function setExpressionOfInterest($ExpressionOfInterest) {
    $this->ExpressionOfInterest = $ExpressionOfInterest;
  }

  /**
   * @param array $RefereeReports
   */
  public function setRefereeReports($RefereeReports) {
    $this->RefereeReports = serialize($RefereeReports);
  }

  /**
   * @param array $SupplementaryForms
   */
  public function setSupplementaryForms($SupplementaryForms) {
    $this->SupplementaryForms = serialize($SupplementaryForms);
  }

  /**
   * @param string $VTACCourseCode
   */
  public function setVTACCourseCode($VTACCourseCode) {
    $this->VTACCourseCode = $VTACCourseCode;
  }

  /**
   *
   */
  public function getId() {
    return $this->id;
  }

  /**
   * @param $value
   *
   * @return \DateTime|null
   *
   * just try and take whatever the input is and make it a datetime.
   */
  public function convertToDateTime($value) {
    if ($value instanceof \DateTime) {
      return $value;
    }
    elseif (is_numeric($value)) {
      return new \DateTime("@$value");
    }
    elseif (is_string($value)) {
      try {
        return new \DateTime("$value");
      }
      catch (Exception $e) {
        return NULL;
      }
    }
    return NULL;
  }

}
