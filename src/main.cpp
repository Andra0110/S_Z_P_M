#include "tests/PatientTests.h"
#include "tests/DoctorTests.h"
#include "tests/VisitTests.h"

int main()
{
    PatientService patientService;
    DoctorService doctorService;
    VisitService visitService;

    testPatients(patientService);
    testDoctors(doctorService);
    testVisits(
        patientService,
        doctorService,
        visitService
    );

    return 0;
}


