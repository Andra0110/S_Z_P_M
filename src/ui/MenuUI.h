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
    
};

#ifndef MENU_UI_H
#define MENU_UI_H

#include "../services/PatientService.h"
#include "../services/Validator.h"
#include <iostream>
#include <string>
#include <limits>

/**
 * @class MenuUI
 * @brief Class managing the Command Line Interface (CLI) of the application.
 */
class MenuUI {
private:
    PatientService& patientService; 

    void handlePatientMenu();
    void displayPatientMenu() const;
    void addNewPatient();
    void displayAllPatients() const;
    void searchPatient() const;
    void updatePatient();
    void deletePatient();

    void clearInputBuffer() const;
    std::string getValidatedInput(const std::string& prompt, bool (*validationFunc)(const std::string&)) const;

public:
    /**
     * @brief Constructor for the MenuUI class.
     * @param pService Reference to the PatientService.
     */
    explicit MenuUI(PatientService& pService);

    /**
     * @brief Main loop running the core application menu.
     */
    void run();
};

#endif