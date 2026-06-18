# Harmonogram Projektu – System Zarządzania Przychodnią Medyczną (S_Z_P_M)

Poniższy harmonogram przedstawia chronologiczny przebieg prac nad systemem, podzielony na tygodniowe sprinty realizowane przez zespół w okresie maj – czerwiec 2026 roku.

---

## Tydzień 1: Inicjalizacja projektu, analiza i struktura (18.05.2026 – 24.05.2026)
* **Analiza wymagań i projekt systemu:** Określenie głównych funkcjonalności MVP systemu przychodni medycznej (Ania).
* **Konfiguracja środowiska:** Stworzenie repozytorium GitHub, konfiguracja kompilatora `g++` oraz pliku `.gitignore` (Ania, Patrycja).
* **Architektura danych:** Utworzenie struktury folderów projektu (`src`, `docs`, `data`) oraz opracowanie pierwszych diagramów klas UML i bazy przypadków użycia (Ania, Wiktoria).

## Tydzień 2: Implementacja rdzenia systemu i CRUD (25.05.2026 – 31.05.2026)
* **Moduł Pacjentów:** Stworzenie klasy `Patient`, serwisu `PatientService` oraz podstawowych operacji: dodawanie, usuwanie, wyszukiwanie i wyświetlanie pacjentów (Ania).
* **Moduł Lekarzy:** Implementacja klasy `Doctor`, obsługa specjalizacji medycznych oraz list lekarzy (Ania).
* **Zapis danych (Persistence):** Wdrożenie mechanizmów wejściowego zapisu i odczytu baz danych lekarzy oraz pacjentów do plików tekstowych/CSV (Ania).
* **Zapewnienie jakości:** Przygotowanie testów jednostkowych dla walidacji danych pacjenta oraz testów edge case'ów (Patrycja).

## Tydzień 3: Logika wizyt i Interfejs Użytkownika (01.06.2026 – 07.06.2026)
* **Moduł Wizyt (Core Logic):** Stworzenie klasy `Visit`, algorytmów sprawdzania konfliktów terminów, weryfikacji dat oraz przypisywania pacjentów do lekarzy (Ania).
* **Rozbudowa terminarza:** Implementacja zaawansowanego mechanizmu blokowania nakładających się wizyt oraz anulowania rezerwacji (Patrycja).
* **Interfejs Użytkownika:** Zaprojektowanie i zakodowanie pełnego menu konsolowego (menu główne, pacjenci, lekarze, wizyty) oraz diagramu przepływu ekranów (Wiktoria).
* **Obsługa wejścia:** Wdrożenie odporności na błędne inputy użytkownika i poprawa komunikacji błędów w terminalu (Wiktoria).

## Tydzień 4: Refaktoryzacja, stabilizacja i dokumentacja (08.06.2026 – 18.06.2026)
* **Refaktoryzacja i poprawki:** Optymalizacja nazw metod, ujednolicenie struktury klas oraz naprawa błędów strumieni plików i obsługi wyjątków w `FileService` (Ania, Patrycja).
* **UX i Testy integracyjne:** Finalne szlifowanie wyglądu konsoli, dodanie testów automatycznych dla konfliktów terminów oraz walidacji końcowych (Wiktoria, Patrycja).
* **Dokumentacja końcowa:** Przygotowanie instrukcji użytkownika, opisu architektury, opisu rozszerzeń aplikacji oraz integracja komentarzy Doxygen w kodzie źródłowym (Wiktoria, Patrycja).
* **Domykanie kamieni milowych:** Wygenerowanie podsumowania prac zespołu, przygotowanie harmonogramu oraz synchronizacja wersji końcowej z repozytorium (Patrycja).