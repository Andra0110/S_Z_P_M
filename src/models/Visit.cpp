/**
 * @file Visit.cpp
 * @brief Implementation of the Visit class.
 */

#include "Visit.h"

/**
 * @brief Constructs a Visit object.
 *
 * @param id Visit identifier.
 * @param patientId Patient identifier.
 * @param doctorId Doctor identifier.
 * @param date Appointment date.
 */
Visit::Visit(
    int id,
    int patientId,
    int doctorId,
    const std::string& date
)
    : id(id),
      patientId(patientId),
      doctorId(doctorId),
      date(date)
{
}

/**
 * @brief Gets visit ID.
 *
 * @return int Visit identifier.
 */
int Visit::getId() const
{
    return id;
}

/**
 * @brief Gets patient ID.
 *
 * @return int Patient identifier.
 */
int Visit::getPatientId() const
{
    return patientId;
}

/**
 * @brief Gets doctor ID.
 *
 * @return int Doctor identifier.
 */
int Visit::getDoctorId() const
{
    return doctorId;
}

/**
 * @brief Gets date.
 *
 * @return std::string Appointment date.
 */
std::string Visit::getDate() const
{
    return date;
}

/**
 * @brief Sets a new appointment date.
 *
 * @param newDate The new date string to set for the visit.
 */
void Visit::setDate(const std::string& newDate)
{
    this->date = newDate;
}