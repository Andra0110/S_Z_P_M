/**
 * @file FileService.h
 * @brief Header file for the FileService class.
 */

#pragma once

#include <string>
#include <vector>

#include "../models/Patient.h"
#include "../models/Doctor.h"
#include "../models/Visit.h"

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

        /**
         * @brief Saves doctors to a text file.
         *
         * @param doctors Vector of doctors.
         * @param filename Output file name.
         */
        static void saveDoctors(
            const std::vector<Doctor>& doctors,
            const std::string& filename
        );

        /**
         * @brief Loads doctors from a text file.
         *
         * @param filename Input file name.
         * @return std::vector<Doctor> Loaded doctors.
         */
        static std::vector<Doctor> loadDoctors(
            const std::string& filename
        );
        
        /**
         * @brief Saves visits to a text file.
         *
         * @param visits Vector of visits.
         * @param filename Output file name.
         */
        static void saveVisits(
            const std::vector<Visit>& visits,
            const std::string& filename
        );

        /**
         * @brief Loads visits from a text file.
         *
         * @param filename Input file name.
         * @return std::vector<Visit> Loaded visits.
         */
        static std::vector<Visit> loadVisits(
            const std::string& filename
        );
};