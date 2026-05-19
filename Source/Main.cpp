#include "../Include/BaseConverter.h"
#include "../Include/PasswordStrength.h"
#include "../Include/Utility.h"

#include <iostream>
#include <limits>

namespace {

constexpr int kMenuExitOnEof = -1;

void discardRestOfLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidMenuChoice() {
    int choice = 0;

    while (true) {
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                std::cout << "\nGoodbye!\n";
                return kMenuExitOnEof;
            }

            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin.clear();
            discardRestOfLine();
            continue;
        }

        if (std::cin.peek() != '\n') {
            discardRestOfLine();
        }

        if (choice >= 1 && choice <= 5) {
            return choice;
        }

        std::cout << "Invalid choice. Please enter a number between 1 and 5: ";
    }
}

}  // namespace

void displayMenu() {
    std::cout << "\n===== UTILITY PROGRAM MENU =====\n";
    std::cout << "1. Basic Calculator\n";
    std::cout << "2. Word Counter\n";
    std::cout << "3. Number Base Converter\n";
    std::cout << "4. Password Strength Checker\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

int main() {
    bool running = true;

    while (running) {
        displayMenu();

        const int choice = getValidMenuChoice();
        if (choice == kMenuExitOnEof) {
            break;
        }

        switch (choice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                wordCounter();
                break;
            case 3:
                numberBaseConverter();
                break;
            case 4:
                passwordStrengthChecker();
                break;
            case 5:
                std::cout << "Goodbye!\n";
                running = false;
                break;
        }
    }

    return 0;
}
