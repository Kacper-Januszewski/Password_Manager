#include "Reader.h"

std::vector<std::string> Reader::Split(std::string lineToSplit)
{
    std::stringstream stream(lineToSplit);
    segments.clear();
    while (std::getline(stream, segment, '"')) {
            segments.push_back(segment);
    }
    return segments;
}

std::vector<Password_Data> Reader::Find(std::vector<Password_Data> passwordVector, int type, std::string input) //name, letter, category, site, login
{
    tmp.clear();
        switch (type) {

        case 1: //Specific name
            for (auto el : passwordVector) {
                if (el.getName() == input) {
                    tmp.push_back(el);
                }
            }
            break;
            
        case 2: //Name containing a letter
            for(auto el : passwordVector){
                if (el.getName().find(input) != std::string::npos) {
                    tmp.push_back(el);
                }
                }
                break;
        case 3: //By category
            for (auto el : passwordVector) {
                if (el.getCategory() == input) {
                    tmp.push_back(el);
                }
            }
            break;
        case 4: //By site
            for (auto el : passwordVector) {
                if (el.getSize() == 1) {
                    if (el.getSite() == input) {
                        tmp.push_back(el);
                    }
                }
            }
            break;
        case 5: //By login
            for (auto el : passwordVector) {
                if (el.getSize() == 1) {
                    if (el.getLogin() == input) {
                        tmp.push_back(el);
                    }
                }
            }
            break;
        case 6: //All
            for (auto el : passwordVector) {
                tmp.push_back(el);
            }
            break;
        case 7: //Password
            for (auto el : passwordVector) {
                if (el.getPassword() == input) {
                    tmp.push_back(el);
                }
            }
            break;
        default:
            std::cout << "Error in finding your choice, default case selected.\n";
            return tmp;
            }
        return tmp;
        }

std::vector<std::string> Reader::Show(std::vector<Password_Data> passwordVector, int type) {
    stringtmp.clear();
    for (auto el : passwordVector) {
        switch (type) {
        case 1: //Specific name
            stringtmp.push_back(el.getName());
            break;
        case 2: //Name containing a letter
            break;
        case 3: //By category
            stringtmp.push_back(el.getCategory());
            break;
        case 4: //By site
            if (el.getSize() == 1) {
                stringtmp.push_back(el.getSite());
            }
            break;
        case 5: //By login
            if (el.getSize() == 1) {
                stringtmp.push_back(el.getLogin());
            }
            break;
        case 6: //All
            break;
        case 7: //Password
            break;
        case 8: //Details
            break;
        default:
            break;
        }
    }
    return stringtmp;
}

std::vector<Password_Data> Reader::Read(std::string fileToRead)
{
    std::ifstream file_in(fileToRead);
    tmp.clear();
    if (file_in.is_open()) {
        while (std::getline(file_in, line)) {
                Split(line);
                switch (segments.size()) {
                case 0:
                    //Empty line //std::cout << "Empty line.\n\n";
                    break;
                case 1:
                    //key line;
                    break;
                case 3:
                    password = Password_Data{ segments.at(0), segments.at(1), segments.at(2) };
                    tmp.push_back(password);
                    break;
                case 5:
                    password = Password_Data{ segments.at(0), segments.at(1), segments.at(2), segments.at(3), segments.at(4) };
                    tmp.push_back(password);
                    break;
                default:
                    std::cout << "Error in Read(), default option chosen";
                    break;
                }
        }
        file_in.close();
    }
    else {
        std::cout << "Cannot open file.";
        return tmp;
    }
    return tmp;
}

bool Reader::hasKey(std::string fileToRead) {
    std::ifstream file_in(fileToRead);

    if (file_in.is_open()) {
        if(std::getline(file_in, line)){
            return true;
        }
        else {
            return false;
        }
        file_in.close();
        }
    else {
        std::cout << "Cannot open file.";
        return NULL;
    }
}

std::string Reader::getKey(std::string fileToRead) {
    std::ifstream file_in(fileToRead);

    if (file_in.is_open()) {
        std::getline(file_in, line);
        file_in.close();
        return line;
    }
    else {
        std::cout << "Cannot open file.";
        return "No key found";
    }
}

std::vector<int> Reader::getTimestamp(std::string fileToRead) {
    std::ifstream file_in_time(fileToRead);
    inttmp.clear();
    segments.clear();
    if (file_in_time.is_open()) {
        std::getline(file_in_time, line);
        std::getline(file_in_time, line);
        Split(line);
        for (std::string segment : segments) {
            inttmp.push_back(stoi(segment));
        }
        file_in_time.close();
        return inttmp;
    }
}