#include "models/Patient.h"
#include "services/PatientService.h"

int main()
{
    PatientService patientService;

    Patient patient1(1, "Anna", "Kowalska", "12345678901");

    PatientService.addPatient(patient1);

    PatientService.displayPatients();

    return 0;
}