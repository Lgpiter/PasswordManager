#include "Manager.h"
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include <ctime>
#include <fstream>

using namespace std;

Manager::Manager(const vector<Password> &passwords, const vector<Category> &categories) : passwords(passwords),
                                                                                          categories(categories) {}

//DZIALA
void Manager::findPassword() {
    char choice;
    cout << "Podaj po jakim parametrze chcesz wyszukac hasel " << endl;
    cout << "1 -> nazwa" << endl;
    cout << "2 -> login" << endl;
    cout << "3 -> haslo" << endl;
    cout << "4 -> kategorie" << endl;
    cout <<"Jesli chcesz wrocic do menu glownego wpisz dowolna litere" <<endl;
    cin >> choice;

    bool isFound = false;

    switch (choice - '0') {
        case 1 :{
            string passwordName;
            cout << "Podaj nazwe hasla jakie chcesz znalezc\n";

            cin.ignore();
            getline(std::cin,passwordName);

            cout << passwordName << endl;
            for(auto & password : passwords){
                if(password.getName() == passwordName) {
                    isFound = true;
                    password.show();
                }
            }
            break;
        }
        case 2:{
            string login;
            cout << "Poda login hasla jakie chcesz znalezc" << endl;

            cin.ignore();
            getline(std::cin,login);

            for(auto & password : passwords){
                if(password.getLogin() == login){
                    isFound = true;
                    password.show();
                }
            }
            break;
        }
        case 3:{
            string password;
            cout << "Podaj haslo jakie chcesz znalezc" << endl;
            cin.ignore();
            getline(std::cin,password);
            for(auto & i : passwords){
                if(i.getPassword() == password) {
                    isFound = true;
                    i.show();
                }
            }
            break;
        }
        case 4:{
            string category;
            cout << "Podaj kategorie hasla jakie chcesz znalezc" << endl;
            cin >> category;
            for(auto & password : passwords){
                if(password.getCategory().getName() == category) {
                    isFound = true;
                    password.show();
                }
            }
            break;
        }
        default:{
            return;
        }
    }

    if(!isFound){
        cout << "Nie znaleziono zadnych hasel o powyzszych kryteriach" << endl;
    }
}


//DZIALA
template <typename functype1, typename funcType2>
void Manager::sortPasswords(functype1 f1,funcType2 f2) {
    for (int i = 0; i < passwords.size(); i++){
        for(int j = i+1; j < passwords.size(); j++){
            if(f1(passwords[i],passwords[j]) < 0) {
                cout << "WCHODZIMY TU?" << endl;
                iter_swap(passwords.begin() + i, passwords.begin() + j);
            }
            else if(f1(passwords[i],passwords[j]) == 0){
                if(f2(passwords[i],passwords[j]) < 0)
                    iter_swap(passwords.begin() + i,passwords.begin() + j);
            }

        }
    }

    showPasswords();
}

void Manager::sortType() {
    int choice1;
    int choice2;
    cout <<"Podaj po jakich kategoriach chcesz posortowac hasla " << endl;
    cout << "1 -> nazwa" << endl;
    cout << "2 -> login" << endl;
    cout << "3 -> haslo" << endl;
    cout << "4 -> kategorie" << endl;
    cout <<"Kategoria 1 -> " << endl;
    cin >> choice1;
    cout << "Kategoria 2 ->" << endl;
    cin >> choice2;

    auto fName = [](Password& p1, Password& p2) -> int{
        return p2.getName().compare(p1.getName());
    };

    auto fLogin = [](Password& p1, Password& p2) -> int{
        return p2.getLogin().compare(p1.getLogin());
    };

    auto fPassword = [](Password& p1, Password& p2) -> int{
        return p2.getPassword().compare(p1.getPassword());
    };

    auto fCategory = [](Password& p1, Password& p2) -> int{
        return p2.getCategory().getName().compare(p1.getCategory().getName());
    };

    switch (choice1) {
        case 1:{
            switch (choice2) {
                case 2:{
                    sortPasswords(fName,fLogin);
                    break;
                }
                case 3:{
                    sortPasswords(fName,fPassword);
                    break;
                }
                case 4:{
                    sortPasswords(fName,fCategory);
                    break;
                }
            }
            break;
        }
        case 2:{
            switch (choice2) {
                case 1:{
                    sortPasswords(fLogin,fName);
                    break;
                }
                case 3:{
                    sortPasswords(fLogin,fPassword);
                    break;
                }
                case 4:{
                    sortPasswords(fLogin,fCategory);
                    break;
                }
            }
            break;
        }
        case 3:{
            switch (choice2) {
                case 1:{
                    sortPasswords(fPassword,fName);
                    break;
                }
                case 2:{
                    sortPasswords(fPassword,fLogin);
                    break;
                }
                case 4:{
                    sortPasswords(fPassword,fCategory);
                    break;
                }
            }
            break;
        }
        case 4:{
            switch (choice2) {
                case 1:{
                    sortPasswords(fCategory,fName);
                    break;
                }
                case 2:{
                    sortPasswords(fCategory,fLogin);
                    break;
                }
                case 3:{
                    sortPasswords(fCategory,fPassword);
                    break;
                }
            }
            break;
        }
        
    }
}

//DZIALA
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
            cin.ignore();
            getline(cin,name);
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

}

