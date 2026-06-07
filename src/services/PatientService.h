#pragma once

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

    public:

    
        /**
         * @brief Adds a new patient to the system.
        * 
         * @param patient Patient object to add.
         */
        void addPatient(const Patient& patient);

            /**
        * @brief Displays all patients stored in the system.
        * 
         * This method prints patient information
        * to the console.
        */ 
        void displayPatients() const;

        /**
         * @brief Searches patient by ID.
         * 
         * @param id Patient identifier.
         * @return Patient* Pointer to patient object.
         * @return nullptr If patient does not exist.
         */
        Patient* searchPatientById(int id);


        /**
         * @brief Removes patient by ID.
         *
         * @param id Patient identifier.
         * @return true If patient was removed.
         * @return false If patient was not found.
         */
        bool removePatient(int id);

        /**
        * @brief Gets all patients.
        *
        * @return const std::vector<Patient>& List of patients.
        */
       const std::vector<Patient>& getPatients() const;
     
     };