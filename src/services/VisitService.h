#pragma once

#include <vector>
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

};