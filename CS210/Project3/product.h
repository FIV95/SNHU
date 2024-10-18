#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product
{
  private:
    std::string _name; // Prefixing with _ for private member
    int _qty;

  public:
    Product(std::string name, int qty);
    std::string getName() const { return _name; }
    void setName(std::string name);
    int getQty() const { return _qty; }
    void setQty(int qty);
};

#endif // PRODUCT_H
