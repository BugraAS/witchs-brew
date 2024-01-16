/**
 * @file Inventory.hpp
 * @brief Header file for the Inventory class.
 */

#pragma once

#include "Item.hpp"
#include <map>
#include <vector>
#include <string>
#include <utility>

/**
 * @class Inventory
 * @brief Represents a collection of items with associated quantities.
 */
class Inventory {
private:
    std::map<Item, float> items; ///< Map to store items and their corresponding quantities.

public:
    /**
     * @brief Default constructor for the Inventory class.
     */
    Inventory();

    /**
     * @brief Function to add a specified quantity of an item to the inventory.
     * @param item The item to add.
     * @param quantity The quantity of the item to add.
     */
    void addItem(Item item, float quantity);

    /**
     * @brief Function to take a specified quantity of an item from the inventory.
     * @param item The item to take.
     * @param quantity The quantity of the item to take.
     * @return The actual quantity taken, considering the available quantity in the inventory.
     */
    float takeItem(Item item, float quantity);

    /**
     * @brief Function to set the quantity of a specific item in the inventory.
     * @param item The item to set.
     * @param quantity The new quantity of the item.
     * @details Overrides the quantity if the item already exists.
     */
    void setItem(Item item, float quantity);

    /**
     * @brief Inline function to get a reference to the items map.
     * @return A reference to the map of items.
     * @note This is a potential security concern, use with caution.
     */
    inline std::map<Item, float>& getItems() { return items; }

    /**
     * @brief Function to remove a specific item from the inventory.
     * @param item The item to remove.
     */
    void RemoveItem(Item item);

    /**
     * @brief Function to check if the inventory contains a specific item.
     * @param item The item to check for.
     * @return True if the item is present in the inventory, false otherwise.
     */
    bool hasItem(Item item) const;

    /**
     * @brief Function to get the quantity of a specific item in the inventory.
     * @param item The item to check for quantity.
     * @return The quantity of the specified item in the inventory.
     */
    float getItemAmount(Item item);

    /**
     * @brief Function to clear all items from the inventory.
     */
    void clear();
};
