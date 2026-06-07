#include "FileService.h"

#include <fstream>

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