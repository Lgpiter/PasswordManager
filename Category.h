//
// Created by Piotr Zadykowicz on 22.06.2022.
//

#ifndef PASSWORDMANAGER_CATEGORY_H
#define PASSWORDMANAGER_CATEGORY_H

#include "string"

class Category {
    std::string name;
    int index;
public:
    Category(const std::string &name, int index);

    int getIndex() const;
};


#endif //PASSWORDMANAGER_CATEGORY_H
