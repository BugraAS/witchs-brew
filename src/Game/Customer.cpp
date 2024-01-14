// Include the declaration of the Customer class
#include "Customer.hpp"

// Constructor definition for the Customer class
Customer::Customer(const std::string& _name) : name(_name), money(0) {
    // Constructor logic if needed
}

// Getter method to retrieve the customer's name
const std::string& Customer::GetName() const {
    return name;
}

// Getter method to retrieve the amount of money the customer has
float Customer::GetMoney() const {
    return money;
}

// Setter method to update the amount of money the customer has
void Customer::SetMoney(float amount) {
    money = amount;
    // Logic for setting customer's money
}

// Method to handle a customer's purchase
void Customer::Purchase(float amount) {
    // Check if the customer has enough money for the purchase
    if (money >= amount) {
        money -= amount;
        // Logic for customer's purchase
    } else {
        // Handle insufficient funds scenario
    }
}
