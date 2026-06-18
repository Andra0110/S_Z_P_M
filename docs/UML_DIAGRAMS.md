# Diagramy Klas UML Systemu S_Z_P_M (#14, #54)

Niniejszy dokument przedstawia strukturę obiektową aplikacji oraz relacje pomiędzy poszczególnymi warstwami systemu zarządzania placówką medyczną.

---

## 1. Wyrenderowany Diagram Klas

```mermaid
classDiagram
    class Patient {
        -int id
        -string firstName
        -string lastName
        -string pesel
        +getFirstName() string
        +getLastName() string
        +getPesel() string
        +setFirstName(string name)
        +setLastName(string name)
    }

    class Doctor {
        -int id
        -string firstName
        -string lastName
        -string specialization
        +getFirstName() string
        +getLastName() string
        +getSpecialization() string
    }

    class Visit {
        -int id
        -int patientId
        -int doctorId
        -string date
        +getPatientId() int
        +getDoctorId() int
        +getDate() string
    }

    class PatientService {
        +addPatient(Patient p)
        +removePatient(int id) bool
        +searchPatientById(int id) Patient*
        +displayPatients()
    }

    class DoctorService {
        +addDoctor(Doctor d)
        +searchDoctorById(int id) Doctor*
        +displayDoctors()
    }

    class VisitService {
        +addVisit(Visit v)
        +removeVisit(int id) bool
        +searchVisitById(int id) Visit*
        +displayVisits()
        +canCreateVisit() bool
        +isDoctorAvailable() bool
    }

    class MenuUI {
        -PatientService patientService
        -DoctorService doctorService
        -VisitService visitService
        +run()
    }

    MenuUI --> PatientService : używa
    MenuUI --> DoctorService : używa
    MenuUI --> VisitService : używa
    PatientService "1" *-- "wiele" Patient : przechowuje
    DoctorService "1" *-- "wiele" Doctor : przechowuje
    VisitService "1" *-- "wiele" Visit : przechowuje
    