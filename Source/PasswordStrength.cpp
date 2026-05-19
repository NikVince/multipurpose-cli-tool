#include "../Include/PasswordStrength.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <string>

namespace {

constexpr int kMinPasswordLength = 8;

bool isSpecialCharacter(char ch) {
    return !std::isalnum(static_cast<unsigned char>(ch));
}

bool readPassword(const char* prompt, std::string& password) {
    std::cout << prompt;
    if (!std::getline(std::cin, password)) {
        if (std::cin.eof()) {
            std::cout << "Error: input ended unexpectedly.\n";
        } else {
            std::cin.clear();
            std::cout << "Error: could not read input.\n";
        }
        return false;
    }
    return true;
}

void printCriteriaRow(const char* label, bool met) {
    std::cout << "  [" << (met ? 'X' : ' ') << "] " << label << '\n';
}

}  // namespace

PasswordAnalysis analyzePassword(const std::string& password) {
    PasswordAnalysis analysis;

    analysis.criteria.minLength = password.size() >= static_cast<size_t>(kMinPasswordLength);

    for (char ch : password) {
        const unsigned char uch = static_cast<unsigned char>(ch);

        if (std::islower(uch)) {
            analysis.criteria.hasLower = true;
        } else if (std::isupper(uch)) {
            analysis.criteria.hasUpper = true;
        } else if (std::isdigit(uch)) {
            analysis.criteria.hasDigit = true;
        } else if (isSpecialCharacter(ch)) {
            analysis.criteria.hasSpecial = true;
        }
    }

    analysis.criteriaMet = static_cast<int>(analysis.criteria.minLength) +
                           static_cast<int>(analysis.criteria.hasLower) +
                           static_cast<int>(analysis.criteria.hasUpper) +
                           static_cast<int>(analysis.criteria.hasDigit) +
                           static_cast<int>(analysis.criteria.hasSpecial);

    if (analysis.criteriaMet <= 2) {
        analysis.level = StrengthLevel::Weak;
    } else if (analysis.criteriaMet == 3) {
        analysis.level = StrengthLevel::Fair;
    } else if (analysis.criteriaMet == 4) {
        analysis.level = StrengthLevel::Good;
    } else {
        analysis.level = StrengthLevel::Strong;
    }

    return analysis;
}

const char* strengthLevelName(StrengthLevel level) {
    switch (level) {
        case StrengthLevel::Weak:
            return "Weak";
        case StrengthLevel::Fair:
            return "Fair";
        case StrengthLevel::Good:
            return "Good";
        case StrengthLevel::Strong:
            return "Strong";
    }

    return "Unknown";
}

void passwordStrengthChecker() {
    std::cout << "\n===== PASSWORD STRENGTH CHECKER =====\n";
    std::cout << "Evaluates length, letter case, digits, and symbols.\n";
    std::cout << "Note: input is visible in the terminal and is not stored.\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string password;
    while (true) {
        if (!readPassword("Enter a password to evaluate: ", password)) {
            return;
        }

        if (!password.empty()) {
            break;
        }

        std::cout << "Password cannot be empty. Please try again.\n";
    }

    const PasswordAnalysis analysis = analyzePassword(password);

    std::cout << "\n--- Criteria ---\n";
    printCriteriaRow("At least 8 characters", analysis.criteria.minLength);
    printCriteriaRow("Contains a lowercase letter", analysis.criteria.hasLower);
    printCriteriaRow("Contains an uppercase letter", analysis.criteria.hasUpper);
    printCriteriaRow("Contains a digit", analysis.criteria.hasDigit);
    printCriteriaRow("Contains a special character", analysis.criteria.hasSpecial);

    std::cout << "\nCriteria met: " << analysis.criteriaMet << " / 5\n";
    std::cout << "Strength rating: " << strengthLevelName(analysis.level) << '\n';

    switch (analysis.level) {
        case StrengthLevel::Weak:
            std::cout << "Recommendation: use a longer mix of upper/lowercase letters, "
                         "numbers, and symbols.\n";
            break;
        case StrengthLevel::Fair:
            std::cout << "Recommendation: add missing character types to improve strength.\n";
            break;
        case StrengthLevel::Good:
            std::cout << "Recommendation: good start — consider a longer passphrase.\n";
            break;
        case StrengthLevel::Strong:
            std::cout << "Recommendation: strong password based on these rules.\n";
            break;
    }
}
