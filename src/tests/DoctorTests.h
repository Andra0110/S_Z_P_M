#ifndef DOCTOR_TESTS_H
#define DOCTOR_TESTS_H

#include "../services/DoctorService.h"

/**
 * @brief Executes automated unit and integration tests for the Doctor module.
 *
 * This function injects mock doctor data into the provided DoctorService,
 * tests adding, displaying, searching, and safely removing doctor records,
 * verifying that the service and file persistence behave correctly.
 *
 * @param doctorService Reference to the DoctorService instance to be tested.
 */
void testDoctors(
    DoctorService& doctorService
);

#endif