/**
 * @file DoctorService.cpp
 * @brief Implementation of the DoctorService class.
 */

#include "DoctorService.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Adds a new doctor to the system.
 *
 * @param doctor Doctor object to add.
 */
void DoctorService::addDoctor(const Doctor& doctor)
{
    doctors.push_back(doctor);
    saveToFile(); 
}

/**
 * @brief Displays all doctors stored in the system.
 */
void DoctorService::displayDoctors() const
{
    for (const auto& doctor : doctors)
    {
        std::cout << "ID: "
                  << doctor.getId()
                  << "\n";

        std::cout << "First Name: "
                  << doctor.getFirstName()
                  << "\n";

        std::cout << "Last Name: "
                  << doctor.getLastName()
                  << "\n";

        std::cout << "Specialization: "
                  << doctor.getSpecialization()
                  << "\n";
                  
        std::cout << std::endl; 
    }
}

/**
 * @brief Searches for a doctor by their ID.
 *
 * @param id Doctor identifier.
 * @return Pointer to the found doctor, or `nullptr` if not found.
 */
Doctor* DoctorService::searchDoctorById(int id)
{
    for (auto& doctor : doctors)
    {
        if (doctor.getId() == id)
        {
            return &doctor;
        }
    }

    return nullptr;
}

/**
 * @brief Removes a doctor by their ID.
 *
 * @param id Doctor identifier.
 * @retval true If the doctor was successfully removed.
 * @retval false If the doctor was not found.
 */
bool DoctorService::removeDoctor(int id)
{
    for (auto it = doctors.begin(); it != doctors.end(); )
    {
        if (it->getId() == id)
        {
            it = doctors.erase(it);
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
 * @brief Gets all doctors.
 *
 * @return const std::vector<Doctor>& List of doctors.
 */
const std::vector<Doctor>& DoctorService::getDoctors() const
{
    return doctors;
}

/**
 * @brief Saves all doctors to a CSV file.
 */
void DoctorService::saveToFile() const
{
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& doctor : doctors)
    {
        file << doctor.getId() << ";"
             << doctor.getFirstName() << ";"
             << doctor.getLastName() << ";"
             << doctor.getSpecialization() << "\n";
    }
    file.close();
}

/**
 * @brief Loads doctors from a CSV file.
 */
void DoctorService::loadFromFile()
{
    std::ifstream file(filename);
    if (!file.is_open()) return;

    doctors.clear();
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string idStr, firstName, lastName, specialization;

        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, firstName, ';') &&
            std::getline(ss, lastName, ';') &&
            std::getline(ss, specialization, ';'))
        {
            try {
                int id = std::stoi(idStr);
                Doctor doctor(id, firstName, lastName, specialization);
                doctors.push_back(doctor);
            }
            catch (...) {
                continue;
            }
        }
    }
    file.close();
}