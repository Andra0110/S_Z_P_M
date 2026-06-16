#include "VisitService.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Adds a new visit if the doctor is available.
 *
 * @param visit Visit object to add.
 */
void VisitService::addVisit(const Visit& visit)
{
    if (isDoctorAvailable(visit.getDoctorId(), visit.getDate()))
    {
        visits.push_back(visit);
        std::cout << "[Sukces] Wizyta o ID " << visit.getId() << " zostala dodana.\n";
    }
    else
    {
        std::cout << "[Blad] Lekarz o ID " << visit.getDoctorId() 
                  << " ma juz zajety termin: " << visit.getDate() << "\n";
    }
}

/**
 * @brief Displays all visits registered in the system.
 */
void VisitService::displayVisits() const
{
    if (visits.empty())
    {
        std::cout << "Terminarz jest pusty. Brak zaplanowanych wizyt.\n";
        return;
    }

    std::cout << "\n=== GLOWNY TERMINARZ WIZYT ===\n";
    for (const auto& visit : visits)
    {
        std::cout << "Wizyta ID: " << visit.getId()
                  << " | Pacjent ID: " << visit.getPatientId()
                  << " | Lekarz ID: " << visit.getDoctorId()
                  << " | Data: " << visit.getDate() << "\n";
    }
}

/**
 * @brief Searches for a visit by its unique identifier.
 *
 * @param id Visit identifier.
 * @return Visit* Pointer to found visit, or nullptr if not found.
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
 * @brief Removes a visit from the calendar by its ID.
 *
 * @param id Visit identifier.
 * @return true If the visit was successfully removed.
 * @return false If the visit was not found.
 */
bool VisitService::removeVisit(int id)
{
    for (auto it = visits.begin(); it != visits.end(); ++it)
    {
        if (it->getId() == id)
        {
            visits.erase(it);
            std::cout << "[Sukces] Wizyta o ID " << id << " zostala anulowana.\n";
            return true;
        }
    }
    std::cout << "[Blad] Nie znaleziono wizyty o ID " << id << ".\n";
    return false;
}

/**
 * @brief Checks if a doctor is free at a specific date and time.
 *
 * @param doctorId Doctor identifier.
 * @param date The date and time string to check.
 * @return true If the doctor has no other appointments at that time.
 * @return false If there is a scheduling conflict.
 */
bool VisitService::isDoctorAvailable(int doctorId, const std::string& date) const
{
    for (const auto& visit : visits)
    {
        if (visit.getDoctorId() == doctorId && visit.getDate() == date)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Returns a reference to the entire list of visits.
 *
 * @return const std::vector<Visit>& Vector of visits.
 */
const std::vector<Visit>& VisitService::getVisits() const
{
    return visits;
}

/**
 * @brief Validates if the internal accounts exist before scheduling.
 *
 * @param patientId Patient identifier.
 * @param doctorId Doctor identifier.
 * @param patientService Reference to Patient Service for validation.
 * @param doctorService Reference to Doctor Service for validation.
 * @return true If both patient and doctor exist.
 * @return false If either the patient or doctor cannot be found.
 */
bool VisitService::canCreateVisit(
    int patientId,
    int doctorId,
    PatientService& patientService,
    DoctorService& doctorService
) const
{
    if (patientService.searchPatientById(patientId) == nullptr)
    {
        std::cout << "[Blad] Pacjent o ID " << patientId << " nie istnieje.\n";
        return false;
    }
    if (doctorService.searchDoctorById(doctorId) == nullptr)
    {
        std::cout << "[Blad] Lekarz o ID " << doctorId << " nie istnieje.\n";
        return false;
    }
    return true;
}

/**
 * @brief Filters and displays the schedule for a single patient.
 *
 * @param patientId Patient identifier.
 */
void VisitService::displayVisitsByPatient(int patientId) const
{
    std::cout << "\n--- Wizyty pacjenta o ID: " << patientId << " ---\n";
    bool hasVisits = false;
    for (const auto& visit : visits)
    {
        if (visit.getPatientId() == patientId)
        {
            std::cout << "Wizyta ID: " << visit.getId()
                      << " | Lekarz ID: " << visit.getDoctorId()
                      << " | Data: " << visit.getDate() << "\n";
            hasVisits = true;
        }
    }
    if (!hasVisits)
    {
        std::cout << "Brak zaplanowanych wizyt dla tego pacjenta.\n";
    }
}

/**
 * @brief Filters and displays the schedule for a single doctor.
 *
 * @param doctorId Doctor identifier.
 */
void VisitService::displayVisitsByDoctor(int doctorId) const
{
    std::cout << "\n--- Harmonogram lekarza o ID: " << doctorId << " ---\n";
    bool hasVisits = false;
    for (const auto& visit : visits)
    {
        if (visit.getDoctorId() == doctorId)
        {
            std::cout << "Wizyta ID: " << visit.getId()
                      << " | Pacjent ID: " << visit.getPatientId()
                      << " | Data: " << visit.getDate() << "\n";
            hasVisits = true;
        }
    }
    if (!hasVisits)
    {
        std::cout << "Lekarz nie ma zaplanowanych wizyt.\n";
    }
}