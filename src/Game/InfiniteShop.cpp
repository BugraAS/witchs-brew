/**
 * @file InfiniteShop.cpp
 * @brief Implementation of the InfiniteShop class.
 */

#include "InfiniteShop.hpp"
#include "Inventory.hpp"
#include <limits>

/**
 * @brief Function to add an item to the InfiniteShop with a specified upgrade, price, name, and description.
 * @param upgrade The item to be added to the InfiniteShop.
 * @param price The price of the item.
 * @param name The name of the item.
 * @param desc The description of the item.
 */
void InfiniteShop::AddItem(Item upgrade, float price, const std::string name, std::string desc){
    // Appends the item with the specified upgrade, infinite stock, name, and description.
    appendItem(upgrade, std::numeric_limits<float>::infinity(), name, desc);
    
    // Sets the demand for the upgrade to MONEY with the specified price.
    setDemand(upgrade, Item::MONEY, price);
}

/**
 * @brief Function to remove an item from the InfiniteShop based on the provided upgrade.
 * @details No safeguards are intentionally added.
 * @param upgrade The item to be removed from the InfiniteShop.
 */
void InfiniteShop::RemoveItem(Item upgrade){
    // Removes the item with the specified upgrade from the inventory.
    inventory.RemoveItem(upgrade);
    
    // Removes the demand entry for the upgrade.
    demands.erase(upgrade);
    
    // Removes the label entry for the upgrade.
    labels.erase(upgrade);
}
