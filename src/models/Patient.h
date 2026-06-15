#pragma once

#include <string>

/**
 * @class Patient
 * @brief Represents a patient in the clinic system.
 */
class Patient
{
    private:
        int id;
        std::string firstName;
        std::string lastName;
        std::string pesel;

    public:

        /**
         * @brief Constructs a new Patient object.
         * 
         * @param id Unique patient identifier.
         * @param firstName Patient first name.
         * @param lastName Patient last name.
         * @param pesel Patient PESEL number.
         */
        Patient(int id,
            const std::string& firstName,
            const std::string& lastName,
            const std::string& pesel);

        /**
         * @brief Returns patient ID.
         * 
         * @return int Patient ID.
         */
        int getId() const;

        /**
         * @brief Returns patient first name.
         * 
         * @return std::string Patient first name.
         */
        std::string getFirstName() const;

        /**
         * @brief Returns patient last name.
         * 
         * @return std::string Patient last name.
         */
        std::string getLastName() const;

        /**
         * @brief Returns patient PESEL number.
         * 
         * @return std::string Patient PESEL.
         */
        std::string getPesel() const;

        /**
         * @brief Sets a new first name for the patient.
         * * @param firstName The new first name.
         */
        void setFirstName(const std::string& firstName);

        /**
         * @brief Sets a new last name for the patient.
         * * @param lastName The new last name.
         */
        void setLastName(const std::string& lastName);

        /**
         * @brief Sets a new PESEL number for the patient.
         * * @param pesel The new PESEL number.
         */
        void setPesel(const std::string& pesel);        
};