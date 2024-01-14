#include "Inventory.hpp"
#include <algorithm>

// Constructor for the Inventory class, initializes the items map.
Inventory::Inventory()
: items()
{

}

// Function to add an item to the inventory with a specified quantity.
void Inventory::addItem(Item item, float quantity){
    // Check if the item already exists in the inventory, if yes, add the quantity to the existing amount.
    float temp = hasItem(item) ? items[item] : 0.0f;
    items[item] = temp + quantity;
}

// Function to take a specified quantity of an item from the inventory.
// Returns the actual quantity taken, considering the available quantity in the inventory.
float Inventory::takeItem(Item item, float quantity){
    // Get the current quantity of the item in the inventory.
    float temp = items[item];
    
    // Update the inventory with the remaining quantity after taking.
    items[item] = std::max(temp - quantity, 0.0f);
    
    // Return the actual quantity taken, considering the available quantity.
    return temp > quantity ? quantity : temp;
}

// Function to set the quantity of a specific item in the inventory.
// Overrides the quantity if the item already exists.
void Inventory::setItem(Item item, float quantity) {
    items[item] = quantity; // override if it exists previously
}

// Function to remove a specific item from the inventory.
void Inventory::RemoveItem(Item item) {
    items.erase(item);
}

// Function to check if the inventory contains a specific item.
bool Inventory::hasItem(Item item) const {
    return items.count(item) > 0;
}

// Function to get the quantity of a specific item in the inventory.
float Inventory::getItemAmount(Item item){
    return hasItem(item) ? items[item] : 0.0f;
}

// Function to clear all items from the inventory.
void Inventory::clear() {
    items.clear();
}
