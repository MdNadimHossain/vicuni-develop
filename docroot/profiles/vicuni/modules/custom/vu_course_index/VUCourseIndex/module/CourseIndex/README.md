Example/Test data:

    <Envelope xmlns="http://schemas.xmlsoap.org/soap/envelope/">
        <Body>
            <CourseIndexUpdate xmlns="urn:ciservice.ws.vu.edu.au">
                <entry xmlns="">
                    <CourseIndexId>1337</CourseIndexId>
                    <AcademicYear>2018</AcademicYear>
                    <AcademicCalendarType>ACAD-YR</AcademicCalendarType>
                    <AcademicCalendarSequenceNum>5115</AcademicCalendarSequenceNum>
                    <AcademicStartDate>2018-01-01</AcademicStartDate>
                    <AcademicEndDate>2018-12-31</AcademicEndDate>
                    <IsMidYearIntake>N</IsMidYearIntake>
                    <AdmissionsCalendarType>ADM-PER-1</AdmissionsCalendarType>
                    <AdmissionsCalendarSequenceNum>5144</AdmissionsCalendarSequenceNum>
                    <AdmissionsStartDate>2017-10-02</AdmissionsStartDate>
                    <EarlyAdmissionsEndDate>2017-11-16</EarlyAdmissionsEndDate>
                    <AdmissionsEndDate>2018-03-02</AdmissionsEndDate>
                    <VtacOpenDate>2017-08-07</VtacOpenDate>
                    <VtacTimelyDate>2017-09-28</VtacTimelyDate>
                    <VtacLateDate>2017-11-03</VtacLateDate>
                    <VtacVeryLateDate>2017-11-03</VtacVeryLateDate>
                    <AdmissionCategory>HE-PGRAD</AdmissionCategory>
                    <CourseOfferingID>1337</CourseOfferingID>
                    <SectorCode>HE</SectorCode>
                    <CourseCode>TEST</CourseCode>
                    <CourseVersion>1</CourseVersion>
                    <CourseName>TESTING</CourseName>
                    <IsVTACCourse>N</IsVTACCourse>
                    <Location>F</Location>
                    <AttendanceType>PT</AttendanceType>
                    <AttendanceMode>ON</AttendanceMode>
                    <CourseType>1</CourseType>
                    <PlaceType>HEFULLFEE</PlaceType>
                    <SpecialisationCode />
                    <SpecialisationName />
                    <UnitSetVersion>0</UnitSetVersion>
                    <ApplicationStartDate>2017-08-22</ApplicationStartDate>
                    <ApplicationEndDate>2018-02-22</ApplicationEndDate>
                    <EarlyApplicationEndDate />
                    <VTACStartDate />
                    <VTACEndDate />
                    <CourseIntakeStatus>OFFERED</CourseIntakeStatus>
                    <College>P7</College>
                    <CollegeName>Victoria University Business School</CollegeName>
                    <IsAdmissionCentreAvailable>Y</IsAdmissionCentreAvailable>
                    <AdditionalRequirements />
                    <VTACCourseCode />
                    <ApplEntryMethod>DIRECT</ApplEntryMethod>
                    <SupplementaryForms />
                    <RefereeReports />
                    <ExpressionOfInterest>N</ExpressionOfInterest>
                    <UpdatedDateTime>2018-01-01</UpdatedDateTime>
                    <PublishedDate>2018-01-01</PublishedDate>
                </entry>
            </CourseIndexUpdate>
        </Body>
    </Envelope>


New fields (?):

    <CourseCommenceDate>2018-02-26</CourseCommenceDate>
    <TeachingCalendarType>SEM-1-B1</TeachingCalendarType>
    <TeachPeriodDescription>Semester 1 - Block 1</TeachPeriodDescription>