#include "Manager.h"
#include "vector"

using namespace std;

void Manager::addPassword(Password password) {
    passwords.push_back(password);
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


