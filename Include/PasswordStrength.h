#ifndef PASSWORD_STRENGTH_H
#define PASSWORD_STRENGTH_H

#include <string>

enum class StrengthLevel { Weak, Fair, Good, Strong };

struct PasswordCriteria {
    bool minLength = false;   // at least 8 characters
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;
};

struct PasswordAnalysis {
    PasswordCriteria criteria;
    int criteriaMet = 0;
    StrengthLevel level = StrengthLevel::Weak;
};

PasswordAnalysis analyzePassword(const std::string& password);
const char* strengthLevelName(StrengthLevel level);

void passwordStrengthChecker();

#endif
