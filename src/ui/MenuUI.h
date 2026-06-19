/**
 * @file MenuUI.h
 * @brief Header file for the MenuUI class managing the console user interface.
 */

#ifndef MENUUI_H
#define MENUUI_H

#pragma once

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
    PatientService& patientService; 
    DoctorService& doctorService;   
    VisitService& visitService;     

    // === PATIENT SUBMENU ===
    
    /**
     * @brief Handles the lifecycle loop of the Patient Management submenu.
     */
    void handlePatientMenu();

    /**
     * @brief Prints the text options for patient management.
     */
    void displayPatientMenu() const;

    /**
     * @brief Prompts user for details and stores a new Patient entity.
     */
    void addNewPatient();

    /**
     * @brief Outputs all stored patient information.
     */
    void displayAllPatients() const;

    /**
     * @brief Performs a search for a patient based on console ID input.
     */
    void searchPatient() const;

    /**
     * @brief Edits the fields of a specific patient record.
     */
    void updatePatient();

    /**
     * @brief Deletes a patient from the active data repository.
     */
    void deletePatient();

    // === DOCTOR SUBMENU ===
    
    /**
     * @brief Handles the lifecycle loop of the Doctor Management submenu.
     */
    void handleDoctorMenu();

    /**
     * @brief Prints the text options for doctor management.
     */
    void displayDoctorMenu() const;

    /**
     * @brief Prompts user for details and stores a new Doctor entity.
     */
    void addNewDoctor();

    /**
     * @brief Outputs all registered doctor information.
     */
    void displayAllDoctors() const;

    /**
     * @brief Performs a search for a doctor based on console ID input.
     */
    void searchDoctor() const;

    // === VISIT SUBMENU ===
    
    /**
     * @brief Handles the lifecycle loop of the Appointment/Visit Management submenu.
     */
    void handleVisitMenu();

    /**
     * @brief Prints the text options for appointment scheduling.
     */
    void displayVisitMenu() const;

    /**
     * @brief Processes reservation rules and hooks into backend validation before reserving timeslots.
     */
    void addNewVisit();

    /**
     * @brief Outputs all scheduled calendar visits.
     */
    void displayAllVisits() const;

    /**
     * @brief Searches and prints full details of a specific visit ID.
     */
    void searchVisit() const;

    /**
     * @brief Calls removal routines to wipe a visit from backend calendars.
     */
    void cancelVisit();

    // === UTILITIES ===
    
    /**
     * @brief Safely clears std::cin stream error state flags and discards unread data.
     */
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