void Manager::addPassword() {
    string name;
    string login;
    cout << "Podaj nazwe ktore chcasz nadac nowemu haslu" << std::endl;
    cin.ignore();
    getline(cin,name);
    cout << "Podaj login dopasowany do tego hasla" << std::endl;
    cin.ignore();
    getline(cin,login);

    int pom = 0; //condition to our while
    int choice;

    string password;

    while(pom == 0){
        cout <<"Jesli masz gotowe haslo wpisz 1, a jesli wygenerowac Ci haslo wpisz 0" << endl;
        cin >> choice;
        if(choice == 0){
            password = createPassword();
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

    for(auto & categorie : categories){
        if(categoryChoice == categorie.getIndex()){
            Password tmp {name,password,login,categorie, true};
            passwords.push_back(tmp);
            break;
        }
    }
}

//dziala
void Manager::addCategory() {
    string name;
    cout << "Podaj nazwe kategori, ktora chcesz stowrzyc " << endl;
    cin.ignore();
    getline(cin,name);

    int size = (int)categories.size() + 1;
    Category category {name, size};
    categories.push_back(category);
}

//dziala
void Manager::deleteCategory() {
    for(auto & categorie : categories)
        categorie.show();

    int choice;
    cout << "Wybierz numer kategorii, ktora chcesz usunac" << endl;
    cin >> choice;

    for(int i = 0; i < passwords.size(); i++){
        if(passwords[i].getCategory().getIndex() == choice) {
            passwords.erase(passwords.begin() + i);
            i--; //zeby nie przeskakiwac elementow
        }
    }

    for(int i = 0; i < categories.size(); i++){
        if(categories[i].getIndex() == choice)
            categories.erase(categories.begin()+i);
    }

    showPasswords();
}

//dziala
void Manager::deletePassword() {
    int choice;

    showPasswords();
    cout << "Wybierz haslo, ktore chcesz usunac (jesli chcesz skonczyc wpisz 0)" << endl;
    cin >> choice;
    if(choice == 0)
        return;
    else {
        cout << "Jestes pewien, ze chcesz usunac to haslo? (jesli tak wpisz 1)" << endl;
        cin >>choice;
        if(choice == 1) {
            passwords.erase(passwords.begin() + choice - 1);
            deletePassword();
        }
    }
}

void Manager::showPasswords() {
    for(int i = 0; i < passwords.size(); i++){
        cout << i+1 <<".";
        passwords[i].show();
    }
}

//funkcja dziala
int Manager::isSafe(const std::string& password) {
    //to check if all parameters are fine
    int counter = 0;
    if(password.length() > 10)
        counter++;

    bool isBigLetter = false;
    for(char i : password){
        if(isupper(i))
            isBigLetter = true;
    }

    if(isBigLetter)
        counter++;

    bool isSpecialCharacter = false;
    std::string specialCharacter = "!@$%^&*?/,.|";

    for(char i : password){
        for(char j : specialCharacter){
            if(i == j)
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

    string password = "";
    char character;
    int random;

    string special = "!@#$%^&*(){}[]|:;'<>?,./";

    srand(time(nullptr));
    for(int i = 0; i < length; i++){
        if(i%3 == 0 && specialCharacters == 'y'){
            //co 3 znak bedzie znakiem specjalnym
            random = rand() % special.length();
            character = special[random];
        }
        else if(i % 2 == 0 && bigLetters == 'y'){
            //co 2 znak wielka litera
            random = rand()%26;
            character = 'A' + random;
        }
        else {
            random = rand()%26;
            character = 'a' + random;
        }

        password += character;
    }

    cout<<password << endl;
    return password;
}

void Manager::printMenu(){
    char choice = 0;

    while (choice != 8) {
        cout << "1.Wyszukaj hasla" << endl;
        cout << "2.Posortuj hasla" << endl;
        cout << "3.Dodaj haslo" << endl;
        cout << "4.Edytuj haslo" << endl;
        cout << "5.Usun haslo" << endl;
        cout << "6.Dodaj kategorie" << endl;
        cout << "7.Usun kategorie" << endl;
        cout << "8.Zakoncz program" << endl;
        cin >> choice;

        switch (choice -'0') {
            case 1: {
                findPassword();
                break;
            }
            case 2: {
                sortType();
                break;
            }
            case 3: {
                addPassword();
                break;
            }
            case 4: {
                editPassword();
                break;
            }
            case 5: {
                deletePassword();
                break;
            }
            case 6: {
                addCategory();
                break;
            }
            case 7: {
                deleteCategory();
                break;
            }
            case 8: {
                return;
            }
            default: {
                cout << "Wybrales zly numer sprobuj jeszcze raz" << endl;
            }
        }
    }
}

void Manager::writeToFile() {
    ofstream outdata;

    outdata.open("C:\\Users\\Piotr Zadykowicz\\Desktop\\PasswordManager\\test.txt");

    Password p  {"test","test1234","12344341",categories[1],true};
    p.codePassword();
    outdata << p.getPassword() << endl;

    for (auto &category : categories)
        outdata <<"Category: " <<  category << endl;

    for (auto & password : passwords) {
        password.codePassword();
        outdata << "Password: " << password << endl;
    }

    time_t currtime=time(0);
    std::string timestamp = std::asctime(localtime(&currtime));

    outdata << timestamp;
    outdata.close();

}

