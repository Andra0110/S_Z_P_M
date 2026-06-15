#include "MenuUI.h"
#include <iostream>
#include <limits>

MenuUI::MenuUI(PatientService& pService, DoctorService& dService) 
    : patientService(pService), doctorService(dService) {}

void MenuUI::run() {
    int choice = 0;
    while (true) {
        std::cout << "\n=== CLINIC MANAGEMENT SYSTEM ===\n";
        std::cout << "1. Patient Management\n";
        std::cout << "2. Doctor Management\n";
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
        } else if (choice == 0) {
            std::cout << "Exiting system. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

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
    std::cout << "3. Search Patient (by PESEL)\n";
    std::cout << "4. Edit Patient Data\n";
    std::cout << "5. Delete Patient\n";
    std::cout << "0. Return to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void MenuUI::addNewPatient() {
    std::cout << "\n[ADD NEW PATIENT]\n";
    std::string firstName = getValidatedInput("Enter first name: ", Validator::validateName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::validateName);
    std::string pesel = getValidatedInput("Enter PESEL (11 digits): ", Validator::validatePesel);

    if (patientService.findPatientByPesel(pesel) != nullptr) {
        std::cout << "Error: A patient with this PESEL already exists.\n";
        return;
    }

    Patient newPatient(firstName, lastName, pesel);
    patientService.addPatient(newPatient);
    std::cout << "Success: Patient has been successfully added.\n";
}

void MenuUI::displayAllPatients() const {
    std::cout << "\n[PATIENT LIST]\n";
    const auto& patients = patientService.getAllPatients();
    if (patients.empty()) {
        std::cout << "No registered patients found.\n";
        return;
    }
    for (const auto& patient : patients) {
        std::cout << "PESEL: " << patient.getPesel() << " | " << patient.getLastName() << ", " << patient.getFirstName() << "\n";
    }
}

void MenuUI::searchPatient() const {
    std::cout << "\n[SEARCH PATIENT]\n";
    std::string pesel = getValidatedInput("Enter patient's PESEL: ", Validator::validatePesel);
    Patient* patient = patientService.findPatientByPesel(pesel);
    if (patient != nullptr) {
        std::cout << "Patient found:\n- Name: " << patient->getFirstName() << " " << patient->getLastName() << "\n";
    } else {
        std::cout << "Info: No patient found.\n";
    }
}

void MenuUI::updatePatient() {
    std::cout << "\n[EDIT PATIENT DATA]\n";
    std::string pesel = getValidatedInput("Enter PESEL to edit: ", Validator::validatePesel);
    Patient* patient = patientService.findPatientByPesel(pesel);
    if (patient == nullptr) {
        std::cout << "Error: Patient does not exist.\n";
        return;
    }
    std::string newFirstName = getValidatedInput("Enter new first name: ", Validator::validateName);
    std::string newLastName = getValidatedInput("Enter new last name: ", Validator::validateName);
    patient->setFirstName(newFirstName);
    patient->setLastName(newLastName);
    std::cout << "Success: Patient data updated.\n";
}

void MenuUI::deletePatient() {
    std::cout << "\n[DELETE PATIENT]\n";
    std::string pesel = getValidatedInput("Enter PESEL to delete: ", Validator::validatePesel);
    if (patientService.deletePatientByPesel(pesel)) {
        std::cout << "Success: Patient removed.\n";
    } else {
        std::cout << "Error: Patient not found.\n";
    }
}

// ============================================================================
// BEZPIECZNA SEKCJA LEKARZY (#46)
// ============================================================================
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

    std::string firstName = getValidatedInput("Enter first name: ", Validator::validateName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::validateName);
    
    Doctor newDoctor(id, firstName, lastName);
    doctorService.addDoctor(newDoctor);
    std::cout << "Success: Doctor has been successfully added.\n";
}

void MenuUI::displayAllDoctors() const {
    std::cout << "\n[DOCTOR LIST]\n";
    // Używamy gotowej metody Twojej koleżanki, która sama wszystko wypisze na ekran!
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
        std::cout << "Doctor found with ID: " << id << "\n";
    } else {
        std::cout << "Info: No doctor found with this ID.\n";
    }
}

// ============================================================================
// METODY POMOCNICZE
// ============================================================================
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