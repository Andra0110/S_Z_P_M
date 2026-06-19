/**
 * @file TestRunner.h
 * @brief Header file for the main test runner managing all subsystem tests.
 */

#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h"

/**
 * @brief Executes automated unit and integration tests for the Patient module.
 *
 * @param patientService Reference to the PatientService instance to be tested.
 */
void testPatients(
    PatientService& patientService
);

/**
 * @brief Executes automated unit and integration tests for the Doctor module.
 *
 * @param doctorService Reference to the DoctorService instance to be tested.
 */
void testDoctors(
    DoctorService& doctorService
);

/**
 * @brief Executes integration tests for the Visit module, verifying relationships 
 * between patients, doctors, and time-slot availability.
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