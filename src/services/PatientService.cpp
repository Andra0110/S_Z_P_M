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

/**
 * @brief Displays all patients stored in the system.
 */
void PatientService::displayPatients() const
{
    for (const auto& patient : patients)
    {
        std::cout << "ID: " 
                  << patient.getId()
                  << "\n";

        std::cout << "First name: "
                  << patient.getFirstName()
                  << "\n";

        std::cout << "Last name: "
                  << patient.getLastName()
                  << "\n";

        std::cout << "PESEL: "
                  << patient.getPesel()
                  << "\n";
                  
        std::cout << std::endl; // Pusta linia odstępu między pacjentami
    }
}

/**
 * @brief Searches patient by ID.
 *
 * @param id Patient identifier.
 * @return Patient* Pointer to found patient.
 * @return nullptr If patient was not found.
 */
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

/**
 * @brief Removes patient by ID.
 *
 * @param id Patient identifier.
 * @return true If patient was removed.
 * @return false If patient was not found.
 */
bool PatientService::removePatient(int id)
{
    for (auto it = patients.begin(); it != patients.end(); )
    {
        if (it->getId() == id)
        {
            it = patients.erase(it); // Bezpieczne usunięcie elementu z wektora
            return true;
        }
        else
        {
            ++it;
        }
    }

    return false;
}

/**
 * @brief Gets all patients.
 *
 * @return const std::vector<Patient>& List of patients.
 */
const std::vector<Patient>& PatientService::getPatients() const
{
    return patients;
}