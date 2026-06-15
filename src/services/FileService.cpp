#include "FileService.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Saves patients to a text file.
 *
 * @param patients Vector of patients.
 * @param filename Output file name.
 */
void FileService::savePatients(
    const std::vector<Patient>& patients,
    const std::string& filename
)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

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
 *
 * @param filename Input file name.
 * @return std::vector<Patient> Loaded patients.
 */
std::vector<Patient> FileService::loadPatients(
    const std::string& filename
)
{
    std::vector<Patient> patients;
    std::ifstream file(filename);
    
    if (!file.is_open())
    {
        return patients; // Zwraca pusty wektor, jeśli plik nie istnieje
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue; // Pomija puste linie

        std::stringstream ss(line);

        std::string idStr;
        std::string firstName;
        std::string lastName;
        std::string pesel;

        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, firstName, ';') &&
            std::getline(ss, lastName, ';') &&
            std::getline(ss, pesel, ';'))
        {
            try
            {
                Patient patient(
                    std::stoi(idStr),
                    firstName,
                    lastName,
                    pesel
                );
                patients.push_back(patient);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error parsing patient data: " << e.what() << "\n";
            }
        }
    }

    file.close();
    return patients;
}

/**
 * @brief Saves doctors to a text file.
 *
 * @param doctors Vector of doctors.
 * @param filename Output file name.
 */
void FileService::saveDoctors(
    const std::vector<Doctor>& doctors,
    const std::string& filename
)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    for (const auto& doctor : doctors)
    {
        file << doctor.getId()
             << ";"
             << doctor.getFirstName()
             << ";"
             << doctor.getLastName()
             << ";"
             << doctor.getSpecialization()
             << "\n";
    }

    file.close();
}

/**
 * @brief Loads doctors from a text file.
 *
 * @param filename Input file name.
 * @return std::vector<Doctor> Loaded doctors.
 */
std::vector<Doctor> FileService::loadDoctors(
    const std::string& filename
)
{
    std::vector<Doctor> doctors;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return doctors;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);

        std::string idStr;
        std::string firstName;
        std::string lastName;
        std::string specialization;

        // POPRAWIONE: Zmiana ',' na ';' w celu zachowania spójności z zapisem
        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, firstName, ';') &&
            std::getline(ss, lastName, ';') &&
            std::getline(ss, specialization, ';'))
        {
            try
            {
                Doctor doctor(
                    std::stoi(idStr),
                    firstName,
                    lastName,
                    specialization
                );
                doctors.push_back(doctor);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error parsing doctor data: " << e.what() << "\n";
            }
        }
    }

    file.close();
    return doctors;
}

/**
 * @brief Saves visits to a text file.
 *
 * @param visits Vector of visits.
 * @param filename Output file name.
 */
void FileService::saveVisits(
    const std::vector<Visit>& visits,
    const std::string& filename
)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

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
 *
 * @param filename Input file name.
 * @return std::vector<Visit> Loaded visits.
 */
std::vector<Visit> FileService::loadVisits(
    const std::string& filename
)
{
    std::vector<Visit> visits;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return visits;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);

        std::string idStr;
        std::string patientIdStr;
        std::string doctorIdStr;
        std::string date;

        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, patientIdStr, ';') &&
            std::getline(ss, doctorIdStr, ';') &&
            std::getline(ss, date, ';'))
        {
            try
            {
                Visit visit(
                    std::stoi(idStr),
                    std::stoi(patientIdStr),
                    std::stoi(doctorIdStr),
                    date
                );
                visits.push_back(visit);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error parsing visit data: " << e.what() << "\n";
            }
        }
    }

    file.close();
    return visits;
}