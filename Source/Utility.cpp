#include "../Include/Utility.h"

#include <iostream>
#include <limits>

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

void secondUtility() {
    std::cout << "[Second Utility Function] — not implemented yet.\n";
}

void thirdUtility() {
    std::cout << "[Third Utility Function] — not implemented yet.\n";
}

void fourthUtility() {
    std::cout << "[Fourth Utility Function] — not implemented yet.\n";
}
