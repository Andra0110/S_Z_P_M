/**
 * @file PatientTests.cpp
 * @brief Automated unit and integration tests for the Patient module.
 */

#include <iostream>

#include "PatientTests.h"
#include "../models/Patient.h"
#include "../services/FileService.h"

/**
 * @brief Executes automated unit and integration tests for the Patient module.
 *
 * @param patientService Reference to the PatientService instance to be tested.
 */
void testPatients(
    PatientService& patientService
)
{
    std::cout << "\n=== PATIENT TESTS ===\n";

    Patient patient1(
        1,
        "Anna",
        "Kowalska",
        "12345678901"
    );

    patientService.addPatient(patient1);
    std::cout << "[TEST] Patient added to temporary session.\n";

    FileService::savePatients(
        patientService.getPatients(),
        "patients.txt"
    );
    std::cout << "[TEST] Patient data backed up to file.\n\n";

    patientService.displayPatients();

    Patient* foundPatient =
        patientService.searchPatientById(1);

    if (foundPatient != nullptr)
    {
        std::cout << "Patient found:\n";
        std::cout << foundPatient->getFirstName()
                  << " "
                  << foundPatient->getLastName()
                  << "\n";

        std::cout << "\n[TEST] Modifying patient's last name...\n";
        foundPatient->setLastName("Kowalska-Nowak");
        
        std::cout << "Updated name: " 
                  << foundPatient->getFirstName() << " " 
                  << foundPatient->getLastName() << "\n";
    }
    else
    {
        std::cout << "Patient not found.\n";
    }
    
    std::cout << std::endl;
}