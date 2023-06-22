#include <Password_Utility.h>

std::string PasswordUtility::PasswordStrength(std::string password) {
    system("cls");
    safetyMeasure = 0;
    hasSpecialCharacter = false;
    hasNumber = false;
    hasCapitalLetter = false;

    if (password.size() >= 5) {
        safetyMeasure++;
    }

    for (auto character : password) {
        if ((!hasSpecialCharacter) && std::ispunct(character)) {
            safetyMeasure++; //Special characters
            hasSpecialCharacter = true;
        }
        if ((!hasNumber) && std::isdigit(character)) {
            safetyMeasure++; //Numbers
            hasNumber = true;
        }
        if ((!hasCapitalLetter) && std::isupper(character)) {
            safetyMeasure++; //Capital letters
            hasCapitalLetter = true;
        }
    }

    switch (safetyMeasure) {
    case 0:
        system("cls");
        return "Password very weak.";
        break;
    case 1:
        system("cls");
        return "Password weak.";
        break;
    case 2:
        system("cls");
        return "Password average.";
        break;
    case 3:
        system("cls");
        return "Password good";
        break;
    case 4:
        system("cls");
        return "Password very good";
        break;
    default:
        system("cls");
        return "Error, default return value";
    }

}

std::string PasswordUtility::PasswordGenerator() {
    isPasswordGeneratorLooped = true;
    generatedPassword.clear();
    std::string set = "abcdefghijklmnopqrstuvwxyz";

        system("cls");
        std::cout << "Enter the length of password:";
        std::cin >> passwordLength;

        system("cls");
        std::cout << "Should the password contain special characters?\n1. Yes\n2. No\n";
        std::cin >> option;
        if (option == 1) {
            set.append("!@#$%^&*!@#$%^&*!@#$%^&*");
        }

        system("cls");
        std::cout << "Should the password contain capital letters?\n1. Yes\n2. No\n";
        std::cin >> option;
        if (option == 1) {
            set.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        }

        system("cls");
        std::cout << "Should the password contain numbers?\n1. Yes\n2. No\n";
        std::cin >> option;
        if (option == 1) {
            set.append("012345678901234567890123456789");
        }
        while (isPasswordGeneratorLooped) {
            generatedPassword.clear();
            srand(time(0));
            for (int i = 0; i < passwordLength; i++) {
                generatedPassword.push_back(set[rand() % (set.size() - 1)]);
            }
            system("cls");
            std::cout << "Generated password: " << generatedPassword << "\nConfirm?\n1. Yes\n2. No" << std::endl;
            std::cin >> option;
            if (option == 1) {
                isPasswordGeneratorLooped = false;
            }
        }
        return generatedPassword;
}