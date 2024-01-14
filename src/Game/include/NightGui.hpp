#pragma once

#include "GuiNode.hpp"
#include "raylib.h"
#include <vector>

// NightGui class is derived from GuiNode, representing the graphical user interface for the nighttime.
class NightGui : public GuiNode {
private:
    std::vector<::Rectangle> boxes; // Vector to store rectangles used for drawing GUI elements.

public:
    // Constructor for the NightGui class.
    NightGui();

    // Function to display the nighttime GUI, implementing the virtual function from the base class.
    virtual void display(Matrix transform) override;

private:
    // Function to transform the rectangles based on a given matrix.
    std::vector<::Rectangle> transformBoxes(Matrix m);
};
