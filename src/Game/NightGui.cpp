/**
 * @file NightGui.cpp
 * @brief Implementation of the NightGui class.
 */

#include "NightGui.hpp"
#include "Global.hpp"
#include "InfiniteShop.hpp"
#include "NightTime.hpp"
#include "PotionShop.hpp"
#include "TradeAgent.hpp"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <string>
#include <vector>
#include "raygui-implement.h"

/**
 * @brief Function to create a list of labels for each item in the trade agent's inventory.
 * @param items The vector of items for which labels need to be created.
 * @param agent The trade agent associated with the items.
 * @return A vector of strings containing labels for each item.
 */
static std::vector<std::string> createLabelList(std::vector<Item> &items, TradeAgent *agent) {
    std::vector<std::string> out{};
    for (Item item : items) {
        std::string temp{agent->getLabel(item)};
        float price = agent->getDemand(item).second;
        temp += TextFormat(" - %s  ", price == 0 ? "FREE" : TextFormat("%.1f $", price));
        out.push_back(temp);
    }
    return out;
}

/**
 * @brief Function to draw the upgrade menu with a list of available upgrades and their descriptions.
 * @param bounds The vector of rectangles representing the layout of GUI components.
 * @param shop The potion shop instance.
 */
static inline void DrawUpgradeMenu(const std::vector<Rectangle> &bounds, PotionShop *shop) {
    // Set GUI alpha and font size
    raygui::GuiSetAlpha(0.7f);
    raygui::setFontSize(30);

    InfiniteShop *upgShop = shop->getUpgradeShop();

    // List of available upgrades
    auto upgrades = upgShop->GetAvailableItems();
    auto upgradeNames = createLabelList(upgrades, shop->getUpgradeShop());
    const char *upgradeList[upgrades.size()];
    for (int i = 0; i < upgrades.size(); i++) {
        upgradeList[i] = upgradeNames[i].c_str();
    }

    // Upgrade selection using a list view
    static int upgradeIndex = 0;
    static int upgradeActive = -1;
    static int upgradeFocus = -1;
    raygui::GuiSetState(raygui::STATE_FOCUSED);
    raygui::GuiSetStyle(raygui::LISTVIEW, raygui::TEXT_ALIGNMENT, raygui::TEXT_ALIGN_RIGHT);
    raygui::GuiSetStyle(raygui::LISTVIEW, raygui::TEXT_PADDING, 10);
    raygui::GuiListViewEx(bounds[5], upgradeList, upgradeNames.size(), &upgradeIndex, &upgradeActive, &upgradeFocus);
    raygui::GuiSetStyle(raygui::LISTVIEW, raygui::TEXT_ALIGNMENT, raygui::TEXT_ALIGN_CENTER);
    raygui::GuiSetState(raygui::STATE_NORMAL);

    // Upgrade description
    raygui::GuiSetStyle(raygui::DEFAULT, raygui::TEXT_ALIGNMENT_VERTICAL, raygui::TEXT_ALIGN_TOP);
    raygui::GuiSetStyle(raygui::DEFAULT, raygui::TEXT_ALIGNMENT, raygui::TEXT_ALIGN_LEFT);
    raygui::GuiSetStyle(raygui::DEFAULT, raygui::TEXT_WRAP_MODE, raygui::TEXT_WRAP_WORD);

    std::string desc{};
    if (upgradeActive != -1)
        desc = upgShop->getDesc(upgrades[upgradeActive]);

    raygui::GuiSetState(raygui::STATE_FOCUSED);
    raygui::setFontSize(25);
    raygui::GuiTextBox(bounds[6], (char *)desc.c_str(), 20, false);
    raygui::setFontSize(30);
    raygui::GuiSetState(raygui::STATE_NORMAL);

    // undo changes to the text settings
    raygui::GuiSetStyle(raygui::DEFAULT, raygui::TEXT_ALIGNMENT_VERTICAL, raygui::TEXT_ALIGN_MIDDLE);
    raygui::GuiSetStyle(raygui::DEFAULT, raygui::TEXT_ALIGNMENT, raygui::TEXT_ALIGN_CENTER);
    raygui::GuiSetStyle(raygui::DEFAULT, raygui::TEXT_WRAP_MODE, raygui::TEXT_WRAP_NONE);

    // Purchase button
    // TODO: Do something when purchase is clicked
    raygui::GuiButton(bounds[8], "Purchase");

    raygui::GuiSetAlpha(1.0);
}

