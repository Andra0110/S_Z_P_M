# Coding Standard – Clinic Management System

This document defines the coding conventions, formatting rules, and architectural guidelines for the project. All team members must adhere to these standards to ensure code maintainability, readability, and consistency.

---

## 1. Naming Conventions

### 1.1. Classes
* **Rule:** Use `PascalCase`.
* **Examples:** `Patient`, `Doctor`, `Visit`, `PatientService`, `Validator`

### 1.2. Methods
* **Rule:** Use `camelCase`.
* **Examples:** `addPatient()`, `displayPatients()`, `searchPatientById()`, `removePatient()`

### 1.3. Variables
* **Rule:** Use `camelCase`.
* **Examples:** `patientService`, `firstName`, `lastName`, `patientId`

### 1.4. Constants
* **Rule:** Use `UPPER_CASE` with underscores.
* **Example:** `const int MAX_PATIENTS = 1000;`

---

## 2. File Naming & Structure

* **Rule:** Each class must be isolated into its own separate header (`.h`) and source (`.cpp`) files.
* **Examples:**
  * `Patient.h` / `Patient.cpp`
  * `PatientService.h` / `PatientService.cpp`

---

## 3. Formatting & Style

### 3.1. Indentation
* Use **4 spaces** for indentation. Do not use tabs.

### 3.2. Braces
* Opening and closing braces **must** be placed on a new line (Allman style).
* **Example:**
```cpp
if (condition)
{
    doSomething();
}
```

---

## 4. Documentation & Comments

* **Rule:** Use **Doxygen** XML/Javadoc style comments for all classes and public methods.
* **Example:**
```cpp
/**
 * @brief Adds a new patient to the system.
 *
 * @param patient Patient object to add.
 */
void addPatient(const Patient& patient);
```

---

## 5. Includes & Namespaces

### 5.1. Header Include Order
1. Project-specific headers first (e.g., `#include "PatientService.h"`)
2. Standard library headers second (e.g., `#include <iostream>`)

---

### 5.2. Namespace Usage
* **Strictly Prohibited:** `using namespace std;`
* **Requirement:** Use explicit namespace qualification at all times.
* **Examples:** `std::cout`, `std::vector`, `std::string`

---

## 6. Const Correctness

* **Rule:** Enforce `const` correctness wherever possible to ensure data integrity.
* **Examples:**
```cpp
void displayPatients() const;
void addPatient(const Patient& patient);
```

---

## 7. General Architecture Rules

* **Single Responsibility:** Keep functions short, focused, and limited to a single task.
* **OOP Principles:** Closely follow object-oriented programming paradigms (encapsulation, abstraction).
* **Layer Separation:** Maintain a strict logical separation between **Models**, **Services**, **UI**, and **Utility** classes.
* **Code Quality:** Prioritize writing highly readable, self-explanatory, and maintainable code over clever workarounds.

