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