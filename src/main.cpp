#include "tests/PatientTests.h"
#include "tests/DoctorTests.h"
#include "tests/VisitTests.h"

/**
 * @brief Main entry point for the test execution suite.
 *
 * This function initializes the core business logic services (Patient, Doctor, Visit)
 * and sequentially passes them to dedicated test routines to verify system integrity,
 * data validation rules, and file persistence mechanisms.
 *
 * @return int Execution status (0 for success).
 */
int main()
{
    PatientService patientService;
    DoctorService doctorService;
    VisitService visitService;

    // Uruchomienie izolowanych testów modułu pacjentów
    testPatients(patientService);

    // Uruchomienie izolowanych testów modułu lekarzy
    testDoctors(doctorService);

    // Uruchomienie testów integracyjnych modułu wizyt (wymaga powiązań między serwisami)
    testVisits(
        patientService,
        doctorService,
        visitService
    );

    return 0;
}