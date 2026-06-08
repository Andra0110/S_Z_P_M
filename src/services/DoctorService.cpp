#include "DoctorService.h"
#include <iostream>

/**
 * @brief Adds a new doctor to the system.
 */
void DoctorService::addDoctor(const Doctor& doctor)
{
    doctors.push_back(doctor);
}

/**
 * @brief Displays all doctors.
 */
void DoctorService::displayDoctors() const
{
    for (const auto& doctor : doctors)
    {
        std::cout << "ID: "
                  << doctor.getId()
                  << std::endl;

        std::cout << "First Name: "
                  << doctor.getFirstName()
                  << std::endl;

        std::cout << "Last Name: "
                  << doctor.getLastName()
                  << std::endl;

        std::cout << "Specialization: "
                  << doctor.getSpecialization()
                  << std::endl;
        
    }
}

/**
 * @brief Searches doctor by ID.
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
 * @brief Removes doctor by ID.
 */
bool DoctorService::removeDoctor(int id)
{
    for (auto it = doctors.begin(); it != doctors.end(); ++it)
    {
        if (it->getId() == id)
        {
            doctors.erase(it);
            return true;
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