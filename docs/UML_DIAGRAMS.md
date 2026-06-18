# Diagramy Klas UML Systemu S_Z_P_M

Poniższy diagram przedstawia strukturę klas systemu zarządzania placówką medyczną, odwzorowując powiązania pomiędzy modelami danych, usługami biznesowymi a interfejsem użytkownika.

## 1. Kod Diagramu Klas (PlantUML)

```plantuml
@startuml
skinparam classAttributeIconSize 0

package "Models" {
    class Patient {
        - id: int
        - firstName: string
        - lastName: string
        - pesel: string
        + getFirstName(): string
        + getLastName(): string
        + getPesel(): string
        + setFirstName(name: string): void
        + setLastName(name: string): void
    }

    class Doctor {
        - id: int
        - firstName: string
        - lastName: string
        - specialization: string
        + getFirstName(): string
        + getLastName(): string
        + getSpecialization(): string
    }

    class Visit {
        - id: int
        - patientId: int
        - doctorId: int
        - date: string
        + getPatientId(): int
        + getDoctorId(): int
        + getDate(): string
    }
}

package "Services" {
    class PatientService {
        + addPatient(p: Patient): void
        + removePatient(id: int): bool
        + searchPatientById(id: int): Patient*
        + displayPatients(): void
    }

    class DoctorService {
        + addDoctor(d: Doctor): void
        + searchDoctorById(id: int): Doctor*
        + displayDoctors(): void
    }

    class VisitService {
        + addVisit(v: Visit): void
        + removeVisit(id: int): bool
        + searchVisitById(id: int): Visit*
        + displayVisits(): void
        + canCreateVisit(pId: int, dId: int, ps: PatientService, ds: DoctorService): bool
        + isDoctorAvailable(dId: int, date: string): bool
    }
}

package "UI" {
    class MenuUI {
        - patientService: PatientService&
        - doctorService: DoctorService&
        - visitService: VisitService&
        + MenuUI(ps: PatientService&, ds: DoctorService&, vs: VisitService&)
        + run(): void
        - handlePatientMenu(): void
        - handleDoctorMenu(): void
        - handleVisitMenu(): void
        - addNewPatient(): void
        - addNewVisit(): void
        - clearInputBuffer(): void
    }
}

package "Utils" {
    class Validator {
        {static} + isValidName(name: string): bool
        {static} + isValidPesel(pesel: string): bool
        {static} + isValidDate(date: string): bool
    }
}

MenuUI --> PatientService : używa
MenuUI --> DoctorService : używa
MenuUI --> VisitService : używa

PatientService "1" *-- "wiele" Patient : przechowuje
DoctorService "1" *-- "wiele" Doctor : przechowuje
VisitService "1" *-- "wiele" Visit : przechowuje

MenuUI ..> Validator : wywołuje walidację
@endum