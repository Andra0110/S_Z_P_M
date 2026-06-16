#include "MenuUI.h"
#include <iostream>
#include <limits>

// Prywatne kody kolorów ANSI ułatwiające zarządzanie UX
namespace {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string CYAN    = "\033[36m";
    const std::string BOLD    = "\033[1m";

    void pressEnterToContinue() {
        std::cout << "\n" << CYAN << "Press Enter to continue..." << RESET;
        std::cin.clear();
        std::cin.get();
    }
}

/**
 * @brief Constructs the MenuUI implementation and binds core services.
 * @param pService Reference to the active PatientService.
 * @param dService Reference to the active DoctorService.
 * @param vService Reference to the active VisitService.
 */
MenuUI::MenuUI(PatientService& pService, DoctorService& dService, VisitService& vService) 
    : patientService(pService), doctorService(dService), visitService(vService) {}

/**
 * @brief Starts the primary infinite loop for the application's main menu.
 */
void MenuUI::run() {
    int choice = 0;
    while (true) {
        std::cout << "\n" << CYAN << "===========================================\n" << RESET;
        std::cout << BOLD << "        CLINIC MANAGEMENT SYSTEM          \n" << RESET;
        std::cout << CYAN << "===========================================\n" << RESET;
        std::cout << "1. Patient Management\n";
        std::cout << "2. Doctor Management\n";
        std::cout << "3. Visit Management\n";
        std::cout << RED << "0. Exit\n" << RESET;
        std::cout << "\nEnter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << RED << "Error: Invalid input. Please enter a number.\n" << RESET;
            clearInputBuffer();
            pressEnterToContinue();
            continue;
        }
        std::cin.ignore();

        if (choice == 1) {
            handlePatientMenu();
        } else if (choice == 2) {
            handleDoctorMenu();
        } else if (choice == 3) {
            handleVisitMenu();
        } else if (choice == 0) {
            std::cout << GREEN << "\nExiting system. Goodbye!\n\n" << RESET;
            break;
        } else {
            std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
            pressEnterToContinue();
        }
    }
}

// =========================================================================
// === PATIENT SUBMENU IMPLEMENTATION ===
// =========================================================================

void MenuUI::handlePatientMenu() {
    int choice = 0;
    while (true) {
        std::cout << "\n" << CYAN << "-------------------------------------------\n" << RESET;
        displayPatientMenu();
        if (!(std::cin >> choice)) {
            std::cout << RED << "Error: Invalid input. Please enter a number.\n" << RESET;
            clearInputBuffer();
            pressEnterToContinue();
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: addNewPatient(); pressEnterToContinue(); break;
            case 2: displayAllPatients(); pressEnterToContinue(); break;
            case 3: searchPatient(); pressEnterToContinue(); break;
            case 4: updatePatient(); pressEnterToContinue(); break;
            case 5: deletePatient(); pressEnterToContinue(); break;
            case 0: return;
            default: 
                std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
                pressEnterToContinue();
        }
    }
}

void MenuUI::displayPatientMenu() const {
    std::cout << CYAN << "--- PATIENT MANAGEMENT ---\n" << RESET;
    std::cout << "1. Add New Patient\n";
    std::cout << "2. Display All Patients\n";
    std::cout << "3. Search Patient (by ID)\n";
    std::cout << "4. Edit Patient Data\n";
    std::cout << "5. Delete Patient\n";
    std::cout << RED << "0. Return to Main Menu\n" << RESET;
    std::cout << "\nEnter your choice: ";
}

