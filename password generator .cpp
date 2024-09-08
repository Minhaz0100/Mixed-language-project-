#include <bits/stdc++.h>    

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool includeUpper, bool includeLower, bool includeNumbers, bool includeSpecial) {
    string password = "";
    string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerChars = "abcdefghijklmnopqrstuvwxyz";
    string numberChars = "0123456789";
    string specialChars = "!@#$%^&*()_+[]{}|;:,.<>?";

    string charPool = "";

    // Add character sets based on user preference
    if (includeUpper) {
        charPool += upperChars;
    }
    if (includeLower) {
        charPool += lowerChars;
    }
    if (includeNumbers) {
        charPool += numberChars;
    }
    if (includeSpecial) {
        charPool += specialChars;
    }

    if (charPool.empty()) {
        cout << "No character sets selected. Unable to generate password." << endl;
        return "";
    }

    // Generate the password
    for (int i = 0; i < length; i++) {
        password += charPool[rand() % charPool.length()];
    }

    return password;
}

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    int length;
    bool includeUpper, includeLower, includeNumbers, includeSpecial;

    cout << "Password Generator\n";
    cout << "Enter the desired length of the password: ";
    cin >> length;

    cout << "Include uppercase letters? (1 for Yes, 0 for No): ";
    cin >> includeUpper;

    cout << "Include lowercase letters? (1 for Yes, 0 for No): ";
    cin >> includeLower;

    cout << "Include numbers? (1 for Yes, 0 for No): ";
    cin >> includeNumbers;

    cout << "Include special characters? (1 for Yes, 0 for No): ";
    cin >> includeSpecial;

    // Generate and display the password
    string password = generatePassword(length, includeUpper, includeLower, includeNumbers, includeSpecial);
    if (!password.empty()) {
        cout << "Generated Password: " << password << endl;
    }

    return 0;
}
    