#ifndef Password_Utility_h
#define Password_Utility_h

#include <iostream>
#include <string>
#include <cctype>

class PasswordUtility {

public:

    /**
* \brief Weryfikator si³y has³a.
*
* Funkcja sprawdza czy has³o jest d³u¿sze ni¿ 5, oraz czy posiada znaki specjalne, wielkie litery oraz liczby.
* Przy ka¿dym spe³nionym warunku zwiêksza siê si³a has³a a na koniec wyœwietlany jest komentarz odpowiedni do si³y.
*
* \param password funkcja przyjmuje podane has³o jako argument.
* \return string funkcja zwraca opis jak silne jest has³o.
*/
    std::string PasswordStrength(std::string password);

    /**
    * \brief Generator hase³.
    * 
    * U¿ytkownik wybiera d³ugoœæ has³a, czy has³o ma zawieraæ znaki specjalne, wielkie litery oraz liczby. Przy ka¿dym wyborze na tak do stringa z mo¿liwymi znakami dodawne s¹ odpowiednie znaki.
    * Po czym generowane jest has³o, u¿ytkownik mo¿e potwierdziæ lub wygenerowaæ je ponownie.
    * 
    * \param NULL funkcja nie przyjmuje argumentów.
    * \return string funkcja zwraca wygenerowane has³o.
    */
    std::string PasswordGenerator();

private:
    std::string generatedPassword;
    int safetyMeasure = 0, passwordLength = 0, option = 0;
    bool hasSpecialCharacter = false, hasCapitalLetter = false, hasNumber = false, isPasswordGeneratorLooped = true;

};

#endif // !Password_Utility_h
