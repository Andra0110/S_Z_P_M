#include "PatientService.h"
#include <iostream>
#include <fstream>  // Potrzebne do obsługi plików (ifstream, ofstream)
#include <sstream>  // Potrzebne do rozbijania tekstu (stringstream)

/**
 * @brief Adds a new patient to the system.
 *
 * @param patient Patient object to add.
 */
void PatientService::addPatient(const Patient& patient)
{
    patients.push_back(patient);
    saveToFile(); // Automatyczny zapis po dodaniu pacjenta
}

/**
 * @brief Displays all patients stored in the system.
 */
void PatientService::displayPatients() const
{
    if (patients.empty())
    {
        std::cout << "The patient registry is empty.\n";
        return;
    }

    for (const auto& patient : patients)
    {
        std::cout << "ID: " 
                  << patient.getId()
                  << "\n";

        std::cout << "First name: "
                  << patient.getFirstName()
                  << "\n";

        std::cout << "Last name: "
                  << patient.getLastName()
                  << "\n";

        std::cout << "PESEL: "
                  << patient.getPesel()
                  << "\n";
                  
        std::cout << std::endl; // Pusta linia odstępu między pacjentami
    }
}

/**
 * @brief Searches patient by ID.
 *
 * @param id Patient identifier.
 * @return Patient* Pointer to found patient.
 * @return nullptr If patient was not found.
 */
Patient* PatientService::searchPatientById(int id)
{
    for (auto& patient : patients)
    {
        if (patient.getId() == id)
        {
            return &patient;
        }
    }

    return nullptr;
}

/**
 * @brief Removes patient by ID.
 *
 * @param id Patient identifier.
 * @return true If patient was removed.
 * @return false If patient was not found.
 */
bool PatientService::removePatient(int id)
{
    for (auto it = patients.begin(); it != patients.end(); )
    {
        if (it->getId() == id)
        {
            it = patients.erase(it); // Bezpieczne usunięcie elementu z wektora
            saveToFile();            // Automatyczny zapis po usunięciu pacjenta
            return true;
        }
        else
        {
            ++it;
        }
    }

    return false;
}

/**
 * @brief Gets all patients.
 *
 * @return const std::vector<Patient>& List of patients.
 */
const std::vector<Patient>& PatientService::getPatients() const
{
    return patients;
}

// =========================================================================
// === PERSISTENCE LAYER IMPLEMENTATION (ZAPIS / ODCZYT PLIKÓW CSV) ===
// =========================================================================

/**
 * @brief Zapisuje wszystkich pacjentów z pamięci RAM do pliku CSV.
 */
void PatientService::saveToFile() const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cout << "[Błąd zapisu] Nie można otworzyć pliku bazy danych: " << filename << "\n";
        return;
    }

    // Mapujemy obiekty z wektora na linie tekstu rozdzielone średnikami
    for (const auto& patient : patients)
    {
        file << patient.getId() << ";"
             << patient.getFirstName() << ";"
             << patient.getLastName() << ";"
             << patient.getPesel() << "\n";
    }

    file.close();
}

/**
 * @brief Wczytuje pacjentów z pliku CSV i umieszcza ich w wektorze.
 */
void PatientService::loadFromFile()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // Brak pliku przy pierwszym uruchomieniu programu to normalna sprawa,
        // dlatego po prostu przerywamy funkcję bez wyrzucania błędu.
        return;
    }

    patients.clear(); // Czyszczenie pamięci przed wczytaniem, zabezpiecza przed duplikacją
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string idStr, firstName, lastName, pesel;

        // Parsowanie linii tekstu według średnika (separator CSV)
        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, firstName, ';') &&
            std::getline(ss, lastName, ';') &&
            std::getline(ss, pesel, ';'))
        {
            try 
            {
                int id = std::stoi(idStr); // Bezpieczna konwersja string na int
                Patient patient(id, firstName, lastName, pesel);
                patients.push_back(patient);
            }
            catch (...) 
            {
                // Ignorujemy uszkodzone lub ręcznie zmodyfikowane linie w pliku tekstowym
                continue;
            }
        }
    }

    file.close();
}