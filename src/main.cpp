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

    // 2. Execute isolated patient module tests
    testPatients(patientService);
    std::cout << "[SUCCESS] Patient module tests passed.\n";

    // 3. Execute isolated doctor module tests
    testDoctors(doctorService);
    std::cout << "[SUCCESS] Doctor module tests passed.\n";

    // 4. Execute integration tests for the visit module (requires service cross-references)
    testVisits(patientService, doctorService, visitService);
    std::cout << "[SUCCESS] Visit module integration tests passed.\n";

    std::cout << "\nAll automated tests completed successfully!\n";
    std::cout << "Press Enter to launch the interactive menu...";
    std::cin.get(); // Wait for user acknowledgment before clearing screen/opening menu

    // 5. Inject dependencies into the UI layer and run the application
    // Przekazujemy oba serwisy: patientService oraz doctorService
    MenuUI ui(patientService, doctorService);
    ui.run();

    return 0;
}