#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <Password_Data.h>

class Reader {
private:
	std::string fileToRead;
	std::string line;
	std::string lineToSplit;
	std::string segment;
	std::vector<std::string> segments;
	Password_Data password;
	std::vector<Password_Data> tmp;
	std::vector<std::string> stringtmp;
	std::vector<int> inttmp;
	std::string input;
public:
	Reader() = default;

	/**
* \brief Funkcja czytania z pliku do wektora klasy hase�.
*
* Funkcja otwiera plik i na podstawie ilo�ci segment�w stwierdza jaki obiekt stworzy�, na koniec zwraca wektor tych obiekt�w.
*
* \param fileToRead �cie�ka pliku do odczytania.
* \return wektor klasy has�a.
*/
	std::vector<Password_Data> Read(std::string fileToRead);

	/**
* \brief Funkcja dzielenia danych typu string.
*
* Funkcja przyjmuje string i na podstawie podanego rozdzielnika dzieli dane na osobne fragmenty, dodaj�c je do wektora string�w.
*
* \param line pojedyncza linia pliku typu string.
* \return wektor string�w z informacjami o zapisanych danych.
*/
	std::vector<std::string> Split(std::string line);

	/**
* \brief Funkcja wyszukiwania danych.
*
* Funkcja przyjmuje wektor klasy hase� i na podstawie danego typu oraz nazwy wyszukiwania, szuka w wektorze obiekt�w spe�niaj�cych warunek, po czym dodaje je do wektora roboczego.
* Na koniec wektor roboczy jest zwracany.
*
* \param passwordVector istniej�cy wektor klasy hase�.
* \param type argument decyduj�cym o rodzaju wyszukiwania.
* \param input argument decyduj�cy czego dok�adnie wyszuka�.
* \return wektor klasy hase� z obiektami spe�niaj�cymi warunek.
*/
	std::vector<Password_Data> Find(std::vector<Password_Data> passwordVector, int type, std::string input);

	/**
* \brief Funkcja wy�wietlania danych.
*
* Funkcja przyjmuje wektor klasy hase� i na podstawie danego typu, dodaje odpowiednie parametry do wektora string�w, kt�ry na koniec jest zwracany.
* Na koniec wektor roboczy jest zwracany.
*
* \param passwordVector istniej�cy wektor klasy hase�.
* \param type argument decyduj�cym o rodzaju wy�wietlania.
* \return wektor string�w spe�niaj�cych warunek.
*/
	std::vector<std::string> Show(std::vector<Password_Data> passwordVector, int type);

	/**
* \brief Funkcja sprawdzania czy istnieje klucz.
*
* Funkcja sprawdza czy istniej� dane zapisane w pliku, je�eli tak to zwraca warto�� true.
*
* \param fileToRead �cie�ka pliku do odczytania.
* \return bool okre�laj�cy czy w pliku jest klucz.
*/
	bool hasKey(std::string fileToRead);

	/**
* \brief Funkcja pobierania klucza.
*
* Funkcja czyta pierwsz� linijk� pliku, kt�ra jest kluczem.
*
* \param fileToRead �cie�ka pliku do odczytania.
* \return string z kluczem.
*/
	std::string getKey(std::string fileToRead);

	/**
* \brief Funkcja pobierania timestampu.
*
* Funkcja odczytuje drug� linijk� pliku, po czym rozdziela j� na cz�ci aby m�c nada� w�a�ciwe warto�ci parametrom timestampu.
*
* \param fileToRead �cie�ka pliku do odczytania.
* \return wektor int�w, przechowuj�cy parametry timestampu.
*/
	std::vector<int> getTimestamp(std::string fileToRead);
};