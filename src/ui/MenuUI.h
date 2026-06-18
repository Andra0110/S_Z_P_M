#ifndef MENUUI_H
#define MENUUI_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h" 
#include "../utils/Validator.h"

/**
 * @class MenuUI
 * @brief Handles the Command Line Interface (CLI) state and submenus for the clinic.
 *
 * This class encapsulates the user interface logic, storing references to core services
 * and providing distinct submenus for managing patients, doctors, and visits.
 */
class MenuUI {
private:
    PatientService& patientService; ///< Reference to the system's PatientService.
    DoctorService& doctorService;   ///< Reference to the system's DoctorService.
    VisitService& visitService;     ///< Reference to the system's VisitService.

    // === PATIENT SUBMENU ===
    void handlePatientMenu();
    void displayPatientMenu() const;
    void addNewPatient();
    void displayAllPatients() const;
    void searchPatient() const;
    void updatePatient();
    void deletePatient();

    // === DOCTOR SUBMENU ===
    void handleDoctorMenu();
    void displayDoctorMenu() const;
    void addNewDoctor();
    void displayAllDoctors() const;
    void searchDoctor() const;

    // === VISIT SUBMENU ===
    void handleVisitMenu();
    void displayVisitMenu() const;
    void addNewVisit();
    void displayAllVisits() const;
    void searchVisit() const;
    void cancelVisit();

    // === UTILITIES ===
    void clearInputBuffer() const;
    
    /**
     * @brief Helper to capture input from the user and validate it immediately.
     * @param prompt The message to display to the user.
     * @param validationFunc Pointer to a static validation function from Validator class.
     * @return std::string Validated user input.
     */
    std::string getValidatedInput(const std::string& prompt, bool (*validationFunc)(const std::string&)) const;

public:
    /**
     * @brief Constructs the MenuUI with explicit dependencies.
     * @param pService Reference to the active PatientService.
     * @param dService Reference to the active DoctorService.
     * @param vService Reference to the active VisitService.
     */
    MenuUI(PatientService& pService, DoctorService& dService, VisitService& vService);

    /**
     * @brief Starts the primary infinite loop for the application's main menu.
     */
    void run();
};

#endif