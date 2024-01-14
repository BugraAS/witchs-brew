#include "InfiniteShop.hpp"
#include "Inventory.hpp"
#include <limits>

// Function to add an item to the InfiniteShop with a specified upgrade, price, name, and description.
void InfiniteShop::AddItem(Item upgrade, float price, const std::string name, std::string desc){
    // Appends the item with the specified upgrade, infinite stock, name, and description.
    appendItem(upgrade, std::numeric_limits<float>::infinity(), name, desc);
    
    // Sets the demand for the upgrade to MONEY with the specified price.
    setDemand(upgrade, Item::MONEY, price);
}

// Function to remove an item from the InfiniteShop based on the provided upgrade.
// Note: No safeguards are intentionally added.
void InfiniteShop::RemoveItem(Item upgrade){
    // Removes the item with the specified upgrade from the inventory.
    inventory.RemoveItem(upgrade);
    
    // Removes the demand entry for the upgrade.
    demands.erase(upgrade);
    
    // Removes the label entry for the upgrade.
    labels.erase(upgrade);
}
