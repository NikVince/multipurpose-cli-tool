#ifndef BASE_CONVERTER_H
#define BASE_CONVERTER_H

#include <string>

enum class ParseStatus {
    Ok,
    Empty,
    InvalidBase,
    InvalidDigit,
    Overflow
};

// Supported bases for this utility: 2, 8, 10, and 16.
bool isSupportedBase(int base);

ParseStatus parseUnsigned(const std::string& input, int base, unsigned long long& value);
std::string formatUnsigned(unsigned long long value, int base);

void numberBaseConverter();

#endif
