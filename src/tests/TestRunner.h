#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h"

void testPatients(
    PatientService& patientService
);

void testDoctors(
    DoctorService& doctorService
);

void testVisits(
    PatientService& patientService,
    DoctorService& doctorService,
    VisitService& visitService
);

#endif