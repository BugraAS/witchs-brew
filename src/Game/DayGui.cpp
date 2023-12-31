#include "DayGui.hpp"
#include "DayTime.hpp"
#include "Global.hpp"
#include "raygui-implement.h"
#include "raylib.h"
#include "raymath.h"
DayGui::DayGui() : boxes() {
  boxes.push_back(::Rectangle{25, 25, 750, 400}); //background rectangle
  boxes.push_back(::Rectangle{15, 15, 770, 420}); //inner encapsulating rectangle
  boxes.push_back(::Rectangle{800-170, 450-70, 130, 30}); //Price selector
  boxes.push_back(::Rectangle{800-170, 450-110, 130, 30});//Day starter
  boxes.push_back(::Rectangle{25, 325, 750, 100}); // bottom half
  boxes.push_back(::Rectangle{35, 55, 730, 250}); // upgrade list
  boxes.push_back(::Rectangle{35, 340, 570, 70}); // description box
}


void DayGui::display(Matrix transform) {
  std::vector<::Rectangle> tBoxes = transformBoxes(transform);
  const Color col{230, 200, 220, 255};
  const float alpha = 0.4;
  DrawRectangleRec(tBoxes[1], Fade(col, alpha));
  DrawRectangleRec(tBoxes[4], ColorAlphaBlend(RAYWHITE, Fade(col, alpha), WHITE));
  raygui::setFontSize(40);
  raygui::GuiGroupBox(tBoxes[0], "Sales");
  raygui::GuiSetStyle(0, 0, 0);
  raygui::setFontSize(20);
  int ret = raygui::GuiButton(tBoxes[2], "Show FPS");
  if(ret)
    Global::showStats ^=1;
  ret = raygui::GuiButton(tBoxes[3], "end Day");
  if(ret)
    static_cast<DayTime*>(parent)->endDay();
  float balance = static_cast<DayTime*>(parent)->getShop()->getBalance();
  raygui::GuiGroupBox(tBoxes[4],TextFormat("Money%10.1f",balance));
}

std::vector<::Rectangle> DayGui::transformBoxes(Matrix m) {
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