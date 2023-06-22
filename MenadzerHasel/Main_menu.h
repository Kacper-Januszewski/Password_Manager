#ifndef Main_menu_h
#define Main_menu_h

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <Password_Data.h>
#include <Password_Utility.h>
#include <Path_Finder.h>
#include <Writer.h>
#include <Reader.h>
#include <Cryptography.h>

class Main_Menu {
	
public:
	std::string key;
	enum type { NAME = 1, LETTER, CATEGORY, SITE, LOGIN, ALL, PASSWORD, DETAILS };

	/**
* \brief Funkcja menu g��wnego.
*
* Na pocz�tku u�ytkownik proszony jest o podanie �cie�ki absolutnej lub wybranie pliku z folderu programu.
* Nast�pnie wykonywana jest funkcja KeyMenu(), kt�ra sprawdza poprawno�� has�a, b�d� nadaje has�o w nowym pliku.
* Gdy nie wyst�pi� �adne b��dy dane z pliku przypisywane s� do wektora, nast�pnie kategorie z wektora wprowadzane s� do zmiennej std::set<std::string> przechowuj�cej kategorie.
* Gdy u�ytkownik poda z�e has�o, b�d� wyst�pi inny niespodziewany b��d, zapisywany jest timestamp i program ko�czy dzia�anie.
* P�niej wy�wietlane jest menu g��wne i u�ytkownik mo�e wybra� czy chce operowa� na has�ach czy na kategoriach, mo�e r�wnie� zako�czy� dzia�anie programu.
* Przy wyborze 3 opcji dane ca�ego pliku s� aktualizowane i zostaje on nadpisany.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void MainMenu();

	/**
* \brief Funkcja do wy�wietlania informacji.
*
* Funkcja przyjmuje typ kt�ry ma zosta� wy�wietlony, po czym wy�wietla rozszyfrowane elementy
*
* \param type typ do wy�wietlenia.
* \return funkcja nie zwraca warto�ci.
*/
	void Show(enum type type);

	/**
* \brief Funkcja do sprawdzania si�y has�a
*
* U�ytkownik proszony jest o podanie has�a, po czym sprawdzana jest jego si�a, na ko�cu u�ytkownik mo�e potwierdzi� has�o lub wpisa� nowe.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return funkcja zwraca potwierdzone has�o.
*/
	std::string PasswordCheckMenu();

	/**
* \brief Funkcja do wy�wietlania danych konkretnego has�a
*
* Gdy wektor z danymi jest pusty wy�wietlany jest komunikat, �e nie ma �adnych hase� do wy�wietlenia.
* W przeciwnym przypadku wy�wietlana jest lista dost�pnych hase� oraz 3 opcje (wybierz has�o, posortuj, wr��) z kt�rych u�ytkownik wybiera co chce zrobi�.
* W przypadku podania przez u�ytkownika konkretnej nazwy has�a wy�wietlane s� jego dane.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void PasswordShowMenu();

	/**
* \brief Wy�wietla menu hase�.
*
* U�ytkownik wybiera jak� czynno�� chce wykona� z 4 dost�pnych opcji (dodaj has�o, usu� has�o, wy�wietl has�o, wr��) po czym wywo�ywane s� odpowiednie funkcje.
* Gdy nie ma �adnych hase� w pliku a u�ytkownik chce usun�� has�o, wy�wietla si� komunikat, �e nie ma hase� do usuni�cia.
* W przeciwnym wypadku wy�wietlana jest lista hase� i u�ytkownik wprowadza r�cznie kt�re has�o chce usun��. Nast�pnie program nadpisuje plik korzystaj�c z wektora, bez usuni�tego has�a.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void PasswordMenu();

	/**
* \brief Wy�wietla list� kategorii oraz konkretne has�a z wybranej kategorii.
*
* Wy�wietlane s� wszystkie kategorie i u�ytkownik proszony jest o wybranie jednej z nich.
* U�ytkownik wybiera jak� kategori� chce wybra�, po czym program szuka wszystkich hase� z podan� kategori� i wy�wietla je na konsoli.
* Gdy nie ma �adnych kategorii dodanych, program wy�wietla komunikat o braku danych do pokazania.
* Gdy do danej kategorii s� przypisane has�a zostaj� one wy�wietlone ze wszystkimi informacjami, w przeciwnym wypadku wy�wietla si� komunikat, �e nie ma danych do wy�wietlenia.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void CategoryShowMenu();

	/**
* \brief Wy�wietla menu kategorii.
*
* U�ytkownik wybiera jak� czynno�� chce wykona� z 4 dost�pnych opcji (dodaj kategori�, usu� kategori�, wy�wietl kategorie, wr��) po czym wywo�ywane s� odpowiednie funkcje.
* Gdy u�ytkownik dodaje kategori� wst�pnie jest ona tylko dodawana do std::set<std::string>, dopiero przy dodawaniu has�a te dane s� zapisywane do pliku.
* Podczas pr�by usuni�cia kategorii, gdy nie ma �adnych kategorii zostaje wy�wietlony komunikat, �e nie ma kategorii do usuni�cia.
* W przeciwnym wypadku wy�wietlana jest lista kategorii i u�ytkownik proszony jest o wybranie kt�r� kategori� chce usun��,
* po czym wy�wietla si� informacja ile hase� zostanie usuni�tych oraz u�ytkownik proszony jest o potwierdzenie usuwania.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void CategoryMenu();

	/**
* \brief Wy�wietla opcje dodania has�a.
*
* Gdy nie ma dodanych �adnych kategorii wy�wietla si� komunikat aby wpierw doda� kategori�. W przeciwnym przypadku u�ytkownik wprowadza dane kt�rymi chce uzupe�ni� has�o.
* U�ytkownik mo�e wybra� czy chce uzupe�ni� stron� i login oraz czy has�o ma zosta� wygenerowane automatycznie lub wprowadzone r�cznie.
* Na sam koniec funkcja zapisuje dane do pliku.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void PasswordAddMenu();

	/**
* \brief Funkcja do wyszukiwania informacji.
*
* Funkcja znajduje obiekty klasy has�a spe�niaj�ce filtr wyszukiwania, przypisuje je do wektora roboczego, po czym wy�wietla ca�y ten wektor.
*
* \param passwordVector wektor z obiektami klasy has�a
* \param type typ wyszukiwania
* \return funkcja nie zwraca warto�ci.
*/
	void SearchMenu(std::vector<Password_Data> passwordVector, enum type type);

