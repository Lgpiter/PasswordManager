#include "Category.h"

Category::Category(const std::string &name, int index) : name(name), index(index) {}

int Category::getIndex() const {
    return index;
}
