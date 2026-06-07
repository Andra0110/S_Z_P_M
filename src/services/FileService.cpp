#include "FileService.h"

#include <fstream>
#include <sstream>
#include <vector>

/**
 * @brief Saves patients to a text file.
 */
void FileService::savePatients(
    const std::vector<Patient>& patients,
    const std::string& filename
)
{
    std::ofstream file(filename);

    for (const auto& patient : patients)
    {
        file << patient.getId()
             << ";"
             << patient.getFirstName()
             << ";"
             << patient.getLastName()
             << ";"
             << patient.getPesel()
             << "\n";
    }

    file.close();
}

/**
 * @brief Loads patients from a text file.
 */
std::vector<Patient> FileService::loadPatients(
    const std::string& filename
)
{
    std::vector<Patient> patients;

    std::ifstream file(filename);

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string firstName;
        std::string lastName;
        std::string pesel;

        std::getline(ss, idStr, ';');
        std::getline(ss, firstName, ';');
        std::getline(ss, lastName, ';');
        std::getline(ss, pesel, ';');

        Patient patient(
            std::stoi(idStr),
            firstName,
            lastName,
            pesel
        );

        patients.push_back(patient);
    }

    return patients;
}