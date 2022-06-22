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
            cout << "Kod do wpisywania hasla";
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


