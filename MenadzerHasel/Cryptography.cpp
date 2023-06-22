#include <Cryptography.h>

std::string Cryptography::Encrypt(const std::string& data, const std::string& password)
{
    key = 0;
    std::ostringstream encryptedData;
    for (int ch : password) {
        ch *= ch;

        key += ch;
    }

    for (int character : data) {

        character = character * key;

        encryptedData << character << " ";
    }

    return encryptedData.str();
}

std::string Cryptography::Decrypt(const std::string& data, const std::string& password)
{
    key = 0;
    std::ostringstream decryptedData;
    std::istringstream iss(data);

    for (int ch : password) {
        ch *= ch;

        key += ch;
    }

    while (iss >> encryptedChar) {
        char character = encryptedChar / key;
        decryptedData << character;
    }

    return decryptedData.str();
}