#include "Category.h"
#include "iostream"

Category::Category(const std::string &name, int index) : name(name), index(index) {}

int Category::getIndex() const {
    return index;
}

void Category::show(){
    std::cout << "Category name: " << this -> name << " index " << this -> index << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Category &category) {
    os << "name: " << category.name << " index: " << category.index;
    return os;
}

const std::string &Category::getName() const {
    return name;
}
