#include "Password_Data.h"

Password_Data::Password_Data(const std::string& category, const std::string& name, const std::string& password)
    : category(category), name(name), password(password) {
    setSize(0);
}

    Password_Data::Password_Data(const std::string& category, const std::string& name, const std::string& password, const std::string& site, const std::string& login)
        : category(category), name(name), password(password), site(site), login(login) {
        setSize(1);
    }

    std::string Password_Data::getCategory() const {
        return category;
    }
    std::string Password_Data::getName() const {
        return name;
    }
    std::string Password_Data::getPassword() const {
        return password;
    }
    std::string Password_Data::getSite() const {
        return site;
    }
    std::string Password_Data::getLogin() const {
        return login;
    }
    int Password_Data::setSize(int newSize) {
        size = newSize;
        return size;
    }
    int Password_Data::getSize() const {
        return size;
    }