#include <Main_menu.h>

void Main_Menu::MainMenu()
{
    initialFind.PathFinder();
    if (KeyMenu()) {
        Data_Vector = reader.Read(initialFind.filePath);
        for (auto el : Data_Vector) {
            categorySet.insert(crypter.Decrypt(el.getCategory(), key));
        }
    }
    else {
        Data_Vector = reader.Read(initialFind.filePath);
        for (auto el : Data_Vector) {
            categorySet.insert(crypter.Decrypt(el.getCategory(), key));
        }
        writer.Rewrite(initialFind.filePath, Data_Vector, key, secondsValue, minutesValue, hoursValue, day, dayOfMonth, month, year);
        return;
    }

    while (isMainLooped) {
        system("cls");
        std::cout << "Menu" << fullSeparate << "1. Passwords\n2. Categories\n3. Exit" << fullSeparate << "Choice: ";
        std::cin >> option;

        switch (option) {

        case 1:
            system("cls");
            PasswordMenu();
            break;

        case 2:
            system("cls");
            CategoryMenu();
            break;

        case 3:
            isMainLooped = false;
            writer.Rewrite(initialFind.filePath, Data_Vector, key, secondsValue, minutesValue, hoursValue, day, dayOfMonth, month, year);
            break;
        default:
            std::cout << "Wrong choice.";
            system("pause");
            break;
        }
    }
    return;
}

void Main_Menu::timestampSet() {
    std::time_t seconds = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &seconds);
    char timestamp[26];
    asctime_s(timestamp, sizeof(timestamp), &localTime);
    secondsValue = localTime.tm_sec;
    minutesValue = localTime.tm_min;
    hoursValue = localTime.tm_hour;
    day = localTime.tm_wday;
    dayOfMonth = localTime.tm_mday;
    month = localTime.tm_mon;
    year = localTime.tm_year + 1900;                    //Since 1900
    return;
}

void Main_Menu::timestampRead() {
    position = 0;
    for (int el : reader.getTimestamp(initialFind.filePath)) {
        switch (position) {
        case 0: 
            secondsValue = el;
            break;
        case 1:
            minutesValue = el;
            break;
        case 2:
            hoursValue = el;
            break;
        case 3:
            day = el;
            break;
        case 4:
            dayOfMonth = el;
            break;
        case 5:
            month = el;
            break;
        case 6:
            year = el;
            break;
        default:
            std::cout << "Error while reading timestamp.";
            system("pause");
            break;
        }
        position++;
    }
}

void Main_Menu::timestampShow() {
    std::cout << "File opened earlier on : ";
    switch (day) {
    case 0:
        std::cout << "Sunday ";
        break;
    case 1:
        std::cout << "Monday ";
        break;
    case 2:
        std::cout << "Tuesday ";
        break;
    case 3:
        std::cout << "Wednesday ";
        break;
    case 4:
        std::cout << "Thursday ";
        break;
    case 5:
        std::cout << "Friday ";
        break;
    case 6:
        std::cout << "Saturday ";
        break;
    default:
        system("cls");
        std::cout << "Error, wrong day of the week.";
        system("pause");
        break;
    }

    switch (month) {
    case 0:
        std::cout << "Jan ";
        break;
    case 1:
        std::cout << "Feb ";
        break;
    case 2:
        std::cout << "March ";
        break;
    case 3:
        std::cout << "April ";
        break;
    case 4:
        std::cout << "May ";
        break;
    case 5:
        std::cout << "June ";
        break;
    case 6:
        std::cout << "July ";
        break;
    case 7:
        std::cout << "Aug ";
        break;
    case 8:
        std::cout << "Sept ";
        break;
    case 9:
        std::cout << "Oct ";
        break;
    case 10:
        std::cout << "Nov ";
        break;
    case 11:
        std::cout << "Dec ";
        break;
    default:
        system("cls");
        std::cout << "Error, wrong month.";
        system("pause");
        break;
    }
    if (dayOfMonth < 10) {
        std::cout << "0";
    }
    std::cout << dayOfMonth << " ";

    if (hoursValue < 10) {
        std::cout << "0";
    }
    std::cout << hoursValue << ":";

    if (minutesValue < 10) {
        std::cout << "0";
    }
    std::cout << minutesValue << ":";
    if (secondsValue < 10) {
        std::cout << "0";
    }
    std::cout << secondsValue << " " << year;
}

