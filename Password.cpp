#include "Password.h"
#include "iostream"



void Password::show() {
    std::cout << "name: " << this->name << " login: " << this ->login << " password " << this -> password << " category " << this -> category << std::endl;
}

const std::string &Password::getPassword() const {
    return password;
}

Password::Password(const std::string &name, const std::string &password, const std::string &login,
                   const Category &category) : name(name), password(password), login(login), category(category) {}






