#include "Password.h"
#include "iostream"

Password::Password(const std::string &name, const std::string &password, const std::string &login, int category) : name(
        name), password(password), login(login), category(category) {}

void Password::show() {
    std::cout << "name: " << this->name << " login: " << this ->login << " password " << this -> password << " category " << this -> category << std::endl;
}

const std::string &Password::getPassword() const {
    return password;
}

int Password::isSafe(std::string &password) {
    //to check if all parameters are fine
    int counter = 0;
    if(password.length() > 10)
}





