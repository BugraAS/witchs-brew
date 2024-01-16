/**
 * @file Customer.hpp
 * @brief Header file for the Customer class.
 */

#pragma once

#include <string>

/**
 * @class Customer
 * @brief Represents a customer with a name and money for purchasing items.
 */
class Customer {
private:
    std::string name; ///< Name of the customer.
    float money;      ///< Amount of money the customer has.

    // Other member variables if needed can be added here.

public:
    /**
     * @brief Constructor for the Customer class.
     * @param _name The name of the customer.
     */
    Customer(const std::string& _name);

    /**
     * @brief Function to get the name of the customer.
     * @return The name of the customer.
     */
    const std::string& GetName() const;

    /**
     * @brief Function to get the amount of money the customer has.
     * @return The amount of money the customer has.
     */
    float GetMoney() const;

    /**
     * @brief Function to set the amount of money for the customer.
     * @param amount The new amount of money for the customer.
     */
    void SetMoney(float amount);

    /**
     * @brief Function to simulate a purchase by deducting the specified amount from the customer's money.
     * @param amount The amount to deduct from the customer's money.
     */
    void Purchase(float amount);

    // Other methods for customer interactions can be added here.
};
