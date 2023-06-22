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
* Funkcja przyjmuje œcie¿kê pliku, klucz do zapisania, oraz wartoœci parametrów timestampu. Po czym zapisuje je po kolei do pliku, oddzielaj¹c parametry cudzys³owem - " ..
*
* \param targetFile œcie¿ka do pliku.
* \param wrtKey klucz do zapisania.
* \param seconds sekundy timestampu.
* \param minutes minuty timestampu.
* \param hours godziny timestampu.
* \param wday który dzieñ tygodnia.
* \param mday który dzieñ miesi¹ca.
* \param month który miesi¹c.
* \param year który rok.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void timestampWrite(std::string targetFile, std::string wrtKey, int seconds, int minutes, int hours, int wday, int mday, int month, int year);
    
    /**
* \brief Funkcja zapisywania klucza do pliku.
*
* Funkcja przyjmuje œcie¿kê pliku i klucz do zapisania. Po czym zapisuje klucz do pliku.
*
* \param targetFile œcie¿ka do pliku.
* \param wrtKey klucz do zapisania.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void KeyWrite(std::string targetFile, std::string wrtKey);
    
    /**
* \brief Funkcja zapisywania podstawowych danych do pliku.
*
* Funkcja przyjmuje œcie¿kê pliku oraz zaszyfrowane: kategoriê, nazwê, has³o. Po czym zapisuje je do pliku, oddzielaj¹c parametry cudzys³owem - " .
*
* \param targetFile œcie¿ka do pliku.
* \param wrtCategory kategoria do zapisania.
* \param wrtName nazwa do zapisania.
* \param wrtPassword has³o do zapisania.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void BasicWrite(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword);
    
    /**
* \brief Funkcja zapisywania rozszerzonych danych do pliku.
*
* Funkcja przyjmuje œcie¿kê pliku oraz zaszyfrowane: kategoriê, nazwê, has³o, stronê, login. Po czym zapisuje je do pliku, oddzielaj¹c parametry cudzys³owem - " .
*
* \param targetFile œcie¿ka do pliku.
* \param wrtCategory kategoria do zapisania.
* \param wrtName nazwa do zapisania.
* \param wrtPassword has³o do zapisania.
* \param wrtSite strona do zapisania.
* \param wrtLogin login do zapisania.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void FullWrite(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword, std::string wrtSite, std::string wrtLogin);
    
    /**
* \brief Funkcja nadpisywania danych do pliku.
*
* Funkcja przyjmuje œcie¿kê pliku, wektor hase³ do zapisania, klucz szyfrowania oraz parametry timestampu. Po czym zapisuje wszystko do pliku.
*
* \param targetFile œcie¿ka do pliku.
* \param rewriteData wektor nadpisywanych danych.
* \param wrtKey klucz do szyfrowania.
* \param seconds sekundy timestampu.
* \param minutes minuty timestampu.
* \param hours godziny timestampu.
* \param wday który dzieñ tygodnia.
* \param mday który dzieñ miesi¹ca.
* \param month który miesi¹c.
* \param year który rok.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void Rewrite(std::string targetFile, std::vector<Password_Data> rewriteData, std::string wrtKey, int seconds, int minutes, int hours, int wday, int mday, int month, int year);
};

#endif //!Writer.h