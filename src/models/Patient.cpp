#include "Patient.h"

/**
 * @brief Constructs a new Patient object.
 * * @param id Unique patient identifier.
 * @param firstName Patient first name.
 * @param lastName Patient last name.
 * @param pesel Patient PESEL number.
 */
Patient::Patient(int id,
            const std::string& firstName,
            const std::string& lastName,
            const std::string& pesel)

        : id(id),
            firstName(firstName),
            lastName(lastName),
            pesel(pesel)

{
}

/**
 * @brief Returns patient ID.
 * * @return int Patient ID.
 */
int Patient::getId() const
{
    return id;
}

/**
 * @brief Returns patient first name.
 * * @return std::string Patient first name.
 */
std::string Patient::getFirstName() const
{
    return firstName;
}

/**
 * @brief Returns patient last name.
 * * @return std::string Patient last name.
 */
std::string Patient::getLastName() const
{
    return lastName;
}

/**
 * @brief Returns patient PESEL number.
 * * @return std::string Patient PESEL.
 */
std::string Patient::getPesel() const
{
    return pesel;
}

/**
 * @brief Sets a new first name for the patient.
 * * @param firstName The new first name.
 */
void Patient::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

/**
 * @brief Sets a new last name for the patient.
 * * @param lastName The new last name.
 */
void Patient::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

/**
 * @brief Sets a new PESEL number for the patient.
 * * @param pesel The new PESEL number.
 */
void Patient::setPesel(const std::string& pesel)
{
    this->pesel = pesel;
}