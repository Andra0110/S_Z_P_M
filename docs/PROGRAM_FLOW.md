# Diagram Przepływu Programu Systemu S_Z_P_M (#15)

Niniejszy dokument przedstawia algorytm działania aplikacji oraz logikę podejmowania decyzji podczas kluczowych operacji systemowych (rejestracja nowej wizyty medycznej).

---

## 1. Wyrenderowany Schemat Blokowy (Główny Przepływ)

```mermaid
graph TD
    A([Start Aplikacji]) --> B[Inicjalizacja Serwisów i Ładowanie Danych z Plików]
    B --> C[Uruchomienie Pętli Głównej MenuUI]
    C --> D{Użytkownik wybiera opcję}
    
    D -->|1| E[Zarządzanie Pacjentami]
    D -->|2| F[Zarządzanie Lekarzami]
    D -->|3| G[Zarządzanie Wizytami]
    D -->|0| H([Koniec Programu i Zamknięcie Strumieni])

    E --> C
    F --> C
    
    G --> I[Wybór: Rejestracja nowej wizyty]
    I --> J[Pobranie Custom Visit ID, Patient ID, Doctor ID]
    J --> K[Pobranie i Walidacja Daty/Godziny]
    K --> L{Czy Pacjent i Lekarz istnieją?}
    
    L -->|Nie| M[Wyświetl błąd: Brak encji]
    M --> C
    
    L -->|Tak| N{Czy Lekarz jest dostępny w tym terminie?}
    
    N -->|Nie| O[Wyświetl błąd: Konflikt terminów]
    O --> C
    
    N -->|Tak| P[Utworzenie obiektu Visit]
    P --> Q[Zapis wizyty do pamięci i pliku bazy danych]
    Q --> R[Wyświetlenie komunikatu o sukcesie]
    R --> C