#pragma once

#include <string>

class Patient
{
    private:
        int id;
        std::string firstName;
        std::string lastName;
        std::string pesel;

    public:
        Patient(int id,
            const std::string& firstName,
            const std::string& lastName,
            const std::string& pesel);
        
        int getId() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getPesel() const;
};