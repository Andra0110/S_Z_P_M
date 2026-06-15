#include <iostream>
#include <vector>

#include "DoctorTests.h"
#include "../models/Doctor.h"
#include "../services/FileService.h"
#include "../utils/Validator.h"

/**
 * @brief Executes automated unit and integration tests for the Doctor module.
 *
 * @param doctorService Reference to the DoctorService instance to be tested.
 */
void testDoctors(
    DoctorService& doctorService
)
{
    std::cout << "\n=== DOCTOR TESTS ===\n";

    std::cout << "\n[TEST] Creating Doctor object:\n";

    Doctor doctor1(
        1,
        "Jan",
        "Nowak",
        "Cardiology"
    );

    std::cout << "ID: " << doctor1.getId() << "\n";
    std::cout << "First name: " << doctor1.getFirstName() << "\n";
    std::cout << "Last name: " << doctor1.getLastName() << "\n";
    std::cout << "Specialization: " << doctor1.getSpecialization() << "\n";

    std::cout << "\n[TEST] DoctorService and File Serialization:\n";

    doctorService.addDoctor(doctor1);

    // Zmieniono ścieżkę z "data/doctors.txt" na "doctors.txt"
    FileService::saveDoctors(
        doctorService.getDoctors(),
        "doctors.txt"
    );

    std::cout << "Loading doctors from file:\n";

    std::vector<Doctor> loadedDoctors =
        FileService::loadDoctors("doctors.txt");

    for (const auto& doctor : loadedDoctors)
    {
        std::cout << " - " << doctor.getId()
                  << " " << doctor.getFirstName()
                  << " " << doctor.getLastName()
                  << " (" << doctor.getSpecialization() << ")\n";
    }

    std::cout << "\n[TEST] Displaying doctors from live service:\n";
    doctorService.displayDoctors();

    // Test wyszukiwania lekarza
    Doctor* foundDoctor = doctorService.searchDoctorById(1);

    if (foundDoctor != nullptr)
    {
        std::cout << "[TEST] Doctor found: "
                  << foundDoctor->getFirstName()
                  << " "
                  << foundDoctor->getLastName()
                  << "\n";
                  
        // TEST EDYCJI (Weryfikacja dodanych setterów)
        std::cout << "[TEST] Modifying doctor specialization...\n";
        foundDoctor->setSpecialization("Neurology");
        std::cout << "Updated specialization: " << foundDoctor->getSpecialization() << "\n";
    }

    // Testy klasy walidatora
    std::cout << "\n[TEST] Doctor validator tests:\n";
    std::cout << "Is 'Cardiology' valid? " << Validator::isValidSpecialization("Cardiology") << "\n";      
    std::cout << "Is empty string valid? " << Validator::isValidSpecialization("") << "\n";

    std::cout << std::endl;
}