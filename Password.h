#ifndef PASSWORDMANAGER_PASSWORD_H
#define PASSWORDMANAGER_PASSWORD_H

#include <string>

class Password {
    std::string name;
    std::string password;
    std::string login;
    int category;

public:
    Password(const std::string &name, const std::string &password, const std::string &login, int category);

    const std::string &getPassword() const;

    int isSafe(std::string &password);

    void show();
};


#endif //PASSWORDMANAGER_PASSWORD_H
