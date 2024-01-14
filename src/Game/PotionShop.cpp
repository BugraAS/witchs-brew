#include "PotionShop.hpp"
#include "Inventory.hpp"
#include <algorithm>
#include <cmath>
#include <limits>

// Constructor for PotionShop, initializes balance and sets up initial money in inventory
PotionShop::PotionShop(float balance)
: PotionShop()
{
    inventory.addItem(Item::MONEY, balance);
}

// Method to buy an upgrade for the PotionShop
void PotionShop::buyUpgrade(Item upgrade){
    // Check if the upgrade has already been bought
    if(inventory.getItemAmount(upgrade) == 1.0)
        return; // already bought

    // Save the current money balance
    float balance = inventory.getItemAmount(Item::MONEY);

    // Attempt to buy the upgrade and get the result
    float res = buy(upgradeSupplier.get(), upgrade, 1.0);

    // Check if the purchase was successful
    if(res != 1.0){
        // Restore the previous money balance if purchase failed (not enough money)
        inventory.setItem(Item::MONEY, balance);
        return; // not enough money
    }

    // Add the bought upgrade to the list of upgrades
    upgrades.push_back(upgrade);
}

// Method to buy a specified amount of ingredient from the supplier
void PotionShop::buyIngredient(Item ingredient, float amount){
    buy(ingredientSupplier.get(), ingredient, amount);
}

// Method to craft a potion using ingredients from the inventory
void PotionShop::craftPotion(){
    // Initialize the amount of potion to craft to a very large value
    float amount = std::numeric_limits<float>::max();

    // Iterate through each ingredient required for the potion
    for(auto ingredient: potionIngredients.getItems()){
        // Get the available amount of the ingredient in the inventory
        float avail = inventory.getItemAmount(ingredient.first);
        // Calculate the maximum amount of potion that can be crafted based on ingredient availability
        amount = std::min(amount, avail / ingredient.second);
    }

    // Iterate through each ingredient again to deduct the used amounts from the inventory
    for(auto ingredient: potionIngredients.getItems())
        inventory.takeItem(ingredient.first, amount * ingredient.second);

    // Add the crafted potion to the inventory
    inventory.addItem(Item::POTION, amount);
}

// Method to uncraft a potion, converting it back into ingredients
void PotionShop::uncraftPotion(){
    // Get the amount of potion in the inventory
    float amount = inventory.getItemAmount(Item::POTION);

    // Iterate through each ingredient required for the potion
    for(auto ingredient: potionIngredients.getItems())
        // Add the corresponding amount of each ingredient back to the inventory
        inventory.addItem(ingredient.first, ingredient.second * amount);
}
