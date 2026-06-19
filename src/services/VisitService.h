/**
 * @file VisitService.h
 * @brief Header file for the VisitService class.
 */

#pragma once

#include <vector>
#include <string>

#include "PatientService.h"
#include "DoctorService.h"
#include "../models/Visit.h"

/**
 * @class VisitService
 * @brief Handles visit management operations.
 */
class VisitService
{
    private:
        std::vector<Visit> visits;
        const std::string filename = "visits.csv";

    public:
        /**
         * @brief Adds a new visit if the doctor is available.
         *
         * @param visit Visit object to add.
         */
        void addVisit(const Visit& visit);

        /**
         * @brief Displays all visits registered in the system.
         */
        void displayVisits() const;

        /**
         * @brief Searches for a visit by its unique identifier.
         *
         * @param id Visit identifier.
         * @return Pointer to the found visit, or `nullptr` if not found.
         */
        Visit* searchVisitById(int id);

        /**
         * @brief Removes a visit from the calendar by its ID.
         *
         * @param id Visit identifier.
         * @retval true If the visit was successfully removed.
         * @retval false If the visit was not found.
         */
        bool removeVisit(int id);

        /**
         * @brief Checks if a doctor is free at a specific date and time.
         *
         * @param doctorId Doctor identifier.
         * @param date Appointment date.
         * @retval true If the doctor has no other appointments at that time.
         * @retval false If there is a scheduling conflict.
         */
        bool isDoctorAvailable(
            int doctorId,
            const std::string& date
        ) const;

        /**
         * @brief Returns a reference to the entire list of visits.
         *
         * @return const std::vector<Visit>& Vector of visits.
         */
        const std::vector<Visit>& getVisits() const;

        /**
         * @brief Validates if the internal accounts exist before scheduling.
         *
         * @param patientId Patient identifier.
         * @param doctorId Doctor identifier.
         * @param patientService Reference to Patient Service for validation.
         * @param doctorService Reference to Doctor Service for validation.
         * @retval true If both patient and doctor exist.
         * @retval false If either the patient or doctor cannot be found.
         */
        bool canCreateVisit(
            int patientId,
            int doctorId,
            PatientService& patientService,
            DoctorService& doctorService
        ) const;

        /**
         * @brief Filters and displays the schedule for a single patient.
         *
         * @param patientId Patient identifier.
         */
        void displayVisitsByPatient(
            int patientId
        ) const;

        /**
         * @brief Filters and displays the schedule for a single doctor.
         *
         * @param doctorId Doctor identifier.
         */
        void displayVisitsByDoctor(
            int doctorId
        ) const;

        /**
         * @brief Loads visits from a CSV file.
         */
        void loadFromFile();

        /**
         * @brief Saves all visits to a CSV file.
         */
        void saveToFile() const;
};