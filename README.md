# S_Z_P_M
System zarządzania przychodnią medyczną. Projekt aplikacji konsolowej w języku C++.

## Opis projektu
Aplikacja została zaprojektowana w celu usprawnienia pracy w przychodni poprzez cyfryzację bazy danych pacjentów, lekarzy oraz terminarza wizyt. System wspiera relacje między lekarzami a pacjentami oraz dba o unikanie konfliktów terminów.

## Architektura systemu
Projekt opiera się na architekturze modułowej, co zapewnia łatwe utrzymanie kodu:
* **Models**: Definicje obiektów (Pacjent, Lekarz, Wizyta).
* **Services**: Logika biznesowa odpowiadająca za walidację i zarządzanie danymi.
* **UI**: Interfejs konsolowy odpowiadający za komunikację z użytkownikiem.
* **Persistence**: Moduł odpowiedzialny za trwały zapis danych do plików CSV/TXT.

## Instrukcja użytkowania
1. Uruchom program korzystając z dołączonego skryptu kompilacji.
2. Nawiguj po menu głównym, wpisując odpowiednie cyfry.
3. Wymagany format daty wizyty: `YYYY-MM-DD HH:MM` (np. 2026-06-20 10:00).
4. System automatycznie sprawdza istnienie pacjenta i lekarza przed utworzeniem wizyty.

## Instrukcja pobierania aplikacji
Aby pobrać najnowszą, stabilną wersję kodu źródłowego, należy otworzyć terminal (Wiersz poleceń / PowerShell / Terminal Mac) i wykonać polecenie:
```bash
git clone [https://github.com/Andra0110/S_Z_P_M.git](https://github.com/Andra0110/S_Z_P_M.git)
cd S_Z_P_M
```

## Instrukcja kompilacji
W zależności od używanego systemu operacyjnego, wykonaj poniższe polecenie w terminalu, upewniając się, że jesteś w **głównym katalogu projektu** (tam, gdzie znajduje się folder `src`).

### Windows (PowerShell)
```powershell
g++ -std=c++17 src/main.cpp src/models/*.cpp src/services/*.cpp src/ui/*.cpp src/tests/*.cpp src/utils/*.cpp -o program.exe; .\program.exe
```

### MacOS (Terminal)
```terminal
clang++ -std=c++17 -g src/main.cpp src/models/*.cpp src/services/*.cpp src/tests/*.cpp src/utils/*.cpp src/ui/*.cpp -o src/main_mac
./src/main_mac
```


## Wymagania
* Kompilator C++ wspierający standard C++17 (np. GCC, MinGW, Clang).
* Środowisko z obsługą terminala (Windows PowerShell, Terminal macOS/Linux).

## Autorzy
* Ania
* Wiktoria
* Patrycja

## Licencja
Projekt stworzony na potrzeby edukacyjne. Wszelkie prawa zastrzeżone.