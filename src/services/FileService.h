#pragma once

#include <string>
#include <vector>

#include "../models/Patient.h"

/**
 * @class FileService
 * @brief Handles saving and loading data from files.
 */
class FileService
{
    public:

    /**
     * @brief Saves patients to a text file.
     *
     * @param patients Vector of patients.
     * @param filename Output file name.
     */
    static void savePatients(
        const std::vector<Patient>& patients,
        const std::string& filename
    );

    /**
     * @brief Loads patients from a text file.
    *
     * @param filename Input file name.
    * @return std::vector<Patient> Loaded patients.
    */
    static std::vector<Patient> loadPatients(
        const std::string& filename
    );
};