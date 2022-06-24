#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"
#include "fstream"

bool checkIsGoodKey(std::string &s);
void readCategories(std::vector<Category> &v);
void readPassword(std::vector<Password> &v);

int main() {    /*
    password5.codePassword(true);
    password1.codePassword(true);
    password2.codePassword(true);


    std::cout << "PRZERWA" << std::endl;

    /*
    password5.decodePassword(true);
    password1.decodePassword(true);
    password2.decodePassword(false);
     */

    /*
    std::string key;
    std :: cout << "Wpisz haslo do pliku" << std::endl;
    std::cin >> key;
    bool mainKey = checkIsGoodKey(key);
     */

    /*
    bool mainKey = true;

    Category category1 {"Pierwsza",1};
    Category category2 {"Druga",2};
    std::vector<Category> kategorie;
    kategorie.push_back(category1);
    kategorie.push_back(category2);

    Password password1 {"Do google1","haslo1", "12345", category1,mainKey};
    Password password2 {"Do google2","haslo2", "1234", category1,mainKey};
    Password password3 {"Do google3","haslo3", "123", category1,mainKey};
    Password password4 {"Do google4","haslo4", "12", category1,mainKey};
    Password password5 {"A","haslo4", "12", category2,mainKey};

    std::vector<Password> hasla;
    hasla.push_back(password1);
    hasla.push_back(password2);
    hasla.push_back(password3);
    hasla.push_back(password4);
    hasla.push_back(password5);

    Manager manager {hasla,kategorie};
    manager.writeToFile();
    */


    std::vector<Category> categories;
   readCategories(categories);
   for(int i = 0; i < categories.size(); i++)
       categories[i].show();

    return 0;
}

bool checkIsGoodKey(std::string &s){
    std::string orginalKey;

    std::ifstream fileInput;
    std::string fileName = "C:\\Users\\Piotr Zadykowicz\\Desktop\\PasswordManager\\wejscie.txt";
    fileInput.open(fileName);

    std::getline(fileInput,orginalKey);
    fileInput.close();
    std::cout << orginalKey << std::endl;

    if(orginalKey== s) {
        return true;
    }
    else
        return false;

}

void readCategories(std::vector<Category> &v){
    std::ifstream fileInput;
    std::string fileName = "C:\\Users\\Piotr Zadykowicz\\Desktop\\PasswordManager\\test.txt";
    fileInput.open(fileName);

    std::string line;

    std :: string name;
    std :: string category;
    int index;

    while(fileInput >> category>> name>> index){
        {
            if(category == "Category:"){
                Category tmp {name,index};
                v.push_back(tmp);
            }
        }
    }
}


void readPassword(std::vector<Password> &v){
    std::ifstream fileInput;
}