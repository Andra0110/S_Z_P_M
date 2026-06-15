#include "Visit.h"

/**
 * @brief Constructs a Visit object.
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
 * @return int patient identifier.
 */
int Visit::getPatientId() const
{
    return patientId;
}

/**
 * @brief Gets doctor ID.
 *
 * @return int doctor identifier.
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