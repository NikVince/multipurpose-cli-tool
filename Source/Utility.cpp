#include "../Include/Utility.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <string>

namespace {

bool readDouble(const char* prompt, double& value) {
    std::cout << prompt;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
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

    if (!readDouble("Enter the first number: ", first)) {
        std::cout << "Invalid input. Please enter a valid number.\n";
        return;
    }

    if (!readDouble("Enter the second number: ", second)) {
        std::cout << "Invalid input. Please enter a valid number.\n";
        return;
    }

    std::cout << "Enter the operation (+, -, *, /): ";
    char operation = '\0';
    if (!(std::cin >> operation) || (operation != '+' && operation != '-' &&
                                     operation != '*' && operation != '/')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid operation. Please use +, -, *, or /.\n";
        return;
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
            if (second == 0.0) {
                std::cout << "Error: division by zero is not allowed.\n";
                success = false;
            } else {
                result = first / second;
            }
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
    std::string line;
    size_t lineCount = 0;

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
        std::cout << "No text entered. Nothing to count.\n";
        return;
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

void thirdUtility() {
    std::cout << "[Third Utility Function] — not implemented yet.\n";
}

void fourthUtility() {
    std::cout << "[Fourth Utility Function] — not implemented yet.\n";
}
