#include "InfiniteShop.hpp"
#include "Inventory.hpp"
#include <limits>

void InfiniteShop::AddItem(Item upgrade, float price, const std::string name, std::string desc){
    appendItem(upgrade, std::numeric_limits<float>::infinity(), name, desc);
    setDemand(upgrade, Item::MONEY, price);
}

//intentionally didn't put any safeguard
void InfiniteShop::RemoveItem(Item upgrade){
    inventory.RemoveItem(upgrade);
    demands.erase(upgrade);
    labels.erase(upgrade);
}