	/**
* \brief Funkcja do sprawdzania i wpisywania klucza pliku �r�d�owego oraz zapisywania timestampu.
*
* Gdy w pliku znajduje si� klucz, wy�wietlany jest timestamp ostatniej pr�by odszyfrowania pliku oraz u�ytkownik proszony jest o podanie has�a.
* Niezale�nie od tego czy podane has�o b�dzie poprawne, timestamp pr�by jest nadpisywany.
* Gdy has�o b�dzie poprawne, funkcja zwr�ci warto�� true i program b�dzie dalej kontynuowa�.
* W przeciwnym wypadku funkcja zwr�ci warto�� false i nast�pi zako�czenie programu.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return funkcja zwraca warto�� bool �wiadcz�c� o w�a�ciwych akcjach u�ytkownika.
*/
	bool KeyMenu();

	/**
* \brief Funkcja ustawiania timestampu.
*
* Funkcja tworzy nowy timestamp i przypisuje jego parametry do konkretnych zmiennych.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void timestampSet();

	/**
* \brief Funkcja wczytywania timestampu.
*
* Funkcja wczytuje timestamp i przypisuje odpowiednie warto�ci do w�a�ciwych zmiennych.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void timestampRead();

	/**
* \brief Funkcja wy�wietlania timestampu.
*
* Funkcja odpowiednio formatuje i wy�wietla warto�ci timestampu.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
	void timestampShow();
	

private:
	std::string search_input;
	std::string password_input;
	std::string name_input;
	std::string category_input = "";
	std::string site_input;
	std::string login_input;
	std::set<std::string> categorySet;
	std::set<std::string>::iterator setIterator = categorySet.begin();
	std::string fullSeparate = "\n====================\n";
	std::string halfSeparate = "\n--------------------\n";
	int option = 0;
	int position = 0;
	int secondsValue, minutesValue, hoursValue, day, dayOfMonth, month, year;
	bool isMainLooped = true;
	bool isPasswordLooped = true, isPasswordShowLooped = true, isCategoryLooped = true, isPasswordCheckLooped = true, isCategoryInputLooped = true;

	std::vector<Password_Data> Data_Vector;
	std::vector<Password_Data> Decrypted_Data_Vector;
	FinderClass initialFind;
	PasswordUtility passwordUtility;
	Writer writer;
	Reader reader;
	Cryptography crypter;
};

#endif // !Main_menu.h