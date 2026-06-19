/**
 * @file Visit.h
 * @brief Header file for the Visit class.
 */

#pragma once

#include <string>

/**
 * @class Visit
 * @brief Represents a medical appointment.
 */
class Visit
{
    private:
        int id;
        int patientId;
        int doctorId;
        std::string date;

    public:
        /**
         * @brief Constructs a Visit object.
         *
         * @param id Visit identifier.
         * @param patientId Patient identifier.
         * @param doctorId Doctor identifier.
         * @param date Appointment date.
         */
        Visit(
            int id,
            int patientId,
            int doctorId,
            const std::string& date
        );

        /**
         * @brief Gets visit ID.
         *
         * @return int Visit identifier.
         */
        int getId() const;

        /**
         * @brief Gets patient ID.
         *
         * @return int Patient identifier.
         */
        int getPatientId() const;

        /**
         * @brief Gets doctor ID.
         *
         * @return int Doctor identifier.
         */
        int getDoctorId() const;

        /**
         * @brief Gets appointment date.
         *
         * @return std::string Appointment date.
         */
        std::string getDate() const;

        /**
         * @brief Sets a new appointment date.
         *
         * @param newDate The new date string to set for the visit.
         */
        void setDate(const std::string& newDate);    
};