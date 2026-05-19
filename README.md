# multipurpose-cli-tool

A modular C++ command-line utility program with an interactive menu.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey)]()
[![Build](https://img.shields.io/badge/build-Makefile-1f6feb.svg)]()

## Features

- **Interactive main menu** — numbered options, input validation, graceful exit
- **Basic calculator** — addition, subtraction, multiplication, and division on two numbers, with division-by-zero protection
- **Modular layout** — separate header (`Include/`), entry point (`Source/Main.cpp`), and utility implementations (`Source/Utility.cpp`)
- Additional utilities (menu slots 2–4) are reserved for future implementation

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
2. [Second Utility Function]
3. [Third Utility Function]
4. [Fourth Utility Function]
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
| `make clean` | Remove object files and the binary |

### Build without Make

```bash
g++ -std=c++17 -Wall -Wextra -IInclude Source/Main.cpp Source/Utility.cpp -o multipurpose-cli-tool
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
│   └── Utility.h          # Utility function declarations
├── Source/
│   ├── Main.cpp           # Entry point, menu loop, routing
│   └── Utility.cpp        # Utility implementations
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

## License

This project is licensed under the [MIT License](LICENSE).
