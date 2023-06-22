#include <Path_Finder.h>

void FinderClass::AbsolutePath() {
    isAbsolutePathLooped = true;

    while (isAbsolutePathLooped) {
        system("cls");
        std::cout << "Enter absolute path to a file:\nPath: ";
        std::cin.ignore();
        std::getline(std::cin, filePath);
        fs::directory_entry de(filePath);

        if (de.exists()) {
            system("cls");
            std::cout << "File chosen: " << de.path().filename() << "\nPath: " << filePath << std::endl;
            isAbsolutePathLooped = false;
            isPathFinderLooped = false;
            return;
        }

        else {
            system("cls");
            std::cout << "Incorrect path.\n1. Retype\n2. Create a file\n3. Return\nChoice: ";
            std::cin >> option;
            if (option == 2) {

                std::ofstream new_file(filePath);
                new_file << "";
                new_file.close();

                std::cout << "File created on path: " << filePath << std::endl;
                isAbsolutePathLooped = false;
                isPathFinderLooped = false;
                return;
            }
            else if (option == 3) {
                isAbsolutePathLooped = false;
                isPathFinderLooped = true;
            }
        }

    }
    return;
}

void FinderClass::DirectoryContents() {
    isDirectoryContentsLooped = true;

    while (isDirectoryContentsLooped) {
        system("cls");
        std::cout << "Choose file:\n";

        try {
            std::string filePath = fs::current_path().string();
            for (const auto& entry : fs::directory_iterator(filePath)) {
                if (entry.path().extension().string() == ".txt")
                    std::cout << entry.path().filename() << std::endl;
            }
        }
        catch (const std::filesystem::filesystem_error& ex) {
            system("cls");
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << "Choice: ";
        std::cin >> fileChoice;
        filePath = fs::current_path().string() + "\\" + fileChoice + ".txt";

        if (fs::exists(filePath)) {
            system("cls");
            std::cout << "File chosen: " << fileChoice << "\nPath: " << filePath << std::endl;
            isPathFinderLooped = false;
            return;
        }

        else {
            system("cls");
            std::cout << "Incorrect file. Return?\n1. Yes\n2. No\nChoice: ";
            std::cin >> option;

            if (option == 1) {
                system("cls");
                isDirectoryContentsLooped = false;
                isPathFinderLooped = true;
            }

            else {
                system("cls");
                isDirectoryContentsLooped = true;
            }
        }

    }
    return;
}

void FinderClass::PathFinder() {

    while (isPathFinderLooped) {
        system("cls");
        std::cout << "1. Enter absolute path\n2. Choose a file from the program directory\nChoice: ";
        std::cin >> fileChoice;

        if (fileChoice == "1") {
            AbsolutePath();
        }

        else {
            DirectoryContents();
        }

    }
}