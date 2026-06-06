#pragma once 

#include <string>

/**
 * @class Doctor
 * @brief Represents a doctor in the clinic system.
 */
class Doctor
{
    private:
        int id;
        std::string firstName;
        std::string lastName;
        std::string specialization;

    public:

    /**
     * @brief Constructs a Doctor object.
     *
     * @param id Doctor identifier.
     * @param firstName Doctor first name.
     * @param lastName Doctor last name.
     * @param specialization Doctor specialization.
     */
    Doctor(
        int id,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& specialization
    );

     /**
     * @brief Gets doctor ID.
     *
     * @return int Doctor identifier.
     */
    int getId() const;

    /**
     * @brief Gets doctor's first name.
     *
     * @return std::string First name.
     */
    std::string getFirstName() const;

    /**
     * @brief Gets doctor's last name.
     *
     * @return std::string Last name.
     */
    std::string getLastName() const;

    /**
     * @brief Gets doctor's specialization.
     *
     * @return std::string Specialization.
     */
    std::string getSpecialization() const;
};