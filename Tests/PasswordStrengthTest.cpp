#include "../Include/PasswordStrength.h"

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

void expectLevel(const std::string& password, StrengthLevel expected, const std::string& label) {
    const PasswordAnalysis analysis = analyzePassword(password);
    if (analysis.level != expected) {
        std::cerr << "FAIL: " << label << " expected " << strengthLevelName(expected) << ", got "
                  << strengthLevelName(analysis.level) << '\n';
        ++failures;
    }
}

}  // namespace

int main() {
    PasswordAnalysis analysis = analyzePassword("");

    check(analysis.criteriaMet == 0, "empty password meets no criteria");
    expectLevel("", StrengthLevel::Weak, "empty password strength");

    analysis = analyzePassword("abc");
    check(!analysis.criteria.minLength, "short password fails length");
    check(analysis.criteria.hasLower, "short password has lower");
    check(!analysis.criteria.hasUpper, "short password lacks upper");
    expectLevel("abc", StrengthLevel::Weak, "short lowercase");

    analysis = analyzePassword("password");
    check(analysis.criteria.minLength, "password meets length");
    check(!analysis.criteria.hasUpper, "password lacks upper");
    expectLevel("password", StrengthLevel::Weak, "lowercase-only word");

    analysis = analyzePassword("Password1");
    check(analysis.criteria.minLength, "Password1 length");
    check(analysis.criteria.hasLower && analysis.criteria.hasUpper &&
              analysis.criteria.hasDigit,
          "Password1 has mixed case and digit");
    check(!analysis.criteria.hasSpecial, "Password1 lacks special");
    expectLevel("Password1", StrengthLevel::Good, "Password1");

    analysis = analyzePassword("Password1!");
    check(analysis.criteria.hasSpecial, "Password1! has special");
    check(analysis.criteriaMet == 5, "Password1! meets all criteria");
    expectLevel("Password1!", StrengthLevel::Strong, "Password1!");

    analysis = analyzePassword("Aa1!xxxx");
    check(analysis.criteriaMet == 5, "Aa1!xxxx meets all criteria");
    expectLevel("Aa1!xxxx", StrengthLevel::Strong, "Aa1!xxxx");

    if (failures == 0) {
        std::cout << "All password strength tests passed.\n";
        return 0;
    }

    std::cerr << failures << " test(s) failed.\n";
    return 1;
}
