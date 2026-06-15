#include "DoctorService.h"
#include <iostream>

/**
 * @brief Adds a new doctor to the system.
 *
 * @param doctor Doctor object to add.
 */
void DoctorService::addDoctor(const Doctor& doctor)
{
    doctors.push_back(doctor);
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
                  
        std::cout << std::endl; // Pusta linia odstępu między lekarzami
    }
}

/**
 * @brief Searches doctor by ID.
 *
 * @param id Doctor identifier.
 * @return Doctor* Pointer to found doctor.
 * @return nullptr If doctor was not found.
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
 *
 * @param id Doctor identifier.
 * @return true If doctor was removed.
 * @return false If doctor was not found.
 */
bool DoctorService::removeDoctor(int id)
{
    for (auto it = doctors.begin(); it != doctors.end(); )
    {
        if (it->getId() == id)
        {
            it = doctors.erase(it); // Bezpieczne usunięcie elementu bez unieważniania iteratora
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