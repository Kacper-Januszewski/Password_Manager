#ifndef Password_Data_h
#define Password_Data_h

#include <string>

class Password_Data
{
private:
    std::string category;
    std::string name;
    std::string password;
    std::string site;
    std::string login;

public:
    Password_Data() = default;
    Password_Data(const std::string& category, const std::string& name, const std::string& password);
    Password_Data(const std::string& category, const std::string& name, const std::string& password, const std::string& site, const std::string& login);

    std::string getCategory() const;
    std::string getName() const;
    std::string getPassword() const;
    std::string getSite() const;
    std::string getLogin() const;
    int setSize(int newSize);
    int getSize() const;
    int size = 0;

};

#endif // !Password_Data.h