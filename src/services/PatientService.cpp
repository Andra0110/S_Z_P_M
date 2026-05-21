#include "PatientService.h"
#include <iostream>

/**
 * @brief Displays all patients.
 */
void PatientService::addPatient(const Patient& patient)
{
    patients.push_back(patient);
}

void PatientService::displayPatients() const
{
    for (const auto& patient : patients)
    {
        std::cout << "ID: " 
                  << patient.getId()
                  << std::endl;

        std::cout << "First name: "
                  << patient.getFirstName()
                  << std::endl;

        std::cout << "Last name: "
                  << patient.getLastName()
                  << std::endl;

        std::cout << "PESEL: "
                  << patient.getPesel()
                  << std::endl;
    }
}