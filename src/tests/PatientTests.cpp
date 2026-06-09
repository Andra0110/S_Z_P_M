#include <iostream>

#include "PatientTests.h"
#include "../models/Patient.h"
#include "../services/FileService.h"

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

    FileService::savePatients(
        patientService.getPatients(),
        "data/patients.txt"
    );

    patientService.displayPatients();

    Patient* foundPatient =
        patientService.searchPatientById(1);

    if (foundPatient != nullptr)
    {
        std::cout << "Patient found: "
                  << std::endl;

        std::cout << foundPatient->getFirstName()
                  << " "
                  << foundPatient->getLastName()
                  << std::endl;
    }
    else
    {
        std::cout << "Patient not found."
                  << std::endl;
    }
}
