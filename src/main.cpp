#include <iostream>
#include "models/Patient.h"
#include "services/PatientService.h"
#include "utils/Validator.h"
#include "models/Doctor.h"
#include "services/DoctorService.h"

int main()
{
    PatientService patientService;

    Patient patient1(1, "Anna", "Kowalska", "12345678901");

    patientService.addPatient(patient1);

    patientService.displayPatients();

    Patient* foundPatient = patientService.searchPatientById(1);

    if (foundPatient != nullptr)
    {
        std::cout << "Patient found: "
                  << std::endl;

        std::cout << foundPatient->getFirstName()
                  << " "
                  << foundPatient->getLastName()
                  <<std::endl;
    }
    else
    {
        std::cout << "Patient not found."
                  << std::endl;
    }

    bool removed = patientService.removePatient(1);

    if (removed)
    {
        std::cout << "Patient removed successfully."
                  << std::endl;  
    }
    else
    {
        std::cout << "Patient not found."
                  << std::endl;
    }

    std::cout <<"\nPatients after removal:\n";

    patientService.displayPatients();

    std::cout << "\nValidator tests:\n";

    std::cout << Validator::isValidName("Anna")
              << std::endl;
              
    std::cout << Validator::isValidName("Anna123")
              << std::endl;

    std::cout << Validator::isValidPesel("12345678901")
              << std::endl;

    std::cout << Validator::isValidPesel("12345")
              << std::endl;
              


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

DoctorService doctorService;

doctorService.addDoctor(doctor1);

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

    return 0;
}