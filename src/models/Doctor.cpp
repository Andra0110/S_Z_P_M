#include "Doctor.h"

/**
 * @brief Constructs a Doctor object.
 *
 * @param id Doctor identifier.
 * @param firstName Doctor first name.
 * @param lastName Doctor last name.
 * @param specialization Doctor specialization.
 */
Doctor::Doctor(
    int id,
    const std::string& firstName,
    const std::string& lastName,
    const std::string& specialization
)
    : id(id),
    firstName(firstName),
    lastName(lastName),
    specialization(specialization)

    {
    }

/**
 * @brief Gets doctor ID.
 *
 * @return int Doctor identifier.
 */
int Doctor::getId() const
{
    return id;
}

/**
 * @brief Gets doctor's first name.
 *
 * @return std::string First name.
 */
std::string Doctor::getFirstName() const
{
    return firstName;
} 

/**
 * @brief Gets doctor's last name.
 *
 * @return std::string Last name.
 */
std::string Doctor::getLastName() const{
    return lastName;
}

/**
 * @brief Gets doctor's specialization.
 *
 * @return std::string Specialization.
 */
std::string Doctor::getSpecialization() const
{
    return specialization;
}