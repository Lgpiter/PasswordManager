#include <iostream>
#include "vector"
#include "Manager.h"
#include "Password.h"
#include "fstream"
#include "filesystem"

/**
 * sprawdza czy podane przez uzytkownika haslo zgadza sie z haslem pliku
 * @param[in] s : haslo przekazane przez uzytkownika
 * @return czy haslo jest prawidlowe
 * @param fileName - nazwa pliku z haslami
 * */
bool checkIsGoodKey(std::string &s, std::string &fileName);

/**
 * czyta kategorie z pliku, a nastepnie dodaje je do vectora
 * @param v - przyjmuje vector kategorii
 * @param fileName - nazwa pliku z haslami
 */
void readCategories(std::vector<Category> &v,std::string &fileName);

/**
 * czyta hasla z pliku, a nastepnie dodaje je do vectora
 * @param v1 vector hasel
 * @param v2 vector kategorii
 * @param fileName - nazwa pliku z haslami
 * @param mainKey czy zostalo wpisane dobre haslo do pliku
 */
void readPassword(std::vector<Password> &v1,std::vector<Category> &v2, bool &mainKey,std::string &fileName);

/**
 * * czyta ostatni czas otwarcia pliku
 * @param timeStamp
 * @param fileName - nazwa pliku z haslami
 */
void readListTimeStamp(std::string &timeStamp,std::string &fileName);

int main() {
    std::string fileName;

    int choice;
    std::cout << "Jesli chcesz wybrac plik z listy wpisz 1, jesli absoultna sciezke wpisz 0" << std::endl;
    std::cin >> choice;
    if(choice == 0){
        std::cout << "Podaj absolutna sciezke do pliku" << std::endl;
        std::cin.ignore();
        std::getline(std::cin,fileName);
    }
    else{
        int counter = 1;
        std::filesystem::path path1 = std::filesystem::current_path().parent_path();
        for(auto & file : std::filesystem::directory_iterator(path1)){
            if(file.path().extension() == ".txt" && file.path().filename() != "CMakeLists.txt")
                std::cout <<counter++ << "." << file.path().filename() << std::endl;

        }

        int choice2;
        std::cout << "Wybierz numer pliku ktory chcesz otworzyc" << std::endl;
        std::cin >> choice2;

        int counter2 = 1;
        for(auto & file : std::filesystem::directory_iterator(path1)){
            if(file.path().extension() == ".txt" && file.path().filename() != "CMakeLists.txt") {
                if(choice2 == counter2)
                    fileName = file.path().string();
                counter2++;
            }
        }
    }
    std::cout << fileName << std::endl;


    std::string key;
    std :: cout << "Wpisz haslo do pliku" << std::endl;
    std::cin >> key;

    bool mainKey = checkIsGoodKey(key,fileName);

    std::string timeStamp;


    std::vector<Category> categories;
   readCategories(categories,fileName);

    if(mainKey){
        readListTimeStamp(timeStamp,fileName);

        std::vector<Password> passwords;
        readPassword(passwords,categories, mainKey,fileName);

        Manager manager {passwords,categories,timeStamp, key,fileName};
        manager.printMenu();
    }
    else{
        std::vector<Password> passwords;
        readPassword(passwords,categories, mainKey,fileName);

        Manager manager {passwords,categories};
        manager.showPasswords();
        manager.writeToFile();
    }


    return 0;
}

bool checkIsGoodKey(std::string &s,std::string &fileName){
    std::string orginalKey;

    std::ifstream fileInput;

    fileInput.open(fileName);
    std::getline(fileInput,orginalKey);
    fileInput.close();


    int pom;


    /**
     * petla do odkodowania hasla
     */

    for(int i = 0; i < orginalKey.size(); i++){
        pom = orginalKey[i] - 135;
        orginalKey[i] = pom;
    }





    if(orginalKey == s) {
        return true;
    }
    else
        return false;
}

void readCategories(std::vector<Category> &v,std::string &fileName){
    std::ifstream fileInput;

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

void readPassword(std::vector<Password> &v1,std::vector<Category> &v2, bool &mainKey,std::string &fileName){
    std::ifstream fileInput;
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

void readListTimeStamp(std::string &timeStamp,std::string &fileName){
   std::vector<std::string> lines;
   std:: string line;

    std::ifstream fileInput;
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