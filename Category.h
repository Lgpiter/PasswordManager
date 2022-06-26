#ifndef PASSWORDMANAGER_CATEGORY_H
#define PASSWORDMANAGER_CATEGORY_H

#include <ostream>
#include "string"


class Category {
    std::string name;
    /**sluzy do numerowania kategorii i ulatwia dzialanie w menu glownym*/
    int index;
public:
    Category(const std::string &name, int index);

    Category();

    const std::string &getName() const;

    int getIndex() const;

    /** wypisuje na konsole informacje o kategorii*/
    void show();

    friend std::ostream &operator<<(std::ostream &os, const Category &category);
};


#endif //PASSWORDMANAGER_CATEGORY_H
