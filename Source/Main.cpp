#include "../Include/Utility.h"

#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n===== UTILITY PROGRAM MENU =====\n";
    std::cout << "1. [First Utility Function]\n";
    std::cout << "2. [Second Utility Function]\n";
    std::cout << "3. [Third Utility Function]\n";
    std::cout << "4. [Fourth Utility Function]\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

int main() {
    bool running = true;

    while (running) {
        displayMenu();

        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1:
                firstUtility();
                break;
            case 2:
                secondUtility();
                break;
            case 3:
                thirdUtility();
                break;
            case 4:
                fourthUtility();
                break;
            case 5:
                std::cout << "Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}
