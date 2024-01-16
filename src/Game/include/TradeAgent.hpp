/**
 * @file TradeAgent.hpp
 * @brief Header file for the TradeAgent class.
 */

#pragma once

#include "Inventory.hpp"
#include "Item.hpp"
#include <map>
#include <string>
#include <utility>

/**
 * @class TradeAgent
 * @brief Represents an entity involved in trading items with an inventory.
 * @details The TradeAgent class provides functionality for buying, selling, managing inventory, and setting trade demands.
 */
class TradeAgent {
protected:
    Inventory inventory;                         ///< Inventory of the trade agent.
    std::map<Item, std::string> labels;          ///< Map to store labels (names) for items.
    std::map<Item, std::string> descriptions;    ///< Map to store descriptions for items.
    std::map<Item, std::pair<Item, float>> demands; ///< Map to store trade demands.

public:
    /**
     * @brief Function to sell a specified quantity of an item to a buyer trade agent.
     * @param buyer Pointer to the buyer TradeAgent.
     * @param item The item to be sold.
     * @param quantity The quantity of the item to be sold.
     * @return The total value of the sold items.
     */
    float sell(TradeAgent* buyer, Item item, float quantity);

    /**
     * @brief Inline function to buy a specified quantity of an item from a seller trade agent.
     * @param seller Pointer to the seller TradeAgent.
     * @param item The item to be bought.
     * @param quantity The quantity of the item to be bought.
     * @return The total value of the bought items.
     */
    inline float buy(TradeAgent* seller, Item item, float quantity) { return seller->sell(this, item, quantity); }

    /**
     * @brief Function to add an item to the inventory with a specified quantity, label, and description.
     * @param item The item to be added to the inventory.
     * @param quantity The quantity of the item to be added.
     * @param label The label (name) for the item.
     * @param description The description for the item.
     */
    void appendItem(Item item, float quantity, std::string label, std::string description);

    /**
     * @brief Function to set the demand for an item, specifying the item to give, the item to receive, and the price.
     * @param give The item to be given in exchange.
     * @param receive The item to be received in exchange.
     * @param price The price for the item.
     */
    void setDemand(Item give, Item receive, float price);

    /**
     * @brief Function to get a vector of available items in the inventory.
     * @return A vector of available items in the inventory.
     */
    const std::vector<Item> GetAvailableItems() const;

    /**
     * @brief Inline function to check if there is a demand for a specific item.
     * @param item The item to check for demand.
     * @return True if there is demand for the item, false otherwise.
     */
    inline const bool hasDemand(const Item item) { return demands.count(item) > 0; }

    /**
     * @brief Inline function to get the label (name) for a specific item.
     * @param item The item to get the label for.
     * @return The label (name) for the item.
     */
    inline const std::string& getLabel(const Item item) { return labels[item]; }

    /**
     * @brief Inline function to get the description for a specific item.
     * @param item The item to get the description for.
     * @return The description for the item.
     */
    inline const std::string& getDesc(const Item item) { return descriptions[item]; }

    /**
     * @brief Inline function to get the current stock quantity for a specific item.
     * @param item The item to get the stock quantity for.
     * @return The current stock quantity for the item.
     */
    inline const float getStock(const Item item) { return inventory.getItemAmount(item); }

    /**
     * @brief Inline function to get the demand for a specific item (item to receive and its price).
     * @param item The item to get the demand for.
     * @return A pair representing the item to receive and its price.
     */
    inline std::pair<Item, float> getDemand(Item item) { return hasDemand(item) ? demands[item] : std::pair<Item, float>{Item{-1}, 0.0}; }

    /**
     * @brief Default constructor for TradeAgent.
     */
    TradeAgent() = default;

    /**
     * @brief Destructor for TradeAgent using default implementation.
     */
    virtual ~TradeAgent() = default;
};
