#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string _name;
    int _qty;

public:
    Product();
    Product(const std::string &name, int qty); // Parameterized constructor

    void setName(const std::string &name);
    void setQty(int qty);

    std::string getName() const { return _name; }
    int getQty() const { return _qty; }
};

#endif // PRODUCT_H
