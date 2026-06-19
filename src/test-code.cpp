#include <iostream>
#include "utils/Validator.h"
#include "services/VisitService.h"
#include "services/FileService.h"

int main() {
    std::cout << "\n=== EDGE CASE TESTS ===\n";

    bool isInvalidPeselValid = Validator::isValidPesel("123");
    if (isInvalidPeselValid == false) {
        std::cout << "Success! Validator correctly rejected short PESEL.\n";
    } else {
        std::cout << "ALARM! Bug! Validator accepted a PESEL that is too short!\n";
    }

    bool isInvalidNameValid = Validator::isValidName("");
    if (isInvalidNameValid == false) {
        std::cout << "Success! Validator correctly rejected empty name.\n";
    } else {
        std::cout << "ALARM! Bug! Validator accepted an empty name!\n";
    }

    std::cout << "\n=== TIMETABLE CONFLICT TEST ===\n";
    VisitService visitService;
    bool available = visitService.isDoctorAvailable(1, "2026-06-15 14:00");
    if (available == false) {
        std::cout << "Success! System correctly detected that Doctor 1 is BUSY.\n";
    } else {
        std::cout << "ALARM! Bug or empty database! System says doctor is available.\n";
    }

    std::cout << "\n=== FILE ERROR HANDLING TEST ===\n";
    std::cout << "Attempting to load data from a non-existent file...\n";
    
    
    std::vector<Visit> fakeVisits = FileService::loadVisits("nie_ma_mnie_tu_123.txt");
    
    
    std::cout << "Success! System survived the missing file test.\n";
    std::cout << "Loaded visits count from empty file: " << fakeVisits.size() << "\n";

    std::cout << "==========================================\n";
    return 0;
}