bool Main_Menu::KeyMenu() {
    std::cout << fullSeparate;
    if (reader.hasKey(initialFind.filePath)) {
        timestampRead();
        timestampShow();
        std::cout << std::endl;
        std::cout << "Enter password: ";
        std::cin >> password_input;

        if (crypter.Encrypt(password_input, password_input) == reader.getKey(initialFind.filePath)) {
            key = reader.getKey(initialFind.filePath);
            timestampSet();

            system("cls");
            std::cout << "Password correct.\n\n";
            system("pause");
            return true;
        }

        else {
            key = reader.getKey(initialFind.filePath);
            system("cls");
            timestampSet();
            std::cout << "Password incorrect.\n\n";
            system("pause");
            return false;
        }
    }

    else if (!reader.hasKey(initialFind.filePath)) {
        system("cls");
        std::cout << "Key not found.";
        std::cout << halfSeparate;
        std::cout << "Set password: ";
        std::cin >> password_input;

        writer.KeyWrite(
            initialFind.filePath, 
            crypter.Encrypt(password_input, password_input)
        );
        key = reader.getKey(initialFind.filePath);

        timestampSet();
        
        writer.timestampWrite(
        initialFind.filePath,
            key,
            secondsValue,
            minutesValue,
            hoursValue,
            day,
            dayOfMonth,
            month,
            year
            );
        return true;
    }

    else {
        std::cout << "Error, couldn't determine main password key.\n";
        system("pause");
        return false;
    }
}

void Main_Menu::Show(Main_Menu::type type) {
    position = 1;
    switch (type) {
    case 1:
        for (auto el : reader.Show(Data_Vector, NAME)) {
            std::cout << crypter.Decrypt(el, key) << halfSeparate;
        }
        break;
    case 3:
        for (auto el : categorySet) {
            std::cout << position << ". " << el << halfSeparate;
            position++;
        }
        break;
    case 4:
        for (auto el : reader.Show(Data_Vector, SITE)) {
            std::cout << crypter.Decrypt(el, key) << halfSeparate;
        }
        break;
    case 5:
        for (auto el : reader.Show(Data_Vector, LOGIN)) {
            std::cout << crypter.Decrypt(el, key) << halfSeparate;
        }
        break;
    default:
        std::cout << "Error in Main_Menu::Show(), wrong type selected.\n";
        system("pause");
        break;
    }

}

void Main_Menu::SearchMenu(std::vector<Password_Data> passwordVector, Main_Menu::type type) {
        Decrypted_Data_Vector.clear();
        switch (type) {
            case 1: //Specific name
                std::cout << "Which name would you like to search?\nChoice: ";
                std::cin >> search_input;
                Decrypted_Data_Vector = reader.Find(passwordVector, type, crypter.Encrypt(search_input, key) );
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << crypter.Decrypt(el.getName(), key) << std::endl;
                }
            break;
            case 2: //Name containing a letter
                std::cout << "Which character would you like to search for?\nChoice: ";
                std::cin >> search_input;
                Decrypted_Data_Vector = reader.Find(passwordVector, type, crypter.Encrypt(search_input, key));
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << crypter.Decrypt(el.getName(), key) << std::endl;
                }
                break;
            case 3: //By category
                std::cout << "Which category would you like to search for?\nChoice: ";
                std::cin >> search_input;
                Decrypted_Data_Vector = reader.Find(passwordVector, type, crypter.Encrypt(search_input, key));
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << crypter.Decrypt(el.getCategory(), key) << std::endl;
                }
                break;
            case 4: //By site
                std::cout << "Which site would you like to search for?\nChoice: ";
                std::cin >> search_input;
                Decrypted_Data_Vector = reader.Find(passwordVector, type, crypter.Encrypt(search_input, key));
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << crypter.Decrypt(el.getSite(), key) << std::endl;
                }
                break;
            case 5: //By login
                std::cout << "Which login would you like to search for?\nChoice: ";
                std::cin >> search_input;
                Decrypted_Data_Vector = reader.Find(passwordVector, type, crypter.Encrypt(search_input, key));
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << crypter.Decrypt(el.getLogin(), key) << std::endl;
                }
                break;
            case 6: //All
                Decrypted_Data_Vector = reader.Find(passwordVector, type, "");
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << "Name: " << crypter.Decrypt(el.getName(), key) << std::endl;
                    std::cout << "Category: " << crypter.Decrypt(el.getCategory(), key) << std::endl;
                    std::cout << "Password: " << crypter.Decrypt(el.getPassword(), key) << std::endl;
                }
                break;
            case 7: //Password
                std::cout << "Which password would you like to search for?\nChoice: ";
                std::cin >> search_input;
                Decrypted_Data_Vector = reader.Find(passwordVector, type, crypter.Encrypt(search_input, key));
                for (auto el : Decrypted_Data_Vector) {
                    std::cout << crypter.Decrypt(el.getPassword(), key) << std::endl;
                }
            default:
                std::cout << "Error in finding your choice, default case selected.\n";
                system("pause");
                break;
            }
}

