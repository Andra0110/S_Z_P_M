#include <iostream>
#include <vector>

#include "VisitTests.h"

#include "../models/Patient.h"
#include "../models/Doctor.h"
#include "../models/Visit.h"

#include "../services/FileService.h"
#include "../utils/Validator.h"

void testVisits(
    PatientService& patientService,
    DoctorService& doctorService,
    VisitService& visitService
)
    {
    std::cout << "\nVisit test:\n";


    Visit visit1(
        1,
        1,
        1,
        "2026-06-15 14:00"
    );

    Visit visit2(
        2,
        1,
        1,
        "2026-06-20 10:00"
    );

    std::cout << "\nVisit validation test:\n";

    bool validVisit =
        visitService.canCreateVisit(
            visit1.getPatientId(),
            visit1.getDoctorId(),
            patientService,
            doctorService
        );

        if (validVisit)
        {
            std::cout <<"Visit can be created."
                    << std::endl; 
        }
        else
        {
            std::cout <<"Invalid patient or doctor."
                    << std::endl;
        }

    std::cout << "\nInvalid visit validation test:\n";

    Visit invalidVisit(
        2,
        999,
        888,
        "2026-06-20 12:00"
    );

    bool invalidResult =
        visitService.canCreateVisit(
            invalidVisit.getPatientId(),
            invalidVisit.getDoctorId(),
            patientService,
            doctorService
    );
        if (invalidResult)
        {
            std::cout << "Visit can be created."
                    << std::endl;
        }
        else
        {
            std::cout << "Invalid patient or doctor."
                    << std::endl;
        }

    std::cout << "Visit ID: "
            << visit1.getId()
            << std::endl;

    std::cout << "Patient ID: "
            << visit1.getPatientId()
            << std::endl;

    std::cout << "Doctor ID: "
            << visit1.getDoctorId()
            << std::endl;

    std::cout << "Date: "
            << visit1.getDate()
            << std::endl;


    std::cout << "\n=== VISIT TESTS ===\n";

    std::cout << "\nVisitService test:\n";

    visitService.addVisit(visit1);
    visitService.addVisit(visit2);

    FileService::saveVisits(
        visitService.getVisits(),
        "data/visits.txt"
    );

    std::cout << "\nConflict test:\n";

    bool available = visitService.isDoctorAvailable(
        1,
        "2026-06-15 14:00"
    );

    if (available)
    {
        std::cout << "Doctor is available."
                << std::endl;
    }
    else
    {
        std::cout << "Conflict detected."
                << std::endl;
    }

    std::cout << "\nAll visits:\n";

    visitService.displayVisits();

    std::cout
        << "\nVisits for patient ID 1:\n";

    visitService.displayVisitsByPatient(1);

    std::cout
        << "\nVisits for doctor ID 1:\n";

    visitService.displayVisitsByDoctor(1);

    Visit* foundVisit =
        visitService.searchVisitById(1);

    if (foundVisit != nullptr)
    {
        std::cout << "\nVisit found: "
                << foundVisit->getDate()
                << std::endl;

    std::cout << "\nDetailed visit information:\n";

    Patient* visitPatient =
        patientService.searchPatientById(
            visit1.getPatientId()
        );

    Doctor* visitDoctor =
        doctorService.searchDoctorById(
            visit1.getDoctorId()
        );

    if (
        visitPatient != nullptr &&
        visitDoctor != nullptr
    )
    {
        std::cout << "Visit ID: "
                << visit1.getId()
                << std::endl;

        std::cout << "Patient: "
                << visitPatient->getFirstName()
                << " "
                << visitPatient->getLastName()
                << std::endl;

        std::cout << "Doctor: "
                << visitDoctor->getFirstName()
                << " "
                << visitDoctor->getLastName()
                << std::endl;

        std::cout << "Specialization: "
                << visitDoctor->getSpecialization()
                << std::endl;

        std::cout << "Date: "
                << visit1.getDate()
                << std::endl;
        }
    }


    bool removedVisit =
        visitService.removeVisit(1);

    if (removedVisit)
    {
        std::cout << "Visit removed successfully."
                << std::endl;
    }
    else
    {
        std::cout << "Visit not found."
                << std::endl;
    }

    std::cout << "\nVisits after removal:\n";

    visitService.displayVisits();

    std::cout
        << "\nVisits for patient ID 1 after removal:\n";

    visitService.displayVisitsByPatient(1);


    std::cout << "\nDate validator tests:\n";

    std::cout << Validator::isValidDate(
        "2026-06-15 14:00"
    ) << std::endl;

    std::cout << Validator::isValidDate(
        "15.06.2026"
    ) << std::endl;

    std::cout << Validator::isValidDate(
        "abc"
    ) << std::endl;


    std::cout << "\nLoading patients from file:\n";

    std::vector<Patient> loadedPatients =
        FileService::loadPatients(
            "data/patients.txt"
        );

    for (const auto& patient : loadedPatients)
    {
        std::cout << patient.getId()
                << " "
                << patient.getFirstName()
                << " "
                << patient.getLastName()
                << std::endl;
    }

    std::cout << "\nLoading visits from file:\n";

    std::vector<Visit> loadedVisits =
        FileService::loadVisits(
            "data/visits.txt"
        );

        for (const auto& visit : loadedVisits)
        {
            std::cout << visit.getId()
                    << " "
                    << visit.getPatientId()
                    << " "
                    << visit.getDoctorId()
                    << " "
                    << visit.getDate()
                    << std::endl;
        }
}
