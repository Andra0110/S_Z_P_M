#pragma once

#include <vector>
#include "../models/Patient.h"

class PatientService
{
    private:
        std::vector<Patient> patients;

    public:
        void addPatient(const Patient& patient);
        void displayPatients() const;
};