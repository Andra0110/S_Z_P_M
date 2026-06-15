#include <iostream>
#include <vector>

#include "VisitTests.h"
#include "../models/Patient.h"
#include "../models/Doctor.h"
#include "../models/Visit.h"
#include "../services/FileService.h"
#include "../utils/Validator.h"

/**
 * @brief Executes integration tests for the Visit module.
 *
 * @param patientService Reference to the active PatientService.
 * @param doctorService Reference to the active DoctorService.
 * @param visitService Reference to the VisitService instance to be tested.
 */
void testVisits(
    PatientService& patientService,
    DoctorService& doctorService,
    VisitService& visitService
)
{
    std::cout << "\n=== VISIT TESTS ===\n";

    // Rejestracja testowego pacjenta i lekarza (wymagane do poprawnej walidacji wizyt)
    Patient mockPatient(1, "Anna", "Kowalska", "12345678901");
    Doctor mockDoctor(1, "Jan", "Nowak", "Cardiology");
    
    // Dodajemy do serwisów (jeśli jeszcze nie istnieją z poprzednich testów)
    if (patientService.searchPatientById(1) == nullptr) {
        patientService.addPatient(mockPatient);
    }
    if (doctorService.searchDoctorById(1) == nullptr) {
        doctorService.addDoctor(mockDoctor);
    }

    // Tworzenie obiektów wizyt
    Visit visit1(
        1,
        1,
        1,
        "2026-06-15 14:00"
    );

    Visit visit2(
        2,
        1,
        1,
        "2026-06-20 10:00"
    );

    std::cout << "\n[TEST] Visit validation test (Existing Patient & Doctor):\n";
    bool validVisit = visitService.canCreateVisit(
        visit1.getPatientId(),
        visit1.getDoctorId(),
        patientService,
        doctorService
    );

    if (validVisit)
    {
        std::cout << "Result: Visit can be created.\n";
    }
    else
    {
        std::cout << "Result: Invalid patient or doctor.\n";
    }

    std::cout << "\n[TEST] Invalid visit validation test (Non-existent entities):\n";
    Visit invalidVisit(
        2,
        999,
        888,
        "2026-06-20 12:00"
    );

    bool invalidResult = visitService.canCreateVisit(
        invalidVisit.getPatientId(),
        invalidVisit.getDoctorId(),
        patientService,
        doctorService
    );
    
    if (invalidResult)
    {
        std::cout << "Result: Visit can be created.\n";
    }
    else
    {
        std::cout << "Result: Invalid patient or doctor (Correctly blocked).\n";
    }

    std::cout << "\n[TEST] Displaying basic visit info:\n";
    std::cout << "Visit ID: " << visit1.getId() << "\n";
    std::cout << "Patient ID: " << visit1.getPatientId() << "\n";
    std::cout << "Doctor ID: " << visit1.getDoctorId() << "\n";
    std::cout << "Date: " << visit1.getDate() << "\n";

    std::cout << "\n[TEST] VisitService Registration & File Serialization:\n";
    visitService.addVisit(visit1);
    visitService.addVisit(visit2);

    // Zmieniono ścieżkę z "data/visits.txt" na "visits.txt"
    FileService::saveVisits(
        visitService.getVisits(),
        "visits.txt"
    );

    std::cout << "\n[TEST] Doctor Availability Conflict test:\n";
    bool available = visitService.isDoctorAvailable(
        1,
        "2026-06-15 14:00"
    );

    if (available)
    {
        std::cout << "Result: Doctor is available.\n";
    }
    else
    {
        std::cout << "Result: Conflict detected (Correctly blocked).\n";
    }

    std::cout << "\n--- All visits ---\n";
    visitService.displayVisits();

    std::cout << "\n--- Visits for patient ID 1 ---\n";
    visitService.displayVisitsByPatient(1);

    std::cout << "\n--- Visits for doctor ID 1 ---\n";
    visitService.displayVisitsByDoctor(1);

    Visit* foundVisit = visitService.searchVisitById(1);

    if (foundVisit != nullptr)
    {
        std::cout << "\n[TEST] Visit found by ID. Date: " << foundVisit->getDate() << "\n";
        std::cout << "\nDetailed visit information:\n";

        Patient* visitPatient = patientService.searchPatientById(visit1.getPatientId());
        Doctor* visitDoctor = doctorService.searchDoctorById(visit1.getDoctorId());

        if (visitPatient != nullptr && visitDoctor != nullptr)
        {
            std::cout << "Visit ID: " << visit1.getId() << "\n";
            std::cout << "Patient: " << visitPatient->getFirstName() << " " << visitPatient->getLastName() << "\n";
            std::cout << "Doctor: " << visitDoctor->getFirstName() << " " << visitDoctor->getLastName() << "\n";
            std::cout << "Specialization: " << visitDoctor->getSpecialization() << "\n";
            std::cout << "Date: " << visit1.getDate() << "\n";
        }
    }

    std::cout << "\n[TEST] Removing Visit ID 1:\n";
    bool removedVisit = visitService.removeVisit(1);

    if (removedVisit)
    {
        std::cout << "Result: Visit removed successfully.\n";
    }
    else
    {
        std::cout << "Result: Visit not found.\n";
    }

    std::cout << "\n--- Visits after removal ---\n";
    visitService.displayVisits();

    std::cout << "\n--- Visits for patient ID 1 after removal ---\n";
    visitService.displayVisitsByPatient(1);

    std::cout << "\n[TEST] Date validator format tests:\n";
    std::cout << "Is '2026-06-15 14:00' valid? " << Validator::isValidDate("2026-06-15 14:00") << "\n";
    std::cout << "Is '15.06.2026' valid? " << Validator::isValidDate("15.06.2026") << "\n";
    std::cout << "Is 'abc' valid? " << Validator::isValidDate("abc") << "\n";

    std::cout << "\n[TEST] Loading patients from backup file:\n";
    std::vector<Patient> loadedPatients = FileService::loadPatients("patients.txt");
    for (const auto& patient : loadedPatients)
    {
        std::cout << " - " << patient.getId() << " " << patient.getFirstName() << " " << patient.getLastName() << "\n";
    }

    std::cout << "\n[TEST] Loading visits from backup file:\n";
    std::vector<Visit> loadedVisits = FileService::loadVisits("visits.txt");
    for (const auto& visit : loadedVisits)
    {
        std::cout << " - Visit ID: " << visit.getId() 
                  << " | Patient ID: " << visit.getPatientId() 
                  << " | Doctor ID: " << visit.getDoctorId() 
                  << " | Date: " << visit.getDate() << "\n";
    }
}