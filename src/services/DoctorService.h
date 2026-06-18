#pragma once

#include <vector>
#include "../models/Doctor.h"

/**
 * @class DoctorService
 * @brief Handles doctor management operations.
 */
class DoctorService
{
    private:
        std::vector<Doctor> doctors;
        const std::string filename = "doctors.csv";
    
    public:

     /**
     * @brief Adds a new doctor to the system.
     *
     * @param doctor Doctor object to add.
     */
    void addDoctor(const Doctor& doctor);
    
    /**
     * @brief Displays all doctors stored in the system.
     */
    void displayDoctors() const;

     /**
     * @brief Searches doctor by ID.
     *
     * @param id Doctor identifier.
     * @return Doctor* Pointer to found doctor.
     * @return nullptr If doctor was not found.
     */
    Doctor* searchDoctorById(int id);

    /**
     * @brief Removes doctor by ID.
     *
     * @param id Doctor identifier.
     * @return true If doctor was removed.
     * @return false If doctor was not found.
     */
    bool removeDoctor(int id);

    /**
    * @brief Gets all doctors.
    *
    * @return const std::vector<Doctor>& List of doctors.
    */
    const std::vector<Doctor>& getDoctors() const;

    void loadFromFile();
    void saveToFile() const;
};