/**
 * @file Validator.h
 * @brief Header file for the Validator class providing static input validation utilities.
 */

#pragma once

#include <string>

/**
 * @class Validator
 * @brief Provides validation methods for user input.
 */
class Validator
{
    public:
        /**
         * @brief Validates patient's first or last name.
         *
         * @param name Name to validate.
         * @retval true If the name contains only alphabetic characters, spaces, or hyphens.
         * @retval false If the name is empty or contains invalid characters.
         */
        static bool isValidName(const std::string& name);

        /**
         * @brief Validates PESEL number.
         *
         * @param pesel PESEL to validate.
         * @retval true If the PESEL consists of exactly 11 digits.
         * @retval false If the length is incorrect or non-digit characters are found.
         */
        static bool isValidPesel(const std::string& pesel);

        /**
         * @brief Validates doctor's specialization.
         *
         * @param specialization Specialization to validate.
         * @retval true If the specialization contains only alphabetic characters, spaces, or hyphens.
         * @retval false If the string is empty or contains invalid characters.
         */
        static bool isValidSpecialization(const std::string& specialization);

        /**
         * @brief Validates appointment date format.
         *
         * @param date Date to validate.
         * @retval true If the date format matches the explicit pattern YYYY-MM-DD HH:MM.
         * @retval false If the date format is invalid or does not match the regex.
         */
        static bool isValidDate(const std::string& date);
};