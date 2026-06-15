#include "tests/PatientTests.h"
#include "tests/DoctorTests.h"
#include "tests/VisitTests.h"
#include "src/ui/MenuUI.h"
#include "src/services/PatientService.h"
#include "src/services/DoctorService.h"
#include "src/services/VisitService.h"
#include <iostream>

/**
 * @brief Main execution function.
 * @return int Execution status (0 for success).
 */
int main() 
{
    PatientService patientService;
    DoctorService doctorService;
    VisitService visitService;

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

    MenuUI ui(patientService, doctorService, visitService);
    ui.run();

    return 0;
}