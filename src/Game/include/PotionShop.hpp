#pragma once

#include "InfiniteShop.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Node.hpp"
#include "TradeAgent.hpp"
#include <memory>
#include <vector>

// PotionShop class is derived from TradeAgent and Node, representing a shop for potion crafting.
class PotionShop : public TradeAgent, public Node {
private:
    std::vector<Item> upgrades;               // Vector to store available potion upgrades.
    Inventory potionIngredients;              // Inventory to store potion ingredients.
    std::unique_ptr<InfiniteShop> ingredientSupplier = std::make_unique<InfiniteShop>();  // Supplier for potion ingredients.
    std::unique_ptr<InfiniteShop> upgradeSupplier = std::make_unique<InfiniteShop>();      // Supplier for potion upgrades.

public:
    // Function to buy a potion upgrade and add it to the shop's upgrades.
    void buyUpgrade(Item upgrade);

    // Function to buy a specified amount of potion ingredient from the supplier.
    void buyIngredient(Item ingredient, float amount);

    // Function to craft a potion by consuming ingredients and adding it to the inventory.
    void craftPotion();

    // Function to uncraft a potion by removing it from the inventory and restoring ingredients.
    void uncraftPotion();

    // Inline function to get a reference to the upgrades vector.
    inline const std::vector<Item>& getUpgrades() const { return upgrades; }

    // Inline function to get a reference to the potionIngredients inventory.
    inline Inventory& getIngredients() { return potionIngredients; }

    // Inline function to get a pointer to the upgradeSupplier.
    inline InfiniteShop* getUpgradeShop() const { return upgradeSupplier.get(); }

    // Inline function to get a pointer to the ingredientSupplier.
    inline InfiniteShop* getIngredientShop() const { return ingredientSupplier.get(); }

    // Inline function to get the current balance in the shop.
    inline float getBalance() { return inventory.getItemAmount(Item::MONEY); }

    // Inline function to get the current price for potions.
    inline float getPrice() { return getDemand(Item::POTION).second; }

    // Inline function to set the price for potions.
    inline void setPrice(float price) { setDemand(Item::POTION, Item::MONEY, price); }

    // Default constructor for PotionShop.
    PotionShop() = default;

    // Constructor for PotionShop with an initial balance.
    PotionShop(float balance);

    // Destructor for PotionShop using default implementation.
    virtual ~PotionShop() = default;
};
