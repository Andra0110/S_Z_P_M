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
        Patient* PatientService::searchPatientById(int id)
        {
            for (auto& patient : patients)
            {
                if (patient.getId() == id)
                {
                    return &patient;
                }
            }

            return nullptr;
        }
};