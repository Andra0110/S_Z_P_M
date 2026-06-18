# Opis Architektury Projektu S_Z_P_M (#53)

Niniejszy dokument zawiera szczegółowy opis struktury architektonicznej konsolowego systemu zarządzania placówką medyczną S_Z_P_M. Projekt został podzielony na dedykowane pakiety/foldery w celu odseparowania odpowiedzialności logicznych.

---

## 1. Drzewo Struktury Projektu

Projekt porządkuje kod źródłowy wewnątrz katalogu `src/` według następującego schematu:

```text
S_Z_P_M/
├── docs/                 # Dokumentacja projektowa (.md)
└── src/                  # Główny katalog kodu źródłowego
    ├── models/           # Klasy reprezentujące encje (modele danych)
    ├── services/         # Serwisy realizujące logikę biznesową
    ├── tests/            # Testy automatyczne komponentów
    ├── ui/               # Interfejs użytkownika (grafika tekstowa)
    └── utils/            # Narzędzia pomocnicze (np. walidacja)
```

## 2. Warstwowy Podział Odpowiedzialności (Layered Architecture)
System implementuje architekturę warstwową, w której każdy folder pełni ściśle określoną rolę, a zależności między nimi przepływają jednostronnie (od warstwy prezentacji do danych).

## 2.1. Warstwa Modelu (src/models/)
Zawiera klasy encji: Patient, Doctor oraz Visit.

**Charakterystyka:** Są to tzw. klasy PODO (Plain Old C++ Objects). Przechowują surowe dane w prywatnych polach i udostępniają do nich dostęp za pomocą getterów i setterów.

**Zasada projektowa:** Modele są całkowicie pasywne – nie wiedzą o istnieniu interfejsu użytkownika ani o mechanizmach zapisu do plików.

## 2.2. Warstwa Logiki Biznesowej i Persystencji (src/services/)
Główny mózg aplikacji, składający się z klas: PatientService, DoctorService oraz VisitService.

**Logika biznesowa:** Odpowiada za operacje na danych (np. algorytm sprawdzania dostępności lekarza w danym terminie isDoctorAvailable).

**Zarządzanie pamięcią:** Przechowuje bazy danych w strukturach dynamicznych (std::vector).

**Trwałość danych (I/O):** Odpowiada za serializację i deserializację obiektów do płaskich plików tekstowych CSV (saveToFile, loadFromFile).

## 2.3. Warstwa Prezentacji (src/ui/)
Zaimplementowana w klasie MenuUI.

**Charakterystyka:** Odpowiada za strumień wejścia/wyjścia (std::cin, std::cout). Odrysowuje menu konsolowe, zbiera intencje użytkownika i formatuje komunikaty błędów lub sukcesów za pomocą kodów kolorowania ANSI.

**Wstrzykiwanie zależności (DI):** MenuUI nie tworzy własnych serwisów. Przyjmuje je w konstruktorze przez referencję, co pozwala na pełną kontrolę nad współdzieleniem danych.

## 2.4. Warstwa Narzędziowa i Testowa (src/utils/, src/tests/)

**utils/Validator:** Komponent pomocniczy dostarczający czyste, statyczne funkcje logiczne do walidacji danych przed ich przepuszczeniem do warstwy biznesowej (np. poprawność numerów PESEL, sprawdzanie formatu dat).

**tests/:** Zestaw testów weryfikujących poprawność zachowania pojedynczych modułów bez konieczności manualnego przeklikiwania aplikacji.

## 3. Integracja Modułów i Relacje (Luźne Wiązanie)
Kluczowym elementem architektury modułowej S_Z_P_M jest zastosowanie luźnego wiązania (Loose Coupling) pomiędzy niezależnymi serwisami za pomocą identyfikatorów cyfrowych (ID):

Klasa Visit w warstwie modeli nie przechowuje referencji ani wskaźników do obiektów Patient i Doctor, a jedynie ich numery patientId oraz doctorId.

Gdy zachodzi potrzeba powiązania i walidacji (np. podczas dodawania nowej wizyty), VisitService wchodzi w interakcję z PatientService oraz DoctorService poprzez ich publiczne API (np. metoda searchDoctorById(id)).

Dzięki temu struktury danych są niezależne, a pliki .csv mogą być modyfikowane i odczytywane bez ryzyka wystąpienia błędów pamięciowych (np. wiszących wskaźników).