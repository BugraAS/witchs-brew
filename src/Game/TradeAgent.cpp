/**
 * @file TradeAgent.cpp
 * @brief Implementation of the TradeAgent class.
 */

#include "TradeAgent.hpp"
#include "Item.hpp"
#include <utility>

/**
 * @brief Function to add an item to the TradeAgent's inventory.
 * @param item The item to be added.
 * @param quantity The quantity of the item to be added.
 * @param label The label for the item.
 * @param description The description for the item.
 */
void TradeAgent::appendItem(Item item, float quantity, std::string label, std::string description) {
    inventory.addItem(item, quantity);  // Add the item to the inventory with the specified quantity.
    labels[item] = label;               // Set the label for the item.
    descriptions[item] = description;   // Set the description for the item.
}

/**
 * @brief Function to sell a specified quantity of an item to another TradeAgent.
 * @param buyer The TradeAgent to sell the item to.
 * @param item The item to be sold.
 * @param quantity The quantity of the item to be sold.
 * @return The total value of the sold items.
 */
float TradeAgent::sell(TradeAgent* buyer, Item item, float quantity) {
    auto demand = getDemand(item);  // Get the demand for the specified item.
    
    // Check if there is no demand or the buyer doesn't have the required item in their inventory.
    if (demand.first.id == -1 || !buyer->inventory.hasItem(demand.first))
        return 0.0f;  // Return 0 if the sale is not possible.

    // Calculate the quantity to sell based on demand and transfer items between buyer and seller inventories.
    float out = buyer->inventory.takeItem(demand.first, quantity * demand.second);
    float given = this->inventory.takeItem(item, out / demand.second);
    buyer->inventory.addItem(item, given);

    return out;  // Return the total value of the sold items.
}

/**
 * @brief Function to set the demand for a specific item.
 * @param give The item to be given in exchange.
 * @param receive The item to be received in exchange.
 * @param price The price for the specified item.
 */
void TradeAgent::setDemand(Item give, Item receive, float price) {
    demands[give] = std::pair<Item, float>{receive, price};  // Set the demand for the specified item.
}

/**
 * @brief Function to get a list of available items in the TradeAgent's inventory.
 * @return A vector containing the list of available items.
 */
const std::vector<Item> TradeAgent::GetAvailableItems() const {
    std::vector<Item> out{};
    
    // Populate the vector with items in the inventory.
    for (auto& name : labels) {
        out.push_back(name.first);
    }
    
    return out;  // Return the list of available items.
}
