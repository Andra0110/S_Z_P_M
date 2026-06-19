/**
 * @file PatientService.cpp
 * @brief Implementation of the PatientService class.
 */

#include "PatientService.h"
#include <iostream>
#include <fstream>  
#include <sstream>  

/**
 * @brief Adds a new patient to the system.
 *
 * @param patient Patient object to add.
 */
void PatientService::addPatient(const Patient& patient)
{
    patients.push_back(patient);
    saveToFile();
}

/**
 * @brief Displays all patients stored in the system.
 */
void PatientService::displayPatients() const
{
    if (patients.empty())
    {
        std::cout << "The patient registry is empty.\n";
        return;
    }

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
                  
        std::cout << std::endl;
    }
}

/**
 * @brief Searches for a patient by their ID.
 *
 * @param id Patient identifier.
 * @return Pointer to the found patient, or `nullptr` if not found.
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
 * @brief Removes a patient by their ID.
 *
 * @param id Patient identifier.
 * @retval true If the patient was successfully removed.
 * @retval false If the patient was not found.
 */
bool PatientService::removePatient(int id)
{
    for (auto it = patients.begin(); it != patients.end(); )
    {
        if (it->getId() == id)
        {
            it = patients.erase(it); 
            saveToFile();            
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

// =========================================================================
// === PERSISTENCE LAYER IMPLEMENTATION (ZAPIS / ODCZYT PLIKÓW CSV) ===
// =========================================================================

/**
 * @brief Saves all patients to a CSV file.
 */
void PatientService::saveToFile() const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cout << "[Write Error] Could not open database file: " << filename << "\n";
        return;
    }

    for (const auto& patient : patients)
    {
        file << patient.getId() << ";"
             << patient.getFirstName() << ";"
             << patient.getLastName() << ";"
             << patient.getPesel() << "\n";
    }

    file.close();
}

/**
 * @brief Loads patients from a CSV file and places them in a vector.
 */
void PatientService::loadFromFile()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return;
    }

    patients.clear(); 
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string idStr, firstName, lastName, pesel;

        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, firstName, ';') &&
            std::getline(ss, lastName, ';') &&
            std::getline(ss, pesel, ';'))
        {
            try 
            {
                int id = std::stoi(idStr);
                Patient patient(id, firstName, lastName, pesel);
                patients.push_back(patient);
            }
            catch (...) 
            {
                continue;
            }
        }
    }

    file.close();
}