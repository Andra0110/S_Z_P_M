#include "VisitService.h"

#include <iostream>

/**
 * @brief Adds a new visit.
 */
void VisitService::addVisit(const Visit& visit)
{
    visits.push_back(visit);
}

/**
 * @brief Displays all visits.
 */
void VisitService::displayVisits() const
{
    for (const auto& visit : visits)
    {
        std::cout << "Visit ID: "
                  << visit.getId()
                  << std::endl;

        std::cout << "Patient ID: "
                  << visit.getPatientId()
                  << std::endl;

        std::cout << "Doctor ID: "
                  << visit.getDoctorId()
                  << std::endl;

        std::cout << "Date: "
                  << visit.getDate()
                  << std::endl;
    }
}

/**
 * @brief Displays all visits.
 */
Visit* VisitService::searchVisitById(int id)
{
    for (auto& visit : visits)
    {
        if (visit.getId() == id)
        {
            return &visit;
        }
    }
    return nullptr;
}

/**
 * @brief Removes visit by ID.
 */
bool VisitService::removeVisit(int id)
{
    for (auto it = visits.begin(); it != visits.end(); ++it)
    {
        if (it->getId() == id)
        {
            visits.erase(it);
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if doctor is available at given date.
 *
 * @param doctorId Doctor identifier.
 * @param date Appointment date.
 * @return true If doctor is available.
 * @return false If conflict exists.
 */
bool VisitService::isDoctorAvailable(
    int doctorId,
    const std::string& date
) const
{
    for (const auto& visit : visits)
    {
        if (
        visit.getDoctorId() == doctorId &&
        visit.getDate() == date
        )
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Gets all visits.
 *
 * @return const std::vector<Visit>& List of visits.
 */
const std::vector<Visit>& VisitService::getVisits() const{
    return visits;
}

bool VisitService::canCreateVisit(
    int patientId,
    int doctorId,
    PatientService& patientService,
    DoctorService& doctorService
) const
{
    if (
        patientService.searchPatientById(patientId)
        == nullptr
    )
    {
        return false;
    }

    if (
        doctorService.searchDoctorById(doctorId)
        == nullptr
    )
    {
        return false;
    }

    return true;
}

/**
 * @brief Displays all visits for a patient.
 */
void VisitService::displayVisitsByPatient(
    int patientId
) const
{
    for (const auto& visit : visits)
    {
        if (visit.getPatientId() == patientId)
        {
            std::cout << "Visit ID: "
                      << visit.getId()
                      << std::endl;

            std::cout << "Doctor ID: "
                      << visit.getDoctorId()
                      << std::endl;

            std::cout << "Date: "
                      << visit.getDate()
                      << std::endl;

            std::cout << std::endl;
        }
    }
}

/**
 * @brief Displays all visits for a doctor.
 */
void VisitService::displayVisitsByDoctor(
    int doctorId
) const
{
    for (const auto& visit : visits)
    {
        if (visit.getDoctorId() == doctorId)
        {
            std::cout << "Visit ID: "
                      << visit.getId()
                      << std::endl;

            std::cout << "Patient ID: "
                      << visit.getPatientId()
                      << std::endl;

            std::cout << "Date: "
                      << visit.getDate()
                      << std::endl;

            std::cout << std::endl;
        }
    }
}

