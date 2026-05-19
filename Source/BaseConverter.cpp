#include "../Include/BaseConverter.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

namespace {

std::string trim(const std::string& input) {
    const auto start = input.find_first_not_of(" \t");
    if (start == std::string::npos) {
        return "";
    }

    const auto end = input.find_last_not_of(" \t");
    return input.substr(start, end - start + 1);
}

bool readLine(const char* prompt, std::string& line) {
    std::cout << prompt;
    if (!std::getline(std::cin, line)) {
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

int parseBaseChoice(const std::string& line) {
    if (line == "2") {
        return 2;
    }
    if (line == "8") {
        return 8;
    }
    if (line == "10") {
        return 10;
    }
    if (line == "16") {
        return 16;
    }
    return -1;
}

int getValidBase(const char* prompt) {
    while (true) {
        std::string line;
        if (!readLine(prompt, line)) {
            return -1;
        }

        const int base = parseBaseChoice(trim(line));
        if (base > 0) {
            return base;
        }

        std::cout << "Invalid base. Please enter 2, 8, 10, or 16.\n";
    }
}

}  // namespace

bool isSupportedBase(int base) {
    return base == 2 || base == 8 || base == 10 || base == 16;
}

ParseStatus parseUnsigned(const std::string& input, int base, unsigned long long& value) {
    if (!isSupportedBase(base)) {
        return ParseStatus::InvalidBase;
    }

    const std::string trimmed = trim(input);
    if (trimmed.empty()) {
        return ParseStatus::Empty;
    }

    value = 0;

    for (char ch : trimmed) {
        int digit = 0;

        if (std::isdigit(static_cast<unsigned char>(ch))) {
            digit = ch - '0';
        } else if (std::isalpha(static_cast<unsigned char>(ch))) {
            digit = std::tolower(static_cast<unsigned char>(ch)) - 'a' + 10;
        } else {
            return ParseStatus::InvalidDigit;
        }

        if (digit >= base) {
            return ParseStatus::InvalidDigit;
        }

        if (value > std::numeric_limits<unsigned long long>::max() / static_cast<unsigned long long>(base)) {
            return ParseStatus::Overflow;
        }

        value = value * static_cast<unsigned long long>(base) + static_cast<unsigned long long>(digit);
    }

    return ParseStatus::Ok;
}

std::string formatUnsigned(unsigned long long value, int base) {
    if (!isSupportedBase(base)) {
        return "";
    }

    if (value == 0) {
        return "0";
    }

    static constexpr char kDigits[] = "0123456789ABCDEF";
    std::string result;

    while (value > 0) {
        result.push_back(kDigits[value % static_cast<unsigned long long>(base)]);
        value /= static_cast<unsigned long long>(base);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

void numberBaseConverter() {
    std::cout << "\n===== NUMBER BASE CONVERTER =====\n";
    std::cout << "Convert non-negative integers between binary (2), octal (8), "
                 "decimal (10), and hexadecimal (16).\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string numberInput;
    while (true) {
        if (!readLine("Enter the number: ", numberInput)) {
            return;
        }

        numberInput = trim(numberInput);
        if (!numberInput.empty()) {
            break;
        }

        std::cout << "Number cannot be empty. Please try again.\n";
    }

    const int sourceBase = getValidBase("Enter the source base (2, 8, 10, 16): ");
    if (sourceBase < 0) {
        return;
    }

    const int targetBase = getValidBase("Enter the target base (2, 8, 10, 16): ");
    if (targetBase < 0) {
        return;
    }

    unsigned long long value = 0;
    const ParseStatus status = parseUnsigned(numberInput, sourceBase, value);

    switch (status) {
        case ParseStatus::Ok:
            break;
        case ParseStatus::Empty:
            std::cout << "Error: number cannot be empty.\n";
            return;
        case ParseStatus::InvalidBase:
            std::cout << "Error: unsupported base.\n";
            return;
        case ParseStatus::InvalidDigit:
            std::cout << "Error: \"" << numberInput
                      << "\" contains a digit invalid for base " << sourceBase << ".\n";
            return;
        case ParseStatus::Overflow:
            std::cout << "Error: number is too large to convert.\n";
            return;
    }

    if (sourceBase == targetBase) {
        std::cout << "Source and target bases are the same. Value: " << numberInput << '\n';
        return;
    }

    const std::string converted = formatUnsigned(value, targetBase);

    std::cout << numberInput << " (base " << sourceBase << ") = " << converted << " (base "
              << targetBase << ")\n";
}
