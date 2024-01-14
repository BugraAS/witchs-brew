#pragma once

#include <string>

// Customer class represents a customer with a name and money for purchasing items.
class Customer {
private:
    std::string name; // Name of the customer.
    float money;      // Amount of money the customer has.

    // Other member variables if needed can be added here.

public:
    // Constructor for the Customer class, initializes the customer with a given name.
    Customer(const std::string& _name);

    // Function to get the name of the customer.
    const std::string& GetName() const;

    // Function to get the amount of money the customer has.
    float GetMoney() const;

    // Function to set the amount of money for the customer.
    void SetMoney(float amount);

    // Function to simulate a purchase by deducting the specified amount from the customer's money.
    void Purchase(float amount);

    // Other methods for customer interactions can be added here.
};
