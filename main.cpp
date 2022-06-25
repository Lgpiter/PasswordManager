#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"
#include "fstream"

bool checkIsGoodKey(std::string &s);
void readCategories(std::vector<Category> &v);
void readPassword(std::vector<Password> &v1,std::vector<Category> &v2, bool &mainKey);
void readListTimeStamp(std::string &timeStamp);

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

     */




    /*
    bool mainKey = true;

    Category category1 {"Pierwsza",1};
    Category category2 {"Druga",2};
    std::vector<Category> kategorie;
    kategorie.push_back(category1);
    kategorie.push_back(category2);

    Password password1 {"Do_google1","haslo1", "12345", category1,mainKey};
    Password password2 {"Do_google2","haslo2", "1234", category1,mainKey};
    Password password3 {"Do_google3","haslo3", "123", category1,mainKey};
    Password password4 {"Do_google4","haslo4", "12", category1,mainKey};
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


    std::string key;
    std :: cout << "Wpisz haslo do pliku" << std::endl;
    std::cin >> key;

    bool mainKey = checkIsGoodKey(key);

    std::string timeStamp;


    std::vector<Category> categories;
   readCategories(categories);

    if(mainKey){
        readListTimeStamp(timeStamp);

        std::vector<Password> passwords;
        readPassword(passwords,categories, mainKey);

        Manager manager {passwords,categories,timeStamp};
        manager.printMenu();
    }
    else{
        std::vector<Password> passwords;
        readPassword(passwords,categories, mainKey);

        Manager manager {passwords,categories};
        manager.showPasswords();
        manager.writeToFile();
    }
    /*
   std::vector<Password> passwords;
    readPassword(passwords,categories, mainKey);

    Manager manager {passwords,categories};
    manager.showPasswords();
    manager.printMenu();
     */

    return 0;
}

bool checkIsGoodKey(std::string &s){
    std::string orginalKey;

    std::ifstream fileInput;
    std::string fileName = "C:\\Users\\Piotr Zadykowicz\\Desktop\\PasswordManager\\test.txt";

    fileInput.open(fileName);
    std::getline(fileInput,orginalKey);
    fileInput.close();


    int pom;
    for(int i = 0; i < orginalKey.size(); i++){
        pom = orginalKey[i] - 135;
        orginalKey[i] = pom;
    }

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
    std::getline(fileInput,line);

    std :: string name;
    std :: string category;
    int index;

    while(fileInput >> category >> name>> index){
            if(category == "Category:"){
                Category tmp {name,index};
                v.push_back(tmp);
            }
    }

    fileInput.close();
}

void readPassword(std::vector<Password> &v1,std::vector<Category> &v2, bool &mainKey){
    std::ifstream fileInput;
    std::string fileName = "C:\\Users\\Piotr Zadykowicz\\Desktop\\PasswordManager\\test.txt";
    fileInput.open(fileName);

    std::string line;
    std::getline(fileInput,line);

    std :: string name;
    std :: string password;
    std :: string login;
    std :: string category;
    int categoryIndex;
    std :: string pom;

    while(fileInput >> pom){
           // std:: cout << pom<<"Name: " << name<<"Pass: " << password <<"Login: "<<login <<"Category: " << category <<"INDEX: " << categoryIndex;
            if(pom == "Password:") {
                fileInput >> name >> password >> login >> category >> categoryIndex;
                for (auto &i: v2) {
                    if (i.getIndex() == categoryIndex) {
                        Password tmp{name, password, login, i, mainKey};
                        tmp.decodePassword();
                        v1.push_back(tmp);
                    }
                }
            }
    }
}

void readListTimeStamp(std::string &timeStamp){
   std::vector<std::string> lines;
   std:: string line;

    std::ifstream fileInput;
    std::string fileName = "C:\\Users\\Piotr Zadykowicz\\Desktop\\PasswordManager\\test.txt";
    fileInput.open(fileName);

    while (getline(fileInput, line)){
        lines.push_back(line);
    }

    std::string pom = lines[lines.size() -1];

    //to encode timestamp
    for(char & i : pom){
        i -= 45;
    }

    timeStamp = pom;

    fileInput.close();

}