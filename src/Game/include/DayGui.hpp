#pragma once
#include "GuiNode.hpp"
#include "raylib.h"
#include <vector>

class DayGui: public GuiNode{
    private:
    std::vector<::Rectangle> boxes;
    public:
    DayGui();
    virtual void display(Matrix transform) override;
    private:
    std::vector<::Rectangle> transformBoxes(Matrix m);
};