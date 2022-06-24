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

    void show();

    void codePassword(bool goodKey);
    void decodePassword(bool goodKey);

    friend std::ostream &operator<<(std::ostream &os, const Password &password);
};


#endif //PASSWORDMANAGER_PASSWORD_H
