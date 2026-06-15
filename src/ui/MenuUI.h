#ifndef MENUUI_H
#define MENUUI_H

#include "../services/PatientService.h"
#include "../services/DoctorService.h"
#include "../services/VisitService.h" 
#include "../utils/Validator.h"

class MenuUI {
private:
    PatientService& patientService;
    DoctorService& doctorService;
    VisitService& visitService;         

    void handlePatientMenu();
    void displayPatientMenu() const;
    void addNewPatient();
    void displayAllPatients() const;
    void searchPatient() const;
    void updatePatient();
    void deletePatient();

    void handleDoctorMenu();
    void displayDoctorMenu() const;
    void addNewDoctor();
    void displayAllDoctors() const;
    void searchDoctor() const;

    void handleVisitMenu();
    void displayVisitMenu() const;
    void addNewVisit();
    void displayAllVisits() const;
    void searchVisit() const;
    void cancelVisit();

    void clearInputBuffer() const;
    std::string getValidatedInput(const std::string& prompt, bool (*validationFunc)(const std::string&)) const;

public:
    MenuUI(PatientService& pService, DoctorService& dService, VisitService& vService);
    void run();
};

#endif