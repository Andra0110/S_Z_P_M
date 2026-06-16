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
     * @return true If name is valid.
     * @return false If name is invalid.
     */
    static bool isValidName(const std::string& name);

    /**
     * @brief Validates PESEL number.
     *
     * @param pesel PESEL to validate.
     * @return true If PESEL is valid.
     * @return false If PESEL is invalid.
     */
    static bool isValidPesel(const std::string& pesel);


    /**
    * @brief Validates doctor's specialization.
     *
     * @param specialization Specialization to validate.
     * @return true If specialization is valid.
     * @return false If specialization is invalid.
     */
    static bool isValidSpecialization(const std::string& specialization);

    /**
     * @brief Validates appointment date format.
    *
    * @param date Date to validate.
    * @return true If date format is valid.
    * @return false If date format is invalid.
    */
    static bool isValidDate(const std::string& date);

};