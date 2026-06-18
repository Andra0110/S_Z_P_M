# Dokumentacja Poprawy UX Terminala (#50)

W ramach ulepszenia interfejsu konsolowego aplikacji (UX - User Experience) wprowadzono szereg zabezpieczeń eliminujących podatności na błędne akcje użytkownika.

## Zastosowane rozwiązania:

1. **Odporność na błędy strumienia wejściowego (Input Crash Protection):**
   * Zastosowano metodę `MenuUI::clearInputBuffer()`.
   * W przypadku wprowadzenia znaków tekstowych w pola oczekujące liczb (np. wybór opcji menu, ID pacjenta), program nie wpada w nieskończoną pętlę, lecz automatycznie resetuje flagi błędów strumienia poprzez `std::cin.clear()` oraz czyści bufor przy użyciu `std::cin.ignore()`.

2. **Walidacja danych w czasie rzeczywistym:**
   * Wykorzystano szablon metody `MenuUI::getValidatedInput()`, przyjmujący wskaźnik na funkcję walidującą z klasy `Validator`.
   * Aplikacja zmusza użytkownika do poprawy danych bezpośrednio przy ich wprowadzaniu – błędny PESEL (brak 11 cyfr) lub imię zawierające cyfry są natychmiast odrzucane z komunikatem: `Error: Invalid data format! Please try again.`.

3. **Czytelność komunikatów:**
   * Wprowadzono ujednolicone tagi informacyjne dla personelu medycznego w konsoli: `[SUCCESS]`, `[ERROR]` oraz `[INFO]`.