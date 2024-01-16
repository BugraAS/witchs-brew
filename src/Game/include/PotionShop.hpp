/**
 * @file PotionShop.hpp
 * @brief Header file for the PotionShop class.
 */

#pragma once

#include "InfiniteShop.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Node.hpp"
#include "TradeAgent.hpp"
#include <memory>
#include <vector>

/**
 * @class PotionShop
 * @brief Represents a shop for potion crafting.
 * @details Derived from TradeAgent and Node, the PotionShop class manages potion-related functionalities.
 */
class PotionShop : public TradeAgent, public Node {
private:
    std::vector<Item> upgrades;               ///< Vector to store available potion upgrades.
    Inventory potionIngredients;              ///< Inventory to store potion ingredients.
    std::unique_ptr<InfiniteShop> ingredientSupplier = std::make_unique<InfiniteShop>();  ///< Supplier for potion ingredients.
    std::unique_ptr<InfiniteShop> upgradeSupplier = std::make_unique<InfiniteShop>();      ///< Supplier for potion upgrades.

public:
    /**
     * @brief Function to buy a potion upgrade and add it to the shop's upgrades.
     * @param upgrade The potion upgrade to be bought.
     */
    void buyUpgrade(Item upgrade);

    /**
     * @brief Function to buy a specified amount of potion ingredient from the supplier.
     * @param ingredient The potion ingredient to be bought.
     * @param amount The quantity of the ingredient to be bought.
     */
    void buyIngredient(Item ingredient, float amount);

    /**
     * @brief Function to craft a potion by consuming ingredients and adding it to the inventory.
     */
    void craftPotion();

    /**
     * @brief Function to uncraft a potion by removing it from the inventory and restoring ingredients.
     */
    void uncraftPotion();

    /**
     * @brief Inline function to get a reference to the upgrades vector.
     * @return A reference to the vector of potion upgrades.
     */
    inline const std::vector<Item>& getUpgrades() const { return upgrades; }

    /**
     * @brief Inline function to get a reference to the potionIngredients inventory.
     * @return A reference to the potionIngredients inventory.
     */
    inline Inventory& getIngredients() { return potionIngredients; }

    /**
     * @brief Inline function to get a pointer to the upgradeSupplier.
     * @return A pointer to the upgradeSupplier.
     */
    inline InfiniteShop* getUpgradeShop() const { return upgradeSupplier.get(); }

    /**
     * @brief Inline function to get a pointer to the ingredientSupplier.
     * @return A pointer to the ingredientSupplier.
     */
    inline InfiniteShop* getIngredientShop() const { return ingredientSupplier.get(); }

    /**
     * @brief Inline function to get the current balance in the shop.
     * @return The current balance in the shop.
     */
    inline float getBalance() { return inventory.getItemAmount(Item::MONEY); }

    /**
     * @brief Inline function to get the current price for potions.
     * @return The current price for potions.
     */
    inline float getPrice() { return getDemand(Item::POTION).second; }

    /**
     * @brief Inline function to set the price for potions.
     * @param price The new price for potions.
     */
    inline void setPrice(float price) { setDemand(Item::POTION, Item::MONEY, price); }

    /**
     * @brief Default constructor for PotionShop.
     */
    PotionShop() = default;

    /**
     * @brief Constructor for PotionShop with an initial balance.
     * @param balance The initial balance in the shop.
     */
    PotionShop(float balance);

    /**
     * @brief Destructor for PotionShop using default implementation.
     */
    virtual ~PotionShop() = default;
};