void MenuUI::addNewPatient() {
    std::cout << CYAN << "\n[ADD NEW PATIENT]\n" << RESET;
    int id;
    std::cout << "Enter Patient ID (number): ";
    while (!(std::cin >> id)) { 
        std::cout << RED << "Error: Must be a number: " << RESET; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    if (patientService.searchPatientById(id) != nullptr) {
        std::cout << RED << "Error: A patient with this ID already exists.\n" << RESET;
        return;
    }

    std::string firstName = getValidatedInput("Enter first name: ", Validator::isValidName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::isValidName);
    std::string pesel = getValidatedInput("Enter PESEL (11 digits): ", Validator::isValidPesel);

    Patient newPatient(id, firstName, lastName, pesel);
    patientService.addPatient(newPatient);
    std::cout << GREEN << "\nSuccess: Patient has been successfully added.\n" << RESET;
}

void MenuUI::displayAllPatients() const {
    std::cout << CYAN << "\n[PATIENT LIST]\n" << RESET;
    patientService.displayPatients(); 
}

void MenuUI::searchPatient() const {
    std::cout << CYAN << "\n[SEARCH PATIENT]\n" << RESET;
    int id;
    std::cout << "Enter Patient ID: ";
    while (!(std::cin >> id)) { 
        std::cout << RED << "Error: Must be a number: " << RESET; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    Patient* patient = patientService.searchPatientById(id);
    if (patient != nullptr) {
        std::cout << GREEN << "\nPatient found:\n" << RESET 
                  << "- Name: " << patient->getFirstName() << " " << patient->getLastName() << "\n"
                  << "- PESEL: " << patient->getPesel() << "\n";
    } else {
        std::cout << YELLOW << "\nInfo: No patient found with this ID.\n" << RESET;
    }
}

void MenuUI::updatePatient() {
    std::cout << CYAN << "\n[EDIT PATIENT DATA]\n" << RESET;
    int id;
    std::cout << "Enter Patient ID to edit: ";
    while (!(std::cin >> id)) { 
        std::cout << RED << "Error: Must be a number: " << RESET; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    Patient* patient = patientService.searchPatientById(id);
    if (patient == nullptr) {
        std::cout << RED << "Error: Patient does not exist.\n" << RESET;
        return;
    }
    std::string newFirstName = getValidatedInput("Enter new first name: ", Validator::isValidName);
    std::string newLastName = getValidatedInput("Enter new last name: ", Validator::isValidName);
    patient->setFirstName(newFirstName);
    patient->setLastName(newLastName);
    std::cout << GREEN << "\nSuccess: Patient data updated.\n" << RESET;
}

void MenuUI::deletePatient() {
    std::cout << CYAN << "\n[DELETE PATIENT]\n" << RESET;
    int id;
    std::cout << "Enter Patient ID to delete: ";
    while (!(std::cin >> id)) { 
        std::cout << RED << "Error: Must be a number: " << RESET; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    if (patientService.removePatient(id)) {
        std::cout << GREEN << "\nSuccess: Patient removed.\n" << RESET;
    } else {
        std::cout << RED << "Error: Patient not found.\n" << RESET;
    }
}

// =========================================================================
// === DOCTOR SUBMENU IMPLEMENTATION ===
// =========================================================================

void MenuUI::handleDoctorMenu() {
    int choice = 0;
    while (true) {
        std::cout << "\n" << CYAN << "-------------------------------------------\n" << RESET;
        displayDoctorMenu();
        if (!(std::cin >> choice)) {
            std::cout << RED << "Error: Invalid input. Please enter a number.\n" << RESET;
            clearInputBuffer();
            pressEnterToContinue();
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: addNewDoctor(); pressEnterToContinue(); break;
            case 2: displayAllDoctors(); pressEnterToContinue(); break;
            case 3: searchDoctor(); pressEnterToContinue(); break;
            case 0: return;
            default: 
                std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
                pressEnterToContinue();
        }
    }
}

void MenuUI::displayDoctorMenu() const {
    std::cout << CYAN << "--- DOCTOR MANAGEMENT ---\n" << RESET;
    std::cout << "1. Add New Doctor\n";
    std::cout << "2. Display All Doctors\n";
    std::cout << "3. Search Doctor (by ID)\n";
    std::cout << RED << "0. Return to Main Menu\n" << RESET;
    std::cout << "\nEnter your choice: ";
}

void MenuUI::addNewDoctor() {
    std::cout << CYAN << "\n[ADD NEW DOCTOR]\n" << RESET;
    int id;
    std::cout << "Enter Doctor ID (number): ";
    while (!(std::cin >> id)) {
        std::cout << RED << "Error: ID must be a number! Try again: " << RESET;
        clearInputBuffer();
    }
    std::cin.ignore();

    if (doctorService.searchDoctorById(id) != nullptr) {
        std::cout << RED << "Error: A doctor with this ID already exists.\n" << RESET;
        return;
    }

    std::string firstName = getValidatedInput("Enter first name: ", Validator::isValidName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::isValidName);
    std::string specialization = getValidatedInput("Enter specialization: ", Validator::isValidSpecialization);
    
    Doctor newDoctor(id, firstName, lastName, specialization);
    doctorService.addDoctor(newDoctor);
    std::cout << GREEN << "\nSuccess: Doctor has been successfully added.\n" << RESET;
}

void MenuUI::displayAllDoctors() const {
    std::cout << CYAN << "\n[DOCTOR LIST]\n" << RESET;
    doctorService.displayDoctors(); 
}

void MenuUI::searchDoctor() const {
    std::cout << CYAN << "\n[SEARCH DOCTOR]\n" << RESET;
    int id;
    std::cout << "Enter Doctor ID: ";
    while (!(std::cin >> id)) {
        std::cout << RED << "Error: ID must be a number! Try again: " << RESET;
        clearInputBuffer();
    }
    std::cin.ignore();

    Doctor* doctor = doctorService.searchDoctorById(id);
    if (doctor != nullptr) {
        std::cout << GREEN << "\nDoctor found:\n" << RESET
                  << "- Name: " << doctor->getFirstName() << " " << doctor->getLastName() << "\n"
                  << "- Specialization: " << doctor->getSpecialization() << "\n";
    } else {
        std::cout << YELLOW << "\nInfo: No doctor found with this ID.\n" << RESET;
    }
}

// =========================================================================
// === VISIT SUBMENU IMPLEMENTATION ===
// =========================================================================

void MenuUI::handleVisitMenu() {
    int choice = 0;
    while (true) {
        std::cout << "\n" << CYAN << "-------------------------------------------\n" << RESET;
        displayVisitMenu();
        if (!(std::cin >> choice)) {
            std::cout << RED << "Error: Invalid input. Please enter a number.\n" << RESET;
            clearInputBuffer();
            pressEnterToContinue();
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: addNewVisit(); pressEnterToContinue(); break;
            case 2: displayAllVisits(); pressEnterToContinue(); break;
            case 3: searchVisit(); pressEnterToContinue(); break;
            case 4: cancelVisit(); pressEnterToContinue(); break;
            case 0: return;
            default: 
                std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
                pressEnterToContinue();
        }
    }
}

void MenuUI::displayVisitMenu() const {
    std::cout << CYAN << "--- VISIT MANAGEMENT ---\n" << RESET;
    std::cout << "1. Book New Visit\n";
    std::cout << "2. Display All Visits\n";
    std::cout << "3. Search Visit (by ID)\n";
    std::cout << "4. Cancel/Remove Visit\n";
    std::cout << RED << "0. Return to Main Menu\n" << RESET;
    std::cout << "\nEnter your choice: ";
}

void MenuUI::addNewVisit() {
    std::cout << CYAN << "\n[BOOK NEW VISIT]\n" << RESET;
    
    int id, patientId, doctorId;
    std::cout << "Enter custom Visit ID (number): ";
    while (!(std::cin >> id)) { std::cout << RED << "Must be a number: " << RESET; clearInputBuffer(); }
    
    std::cout << "Enter Patient ID (number): ";
    while (!(std::cin >> patientId)) { std::cout << RED << "Must be a number: " << RESET; clearInputBuffer(); }
    
    std::cout << "Enter Doctor ID (number): ";
    while (!(std::cin >> doctorId)) { std::cout << RED << "Must be a number: " << RESET; clearInputBuffer(); }
    std::cin.ignore();

    std::string date = getValidatedInput("Enter Date (YYYY-MM-DD HH:MM): ", Validator::isValidDate);

    if (!visitService.canCreateVisit(patientId, doctorId, patientService, doctorService)) {
        std::cout << RED << "\nError: Provided Patient ID or Doctor ID does not exist in the system!\n" << RESET;
        return;
    }

    if (!visitService.isDoctorAvailable(doctorId, date)) {
        std::cout << RED << "\nError: The doctor is already booked on this date and time!\n" << RESET;
        return;
    }

    Visit newVisit(id, patientId, doctorId, date);
    visitService.addVisit(newVisit);
    std::cout << GREEN << "\nSuccess: Visit booked successfully.\n" << RESET;
}

void MenuUI::displayAllVisits() const {
    std::cout << CYAN << "\n[ALL BOOKED VISITS]\n" << RESET;
    visitService.displayVisits(); 
}

void MenuUI::searchVisit() const {
    std::cout << CYAN << "\n[SEARCH VISIT]\n" << RESET;
    int id;
    std::cout << "Enter Visit ID: ";
    while (!(std::cin >> id)) { std::cout << RED << "Must be a number: " << RESET; clearInputBuffer(); }
    std::cin.ignore();

    Visit* visit = visitService.searchVisitById(id);
    if (visit != nullptr) {
        std::cout << GREEN << "\nSuccess: Visit found with ID: " << id << "\n" << RESET;
        std::cout << "- Patient ID: " << visit->getPatientId() << "\n";
        std::cout << "- Doctor ID: " << visit->getDoctorId() << "\n";
        std::cout << "- Date & Time: " << visit->getDate() << "\n";
    } else {
        std::cout << YELLOW << "\nInfo: No visit found with this ID.\n" << RESET;
    }
}

void MenuUI::cancelVisit() {
    std::cout << CYAN << "\n[CANCEL VISIT]\n" << RESET;
    int id;
    std::cout << "Enter Visit ID to cancel: ";
    while (!(std::cin >> id)) { std::cout << RED << "Must be a number: " << RESET; clearInputBuffer(); }
    std::cin.ignore();

    if (visitService.removeVisit(id)) {
        std::cout << GREEN << "\nSuccess: Visit has been cancelled.\n" << RESET;
    } else {
        std::cout << RED << "Error: Visit not found.\n" << RESET;
    }
}

// =========================================================================
// === UTILITIES IMPLEMENTATION ===
// =========================================================================

void MenuUI::clearInputBuffer() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string MenuUI::getValidatedInput(const std::string& prompt, bool (*validationFunc)(const std::string&)) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (validationFunc(input)) return input;
        std::cout << RED << "Error: Invalid data format! Please try again.\n" << RESET;
    }
}