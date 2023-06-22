#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

class Cryptography {
private:
    int key = 0;
    std::string cypher;
    std::ostringstream encryptedData;
    std::ostringstream decryptedData;
    std::istringstream iss;
    int encryptedChar;

public:
    Cryptography() = default;

    /**
* \brief Funkcja szyfrowania.
*
* Funkcja przyjmuje dane do zaszyfrowania wraz z has³em szyfruj¹cym, po czym ka¿d¹ wartoœæ znaku has³a podnosi do potêgi drugiej i dodaje do ³¹cznej wartoœci klucza szyfruj¹cego.
* Nastêpnie ka¿dy znak z danych mno¿y przez wartoœæ klucza oraz dodaje do string streama ze spacj¹ pomiêdzy znakami. Na koniec zwraca wartoœæ jako string.
*
* \param data dane do zaszyfrowania.
* \param password has³o szyfruj¹ce.
* \return string zaszyfrowane dane.
*/
    std::string Encrypt(const std::string& data, const std::string& password);

    /**
* \brief Funkcja rozszyfrowania.
*
* Funkcja przyjmuje dane do rozszyfrowania wraz z has³em szyfruj¹cym, po czym ka¿d¹ wartoœæ znaku has³a podnosi do potêgi drugiej i dodaje do ³¹cznej wartoœci klucza szyfruj¹cego.
* Nastêpnie dopóki mo¿na wczytaæ kolejny znak ze string streama. Ka¿d¹ wartoœæ znaku z danych dzieli przez wartoœæ klucza oraz dodaje do string streama. Na koniec zwraca wartoœæ jako string.
*
* \param data dane do rozszyfrowania.
* \param password has³o szyfruj¹ce.
* \return string rozszyfrowane dane.
*/
    std::string Decrypt(const std::string& data, const std::string& password);
};