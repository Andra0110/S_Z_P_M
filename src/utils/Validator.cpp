#include "validator.h"

#include <cctype>
#include <regex>

/**
 * @brief Validates patient's name.
 */
bool Validator::isValidName(const std::string& name)
{
    if (name.empty())
    {
        return false;
    }

    for (char character : name)
    {
        if (!std::isalpha(character))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates PESEL number.
 */
bool Validator::isValidPesel(const std::string& pesel)
{
    if (pesel.length() != 11)
    {
        return false;
    }

    for (char character : pesel)
    {
        if (!std::isdigit(character))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates doctor's specialization.
 *
 * @param specialization Doctor specialization.
 * @return true If specialization is valid.
 * @return false If specialization is invalid.
 */
bool Validator::isValidSpecialization(const std::string& specialization)
    {
        return !specialization.empty();
    }

/**
 * @brief Validates appointment date format.
 *
 * @param date Date to validate.
 * @return true If date format is valid.
 * @return false If date format is invalid.
 */
bool Validator::isValidDate(const std::string& date)
{
    std::regex pattern(
        R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2})"
    );

    return std::regex_match(date, pattern);
}
