//
// Created by Piotr Zadykowicz on 22.06.2022.
//

#ifndef PASSWORDMANAGER_CATEGORY_H
#define PASSWORDMANAGER_CATEGORY_H

#include <ostream>
#include "string"

class Category {
    std::string name;
    int index;
public:
    Category(const std::string &name, int index);

    Category();

    const std::string &getName() const;

    int getIndex() const;
    void show();

    friend std::ostream &operator<<(std::ostream &os, const Category &category);
};


#endif //PASSWORDMANAGER_CATEGORY_H
