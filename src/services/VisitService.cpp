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