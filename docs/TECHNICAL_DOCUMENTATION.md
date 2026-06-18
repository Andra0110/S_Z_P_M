# Dokumentacja Techniczna Systemu Medycznego S_Z_P_M (#51)

Niniejszy dokument opisuje architekturę, strukturę modułową oraz mechanizmy kontroli danych konsolowej aplikacji medycznej S_Z_P_M (C++).

---

## 1. Architektura i Podział Odpowiedzialności (`src/`)

Aplikacja została zaimplementowana w architekturze warstwowej z pełną separacją logiki biznesowej od warstwy prezentacji użytkownika:

* **Warstwa Interfejsu (`src/ui/MenuUI`):** Klasa odpowiada za rysowanie menu, pobieranie danych wejściowych z konsoli i obsługę kolorowania interfejsu (kody ANSI).
* **Warstwa Biznesowa (`src/services/`):** Klasy `PatientService`, `DoctorService` oraz `VisitService` zarządzają strukturami danych, kontrolują dostępność zasobów oraz wykonują operacje I/O na plikach bazy danych (`.txt`/`.csv`).
* **Warstwa Narzędziowa (`src/utils/Validator`):** Odpowiada za czystość danych wejściowych poprzez zestaw statycznych funkcji walidujących.

---

## 2. Szczegółowy Opis Implementacji Warstwy Interfejsu (`MenuUI`)

Klasa `MenuUI` jest agregatorem usług biznesowych i wstrzykuje referencje do serwisów poprzez konstruktor:

```cpp
MenuUI(PatientService& pService, DoctorService& dService, VisitService& vService);
src/
│
├── models/             # Warstwa Modelu (Definicje obiektów/encji)
│   ├── Patient.h / .cpp    - Reprezentacja danych pacjenta
│   ├── Doctor.h / .cpp     - Reprezentacja danych lekarza
│   └── Visit.h / .cpp      - Reprezentacja danych wizyty lekarskiej
│
├── services/           # Warstwa Logiki Biznesowej i Persystencji
│   ├── PatientService.h / .cpp  - Zarządzanie wektorem pacjentów, zapis CSV
│   ├── DoctorService.h / .cpp   - Zarządzanie wektorem lekarzy, zapis CSV
│   └── VisitService.h / .cpp    - Koordynacja wizyt, weryfikacja terminów, zapis CSV
│
├── ui/                 # Warstwa Prezentacji (Interfejs użytkownika)
│   └── MenuUI.h / .cpp     - Konsolowe menu, obsługa I/O, interakcja z użytkownikiem
│
├── utils/              # Warstwa Pomocnicza (Narzędziowa)
│   └── Validator.h / .cpp  - Statyczna walidacja danych (PESEL, daty, formaty)
│
└── main.cpp            # Punkt wejścia aplikacji (Inicjalizacja i DI)
classDiagram
    class main {
        +main(argc, argv) int
    }

    class MenuUI {
        -PatientService& patientService
        -DoctorService& doctorService
        -VisitService& visitService
        +displayMainMenu() void
    }

    class VisitService {
        -vector~Visit~ visits
        -string filename
        +addVisit(Visit visit) void
        +canCreateVisit(int pId, int dId, PatientService& ps, DoctorService& ds) bool
        +isDoctorAvailable(int dId, string date) bool
        +saveToFile() void
        +loadFromFile() void
    }

    class PatientService {
        -vector~Patient~ patients
        -string filename
        +searchPatientById(int id) Patient*
        +saveToFile() void
        +loadFromFile() void
    }

    class DoctorService {
        -vector~Doctor~ doctors
        -string filename
        +searchDoctorById(int id) Doctor*
        +saveToFile() void
        +loadFromFile() void
    }

    class Validator {
        <<utility>>
        +validatePESEL(string pesel) bool
        +validateDate(string date) bool
    }

    main --> MenuUI : Inicjalizuje i wstrzykuje zależności
    MenuUI --> PatientService : Wywołuje akcje pacjentów
    MenuUI --> DoctorService : Wywołuje akcje lekarzy
    MenuUI --> VisitService : Wywołuje akcje wizyt
    MenuUI ..> Validator : Waliduje błędy wejścia
    VisitService --> PatientService : Sprawdza istnienie Pacjenta (ID)
    VisitService --> DoctorService : Sprawdza dostępność Lekarza (ID)
    git add docs/TECHNICAL_DOCUMENTATION.md