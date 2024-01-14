#pragma once

#include "TradeAgent.hpp"
#include <string>
#include <vector>

// InfiniteShop class is derived from TradeAgent, representing a shop with infinite stock.
class InfiniteShop : public TradeAgent {
private:
    // No private members declared in this class.

public:
    // Default constructor for the InfiniteShop class.
    InfiniteShop() = default;

    // Function to add an item to the shop with infinite stock, a specified price, name, and description.
    void AddItem(Item upgrade, float price, const std::string name, std::string desc);

    // Function to remove an item from the shop based on the provided upgrade.
    void RemoveItem(Item upgrade);
};
