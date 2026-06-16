#include "MenuUI.h"
#include <iostream>
#include <limits>

/**
 * @brief Constructs the MenuUI implementation and binds core services.
 * * @param pService Reference to the active PatientService.
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
        std::cout << "\n=== CLINIC MANAGEMENT SYSTEM ===\n";
        std::cout << "1. Patient Management\n";
        std::cout << "2. Doctor Management\n";
        std::cout << "3. Visit Management\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
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
            std::cout << "Exiting system. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// =========================================================================
// === PATIENT SUBMENU IMPLEMENTATION ===
// =========================================================================

void MenuUI::handlePatientMenu() {
    int choice = 0;
    while (true) {
        displayPatientMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: addNewPatient(); break;
            case 2: displayAllPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 0: return;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void MenuUI::displayPatientMenu() const {
    std::cout << "\n--- PATIENT MANAGEMENT ---\n";
    std::cout << "1. Add New Patient\n";
    std::cout << "2. Display All Patients\n";
    std::cout << "3. Search Patient (by ID)\n";
    std::cout << "4. Edit Patient Data\n";
    std::cout << "5. Delete Patient\n";
    std::cout << "0. Return to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void MenuUI::addNewPatient() {
    std::cout << "\n[ADD NEW PATIENT]\n";
    int id;
    std::cout << "Enter Patient ID (number): ";
    while (!(std::cin >> id)) { 
        std::cout << "Error: Must be a number: "; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    if (patientService.searchPatientById(id) != nullptr) {
        std::cout << "Error: A patient with this ID already exists.\n";
        return;
    }

    std::string firstName = getValidatedInput("Enter first name: ", Validator::isValidName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::isValidName);
    std::string pesel = getValidatedInput("Enter PESEL (11 digits): ", Validator::isValidPesel);

    Patient newPatient(id, firstName, lastName, pesel);
    patientService.addPatient(newPatient);
    std::cout << "Success: Patient has been successfully added.\n";
}

void MenuUI::displayAllPatients() const {
    std::cout << "\n[PATIENT LIST]\n";
    patientService.displayPatients(); 
}

void MenuUI::searchPatient() const {
    std::cout << "\n[SEARCH PATIENT]\n";
    int id;
    std::cout << "Enter Patient ID: ";
    while (!(std::cin >> id)) { 
        std::cout << "Error: Must be a number: "; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    Patient* patient = patientService.searchPatientById(id);
    if (patient != nullptr) {
        std::cout << "Patient found:\n- Name: " << patient->getFirstName() << " " << patient->getLastName() << "\n";
    } else {
        std::cout << "Info: No patient found with this ID.\n";
    }
}

void MenuUI::updatePatient() {
    std::cout << "\n[EDIT PATIENT DATA]\n";
    int id;
    std::cout << "Enter Patient ID to edit: ";
    while (!(std::cin >> id)) { 
        std::cout << "Error: Must be a number: "; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    Patient* patient = patientService.searchPatientById(id);
    if (patient == nullptr) {
        std::cout << "Error: Patient does not exist.\n";
        return;
    }
    std::string newFirstName = getValidatedInput("Enter new first name: ", Validator::isValidName);
    std::string newLastName = getValidatedInput("Enter new last name: ", Validator::isValidName);
    patient->setFirstName(newFirstName);
    patient->setLastName(newLastName);
    std::cout << "Success: Patient data updated.\n";
}

void MenuUI::deletePatient() {
    std::cout << "\n[DELETE PATIENT]\n";
    int id;
    std::cout << "Enter Patient ID to delete: ";
    while (!(std::cin >> id)) { 
        std::cout << "Error: Must be a number: "; 
        clearInputBuffer(); 
    }
    std::cin.ignore();

    if (patientService.removePatient(id)) {
        std::cout << "Success: Patient removed.\n";
    } else {
        std::cout << "Error: Patient not found.\n";
    }
}

// =========================================================================
// === DOCTOR SUBMENU IMPLEMENTATION ===
// =========================================================================

void MenuUI::handleDoctorMenu() {
    int choice = 0;
    while (true) {
        displayDoctorMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: addNewDoctor(); break;
            case 2: displayAllDoctors(); break;
            case 3: searchDoctor(); break;
            case 0: return;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void MenuUI::displayDoctorMenu() const {
    std::cout << "\n--- DOCTOR MANAGEMENT ---\n";
    std::cout << "1. Add New Doctor\n";
    std::cout << "2. Display All Doctors\n";
    std::cout << "3. Search Doctor (by ID)\n";
    std::cout << "0. Return to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void MenuUI::addNewDoctor() {
    std::cout << "\n[ADD NEW DOCTOR]\n";
    int id;
    std::cout << "Enter Doctor ID (number): ";
    while (!(std::cin >> id)) {
        std::cout << "Error: ID must be a number! Try again: ";
        clearInputBuffer();
    }
    std::cin.ignore();

    if (doctorService.searchDoctorById(id) != nullptr) {
        std::cout << "Error: A doctor with this ID already exists.\n";
        return;
    }

    std::string firstName = getValidatedInput("Enter first name: ", Validator::isValidName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::isValidName);
    std::string specialization = getValidatedInput("Enter specialization: ", Validator::isValidSpecialization);
    
    Doctor newDoctor(id, firstName, lastName, specialization);
    doctorService.addDoctor(newDoctor);
    std::cout << "Success: Doctor has been successfully added.\n";
}

void MenuUI::displayAllDoctors() const {
    std::cout << "\n[DOCTOR LIST]\n";
    doctorService.displayDoctors(); 
}

void MenuUI::searchDoctor() const {
    std::cout << "\n[SEARCH DOCTOR]\n";
    int id;
    std::cout << "Enter Doctor ID: ";
    while (!(std::cin >> id)) {
        std::cout << "Error: ID must be a number! Try again: ";
        clearInputBuffer();
    }
    std::cin.ignore();

    Doctor* doctor = doctorService.searchDoctorById(id);
    if (doctor != nullptr) {
        std::cout << "Doctor found:\n- Name: " << doctor->getFirstName() << " " << doctor->getLastName() 
                  << "\n- Specialization: " << doctor->getSpecialization() << "\n";
    } else {
        std::cout << "Info: No doctor found with this ID.\n";
    }
}

// =========================================================================
// === VISIT SUBMENU IMPLEMENTATION ===
// =========================================================================

void MenuUI::handleVisitMenu() {
    int choice = 0;
    while (true) {
        displayVisitMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: addNewVisit(); break;
            case 2: displayAllVisits(); break;
            case 3: searchVisit(); break;
            case 4: cancelVisit(); break;
            case 0: return;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void MenuUI::displayVisitMenu() const {
    std::cout << "\n--- VISIT MANAGEMENT ---\n";
    std::cout << "1. Book New Visit\n";
    std::cout << "2. Display All Visits\n";
    std::cout << "3. Search Visit (by ID)\n";
    std::cout << "4. Cancel/Remove Visit\n";
    std::cout << "0. Return to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void MenuUI::addNewVisit() {
    std::cout << "\n[BOOK NEW VISIT]\n";
    
    int id, patientId, doctorId;
    std::cout << "Enter custom Visit ID (number): ";
    while (!(std::cin >> id)) { std::cout << "Must be a number: "; clearInputBuffer(); }
    
    std::cout << "Enter Patient ID (number): ";
    while (!(std::cin >> patientId)) { std::cout << "Must be a number: "; clearInputBuffer(); }
    
    std::cout << "Enter Doctor ID (number): ";
    while (!(std::cin >> doctorId)) { std::cout << "Must be a number: "; clearInputBuffer(); }
    std::cin.ignore();

    std::string date = getValidatedInput("Enter Date (YYYY-MM-DD HH:MM): ", Validator::isValidDate);

    if (!visitService.canCreateVisit(patientId, doctorId, patientService, doctorService)) {
        std::cout << "Error: Provided Patient ID or Doctor ID does not exist in the system!\n";
        return;
    }

    if (!visitService.isDoctorAvailable(doctorId, date)) {
        std::cout << "Error: The doctor is already booked on this date and time!\n";
        return;
    }

    Visit newVisit(id, patientId, doctorId, date);
    visitService.addVisit(newVisit);
    std::cout << "Success: Visit booked successfully.\n";
}

void MenuUI::displayAllVisits() const {
    std::cout << "\n[ALL BOOKED VISITS]\n";
    visitService.displayVisits(); 
}

void MenuUI::searchVisit() const {
    std::cout << "\n[SEARCH VISIT]\n";
    int id;
    std::cout << "Enter Visit ID: ";
    while (!(std::cin >> id)) { std::cout << "Must be a number: "; clearInputBuffer(); }
    std::cin.ignore();

    Visit* visit = visitService.searchVisitById(id);
    if (visit != nullptr) {
        std::cout << "Success: Visit found with ID: " << id << "\n";
        std::cout << "- Patient ID: " << visit->getPatientId() << "\n";
        std::cout << "- Doctor ID: " << visit->getDoctorId() << "\n";
        std::cout << "- Date & Time: " << visit->getDate() << "\n";
    } else {
        std::cout << "Info: No visit found with this ID.\n";
    }
}

void MenuUI::cancelVisit() {
    std::cout << "\n[CANCEL VISIT]\n";
    int id;
    std::cout << "Enter Visit ID to cancel: ";
    while (!(std::cin >> id)) { std::cout << "Must be a number: "; clearInputBuffer(); }
    std::cin.ignore();

    if (visitService.removeVisit(id)) {
        std::cout << "Success: Visit has been cancelled.\n";
    } else {
        std::cout << "Error: Visit not found.\n";
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
        std::cout << "Error: Invalid data format! Please try again.\n";
    }
}