#include "Manager.h"
#include "iostream"
#include "vector"

using namespace std;

void Manager::addPassword() {
    /*
    string name;
    string login;
    cout << "Podaj nazwe ktore chcasz nadac nowemu haslu" << std::endl;
    cin >> name;
    cout << "Podaj login dopasowany do tego hasla" << std::endl;
    cin >> login;

    */
    int pom = 0;
    int choice;

    while(pom == 0){
        cout <<"Jesli masz gotowe haslo wpisz 1, a jesli wygenerowac Ci haslo wpisz 0" << endl;
        cin >> choice;
        if(choice == 0){
            cout << "Kod do generowania hasla";
            pom = 1;
        }
        else if (choice == 1){
            string password;
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
}


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


