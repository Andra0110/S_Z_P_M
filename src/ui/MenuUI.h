#ifndef MENU_UI_H
#define MENU_UI_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h"

/**
 * @class MenuUI
 * @brief Handles the Command Line Interface (CLI) menus for the application.
 */
class MenuUI
{
public:
    /**
     * @brief Starts the main application loop and displays the primary menu.
     * * @param patients Active PatientService instance.
     * @param doctors Active DoctorService instance.
     * @param visits Active VisitService instance.
     */
    static void run(
        PatientService& patients,
        DoctorService& doctors,
        VisitService& visits
    );

private:
    // Tutaj w przyszłości dodamy prywatne metody pomocnicze dla podmenu, np.:
    // static void handlePatientMenu(PatientService& patients);
    // static void handleDoctorMenu(DoctorService& doctors);
    // static void handleVisitMenu(VisitService& visits, PatientService& patients, DoctorService& doctors);
};

#endif