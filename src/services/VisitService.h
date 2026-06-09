#pragma once

#include <vector>
#include <string>

#include "PatientService.h"
#include "DoctorService.h"
#include "../models/Visit.h"

/**
 * @class VisitService
 * @brief Handles visit management operations.
 */
class VisitService
{
    private:
        std::vector<Visit> visits;

    public:

    /**
     * @brief Adds a new visit.
     *
     * @param visit Visit object to add.
     */
    void addVisit(const Visit& visit);

     /**
     * @brief Displays all visits.
     */
    void displayVisits() const;

    /**
     * @brief Searches visit by ID.
     *
     * @param id Visit identifier.
     * @return Visit* Pointer to found visit.
     * @return nullptr If visit was not found.
     */
    Visit* searchVisitById(int id);

    /**
     * @brief Removes visit by ID.
     *
     * @param id Visit identifier.
     * @return true If visit was removed.
     * @return false If visit was not found.
     */
    bool removeVisit(int id);

    /**
     * @brief Checks if doctor is available at given date.
     *
     * @param doctorId Doctor identifier.
     * @param date Appointment date.
     * @return true If doctor is available.
     * @return false If conflict exists.
    */
    bool isDoctorAvailable(
        int doctorId,
        const std::string& date
    ) const;

    /**
    * @brief Gets all visits.
    *
    * @return const std::vector<Visit>& List of visits.
    */
    const std::vector<Visit>& getVisits() const;

    /**
 * @brief Validates if visit can be created.
 *
 * @param patientId Patient identifier.
 * @param doctorId Doctor identifier.
 * @param patientService Patient service.
 * @param doctorService Doctor service.
 * @return true If visit is valid.
 * @return false If patient or doctor does not exist.
 */
bool canCreateVisit(
    int patientId,
    int doctorId,
    PatientService& patientService,
    DoctorService& doctorService
) const;

};