#include "../Include/BaseConverter.h"

#include <iostream>
#include <string>

namespace {

int failures = 0;

void check(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << '\n';
        ++failures;
    }
}

void testParseUnsigned() {
    unsigned long long value = 0;

    check(parseUnsigned("1010", 2, value) == ParseStatus::Ok, "binary 1010 parses");
    check(value == 10, "binary 1010 equals 10");

    check(parseUnsigned("255", 10, value) == ParseStatus::Ok, "decimal 255 parses");
    check(value == 255, "decimal 255 value");

    check(parseUnsigned("FF", 16, value) == ParseStatus::Ok, "hex FF parses");
    check(value == 255, "hex FF equals 255");

    check(parseUnsigned("ff", 16, value) == ParseStatus::Ok, "hex ff is case-insensitive");
    check(value == 255, "hex ff equals 255");

    check(parseUnsigned("377", 8, value) == ParseStatus::Ok, "octal 377 parses");
    check(value == 255, "octal 377 equals 255");

    check(parseUnsigned("102", 2, value) == ParseStatus::InvalidDigit, "digit 2 invalid in base 2");
    check(parseUnsigned("G1", 16, value) == ParseStatus::InvalidDigit, "G invalid in hex");
    check(parseUnsigned("", 10, value) == ParseStatus::Empty, "empty input rejected");
    check(parseUnsigned("10", 99, value) == ParseStatus::InvalidBase, "unsupported base rejected");
}

void testFormatUnsigned() {
    check(formatUnsigned(10, 2) == "1010", "10 to binary");
    check(formatUnsigned(255, 16) == "FF", "255 to hex");
    check(formatUnsigned(255, 8) == "377", "255 to octal");
    check(formatUnsigned(0, 10) == "0", "zero formats as 0");
    check(formatUnsigned(42, 10) == "42", "42 to decimal");
}

void testRoundTrip() {
    unsigned long long value = 0;
    const std::string input = "1A2B3C";

    check(parseUnsigned(input, 16, value) == ParseStatus::Ok, "round-trip parse");
    check(formatUnsigned(value, 16) == "1A2B3C", "round-trip format");
}

void testIsSupportedBase() {
    check(isSupportedBase(2), "base 2 supported");
    check(isSupportedBase(16), "base 16 supported");
    check(!isSupportedBase(3), "base 3 unsupported");
    check(!isSupportedBase(12), "base 12 unsupported");
}

}  // namespace

int main() {
    testIsSupportedBase();
    testParseUnsigned();
    testFormatUnsigned();
    testRoundTrip();

    if (failures == 0) {
        std::cout << "All base converter tests passed.\n";
        return 0;
    }

    std::cerr << failures << " test(s) failed.\n";
    return 1;
}
