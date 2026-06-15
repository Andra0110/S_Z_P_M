#include "MenuUI.h"

MenuUI::MenuUI(PatientService& pService) : patientService(pService) {}

/**
 * @brief Clears the std::cin stream buffer in case of invalid input.
 */
void MenuUI::clearInputBuffer() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Requests input from the user and validates it in a loop until correct.
 * @param prompt The message displayed to the user.
 * @param validationFunc Pointer to the validation function from the Validator class.
 * @return A successfully validated string.
 */
std::string MenuUI::getValidatedInput(const std::string& prompt, bool (*validationFunc)(const std::string&)) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (validationFunc(input)) {
            return input;
        }
        std::cout << "Error: Invalid data format! Please try again.\n";
    }
}

void MenuUI::run() {
    int choice = 0;
    while (true) {
        std::cout << "\n=== CLINIC MANAGEMENT SYSTEM ===\n";
        std::cout << "1. Patient Management\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid character. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        std::cin.ignore(); // Clear the newline character after cin >>

        if (choice == 1) {
            handlePatientMenu();
        } else if (choice == 0) {
            std::cout << "Exiting the program...\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

/**
 * @brief Main loop of the patient management submenu.
 */
void MenuUI::handlePatientMenu() {
    int choice = 0;
    while (true) {
        displayPatientMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid character. Please enter a number.\n";
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
            case 0: return; // Return to the main menu
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

/**
 * @brief Displays the options of the patient submenu.
 */
void MenuUI::displayPatientMenu() const {
    std::cout << "\n--- PATIENT MANAGEMENT ---\n";
    std::cout << "1. Add new patient\n";
    std::cout << "2. Display all patients\n";
    std::cout << "3. Search patient (by PESEL)\n";
    std::cout << "4. Edit patient data\n";
    std::cout << "5. Delete patient\n";
    std::cout << "0. Back to main menu\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Collects user data, validates it, and adds a new patient via the service.
 */
void MenuUI::addNewPatient() {
    std::cout << "\n[ADDING NEW PATIENT]\n";
    
    std::string firstName = getValidatedInput("Enter first name: ", Validator::validateName);
    std::string lastName = getValidatedInput("Enter last name: ", Validator::validateName);
    std::string pesel = getValidatedInput("Enter PESEL (11 digits): ", Validator::validatePesel);

    if (patientService.findPatientByPesel(pesel) != nullptr) {
        std::cout << "Error: A patient with this PESEL already exists in the system.\n";
        return;
    }

    Patient newPatient(firstName, lastName, pesel);
    patientService.addPatient(newPatient);
    std::cout << "Success: Patient has been successfully added.\n";
}

/**
 * @brief Displays the list of all patients retrieved from the service.
 */
void MenuUI::displayAllPatients() const {
    std::cout << "\n[PATIENT LIST]\n";
    const auto& patients = patientService.getAllPatients();

    if (patients.empty()) {
        std::cout << "No registered patients in the system.\n";
        return;
    }

    for (const auto& patient : patients) {
        std::cout << "PESEL: " << patient.getPesel() 
                  << " | " << patient.getLastName() 
                  << " " << patient.getFirstName() << "\n";
    }
}

/**
 * @brief Searches for a patient based on the provided PESEL number.
 */
void MenuUI::searchPatient() const {
    std::cout << "\n[SEARCH PATIENT]\n";
    std::string pesel = getValidatedInput("Enter patient's PESEL: ", Validator::validatePesel);

    Patient* patient = patientService.findPatientByPesel(pesel);

    if (patient != nullptr) {
        std::cout << "Patient found:\n";
        std::cout << "First Name: " << patient->getFirstName() << "\n";
        std::cout << "Last Name: " << patient->getLastName() << "\n";
        std::cout << "PESEL: " << patient->getPesel() << "\n";
    } else {
        std::cout << "Info: No patient found with the provided PESEL.\n";
    }
}

/**
 * @brief Modifies the data of an existing patient.
 */
void MenuUI::updatePatient() {
    std::cout << "\n[EDIT PATIENT DATA]\n";
    std::string pesel = getValidatedInput("Enter PESEL of the patient to edit: ", Validator::validatePesel);

    Patient* patient = patientService.findPatientByPesel(pesel);

    if (patient == nullptr) {
        std::cout << "Error: Patient with the provided PESEL does not exist.\n";
        return;
    }

    std::cout << "Editing data for: " << patient->getFirstName() << " " << patient->getLastName() << "\n";
    
    std::string newFirstName = getValidatedInput("Enter new first name: ", Validator::validateName);
    std::string newLastName = getValidatedInput("Enter new last name: ", Validator::validateName);

    patient->setFirstName(newFirstName);
    patient->setLastName(newLastName);

    std::cout << "Success: Patient data has been updated.\n";
}

/**
 * @brief Deletes a patient from the system based on the PESEL number.
 */
void MenuUI::deletePatient() {
    std::cout << "\n[DELETE PATIENT]\n";
    std::string pesel = getValidatedInput("Enter PESEL of the patient to delete: ", Validator::validatePesel);

    bool success = patientService.deletePatientByPesel(pesel);

    if (success) {
        std::cout << "Success: Patient has been removed from the system.\n";
    } else {
        std::cout << "Error: Patient not found. Operation cancelled.\n";
    }
}