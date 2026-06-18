#include "tests/PatientTests.h"
#include "tests/DoctorTests.h"
#include "tests/VisitTests.h"
#include "ui/MenuUI.h"
#include "services/PatientService.h"
#include "services/DoctorService.h"
#include "services/VisitService.h"
#include <iostream>
#include <cstring>

/**
 * @brief Main execution function.
 *
 * Checks for optional runtime arguments to trigger automated testing.
 * Otherwise, directly initializes the object-oriented MenuUI suite to launch
 * the interactive clinic console.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Execution status (0 for success).
 */
int main(int argc, char* argv[]) 
{
    PatientService patientService;
    DoctorService doctorService;
    VisitService visitService;

    // AUTOMATYCZNE WCZYTANIE BAZY PACJENTÓW Z PLIKU PRZY STARCIE
    patientService.loadFromFile();
    doctorService.loadFromFile();
    visitService.loadFromFile();
    

    if (argc > 1 && std::strcmp(argv[1], "--test") == 0)
    {
        std::cout << "===========================================\n";
        std::cout << "RUNNING AUTOMATED BACKEND TESTS...\n";
        std::cout << "===========================================\n";

        testPatients(patientService);
        std::cout << "[SUCCESS] Patient module tests passed.\n";

        testDoctors(doctorService);
        std::cout << "[SUCCESS] Doctor module tests passed.\n";

        testVisits(patientService, doctorService, visitService);
        std::cout << "[SUCCESS] Visit module integration tests passed.\n";

        std::cout << "\nAll automated tests completed successfully!\n";
        std::cout << "Press Enter to launch the interactive menu...";
        std::cin.get(); 
    }

    MenuUI ui(patientService, doctorService, visitService);
    ui.run();

    return 0;
}