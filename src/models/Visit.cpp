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

int Visit::getId() const
{
    return id;
}

int Visit::getPatientId() const
{
    return patientId;
}

int Visit::getDoctorId() const
{
    return doctorId;
}

std::string Visit::getDate() const
{
    return date;
}