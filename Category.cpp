#include "Category.h"
#include "iostream"

Category::Category(const std::string &name, int index) : name(name), index(index) {}

Category::Category() {};

int Category::getIndex() const {
    return index;
}

const std::string &Category::getName() const {
    return name;
}

void Category::show(){
    std::cout << "Category name: " << this -> name << " index " << this -> index << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Category &category) {
    os << category.name << " " << category.index;
    return os;
}

