#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"
#include "fstream"
void readPassword(std::vector<Category> &v);

int main() {
    Category category1 {"Pierwsza",1};
    Category category2 {"Druga",2};
    std::vector<Category> kategorie;
    kategorie.push_back(category1);
    kategorie.push_back(category2);

    Password password1 {"Do google1","haslo1", "12345", category1};
    Password password2 {"Do google2","haslo2", "1234", category1};
    Password password3 {"Do google3","haslo3", "123", category1};
    Password password4 {"Do google4","haslo4", "12", category1};
    Password password5 {"A","haslo4", "12", category2};

    /*
    password5.codePassword(true);
    password1.codePassword(true);
    password2.codePassword(true);


    std::cout << "PRZERWA" << std::endl;

    /*
    password5.decodePassword(true);
    password1.decodePassword(true);
    password2.decodePassword(false);
     */
    std::vector<Password> hasla;
    hasla.push_back(password1);
    hasla.push_back(password2);
    hasla.push_back(password3);
    hasla.push_back(password4);
    hasla.push_back(password5);

    Manager manager {hasla,kategorie};
    manager.writeToFile();
    return 0;
}

void readPassword(std::vector<Category> &v){
    std::ifstream fileInput;
}