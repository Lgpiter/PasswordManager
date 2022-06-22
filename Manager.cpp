#include "Manager.h"
#include "iostream"
#include "vector"

using namespace std;

void Manager::findPassword() {};
void Manager::sortPasswords() {};


void Manager::editPassword() {
    for(int i = 0; i < passwords.size(); i++){
        cout << i + 1 << ".";
        passwords[i].show();
    }

    int choice;
    cout << "Ktore haslo chcesz zmienic?" << endl;
    cin >> choice;



    int changeChoice;
    cout << "Co chcesz zmienic w hasle? " << endl;
    cout << "1 -> nazwa" << endl;
    cout << "2 -> login" << endl;
    cout << "3 -> haslo" << endl;
    cout << "4 -> kategorie" << endl;
    cin >>changeChoice;


    switch (changeChoice) {
        case 1:{
            string name;
            cout << "Podaj nazwe na jaka chcesz zmienic" << endl;
            cin >> name;
            passwords[choice -1].setName(name);
            break;
        }
        case 2:{
            string login;
            cout << "Podaj login na jaki chcesz zmienic" << endl;
            cin >> login;
            passwords[choice-1].setLogin(login);
            break;
        }
        case 3:{
            string password;
            cout << "Podaj haslo na jakie chcesz zmienic" << endl;
            cin >> password;
            passwords[choice - 1].setPassword(password);
            break;
        }
        case 4:{
            int categoryChoice;
            for(int i = 0; i < categories.size(); i++){
                cout << i + 1 << ".";
                categories[i].show();
            }
            cout << "Wybierz numer kategori, na ktora chcesz zmienic" << endl;
            cin >> categoryChoice;
            passwords[choice-1].setCategory(categories[categoryChoice-1]);
            break;
        }
    }

};

void Manager::addPassword() {
    string name;
    string login;
    cout << "Podaj nazwe ktore chcasz nadac nowemu haslu" << std::endl;
    cin >> name;
    cout << "Podaj login dopasowany do tego hasla" << std::endl;
    cin >> login;

    int pom = 0;
    int choice;

    string password;

    while(pom == 0){
        cout <<"Jesli masz gotowe haslo wpisz 1, a jesli wygenerowac Ci haslo wpisz 0" << endl;
        cin >> choice;
        if(choice == 0){
            cout << "Kod do generowania hasla";
            pom = 1;
        }
        else if (choice == 1){
            cout << "Podaj swoje haslo";
            cin >>password;
            cout << "Sila Twojego hasla to: ";
            switch (isSafe(password)) {
                case 0 :{
                    cout << "slabe" << endl;
                    break;
                }
                case 1:{
                    cout << "srednie" << endl;
                }
                case 2:{
                    cout << "mocne" << endl;
                }
                case 3:{
                    cout << "bardzo mocne" << endl;
                }
            }


            pom = 1;
        }
    }

    int categoryChoice;

    cout << "Wybierz kategorie, do ktorej chcesz dodac haslo" << std::endl;
    cin >> categoryChoice;

    for(int i = 0; i < categories.size(); i++){
        if(categoryChoice == categories[i].getIndex()){
            Password tmp {name,password,login,categories[i]};
            passwords.push_back(tmp);
            break;
        }
    }
}

void Manager::addCategory() {
    string name;
    cout << "Podaj nazwe kategori, ktora chcesz stowrzyc " << endl;
    cin >> name;

    int size = categories.size() + 1;
    Category category {name, size};
    categories.push_back(category);
}

void Manager::deleteCategory() {
    for(int i = 0; i < categories.size(); i++)
        categories[i].show();

    int choice;
    cout << "Wybierz numer kategorii, ktora chcesz usunac" << endl;
    cin >> choice;

    for(int i = 0; i < passwords.size(); i++){
        if(passwords[i].getCategory().getIndex() == choice)
            passwords.erase(std::next(passwords.begin(),i),std::next(passwords.begin(),i+1));
    }

    for(int i = 0; i < categories.size(); i++){
        if(categories[i].getIndex() == choice)
            categories.erase(std::next(categories.begin(), i), std::next(categories.begin(),i+1));
    }
};

void Manager::deletePassword(Password password) {
    for(int i = 0; i <passwords.size(); i++){
        if(passwords[i].getPassword() == password.getPassword())
            passwords.erase(std::next(passwords.begin(),i),std::next(passwords.begin(),i+1));
    }
}

Manager::Manager(const vector<Password> &passwords) : passwords(passwords) {}

void Manager::showPasswords() {
    for(int i = 0; i < passwords.size(); i++){
        passwords[i].show();
    }
}

//funkcja dziala
int Manager::isSafe(std::string password) {
    //to check if all parameters are fine
    int counter = 0;
    if(password.length() > 10)
        counter++;

    bool isBigLetter = false;
    for(int i = 0; i < password.length(); i++){
        if(isupper(password[i]))
            isBigLetter = true;
    }

    if(isBigLetter)
        counter++;

    bool isSpecialCharacter = false;
    std::string specialCharacter = "!@$%^&*?/,.|";

    for(int i = 0; i < password.length(); i++){
        for(int j = 0; j < specialCharacter.length(); j++){
            if(password[i] == specialCharacter[j])
                isSpecialCharacter = true;
        }
    }

    if(isSpecialCharacter)
        counter++;

    return counter;
}

std::string Manager::createPassword() {
    int length;
    char bigLetters;
    char specialCharacters;
    cout << "Podaj dlugosc hasla" << endl;
    cin >> length;
    cout << "Czy chcesz by zawieralo duze litery (y/n)" << endl;
    cin >> bigLetters;
    cout << "Czy chcesz by zawieralo znaki specjalne (y/n)" << endl;
    cin >> specialCharacters;
}

void Manager::printMenu(){
    int choice;
    cout << "1.Wyszukaj hasla" << endl;
    cout << "2.Posortuj hasla" << endl;
    cout << "3.Dodaj haslo" << endl;
    cout << "4.Edytuj haslo" << endl;
    cout << "5.Usun haslo" << endl;
    cout << "6.Dodaj kategorie" << endl;
    cout << "7.Usun kategorie" << endl;
    cout << "8.Zakoncz program" << endl;
    cin >> choice;

    switch (choice) {
        case 1:{
            findPassword();
            break;
        }
        case 2:{
            sortPasswords();
            break;
        }
        case 4:{
            editPassword();
            break;
        }
        case 5:{
            //deletePassword();
            break;
        }
        case 6:{
            addCategory();
            break;
        }
        case 7:{
            deleteCategory();
            break;
        }case 8:{
            break;
        }
        default:{
            cout << "Wybrales zly numer sprobuj jeszcze raz" << endl;
            printMenu();
        }

    }
}


