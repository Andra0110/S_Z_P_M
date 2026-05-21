#include <iostream>
#include "models/Patient.h"
#include "services/PatientService.h"

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

    return 0;
}