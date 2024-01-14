/**
 * @file Customer.cpp
 * @brief Implementation of the Customer class.
 */

#include "Customer.hpp"

/**
 * @brief Constructor for the Customer class.
 * @param _name The name of the customer.
 */
Customer::Customer(const std::string& _name) : name(_name), money(0) {
    // Constructor logic if needed
}

/**
 * @brief Getter method to retrieve the customer's name.
 * @return The name of the customer.
 */
const std::string& Customer::GetName() const {
    return name;
}

/**
 * @brief Getter method to retrieve the amount of money the customer has.
 * @return The amount of money the customer has.
 */
float Customer::GetMoney() const {
    return money;
}

/**
 * @brief Setter method to update the amount of money the customer has.
 * @param amount The new amount of money for the customer.
 */
void Customer::SetMoney(float amount) {
    money = amount;
    // Logic for setting customer's money
}

/**
 * @brief Method to handle a customer's purchase.
 * @param amount The amount to be deducted from the customer's money for the purchase.
 */
void Customer::Purchase(float amount) {
    // Check if the customer has enough money for the purchase
    if (money >= amount) {
        money -= amount;
        // Logic for customer's purchase
    } else {
        // Handle insufficient funds scenario
    }
}
