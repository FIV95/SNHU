#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    // Constructor with default parameters
    ItemToPurchase(string name = "none", string description = "none", double price = 0, int quantity = 0);

    // Getters
    string GetName();
    string GetDescription();
    double GetPrice();
    int GetQuantity();

    // Prints
    void PrintItemCost();
    void PrintItemDescription();

    // Setters
    void SetName(string name);
    void SetDescription(string description);
    void SetPrice(double price);
    void SetQuantity(int quantity);

    // Overload + operator
    int operator+(const ItemToPurchase& rhs);

private:
    string name;
    string description;
    double price;
    int quantity;
};

#endif
