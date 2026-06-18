# Podsumowanie pracy zespołu – System Zarządzania Przychodnią Medyczną (S_Z_P_M)

## 1. Metryka Projektu
* **Nazwa projektu:** System Zarządzania Przychodnią Medyczną (S_Z_P_M)
* **Język programowania:** C++ (Standard C++17)
* **Skład zespołu:** Patrycja, Wiktoria, Ania
* **Czas realizacji:** Maj – Czerwiec 2026 r.

---

## 2. Szczegółowy podział ról i wkładu w projekt

### Patrycja (Backend Developer / Quality Assurance)
Odpowiedzialna za logikę biznesową, mechanizmy walidacji, stabilność systemu i testowanie.
* **Logika i backend:** Implementacja zaawansowanego terminarza wizyt oraz obsługa błędów strumieni plików (`FileService`).
* **Testowanie (QA):** Przygotowanie i przeprowadzenie testów konfliktów terminów lekarskich, testów walidacji danych oraz testów przypadków skrajnych (*edge case'ów*).
* **Inżynieria i organizacja:** Konfiguracja mechanizmów repozytorium (`.gitignore`), współtworzenie list przypadków użycia (*use case list*), diagramu przepływu oraz dokumentacji technicznej końcowej.

### Wiktoria (Frontend Developer / UX Designer / Technical Writer)
Odpowiedzialna za interakcję z użytkownikiem, interfejs terminala oraz kompletną dokumentację analityczno-projektową.
* **UI Konsolowe:** Zaprojektowanie i zakodowanie struktury Menu (głównego, wizyt, lekarzy oraz pacjentów), a także implementacja obsługi błędnych danych wejściowych i poprawa UX terminala.
* **Projektowanie systemowe:** Przygotowanie diagramów klas UML oraz graficznych diagramów przepływu programu.
* **Dokumentacja:** Stworzenie instrukcji użytkownika, opisu architektury systemu, specyfikacji rozszerzeń aplikacji, opisu technicznego oraz integracja komentarzy w standardzie Doxygen.

### Ania (Core Backend Developer / DevOps)
Odpowiedzialna za inicjalizację środowiska, strukturę danych aplikacji oraz bazowe operacje CRUD i system persystencji.
* **Inicjalizacja projektu:** Utworzenie repozytorium GitHub, konfiguracja kompilatora `g++`, ustalenie standardu czystego kodu, analiza wymagań systemu oraz podział ról.
* **Baza kodu i CRUD:** Implementacja podstawowych klas domenowych (`Patient`, `Doctor`, `Visit`) oraz powiązanych serwisów logicznych odpowiedzialnych za dodawanie, usuwanie, wyszukiwanie i wyświetlanie danych.
* **Logika operacji i zapis plików:** Kodowanie walidacji dat, weryfikacji konfliktów, przypisywania pacjentów do personelu medycznego oraz implementacja wejściowego odczytu i zapisu danych do plików CSV/TXT.
* **Refaktoryzacja:** Przeprowadzenie gruntownego refaktoru klas oraz ujednolicenie nazewnictwa metod w całym projekcie.

---

## 3. Wnioski i podsumowanie współpracy
Zespół pomyślnie zintegrował wszystkie moduły w stabilnie działającą całość. Dzięki jasnemu podziałowi na warstwę danych (Ania), warstwę prezentacji (Wiktoria) oraz mechanizmy zabezpieczeń i testów (Patrycja), aplikacja cechuje się wysoką modułowością i odpornością na błędy użytkownika. Wszystkie założenia funkcjonalne systemu zostały w pełni zrealizowane.