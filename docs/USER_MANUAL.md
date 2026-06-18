# Instrukcja Użytkownika Systemu Medycznego S_Z_P_M (#52)

Dokument zawiera szczegółowy opis funkcjonalny konsolowej aplikacji klinicznej służącej do zarządzania placówką medyczną (S_Z_P_M).

---

## 1. Uruchomienie programu i tryby pracy

Aplikację można uruchomić na dwa sposoby w zależności od potrzeb (weryfikowane w pliku `main.cpp`):

1.  **Tryb Standardowy (Interaktywny):** Uruchomienie pliku wykonywalnego bez dodatkowych parametrów. Inicjalizuje moduł grafiki tekstowej `MenuUI` i pozwala na pracę z systemem.
2.  **Tryb Testowy (Automatyczny):** Uruchomienie programu z poziomu terminala z przekazaniem argumentów startowych (`argc`, `argv`). Uruchamia to automatyczne testy jednostkowe modułów:
    *   `PatientTests`
    *   `DoctorTests`
    *   `VisitTests`

---

## 2. Szczegółowy Przewodnik po Menu Głównym (`MenuUI`)

Nawigacja po systemie opiera się na wprowadzaniu cyfr w konsoli i zatwierdzaniu klawiszem **Enter**.

### Moduł 1: Zarządzanie Pacjentami (`PatientService`)
Po wybraniu opcji zarządzania pacjentami system umożliwia:
*   **Dodanie nowego pacjenta:** Wymaga podania imienia, nazwiska oraz numeru PESEL. Dane są automatycznie walidowane i zapisywane w pliku `data/patients.txt`.
*   **Wyszukiwanie:** Pozwala odnaleźć kartotekę pacjenta w bazie na podstawie jego unikalnego identyfikatora lub numeru PESEL.

### Moduł 2: Ewidencja Lekarzy (`DoctorService`)
*   Umożliwia wyświetlenie pełnej listy lekarzy zaimportowanej z pliku `data/doctors.txt`.
*   Każdy lekarz opisany jest identyfikatorem (ID), imieniem, nazwiskiem oraz przypisaną specjalizacją medyczną.

### Moduł 3: Harmonogram Wizyt (`VisitService`)
*   **Rejestracja wizyty:** Użytkownik podaje ID pacjenta oraz ID lekarza, a system kojarzy te encje i zapisuje nową wizytę w pliku `data/visits.txt`.

---

## 3. Walidacja Danych i Bezpieczeństwo (UX)

System posiada wbudowane mechanizmy odporności na błędy ludzkie (Input Crash Protection):
1.  **Format PESEL:** Wprowadzenie wartości innej niż 11 cyfr blokuje operację i wyświetla komunikat: `Error: Invalid data format! Please try again.`.
2.  **Ochrona przed zawieszeniem:** Wpisanie znaków tekstowych (liter) w miejscach, gdzie system oczekuje liczb (np. wybór opcji w menu), skutkuje wyczyszczeniem bufora `std::cin` i ponownym wyświetleniem menu, zamiast awarii programu.