/**
 * @brief Constructor for the NightGui class.
 * @details Initializes the rectangles used for drawing.
 */
NightGui::NightGui() : boxes() {
    boxes.push_back(::Rectangle{25, 35, 750, 390});        // Inner encapsulating rectangle // 9
    boxes.push_back(::Rectangle{15, 15, 770, 420});        // Background rectangle // 1
    boxes.push_back(::Rectangle{800 - 170, 450 - 70, 130, 30}); // Price selector // 2
    boxes.push_back(::Rectangle{800 - 170, 450 - 110, 130, 30}); // Day starter // 3
    boxes.push_back(::Rectangle{25, 325, 750, 100});        // Bottom half // 4
    boxes.push_back(::Rectangle{35, 55, 730, 250});        // Upgrade list // 5
    boxes.push_back(::Rectangle{35, 340, 570, 70});        // Description box // 6
    boxes.push_back(::Rectangle{200, 20, 565, 30});        // Tab bar // 7
    boxes.push_back(::Rectangle{800 - 190, 450 - 110, 150, 70});        // Buy button // 8
}

/**
 * @brief Function to display the night GUI, including the shop information and upgrade menu.
 * @param transform The transformation matrix for GUI components.
 */
void NightGui::display(Matrix transform) {
    // Set GUI style and alpha
    raygui::setStyle(raygui::STYLE_CHERRY);
    std::vector<::Rectangle> tBoxes = transformBoxes(transform);
    const Color col{raygui::getStyleColor()};
    const float alpha = 0.90;

    // Get the potion shop from the NightTime parent
    PotionShop *shop = static_cast<NightTime *>(parent)->getShop();
    float balance = shop->getBalance();

    // Draw the background and encapsulating rectangles
    DrawRectangleRec(tBoxes[1], Fade(col, alpha));
    DrawRectangleRec(tBoxes[4], ColorAlphaBlend(RAYWHITE, Fade(col, alpha), WHITE));

    // Draw the shop title in a group box
    raygui::setFontSize(40);
    raygui::GuiGroupBox(tBoxes[0], "the shop");

    // Draw the balance information in a group box
    raygui::setFontSize(30);
    raygui::GuiGroupBox(tBoxes[4], TextFormat("Money%10.1f", balance));

    // Draw tabs
    raygui::setFontSize(25);
    const char*  names[] = {"Upgrades","Ingredients","Pricing", "Options"};
    static int activeTab = 0;
    raygui::GuiTabBarNoClose(tBoxes[7],names,sizeof(names)/sizeof(char*),&activeTab);
    raygui::setFontSize(20);

    // // Draw the "end Night" button and handle its click event
    // int ret = raygui::GuiButton(tBoxes[3], "end Night");
    // if (ret)
    //     static_cast<NightTime *>(parent)->endNight();

    // // Draw and handle the price selector
    // int price = shop->getPrice();
    // int newprice = price;
    // static bool priceEdit = false;
    // priceEdit ^= raygui::GuiSpinner(tBoxes[2], nullptr, &newprice, 0, 100, priceEdit);
    // if (newprice != price)
    //     shop->setPrice(static_cast<float>(newprice));

    // Draw the upgrade menu
    switch (activeTab) {
        case 0: DrawUpgradeMenu(tBoxes, shop); break;
        default: break;
    }
}

/**
 * @brief Function to transform the rectangles based on a given matrix.
 * @param m The transformation matrix.
 * @return A vector of transformed rectangles.
 */
std::vector<::Rectangle> NightGui::transformBoxes(Matrix m) {
    std::vector<::Rectangle> out{};
    for (Rectangle r : boxes) {
        Vector2 p{r.x, r.y};          // position
        Vector2 d{r.width, r.height}; // dimension
        p = Vector2Transform(p, t);
        m.m12 = 0;
        m.m13 = 0;
        d = Vector2Transform(d, m);
        out.push_back(::Rectangle{p.x, p.y, d.x, d.y});
    }
    return out;
}
