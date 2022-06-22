#include "Manager.h"
#include "iostream"
#include "vector"

using namespace std;

void Manager::findPassword() {};
void Manager::sortPasswords() {};
void Manager::editPassword() {};

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

void Manager::deleteCategory() {};

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


