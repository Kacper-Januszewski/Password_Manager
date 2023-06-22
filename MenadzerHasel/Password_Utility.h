#ifndef Password_Utility_h
#define Password_Utility_h

#include <iostream>
#include <string>
#include <cctype>

class PasswordUtility {

public:

    /**
* \brief Weryfikator si�y has�a.
*
* Funkcja sprawdza czy has�o jest d�u�sze ni� 5, oraz czy posiada znaki specjalne, wielkie litery oraz liczby.
* Przy ka�dym spe�nionym warunku zwi�ksza si� si�a has�a a na koniec wy�wietlany jest komentarz odpowiedni do si�y.
*
* \param password funkcja przyjmuje podane has�o jako argument.
* \return string funkcja zwraca opis jak silne jest has�o.
*/
    std::string PasswordStrength(std::string password);

    /**
    * \brief Generator hase�.
    * 
    * U�ytkownik wybiera d�ugo�� has�a, czy has�o ma zawiera� znaki specjalne, wielkie litery oraz liczby. Przy ka�dym wyborze na tak do stringa z mo�liwymi znakami dodawne s� odpowiednie znaki.
    * Po czym generowane jest has�o, u�ytkownik mo�e potwierdzi� lub wygenerowa� je ponownie.
    * 
    * \param NULL funkcja nie przyjmuje argument�w.
    * \return string funkcja zwraca wygenerowane has�o.
    */
    std::string PasswordGenerator();

private:
    std::string generatedPassword;
    int safetyMeasure = 0, passwordLength = 0, option = 0;
    bool hasSpecialCharacter = false, hasCapitalLetter = false, hasNumber = false, isPasswordGeneratorLooped = true;

};

#endif // !Password_Utility_h
