#pragma once

#include "Item.hpp"
#include <map>
#include <vector>
#include <string>
#include <utility>

// Inventory class represents a collection of items with associated quantities.
class Inventory {
private:
    std::map<Item, float> items; // Map to store items and their corresponding quantities.

public:
    // Default constructor for the Inventory class.
    Inventory();

    // Function to add a specified quantity of an item to the inventory.
    void addItem(Item item, float quantity);

    // Function to take a specified quantity of an item from the inventory.
    // Returns the actual quantity taken, considering the available quantity in the inventory.
    float takeItem(Item item, float quantity);

    // Function to set the quantity of a specific item in the inventory.
    // Overrides the quantity if the item already exists.
    void setItem(Item item, float quantity);

    // Inline function to get a reference to the items map. (HACK: This is a potential security concern.)
    inline std::map<Item, float>& getItems() { return items; }

    // Function to remove a specific item from the inventory.
    void RemoveItem(Item item);

    // Function to check if the inventory contains a specific item.
    bool hasItem(Item item) const;

    // Function to get the quantity of a specific item in the inventory.
    float getItemAmount(Item item);

    // Function to clear all items from the inventory.
    void clear();
};
