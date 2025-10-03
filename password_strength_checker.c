#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool hasUpperCase(const char *password) {
    while (*password) {
        if (isupper(*password)) return true;
        password++;
    }
    return false;
}

bool hasLowerCase(const char *password) {
    while (*password) {
        if (islower(*password)) return true;
        password++;
    }
    return false;
}

bool hasDigit(const char *password) {
    while (*password) {
        if (isdigit(*password)) return true;
        password++;
    }
    return false;
}

bool hasSpecialChar(const char *password) {
    const char *specialChars = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";
    while (*password) {
        if (strchr(specialChars, *password)) return true;
        password++;
    }
    return false;
}

const char* checkStrength(const char *password) {
    int length = strlen(password);
    bool upper = hasUpperCase(password);
    bool lower = hasLowerCase(password);
    bool digit = hasDigit(password);
    bool special = hasSpecialChar(password);

    if (length >= 12 && upper && lower && digit && special)
        return "Very Strong 💪";
    else if (length >= 8 && upper && lower && digit)
        return "Strong 🔐";
    else if (length >= 6 && (upper || lower) && digit)
        return "Moderate 🟡";
    else
        return "Weak ❌";
}

int main() {
    char password[100];

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove trailing newline if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    const char *strength = checkStrength(password);
    printf("Password Strength: %s\n", strength);

    return 0;
}
