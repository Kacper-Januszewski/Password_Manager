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
* Funkcja przyjmuje dane do zaszyfrowania wraz z has�em szyfruj�cym, po czym ka�d� warto�� znaku has�a podnosi do pot�gi drugiej i dodaje do ��cznej warto�ci klucza szyfruj�cego.
* Nast�pnie ka�dy znak z danych mno�y przez warto�� klucza oraz dodaje do string streama ze spacj� pomi�dzy znakami. Na koniec zwraca warto�� jako string.
*
* \param data dane do zaszyfrowania.
* \param password has�o szyfruj�ce.
* \return string zaszyfrowane dane.
*/
    std::string Encrypt(const std::string& data, const std::string& password);

    /**
* \brief Funkcja rozszyfrowania.
*
* Funkcja przyjmuje dane do rozszyfrowania wraz z has�em szyfruj�cym, po czym ka�d� warto�� znaku has�a podnosi do pot�gi drugiej i dodaje do ��cznej warto�ci klucza szyfruj�cego.
* Nast�pnie dop�ki mo�na wczyta� kolejny znak ze string streama. Ka�d� warto�� znaku z danych dzieli przez warto�� klucza oraz dodaje do string streama. Na koniec zwraca warto�� jako string.
*
* \param data dane do rozszyfrowania.
* \param password has�o szyfruj�ce.
* \return string rozszyfrowane dane.
*/
    std::string Decrypt(const std::string& data, const std::string& password);
};