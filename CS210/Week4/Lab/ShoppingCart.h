#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
    // Constructor with default parameters
    ShoppingCart(string customerName = "none", string currentDate = "January 1, 2016");

    // Getters
    string GetCustomerName();
    string GetCurrentDate();
    int GetNumItemsInCart();
    double GetCostOfCart();

    // Actions
    void AddItem(ItemToPurchase newItem);
    void RemoveItem(ItemToPurchase targetItem);
    void ModifyItem(ItemToPurchase targetItem);

    // Prints
    void PrintTotal();
    void PrintDescriptions();

    // Setters
    void SetCustomerName(string customerName);
    void SetDate(string date);


private:
    string customerName;
    string currentDate;
    vector <ItemToPurchase > cartItems;
};

#endif
