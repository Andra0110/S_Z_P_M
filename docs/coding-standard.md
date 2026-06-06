# Coding Standard

## Naming Conventions

### Classes
Use PascalCase.

Examples:
- Patient
- Doctor
- Visit
- PatientService
- Validator

### Methods
Use camelCase.

Examples:
- addPatient()
- displayPatients()
- searchPatientById()
- removePatient()

### Variables
Use camelCase.

Examples:
- patientService
- firstName
- lastName
- patientId

### Constants
Use UPPER_CASE.

Example:

```cpp
const int MAX_PATIENTS = 1000;
```

---

## File Naming

Each class should have separate header and source files.

Examples:

- Patient.h
- Patient.cpp
- PatientService.h
- PatientService.cpp

---

## Formatting

- Use 4 spaces for indentation.
- Opening braces should be placed on a new line.

Example:

```cpp
if (condition)
{
    doSomething();
}
```

---

## Comments

Use Doxygen comments for:

- classes
- public methods

Example:

```cpp
/**
 * @brief Adds a new patient to the system.
 *
 * @param patient Patient object to add.
 */
void addPatient(const Patient& patient);
```

---

## Includes

Project headers first:

```cpp
#include "PatientService.h"
```

Then standard library headers:

```cpp
#include <iostream>
#include <vector>
```

---

## Namespace Usage

Do not use:

```cpp
using namespace std;
```

Use explicit namespace qualification:

```cpp
std::cout
std::vector
std::string
```

---

## Const Correctness

Use `const` whenever possible.

Examples:

```cpp
void displayPatients() const;
```

```cpp
void addPatient(const Patient& patient);
```

---

## General Rules

- Keep functions short and focused.
- Follow object-oriented programming principles.
- Separate models, services, UI and utility classes.
- Write readable and maintainable code.