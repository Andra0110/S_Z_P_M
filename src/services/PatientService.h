/**
 * @file PatientService.h
 * @brief Header file for the PatientService class.
 */

#ifndef PATIENTSERVICE_H
#define PATIENTSERVICE_H

#pragma once

#include <string>
#include <vector>

#include "../models/Patient.h"

/**
 * @class PatientService
 * @brief Handles patient management operations.
 */
class PatientService
{
    private:
        std::vector<Patient> patients;
        const std::string filename = "patients.csv";

    public:
        /**
         * @brief Adds a new patient to the system.
         * * @param patient Patient object to add.
         */
        void addPatient(const Patient& patient);

        /**
         * @brief Displays all patients stored in the system.
         * * This method prints formatted patient information directly to the console.
         */ 
        void displayPatients() const;

        /**
         * @brief Searches for a patient by their ID.
         * * @param id Patient identifier.
         * @return Pointer to the found patient, or `nullptr` if the patient does not exist.
         */
        Patient* searchPatientById(int id);

        /**
         * @brief Removes a patient by their ID.
         *
         * @param id Patient identifier.
         * @retval true If the patient was successfully removed.
         * @retval false If the patient was not found.
         */
        bool removePatient(int id);

        /**
         * @brief Gets all patients.
         *
         * @return const std::vector<Patient>& List of patients.
         */
        const std::vector<Patient>& getPatients() const;

        /**
         * @brief Loads patients from a CSV file.
         */
        void loadFromFile();

        /**
         * @brief Saves all patients to a CSV file.
         */
        void saveToFile() const;
};

#endif