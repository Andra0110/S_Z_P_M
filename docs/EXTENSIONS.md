# Opis Planowanych Rozszerzeń Systemu S_Z_P_M (#57)

Niniejszy dokument przedstawia analizę możliwości rozwoju aplikacji S_Z_P_M oraz specyfikację techniczną potencjalnych modułów rozszerzających architekturę systemu w przyszłych iteracjach.

---

## 1. Proponowane Kierunki Rozwoju (Rozszerzenia)

### A. Migracja z plików tekstowych do relacyjnej bazy danych (SQL)
* **Opis:** Obecna warstwa serwisowa zapisuje dane w plikach `.txt`/`.csv`. Planowane rozszerzenie zakłada wdrożenie bazy danych SQLite lub PostgreSQL.
* **Wpływ na architekturę:** Dzięki separacji warstw (odpowiedzialność `src/services/`), zmiana mechanizmu zapisu nie wpłynie na kod warstwy prezentacji (`MenuUI`). Wystarczy podmienić implementację metod I/O w serwisach.

### B. System Uprawnień i Logowania (Autentykacja)
* **Opis:** Podział użytkowników systemu na trzy role: `Administrator` (pełny dostęp CRUD), `Lekarz` (podgląd swoich wizyt) oraz `Pacjent` (podgląd historii leczenia i rejestracja).
* **Wpływ na architekturę:** Dodanie nowego modelu `User` w `src/models/` oraz nowego serwisu `AuthService` filtrującego widoki w `MenuUI` na podstawie zalogowanej roli.

### C. Warstwa powiadomień SMS / E-mail
* **Opis:** Automatyczne generowanie powiadomień przypominających o nadchodzącej wizycie po pomyślnym zapisie obiektu `Visit`.
* **Wpływ na architekturę:** Dodanie zewnętrznej biblioteki do obsługi protokołu SMTP/API (np. curl) i wpięcie jej jako niezależnego narzędzia w katalogu `src/utils/`.

---

## 2. Podsumowanie Skalowalności

Dzięki zastosowaniu zasad programowania obiektowego (SOLID) oraz podziałowi projektu na odseparowane katalogi (`models`, `services`, `ui`, `utils`), system S_Z_P_M jest w pełni gotowy na implementację powyższych rozszerzeń bez konieczności przepisywania logiki aplikacji od nowa.