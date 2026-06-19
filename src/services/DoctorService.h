/**
 * @file DoctorService.h
 * @brief Header file for the DoctorService class.
 */

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
         * @brief Searches for a doctor by their ID.
         *
         * @param id Doctor identifier.
         * @return Pointer to the found doctor, or `nullptr` if not found.
         */
        Doctor* searchDoctorById(int id);

        /**
         * @brief Removes a doctor by their ID.
         *
         * @param id Doctor identifier.
         * @retval true If the doctor was successfully removed.
         * @retval false If the doctor was not found.
         */
        bool removeDoctor(int id);

        /**
         * @brief Gets all doctors.
         *
         * @return const std::vector<Doctor>& List of doctors.
         */
        const std::vector<Doctor>& getDoctors() const;

        /**
         * @brief Loads doctors from a CSV file.
         */
        void loadFromFile();

        /**
         * @brief Saves all doctors to a CSV file.
         */    
        void saveToFile() const;
};