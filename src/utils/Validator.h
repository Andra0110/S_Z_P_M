#include "Validator.h"
#include <cctype>

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

    for (char c : name)
    {
        // Nazwisko lub imię może zawierać litery, spacje oraz myślniki (np. Kowalska-Nowak)
        if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ' && c != '-')
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
    // Podstawowa walidacja strukturalna: PESEL musi mieć dokładnie 11 cyfr
    if (pesel.length() != 11)
    {
        return false;
    }

    for (char c : pesel)
    {
        if (!std::isdigit(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates doctor's specialization.
 *
 * @param specialization Specialization to validate.
 * @return true If specialization is valid.
 * @return false If specialization is invalid.
 */
bool Validator::isValidSpecialization(const std::string& specialization)
{
    if (specialization.empty())
    {
        return false;
    }

    for (char c : specialization)
    {
        if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ' && c != '-')
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Validates appointment date format (Expected: YYYY-MM-DD HH:MM).
 *
 * @param date Date to validate.
 * @return true If date format is valid.
 * @return false If date format is invalid.
 */
bool Validator::isValidDate(const std::string& date)
{
    // Format "YYYY-MM-DD HH:MM" ma dokładnie 16 znaków
    if (date.length() != 16)
    {
        return false;
    }

    // Sprawdzenie sztywnych separatorów formatu:
    // YYYY[4]-MM[7]-DD[10] HH[13]:MM
    if (date[4] != '-' || date[7] != '-' || date[10] != ' ' || date[13] != ':')
    {
        return false;
    }

    // Sprawdzenie czy pozostałe znaki to cyfry
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7 || i == 10 || i == 13)
        {
            continue; // Pomijamy sprawdzone już separatory
        }
        
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
        {
            return false;
        }
    }

    return true;
}