#include "Validator.h"

#include <cctype>
#include <regex>

/**
 * @brief Validates patient's first or last name.
 *
 * @param name Name to validate.
 * @return true If name is valid.
 * @return false If name is invalid.
 */
bool Validator::isValidName(const std::string& name)
{
    if (name.empty())
    {
        return false;
    }

    for (char character : name)
    {
        // Zapewniamy bezpieczne rzutowanie oraz dopuszczamy spacje i myślniki (przydatne przy nazwiskach)
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
 * @param pesel PESEL to validate.
 * @return true If PESEL is valid.
 * @return false If PESEL is invalid.
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
 * @param specialization Doctor specialization.
 * @return true If specialization is valid.
 * @return false If specialization is invalid.
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
 * @param date Date to validate.
 * @return true If date format matches YYYY-MM-DD HH:MM.
 * @return false If date format is invalid.
 */
bool Validator::isValidDate(const std::string& date)
{
    // Wyrażenie regularne doskonale pilnuje układu cyfr i separatorów
    std::regex pattern(
        R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2})"
    );

    return std::regex_match(date, pattern);
}
