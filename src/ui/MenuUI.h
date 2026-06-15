#ifndef MENUUI_H
#define MENUUI_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../utils/Validator.h"

class MenuUI {
private:
    PatientService& patientService;
    DoctorService& doctorService;

    // Sekcja Pacjentów
    void handlePatientMenu();
    void displayPatientMenu() const;
    void addNewPatient();
    void displayAllPatients() const;
    void searchPatient() const;
    void updatePatient();
    void deletePatient();

    // Sekcja Lekarzy (#46)
    void handleDoctorMenu();
    void displayDoctorMenu() const;
    void addNewDoctor();
    void displayAllDoctors() const;
    void searchDoctor() const;

    // Funkcje pomocnicze
    void clearInputBuffer() const;
    std::string getValidatedInput(const std::string& prompt, bool (*validationFunc)(const std::string&)) const;

public:
    MenuUI(PatientService& pService, DoctorService& dService);
    void run();
};

#endif // MENUUI_H