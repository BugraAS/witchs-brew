#pragma once

#include "Inventory.hpp"
#include "Item.hpp"
#include <map>
#include <string>
#include <utility>

// TradeAgent class represents an entity involved in trading items with an inventory.
class TradeAgent {
protected:
    Inventory inventory; // Inventory of the trade agent.
    std::map<Item, std::string> labels; // Map to store labels (names) for items.
    std::map<Item, std::string> descriptions; // Map to store descriptions for items.
    std::map<Item, std::pair<Item, float>> demands; // Map to store trade demands.

public:
    // Function to sell a specified quantity of an item to a buyer trade agent.
    float sell(TradeAgent* buyer, Item item, float quantity);

    // Inline function to buy a specified quantity of an item from a seller trade agent.
    inline float buy(TradeAgent* seller, Item item, float quantity) { return seller->sell(this, item, quantity); }

    // Function to add an item to the inventory with a specified quantity, label, and description.
    void appendItem(Item item, float quantity, std::string label, std::string description);

    // Function to set the demand for an item, specifying the item to give, the item to receive, and the price.
    void setDemand(Item give, Item receive, float price);

    // Function to get a vector of available items in the inventory.
    const std::vector<Item> GetAvailableItems() const;

    // Inline function to check if there is a demand for a specific item.
    inline const bool hasDemand(const Item item) { return demands.count(item) > 0; }

    // Inline function to get the label (name) for a specific item.
    inline const std::string& getLabel(const Item item) { return labels[item]; }

    // Inline function to get the description for a specific item.
    inline const std::string& getDesc(const Item item) { return descriptions[item]; }

    // Inline function to get the current stock quantity for a specific item.
    inline const float getStock(const Item item) { return inventory.getItemAmount(item); }

    // Inline function to get the demand for a specific item (item to receive and its price).
    inline std::pair<Item, float> getDemand(Item item) { return hasDemand(item) ? demands[item] : std::pair<Item, float>{Item{-1}, 0.0}; }

    // Default constructor for TradeAgent.
    TradeAgent() = default;

    // Destructor for TradeAgent using default implementation.
    virtual ~TradeAgent() = default;
};
