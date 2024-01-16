/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class.
 */

#include "Inventory.hpp"
#include <algorithm>

/**
 * @brief Constructor for the Inventory class.
 * @details Initializes the items map.
 */
Inventory::Inventory()
    : items()
{
}

/**
 * @brief Function to add an item to the inventory with a specified quantity.
 * @param item The item to be added to the inventory.
 * @param quantity The quantity of the item to be added.
 */
void Inventory::addItem(Item item, float quantity){
    // Check if the item already exists in the inventory, if yes, add the quantity to the existing amount.
    float temp = hasItem(item) ? items[item] : 0.0f;
    items[item] = temp + quantity;
}

/**
 * @brief Function to take a specified quantity of an item from the inventory.
 * @param item The item to be taken from the inventory.
 * @param quantity The quantity of the item to be taken.
 * @return The actual quantity taken, considering the available quantity in the inventory.
 */
float Inventory::takeItem(Item item, float quantity){
    // Get the current quantity of the item in the inventory.
    float temp = items[item];
    
    // Update the inventory with the remaining quantity after taking.
    items[item] = std::max(temp - quantity, 0.0f);
    
    // Return the actual quantity taken, considering the available quantity.
    return temp > quantity ? quantity : temp;
}

/**
 * @brief Function to set the quantity of a specific item in the inventory.
 * @param item The item for which the quantity needs to be set.
 * @param quantity The new quantity to be set for the item.
 */
void Inventory::setItem(Item item, float quantity) {
    items[item] = quantity; // override if it exists previously
}

/**
 * @brief Function to remove a specific item from the inventory.
 * @param item The item to be removed from the inventory.
 */
void Inventory::RemoveItem(Item item) {
    items.erase(item);
}

/**
 * @brief Function to check if the inventory contains a specific item.
 * @param item The item to check for in the inventory.
 * @return True if the inventory contains the specified item, false otherwise.
 */
bool Inventory::hasItem(Item item) const {
    return items.count(item) > 0;
}

/**
 * @brief Function to get the quantity of a specific item in the inventory.
 * @param item The item for which the quantity needs to be retrieved.
 * @return The quantity of the specified item in the inventory.
 */
float Inventory::getItemAmount(Item item){
    return hasItem(item) ? items[item] : 0.0f;
}

/**
 * @brief Function to clear all items from the inventory.
 */
void Inventory::clear() {
    items.clear();
}
