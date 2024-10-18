#include "product.h"

// Default constructor
Product::Product() : _name(""), _qty(0) {
}

// Parameterized constructor
Product::Product(const std::string &name, int qty) : _name(name), _qty(qty) {
}

void Product::setName(const std::string &name) {
    this->_name = name;
}

void Product::setQty(int qty) {
    this->_qty = qty;
}
