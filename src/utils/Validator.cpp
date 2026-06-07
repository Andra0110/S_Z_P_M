#include "validator.h"

#include <cctype>

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
