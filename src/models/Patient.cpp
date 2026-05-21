#include "Patient.h"

Patient::Patient(int id,
            const std::string& firstName,
            const std::string& lastName,
            const std::string& pesel)

        : id(id),
            firstName(firstName),
            lastName(lastName),
            pesel(pesel)

{
}

int Patient::getId() const
{
    return id;
}

std::string Patient::getFirstName() const
{
    return firstName;
}

std::string Patient::getLastName() const
{
    return lastName;
}

std::string Patient::getPesel() const
{
    return pesel;
}