#include "ShoppingCart.h"
#include <iostream>
using namespace std;

// Constructor definition
ShoppingCart::ShoppingCart(string customerName, string currentDate) {
   this->customerName = customerName;
   this->currentDate = currentDate;
}

// Print Methods
void ShoppingCart::PrintTotal() {
   // TESTME
   unsigned int i;
   double total = 0.00;

   std::cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl;
   std::cout << "Number of items: " << this->cartItems.size() << endl;
   for (i = 0; i < this->cartItems.size(); ++i)
   {
    ItemToPurchase currItem = this->cartItems.at(i);
    double currItemTotal = currItem.GetQuantity() * currItem.GetPrice();
    std::cout << currItem.GetName() << " " << currItem.GetQuantity() << " @ $" << currItem.GetPrice() << " = " << currItemTotal << endl;
    total = total + this->cartItems.at(i).GetPrice();
   }

   cout << "Total: $" << total << endl;

}

void ShoppingCart::PrintDescriptions() {
  int i;
  std::cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl;
  std::cout << "Item Descriptions" << endl;
  for (int i = 0; i < this->cartItems.size(); ++i)
  {
    ItemToPurchase currItem = this->cartItems.at(i);
    std::cout << currItem.GetName() << ": " << currItem.GetDescription() << endl;
  }
}

// Getter Methods
string ShoppingCart::GetCustomerName() { return this->customerName; }
string ShoppingCart::GetCurrentDate() { return this->currentDate; }
int ShoppingCart::GetNumItemsInCart() { return this->cartItems.size(); }
double ShoppingCart::GetCostOfCart() {
   // FIXME
}

// Setter Methods
void ShoppingCart::SetCustomerName(string customerName) { this->customerName = customerName;}
void ShoppingCart::SetDate(string date) { this->currentDate = date;}

// Action Methods
void AddItem(ItemToPurchase newItem) {
   // FIXME
}

void RemoveItem(ItemToPurchase targetItem) {
   // FIXME
}

void ModifyItem(ItemToPurchase targetItem) {
   // FIXME
}








