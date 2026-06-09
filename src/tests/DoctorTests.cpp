#include <iostream>
#include <vector>

#include "DoctorTests.h"
#include "../models/Doctor.h"
#include "../services/FileService.h"
#include "../utils/Validator.h"

void testDoctors(
    DoctorService& doctorService
)
{
    std::cout << "\n=== DOCTOR TESTS ===\n";

std::cout << "\nDoctor test:\n";

Doctor doctor1(
    1,
    "Jan",
    "Nowak",
    "Cardiology"
);

std::cout << "ID: "
          << doctor1.getId()
          << std::endl;

std::cout << "First name: "
          << doctor1.getFirstName()
          << std::endl;

std::cout << "Last name: "
          << doctor1.getLastName()
          << std::endl;

std::cout << "Specialization: "
          << doctor1.getSpecialization()
          << std::endl;


std::cout << "\nDoctorService test:\n";

doctorService.addDoctor(doctor1);

FileService::saveDoctors(
    doctorService.getDoctors(),
    "data/doctors.txt"
);

std::cout << "\nLoading doctors from file:\n";

std::vector<Doctor> loadedDoctors =
    FileService::loadDoctors(
        "data/doctors.txt"
    );

for (const auto& doctor : loadedDoctors)
{
    std::cout << doctor.getId()
              << " "
              << doctor.getFirstName()
              << " "
              << doctor.getLastName()
              << " "
              << doctor.getSpecialization()
              << std::endl;
}

doctorService.displayDoctors();

Doctor* foundDoctor = doctorService.searchDoctorById(1);

if (foundDoctor != nullptr)
{
    std::cout << "Doctor found: "
              << foundDoctor->getFirstName()
              << " "
              << foundDoctor->getLastName()
              << std::endl;
}


std::cout << "\nDoctor validator tests:\n";

std::cout << Validator::isValidSpecialization("Cardiology")
          << std::endl;    
          
std::cout << Validator::isValidSpecialization("")
          << std::endl;


}


