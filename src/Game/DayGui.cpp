/**
 * @file DayGui.cpp
 * @brief Implementation of the DayGui class.
 */

#include "DayGui.hpp"
#include "DayTime.hpp"
#include "Global.hpp"
#include "raygui-implement.h"
#include "raylib.h"
#include "raymath.h"

/**
 * @brief Constructor for the DayGui class.
 */
DayGui::DayGui() : boxes() {
  // Define initial rectangles for GUI components
  boxes.push_back(::Rectangle{25, 25, 750, 400}); // Background rectangle
  boxes.push_back(::Rectangle{15, 15, 770, 420}); // Inner encapsulating rectangle
  boxes.push_back(::Rectangle{800-170, 450-70, 130, 30}); // Price selector
  boxes.push_back(::Rectangle{800-170, 450-110, 130, 30}); // Day starter
  boxes.push_back(::Rectangle{25, 325, 750, 100}); // Bottom half
  boxes.push_back(::Rectangle{35, 55, 730, 250}); // Upgrade list
  boxes.push_back(::Rectangle{35, 340, 570, 70}); // Description box
}

/**
 * @brief Method to display the GUI with a given transformation matrix.
 * @param transform The transformation matrix to be applied to the GUI components.
 */
void DayGui::display(Matrix transform) {
  // Transform the original boxes based on the given matrix
  std::vector<::Rectangle> tBoxes = transformBoxes(transform);

  // Define colors and transparency
  const Color col{230, 200, 220, 255};
  const float alpha = 0.4;

  // Draw background rectangles with transparency
  DrawRectangleRec(tBoxes[1], Fade(col, alpha));
  DrawRectangleRec(tBoxes[4], ColorAlphaBlend(RAYWHITE, Fade(col, alpha), WHITE));

  // Set font size and draw GUI components
  raygui::setFontSize(40);
  raygui::GuiGroupBox(tBoxes[0], "Sales");
  raygui::GuiSetStyle(0, 0, 0);
  raygui::setFontSize(20);

  // Button to toggle showing FPS
  int ret = raygui::GuiButton(tBoxes[2], "Show FPS");
  if(ret)
    Global::showStats ^=1;

  // Button to end the day
  ret = raygui::GuiButton(tBoxes[3], "end Day");
  if(ret)
    static_cast<DayTime*>(parent)->endDay();

  // Display the current balance in a group box
  float balance = static_cast<DayTime*>(parent)->getShop()->getBalance();
  raygui::GuiGroupBox(tBoxes[4],TextFormat("Money%10.1f",balance));
}

/**
 * @brief Method to transform the original boxes based on a transformation matrix.
 * @param m The transformation matrix.
 * @return Transformed rectangles based on the given matrix.
 */
std::vector<::Rectangle> DayGui::transformBoxes(Matrix m) {
  std::vector<::Rectangle> out{};
  for (Rectangle r : boxes) {
    Vector2 p{r.x, r.y};          // Position
    Vector2 d{r.width, r.height}; // Dimension
    p = Vector2Transform(p, t);
    m.m12 = 0;
    m.m13 = 0;
    d = Vector2Transform(d, m);
    out.push_back(::Rectangle{p.x, p.y, d.x, d.y});
  }
  return out;
}
