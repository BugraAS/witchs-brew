/**
 * @file InfiniteShop.hpp
 * @brief Header file for the InfiniteShop class.
 */

#pragma once

#include "TradeAgent.hpp"
#include <string>
#include <vector>

/**
 * @class InfiniteShop
 * @brief Represents a shop with infinite stock.
 * @details Derived from TradeAgent, the InfiniteShop class allows adding items with infinite stock.
 */
class InfiniteShop : public TradeAgent {
private:
    // No private members declared in this class.

public:
    /**
     * @brief Default constructor for the InfiniteShop class.
     */
    InfiniteShop() = default;

    /**
     * @brief Function to add an item to the shop with infinite stock.
     * @param upgrade The item to add.
     * @param price The price of the item.
     * @param name The name of the item.
     * @param desc The description of the item.
     */
    void AddItem(Item upgrade, float price, const std::string name, std::string desc);

    /**
     * @brief Function to remove an item from the shop based on the provided upgrade.
     * @param upgrade The item to remove.
     * @details No safeguards are intentionally added.
     */
    void RemoveItem(Item upgrade);
};