void Main_Menu::PasswordShowMenu() {
    if ((reader.Show(Data_Vector, NAME)).empty()) {
        system("cls");
        std::cout << "Error, no passwords to show.\n";
        system("pause");
        return;
    }
    while (isPasswordShowLooped) {
        std::cout << std::endl;
        system("cls");
        std::cout << "Passwords: ";
        std::cout << fullSeparate;
        Show(NAME);
        std::cout << fullSeparate;
        std::cout << "1. Choose password \n2. Sort\n3. Return" << fullSeparate << "Choice: ";
        std::cin >> option;
        switch (option) {
        case 1:
            system("cls");
            std::cout << "Passwords: ";
            std::cout << fullSeparate;
            Show(NAME);
            std::cout << fullSeparate;
            std::cout << "Enter the name of the password: ";
            std::cin >> search_input;
            system("cls");
            for (auto el : reader.Find(Data_Vector, NAME, crypter.Encrypt(search_input, key))) {
                std::cout << "====================\n";

                std::cout << "Name:" << crypter.Decrypt(el.getName(), key);
                std::cout << halfSeparate;

                std::cout << "Category: " << crypter.Decrypt(el.getCategory(), key);
                std::cout << halfSeparate;

                if (el.getSize() == 1) {
                    std::cout << "Site: " << crypter.Decrypt(el.getSite(), key);
                    std::cout << halfSeparate;

                    std::cout << "Login: " << crypter.Decrypt(el.getLogin(), key);
                    std::cout << halfSeparate;
                }

                std::cout << "Password: " << crypter.Decrypt(el.getPassword(), key);
                std::cout << fullSeparate;
            }
            system("pause");
            break;
        case 2:
            std::cout << "\n1. By name\n2. By category\n3. By both\nChoice: ";
            std::cin >> option;
            switch (option) {
            case 1:
                //sort(Data_Vector.begin(), Data_Vector.end(), compareByName);
                break;
            case 2:
                //sort(Data_Vector.begin(), Data_Vector.end(), compareByCategory);
                break;
            case 3:
                //sort(Data_Vector.begin(), Data_Vector.end(), compareByBoth);
                break;
            default:
                std::cout << "Wrong input.\n";
                system("pause");
                break;
            }
            break;
        case 3:
            isPasswordShowLooped = false;
            break;
        default:
            std::cout << "Wrong input.\n";
            system("pause");
            break;
        }
    }
}

std::string Main_Menu::PasswordCheckMenu() {
    isPasswordCheckLooped = true;
    while (isPasswordCheckLooped) {
        system("cls");
        std::cout << "Password: ";
        std::cin >> password_input;
        system("cls");
        std::cout << passwordUtility.PasswordStrength(password_input);
        std::cout << "\n1. Confirm\n2. Retype\nChoice: ";
        std::cin >> option;
        if (option == 1) {
            isPasswordCheckLooped = false;
        }
        else {
            isPasswordCheckLooped = true;
        }
    }
    return password_input;
}

