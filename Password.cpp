#include "Password.h"
#include "iostream"



void Password::show() {
    std::cout << "name: " << this->name << " login: " << this ->login << " password " << this -> password << " category " << category << std::endl;
}

const std::string &Password::getPassword() const {
    return password;
}

Password::Password(const std::string &name, const std::string &password, const std::string &login,
                   const Category &category) : name(name), password(password), login(login), category(category) {}

const Category &Password::getCategory() const {
    return category;
}

void Password::setName(const std::string &name) {
    Password::name = name;
}

void Password::setPassword(const std::string &password) {
    Password::password = password;
}

void Password::setLogin(const std::string &login) {
    Password::login = login;
}

void Password::setCategory(const Category &category) {
    Password::category = category;
}

const std::string &Password::getName() const {
    return name;
}

const std::string &Password::getLogin() const {
    return login;
}






