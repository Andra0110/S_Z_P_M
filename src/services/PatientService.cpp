#include "PatientService.h"
#include <iostream>

/**
 * @brief Adds a new patient to the system.
 *
 * @param patient Patient object to add.
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

Patient* PatientService::searchPatientById(int id)
{
    for (auto& patient : patients)
    {
        if (patient.getId() == id)
        {
            return &patient;
        }
    }

    return nullptr;
}