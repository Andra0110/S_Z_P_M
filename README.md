# System Zarządzania Placówką Medyczną (S_Z_P_M)

Projekt realizuje konsolową aplikację do zarządzania placówką medyczną (przychodnią). Umożliwia rejestrację pacjentów, zarządzanie bazą lekarzy oraz kompleksową rezerwację wizyt medycznych z automatycznym sprawdzaniem dostępności terminów.

## 🚀 Główne Funkcjonalności

### 👥 Moduł Pacjentów
* Dodawanie pacjentów z unikalnym identyfikatorem ID.
* Pełna walidacja poprawności danych (imię, nazwisko, 11-cyfrowy PESEL).
* Wyszukiwanie, edycja oraz usuwanie kartotek pacjentów po ich ID.

### 🩺 Moduł Lekarzy
* Rejestracja lekarzy w systemie.
* Wyświetlanie pełnej listy personelu medycznego oraz wyszukiwanie po ID.

### 📅 Moduł Wizyt
* Umawianie wizyt poprzez wiązanie relacji: `Visit ID` + `Patient ID` + `Doctor ID` + `Data`.
* Zabezpieczenie przed rezerwacją wizyty dla nieistniejącego pacjenta lub lekarza.
* Automatyczna weryfikacja dostępności lekarza w wybranym dniu (blokada duplikacji terminów).
* Możliwość odwoływania zaplanowanych wizyt.

---

## 🛠️ Architektura Projektu

Aplikacja została zaprojektowana zgodnie z podziałem na warstwy (gwarantującym czystość kodu i łatwość rozbudowy):

* **Models (Warstwa Danych):** Klasy `Patient`, `Doctor`, `Visit` reprezentujące obiekty biznesowe.
* **Services (Warstwa Logiki):** Klasy `PatientService`, `DoctorService`, `VisitService` odpowiadające za przetwarzanie danych i reguły biznesowe aplikacji.
* **UI (Warstwa Prezentacji):** Klasa `MenuUI` odpowiedzialna za interakcję z użytkownikiem poprzez konsolę.
* **Utils (Narzędzia):** Klasa `Validator` służąca do sprawdzania poprawności wprowadzanych ciągów tekstowych.

---

## 💻 Instrukcja Uruchomienia

Aplikacja uruchamia się bezpośrednio w konsoli systemowej. Przy każdym starcie wykonywane są automatyczne testy integracyjne backendu, weryfikujące poprawność działania modułów.

### Kompilacja (wymagany kompilator zgodny ze standardem C++17/C++20):
```bash
g++ main.cpp src/ui/MenuUI.cpp src/services/PatientService.cpp src/services/DoctorService.cpp src/services/VisitService.cpp -o S_Z_P_M