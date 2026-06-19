/**
 * @file VisitTests.h
 * @brief Header file for the Visit module integration tests.
 */

#ifndef VISIT_TESTS_H
#define VISIT_TESTS_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h"

/**
 * @brief Executes integration tests for the Visit module.
 *
 * This function verifies the core business logic of scheduling visits, including
 * checking patient and doctor existence, validating time-slot availability, and
 * testing the serialization/deserialization of visit records.
 *
 * @param patientService Reference to the active PatientService.
 * @param doctorService Reference to the active DoctorService.
 * @param visitService Reference to the VisitService instance to be tested.
 */
void testVisits(
    PatientService& patientService,
    DoctorService& doctorService,
    VisitService& visitService
);

#endif