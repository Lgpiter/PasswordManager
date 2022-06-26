#ifndef PASSWORDMANAGER_PASSWORD_H
#define PASSWORDMANAGER_PASSWORD_H

#include <string>
#include <ostream>
#include "Category.h"

class Password {
    std::string name;
    std::string password;
    std::string login;
    Category category;

    /**przekazanie czy uzytkownik podal dobre haslo do pliku*/
    bool goodKey;

public:
    Password(const std::string &name, const std::string &password, const std::string &login, const Category &category,
             bool goodKey);

    const std::string &getName() const;

    const std::string &getPassword() const;

    const std::string &getLogin() const;

    const Category &getCategory() const;

    void setName(const std::string &name);

    void setPassword(const std::string &password);

    void setLogin(const std::string &login);

    void setCategory(const Category &category);

    /** wypisuje na konsole informacje o hasle*/
    void show();

    /**sluzy do zakodowania hasla w celu zapisania do pliku */
    void codePassword();

    /**sluzy do rozkodowania hasel z pliku*/
    void decodePassword();

    friend std::ostream &operator<<(std::ostream &os, const Password &password);
};


#endif //PASSWORDMANAGER_PASSWORD_H
