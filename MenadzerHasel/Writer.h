#ifndef Writer_h
#define Writer_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Password_Data.h>

class Writer {
private:
    std::string targetFile;
    std::string wrtKey;
    std::string wrtCategory;
    std::string wrtName;
    std::string wrtPassword;
    std::string wrtSite;
    std::string wrtLogin;

public:
    Writer() = default;
    Writer(std::string targetFile, std::string wrtKey)
        : targetFile(targetFile), wrtKey(wrtKey) {}

    Writer(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword)
        : targetFile(targetFile), wrtCategory(wrtCategory), wrtName(wrtName), wrtPassword(wrtPassword) {}

    Writer(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword, std::string wrtSite, std::string wrtLogin)
        : targetFile(targetFile), wrtCategory(wrtCategory), wrtName(wrtName), wrtPassword(wrtPassword), wrtSite(wrtSite), wrtLogin(wrtLogin) {}

    /**
* \brief Funkcja zapisywania timestampu do pliku.
*
* Funkcja przyjmuje �cie�k� pliku, klucz do zapisania, oraz warto�ci parametr�w timestampu. Po czym zapisuje je po kolei do pliku, oddzielaj�c parametry cudzys�owem - " ..
*
* \param targetFile �cie�ka do pliku.
* \param wrtKey klucz do zapisania.
* \param seconds sekundy timestampu.
* \param minutes minuty timestampu.
* \param hours godziny timestampu.
* \param wday kt�ry dzie� tygodnia.
* \param mday kt�ry dzie� miesi�ca.
* \param month kt�ry miesi�c.
* \param year kt�ry rok.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void timestampWrite(std::string targetFile, std::string wrtKey, int seconds, int minutes, int hours, int wday, int mday, int month, int year);
    
    /**
* \brief Funkcja zapisywania klucza do pliku.
*
* Funkcja przyjmuje �cie�k� pliku i klucz do zapisania. Po czym zapisuje klucz do pliku.
*
* \param targetFile �cie�ka do pliku.
* \param wrtKey klucz do zapisania.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void KeyWrite(std::string targetFile, std::string wrtKey);
    
    /**
* \brief Funkcja zapisywania podstawowych danych do pliku.
*
* Funkcja przyjmuje �cie�k� pliku oraz zaszyfrowane: kategori�, nazw�, has�o. Po czym zapisuje je do pliku, oddzielaj�c parametry cudzys�owem - " .
*
* \param targetFile �cie�ka do pliku.
* \param wrtCategory kategoria do zapisania.
* \param wrtName nazwa do zapisania.
* \param wrtPassword has�o do zapisania.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void BasicWrite(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword);
    
    /**
* \brief Funkcja zapisywania rozszerzonych danych do pliku.
*
* Funkcja przyjmuje �cie�k� pliku oraz zaszyfrowane: kategori�, nazw�, has�o, stron�, login. Po czym zapisuje je do pliku, oddzielaj�c parametry cudzys�owem - " .
*
* \param targetFile �cie�ka do pliku.
* \param wrtCategory kategoria do zapisania.
* \param wrtName nazwa do zapisania.
* \param wrtPassword has�o do zapisania.
* \param wrtSite strona do zapisania.
* \param wrtLogin login do zapisania.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void FullWrite(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword, std::string wrtSite, std::string wrtLogin);
    
    /**
* \brief Funkcja nadpisywania danych do pliku.
*
* Funkcja przyjmuje �cie�k� pliku, wektor hase� do zapisania, klucz szyfrowania oraz parametry timestampu. Po czym zapisuje wszystko do pliku.
*
* \param targetFile �cie�ka do pliku.
* \param rewriteData wektor nadpisywanych danych.
* \param wrtKey klucz do szyfrowania.
* \param seconds sekundy timestampu.
* \param minutes minuty timestampu.
* \param hours godziny timestampu.
* \param wday kt�ry dzie� tygodnia.
* \param mday kt�ry dzie� miesi�ca.
* \param month kt�ry miesi�c.
* \param year kt�ry rok.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void Rewrite(std::string targetFile, std::vector<Password_Data> rewriteData, std::string wrtKey, int seconds, int minutes, int hours, int wday, int mday, int month, int year);
};

#endif //!Writer.h