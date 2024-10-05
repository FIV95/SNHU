#include "ItemToPurchase.h"

// Constructor definition
ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
    this->name = name;
    this->description = description;
    this->price = price;
    this->quantity = quantity;
}

// Print methods
void ItemToPurchase::PrintItemCost() {
   double subtotal;
   subotal = this->quantity * this->price;
   cout << this->name << " " << this-quantity << " @ $" << this->price << " = $" << subtotal << endl;
}

void PrintItemDescription() {
   cout << this->name << ": " << this->description << endl;
}


// Getter methods
string ItemToPurchase::GetName() { return this->name; }
string ItemToPurchase::GetDescription() { return this->description; }
double ItemToPurchase::GetPrice() { return this->price; }
int ItemToPurchase::GetQuantity() { return this->quantity; }


// Setter methods
void ItemToPurchase::SetName(string name) { this->name = name; }
void ItemToPurchase::SetDescription(string description) { this->quantity = description; }
void ItemToPurchase::SetPrice(double price) { this->price = price; }
void ItemToPurchase::SetQuantity(int quantity) { this->quantity = quantity; }


// Overload the + operator to calculate total price of two items
int ItemToPurchase::operator+(const ItemToPurchase& rhs) {
    int sum;
    int Item1_IndividualProductTotal = this->quantity * this->price;
    int Item2_IndividualProductTotal = rhs.quantity * rhs.price;

    sum = Item1_IndividualProductTotal + Item2_IndividualProductTotal;
    return sum;
}


