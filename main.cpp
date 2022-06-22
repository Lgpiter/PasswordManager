#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"

int main() {
    Category category1 {"Pierwsza",1};
    Password password1 {"Do google1","haslo1", "12345", category1};
    Password password2 {"Do google2","haslo2", "1234", category1};
    Password password3 {"Do google3","haslo3", "123", category1};
    Password password4 {"Do google4","haslo4", "12", category1};

    std::vector<Password> hasla;
    hasla.push_back(password1);
    hasla.push_back(password2);
    hasla.push_back(password3);
    hasla.push_back(password4);

    Manager manager {hasla};
    std::string test1  = "test";
    std::string test2  = "Test";
    std::string test3 = "Test%";
    std::string test4 = "Test%dsadjksandsaklda";
    std::cout << manager.isSafe(test1)<<std::endl;
    std::cout << manager.isSafe(test2)<<std::endl;
    std::cout << manager.isSafe(test3)<<std::endl;
    std::cout << manager.isSafe(test4)<<std::endl;

    manager.editPassword();
    manager.showPasswords();
    return 0;
}
