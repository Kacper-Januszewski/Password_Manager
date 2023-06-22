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
* \brief Menu wybierania pliku przez œcie¿kê absolutn¹.
*
* Wyœwietlana jest informacja o podanie œcie¿ki absolutnej i u¿ytkownik proszony jest o jej wprowadzenie.
* W przypadku gdy plik istnieje, wyœwietla siê informacja, ¿e zosta³ on wybrany oraz jego œcie¿ka.
* W przeciwnym przypadku wyœwietla siê pytanie czy stworzyæ plik, wpisaæ ponownie lub powróciæ do poprzedniego menu.
* 
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void AbsolutePath();

    /**
* \brief Menu wybierania pliku z folderu programu.
*
* Wyœwietlane s¹ pliki w folderze programu, i u¿ytkownik proszony jest o wprowadzenie nazwy pliku, który chce otworzyæ.
* W przypadku gdy plik istnieje, wyœwietla siê informacja, ¿e zosta³ on wybrany oraz jego œcie¿ka.
* W przeciwnym przypadku wyœwietla siê informacja, ¿e podana zosta³a z³a nazwa.
*
* \param NULL funkcja nie przyjmuje argumentów.
* \return NULL funkcja nie zwraca wartoœci.
*/
    void DirectoryContents();
    
    /**
    * \brief Menu wybierania pliku.
    * 
    * W zale¿noœci od wyboru u¿ytkownika uruchamiana jest funkcja wyboru œcie¿ki absolutnej lub wyboru pliku z folderu programu.
    * 
    * \param NULL funkcja nie przyjmuje argumentów.
    * \return NULL funkcja nie zwraca wartoœci.
    */
    void PathFinder();
    std::string filePath;

private:
    std::string fileChoice;
    bool isAbsolutePathLooped = true, isPathFinderLooped = true, isDirectoryContentsLooped = true;
    int option = 0;
};

#endif // !PATH_FINDER_H