//
// Created by Piotr Zadykowicz on 22.06.2022.
//

#ifndef PASSWORDMANAGER_MANAGER_H
#define PASSWORDMANAGER_MANAGER_H

#include "vector"
#include "Password.h"
#include "Category.h"


class Manager {
    std::vector <Password> passwords;
    std::vector <Category> categories;

public:
    Manager(const std::vector<Password> &passwords);

    void findPassword();
    void sortPasswords();
    void addPassword();
    void editPassword();
    void deletePassword(Password password);
    void addCategory();
    void deleteCategory();
    void showPasswords();

    void printMenu();
    int isSafe(std::string password);
    std::string createPassword();
};


#endif //PASSWORDMANAGER_MANAGER_H
