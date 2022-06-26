#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"
#include "fstream"

/**
 * sprawdza czy podane przez uzytkownika haslo zgadza sie z haslem pliku
 * @param[in] s : haslo przekazane przez uzytkownika
 * @return czy haslo jest prawidlowe
 * */
bool checkIsGoodKey(std::string &s);

/**
 * czyta kategorie z pliku, a nastepnie dodaje je do vectora
 * @param v - przyjmuje vector kategorii
 */
void readCategories(std::vector<Category> &v);

/**
 * czyta hasla z pliku, a nastepnie dodaje je do vectora
 * @param v1 vector hasel
 * @param v2 vector kategorii
 * @param mainKey czy zostalo wpisane dobre haslo do pliku
 */
void readPassword(std::vector<Password> &v1,std::vector<Category> &v2, bool &mainKey);

/**
 * czyta ostatni czas otwarcia pliku
 * @param timeStamp -
 */
void readListTimeStamp(std::string &timeStamp);

int main() {
    std::cout << "Jesli chcesz wybrac plik z listy wpisz 1, jesli absoultna sciezke wpisz 0" << std::endl;
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

    /**
     * otrzymanie ostatniej linii, w ktorej zawsze kodowany jest timestamp
     */
    std::string pom = lines[lines.size() -1];

    /**
     * rozkodowanie timestampa
     */
    for(char & i : pom){
        i -= 45;
    }

    timeStamp = pom;

    fileInput.close();

}