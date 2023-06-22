#ifndef Path_Finder_h
#define Path_Finder_h

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

class FinderClass {

public:

    /**
* \brief Menu wybierania pliku przez �cie�k� absolutn�.
*
* Wy�wietlana jest informacja o podanie �cie�ki absolutnej i u�ytkownik proszony jest o jej wprowadzenie.
* W przypadku gdy plik istnieje, wy�wietla si� informacja, �e zosta� on wybrany oraz jego �cie�ka.
* W przeciwnym przypadku wy�wietla si� pytanie czy stworzy� plik, wpisa� ponownie lub powr�ci� do poprzedniego menu.
* 
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void AbsolutePath();

    /**
* \brief Menu wybierania pliku z folderu programu.
*
* Wy�wietlane s� pliki w folderze programu, i u�ytkownik proszony jest o wprowadzenie nazwy pliku, kt�ry chce otworzy�.
* W przypadku gdy plik istnieje, wy�wietla si� informacja, �e zosta� on wybrany oraz jego �cie�ka.
* W przeciwnym przypadku wy�wietla si� informacja, �e podana zosta�a z�a nazwa.
*
* \param NULL funkcja nie przyjmuje argument�w.
* \return NULL funkcja nie zwraca warto�ci.
*/
    void DirectoryContents();
    
    /**
    * \brief Menu wybierania pliku.
    * 
    * W zale�no�ci od wyboru u�ytkownika uruchamiana jest funkcja wyboru �cie�ki absolutnej lub wyboru pliku z folderu programu.
    * 
    * \param NULL funkcja nie przyjmuje argument�w.
    * \return NULL funkcja nie zwraca warto�ci.
    */
    void PathFinder();
    std::string filePath;

private:
    std::string fileChoice;
    bool isAbsolutePathLooped = true, isPathFinderLooped = true, isDirectoryContentsLooped = true;
    int option = 0;
};

#endif // !PATH_FINDER_H