void Main_Menu::PasswordAddMenu() {
    if (categorySet.empty()) {
        system("cls");
        std::cout << "Error, add a category first.\n";
        system("pause");
        return;
    }
    isCategoryInputLooped = true;
    system("cls");
    std::cout << "Password name: ";
    std::cin >> name_input;

    while (isCategoryInputLooped) {
        system("cls");
        std::cout << "Categories: " << fullSeparate;
        Show(CATEGORY);
        std::cout << fullSeparate;

        std::cout << "Password category: ";
        std::cin >> option;

        if (option <= categorySet.size()) {
            setIterator = categorySet.begin();
            std::advance(setIterator, option - 1);

            isCategoryInputLooped = false;
        }
        else {
            std::cout << "Wrong input." << std::endl;
            system("pause");
            isCategoryInputLooped = true;
        }
    }

        category_input = *setIterator;

        system("cls");
    std::cout << "Do you want to include site and login?\n1. Yes\n2. No\nChoice: ";
    std::cin >> option;

    if (option == 1) {
        system("cls");
        std::cout << "Password site: ";
        std::cin >> site_input;

        system("cls");
        std::cout << "Password login: ";
        std::cin >> login_input;

        system("cls");
        std::cout << "1. Enter password manually\n2. Generate password\nChoice: ";
        std::cin >> option;

        if (option == 1) {
            writer.FullWrite(
                initialFind.filePath, 
                crypter.Encrypt(category_input, key), 
                crypter.Encrypt(name_input, key), 
                crypter.Encrypt(PasswordCheckMenu(), key), 
                crypter.Encrypt(site_input, key),  
                crypter.Encrypt(login_input, key)
            );
        }
        else {
            writer.FullWrite(
                initialFind.filePath, 
                crypter.Encrypt(category_input, key), 
                crypter.Encrypt(name_input, key),
                crypter.Encrypt(passwordUtility.PasswordGenerator(), key), 
                crypter.Encrypt(site_input, key),
                crypter.Encrypt(login_input, key)
            );
        }

    }
    else {
        system("cls");
        std::cout << "1. Enter password manually\n2. Generate password\nChoice: ";
        std::cin >> option;
        if (option == 1) {
            writer.BasicWrite(
                initialFind.filePath, 
                crypter.Encrypt(category_input, key),
                crypter.Encrypt(name_input, key),
                crypter.Encrypt(PasswordCheckMenu(), key)
            );
        }
        else {
            writer.BasicWrite(initialFind.filePath, 
                crypter.Encrypt(category_input, key),
                crypter.Encrypt(name_input, key),
                crypter.Encrypt(passwordUtility.PasswordGenerator(), key)
            );
        }
    }
}

void Main_Menu::PasswordMenu()
{
    isPasswordLooped = true;
    while (isPasswordLooped) {
        system("cls");
        std::cout << "Password menu." << fullSeparate;
        std::cout << "1. Add\n2. Delete\n3. Show\n4. Return" << fullSeparate << "Choice: ";
        std::cin >> option;
        switch (option) {
        case 1:
            PasswordAddMenu();
            Data_Vector = reader.Read(initialFind.filePath);
            break;
        case 2:
            system("cls");
            if (Data_Vector.empty()) {
                std::cout << "Error, no passwords to delete.\n";
                system("pause");
                return;
            }
            Decrypted_Data_Vector.clear();
            std::cout << "Passwords: " << fullSeparate;
            Show(NAME);
            std::cout << fullSeparate;
            std::cout << "\n1. Which password do you want to delete?\nChoice: ";
            std::cin >> search_input;
            for (auto el : Data_Vector) {
                if (crypter.Encrypt(search_input, key) != el.getName()) {
                    Decrypted_Data_Vector.push_back(el);
                }
            }
            for (auto el : Decrypted_Data_Vector) {
                std::cout << el.getCategory() << '\n';
            }
            writer.Rewrite(initialFind.filePath, Decrypted_Data_Vector, key, secondsValue, minutesValue, hoursValue, day, dayOfMonth, month, year);
            Data_Vector = Decrypted_Data_Vector;
            break;
        case 3:
            isPasswordShowLooped = true;
            PasswordShowMenu();
            break;
        case 4:
            isPasswordLooped = false;
            break;
        default:
            std::cout << "Wrong input.\n";
            system("pause");
            break;
        }
    }
}

