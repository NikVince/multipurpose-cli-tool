# multipurpose-cli-tool

A modular C++ command-line utility program with an interactive menu. Built as the **Module 1 capstone** for the [Microsoft Introduction to C++ Programming Professional Certificate](https://www.coursera.org/professional-certificates/microsoft-introduction-to-c-plus-plus-programming) on Coursera (not the final capstone for the full four-course program).

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey)]()
[![Build](https://img.shields.io/badge/build-Makefile-1f6feb.svg)]()

## Features

- **Interactive main menu** — numbered options, input validation, graceful exit
- **Basic calculator** — addition, subtraction, multiplication, and division on two numbers, with division-by-zero protection
- **Word counter** — counts lines, words, and characters (with and without spaces) from multi-line text
- **Number base converter** — converts non-negative integers between binary, octal, decimal, and hexadecimal
- **Password strength checker** — scores passwords using length, case, digits, and symbols (input is not stored)
- **Modular layout** — separate headers and sources per utility; core logic covered by unit tests

## Prerequisites

| Requirement | Notes |
|-------------|--------|
| **g++** | GCC 7+ or compatible (Clang `clang++` also works with the manual compile command below) |
| **make** | Optional; recommended for building |
| **Terminal** | Interactive stdin is required for the menu |

Check your compiler:

```bash
g++ --version
```

## Quick start

Clone the repository and build from the project root:

```bash
git clone https://github.com/NikVince/multipurpose-cli-tool.git
cd multipurpose-cli-tool
make
./multipurpose-cli-tool
```

Or build and run in one step:

```bash
make run
```

## Usage

After starting the program, you will see the main menu:

```text
===== UTILITY PROGRAM MENU =====
1. Basic Calculator
2. Word Counter
3. Number Base Converter
4. Password Strength Checker
5. Exit
Enter your choice (1-5):
```

### Basic calculator (option 1)

1. Choose `1` from the main menu.
2. Enter the first number, then the second number.
3. Enter an operation: `+`, `-`, `*`, or `/`.
4. Read the result on screen; the main menu returns automatically.

**Example session**

```text
Enter your choice (1-5): 1

===== BASIC CALCULATOR =====
...
Enter the first number: 10
Enter the second number: 4
Enter the operation (+, -, *, /): /
10 / 4 = 2.5
```

Invalid input (non-numeric values, unknown operators, or division by zero) prints an error message and returns you to the main menu without crashing.

### Exit

Choose `5` to quit the program.

## Build commands

| Command | Description |
|---------|-------------|
| `make` | Compile the project (output: `multipurpose-cli-tool`) |
| `make run` | Build (if needed) and run the executable |
| `make clean` | Remove object files and binaries |
| `make test` | Build and run all unit tests |

### Build without Make

```bash
g++ -std=c++17 -Wall -Wextra -IInclude Source/Main.cpp Source/Utility.cpp Source/BaseConverter.cpp Source/PasswordStrength.cpp -o multipurpose-cli-tool
./multipurpose-cli-tool
```

Compiler flags:

- `-std=c++17` — C++17 standard
- `-Wall -Wextra` — common warnings enabled
- `-IInclude` — header search path for `Utility.h`

## Project structure

```text
multipurpose-cli-tool/
├── Include/
│   ├── Utility.h          # Calculator and word counter declarations
│   ├── BaseConverter.h    # Base conversion API and UI entry point
│   └── PasswordStrength.h # Password analysis API and UI entry point
├── Source/
│   ├── Main.cpp           # Entry point, menu loop, routing
│   ├── Utility.cpp        # Calculator and word counter
│   ├── BaseConverter.cpp  # Base conversion logic and interactive UI
│   └── PasswordStrength.cpp
├── Tests/
│   ├── BaseConverterTest.cpp
│   └── PasswordStrengthTest.cpp
├── Makefile               # Build rules (g++)
├── .gitignore               # Ignores binary and object files
├── LICENSE                  # MIT License
└── README.md
```

## Development

- Add new utility declarations in `Include/Utility.h`.
- Implement logic in `Source/Utility.cpp`.
- Register the option in `displayMenu()` and the `switch` in `Source/Main.cpp`.
- Rebuild with `make` and test interactively in a terminal.
- Run `make test` after changing base conversion or password strength logic.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

Module 1 capstone project for the [Microsoft Introduction to C++ Programming Professional Certificate](https://www.coursera.org/professional-certificates/microsoft-introduction-to-c-plus-plus-programming) on Coursera. The full program includes four courses and separate portfolio projects; this repository covers only the command-line utility assignment from Module 1 of Course 1 (*C++ Programming Fundamentals*).
