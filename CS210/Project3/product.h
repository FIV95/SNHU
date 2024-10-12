#ifdef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product
{
  private:
  std::string name;
  int qty;

  public:
  Product(std::string name, int frequency);
  std::string getName() const {return this->name;}
  void setName(std::string name);
  int getFrequency() const {return this->frequency;}
  void setFrequency(int frequency);
};