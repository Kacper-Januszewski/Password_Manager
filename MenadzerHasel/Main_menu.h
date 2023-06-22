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
* \brief Funkcja menu g³ównego.
*
* Na pocz¹tku u¿ytkownik proszony jest o podanie œcie¿ki absolutnej lub wybranie pliku z folderu programu.
* Nastêpnie wykonywana jest funkcja KeyMenu(), która sprawdza poprawnoœæ has³a, b¹dŸ nadaje has³o w nowym pliku.
* Gdy nie wyst¹pi¹ ¿adne b³êdy dane z pliku przypisywane s¹ do wektora, nastêpnie kategorie z wektora wprowadzane s¹ do zmiennej std::set<std::string> przechowuj¹cej kategorie.
* Gdy u¿ytkownik poda z³e has³o, b¹dŸ wyst¹pi inny niespodziewany b³¹d, zapisywany jest timestamp i program koñczy dzia³anie.
* PóŸniej wyœwietlane jest menu g³ówne i u¿ytkownik mo¿e wybraæ czy chce operowaæ na has³ach czy na kategoriach, mo¿e równie¿ zakoñczyæ dzia³anie programu.
* Przy wyborze 3 opcji dane ca³ego pliku s¹ aktualizowane i zostaje on nadpisany.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void MainMenu();

	/**
* \brief Funkcja do wyœwietlania informacji.
*
* Funkcja przyjmuje typ który ma zostaæ wyœwietlony, po czym wyœwietla rozszyfrowane elementy
*
* \param type typ do wyœwietlenia.
* \return funkcja nie zwraca wartoœci.
*/
	void Show(enum type type);

	/**
* \brief Funkcja do sprawdzania si³y has³a
*
* U¿ytkownik proszony jest o podanie has³a, po czym sprawdzana jest jego si³a, na koñcu u¿ytkownik mo¿e potwierdziæ has³o lub wpisaæ nowe.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return funkcja zwraca potwierdzone has³o.
*/
	std::string PasswordCheckMenu();

	/**
* \brief Funkcja do wyœwietlania danych konkretnego has³a
*
* Gdy wektor z danymi jest pusty wyœwietlany jest komunikat, ¿e nie ma ¿adnych hase³ do wyœwietlenia.
* W przeciwnym przypadku wyœwietlana jest lista dostêpnych hase³ oraz 3 opcje (wybierz has³o, posortuj, wróæ) z których u¿ytkownik wybiera co chce zrobiæ.
* W przypadku podania przez u¿ytkownika konkretnej nazwy has³a wyœwietlane s¹ jego dane.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void PasswordShowMenu();

	/**
* \brief Wyœwietla menu hase³.
*
* U¿ytkownik wybiera jak¹ czynnoœæ chce wykonaæ z 4 dostêpnych opcji (dodaj has³o, usuñ has³o, wyœwietl has³o, wróæ) po czym wywo³ywane s¹ odpowiednie funkcje.
* Gdy nie ma ¿adnych hase³ w pliku a u¿ytkownik chce usun¹æ has³o, wyœwietla siê komunikat, ¿e nie ma hase³ do usuniêcia.
* W przeciwnym wypadku wyœwietlana jest lista hase³ i u¿ytkownik wprowadza rêcznie które has³o chce usun¹æ. Nastêpnie program nadpisuje plik korzystaj¹c z wektora, bez usuniêtego has³a.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void PasswordMenu();

	/**
* \brief Wyœwietla listê kategorii oraz konkretne has³a z wybranej kategorii.
*
* Wyœwietlane s¹ wszystkie kategorie i u¿ytkownik proszony jest o wybranie jednej z nich.
* U¿ytkownik wybiera jak¹ kategoriê chce wybraæ, po czym program szuka wszystkich hase³ z podan¹ kategori¹ i wyœwietla je na konsoli.
* Gdy nie ma ¿adnych kategorii dodanych, program wyœwietla komunikat o braku danych do pokazania.
* Gdy do danej kategorii s¹ przypisane has³a zostaj¹ one wyœwietlone ze wszystkimi informacjami, w przeciwnym wypadku wyœwietla siê komunikat, ¿e nie ma danych do wyœwietlenia.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void CategoryShowMenu();

	/**
* \brief Wyœwietla menu kategorii.
*
* U¿ytkownik wybiera jak¹ czynnoœæ chce wykonaæ z 4 dostêpnych opcji (dodaj kategoriê, usuñ kategoriê, wyœwietl kategorie, wróæ) po czym wywo³ywane s¹ odpowiednie funkcje.
* Gdy u¿ytkownik dodaje kategoriê wstêpnie jest ona tylko dodawana do std::set<std::string>, dopiero przy dodawaniu has³a te dane s¹ zapisywane do pliku.
* Podczas próby usuniêcia kategorii, gdy nie ma ¿adnych kategorii zostaje wyœwietlony komunikat, ¿e nie ma kategorii do usuniêcia.
* W przeciwnym wypadku wyœwietlana jest lista kategorii i u¿ytkownik proszony jest o wybranie któr¹ kategoriê chce usun¹æ,
* po czym wyœwietla siê informacja ile hase³ zostanie usuniêtych oraz u¿ytkownik proszony jest o potwierdzenie usuwania.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void CategoryMenu();

	/**
* \brief Wyœwietla opcje dodania has³a.
*
* Gdy nie ma dodanych ¿adnych kategorii wyœwietla siê komunikat aby wpierw dodaæ kategoriê. W przeciwnym przypadku u¿ytkownik wprowadza dane którymi chce uzupe³niæ has³o.
* U¿ytkownik mo¿e wybraæ czy chce uzupe³niæ stronê i login oraz czy has³o ma zostaæ wygenerowane automatycznie lub wprowadzone rêcznie.
* Na sam koniec funkcja zapisuje dane do pliku.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void PasswordAddMenu();

	/**
* \brief Funkcja do wyszukiwania informacji.
*
* Funkcja znajduje obiekty klasy has³a spe³niaj¹ce filtr wyszukiwania, przypisuje je do wektora roboczego, po czym wyœwietla ca³y ten wektor.
*
* \param passwordVector wektor z obiektami klasy has³a
* \param type typ wyszukiwania
* \return funkcja nie zwraca wartoœci.
*/
	void SearchMenu(std::vector<Password_Data> passwordVector, enum type type);

	/**
* \brief Funkcja do sprawdzania i wpisywania klucza pliku Ÿród³owego oraz zapisywania timestampu.
*
* Gdy w pliku znajduje siê klucz, wyœwietlany jest timestamp ostatniej próby odszyfrowania pliku oraz u¿ytkownik proszony jest o podanie has³a.
* Niezale¿nie od tego czy podane has³o bêdzie poprawne, timestamp próby jest nadpisywany.
* Gdy has³o bêdzie poprawne, funkcja zwróci wartoœæ true i program bêdzie dalej kontynuowa³.
* W przeciwnym wypadku funkcja zwróci wartoœæ false i nast¹pi zakoñczenie programu.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return funkcja zwraca wartoœæ bool œwiadcz¹c¹ o w³aœciwych akcjach u¿ytkownika.
*/
	bool KeyMenu();

	/**
* \brief Funkcja ustawiania timestampu.
*
* Funkcja tworzy nowy timestamp i przypisuje jego parametry do konkretnych zmiennych.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void timestampSet();

	/**
* \brief Funkcja wczytywania timestampu.
*
* Funkcja wczytuje timestamp i przypisuje odpowiednie wartoœci do w³aœciwych zmiennych.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
	void timestampRead();

	/**
* \brief Funkcja wyœwietlania timestampu.
*
* Funkcja odpowiednio formatuje i wyœwietla wartoœci timestampu.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
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