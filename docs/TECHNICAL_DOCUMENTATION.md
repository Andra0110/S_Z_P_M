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