void Main_Menu::CategoryShowMenu() {
    if (categorySet.empty()) {
        std::cout << "Error, no categories to show.\n" << fullSeparate;
        system("pause");
        return;
    }
    isCategoryInputLooped = true;
    while (isCategoryInputLooped) {
        system("cls");
        std::cout << "Categories: " << fullSeparate;
        Show(CATEGORY);
        std::cout << fullSeparate;
        std::cout << "\nSelect a category: ";
        std::cin >> option;

        if (option <= categorySet.size()) {
            setIterator = categorySet.begin();
            std::advance(setIterator, option - 1);

            isCategoryInputLooped = false;
        }
        else {
            system("cls");
            std::cout << "Wrong input." << std::endl;
            system("pause");
            isCategoryInputLooped = true;
        }
    }

                system("cls");
                position = 1;
                if (reader.Find(Data_Vector, CATEGORY, crypter.Encrypt(*setIterator, key)).empty()) {
                    std::cout << "====================\n" << "No data to show." << fullSeparate;
                    system("pause");
                    return;
                }
                else {
                    for (auto el : reader.Find(Data_Vector, CATEGORY, crypter.Encrypt(*setIterator, key))) {
                        std::cout << "====================\n";
                        std::cout << "Position " << position << fullSeparate;
                        position++;

                        std::cout << "Name:" << crypter.Decrypt(el.getName(), key);
                        std::cout << halfSeparate;

                        std::cout << "Category: " << crypter.Decrypt(el.getCategory(), key);
                        std::cout << halfSeparate;

                        if (el.getSize() == 1) {
                            std::cout << "Site: " << crypter.Decrypt(el.getSite(), key);
                            std::cout << halfSeparate;

                            std::cout << "Login: " << crypter.Decrypt(el.getLogin(), key);
                            std::cout << halfSeparate;
                        }

                        std::cout << "Password: " << crypter.Decrypt(el.getPassword(), key);
                        std::cout << fullSeparate << "\n\n";
                    }
                    system("pause");
                }
}

void Main_Menu::CategoryMenu()
{
    isCategoryLooped = true;
    while (isCategoryLooped) {
        system("cls");
        std::cout << "Category menu." << fullSeparate;
        std::cout << "1. Add\n2. Delete\n3. Show\n4. Return" << fullSeparate << "Choice: ";
        std::cin >> option;
        switch (option) {
        case 1:
            system("cls");
            std::cout << "Category name: ";
            std::cin >> category_input;
            categorySet.insert(category_input);
            break;
        case 2:
            system("cls");
            if (categorySet.empty()) {
                std::cout << "Error, no categories to delete.\n";
                system("pause");
                return;
            }
            isCategoryInputLooped = true;
            while (isCategoryInputLooped) {
                system("cls");
                std::cout << "Categories: " << fullSeparate;
                Show(CATEGORY);
                std::cout << fullSeparate;
                std::cout << "\nWhich category would you like to delete: \nChoice: ";
                std::cin >> option;

                if (option <= categorySet.size()) {
                    setIterator = categorySet.begin();
                    std::advance(setIterator, option - 1);

                    isCategoryInputLooped = false;
                }
                else {
                    std::cout << "Wrong input." << std::endl;
                    system("pause");
                    isCategoryInputLooped = true;
                }
            }
            Decrypted_Data_Vector.clear();

            position = 0;
            for (auto el : Data_Vector) {
                if (crypter.Encrypt(*setIterator, key) != el.getCategory()) {
                    Decrypted_Data_Vector.push_back(el);
                }
                else {
                    position++;
                }
            }

            system("cls");
            std::cout << "You are deleting " << position << " passwords with category " << *setIterator << ". Confirm?\n1. Yes\n2. No\nChoice: ";
            std::cin >> option;
            if (option == 1) {
                categorySet.erase(*setIterator);
                writer.Rewrite(initialFind.filePath, Decrypted_Data_Vector, key, secondsValue, minutesValue, hoursValue, day, dayOfMonth, month, year);
                Data_Vector = Decrypted_Data_Vector;
            }
            else {
                break;
            }
            break;
        case 3:
            system("cls");
            CategoryShowMenu();
            break;
        case 4: 
            isCategoryLooped = false;
            break;
        default:
            system("cls");
            std::cout << "Wrong input.\n";
            system("pause");
            break;
        }
    }
}