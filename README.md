# multipurpose-cli-tool

🚀 **A Modular, High-Performance C++ Command-Line Utility Tool**

[![C++ Version](https://img.shields.io/badge/C%2B%2B-17%2F20-blue.svg?style=flat-square&logo=c%2B%2B)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg?style=flat-square)](https://github.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg?style=flat-square)]()

`multipurpose-cli-tool` is a versatile, lightweight digital Swiss Army knife built from the ground up in modern C++. Designed to streamline developer and power-user workflows, it integrates a suite of text processing, statistical data analysis, and mathematical modeling tools into a single, highly optimized executable.

This project represents the comprehensive capstone for the **Microsoft: Introduction to C++ Programming** course on Coursera, showcasing advanced modular architecture, strict input validation, and user-centric console design.

---

## 🏗️ Architecture & Project Structure

The codebase strictly adheres to standard C++ multi-file structural conventions to ensure a clean separation of concerns, easier testing, and effortless maintainability.

```text
multipurpose-cli-tool/
├── Include/
│   └── Utility.h       # Centralized header containing definitions, structs, and interfaces
├── Source/
│   ├── Main.cpp        # Entry point, core UI execution loop, and user menu routing
│   └── Utility.cpp     # Explicit concrete implementation of core sub-system functions
├── LICENSE             # MIT License file
└── README.md           # Project documentation