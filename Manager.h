#ifndef PASSWORDMANAGER_MANAGER_H
#define PASSWORDMANAGER_MANAGER_H

#include "vector"
#include "Password.h"
#include "Category.h"


class Manager {
    std::vector <Password> passwords;
    std::vector <Category> categories;
    std::string lastTimeStamp;
    std::string mainKey;
    std::string fileName;

public:
    Manager(const std::vector<Password> &passwords, const std::vector<Category> &categories);

    Manager(const std::vector<Password> &passwords, const std::vector<Category> &categories,
            const std::string &lastTimeStamp, const std::string &mainKey, const std::string &fileName);

    /**sluzy do znajdowania hasel wczytanych z pliku*/
    void findPassword();

    /**sluzy do wyboru przez uzytkownika po jakich kryteriach chce posortowac hasla*/
    void sortType();


    /**
     * sluzy do sortowania hasel po kategoriach
     * @tparam functype1
     * @tparam funcType2
     * @param f1 -> pierwsza funkcja sortujaca po danej Kategorii
     * @param f2 -> druga funkcja sotrujaca po danej karegorii
     */
    template <typename functype1, typename funcType2>
    void sortPasswords(functype1 f1,funcType2 f2);

    /**dodaje nowe haslo*/
    void addPassword();

    /**edytuje wybrane pole w istniejacym juz hasle*/
    void editPassword();

    /**usuwa hasla*/
    void deletePassword();

    /**tworzy nowa kategorie, do ktorej bedziemy mogli dodawac hasla*/
    void addCategory();

    /**usuwa dana kategorie wraz ze wszystkimi haslami, ktore sa w niej*/
    void deleteCategory();

    /**wypisuje na konsole wszystkie hasla*/
    void showPasswords();

    /**zapisywanie danych do pliku wraz z koncem dzialania programu*/
    void writeToFile();

    /**wypisywanie menu na konsole, ktore ulatwia poruszanie sie po programie*/
    void printMenu();

    /**pokazuje dokladny czas ostatniej proby otwarcia pliku*/
    void showLastTimeOpened();

    /**sprawdza czy haslo podane przez uzytkownika jest bezpieczne
     * @param[in]password : haslo podane przez uzytkownika
     * @return skale bezpieczenstwa hasla od 0 - 3
     * */
    static int isSafe(const std::string& password);

    /**tworzy nowe haslo zalezne od preferencji uzytkownika, dlugosc, znaki specjalne*/
    static std::string createPassword();
};


#endif //PASSWORDMANAGER_MANAGER_H
