#ifndef PATIENT_TESTS_H
#define PATIENT_TESTS_H

#include "../services/PatientService.h"

/**
 * @brief Executes automated unit and integration tests for the Patient module.
 *
 * This function injects mock patient data into the provided PatientService, 
 * tests adding, displaying, searching, and safely removing patient records, 
 * verifying that the underlying container behaves as expected.
 *
 * @param patientService Reference to the PatientService instance to be tested.
 */
void testPatients(
    PatientService& patientService
);

#endif