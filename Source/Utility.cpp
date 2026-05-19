#include "../Include/Utility.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <string>

namespace {

bool getValidNumber(const char* prompt, double& num) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> num) {
            return true;
        }

        if (std::cin.eof()) {
            std::cout << "Error: input ended unexpectedly.\n";
            return false;
        }

        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

char getValidOperation() {
    char operation = '\0';

    while (true) {
        std::cout << "Enter the operation (+, -, *, /): ";
        if (!(std::cin >> operation)) {
            if (std::cin.eof()) {
                std::cout << "Error: input ended unexpectedly.\n";
                return '\0';
            }

            std::cout << "Invalid input. Please enter an operation (+, -, *, /): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return operation;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid operation. Please use +, -, *, or /.\n";
    }
}

size_t countWords(const std::string& text) {
    size_t count = 0;
    bool inWord = false;

    for (char ch : text) {
        if (std::isspace(static_cast<unsigned char>(ch))) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            ++count;
        }
    }

    return count;
}

size_t countCharactersWithoutSpaces(const std::string& text) {
    size_t count = 0;

    for (char ch : text) {
        if (!std::isspace(static_cast<unsigned char>(ch))) {
            ++count;
        }
    }

    return count;
}

}  // namespace

void basicCalculator() {
    std::cout << "\n===== BASIC CALCULATOR =====\n";
    std::cout << "Perform addition, subtraction, multiplication, or division on two numbers.\n";
    std::cout << "Supported operations: +  -  *  /\n\n";

    double first = 0.0;
    double second = 0.0;

    if (!getValidNumber("Enter the first number: ", first) ||
        !getValidNumber("Enter the second number: ", second)) {
        return;
    }

    const char operation = getValidOperation();

    if (operation == '\0') {
        return;
    }

    if (operation == '/') {
        while (second == 0.0) {
            std::cout << "Error: division by zero is not allowed.\n";
            if (!getValidNumber("Enter a non-zero divisor: ", second)) {
                return;
            }
        }
    }

    double result = 0.0;
    bool success = true;

    switch (operation) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            result = first / second;
            break;
        default:
            success = false;
            break;
    }

    if (success) {
        std::cout << first << " " << operation << " " << second << " = " << result << '\n';
    }
}

void wordCounter() {
    std::cout << "\n===== WORD COUNTER =====\n";
    std::cout << "Count words, characters, and lines in your text.\n";
    std::cout << "Enter one or more lines, then press Enter on an empty line to finish.\n\n";

    // Discard newline left in the buffer after the menu choice (cin >> choice).
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string text;
    size_t lineCount = 0;

    while (text.empty()) {
        std::string line;
        lineCount = 0;

        while (true) {
            if (!std::getline(std::cin, line)) {
                std::cin.clear();
                std::cout << "Error: could not read input.\n";
                return;
            }

            if (line.empty()) {
                break;
            }

            if (!text.empty()) {
                text += '\n';
            }
            text += line;
            ++lineCount;
        }

        if (text.empty()) {
            std::cout << "No text entered. Please enter at least one line of text.\n\n";
        }
    }

    const size_t words = countWords(text);
    const size_t charsWithSpaces = text.size();
    const size_t charsWithoutSpaces = countCharactersWithoutSpaces(text);

    std::cout << "\n--- Results ---\n";
    std::cout << "Lines:                      " << lineCount << '\n';
    std::cout << "Words:                      " << words << '\n';
    std::cout << "Characters (with spaces):   " << charsWithSpaces << '\n';
    std::cout << "Characters (without spaces): " << charsWithoutSpaces << '\n';
}


void fourthUtility() {
    std::cout << "[Fourth Utility Function] — not implemented yet.\n";
}
