# Dokumentacja Przypadków Użycia (Use Cases) – System S_Z_P_M

**Główny Aktor:** Użytkownik / Pracownik rejestracji przychodni

---

## 1. Wykaz Przypadków Użycia

### Moduł Zarządzania Pacjentami (Patient Module)
* **UC-01: Add New Patient** – System pozwala na wprowadzenie danych osobowych (imię, nazwisko, PESEL, adres) i waliduje poprawność formatu numeru PESEL.
* **UC-02: Search Patient** – Użytkownik może wyszukać zarejestrowanego pacjenta po unikalnym identyfikatorze ID lub numerze PESEL.
* **UC-03: List Patients** – Wygenerowanie pełnego zestawienia wszystkich zarejestrowanych pacjentów w systemie.
* **UC-04: Delete Patient** – Bezpieczne usunięcie kartoteki pacjenta z bazy danych przychodni.

### Moduł Zarządzania Lekarzami (Doctor Module)
* **UC-05: Add New Doctor** – Wprowadzenie nowego lekarza do bazy danych wraz z przypisaniem jego specjalizacji medycznej (Specialty).
* **UC-06: Search Doctor** – Użytkownik może wyszukać lekarza w bazie za pomocą jego unikalnego ID lub filtrując po specjalizacji.
* **UC-07: List Doctors** – Wygenerowanie pełnego wykazu personelu medycznego dostępnego w przychodni.

### Moduł Harmonogramu i Wizyt (Visit Module)
* **UC-08: Book Appointment** – Umówienie pacjenta do wybranego lekarza na konkretną datę i godzinę.
* **UC-09: Validate Schedule Conflicts** – System automatycznie blokuje możliwość zapisania wizyty, jeśli dany lekarz ma już przypisany inny termin w tych samych godzinach.
* **UC-10: View Appointment Schedule** – Podgląd wszystkich zaplanowanych wizyt lekarskich w systemie.
* **UC-11: Cancel Appointment** – Usunięcie wybranej rezerwacji terminu i zwolnienie miejsca dla innych pacjentów.

### Moduł Systemowy i Persystencji (System & Persistence)
* **UC-12: Save Data to Files** – Automatyczny lub wywoływany przez menu eksport aktualnego stanu bazy danych do plików tekstowych CSV.
* **UC-13: Load Data from Files** – Automatyczne ładowanie danych przy uruchomieniu aplikacji, zapewniające ciągłość pracy systemu.
* **UC-14: Input Error Handling (UX)** – System przechwytuje niepoprawne typy danych w terminalu i zapobiega awarii programu.

---

## 2. Szczegółowe Scenariusze Głównych Przypadków Użycia

### UC-01: Add New Patient
* **Warunek wstępny:** Użytkownik znajduje się w menu zarządzania pacjentami (Patient Management Menu).
* **Scenariusz główny (Główny przepływ):**
  1. Użytkownik wybiera opcję "Add Patient" z poziomu menu terminala.
  2. System prosi o podanie danych: First Name, Last Name, PESEL, Address.
  3. Użytkownik wprowadza wymagane dane.
  4. System dokonuje walidacji (sprawdza czy PESEL składa się z dokładnie 11 cyfr).
  5. System generuje unikalne Patient ID, zapisuje obiekt w pamięci i wyświetla angielski komunikat o sukcesie (np. "Patient added successfully!").
* **Scenariusz alternatywny (Błąd walidacji):**
  * 4a. Wprowadzony numer PESEL ma niepoprawną długość lub zawiera litery.
  * 4b. System wyświetla komunikat o błędzie (np. "Invalid PESEL!") i przerywa operację dodawania, wracając do menu.

### UC-08 & UC-09: Book Appointment (z walidacją konfliktów)
* **Warunek wstępny:** Pacjent (Patient) oraz Lekarz (Doctor) istnieją już w bazie danych systemu.
* **Scenariusz główny:**
  1. Użytkownik wybiera opcję "Book Appointment".
  2. System prosi o podanie Patient ID, Doctor ID oraz terminu (date i time).
  3. Użytkownik wprowadza żądane identyfikatory oraz czas wizyty.
  4. System uruchamia algorytm sprawdzania konfliktów w `VisitService` dla kalendarza danego lekarza.
  5. System potwierdza dostępność terminu, tworzy obiekt wizyty i wyświetla komunikat o sukcesie.
* **Scenariusz alternatywny (Konflikt terminów):**
  * 4a. Wybrany lekarz ma już przypisaną inną wizytę w tym samym czasie.
  * 4b. System blokuje operację, wyświetlając komunikat ostrzegawczy o zajętym terminie (np. "Doctor is unavailable at this time!").

### UC-14: Input Error Handling (Zabezpieczenie terminala)
* **Warunek wstępny:** Aplikacja konsolowa oczekuje na wybór opcji z menu (oczekiwany typ: integer).
* **Scenariusz główny:**
  1. System wyświetla listę opcji i czeka na input użytkownika.
  2. Użytkownik wprowadza poprawną cyfrę odpowiadającą opcji z menu.
  3. System przekierowuje użytkownika do właściwego modułu.
* **Scenariusz alternatywny (Wprowadzenie niepoprawnego typu danych):**
  * 2a. Użytkownik przez pomyłkę wprowadza ciąg znaków (np. "abc" zamiast liczby).
  * 2b. System wykrywa błąd strumienia wejściowego (`std::cin.fail()`), czyści flagi błędów, ignoruje niepoprawny tekst (flush stream) i wyświetla komunikat o konieczności podania liczby (np. "Invalid choice, try again!"), zapobiegając zawieszeniu się programu w pętli.