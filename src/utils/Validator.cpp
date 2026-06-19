/**
 * @file Validator.cpp
 * @brief Implementation of utility functions for input validation.
 */

#include "Validator.h"

#include <cctype>
#include <regex>

/**
 * @brief Validates patient's first or last name.
 *
 * @param name Name to validate.
 * @retval true If the name contains only alphabetic characters, spaces, or hyphens.
 * @retval false If the name is empty or contains invalid characters.
 */
bool Validator::isValidName(const std::string& name)
{
    if (name.empty())
    {
        return false;
    }

    for (char character : name)
    {
        if (!std::isalpha(static_cast<unsigned char>(character)) && character != ' ' && character != '-')
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates PESEL number.
 *
 * @param pesel PESEL string to validate.
 * @retval true If the PESEL consists of exactly 11 digits.
 * @retval false If the length is incorrect or non-digit characters are found.
 */
bool Validator::isValidPesel(const std::string& pesel)
{
    if (pesel.length() != 11)
    {
        return false;
    }

    for (char character : pesel)
    {
        if (!std::isdigit(static_cast<unsigned char>(character)))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates doctor's specialization.
 *
 * @param specialization Doctor specialization string to validate.
 * @retval true If the specialization contains only alphabetic characters, spaces, or hyphens.
 * @retval false If the string is empty or contains invalid characters.
 */
bool Validator::isValidSpecialization(const std::string& specialization)
{
    if (specialization.empty())
    {
        return false;
    }

    for (char character : specialization)
    {
        if (!std::isalpha(static_cast<unsigned char>(character)) && character != ' ' && character != '-')
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates appointment date format.
 *
 * @param date Date string to validate.
 * @retval true If the date format matches the explicit pattern YYYY-MM-DD HH:MM.
 * @retval false If the date format is invalid or does not match the regex.
 */
bool Validator::isValidDate(const std::string& date)
{
    std::regex pattern(
        R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2})"
    );

    return std::regex_match(date, pattern);
}