#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"

int main() {
    Password password1 {"Do google1","haslo1", "12345", 1};
    Password password2 {"Do google2","haslo2", "1234", 2};
    Password password3 {"Do google3","haslo3", "123", 3};
    Password password4 {"Do google4","haslo4", "12", 4};

    std::vector<Password> hasla;
    hasla.push_back(password1);
    hasla.push_back(password2);
    hasla.push_back(password3);
    hasla.push_back(password4);

    Manager manager {hasla};
    manager.showPasswords();

    std::cout<<"TEST dodania" << std::endl;
    manager.addPassword();
    return 0;
}
