#ifndef PASSWORDMANAGER_PASSWORD_H
#define PASSWORDMANAGER_PASSWORD_H

#include <string>
#include "Category.h"

class Password {
    std::string name;
    std::string password;
    std::string login;
    Category category;

public:
    Password(const std::string &name, const std::string &password, const std::string &login, const Category &category);

    const std::string &getName() const;

    const std::string &getPassword() const;

    const std::string &getLogin() const;

    const Category &getCategory() const;

    void setName(const std::string &name);

    void setPassword(const std::string &password);

    void setLogin(const std::string &login);

    void setCategory(const Category &category);

    void show();
};


#endif //PASSWORDMANAGER_PASSWORD_H
