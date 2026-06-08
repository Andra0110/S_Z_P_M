#include "FileService.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

/**
 * @brief Saves doctors to a text file.
 */
void FileService::saveDoctors(
    const std::vector<Doctor>& doctors,
    const std::string& filename
)
{
    std::ofstream file(filename);

    for (const auto& doctor : doctors)
    {
        file << doctor.getId()
             << ";"
             << doctor.getFirstName()
             << ";"
             <<doctor.getLastName()
             << ";"
             << doctor.getSpecialization()
             <<"\n";
    }

    file.close();
}

/**
 * @brief Loads doctors from a text file.
 */
std::vector<Doctor> FileService::loadDoctors(
    const std::string& filename
)
{
    std::vector<Doctor> doctors;

    std::ifstream file(filename);

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string firstName;
        std::string lastName;
        std::string specialization;

        std::getline(ss, idStr, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, specialization, ',');

        Doctor doctor(
            std::stoi(idStr),
            firstName,
            lastName,
            specialization
        );

        doctors.push_back(doctor);
    }

    return doctors;
}

/**
 * @brief Saves visits to a text file.
 */
void FileService::saveVisits(
    const std::vector<Visit>& visits,
    const std::string& filename
)
{
    std::ofstream file(filename);

    for (const auto& visit : visits)
    {
        file << visit.getId()
             << ";"
             << visit.getPatientId()
             << ";"
             << visit.getDoctorId()
             << ";"
             << visit.getDate()
             << "\n";
    }

    file.close();
}

/**
 * @brief Loads visits from a text file.
 */
std::vector<Visit> FileService::loadVisits(
    const std::string& filename
)
{
    std::vector<Visit> visits;

    std::ifstream file(filename);

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string patientIdStr;
        std::string doctorIdStr;
        std::string date;

        std::getline(ss, idStr, ';');
        std::getline(ss, patientIdStr, ';');
        std::getline(ss, doctorIdStr, ';');
        std::getline(ss, date, ';');

        Visit visit
        (
            std::stoi(idStr),
            std::stoi(patientIdStr),
            std::stoi(doctorIdStr),
            date
        );

        visits.push_back(visit);
    }

    return visits;
}