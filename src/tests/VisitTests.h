#ifndef VISIT_TESTS_H
#define VISIT_TESTS_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h"

void testVisits(
    PatientService& patientService,
    DoctorService& doctorService,
    VisitService& visitService
);

#endif