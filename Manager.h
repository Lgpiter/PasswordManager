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
    std::string lastTimeStamp;

public:
    Manager(const std::vector<Password> &passwords, const std::vector<Category> &categories);

    Manager(const std::vector<Password> &passwords, const std::vector<Category> &categories,
            const std::string &lastTimeStamp);

    void findPassword();

    void sortType();

    template <typename functype1, typename funcType2>
    void sortPasswords(functype1 f1,funcType2 f2);

    void addPassword();
    void editPassword();
    void deletePassword();
    void addCategory();
    void deleteCategory();
    void showPasswords();

    void writeToFile();

    void printMenu();
    void showLastTimeOpened();
    static int isSafe(const std::string& password);
    static std::string createPassword();
};


#endif //PASSWORDMANAGER_MANAGER_H
