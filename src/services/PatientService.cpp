#include "PatientService.h"
#include <iostream>

void PatientService::addPatient(const Patient& patient)
{
    patients.push_back(patient);
}

void PatientService::displayPatients() const
{
    for (const auto& patient : patients)
    {
        std::cout << patient.getId() << " "
                  << patient.getFirstName() << " "
                  << patient.getLastName() << std::endl;
    }
}