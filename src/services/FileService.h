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
};