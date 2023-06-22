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
* \brief Funkcja czytania z pliku do wektora klasy hase³.
*
* Funkcja otwiera plik i na podstawie iloœci segmentów stwierdza jaki obiekt stworzyæ, na koniec zwraca wektor tych obiektów.
*
* \param fileToRead œcie¿ka pliku do odczytania.
* \return wektor klasy has³a.
*/
	std::vector<Password_Data> Read(std::string fileToRead);

	/**
* \brief Funkcja dzielenia danych typu string.
*
* Funkcja przyjmuje string i na podstawie podanego rozdzielnika dzieli dane na osobne fragmenty, dodaj¹c je do wektora stringów.
*
* \param line pojedyncza linia pliku typu string.
* \return wektor stringów z informacjami o zapisanych danych.
*/
	std::vector<std::string> Split(std::string line);

	/**
* \brief Funkcja wyszukiwania danych.
*
* Funkcja przyjmuje wektor klasy hase³ i na podstawie danego typu oraz nazwy wyszukiwania, szuka w wektorze obiektów spe³niaj¹cych warunek, po czym dodaje je do wektora roboczego.
* Na koniec wektor roboczy jest zwracany.
*
* \param passwordVector istniej¹cy wektor klasy hase³.
* \param type argument decyduj¹cym o rodzaju wyszukiwania.
* \param input argument decyduj¹cy czego dok³adnie wyszukaæ.
* \return wektor klasy hase³ z obiektami spe³niaj¹cymi warunek.
*/
	std::vector<Password_Data> Find(std::vector<Password_Data> passwordVector, int type, std::string input);

	/**
* \brief Funkcja wyœwietlania danych.
*
* Funkcja przyjmuje wektor klasy hase³ i na podstawie danego typu, dodaje odpowiednie parametry do wektora stringów, który na koniec jest zwracany.
* Na koniec wektor roboczy jest zwracany.
*
* \param passwordVector istniej¹cy wektor klasy hase³.
* \param type argument decyduj¹cym o rodzaju wyœwietlania.
* \return wektor stringów spe³niaj¹cych warunek.
*/
	std::vector<std::string> Show(std::vector<Password_Data> passwordVector, int type);

	/**
* \brief Funkcja sprawdzania czy istnieje klucz.
*
* Funkcja sprawdza czy istniej¹ dane zapisane w pliku, je¿eli tak to zwraca wartoœæ true.
*
* \param fileToRead œcie¿ka pliku do odczytania.
* \return bool okreœlaj¹cy czy w pliku jest klucz.
*/
	bool hasKey(std::string fileToRead);

	/**
* \brief Funkcja pobierania klucza.
*
* Funkcja czyta pierwsz¹ linijkê pliku, która jest kluczem.
*
* \param fileToRead œcie¿ka pliku do odczytania.
* \return string z kluczem.
*/
	std::string getKey(std::string fileToRead);

	/**
* \brief Funkcja pobierania timestampu.
*
* Funkcja odczytuje drug¹ linijkê pliku, po czym rozdziela j¹ na czêœci aby móc nadaæ w³aœciwe wartoœci parametrom timestampu.
*
* \param fileToRead œcie¿ka pliku do odczytania.
* \return wektor intów, przechowuj¹cy parametry timestampu.
*/
	std::vector<int> getTimestamp(std::string fileToRead);
};